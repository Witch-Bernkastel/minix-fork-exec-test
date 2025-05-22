#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <numero_de_processos>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Número inválido de processos.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Erro ao criar processo");
            exit(1);
        } else if (pid == 0) {
            execl("./hello", "hello", NULL);
            perror("Erro ao executar exec");
            exit(1);
        }
    }

    sleep(2); // dar tempo dos filhos imprimirem
    return 0;
}