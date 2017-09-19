#include <mpi.h>
#include <stdio.h>
/**
 * Sánchez Baños Margarito
 */
int main(int argc, char *argv[])
{
  int mirank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &mirank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if(!(mirank%2)){
   printf("Hola desde el proceso %d de %d soy par\n", mirank, size);
  }else{
   printf("Hola desde el proceso %d de %d soy impar\n", mirank, size);
  }
  MPI_Finalize();
  return 0;
}
