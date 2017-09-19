#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readVector(int *vector, int size);
int dotProduct(int *vectora, int *vectorb, int size);
void printVector(char *message, int *vector, int size);

/**
 * Programa que realiza el producto punto entre dos vectores
 * de Tamaño N
 * @param  argc Numero de Argumento pasados al programa
 * @param  argv Argumentos pasados al programa
 * @return      0 para una ejecución correcta
 */
int main(int argc, char *argv[])
{
  int *vectora;
  int *vectorb;
  int size;

  printf("\n¿De qué tamaño serán los vectores?\n");
  scanf("%d", &size);
  vectora = calloc(size, sizeof(int));
  vectorb = calloc(size, sizeof(int));
  readVector(vectora, size);
  printVector("Vector A: ",vectora, size);
  readVector(vectorb, size);
  printVector("Vector B: ",vectorb, size);
  printf("\nProducto Punto: %d\n", dotProduct(vectora, vectorb, size));
  return 0;
}

/**
 * Lee el vector y genera valores aleatorios
 * @param vector Apuntador a una direccion de memoria
 * @param size   Tamaño del vector
 */
void readVector(int *vector, int size) {
  int i = 0;
  time_t t;
  srand((unsigned) time(&t));
  
  for (i = 0; i < size; i++){
    *(vector+i) = rand() % 5;
  }
}

/**
 * Hace el producto punto de dos vectores
 * @param  vectora Apuntador a vectora
 * @param  vectorb Apuntador a vectorb
 * @param  size    tamaño de los vectores
 * @return   Int   Producto punto de los dos vectore
 */
int dotProduct(int *vectora, int *vectorb, int size) {
  int aux = 0;
  for (int i = 0; i < size; i++)
  {
    aux += *(vectora+i) * *(vectorb+i);
  }
  return aux;
}

/**
 * Imprime un vector
 * @param message Texto a desplegar como titulo de los impreso
 * @param vector  Vector a imprimir
 * @param size    Tamaño del vector a imprimir
 */
void printVector(char *message, int *vector, int size) {
  printf("\n%s\n", message);
  printf("[");
  for (int i = 0; i < size; i++)
  {
    printf(" %d ", *(vector+i));
  }
  printf("]");
}
