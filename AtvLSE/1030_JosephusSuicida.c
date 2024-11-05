#include <stdio.h>
#include "listase.h"

int FlaviousJosephus(tp_listase **plista/*, int n, int k*/){
    tp_listase *atu, *ant;
    int pessoa;

    /*for(int i = 0; i < n; i++){ //2, 3, 4, 5, 1 . TESTE
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &pessoa);
        insere_listase_no_fim(plista, pessoa); //DUVIDA, plista já é ponteiro de ponteiro, e na funcao insere passamos o endereço do ponteiro, mas como plista ja tem um endereço do ponteiro, passamos só a PLISTA.
    }*/

    int k = 2;
    insere_listase_no_fim(plista, 2);
    insere_listase_no_fim(plista, 3);
    insere_listase_no_fim(plista, 4);
    insere_listase_no_fim(plista, 5);
    insere_listase_no_fim(plista, 1);


    //primeira parte feita, preencher a lista.
    ///////////////////////////////////////////////
    atu = *plista;
    ant = NULL;

    
    while((atu->prox != *plista) && (atu-> prox != NULL)){
        atu = atu -> prox; //quando prox for NULL, ele volta para o ultimo prox.
    }

    atu -> prox = *plista; //prox final apontapara plista. (inicio)

    //Ciranda feita, circulo de Josephus fechado, agora navegaremos e mataremos

    while(tamanho_listase(*plista) > 1){

        for(int j = 0; j < k; j++){ //enquanto for menor que o gap
        ant = atu;
        atu = atu -> prox;
        }

        ant -> prox = atu -> prox;
        free(atu);
        atu = ant -> prox;
    }

    return printf("\nSobrevivente: %d\n", atu -> info);

}

int main(){
    tp_listase *CirandaSuicidio;
    CirandaSuicidio = inicializa_listase();
    int N, GAP;

    /*printf("Selecione o numero de pessoas: ");
    scanf("%d", &N);

    printf("\nSelecione o numero de saltos entre os suicídios: ");
    scanf("%d", &GAP);
    printf("\n");*/

    FlaviousJosephus(&CirandaSuicidio/*, N, GAP*/);





    return 0;
}