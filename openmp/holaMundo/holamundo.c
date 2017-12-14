#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
  #pragma omp parallel num_threads(4)
  {
    int i, id, num;
    id = omp_get_thread_num();
    num = omp_get_num_threads();
    printf("Hola Mundo\n");
    printf("Numero de procesos: %d\n", num);
    #pragma omp for
      for (i = 0; i < 6; i++) printf("Iter: %d, por el hilo %d\n", i, id);
  }
  printf("Adios\n");
  return 0;
}
