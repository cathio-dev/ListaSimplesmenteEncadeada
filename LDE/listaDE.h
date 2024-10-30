#ifndef LISTADE_H
#define LISTADE_H
#include <stdio.h>
#include <stdlib.h>
  
typedef int tp_item;

typedef struct tp_no_aux { //memoria alocada para o novo nó na lista.
    struct tp_no_aux *ant;
    tp_item info;
    struct tp_no_aux *prox;
} tp_no;

typedef struct {  //memoria alocada para o descritor.
    tp_no *ini;
    tp_no *fim;
    int tamanho; 
} tp_listaDE;



//Aloca um nó da lista
tp_no *aloca_novo_no() {
  tp_no* pt;
  pt=(tp_no*) malloc(sizeof(tp_no));
  return pt;
}


int listaDE_vazia(tp_listaDE *lista) {
  if  (lista->ini == NULL) 
  return 1; 
  return 0;
}





tp_listaDE *inicializa_listaDE(){
    tp_listaDE *lista=(tp_listaDE*) malloc(sizeof(tp_listaDE));
    lista -> ini = NULL;
    lista -> fim = NULL;
    lista -> tamanho = 0;
    return lista; //retornamos o endereço de memória que aponta para a memória alocada para o ponteiro de lista na main.
}

int insere_listaDE_no_fim(tp_listaDE *lista, tp_item e){
  tp_no *novo_no;
  novo_no = aloca_novo_no();
  if(!novo_no) return 0;
  novo_no -> info = e;
  novo_no -> prox = NULL;

  if(listaDE_vazia(lista)){
    novo_no -> ant = NULL;
    lista -> fim = novo_no; //fim é o próprio nó
    lista -> ini = novo_no; //ini será o próprio nó, ambos decretores estão no primeiro nó.
  }else{ //se não for o primeiro item(nó):
    novo_no -> ant = lista -> fim; //o ANT do novo_no, aponta para o NÓ ANTERIOR, usando o decretor FIM, que aponta para ele.
    lista -> fim -> prox = novo_no; //o proximo do NÓ anterior, que FIM apontava, assumirá o endereçõ do novo_no.
    lista -> fim = novo_no; //SO DEPOIS DE USARMOS O ARTIFÍCIO DO FIM, podemos alterar ele para o nó alocado.
  }

  lista -> tamanho ++;

}

int remove_listaDE (tp_listaDE *lista, tp_item e){
  tp_no *atu;
  atu = lista -> ini; //atu recebe o endereço do primeiro nó.

  while( (atu != NULL) && (atu -> info != e)){ //enquanto info nao for o que pediu, e nao for null
    atu = atu -> prox;
  }

  if(atu == NULL) return 0;

  if(lista -> ini == lista -> fim){ //se for o unico elemento da lista
    lista -> ini = lista -> fim = NULL; //tornamos o inicio e o fim NULL. deixando a lista vazia.
  }



  else if(lista -> ini == atu){ //primeiro elemento da lista
    lista -> ini = atu -> prox; //o inicio passa a ser o proximo nó.
    atu -> prox -> ant = NULL; //e atu prox, que era o proximo nó (agora primeiro), tem o anterior NULL.
  }

  else if(lista ->fim == atu){ //se atu parar no fim, quer dizer que o elemento a se remover será o último.
    lista -> fim = atu -> ant; //fim, será o nó anterior ao último.
    atu = atu -> ant; //estabelecendo o novo atu.
    atu -> prox = NULL; //atribuí o valor de prox do novo último nó = NULL.
  }else{
    atu->prox->ant = atu->ant; //NO CADERNO
    atu->ant->prox = atu-> prox; //NO CADERNO.
  }

  free(atu);
  lista-> tamanho--; //excluí um do tamanho
  return 1;
  
}

  

  
//imprime os conteudos da lista (de frente para tras ou de tras pra frente)
/*void imprime_listad(tp_listad *lista, int ordem) {
  if (lista==NULL)
  printf("Lista n o inicializada");�
  else {
  tp_no *atu;
  switch (ordem) {
    case 1: atu = lista->ini;
      while (atu != NULL) {
        printf("%d ", atu->info);
          atu=atu->prox;
      }
    break;
    case 2: atu = lista->fim;
      while (atu != NULL) {
        printf("%d ", atu->info);
          atu=atu->ant;
      }
    break;
    default: printf("codigo invalido");
  }
  }  
  printf("\n");
}*/

#endif