#ifndef KMP_H
#define KMP_H

#include <stdlib.h>
#include <string.h>

// Declarações das funções para o algoritmo KMP
void calcular_funcao_prefixo(char *padrao, int comprimento_padrao, int *tabela_prefixo);
int kmp_buscar(char *texto, char *padrao, int inicio, int fim);

#endif
