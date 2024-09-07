#include "uteis.h"

//estruturas para armazenar e calcular o tempo de usuario e sistema
void exibir_tempo_execucao(struct rusage *inicio, struct rusage *fim) {
    struct timeval tempo_usuario, tempo_sistema;
    timersub(&fim->ru_utime, &inicio->ru_utime, &tempo_usuario);
    timersub(&fim->ru_stime, &inicio->ru_stime, &tempo_sistema);

    printf("Tempo de usuário: %ld.%06ld segundos\n", tempo_usuario.tv_sec, tempo_usuario.tv_usec);
    printf("Tempo de sistema: %ld.%06ld segundos\n", tempo_sistema.tv_sec, tempo_sistema.tv_usec);
}

//funcao para ler uma string 
char* ler_string(FILE *arquivo) {
    // Capacidade inicial do buffer
    int capacidade = 16;
    //alocacao de memoria para a string
    char *str = (char *)malloc(capacidade * sizeof(char));
    if (str == NULL) {
        perror("Erro ao alocar memória");
        return NULL;
    }

    //tamnho atual da string
    int tamanho = 0;
    //var para armazenar o caractere lido
    int c;
    //for para ler caracteres
    while ((c = fgetc(arquivo)) != EOF && c != '\n' && c != ' ') {
        if (tamanho + 1 >= capacidade) {
            //dobra a capacidade do buffer
            capacidade *= 2;
            str = (char *)realloc(str, capacidade * sizeof(char));
            if (str == NULL) {
                perror("Erro ao realocar memória");
                return NULL;
            }
        }
        //adiciona o caractere lido a string e aumenta o tamanho
        str[tamanho++] = c; 
    }
    str[tamanho] = '\0';

    return str;
}
