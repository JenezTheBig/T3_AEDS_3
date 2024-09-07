#include "kmp.h"

// Função para calcular a função prefixo (também conhecida como pi) para o algoritmo KMP
void calcular_funcao_prefixo(char *padrao, int comprimento_padrao, int *tabela_prefixo) {
    int comprimento = 0;
    tabela_prefixo[0] = 0; // O comprimento do prefixo para o primeiro caractere é sempre 0

    // Preenchimento da tabela de prefixos para o padrão
    for (int i = 1; i < comprimento_padrao; i++) {
        while (comprimento > 0 && padrao[i] != padrao[comprimento]) {
            comprimento = tabela_prefixo[comprimento - 1];
        }
        if (padrao[i] == padrao[comprimento]) {
            comprimento++;
        }
        tabela_prefixo[i] = comprimento;
    }
}

// Função para buscar uma substring utilizando o algoritmo KMP
int kmp_buscar(char *texto, char *padrao, int inicio, int fim) {
    int comprimento_texto = fim - inicio + 1;
    int comprimento_padrao = strlen(padrao);
    int *tabela_prefixo = (int *)malloc(comprimento_padrao * sizeof(int));
    
    // Calcula a tabela de prefixos para o padrão
    calcular_funcao_prefixo(padrao, comprimento_padrao, tabela_prefixo);

    int j = 0; // índice para padrao[]
    for (int i = 0; i < comprimento_texto; i++) {
        while (j > 0 && texto[inicio + i] != padrao[j]) {
            j = tabela_prefixo[j - 1];
        }
        if (texto[inicio + i] == padrao[j]) {
            j++;
        }
        if (j == comprimento_padrao) {
            free(tabela_prefixo);
            return 1; // Substring encontrada
        }
    }
    free(tabela_prefixo);
    return 0; // Substring não encontrada
}
