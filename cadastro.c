/*************************************************************************
DescriÃ§Ã£o do Algoritmo: O trabalho prÃ¡tico 03 consiste na criaÃ§Ã£o de um programa que vai simular um sistema de
locaÃ§Ã£o de filmes. Para isso vocÃªs devem usar a estrutura de lista dinÃ¢mica simples.
Nome da Disciplina: Estrutura de Dados
Nome Professor: Leonair
Nome Aluno: Gabriel Augusto Queiroz de Almeida
Turma: Estrutura de Dados
RGA: 201611901002
Data Entrega:
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>    //ContÃ©m funÃ§Ãµes para manipulaÃ§Ã£o de caracteres
#include <locale.h>   //Para colocar acentos, acrescenta-se o cÃ³digo abaixo  dentro do int main() setlocale(LC_ALL,"");
#include <conio2.h>   //Para trabalhar com gotoxy(), textcolor(), textbackground(),clrscr()

typedef struct dado{
	int codigo;
	char nome[80];
	float valor;
	int qt;
}dados;

typedef struct Item{ 
    dados numero;
    struct Item *proximo; 
}Itens;

typedef struct Filas{ 
    Itens *inicio; 
    Itens *fim; 
}Fila;

void Inicializar(Fila **fila){ 
    // -> Recebe a fila por referencia 
    //    para inicializï¿½-la 
    *fila = (Fila *) malloc(sizeof(Fila)); 
    (*fila)->inicio = NULL; 
    (*fila)->fim = NULL; 
}

int EstaVazia(Fila *fila){ 
    return fila->inicio == NULL; 
}

void Inserir(Fila *fila, int elemento){ 
    Itens *novo; 
    novo = (Itens *)malloc(sizeof(Itens));
	int aux, valor;
	char nome; 
    // -> Verifica se a memória foi alocada com sucesso 
    if (novo != NULL){ 
    	fflush(stdin);
 		novo->numero.codigo = elemento;  
		fflush(stdin);	
		
		printf("digite quantidade:");	
    	scanf("%d", &aux);
    	novo->numero.qt = aux; 
    	fflush(stdin);
    	
    	printf("digite valor:");
    	scanf("%d", &valor );
    	novo->numero.valor= valor; 
    	fflush(stdin);
    	
    	printf("digite nome:");
    	fgets(novo->numero.nome, 80, stdin);
		fflush(stdin);
        novo->proximo = NULL;
        
        if(EstaVazia(fila)){ 
            // -> Primeiro Item da Fila. 
            fila->inicio = novo; 
            fila->fim = novo; 
        } 
        else{ 
            // -> Ultimo item da Fila 
            fila->fim->proximo = novo; 
            fila->fim=novo; 
        } 
    } 
}

void Retirar(Fila *fila){ 
    Itens *item;
    if(!EstaVazia(fila)) 
    { 
        item = fila->inicio; 
        fila->inicio = item->proximo; 
        free(item);

        // -> Se a fila acabou devemos atualizar o final 
        if (fila->inicio == NULL) 
            fila->fim = NULL; 
    } 
}

void MostrarFila(Fila *fila){     
	int i = 0; 
    Itens *item; 
    printf("\n\n Listando...\n\n"); 
    printf("---------------------------------\n");
    if (EstaVazia(fila)){ 
        printf ("A Fila esta vazia!\n"); 
    } 
    else{       
        item = fila->inicio;
        while(item != NULL){ 
            i++; 
            printf("Item [%i]\n",i); 
            printf("Codigo-> %d\t", item->numero.codigo); 
            printf("Nome-> %s\t", item->numero.nome); 
            printf("Qt-> %d\t", item->numero.qt); 
            printf("Valor-> %.2f\n", item->numero.valor); 
            item = item->proximo; 
        } 
    }
    printf("---------------------------------\n"); 
}

void Menu(){   
	system("cls");
	system("Color 37");	
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
    gotoxy(24,10);printf("| 4 - Cadastro funcionário \n" );
    gotoxy(24,11);printf("| 5 - Cadastro Locação \n" );
    gotoxy(24,12);printf("| 6 - Fazer Devolução \n");
    gotoxy(24,13);printf("| 7 - Excluir gênero \n" );
    gotoxy(24,14);printf("| 8 - Excluir Filmes \n" );
    gotoxy(24,15);printf("| 9 - Excluir Cliente \n");
    gotoxy(24,16);printf("| 10 - Excluir Funcionário \n" );
    gotoxy(24,17);printf("| 11 - Excluir Locação \n" );
    gotoxy(24,18);printf("| 12 - Listar locação data especifica \n");
    gotoxy(24,19);printf("| 13 - Listar filmes em atraso \n");
    gotoxy(24,20);printf("| 14 - Listar devolução \n");
    gotoxy(24,21);printf("| 15 - Sair \n" );
    gotoxy(24,22);printf("| Opção : " );
}

int tamanho (Fila *fila){ /*Retorna o tamanho da fila*/ 
	Itens *p;
	int cont = 0; 
	p = fila->inicio;
	while (p != NULL){ 
		cont ++; 
    	p = p->proximo; 
   	}
	return cont;
 }

int main(){   
 	setlocale(LC_ALL,"");
    Fila *fila = NULL; 
    int opcao,tam; 
    int numero;
    Inicializar(&fila); 
   do{
    Menu(); 
    scanf("%i", &opcao);
	system("cls");
        switch (opcao){ 
            case 1: 
                printf( "Digite um numero: "); 
                scanf("%d", &numero);
                Inserir(fila, numero); 
                MostrarFila(fila);
                system("pause");
                break; 
            case 2: 
                Retirar(fila); 
                MostrarFila(fila);
                system("pause");
                break;          
            case 3: 
                tam= tamanho(fila); 
                printf( "Tamanho Fila=%d\n",tam);
                system("pause");
                break;
            case 4: 
                   exit;
                   break;
        	case 5:
        		
        		break;
        	case 6:
        		
        		break;
        	case 7:
        		
        		break;
        	case 8:
        		
        		break;
        	case 9:
        		
        		break;
        	case 10:
        		
        		break;
        	case 11:
        		
        		break;
        	case 12:
        		
        		break;
        	case 13:
        		
        		break;
        	case 14:
        		
        		break;
        	case 15:
        		exit;
        		break;	
            default:
                printf( "Escolha invalida.\n\n"); 
                system("pause");
                break; 
        }    
    }while (opcao!=15);
    system("pause"); 
    return 0;
}
