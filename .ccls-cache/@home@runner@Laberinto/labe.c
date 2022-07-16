#include <stdio.h>
#include "labe.h"
void quitaBlancos(char *s) {
    int i = 0, j = 0;
    for (i = 0; i < strlen(s); ++i)
        if (!isspace(s[i]))
            s[j++] = s[i];
    s[j] = '\0';
}

char* CargarLaberinto(const char* archivo, int* r, int* c) {
  FILE *fp = fopen(archivo, "r");
  char lin[MAXL];
    int rows = 0, cols = 0;
  while (fgets(lin, MAXL, fp)) { //leer cadena de caracteres string, con un maximo de tamaño de archivo
    quitaBlancos(lin);//limpia el archivo de los espacio en blanco
    if (strlen(lin) > 0) {//strlen mide la longitud de la cadena sin tomar los espacios vacios
        ++rows;// aumenta filas
        if (cols == 0) cols = strlen(lin); //iguala el tamaño de lin a columnas
    }
  }
  fclose(fp); //cierra el archivo
  *r = rows;
  *c = cols;
  //hasta aca lee 1 vez para ver el tamaño
  
  //ahira crea la vara
  char* labe = (char*) malloc(rows * cols * sizeof(char));// signa memoria deinamica al tamaño de la matriz

    // vuelve a leer pa rellenar
    fp = fopen(archivo, "r");
    char ch;
    int i = 0;
  while (!feof(fp)) {//fin de archivo
    ch = fgetc(fp);//lee ch
    if (!isspace(ch))// es blanco?
        labe[i++] = ch; //crea el laberito con el while
  }
  fclose(fp); // se cierra
  return labe;//se obtien la matriz nueva sin espacios
}

void MostrarLaberinto(char* L, int r, int c) {
  int i, j;

  // system("cls"); // <- windoze
  system("clear"); // <- linux

  for (i = 0; i < r; i++) { //imprime la matriz  mientras i sea menor a filas, entra el for anidado y mientras j sea menor a columnas, imprime cada arreglo como las filas
    for (j = 0; j < c; j++)
      printf("%c ", L[c*i+j]);
    printf("\n");
  }
  // Sleep(20);//c++
  usleep(50000); // linux permite bloquear la ejecución actual por tiempo
              // determinado, si se comenta entonces la ejecion es mas rapida.
}

int RecorrerLaberinto(char* L, int r, int c, int x, int y) {
  int estado = 0;// iniciación 

  if (L[c*y+x] == '2') {// muestra se hay solución
    printf("\nLa solución se encontró en la coordenada (%i, %i)\n\n", y, x);
    return 2; // Si hay solución
  }
  if (L[c*y+x] == '0' || L[c*y+x] == ' ')// ||=ó
    return 0;

  L[c*y+x] = ' ';

  MostrarLaberinto(L, r, c);//utiliza la funcion laberito. 
  if (x > 0) {
    estado = RecorrerLaberinto(L, r, c, x - 1, y);
    if (estado == 2)//retorna 2 si encuentra la solución
      return 2;
  }

  if (x < c - 1) {
    estado = RecorrerLaberinto(L, r, c, x + 1, y);
    if (estado == 2)
      return 2;
  }

  if (y > 0) {
    estado = RecorrerLaberinto(L, r, c, x, y - 1);
    if (estado == 2)
      return 2;
  }

  if (y < r - 1) {
    estado = RecorrerLaberinto(L, r, c, x, y + 1);
    if (estado == 2)
      return 2;
  }

  L[c*y+x] = '1';

  return 1; // Si regresa 1 no hay solución
}
