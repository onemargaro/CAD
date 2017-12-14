#include <stdio.h>
#include <omp.h>
void schedule(int private, int num_threads, char* type, int chunck, int max);
int main(int argc, char *argv[])
{
  int n_hilos, tid, nth, iteraciones, i;
  printf("Cambiando a Static\n");
  schedule(iteraciones, 4, "static", 10, 100000);
  printf("Cambiando a Dynamic\n");
  schedule(iteraciones, 4, "dynamic", 15, 100000);
  printf("Cambiando a Guided\n");
  schedule(iteraciones, 4, "guided", 12, 100000);
  return 0;
}


void schedule(int private, int num_threads, char* type, int chunck, int max){
  int i;
  #pragma omp parallel num_threads(num_threads) private(private)
  {
    private=0;
    printf("hilo %d\n", omp_get_thread_num());
    if(type=="static"){
        #pragma omp for schedule (static, chunck)
        for(i=0; i<max; i++) private++;
        printf("iteraciones: %d\n", private);
    }else if(type == "dynamic"){
        #pragma omp for schedule (dynamic, chunck)
        for(i=0; i<max; i++) private++;
        printf("iteraciones: %d\n", private);
    }else if(type=="guided"){
        #pragma omp for schedule (guided, chunck)
        for(i=0; i<max; i++) private++;
        printf("iteraciones: %d\n", private);
    }else{
      printf("Error\n");
    }
  }
}
