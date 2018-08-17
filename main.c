#include<stdio.h>
#include<stdlib.h>

struct RegFuc{
	int numeroMatricula;
	int idade;
	struct RegFuc *prox;	
};

struct RegFuc *listaRFunc = NULL;

void registrarFunc(){
	struct RegFuc *aux;
	aux = malloc(sizeof(struct RegFuc));
	printf("\n-----------------------------------------------------\n");
	printf("\nRegistrando funcionario...\n");
	printf("Digite o numero da matricula (1-10): ");
	scanf("%d", &aux->numeroMatricula);
	printf("Digite a idade: ");
	scanf("%d", &aux->idade);
	printf("\n");
	printf("-----------------------------------------------------\n\n");
	if(listaRFunc == NULL){
		aux->prox=NULL;
		listaRFunc = aux;
	}else{
		aux->prox=listaRFunc;
		listaRFunc = aux;	
	}			
}

void visualizarRegistro(){
	struct RegFuc *aux;
	if(listaRFunc == NULL){
		printf("\n-----------------------------------------------------\n\n");
		printf("Nao existem funcionarios cadastrados!\n");
		printf("\n-----------------------------------------------------\n\n");
		return;
	}
	aux=listaRFunc;
	printf("\n******************* Funcionarios *******************\n");
	while(1){		
		printf("\nMatricula: %i\n", aux->numeroMatricula);
		printf("Idade: %i\n\n", aux->idade);
		if(aux->prox == NULL){
			printf("\n****************************************************\n\n");
			break;
		}
		printf("\n-----------------------------------------------------\n\n");
		aux=aux->prox;
	}
}

main(){
	int acao;
	
	do{
		printf("Escolha uma opcao:\n");
		printf("0. Sair\n");
		printf("1. Registrar\n");
		printf("2. Visualizar Funcionario\n");		
		printf("command: ");
		scanf("%i", &acao);
		
		if(acao == 1){
			registrarFunc();
			
		}else if(acao == 2){
			visualizarRegistro();
		}		
	}while(acao != 0);
			
}
