#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[]){
  int rank, valor;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  do{
    if (rank == 0) scanf("%d", &valor);
    MPI_Bcast(&valor, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Proceso %d tiene %d\n", rank, valor);
  } while (valor >= 0);
  MPI_Finalize();
  return 0;
}
