#include <mpi.h>
#include <stdio.h>
#include <string.h>
/**
 * Sánchez Baños Margarito
 */
int main(int argc, char *argv[])
{
  int myrank, size, origen, destino, tag = 1;
  char mensaje[100];
  MPI_Status status;
  MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(myrank != 0) {
      printf("Proceso %d de %d\n", myrank, size);
      sprintf(mensaje, "Saludos desde el proceso %d", myrank);
      destino = 0;
      MPI_Send(mensaje, strlen(mensaje)+1, MPI_CHAR, destino, tag, MPI_COMM_WORLD);
    }else{
      printf("proceso 0, total de procesos = %d\n", size);
      for(origen = 1; origen < size; origen++) {
        MPI_Recv(mensaje, 100, MPI_CHAR, origen, tag, MPI_COMM_WORLD, &status);
        printf("%s\n", mensaje);
      }
    }
    MPI_Finalize();
  return 0;
}
