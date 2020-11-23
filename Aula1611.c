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
	int data;

	struct myList *next;
}List;

// Define o novo tipo para facilitar a declaração de novas variáveis
//typedef struct myList List;

void printFullList(List *list);
List* newList();
List* insert(List* list, int data);
List* insertAtPosition(List* list, int data, int position);
List* newNode();
List* removeNode(List* list, int data);
int search(List* list, int data);






int main(void) {
	/**
	 *  *myList - Is our list, as it name shows. Here we create an empty list,
	 *  which means that we don't know for what it is pointing.
	 */
	List *myList;
	int searchResult = 0;

	myList = newList(); // Creates an empty list that points to NULL

	// Inserting some elements
	myList = insert(myList, 10);
	myList = insert(myList, 13);
	myList = insert(myList, 38);
	myList = insert(myList, 24);
	myList = insert(myList, 11);

	// Printing the list
	printFullList(myList);

	myList = insertAtPosition(myList, 16, 3);

	printf("\n\n");

	printFullList(myList);

	// Check if a data is on list
	searchResult = search(myList, 13);
	if (searchResult){
		printf("\n");
		printf("The data was found at position: %d", searchResult);
		printf("\n\n");
	} else {
		printf("\n");
		printf("The data was not found.");
		printf("\n\n");
	}

	myList = removeNode(myList, 10);

//	myList = insertAtPosition(myList, 55, 30);
//
	printf("\n\n");
	printFullList(myList);
	printf("\n");


	return EXIT_SUCCESS;
}

List* newList() {
	return NULL;
//	List *node = malloc(sizeof(List));
//	node->next = NULL;
//	return node;
}


// Insere no início da Lista
List* insert(List* list, int data){
	List *node = newNode();

	node->data = data;
	node->next = list;

	return node;
}


List* insertAtPosition(List* list, int data, int position){
	List *aux = list; // ponteiro auxiliar
	List *node = newNode(); // novo nó (em branco)
	int count = 1; // ajuda a encontrar a posição
	position--;

// Procurando a posição correta para inserção.
	while (count != position) {
		aux = aux->next;
		count++;
	}

	node->data = data;
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
		printf("%d, ", list->data);
		if ( count % 10 == 0) {
			printf("\n");
		}
		list = list->next;
	}
}

/**
 * Returns the position where the data was found or
 * 0 if it was not found.
 */
int search(List* list, int data){
	int position = 1; // Indicate in which position the data was found
	while (list!=NULL){
		if( list->data == data) {
			return position;
		}
		list = list->next;
		position += 1;
	}
	return 0;
}


List* removeNode(List* list, int data){
	List* node;
	List* aux;
	int position = 1;
	int i = 1;

	aux = list;

	position = search(list, data);

	if (position) {
		if(position > 1) {
			while(i < position-1) {
				aux = aux->next;
				i+=1;
			}
			printf("\n");
			printf("\nElemento %d removido da lista.", aux->next->data);
			printf("\n");

			node = aux->next;
			aux->next = aux->next->next;

			free(node);
		} else {
			printf("\n");
			printf("\nElemento %d removido da lista.", list->data);
			printf("\n");
			node = list;
			list = list->next;
			free(node);
		}
	} else {
		printf("\n");
		printf("\nElemento não localizado na lista.");
		printf("\n");

	}

	return list;
}
















