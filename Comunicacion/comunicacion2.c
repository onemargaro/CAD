#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[]){
  int mensaje[8], nprocs, rank, send, i;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    send = rank+1;
    MPI_Gather(&send, 1, MPI_INTEGER, mensaje, 1, MPI_INTEGER, 0, &rank);
    if(rank == 0) {
      printf("Resultado: %d %d %d %d %d %d %d %d\n", mensaje[0], mensaje[1], mensaje[2], mensaje[3], mensaje[4], mensaje[5], mensaje[6], mensaje[7] );
    }
  MPI_Finalize();
  return 0;
}
