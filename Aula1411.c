/*
 * main.c
 *
 *  Created on: 13 de nov de 2020
 *      Author: fabricio
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * malloc -- aloca memória dinamicamente
 * calloc -- aloca memória dinamencamente e inicializa com 0
 * realloc -- aumenta a quantidade de memória (insere mais memória)
 * free -- libera a memória
 */

void exemplo01(); // Ponteiro declaração
void exemplo02(); // Ponteiro manipulação
void exemplo03(); // Ponteiro com vetor (trabalhando com vetores)
void exemplo04(); // Alocação de memória
void exemplo05();
void exemplo06();
void printStringInt( char *word, int *pt);


struct tipo_pessoa {
	char *nome = NULL;
	int idade;
	float peso;
};

typedef struct tipo_pessoa tPessoa;

void imprimirPessoa(tPessoa pessoa) {
	printf("\n");
	printf("Nome: %s\n", pessoa.nome);
	printf("Idade: %d\n", pessoa.idade);
	printf("Peso: %.2f\n", pessoa.peso);
	printf("\n");
}

int main() {

	struct tipo_pessoa pessoa;
	tPessoa pessoas[10];

	pessoa.nome = "Fabricio Valadares";
	pessoa.idade = 35;
	pessoa.peso = 90.5f;

	imprimirPessoa(pessoa);




//	exemplo01();
//	exemplo02();
//	exemplo03();
//	exemplo04();
//	exemplo05();
//	exemplo06();






	return 0;
}

void exemplo01 (){
	  int *pt = NULL;
	  int count = 10;

	  pt = &count;

	  *pt = 13;

	  printf("count: %d\n", count); // %d número inteiro
	  printf("*pt: %d\n", *pt);
	  printf("pt: \t\t %p\n", pt); // %p endereço de memória
	  printf("&count: \t %p\n", &count);
	  printf("&pt: \t\t %p\n", &pt); // %p endereço de memória

}

void exemplo02 (){
	int a = 10;
	int b = 20;
	int *pta;
	int *ptb;

	pta = &a;
	ptb = &b;

	printStringInt("Valor de a:", pta);
	printStringInt("Valor de b:", ptb);

	printf("\nDois ponteiros apontando para a mesma variável: \n");

	pta = ptb;

	*pta = 37;

	printStringInt("Valor de a:", pta);
	printStringInt("Valor de b:", ptb);

	pta = &a;

	printf("\nCopiando o conteúdo de um ponteiro no outro: \n");

	*pta = 2020;

	pta = ptb;

	printStringInt("Valor de a:", pta);
	printStringInt("Valor de b:", ptb);

	printf("\n");


	pta = &a;
	ptb = &b;

	printf("Endereço de pta: %p\n", pta);
	pta++;
	printf("Endereço de pta++: %p\n", pta);

	printf("\n");
	pta = &a; // retorna o ponteiro para a posição original
	printStringInt("Valor de a:", pta);

	// incrementa o valor da variável apontada
	(*pta)++;
	printStringInt("Valor de a++:", pta);

}

void exemplo03() {
	int *pt = NULL;
	int num[10];

	// pt aponta para num ou pt = &num[0]
	pt = num;

// Percorrer o vetor usando o ponteiro;
	for (int i = 0; i < 10; i++ ){
	  *pt = i+1; // Alternado o valor do vetor
	  pt++; // incrementa o endereço apontado pelo ponteiro.
	}

	pt = num; // retorna com o ponteiro para a cabeça do vetor

	printf("\nImprimindo: \n");

	for (int i =0; i < 10; i++ ){
	  printf("%d, ", *pt);
	  pt++;
	}
//
//	printf("%li bytes\n", sizeof(int));
//	printf("%li bytes\n", sizeof(float));
//	printf("%li bytes\n", sizeof(double));


}

void exemplo04() {
//	void *malloc (unsigned int num)
//	malloc(sizeof(int))

	int *pt = NULL;

	pt = malloc(sizeof(int)); // reserva memória para um inteiro!

	if (!pt) {
		printf("\n**ERRO: Memória insuficiente!!**\n");
		return;
	}

	printf("\nInforme a idade: ");
	scanf("%d", pt); // endereço onde o dado será salvo

	// imprime o conteúdo associado ao ponteiro
	printf("\nA idade informada foi : %d\n", *pt);

}


void exemplo05() {
	int *pt = NULL;
	int a;

	printf("\nA quantidade de idades: ");
	scanf("%d", &a); // endereço onde o dado será salvo
	// reserva memória para um vetor de inteiros!
	pt = malloc( a * sizeof(int));

	// Preenche o vetor
	for (int i =0; i < a; i++ ){
	  printf("Infore a %da. idade: ", i+1);
	  scanf("%d", &pt[i]);
	}

	printf("\nImprimendo as idades informadas: \n");

	for (int i =0; i < a; i++ ){
	  printf("%d, ", pt[i]);
	}

}


void exemplo06() {
	int *pt = NULL;
	int a;

	printf("\nExemplo 06 A quantidade de idades: ");
	scanf("%d", &a); // endereço onde o dado será salvo
	// reserva memória para um vetor de inteiros!
	pt = malloc( a * sizeof(int));

	// Preenche o vetor
	for (int i =0; i < a; i++ ){
	  printf("Infore a %da. idade: ", i+1);
	  scanf("%d", pt);
	  pt++;
	}

	// retorna para a posição inicial
	for (int i =0; i < a; i++ ){
		pt--;
	}



	printf("\nImprimendo as idades informadas: \n");


	for (int i =0; i < a; i++ ){
	  printf("%d, ", *pt);
	  pt++;
	}

	printf("\n");

	for (int i =0; i < a; i++ ){
		pt--;
	}

	printf("\n%p\n", &pt);

	free(pt); // libera a memória aloca
	pt = NULL;


	printf("\nDepois da mudança: %p\n", &pt);

}
void printStringInt(char *word, int *pt){
	printf("%s %d\n", word, *pt);
}


