#include "boyer_moore.h"

// Função para preprocessar o padrão para a heurística do mau caráter (bad character) do algoritmo Boyer-Moore
void heuristica_mau_carater(char *padrao, int comprimento_padrao, int tabela_mau_carater[256]) {
    // Inicializa a tabela com -1
    for (int i = 0; i < 256; i++) {
        tabela_mau_carater[i] = -1;
    }
    // Preenche a tabela com as últimas ocorrências de cada caractere no padrão
    for (int i = 0; i < comprimento_padrao; i++) {
        tabela_mau_carater[(int)padrao[i]] = i;
    }
}

// Função para buscar uma substring utilizando o algoritmo Boyer-Moore
int boyer_moore_buscar(char *texto, char *padrao, int inicio, int fim) {
    int comprimento_texto = fim - inicio + 1;
    int comprimento_padrao = strlen(padrao);
    int tabela_mau_carater[256];
    
    // Calcula a tabela de mau caráter para o padrão
    heuristica_mau_carater(padrao, comprimento_padrao, tabela_mau_carater);

    int deslocamento = 0; // deslocamento do padrão em relação ao texto
    while (deslocamento <= (comprimento_texto - comprimento_padrao)) {
        int j = comprimento_padrao - 1;

        // Compara o padrão com o texto de trás para frente
        while (j >= 0 && padrao[j] == texto[inicio + deslocamento + j]) {
            j--;
        }

        // Se o padrão foi encontrado
        if (j < 0) {
            return 1; // Substring encontrada
        } else {
            // Se não encontrou, faz o deslocamento com base na tabela de mau caráter
            deslocamento += (j - tabela_mau_carater[(int)texto[inicio + deslocamento + j]]) > 1 ? (j - tabela_mau_carater[(int)texto[inicio + deslocamento + j]]) : 1;
        }
    }
    return 0; // Substring não encontrada
}
