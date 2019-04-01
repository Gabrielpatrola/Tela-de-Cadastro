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

typedef struct Item{ 
    generos genero;
    filmes filme;
    clientes cliente;
    funcionarios funcionario;
    locacoes locacao;
    devolucoes devolucao;
    struct Item *proximo; 
}Itens;

typedef struct Filas{ 
    Itens *inicio; 
    Itens *fim; 
}Fila;

void Inicializar(Fila **fila){ 
    // -> Recebe a fila por referencia 
    //    para inicialização
    *fila = (Fila *) malloc(sizeof(Fila)); 
    (*fila)->inicio = NULL; 
    (*fila)->fim = NULL; 
}

int EstaVazia(Fila *fila){ 
    return fila->inicio == NULL; 
}

void Inserir(Fila *fila, int elemento) 
{ 
    Itens *novo; 
    novo = (Itens *)malloc(sizeof(Itens));  

    // -> Verifica se a memória foi alocada com sucesso 
    if (novo != NULL) 
    { 
        novo->genero.cod_gen = elemento; 
        fflush(stdin);
    	printf("digite nome do gênero:");
    	fgets(novo->genero.nome, 80, stdin);
		fflush(stdin);
		novo->proximo = NULL;
		
        if(EstaVazia(fila)) 
        { 
            // -> Primeiro Item da Fila. 
            fila->inicio = novo; 
            fila->fim = novo; 
        } 
        else 
        { 
            // -> Ultimo item da Fila 
            fila->fim->proximo = novo; 
            fila->fim=novo; 
        } 
    } 
}


void Inserir_cliente(Fila *fila, int elemento){ 
    Itens *novo; 
    novo = (Itens *)malloc(sizeof(Itens));
	int aux, valor;
	char nome; 
    // -> Verifica se a memória foi alocada com sucesso 
    if (novo != NULL){ 
    	fflush(stdin);
 		novo->cliente.cod_cliente = elemento;  
		fflush(stdin);	
		
    	printf("digite nome:");
    	fgets(novo->cliente.nome_cliente, 80, stdin);
		fflush(stdin);
		
		printf("digite a data de nascimento:");
    	fgets(novo->cliente.nasc_cliente, 11, stdin);
		fflush(stdin);
		
		printf("digite o rg:");
    	fgets(novo->cliente.rg_cliente, 13, stdin);
		fflush(stdin);
		
		printf("digite o cpf:");
    	fgets(novo->cliente.cpf_cliente, 15, stdin);
		fflush(stdin);
		
		printf("digite o numero de celular:");
    	fgets(novo->cliente.cel_cliente, 16, stdin);
		fflush(stdin);
		
		printf("digite o email:");
    	fgets(novo->cliente.email_cliente, 50, stdin);
		fflush(stdin);
		
		printf("digite o endereco:");
    	fgets(novo->cliente.endereco, 80, stdin);
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

void Inserir_funcionario(Fila *fila, int elemento){ 
    Itens *novo; 
    novo = (Itens *)malloc(sizeof(Itens));
	int aux, valor;
	char nome; 
    // -> Verifica se a memória foi alocada com sucesso 
    if (novo != NULL){ 
    	fflush(stdin);
 		novo->funcionario.cod_func = elemento;  
		fflush(stdin);	
		
    	printf("digite nome:");
    	fgets(novo->funcionario.nome_func, 80, stdin);
		fflush(stdin);
		
		printf("digite a data de nascimento:");
    	fgets(novo->funcionario.nasc_func, 11, stdin);
		fflush(stdin);
		
		printf("digite a data de admissão:");
    	fgets(novo->funcionario.data_admissao, 11, stdin);
		fflush(stdin);
		
		printf("digite o rg:");
    	fgets(novo->funcionario.rg_func, 13, stdin);
		fflush(stdin);
		
		printf("digite o cpf:");
    	fgets(novo->funcionario.cpf_func, 15, stdin);
		fflush(stdin);
		
		printf("digite o numero de celular:");
    	fgets(novo->funcionario.cel_func, 16, stdin);
		fflush(stdin);
		
		printf("digite o email:");
    	fgets(novo->funcionario.email_func, 50, stdin);
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

void Inserir_Filme(Fila *fila, int elemento, int auxiliar){ 
    Itens *novo; 
    novo = (Itens *)malloc(sizeof(Itens));
	float valor;
	int aux;
	char nome; 
    // -> Verifica se a memória foi alocada com sucesso 
    if (novo != NULL){ 
    	fflush(stdin);
 		novo->filme.cod_filme = elemento;  
 		novo->filme.cod_gen = auxiliar;
		fflush(stdin);	
		
    	printf("digite nome do filme:");
    	fgets(novo->filme.nome_filme, 80, stdin);
		fflush(stdin);
		
		printf("digite o ano do filme:");
    	fgets(novo->filme.ano, 5, stdin);
		fflush(stdin);
		
		printf("digite a classificação do filme:");
    	fgets(novo->filme.classificacao, 50, stdin);
		fflush(stdin);
		
		printf("digite o valor do filme:");
		scanf("%f", &valor);
		novo->filme.valor = valor;
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

void Inserir_locacao(Fila *fila, int elemento, int fun, int clin){ 
    Itens *novo; 
    novo = (Itens *)malloc(sizeof(Itens));
	float valor;
	int aux; 
    // -> Verifica se a memória foi alocada com sucesso 
    if (novo != NULL){ 
    	fflush(stdin);
 		novo->locacao.cod_loc = elemento;  
 		novo->locacao.cod_cliente = clin;
 		novo->locacao.cod_func = fun;
		fflush(stdin);	
		
    	printf("Digite data de locação:");
    	fgets(novo->locacao.data_loc, 11, stdin);
		fflush(stdin);
		
		printf("digite data de devolução:");
    	fgets(novo->locacao.data_devo, 11, stdin);
		fflush(stdin);
		
		printf("digite valor total:");
		scanf("%f", &valor);
    	novo->locacao.valor_total = valor;
		fflush(stdin);
		
		printf("Pagamento:");
		scanf("%f", &valor);
		fgets(novo->locacao.pagamento, 8, stdin);		
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
            printf("Codigo do gênero -> %d", item->genero.cod_gen); 
            printf("\nNome do gênero -> %s\n", item->genero.nome);
            item = item->proximo; 
        } 
    }
    printf("---------------------------------\n"); 
}

void MostrarFila_Filme(Fila *fila){     
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
            printf("Codigo do Filme -> %d\n", item->filme.cod_filme); 
            printf("Nome do Filme-> %s", item->filme.nome_filme);
            printf("Codigo do Gênero -> %d", item->filme.cod_gen); 
            printf("\nAno do Filme -> %s", item->filme.ano); 
            printf("Classificação -> %s", item->filme.classificacao);
            printf("Valor -> %f\n", item->filme.valor); 
            item = item->proximo; 
        } 
    }
    printf("---------------------------------\n"); 
}

void MostrarFila_cliente(Fila *fila){     
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
            printf("Codigo do Cliente -> %d\n", item->cliente.cod_cliente); 
            printf("Nome do Cliente -> %s", item->cliente.nome_cliente);
            printf("Data de Nascimento -> %s", item->cliente.nasc_cliente); 
            printf("RG -> %s", item->cliente.rg_cliente); 
            printf("CPF -> %s", item->cliente.cpf_cliente);
            printf("Celular -> %s", item->cliente.cel_cliente);
			printf("Email -> %s", item->cliente.email_cliente);  
			printf("Endereco -> %s", item->cliente.endereco); 
            item = item->proximo; 
        } 
    }
    printf("---------------------------------\n"); 
}

void MostrarFila_funcionario(Fila *fila){     
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
            printf("Codigo do Funcionário -> %d\n", item->funcionario.cod_func); 
            printf("Nome do Funcionário -> %s", item->funcionario.nome_func);
            printf("Data de Nascimento -> %s", item->funcionario.nasc_func); 
        	printf("Data de Admissão -> %s", item->funcionario.data_admissao); 
            printf("RG -> %s", item->funcionario.rg_func); 
            printf("CPF -> %s", item->funcionario.cpf_func);
            printf("Celular -> %s", item->funcionario.cel_func);
		printf("Email -> %s", item->funcionario.email_func);  
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
    Fila *genero = NULL;
	Fila *filme = NULL; 
	Fila *cliente = NULL;
	Fila *funcionario = NULL;
	Fila *locacao = NULL;
	Fila *devolucao = NULL;
    int opcao,tam;
	int auxiliar, clin, fun; 
    int numero;
    Inicializar(&genero);
	Inicializar(&filme);  
	Inicializar(&cliente);  
	Inicializar(&funcionario);
	Inicializar(&locacao);
	Inicializar(&devolucao);
   do{
    Menu(); 
    scanf("%i", &opcao);
	system("cls");
        switch (opcao){ 
            case 1: 
                printf( "Digite codigo do gênero: "); 
                scanf("%d", &numero);
                Inserir(genero, numero); 
                MostrarFila(genero);
                system("pause");
                break; 
            case 2: 
            	printf( "Digite codigo do filme: ");
            	scanf("%d", &numero); 
            	printf("Digite o codigo do gênero: ");
            	scanf("%d", &auxiliar);
				Inserir_Filme(filme, numero, auxiliar); 
                MostrarFila_Filme(filme);
            	system("pause");
                break;          
            case 3: 
            	printf("Digite o codigo do cliente: ");
            	scanf("%d", &numero);
				Inserir_cliente(cliente, numero); 
                MostrarFila_cliente(cliente);
            	system("pause");
                break;
            case 4:
				printf("Digite o codigo do funcionário: ");
            	scanf("%d", &numero); 
            	Inserir_funcionario(funcionario, numero);
            	MostrarFila_funcionario(funcionario);
				system("pause");
                break;
        	case 5:
				printf("Digite o codigo da locação: ");
				scanf("%d", &numero);
				printf("Digite o codigo do cliente: ");
				scanf("%d", &clin);
				printf("Digite o codigo do funcionario: ");
				scanf("%d", &fun);
				Inserir_locacao(locacao, numero, clin, fun);
        		break;
        	case 6:
        
                system("pause");
        		break;
        	case 7:
        		Retirar(genero); 
        		MostrarFila(genero);
        		system("pause");
        		break;
        	case 8:
        		Retirar(filme); 
        		MostrarFila_Filme(filme);
        		system("pause");
        		break;
        	case 9:
        		Retirar(cliente); 
        		MostrarFila_cliente(cliente);
        		system("pause");
        		break;
        	case 10:
        		Retirar(funcionario); 
        		MostrarFila_funcionario(funcionario);
        		system("pause");
        		break;
        	case 11:
        		Retirar(locacao);
        		system("pause");
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
                printf( "Escolha inválida.\n\n"); 
                system("pause");
                break; 
        }    
    }while (opcao!=15);
    system("pause"); 
    return 0;
}
