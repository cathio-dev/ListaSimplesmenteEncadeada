#include <stdio.h>
#include "listase.h"

int main(){
    tp_listase *lista;
    lista = inicializa_listase();

    insere_no_inicio_listase(&lista, 30);
    insere_no_inicio_listase(&lista, 20);
    insere_no_inicio_listase(&lista, 10);

    imprime_listase(lista);


}