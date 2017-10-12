#include <stdio.h>

int main(int argc, char *argv[])
{
  #pragma omp parallel
  {
    int i;
    printf("Hola Mundo\n");
    #pragma omp for
      for (i = 0; i < 6; i++) printf("Iter: %d\n", i);
  }
  printf("Adios\n");
  return 0;
}
