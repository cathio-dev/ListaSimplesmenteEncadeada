#include <stdio.h>
#include "listase.h"

int main(){
    tp_listase *listaVelhos;
    listaVelhos = inicializa_listase();

    insere_prioritario_listase(&listaVelhos, 10);
    insere_prioritario_listase(&listaVelhos, 57);
    insere_prioritario_listase(&listaVelhos, 61);
    insere_prioritario_listase(&listaVelhos, 70);
    insere_prioritario_listase(&listaVelhos, 4);
    insere_prioritario_listase(&listaVelhos, 3);
    insere_prioritario_listase(&listaVelhos, 67);

    imprime_listase(listaVelhos);
    return 0;
}