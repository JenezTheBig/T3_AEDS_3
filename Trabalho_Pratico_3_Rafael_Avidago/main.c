#include "kmp.h"
#include "boyer_moore.h"
#include "uteis.h"

int main(int argc, char *argv[]) {
    //verifica se o numero de argumentos e correto
    if (argc != 4) {
        printf("Uso: %s <algoritmo> <nome_do_arquivo_de_entrada> <nome_do_arquivo_de_saida>\n", argv[0]);
        printf("Algoritmos disponíveis: KMP, BM\n");
        return 1;
    }
    //armazena os argumentos 
    char *algoritmo = argv[1];
    FILE *arquivo_entrada = fopen(argv[2], "r");
    if (!arquivo_entrada) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    FILE *arquivo_saida = fopen(argv[3], "w");
    if (!arquivo_saida) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(arquivo_entrada);
        return 1;
    }

    // Lê o texto principal e o padrão usando a função ler_string (uteis.c)
    char *texto_principal = ler_string(arquivo_entrada);
    if (texto_principal == NULL) {
        fclose(arquivo_entrada);
        fclose(arquivo_saida);
        return 1;
    }

    char *padrao = ler_string(arquivo_entrada);
    if (padrao == NULL) {
        free(texto_principal);
        fclose(arquivo_entrada);
        fclose(arquivo_saida);
        return 1;
    }
    // le o numero de queries
    int num_queries;
    if (fscanf(arquivo_entrada, "%d", &num_queries) != 1) {
        perror("Erro ao ler o número de queries");
        free(texto_principal);
        free(padrao);
        fclose(arquivo_entrada);
        fclose(arquivo_saida);
        return 1;
    }

    //var para medir tempo
    int inicio_intervalo, fim_intervalo;
    struct rusage tempo_inicio, tempo_fim;

    getrusage(RUSAGE_SELF, &tempo_inicio);

    //Laco para processar cada querie
    for (int i = 0; i < num_queries; i++) {
        if (fscanf(arquivo_entrada, "%d %d", &inicio_intervalo, &fim_intervalo) != 2) {
            perror("Erro ao ler os intervalos");
            break;
        }
        //ajusta os indices para que sejam baseados em zero
        inicio_intervalo -= 1; 
        fim_intervalo -= 1;

        //verifica qual agoritmo foi escolhido KMP(kmp.c)
        if (strcmp(algoritmo, "KMP") == 0) {
            if (kmp_buscar(texto_principal, padrao, inicio_intervalo, fim_intervalo)) {
                //se o padrao e encontrado escreve sim no arquivo de saida
                fprintf(arquivo_saida, "sim\n");
            } else {
                //caso contrario escreve nao
                fprintf(arquivo_saida, "não\n");
            }
            //a mesma coisa se aplica abaixo. BM(boyer_moore.c)
        } else if (strcmp(algoritmo, "BM") == 0) {
            if (boyer_moore_buscar(texto_principal, padrao, inicio_intervalo, fim_intervalo)) {
                fprintf(arquivo_saida, "sim\n");
            } else {
                fprintf(arquivo_saida, "não\n");
            }
        } else {
            fprintf(arquivo_saida, "Algoritmo não reconhecido: %s\n", algoritmo);
            free(texto_principal);
            free(padrao);
            fclose(arquivo_entrada);
            fclose(arquivo_saida);
            return 1;
        }
    }
    //marca o fim da medicao do tempo de execucao
    getrusage(RUSAGE_SELF, &tempo_fim);

    //exibe o tempo de execucao usando a funcao exibir_tempo_execucao
    exibir_tempo_execucao(&tempo_inicio, &tempo_fim);

    //libera a memoria
    free(texto_principal);
    free(padrao);

    //fecha os arquivos de entrada e saida
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
    return 0;
}
