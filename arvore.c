/*
programa para criar Nos(Nodes) de acordo com a quantidade que o usuario solicitar;
O programa faz as devidas buscas pelos dados solicitado pelo usuario;

Autor: Claver Ricardo dos Santos Barreto.
Linguagem: C (Estrictamente C).


*/
#include <stdio.h>
#include <stdlib.h>

struct Node{

	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* FetchNewNode(int data){

	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	(*NewNode).data = data;
	(*NewNode).left = NULL; 
	(*NewNode).right = NULL;
	return NewNode;
}

struct Node* Insert(struct Node* root, int data){

	if(root == NULL){
	
		root = FetchNewNode(data);
	}
	else if((*root).data < data){
	
		(*root).right = Insert((*root).right, data);
	}
	else{
		(*root).left = Insert((*root).left, data);
	}
	return root;
}

int Busca(struct Node* root, int data){

	if(root == NULL){
	
		return 0;
	}
	else if((*root).data == data){
	
		return 1;
	}
	else if((*root).data >= data){
	
		return Busca((*root).left, data);
	}
	else{
	
		return Busca((*root).right, data);
	}
}

void main(){

	struct Node* root = NULL; //cria uma arvore vazia
	root = Insert(root, 10); //use scanf to ask data to the user
	root = Insert(root, 20);
	root = Insert(root, 15);
	root = Insert(root, 5);

	int number;
	printf("insert a number:");
	scanf("%i", &number);

	if(Busca(root, number) == 1){
		printf("number found.");
	}
	else{
	
		printf("number not found.");
	}

}
