#include <stdio.h>
#include "listade.h"
#include <stdlib.h>
#include <time.h>

/*void media_listaDE(tp_listaDE *lista){
  tp_no *atu, *ant;
  int soma = 0, tam = 0, media, i = 0/;
  atu = lista->ini;

  if(listaDE_vazia(lista)) return 0;



  while (atu != NULL) {
    soma = soma + atu->info; 
    tam++;
    atu=atu->prox;
  }

  media = soma/tam;
  int x = (rand() % 4);

  switch(x){
    case 1:

    tp_no *novo_no;
    novo_no = aloca_novo_no();
    if(!novo_no) return 0;
    novo_no -> info = media;
    novo_no -> prox = NULL;

    novo_no -> prox = lista -> ini; //o prix do novo_no, aponta para o atual ini, usando o decretor ini, que aponta para ele.
    lista->ini = novo_no; //o inicio recebe o novo_no, atual ini.
    //fim não é alterado.


    break;

    case 2:

    tp_no *novo_no;
    novo_no = aloca_novo_no();
    if(!novo_no) return 0;
    novo_no -> info = media;
    novo_no -> prox = NULL;

    atu = lista->ini;
    while ((atu != NULL) && i != (tam/2)) { //quando tamanho percorrer a metade, insere o nó.
      soma = soma + atu->info; 
      i++;
      atu=atu->prox;
    }

    novo_no -> prox = atu ->prox;
    atu-> prox = novo_no -> ant;






    break;


    case 3:

    tp_no *novo_no;
    novo_no = aloca_novo_no();
    if(!novo_no) return 0;
    novo_no -> info = media;
    novo_no -> prox = NULL;

    novo_no -> ant = lista -> fim; //o ANT do novo_no, aponta para o NÓ ANTERIOR, usando o decretor FIM, que aponta para ele.
    lista -> fim -> prox = novo_no; //o proximo do NÓ anterior, que FIM apontava, assumirá o endereçõ do novo_no.
    lista -> fim = novo_no; //SO DEPOIS DE USARMOS O ARTIFÍCIO DO FIM, podemos alterar ele para o nó alocado.

    break;
  }

  //media feita, vamos para o sortei, e logo após inserção do novo nó na lista.

}*/

//está na biblioteca


int main(){
    tp_listaDE *listaDE;
    listaDE = inicializa_listaDE;

    MediaListaDE(listaDE);
    
    return 0;
}
