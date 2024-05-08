#include <iostream>
using namespace std;

/*
2) Elaborar uma função que gere uma cópia de uma fila e retorne uma nova fila.
   Elabore também o programa principal (main) demonstrando como a função é utilizada.
   Segue o protótipo abaixo:

   Fila *copia(Fila *l);
*/

typedef struct no { 
float valor;
struct no* prox;  
} No;

typedef struct Fila{ 
No *ini;       
No *fim;      
} Fila;

void menu();
Fila *cria (void);
void insere (Fila *l, float v);
void imprime (Fila* l);
Fila *copia (Fila *l); // protótipo copia exercicio 2
void imprimeCopia (Fila *l);
int vazia (Fila* l);
void libera (Fila* l);

int main() {
Fila *l = new Fila();

int opcao;
float v;
string terminar;

  do{
menu ();
cout << "----------------------------------------\n\n  ";
cin >> opcao;

if ( (opcao) > 3 || (opcao) < 1 ){
  cout << " OPCAO INVALIDA!" << endl;
}

switch (opcao){

case 1:
    cout << " Insira o valor" << endl;
    cin >> v;
     
    insere (l, v);
    cout << "\n-----Valor inserido com sucesso!-----" << endl;
break;

case 2:
cout << "......Imprimindo: ......." << endl;
imprime (l);
break;

case 3:
cout << "......Copiando nova fila...... " << endl;
cout << "......Imprimindo nova fila: ...... " << endl;
copia(l);  // ex 2: funcao Fila *copia (Fila *l);
imprimeCopia(l); // na main()
break;
 
libera (l);
   } 

   cout << "\nDeseja continuar? s/n \n";
   cin >> terminar;
    
   } while (terminar != "n");

return 0;
}

void menu(){
  cout << "-------------Digite para---------------";
  cout << "\n\n        1 - Inserir na fila\n";   
  cout << "        2 - Imprimir\n";
  cout << "        3 - copiar e imprimir nova fila\n";   
  cout << "        0 - Sair\n";
  }

Fila *cria (void) {
 Fila *l = new Fila();

 l->ini = l->fim = NULL;
 return l;
}

void insere (Fila *l, float v) {
  No *aux = new No();
  aux->valor = v;           
  aux->prox = NULL;     
  
  if (l->fim != NULL) {
    l->fim->prox = aux;
  }
  l->fim = aux; 

  if (l->ini == NULL) {  
    l->ini = l->fim;
  }
}

void imprime (Fila* l){
  No *aux;
  aux = l->ini;
  while (aux != NULL){
    cout << " Info = " << aux->valor << endl;
    aux = aux->prox;
  }
  cout << endl;
}

////////// funcao copia ex 2 ///////////
Fila *copia (Fila *l) {
    Fila *novaFila = new Fila();
    No *atual = l->ini;
    while (atual != NULL) {
        insere(novaFila, atual->valor);
        atual = atual->prox;
    }
    return novaFila;
}///////////////////////////////////////

void imprimeCopia (Fila *l) {
    No *atual = l->ini;
    while (atual != NULL) {
        cout << " Info = " << atual->valor << endl;
        atual = atual->prox;
    }
    cout << endl;
}

int vazia (Fila* l) {
  if (l->ini == NULL) {
   return 1;
  }
  else {
    return 0;
  }
}

void libera (Fila* l) {
  No* aux = l->ini;
  No* tmp;
  while (aux != NULL) {
    tmp = aux->prox;
    delete aux;
    aux = tmp;
  }
  delete l;
}
