#ifndef UTEIS_H
#define UTEIS_H

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

// Declarações das funções
void exibir_tempo_execucao(struct rusage *inicio, struct rusage *fim);
char* ler_string(FILE *arquivo);

#endif // UTEIS_H
