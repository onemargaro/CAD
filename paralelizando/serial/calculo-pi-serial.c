#include <stdio.h>
#include <math.h>
/**
 * Sánchez Baños Margarito
 */
double f (double a) {
  return (4.0/(1.0+a*a));
}
int main(int argc, char *argv[]){
  int i, n;
  double PI25DEC = 3.14159265358979328462643;
  double pi, h, sum, x;
  n = 100;
  h = 1.0 / (double)n;
  sum = 0.0;

  for (i = 0; i <= n; i++){
    x = h*((double)i-0.5);
    sum+=f(x);
  }
  pi = h*sum;
  printf("\npi es aprox %.16f, el error cometido es %.16f\n", pi, fabs(pi-PI25DEC));
  return 0;
}
