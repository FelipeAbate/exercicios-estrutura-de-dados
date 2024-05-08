#include <iostream>
using namespace std;

/*
4) Elaborar uma função que compare duas filas e retorne 1 ou true se elas forem iguais
   ou 0 ou false se forem diferentes. 
   Duas filas são iguais se os elementos forem iguais, nas mesmas posições e 
   tiverem o mesmo tamanho. 
   Faça um programa principal demonstrando como ela é usada.

   int *compara(Lista *l1, Lista *l2);
*/

typedef struct pessoa { 
int idade;
struct pessoa* prox;  
} Pessoa;           

typedef struct Lista{ 
Pessoa *ini;       
Pessoa *fim;     
} Lista;           

Lista* cria (void);
void insere (Lista* l, int valor );
int vazia (Lista* l);
int compara(Lista* l1, Lista* l2); /// exercicio 4 protótipo
void libera (Lista* l);

int main () {
Lista* l1 = new Lista();
Lista* l2 = new Lista();

    insere (l1, 10);
    insere (l1, 24);
    insere (l1, 32);

    insere (l2, 10);
    insere (l2, 24);
    insere (l2, 44);

    // chamada a funcao compara(); na main()
    int resultado = compara (l1, l2); 

    if (resultado)
        cout << "As listas sao iguais.\n";
    else
        cout << "As listas sao diferentes.\n";

    libera(l1);
    libera(l2);

   return 0;
}
  
Lista *cria (void) {
Lista *l = new Lista();

 l->ini = l->fim = NULL;
 return l;
}

void insere ( Lista *l, int valor ){
  Pessoa *aux = new Pessoa();
  aux->idade = valor;         
  aux->prox = NULL;    

  if (l->fim != NULL) {
    l->fim->prox = aux;
  }
  l->fim = aux; 

  if( l->ini == NULL ) {  
    l->ini = l->fim;
  }
}

///  exercicio 4 função compara duas filas e retornar uma nova  ///
int compara (Lista* l1, Lista* l2) {
    Pessoa* atual1 =  l1->ini;
    Pessoa* atual2 = l2->ini;

    while (atual1 && atual2) {
        if (atual1->idade != atual2->idade) // compara os elementos
        return 0;

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    if (atual1 == atual2) // compara se o tamanho eh igual
     return 1;            // se eh igual return 1

    return 0;             // senao return 0
 }
//////////////////////////////////////////////////////////

int vazia (Lista* l) {
  if (l->ini == NULL) {
   return 1;
  }
  else {
    return 0;
  }
}

void libera (Lista* l) {
  Pessoa* aux = l->ini;
  Pessoa* tmp;
  while (aux != NULL) {
    tmp = aux->prox;
    delete aux;
    aux = tmp;
  }
  delete l;
}
