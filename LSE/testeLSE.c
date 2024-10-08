#include "listase.h"
#include <stdio.h>

int main(){

    tp_listase *lista; //ponteiro que vai ser a lista
    tp_listase *listaaux;

    lista = inicializa_listase(); //aponta para o endereço do inicializa, o conteúdo será NULL. //como se fizessemos lista = NULL.
    listaaux = inicializa_listase();
    int N = 10;
    int contadorMaiores;

    insere_listase_no_fim(&lista, 10);
    insere_listase_no_fim(&lista, 20);
    insere_listase_no_fim(&lista, 30);
    insere_listase_no_fim(&lista, 57);

    imprime_listase(lista);
    printf("\n");

    destroi_impar_listase(&lista);

    printf("\n");
    imprime_listase(lista);
    printf("\n");

    /*insere_listase_no_fim(&listaaux, 10);
    insere_listase_no_fim(&listaaux, 20);
    insere_listase_no_fim(&listaaux, 30);
    insere_listase_no_fim(&listaaux, 2);

    imprime_listase(listaaux);
    printf("\n");

    int compara = compara_listase(lista, listaaux);
    if(compara == 1){
        printf("\nListas iguais.\n");
    }else{
        printf("\nListas diferentes.\n");
    }*/

    /*contadorMaiores = nos_maiores_n_listase(lista, N);
    printf("\nQNT NOS MAIORES = %d", contadorMaiores);*/

    /*if(listase_vazia(lista) == 1) //passando o ponteiro, que passa o conteúdo dele(por copia) que aponta para o endereço, e vai retornar o conteudo dele na funcao, e ver se é NULL ou outra coisa.
        printf("vazian\n");

    insere_listase_no_fim(&lista, 10); //passamos o endereço do ponteiro, passando por referência, mas a função insere_listase_no_fim, usa um ponteiro do ponteiro como receptor de parâmetro.
    insere_listase_no_fim(&lista, 30);

    if(listase_vazia(lista) == 0){
        printf("Lista tem itens\n\n");
    }

    imprime_listase(lista);

    printf("\n");

    remove_listase(&lista, 10);
    insere_listase_no_fim(&lista, 70);
    insere_listase_no_fim(&lista, 70);
    insere_listase_no_fim(&lista, 70);

    printf("\n");

    imprime_listase(lista);

    int tam = tamanho_listase(lista);
    printf("\nTAMANHO: %d\n", tam);

    insere_listase_no_fim(&listaaux, 70);
    insere_listase_no_fim(&listaaux, 60);
    insere_listase_no_fim(&listaaux, 70);
    insere_listase_no_fim(&listaaux, 80);

    imprime_listase(listaaux);
    printf("\n");

    if(compara_listase(lista, listaaux) == 0){
        printf("\nListas diferentes.");
    }else{
        printf("Listas iguais");
    }*/


    return 0;
}