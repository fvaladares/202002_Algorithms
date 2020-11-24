/*
 * Pilha.c
 *
 *  Created on: 23 de nov de 2020
 *      Author: fabricio
 */

#include "Pilha.h"


Pilha* pilhaVazia(Pilha *pilha) {
	pilha = malloc(sizeof(Pilha*));
	pilha->prox = NULL;
	return pilha;
}

Pilha* push(Pilha *pilha, int dado){
	Pilha *nova = NULL;

	nova = pilhaVazia(nova);

	nova->dado = dado;
	nova->prox = pilha->prox;

	pilha->prox = nova;

	return pilha;
}

int pop(Pilha *pilha){
	int dado;
	Pilha *no = NULL;

	no = pilha->prox;
	dado = no->dado;

	pilha->prox = no->prox;
	free(no);

	return dado;
}
int estaVazia(Pilha *pilha){
	if(pilha->prox) {
		printf("\nPilha não vazia!!\n");
		return 0;
	} else {
		printf("\nPilha vazia!!\n");
		return 1;
	}
}

int top(Pilha *pilha){
	return pilha->prox->dado;
}



