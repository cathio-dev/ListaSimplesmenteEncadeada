#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> //ja tem na biblioteca listaDE
#include "listade.h"


int main(){
    tp_listaDE *listaDE;
    listaDE = inicializa_listaDE;

    if(listaDE_vazia(listaDE)) printf("Lista Vazia");

    insere_listaDE_no_fim(listaDE, 10);
    insere_listaDE_no_fim(listaDE, 20);
    imprime_listaDE(listaDE, 2);
    
    return 0;
}