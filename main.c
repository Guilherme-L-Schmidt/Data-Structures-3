#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registros.h"
#include "funcionalidades.h"

int main() {
    // detecta o comando numerico para selecionar a funcionalidade
    int comando;
    scanf("%d", &comando);

    // executa a funcionalidade selecionada
    switch(comando) {
        case 1:
            funcionalidade1();
            break;
        case 2:
            funcionalidade2();
            break;
        case 3:

            break;
        case 4:
            break;
        default:
            printf("comando nao encontrado\n");
    }




    return 0;
}

