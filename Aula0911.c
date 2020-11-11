/*
 ============================================================================
 Name        : Aula0911.c
 Author      : Fabricio Valadares
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NOTAS 4

// Declaração das funções
void exPonteiro();

void printIntArray(int vetor[]);

void printIntPArray(int *vetor);

void executarTodosOsExemplos();

void exemploPonteiro() {
//	int i = 10;
//	int *notas = NULL;
//	int qtdNotas = 0;
	int *pVariavel = NULL;

	printf("\nEndereço da variável: %p\n", pVariavel);
	// Reserva espaço de memória suficiente para um inteiro;
	pVariavel = malloc (sizeof(int));

	printf("Informe um número: ");
	scanf("%d", pVariavel);

	printf("\nO valor informado foi: %d\n", *pVariavel);
	printf("\nEndereço da variável: %p\n", pVariavel);
	printf("\nEndereço da variável: %p\n", &pVariavel);

	free(pVariavel);

	printf("\nO valor informado foi: %d\n", *pVariavel);
	printf("\nEndereço da variável: %p\n", pVariavel);
	printf("\nEndereço da variável: %p\n", &pVariavel);

	pVariavel = malloc (sizeof(int));
	printf("Informe um número: ");
	scanf("%d", pVariavel);
	printf("\nO valor informado foi: %d\n", *pVariavel);
	printf("\nEndereço da variável: %p\n", pVariavel);
	printf("\nEndereço da variável: %p\n", &pVariavel);
}



// ****** MAIN ******
int main(void) {
//	int *p = NULL;
//
//	p = malloc(sizeof(int));
//
//	*p = 55;
//
//	scanf("%d", p);
//
//	printf("\n%i\n", *p);

	int *pNotas = NULL;
	int qtdNotas = 0;

	printf("\nInforme a quantidade de notas desejada: ");
	scanf("%d", &qtdNotas);

	// Alocação dinâmica de memória para um vetor
	pNotas = (int*) malloc(qtdNotas * sizeof(int));

	printf("\n-----------------------\n");
	for (int i = 0; i < qtdNotas; i++) {
		printf("Informe a nota %d: ", i+1);
		scanf("%d", &pNotas[i]);
	}

	printf("\n-----------------------\n");
	for (int i = 0; i < qtdNotas; i++) {
		printf("A nota %d: %d\n", i+1, pNotas[i]);
	}










//	printf("Por favor, informe a quantidade de notas desejadas: ");
//	scanf("%d", &qtdNotas);

	// Desmarque a opção abaixo para executar todos os exemplos.. :)
//	executarTodosOsExemplos();

//	printf("Por favor, informe as notas");
//	for (int i = 0; i < NOTAS; i++) {
//		printf("\nNota %d: ", i+1);
//		scanf("%d", &notas[i]);
//	}
//
//	printIntArray(notas);

	// pNotas -> 0x1ffff01

	return 0;
}




// Implementação das funções

void exPonteiro(){

	// Declaração das variáveis
	int numero;
	int *pNumero;

	// Inicializando as variáveis
	numero = 10;
	pNumero = &numero;

	printf("Variável \t| Valor \t\t| Endereço\n");
	printf("Número \t\t| %d \t\t\t| %p\n", numero, numero);
	printf("pNumero \t| %p \t| %p\n", pNumero, &pNumero);
	printf("Valor do ponteiro: %d", *pNumero);
}

void printIntArray(int vetor[]) {
	printf("\nNotas inseridas: ");
	for (int i = 0; i < NOTAS; i++) {
		printf("\n\tNota %2d: %2d", i+1, vetor[i]);
	}
	vetor[0] = 15;
}

void printIntPArray(int *vetor){
	int *pVetor;
	pVetor = vetor;
	printf("\nNotas inseridas: ");
	for (int i = 0; i < NOTAS; i++){
		printf("\n\tNota %2d: %2d", i+1, *pVetor);
		pVetor++; // incrementa a posição do ponteiro.
	}
	pVetor = vetor;
	*pVetor = 25;
}


void executarTodosOsExemplos() {
	//	const int qtdNotas = 12;

		int notas[NOTAS];
		int *pNotas;
		// Ponteiro aponta para a primeira posição do vetor de notas
		pNotas = notas;

		printf("Por favor, informe as notas");
		for (int i = 0; i < NOTAS; i++) {
			printf("\nNota %d: ", i+1);
			scanf("%d", &notas[i]);
		}

		printf("\nNotas inseridas: ");
		for (int i = 0; i < NOTAS; i++) {
			printf("\n\tNota %2d: %2d", i+1, notas[i]);
		}

		printf("\n-------------USANDO PONTEIROS-----------------");
		printf("\nNotas inseridas: ");
		for (int i = 0; i < NOTAS; i++){
			printf("\n\tNota %2d: %2d", i+1, *pNotas);
			pNotas++; // incrementa a posição do ponteiro.
		}

		printf("\n-------------USANDO FUNÇÃO-----------------");
		printIntArray(notas);

		printf("\n-------------USANDO FUNÇÃO 2 -----------------");
		printIntArray(notas);

		printf("\n-------------USANDO FUNÇÃO 3 PONTEIROS -----------------");
		printIntPArray(notas);

		printf("\n-------------USANDO FUNÇÃO-----------------");
			printIntArray(notas);
}

