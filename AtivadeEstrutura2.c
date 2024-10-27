#include <stdio.h>
#include <stdlib.h>

 struct lista{
 int info;
 struct lista *prox;
 };

 typedef struct lista Lista;

Lista* criaLista(){
 return NULL;
 };

Lista* inserirLista(Lista *lista, int i){
 Lista* novo = (Lista*) malloc(sizeof(Lista));
 novo -> info = i;
 novo -> prox = lista;
 return novo;
 };

 int main(){
 Lista* l;
 l = criaLista();
 l = insereElemento(l, 23);
 l = insereElemento(l, 40);
 return 0;
 };

 void inserirLista(Lista **lista, int i){
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo -> info = i;
   novo -> prox = *lista;
   *lista = novo;
 };

 int main(){
   Lista* l = criaLista();
   insereLista(&l, 23);
   insereLista(&l, 40);
   return 0;
 };

Lista *imprimeLista(Lista *l) {
   Lista *p;
   for (p = l; p != NULL; p = p->prox) {
      printf("%d\n", p->info);
   }
 }

 int listaVazia(Lista *l){
   if(l == NULL){
      return 1;
   }else{
      return 0;
   }
 }

 Lista *buscaLista(Lista *l, int v){
   Lista *p;
   for(p = l; p != NULL; p = p->prox){
      if(p->info == v){
         return p;
      }
    }
    return NULL;
 }

 Lista *retiraLista(Lista *l, int v){
   //ponteiro para elemento anterior
   Lista *ant = NULL;
   //ponteiro para percorrer a lista
   Lista *p = l;
   //procura elemento na lista, guardando anterior
   while(p != NULL && p->info != v){
      ant = p;
      p = p->prox;
   }

//verifica se achou elemento
   if(p == NULL){
      //não achou: retorna lista original
      return l;
   }
   //retira elemento
   if(ant == NULL){
   //retira elemento do inicio
      l = p->prox;
   }else{
   //retira elemento do meio da lista
      ant->prox = p->prox;
   }
   free(p);
   return l;
 }

 void liberaLista(Lista *l){
   Lista *p = l;
   while(p != NULL){
      //guarda referência para o próximo elemento
      Lista *t = p->prox;
      free(p); //libera a memória apontada por p
      p = t; //faz p apontar para o próximo
   }
 }

 Lista* inserirEmOrdem(Lista *l, int v) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;

    Lista* ant = NULL;  // Ponteiro anterior
    Lista* p = l;       // Ponteiro para percorrer

    // Procur a aposição correta para inserir
    while (p != NULL && p->info < v) {
        ant = p;
        p = p->prox;
    }

    // Se for inserido no início
    if (ant == NULL) {
        novo->prox = l;
        l = novo;
    } else {
        // Insere o elemento no meio ou no final
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return l;
}

