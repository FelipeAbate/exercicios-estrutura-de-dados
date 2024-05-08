# exercicios-estrutura-de-dados

## estrutura de dados do tipo fila! sem bibloteca QUEUE!

Curso: ADS UNIARA 2° SEMESTRE ESTRUTURA DE DADOS 2024
Tarefa 4: Estrutura de Dados 
Luiz Felipe Abate 11/03/2024


Utilize um compilador C++ para ajudá-lo (ex: Dev C++, Code Blocks, etc.)

1) Implemente uma função que retorna a posição de um elemento. Será preciso percorrer a lista até que se encontre o elemento cujos campos sejam iguais ao do elemento passado
como parâmetro. Retorna -1 caso a lista não contenha o elemento. Elabore também o programa principal (main) demonstrando como a função é utilizada. Segue o protótipo abaixo:

int posicaoDoElemento(Fila *f, float dado);


2) Elaborar uma função que gere uma cópia de uma fila e retorne uma nova fila. Elabore também o programa principal (main) demonstrando como a função é utilizada. Segue o protótipo abaixo:

Fila *copia(Fila *l);


3) Elaborar uma função que concatene duas filas e retorne uma nova fila. Elabore também o programa principal (main) demonstrando como a função é utilizada. Segue o protótipo abaixo:

Fila *concatena(Fila *l1, Fila *l2);

4) Elaborar uma função que compare duas filas e retorne 1 ou true se elas forem iguais ou 0 ou false se forem diferentes. Duas filas são iguais se os elementos forem iguais, nas mesmas posições e tiverem o mesmo tamanho. Faça um programa principal demonstrando como ela é usada.

int *compara(Lista *l1, Lista *l2);

