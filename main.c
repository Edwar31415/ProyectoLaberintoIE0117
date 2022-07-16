#include <stdio.h>
#include "labe.h" // uso del archivo creado

#define LABERINTO "./laberinto.txt"

int main() {
  char* labe;
  int rens, cols;// filas colunas

  labe = CargarLaberinto(LABERINTO, &rens, &cols);//usa el archivo labe, pasandole a las funcion CargarLaberinto, el laberito, filas y columnas.
  printf("%d %d\n", rens, cols);// impresion de filas y colunmas luego de pasar por la funcion
  MostrarLaberinto(labe, rens, cols);// llama a la fucción Mostrar laberinto con ayuda de labe.h y le pasa el laberinto, columnas y filas

  int x, y; //logica del recorrido de los bordes 
  /* Bordes
   *   (0, y)
   *   (x, 0)
   *   (rens-1, y)
   *   (x, cols-1)
   */
//recorriendo los bordes y analiza si la fucion recorrido es igual a 2(la solucion)
  x = 0;
  for (y = 0; y < rens; ++y)
    if (RecorrerLaberinto(labe, rens, cols, x, y) == 2) { // si al pasarle los parametros la funcion retorna 2 la condicion se cumple y 
      printf("SOLUCIONADO!\n\n");
      return 0;
    }

  y = 0;
  for (x = 1; x < cols - 1; ++x)
    if (RecorrerLaberinto(labe, rens, cols, x, y) == 2) {
      printf("SOLUCIONADO!\n\n");
      return 0;
    }

  x = cols - 1;
  for (y = 0; y < rens; ++y)
    if (RecorrerLaberinto(labe, rens, cols, x, y) == 2) {
      printf("SOLUCIONADO!\n\n");
      return 0;
    }

  y = rens - 1;
  for (x = 1; x < cols - 1; ++x)
    if (RecorrerLaberinto(labe, rens, cols, x, y) == 2) {
      printf("SOLUCIONADO!\n\n");
      return 0;
    }

  printf("\nNo hay solución.\n");// en caso de que ninguna condicion se cumpla.
  free(labe);
  return 0;
}
