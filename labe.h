#ifndef LABE_H
#define LABE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>



#define MAXL 1024

char* CargarLaberinto(const char* archivo, int* r, int* c);

void MostrarLaberinto(char* L, int r, int c);

int RecorrerLaberinto(char* L, int r, int c, int x, int y);

#endif