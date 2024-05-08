#include <iostream>
using namespace std;

/*
1) Implemente uma função que retorna a posição de um elemento. 
   Será preciso percorrer a lista até que se encontre o elemento cujos campos 
   sejam iguais ao do elemento passado como parâmetro.
   Retorna -1 caso a lista não contenha o elemento.
   Elabore também o programa principal (main) demonstrando como a função é utilizada.
   Segue o protótipo abaixo:

   int posicaoDoElemento(Fila *f, float dado);
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
void insere (Fila *f, float v);
void imprime (Fila* f);
int  posicaoDoElemento (Fila *f, float dado);
int vazia (Fila* f);
void libera (Fila* f);

int main() {
Fila *f = new Fila();
    
int opcao;
float v, num;
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
     
    insere (f, v);
    cout << "\n-----Valor inserido com sucesso!-----" << endl;
break;

case 2:
cout << "----Imprimindo ----" << endl;
imprime (f);
break;

case 3:
cout << " Qual elemento deseja obter a posicao? " << endl;
cin >> num;
int posicao = posicaoDoElemento (f, num);

if (posicao != -1) {
 cout << "O elemento " << num << " foi encontrado na posicao " << posicao << " na fila." << endl;
 } 
else {
  cout << "O elemento " << num << " nao foi encontrado na fila." << endl;
 } 
break;
 

 libera (f);
   } 

   cout << "\nDeseja continuar? s/n para sair digite: n\n";
   cin >> terminar;
    
   } while (terminar != "n");

return 0;
}

void menu(){
  cout << "-------------Digite para---------------";
  cout << "\n\n        1 - Inserir na fila\n";   
  cout << "        2 - Imprimir fila\n";
  cout << "        3 - Imprime posicao de um dado passado\n";   
  cout << "        0 - Sair\n";
  }

Fila *cria (void) {
 Fila *f = new Fila();

 f->ini = f->fim = NULL;
 return f;
}

void insere (Fila *f, float v) {
  No *aux = new No();
  aux->valor = v;           
  aux->prox = NULL;     
  
  if (f->fim != NULL) {
    f->fim->prox = aux;
  }
  f->fim = aux; 

  if (f->ini == NULL) {  
    f->ini = f->fim;
  }
}

void imprime (Fila* f){
  No *aux;
  aux = f->ini;
  while (aux != NULL){
    cout << " Info = " << aux->valor << endl;
    aux = aux->prox;
  }
}

int posicaoDoElemento (Fila* f, float dado) {
   No *verificaPosicao = new No;
   verificaPosicao = f->ini;
   int posicao = 0;

   while (verificaPosicao != NULL) {
   if (verificaPosicao->valor == dado) {
   return posicao;
   }
     verificaPosicao = verificaPosicao->prox;
     posicao++;
  }
 return -1; 
}

int vazia (Fila* f) {
  if (f->ini == NULL) {
   return 1;
  }
  else {
    return 0;
  }
}

void libera (Fila* f) {
  No* aux = f->ini;
  No* tmp;
  while (aux != NULL) {
    tmp = aux->prox;
    delete aux;
    aux = tmp;
  }
  delete f;
}

