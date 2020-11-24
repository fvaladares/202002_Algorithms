/*
 * Fila.c
 *
 *  Created on: 23 de nov de 2020
 *      Author: fabricio
 */


#include "Fila.h"
// Implementação das funções

Fila* filaVazia() {
	Fila *fila = NULL;

	fila = (Fila *) malloc(sizeof(Fila*));
	fila->prox = fila;

	return fila;
}
Fila* enfileirar(Fila *fila, int dado){
	Fila *novoNo = NULL;

	novoNo = filaVazia();
	novoNo->prox = fila->prox;
	fila->prox = novoNo;
	fila->dado = dado;

	return novoNo;
}
int desenfileirar(Fila *fila){
	Fila *aux = NULL;

	aux = fila->prox;
	int dado = aux->dado;

	fila->prox = aux->prox;
	free(aux);

	return dado;
}
int filaEstaVazia(Fila *fila){
	if( fila->prox == fila) {
		printf("\nFila vazia\n");
		return 1;
	} else {
		printf("\nFila NÃO vazia\n");
		return 0;
	}
}
void imprimirFila(Fila *fila){
	Fila *aux = NULL;

	printf("\nA fila: ");
	aux = fila->prox;
	while (aux != fila) {
		printf("%d <- ", aux->dado);
		aux = aux ->prox;
	}
	printf("\n");
}







