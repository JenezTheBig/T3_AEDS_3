#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <string.h>

// Declarações das funções para o algoritmo Boyer-Moore
void heuristica_mau_carater(char *padrao, int comprimento_padrao, int tabela_mau_carater[256]);
int boyer_moore_buscar(char *texto, char *padrao, int inicio, int fim);

#endif
