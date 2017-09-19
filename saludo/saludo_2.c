#include <mpi.h>
#include <stdio.h>
#include <string.h>
/**
 * Programa en MPI que suma 1
 * al contador por cada proceso lanzado
 * @param  argc Numero de argumentos
 * @param  argv Argumentos
 * @return      0 si todo sale bien
 */
int main(int argc, char *argv[])
{
  int myrank, size, origen, destino, tag = 1;
  int numero=100;
  MPI_Status status;
  MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(myrank != 0) {
      /*
      MPI_Recv recibe en la dirección de 'numero' lo que se le envie en el proceso
      en que se encuentre
       */
      MPI_Recv(&numero, 1, MPI_INT, myrank-1, tag, MPI_COMM_WORLD, &status);
      printf("proceso %d de %d", myrank, size);
      // aqui se le incrementa uno al numero que se recibio
      numero+=1;
      // se imprime el numero recibido
      printf("   numero incrementado: %d\n", numero);
      if(myrank+1 == size){ // se verifica que no sea el último proceso lanzado
        /**
         * Si es el último proceso lanzado lo devulve al proceso 0 para imprimir el
         * valor final
         */
        MPI_Send(&numero, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
      }else{
        /**
         * En caso de que no sea el último proceso
         * se envia al siguiente proceso para que vuelva a incrementar en 1 el
         * contador
         */
        MPI_Send(&numero, 1, MPI_INT, myrank+1, tag, MPI_COMM_WORLD);
      }
    }else{
      printf("proceso 0, total de procesos = %d\n", size);
      printf("Original = %d\n", numero);
      MPI_Send(&numero, 1, MPI_INT, myrank+1, tag, MPI_COMM_WORLD);
      MPI_Recv(&numero, 1, MPI_INT, size-1, tag, MPI_COMM_WORLD, &status);
      numero+=1;
      printf("Final = %d\n", numero);
    }
    MPI_Finalize();
  return 0;
}