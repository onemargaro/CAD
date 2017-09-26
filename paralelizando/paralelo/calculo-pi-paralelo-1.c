#include <stdio.h>
#include <math.h>
#include <mpi.h>
/**
 * Sánchez Baños Margarito
 */
double f (double a) {
  return (4.0/(1.0+a*a));
}
int main(int argc, char *argv[]){
  int i, n, aux, myrank, size, origen, tag = 1;
  double PI25DEC = 3.14159265358979328462643;
  double pi, h, sum = 0.0, x;
  n = 100;
  h = 1.0 / (double)n;
  MPI_Status status;
  MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    aux = n/size;
    if(myrank != 0) {
      if (myrank+1 == size) { // en caso de que sea el último proceso
        // printf("\nintervalo de %d a %d\n", (myrank*aux) - aux, n);
        for (i = (myrank * aux) - aux; i <= n; i++){
          x = h*((double)i-0.5);
          sum+=f(x);
        }
        // printf("\nsuma = %d\n", sum); //preguntar sobre esto al profesor
      }else{
        // printf("\nintervalo de %d a %d\n", (myrank*aux) - aux, (myrank*aux)-1);
        for (i = (myrank * aux) - aux; i <= (myrank * aux) - 1; i++){
          x = h*((double)i-0.5);
          sum+=f(x);
        }
        // printf("\nsuma = %d\n", sum); //preguntar sobre esto al profesor
      }
      MPI_Send(&sum, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
    }else{
      for(origen = 1; origen < size; origen++) {
        MPI_Recv(&x, 1, MPI_DOUBLE, origen, tag, MPI_COMM_WORLD, &status);
        // printf("Suma de proceso %d   sum=%d\n", origen, x); //igual preguntar
        sum+=x;
      }
      pi = h*sum;
      printf("\npi es aprox %.16f, el error cometido es %.16f\n", pi, fabs(pi-PI25DEC));
    }
  MPI_Finalize();
  return 0;
}
