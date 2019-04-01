#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>    //Contêm funções para manipulação de caracteres
#include <locale.h>   //Para colocar acentos, acrescenta-se o código abaixo  dentro do int main() setlocale(LC_ALL,"");
#include <conio2.h>   //Para trabalhar com gotoxy(), textcolor(), textbackground(),clrscr()

typedef struct funcionario{
	int cod_func;
	char nome_func[80];
	char nasc_func[11];
	char rg_func[13];
	char cpf_func[15];
	char cel_func[15];
	char email_func[50];
	char data_admissao[11];
	struct funcionario *proximo;
}funcionarios;

typedef struct locacao{
	int cod_loc;
	char data_loc[11];
	char data_devo[11];
	float valor_total;
	float juros;
	float desc;
	int cod_cliente;
	int cod_func;
	char pagamento[8];
	int cod_filme;
	struct locacao *proximo;
}locacoes;

typedef struct devolucao{
	int cod_loc;
	char data_loc[11];
	char data_devo[11];
	float valor_original;
	float valor_pago;
	int dias_atrasados;	
	struct devolucao *proximo;
}devolucoes;

typedef struct cliente{
	int cod_cliente;
	char nome_cliente[80];
	char nasc_cliente[11];
	char rg_cliente[13];
	char cpf_cliente[15];
	char cel_cliente[16];
	char email_cliente[50];
	char endereco[80];
	struct cliente *proximo;
}clientes;

typedef struct genero{
	int cod_gen;
	char nome[80];
	struct genero *proximo;
}generos;

typedef struct filme{
	int cod_filme;
	int cod_gen;
	char nome_filme[80];
	char ano[5];
	char classificacao[50];
	float valor;
	struct filme *proximo;
}filmes;

typedef struct Node{
 int num;
 struct Node *prox;
}node; 

int tam;

void inicia(node *LISTA){
 	LISTA->prox = NULL;
 	tam=0;
}


int vazia(node *LISTA){
 	if(LISTA->prox == NULL)
 	 	return 1;
 	else
  		return 0;
}

node *aloca(){
 	node *novo=(node *) malloc(sizeof(node));
 	if(!novo){
  		printf("Sem memoria disponivel!\n");
  		exit(1);
 	}
	 else{
  		printf("Novo elemento: "); scanf("%d", &novo->num);
  		return novo;
 	}
}

void insereFim(node *LISTA){
	node *novo=aloca();
 	novo->prox = NULL;
	if(vazia(LISTA))
 		LISTA->prox=novo;
 	else{
  	node *tmp = LISTA->prox;
  		while(tmp->prox != NULL)
   			tmp = tmp->prox;
  			tmp->prox = novo;
 }
 	tam++;
}

void insereInicio(node *LISTA){
 	node *novo=aloca(); 
 	node *oldHead = LISTA->prox;
 	LISTA->prox = novo;
 	novo->prox = oldHead;
 	tam++;
}

void exibe(node *LISTA){
 	system("cls");
 	if(vazia(LISTA)){
  		printf("Lista vazia!\n\n");
  		return ;
 	}
 	node *tmp;
 	tmp = LISTA->prox;
 	printf("Lista:");
 	while( tmp != NULL){
  		printf("%5d", tmp->num);
  		tmp = tmp->prox;
 	}
 	printf("\n        ");
 	int count;
 	for(count=0 ; count < tam ; count++){
 	 	printf("  ^  ");
 		printf("\nOrdem:");
 		for(count=0 ; count < tam ; count++){
 			printf("%5d", count+1);
 		}
 	}
 	printf("\n\n");
}

void libera(node *LISTA){
 	if(!vazia(LISTA)){
  		node *proxNode,
     	*atual;
  		atual = LISTA->prox;
  		while(atual != NULL){
   			proxNode = atual->prox;
   			free(atual);
  		 	atual = proxNode;
  		}
	 }
}

void insere(node *LISTA){
 	int pos,
  	count;
 	printf("Em que posição, [de 1 ate %d] você deseja inserir: ", tam);
 	scanf("%d", &pos);
 	if(pos>0 && pos <= tam){
  		if(pos==1)
   			insereInicio(LISTA);
  		else{
   			node *atual = LISTA->prox,
     		*anterior=LISTA; 
   			node *novo=aloca();
    	 	for(count=1 ; count < pos ; count++){
     			anterior=atual;
     			atual=atual->prox;
   			}
   			anterior->prox=novo;
   			novo->prox = atual;
   			tam++;
  		}
   
 	}
	else{
  		printf("Elemento inválido\n\n"); 
  	}	
}

node *retiraInicio(node *LISTA){
 	if(LISTA->prox == NULL){
  		printf("Lista já está vazia\n");
  		return NULL;
 	}
	 else{
  		node *tmp = LISTA->prox;
  		LISTA->prox = tmp->prox;
  		tam--;
  		return tmp;
 	}  
}

node *retiraFim(node *LISTA){
 	if(LISTA->prox == NULL){
  		printf("Lista já vazia\n\n");
  		return NULL;
 	}
	else{
  		node *ultimo = LISTA->prox,
    	*penultimo = LISTA;
  		while(ultimo->prox != NULL){
   			penultimo = ultimo;
   			ultimo = ultimo->prox;
  		}
   		penultimo->prox = NULL;
  		tam--;
  		return ultimo;  
 	}
}

node *retira(node *LISTA){
 	int opt, count;
 	printf("Que posição, [de 1 ate %d] você deseja retirar: ", tam);
 	scanf("%d", &opt);
 	if(opt>0 && opt <= tam){
  		if(opt==1)
   			return retiraInicio(LISTA);
  		else{
   			node *atual = LISTA->prox,
     		*anterior=LISTA; 
   			for(count=1 ; count < opt ; count++){
    			anterior=atual;
    			atual=atual->prox;
   			}
  			anterior->prox=atual->prox;
  			tam--;
  			return atual;
  		}
 	}
	else{
  		printf("Elemento inválido\n\n");
 	 	return NULL;
 	}
}

int menu(void){
	system("cls");
	system("Color 37");	
 	int opt;
 	 for(int i=24;i<65;i++){
		gotoxy(i,23);printf("-"); //For para o prenchimento da parte inferior do menu
	}
	for(int x = 6; x<23; x++){
		gotoxy(64, x);printf("|");
	}	
 	gotoxy(24,5);printf("------------- MENU PRINCIPAL ------------");
    gotoxy(24,6);printf("| Digite a sua escolha: \n" );
    gotoxy(24,7);printf("| 1 - Cadastro Gênero \n" );
    gotoxy(24,8);printf("| 2 - Cadastro Filmes \n" );
    gotoxy(24,9);printf("| 3 - Cadastro Cliente \n");
    gotoxy(24,10);printf("| 4 - Cadastro Funcionário \n" );
    gotoxy(24,11);printf("| 5 - Cadastro Locação \n" );
    gotoxy(24,12);printf("| 6 - Fazer Devolução \n");
    gotoxy(24,13);printf("| 7 - Excluir gênero \n" );
    gotoxy(24,14);printf("| 8 - Excluir Filmes \n" );
    gotoxy(24,15);printf("| 9 - Excluir Cliente \n");
    gotoxy(24,16);printf("| 10 - Excluir Funcionário \n" );
    gotoxy(24,17);printf("| 11 - Excluir Locação \n" );
    gotoxy(24,18);printf("| 12 - Listar locação data específica \n");
    gotoxy(24,19);printf("| 13 - Listar filmes em atraso \n");
    gotoxy(24,20);printf("| 14 - Listar devolução \n");
    gotoxy(24,21);printf("| 15 - Sair \n" );
    gotoxy(24,22);printf("| Opção : " );
	gotoxy(33,22);scanf("%d", &opt);
 	return opt;
}

void opcao(node *LISTA, int op){
 	node *tmp;
 	switch(op){
  	case 0:
   		libera(LISTA);
   		system("pause");
   	break;
   
  	case 1:
   		libera(LISTA);
   		inicia(LISTA);
   		system("pause");
   	break;
  
  	case 2:
   		exibe(LISTA);
   		system("pause");
   	break;
  
  	case 3:
   		insereInicio(LISTA);
   		system("pause");
   	break;  
   
  	case 4:
   		insereFim(LISTA);
   		system("pause");
   	break;
   
  	case 5:
   		insere(LISTA);
   		system("pause");
   	break;
  
  	case 6:
   		tmp= retiraInicio(LISTA);
   		printf("Retirado: %3d\n\n", tmp->num);
   		system("pause");
   	break;
   
  	case 7:
   		tmp= retiraFim(LISTA);
   		printf("Retirado: %3d\n\n", tmp->num);
   		system("pause");
   	break;
  
  	case 8:
   		tmp= retira(LISTA);
   		printf("Retirado: %3d\n\n", tmp->num);
   		system("pause");
   	break;
   	
	case 9:
   		exibe(LISTA);
   		system("pause");
   	break;
   	
   	case 10:
   		exibe(LISTA);
   		system("pause");
   	break;
  
    case 11:
   		exibe(LISTA);
   		system("pause");
   	break;
   	
   	case 12:
   		exibe(LISTA);
   		system("pause");
   	break;
   	
   	case 13:
   		exibe(LISTA);
   		system("pause");
   	break;
   	
   	case 14:
   		exibe(LISTA);
   		system("pause");
   	break;
   	
   	case 15:
   		exibe(LISTA);
   		system("pause");
   	break;
   	
  	default:
   		printf("Comando inválido\n\n");
   		system("pause");
 	}
}

int main(){
	setlocale(LC_ALL,"");
 	node *LISTA = (node *) malloc(sizeof(node));
 	if(!LISTA){
  		printf("Sem memória disponível!\n");
  		exit(1);
	}
	else{
 		inicia(LISTA);
 		int opt;
 		do{
  			opt=menu();
  			opcao(LISTA,opt);
 		}while(opt);
 		free(LISTA);
 		return 0;
 	}
}
