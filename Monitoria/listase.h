#ifndef LISTASE.H
#define LISTASE.H
#include <stdio.h>
#include <stdlib.h>

typedef int tp_itemLSE;

typedef struct tp_no{
    tp_itemLSE info;
    struct tp_no *prox;
}tp_listase;

tp_listase * inicializa_listase(){ //"tp_listase *" retornar m ponteiro do tipo tp_lista no return.
    return NULL;
}

int listase_vazia(tp_listase *lista){ //passamos como parâmetro uma cópia do conteúdo de lista, ue vai alterar o conteúdo do ponteiro, vai identificar o que tem na lista, NULL ou não.
    if(lista == NULL) return 1;
    return 0;                                 // usamos listaseVazia(lista) na main

}

tp_listase *aloca_listase(){
    tp_listase *novo_no;
    novo_no=(tp_listase*) malloc(sizeof(tp_listase)); //transforma a memoria alocada em tipo listase, para armazenar no novo_no.
    
    return novo_no; //retorna o novo_no que foi uma alocação dinâmica de um novo pedaço da lista(Nó)
    
}

int insere_listase_no_fim(tp_listase **l, tp_itemLSE e) { //pega o conteúdo que tá no conteúdo do ponteiro inicial, que é o *lista na main.
    tp_listase *novo_no, *atual;
    novo_no = aloca_listase(); //colocando o conteudo de novo_no local, o conteúdo para onde alocalistase aponta, que é a memória alocada.
    if(novo_no==NULL) return 0; //se o novo no for NULL, quer dizer que deu erro, ou está com memória cheia (debug quase indiferente)
        novo_no->info=e;
        novo_no->prox=NULL;
     
    if(listase_vazia(*l)) { //se a lista tiver vazia, ou seja conteudo de *l ser = a null //passamos endereço de outro ponteiro, na lista main, para não perdermos o conteúdo
        *l=novo_no;           //significa que o ponteiro primario é o primeiro NÓ, que assume o valor de novo_no
    }else{
        atual = *l;          //else,criamos a variavel atual, para percorrer os nós até achar o novo no atual
        while(atual->prox!=NULL) {  //enquanto o pointer de atual para o proximo, for diferente que NULL(Está com algum valor dentro),
            atual=atual->prox;            //o atual agora é o próximo, percorrendo assim esse loop até chegar ao final da lista, quando PROX = NULL
        }
        atual->prox=novo_no; //quando sair do loop, o atual estará apontando para o proximo, que será = ao novo_no da lista.
    }
    return 1; //retorna 1 para item inserido.
}

void imprime_listase(tp_listase *lista){
    tp_listase *atual;
    atual = lista; //como lista aponta para o primeiro nó, o ponteiro atual adquire o conteúdo do ponteiro lista, que é o endereço de info do primeiro nó.
    while(atual != NULL){ //enquanto atual não for NULL, vamos printar a informação do atual nó.
        printf("|%d| -> ", atual -> info); //printa atual que aponta para o info do nó.
        atual = atual -> prox; //navegamos, atual agora aponta para o PROX, ue tem endereço do proximo NO.
    }
    printf("NULL");
}

int remove_listase(tp_listase **plista, tp_itemLSE e){
    tp_listase *anterior, *atual;
    atual = *plista; //atual adquire o conteúdo dentro de *plista, que tem o conteúdo de plista, que é o endereço do ponteiro primário, que é lista na main.
    anterior = NULL; //conteúdo de anterior = NULL, agindo com um "-1", de referência de início. Ponteiro que acompanha atual.

    while((atual != NULL) && (atual-> info != e)){ //navega ate achar a info que pedimos, se não achar, retorna zero por atual ser = 0.
        anterior = atual; //anterior recebe o conteúdo de atual, "salvar um checkpoint". ponteiros recebem endereço de memória.
        atual = atual -> prox; //navegando em atual novamente.
    }

    if(atual == NULL) return 0; //se atual for NULL, quer dizer que não achamos o elemento.
    if(anterior == NULL){ //se anterior for NULL, quer dizer que não houve movimento, e o removido foi o primeiro item.
        *plista = atual -> prox; //o conteúdo de lista na main, por meio do ponteiro de lista, o primeiro nó foi removido.
    }else{
        anterior -> prox = atual -> prox; //começa a navegação, e antes de navegar, colocamos o valor que era o proximo nó de atual, para o anterior apontar. basicamente é como se 1 -> 2 -> 3, e agora 1-> -- 3 (2 removido) (ant = 1) aponta para o proximo do removido.
    }

    free(atual); //apagamos o NÓ (malloc)
    atual = NULL; //atual tem conteúdo NULL (formalidade)
    return 1; //retorna (Operação concluída)

}

tp_listase *busca_listase(tp_listase *lista, tp_itemLSE e){ //mesma procura do remove, porém retornando a resposta anterior, se tem ou nao na lista.
    tp_listase *atual;
    atual = lista;
    while((atual != NULL) && (atual->info != e)){
        atual = atual -> prox;
    }

    if(atual == NULL) return NULL;
    return atual;
}

int tamanho_listase(tp_listase *lista){
    int cont = 0;
    tp_listase *atual;
    atual = lista;
    while(atual != NULL){
        cont++;
        atual = atual -> prox;
    }

    return cont;   
}

void destroi_listase(tp_listase **plista){
    tp_listase *atual;
    atual = *plista;

    while(atual != NULL){
        *plista = atual -> prox; //valor de prox, da seu conteudo pra ponteiro lista, fazendo um link pointer, e damos free naquela memória perdida.
        free(atual); //free na memória para desalocar
        atual = *plista; //atual agora é para ponteiro de ponteiro lista denovo
    }

}

/*1 - Construa uma função que faça a inserção de um número inteiro em uma lista encadeada
por ordem numérica.*/

void insere_ordem_listase(tp_listase **plista, tp_itemLSE e){
    tp_listase *anterior, *atual, *novo_no;
    novo_no = aloca_listase();
    novo_no -> info = e; //info do novo nó será o número mandado. Alocaremos o nó, antes ou depois de outro nó.
    atual = *plista;
    anterior = NULL;

    while((atual != NULL) && atual -> info < novo_no -> info){ //se o elemento atual, for maior que do novo no, saíremos, para alocar o no, depois do atual registrado, e antes do proximo do passado
        anterior = atual;
        atual = atual -> prox;
    }

    anterior -> prox = novo_no; //anterior apontando para o novo_no alocado
    novo_no -> prox = atual;    //novo no apontando para proximo atual




}




/*2 - Construa uma função que receba como parâmetros, uma lista encadeada e um número
inteiro n e retorne o número de nós da lista que possuem um campo
info com valores maiores do que n.*/

int nos_maiores_n_listase(tp_listase *lista, int N){
    tp_listase *atual;
    int cont = 0;
    atual = lista; //aponta para o primeir nó.

    while(atual != NULL){
        if(atual->info > N) cont++;
        atual = atual -> prox;
    }

    return cont;
}


/* 3 - Construa uma função que receba duas listas e retorne 1 caso elas sejam idênticas ou 0,
caso contrário. */

int compara_listase(tp_listase *lista, tp_listase *listaaux){

    tp_listase *atual;
    tp_listase *atualaux;
    int verdade = 0; //contador que conta quantas vezes as infos foram iguais. se o numero for igual ao tamanho da lista, retorna 1.

    atual = lista;
    atualaux = listaaux;

    if(tamanho_listase(lista) != tamanho_listase(listaaux)) return 0;

    while(atual != NULL && atualaux != NULL){

        if(atual->info == atualaux->info) verdade++;
        atual = atual -> prox;
        atualaux = atualaux -> prox;
    }

    if(verdade == tamanho_listase(lista)) return 1;

}

/*4 - Construa uma função que receba uma lista encadeada como parâmetro e destrua todos os
nós que contenham valores ímpares.*/

void destroi_impar_listase(tp_listase **plista){
    tp_listase *atual, *anterior;
    atual = *plista;
    anterior = NULL;

    if(listase_vazia(*plista) == 1) printf("Não foi possível, lista vazia.");
    
    while(atual != NULL){

        anterior = atual;       //navegação
        atual = atual -> prox;  //navegação

        if((anterior -> info % 2) != 0){ //ja fizemos uma navegação, para o segundo nó, e o anterior aponta para o primeiro
            remove_listase(plista, anterior -> info);
        }
    }

}

/*5 - Considerando listas de valores inteiros, implemente uma função que receba como
parâmetro duas listas simplesmente encadeadas L1 e L2 e ao final, o último elemento da
lista 1 deve referenciar o primeiro elemento da lista 2 e o inverso também, o último
elemento da lista 2 deve referenciar o primeiro elemento da lista 1, criando assim uma
lista encadeada circular. Por fim, o ponteiro para a lista 2 deve referenciar o primeiro
elemento da lista 1, conforme desenho esquemático abaixo.*/

void ciranda_listase(tp_listase *lista1, tp_listase *lista2){
    tp_listase *atual1, *atual2;
    atual1 = lista1; //vamos caminhar, e juntar o final com o inicio da outra
    atual2 = lista2;

    while(atual1 -> prox != NULL){
        atual1 = atual1 -> prox; //quando prox for NULL, ele volta para o ultimo prox.
    }

    atual1 -> prox = lista2;

    while(atual2 -> prox != NULL){
        atual2 = atual2 -> prox; //quando prox for NULL, ele volta para o ultimo prox.
    }

    atual2 -> prox = lista1;

}

/*Monitoria - Crie uma função que irá inserir um nó sempre no início da lista*/

int insere_no_inicio_listase(tp_listase **plista, tp_itemLSE e){
    tp_listase *atual, *novo_no;
    atual = *plista;
    novo_no = aloca_listase();

    if(novo_no == NULL) return 0;

    novo_no -> info = e;
    novo_no -> prox = atual; //novo no aponta para o que era o primeiro
    *plista = novo_no; //plista recebe o novo no

}

//Monitoria - Manipular a função do insere no início listase

int insere_prioritario_listase(tp_listase **plista, tp_itemLSE e){
    tp_listase *atual, *novo_no;
    novo_no = aloca_listase();

    if(novo_no == NULL) return 0;

    novo_no -> info = e;

    if(listase_vazia(*plista)){
        *plista=novo_no;   
    } //se a lista tiver vazia, ou seja conteudo de *l ser = a null //passamos endereço de outro ponteiro, na lista main, para não perdermos o conteúdo
    //significa que o ponteiro primario é o primeiro NÓ, que assume o valor de novo_no

    atual = *plista;

    if(e >= 60){
        novo_no -> prox = atual; //novo no aponta para o que era o primeiro
        *plista = novo_no; //plista recebe o novo no
    }else{

        novo_no = aloca_listase();
        atual = *plista;


        if(novo_no == NULL) return 0;



        while(atual -> prox != NULL){
            atual = atual -> prox;
        }

        atual -> prox = novo_no; // prox recebe endereço de novo_no


    }
}

/*
int insere_prioridade(tp_listase **l, tp_item e){
    if(e<60){
        insere_listase_no_fim(l, e);
        return 1;
    }
    tp_listase *atu, *ant;
    ant = NULL;
    atu = *l;
    while(atu->info >= 60){ // percorre a lista até que atu seja menor que 60
        ant = atu;
        atu = atu->prox;
    }
    if (ant == NULL) { // inserir primeira prioridade
        insereListaseIni(l,e);
        return 1;
    }
    tp_listase *novo_no = aloca_listase();
    novo_no->info = e;
    
    if (novo_no == NULL) return 0; // nao alocou memoria
    
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
    return 1;
}*/


#endif