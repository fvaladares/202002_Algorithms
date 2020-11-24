/*
 * Main.c
 *
 *  Created on: 23 de nov de 2020
 *      Author: fabricio
 *      AQUI
 */


#include "Pilha.h"
#include "Fila.h"

void testePilha();
void testeFila();

int main(){
//	testePilha();
	testeFila();

	return 0;
}

// Implementação das funções
void testePilha(){
	Pilha *minhaPilha = NULL;

	// Inicia a pilha vazia
	minhaPilha = pilhaVazia(minhaPilha);
	// Testa se a pilha está vazia
	estaVazia(minhaPilha);

	int dado = 2020;
	printf("\nInserindo o elemento %d na pilha\n", dado);
	minhaPilha = push(minhaPilha, dado);

	dado = 2021;
	printf("\nInserindo o elemento %d na pilha\n", dado);
	minhaPilha = push(minhaPilha, dado);

	dado = 2022;
	printf("\nInserindo o elemento %d na pilha\n", dado);
	minhaPilha = push(minhaPilha, dado);

	dado = 2023;
	printf("\nInserindo o elemento %d na pilha\n", dado);
	minhaPilha = push(minhaPilha, dado);

	estaVazia(minhaPilha);

	dado = top(minhaPilha);

	printf("\nTopo da pilha: %d\n", dado);

	dado = pop(minhaPilha);

	printf("\nElemento %d removido da pilha\n",dado);

	dado = top(minhaPilha);

	printf("\nTopo da pilha: %d\n", dado);

	dado = pop(minhaPilha);

	printf("\nElemento %d removido da pilha\n",dado);

	dado = top(minhaPilha);

	printf("\nTopo da pilha: %d\n", dado);

	dado = 2025;
	printf("\nInserindo o elemento %d na pilha\n", dado);
	minhaPilha = push(minhaPilha, dado);

	dado = top(minhaPilha);

	printf("\nTopo da pilha: %d\n", dado);

}


void testeFila() {
	Fila *minhaFila = NULL;

	minhaFila = filaVazia();
	filaEstaVazia(minhaFila);

	int dado = 2020;
	printf("\nTentando inserir o elemento %d\n", dado);
	minhaFila = enfileirar(minhaFila, dado);
	filaEstaVazia(minhaFila);

	imprimirFila(minhaFila);

	dado = 2021;
	printf("\nTentando inserir o elemento %d\n", dado);
	minhaFila = enfileirar(minhaFila, dado);
	dado = 2022;
	printf("\nTentando inserir o elemento %d\n", dado);
	minhaFila = enfileirar(minhaFila, dado);
	dado = 2023;
	printf("\nTentando inserir o elemento %d\n", dado);
	minhaFila = enfileirar(minhaFila, dado);
	dado = 2024;
	printf("\nTentando inserir o elemento %d\n", dado);
	minhaFila = enfileirar(minhaFila, dado);

	for(dado = 2025; dado <= 2050; dado ++){
		minhaFila = enfileirar(minhaFila, dado);
	}

	imprimirFila(minhaFila);

	dado = desenfileirar(minhaFila);
	printf("\nElemento removido da fila: %d\n", dado);

	imprimirFila(minhaFila);

	dado = desenfileirar(minhaFila);
	printf("\nElemento removido da fila: %d\n", dado);
	imprimirFila(minhaFila);


}
