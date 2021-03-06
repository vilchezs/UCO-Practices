#include "ej10.h"

int randomNumber (int min, int max) {
  int random;
  random = ((min + rand() % (max + 1 - min)));
  return random;
}

int * vectorDeAleatorios (int nEle, int min, int max) {
  int *ptrv = calloc(nEle, sizeof(int));
  if (ptrv == NULL) {
    printf("La reserva de memoria no se ha realizado correctamente\n");
    exit(-3);
  }
  srand(time(NULL));
  for (int i = 0; i < nEle; i++) {
    ptrv[i] = randomNumber(min, max);
  }
  return ptrv;
}

void printVector (int * vector, int nEle) {
  printf("Vector = ");
  printf("{");
  for (int i = 0; i < nEle; i++) {
    if (i == nEle - 1) printf("%d", vector[i]);
    else printf("%d, ", vector[i]);
  }
  printf("}\n");
}

void writeInFile (char *file, int* vector, int nEle) {
  FILE *f;
  if ((f = fopen (file, "wb")) == NULL) {
    printf("No se ha podido abrir el fichero <%s>\n", file);
    exit(-4);
  }

  fwrite (vector, sizeof(int), nEle, f);
  fclose(f);
}

int * readFile (char* file, int* vector, int nEle) {
  FILE *f;
  if ((f = fopen (file, "rb")) == NULL) {
    printf("No se ha podido abrir el fichero <%s>\n", file);
    exit(-4);
  }

  fread(vector, sizeof(int), nEle, f);
  fclose(f);

  return vector;
}
