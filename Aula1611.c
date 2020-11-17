/*
 ============================================================================
 Name        : ListaLigada.c
 Author      : Fabricio Valadares
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Estrutura do novo tipo de dado
typedef struct myList {
	int info;

	struct myList *next;
}List;

// Define o novo tipo para facilitar a declaração de novas variáveis
//typedef struct myList List;

List* newList();
List* insert(List* list, int info);
List* insertAtPosition(List* list, int info, int position);
List* newNode();
void printFullList(List *list);




int main(void) {
	// Nossa nova lista
	List *myList; // Cria um ponteiro (não sei o que tem dentro dele)

	myList = newList(); // aponta para nulo

	myList = insert(myList, 10);
	myList = insert(myList, 13);
	myList = insert(myList, 38);
	myList = insert(myList, 24);
	myList = insert(myList, 11);

	printFullList(myList);

	myList = insertAtPosition(myList, 16, 3);

	printf("\n\n");

	printFullList(myList);

	myList = insertAtPosition(myList, 55, 30);

	printf("\n\n");

	printFullList(myList);


	return EXIT_SUCCESS;
}

List* newList() {
	return NULL;
//	List *node = malloc(sizeof(List));
//	node->next = NULL;
//	return node;
}


// Insere no início da Lista
List* insert(List* list, int info){
	List *node = newNode();

	node->info = info;
	node->next = list;

	return node;
}

/*TODO: Corrigir o erro quando a posição ultrapassar o limite da lista!! 
* Lembre-se o fim da lista é marcado por um NULL
*/
List* insertAtPosition(List* list, int info, int position){
	List *aux = list; // ponteiro auxiliar
	List *node = newNode(); // novo nó (em branco)
	int count = 1; // ajuda a encontrar a posição
	position--;

// Procurando a posição correta para inserção.
	while (count != position) {
		aux = aux->next;
		count++;
	}

	node->info = info;
	node->next = aux->next;
	aux->next = node;

	return list;
}


List* newNode() {
	return (malloc(sizeof(List*)));
}



void printFullList(List *list) {
	int count = 1;
	while(list != NULL) {
		printf("%d, ", list->info);
		if ( count % 10 == 0) {
			printf("\n");
		}
		list = list->next;
	}
}



















