/*
 * Fila.h
 *
 *  Created on: 23 de nov de 2020
 *      Author: fabricio
 */

#ifndef FILA_H_
#define FILA_H_
#include <stdio.h>
#include <stdlib.h>


typedef struct fila {
	int dado;
	struct fila *prox;
} Fila;


// Assinatura das funções
Fila* filaVazia(); // Criar fila vazia
Fila* enfileirar(Fila *fila, int dado); // Inserir elementos
int desenfileirar(Fila *fila); // Remover elementos
int filaEstaVazia(Fila *fila); // Fila está vazia?
void imprimirFila(Fila *fila); // Imprimir fila


#endif /* FILA_H_ */
