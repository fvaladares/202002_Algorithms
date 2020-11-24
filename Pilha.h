/*
 * Pilha.h
 *
 *  Created on: 23 de nov de 2020
 *      Author: fabricio
 */

#ifndef PILHA_H_
#define PILHA_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * Definição da pilha
 */

typedef struct pilha {
	int dado;
	struct pilha *prox;
} Pilha;


/**
 *  Protótipo das funções
 */

Pilha* pilhaVazia(Pilha *pilha); // Cria a pilha vazia
Pilha* push(Pilha *pilha, int dado); // Insere elementos na pilha
int pop(Pilha *pilha); // Remove elementos da pilha
int estaVazia(Pilha *pilha); // Verifica se a pilha está vazia
int top(Pilha *pilha); // Retorna o elemenento que está no topo


#endif /* PILHA_H_ */
