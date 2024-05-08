#include <iostream>
using namespace std;

/*
3) Elaborar uma função que concatene duas filas e retorne uma nova fila.
   Elabore também o programa principal (main) demonstrando como a função é utilizada.
   Segue o protótipo abaixo:

   Fila *concatena(Fila *l1, Fila *l2);
*/

typedef struct pessoa { 
int idade;
struct pessoa* prox;  
} Pessoa;           

typedef struct Fila{ 
Pessoa *ini;       
Pessoa *fim;     
} Fila;           

Fila* cria (void);
void insere ( Fila* f, int valor );
float retira (Fila* f);
int vazia ( Fila* f );
Fila* concatenar(Fila* l1, Fila* l2); /// exercicio 3 protótipo
void exibirFila(Fila* f);
void libera ( Fila* f );

int main () {
// Criando e inicializando as filas
Fila* l1 = new Fila();
Fila* l2 = new Fila();

insere (l1, 10);
insere (l1, 20);
insere (l1, 30);
cout << " Fila 1 info: ";
exibirFila (l1);
      
insere (l2, 40);
insere (l2, 50);
insere (l2, 60);
cout << " Fila 2 info: ";
exibirFila (l2);    

Fila* novaFila = concatenar(l1, l2);
cout << "\n Nova fila concatenada: ";
exibirFila(novaFila);

    delete l1;
    delete l2;
    delete novaFila;

   return 0;
}
  
Fila* cria (void){
Fila* f = new Fila();
f->ini = f->fim = NULL;
return f;
}

void insere ( Fila *f, int valor ){
  Pessoa *aux = new Pessoa();
  aux->idade = valor;         
  aux->prox = NULL;    

  if (f->fim != NULL) {
    f->fim->prox = aux;
  }
  f->fim = aux; 

  if( f->ini == NULL ) {  
    f->ini = f->fim;
  }
}

float retira (Fila* f){
  int d;
  if (vazia (f)){
    cout << "Fila vazia" << endl;
    exit (1);
  }
  d = f->ini->idade;

  Pessoa *segundo = f->ini->prox;
  delete f->ini;
  
  f->ini = segundo;
  if (f->ini == NULL) {
    f->fim = NULL;
  }
  return d;
}

int vazia (Fila* f) {
  if (f->ini == NULL) {
   return 1;
  }
  else {
    return 0;
  }
}

///  exercicio 3 função concatenar duas filas e retornar uma nova  ///
Fila* concatenar (Fila* l1, Fila* l2) {
    Fila* novaFila = new Fila();
    
    // Concatenando elementos da primeira fila
    Pessoa* atual = l1->ini;
    while (atual != NULL) {
        insere (novaFila, atual->idade);
        atual = atual->prox;
    }

    // Concatenando elementos da segunda fila
    atual = l2->ini;
    while (atual != NULL) {
        insere (novaFila, atual->idade);
        atual = atual->prox;
    }
    return novaFila;
}

void exibirFila (Fila* f) {
    Pessoa* atual = f->ini;
    cout << "Fila: ";
    while (atual != NULL) {
        cout << atual->idade << " ";
        atual = atual->prox;
    }
    cout << endl;
}
//////   exercicio 3   função /////////

void libera (Fila* f) {
  Pessoa* aux = f->ini;
  Pessoa* tmp;
  while (aux != NULL) {
    tmp = aux->prox;
    delete aux;
    aux = tmp;
  }
  delete f;
}
