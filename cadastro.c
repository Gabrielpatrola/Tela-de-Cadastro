/*************************************************************************
Nome da Disciplina: Estrutura de Dados
Nome Professor: Leonair Neves Sousa
Nome Aluno: Gabriel Augusto Queiroz de Almeida
Turma: VE1
RGA: 201611901002
Data Entrega:
*************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <conio2.h>
#include <windows.h>
#include <locale.h> // Para colocar acentos, acrescenta-se o código abaixo dentro do int main setlocale(LC_ALL,"")

//defines para o controle nos menus
#define ACIMA 72
#define ABAIXO 80
#define ENTER 13
#define ESC 27

void gotoxy( int x, int y ){
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct funcionario{
    int cod_func;
    char nome_func[80];
    char nasc_func[11];
    char rg_func[13];
    char cpf_func[15];
    char cel_func[15];
    char email_func[50];
    char data_admissao[11];
    struct funcionario *prox;
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
    struct locacao *prox;
}locacoes;

typedef struct devolucao{
    int cod_loc;
    char data_loc[11];
    char data_devo[11];
    float valor_original;
    float valor_pago;
    int dias_atrasados; 
    struct devolucao *prox;
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
    struct cliente *prox;
}clientes;

typedef struct genero{
    int cod_gen;
    char nome_genero[80];
    struct genero *prox;
}generos;

typedef struct filme{
    int cod_filme;
    int cod_genero;
    char nome_filme[80];
    char ano[5];
    char classificacao[50];
    float valor;
    struct filme *prox;
}filmes;

int tam;
int tam_loc;
void inicia(generos *gen){
    gen->prox = NULL;
    tam=0;
}
void inicia_filme(filmes *fil){
    fil->prox = NULL;
    tam=0;
}
void inicia_cliente(clientes *clin){
    clin->prox = NULL;
    tam=0;
}
void inicia_funcionario(funcionarios *func){
    func->prox = NULL;
    tam=0;
}
void inicia_locacao(locacoes *loc){
    loc->prox = NULL;
    tam=0;
}

int vazia(generos *gen){
    if(gen->prox == NULL)
        return 1;
        else
        return 0;
}

int vazia_filme(filmes *fil){
    if(fil->prox == NULL)
        return 1;
        else
        return 0;
}

int vazia_cliente(clientes *clin){
    if(clin->prox == NULL)
        return 1;
        else
        return 0;
}

int vazia_funcionario(funcionarios *func){
    if(func->prox == NULL)
        return 1;
        else
        return 0;
}

int vazia_locacao(locacoes*loc){
    if(loc->prox == NULL)
        return 1;
        else
        return 0;
}

generos *aloca(){
    generos *novo=(generos *) malloc(sizeof(generos));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
    	gotoxy(24,8);printf("------------------------------------------------------------");
    	gotoxy(23,7);printf("|");
		gotoxy(84,7);printf("|");
    	gotoxy(24,5);printf("---------------------------- MENU---------------------------");
        gotoxy(23,6);printf("| Digite o Codigo do Genero:                                 |"); 
		gotoxy(51,6);scanf("%d", &novo->cod_gen); 
		fflush(stdin);
	
		gotoxy(25,7);printf("Digite o nome do genero:");
        fgets(novo->nome_genero, 80, stdin);
        fflush(stdin);
        return novo;
    }
}

void insereInicio(generos *gen){
    generos *novo=aloca(); 
    generos *oldHead = gen->prox;
    gen->prox = novo;
    novo->prox = oldHead;
    tam++;
}

void exibe(generos *gen){
    system("cls");
    if(vazia(gen)){
    	gotoxy(24,5);printf("---------------------------- MENU---------------------------");
        gotoxy(23,6);printf("| Lista de gêneros vazia!                                    |");
        gotoxy(23,7);printf("|");
		gotoxy(84,7);printf("|");
        gotoxy(24,8);printf("------------------------------------------------------------");
       	gotoxy(25,7);system("pause");
        return;
    }
    generos *tmp;
    tmp = gen->prox;
    while( tmp != NULL){
    	gotoxy(24,9);printf("------------------------------------------------------------");
    	gotoxy(23,6);printf("|");
		gotoxy(84,6);printf("|");
    	gotoxy(23,7);printf("|");
		gotoxy(84,7);printf("|");
		gotoxy(23,8);printf("|");
		gotoxy(84,8);printf("|");
    	gotoxy(24,5);printf("---------------------------- MENU---------------------------");
        gotoxy(25,6);printf("Codigo [%d]\n", tmp->cod_gen);
        gotoxy(25,7);printf("Nome:%s\n", tmp->nome_genero);
        tmp = tmp->prox;
        gotoxy(25,8);system("pause");
    }
        printf("\n\n");
}

void libera(generos *gen){
    if(!vazia(gen)){
        generos *proxgeneros, *atual;
        atual = gen->prox;
        while(atual != NULL){
            proxgeneros = atual->prox;
            free(atual);
            atual = proxgeneros;
        }
    }
}

//funcao para checar se o genero existe antes de registrar o filme
int generoExiste(generos *gen, int cod_gen){
    generos *tmp;
	tmp = gen->prox;
	while(tmp != NULL) {
		if(tmp->cod_gen == cod_gen)
			return 1;
		else
		   tmp = tmp->prox;
	}
    return 0;
}

int clienteExiste(clientes *clin, int cod_cliente){
    clientes *tmp;
	tmp = clin->prox;
	while(tmp != NULL) {
		if(tmp->cod_cliente == cod_cliente)
			return 1;
		else
		   tmp = tmp->prox;
	}
    return 0;
}

int funcionarioExiste(funcionarios *func, int cod_func){
    funcionarios *tmp;
	tmp = func->prox;
	while(tmp != NULL) {
		if(tmp->cod_func == cod_func)
			return 1;
		else
		   tmp = tmp->prox;
	}
    return 0;
}

int filmeExiste(filmes *fil, int cod_filme){
    filmes *tmp;
	tmp = fil->prox;
	while(tmp != NULL) {
		if(tmp->cod_filme == cod_filme)
			return 1;
		else
		   tmp = tmp->prox;
	}
    return 0;
}


filmes *aloca_filme(generos *gen){
	int aux;
	generos *tmp;
    filmes *novo=(filmes *) malloc(sizeof(filmes));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
    	system("cls");
    	for(int i=24;i<90;i++){
			gotoxy(i,12);printf("-"); //For para o prenchimento da parte inferior do menu
		}        
		for(int i=6;i<12;i++){
			gotoxy(90,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		for(int i=6;i<12;i++){
			gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
    	gotoxy(24,5);printf("---------------------------- FILMES ------------------------------");
		gotoxy(25,6);printf("Digite o codigo do genero:");
    	scanf("%d", &aux);
    	generoExiste(gen, aux);
    	if(generoExiste(gen, aux) == 1){
			novo->cod_genero = aux;
			system("cls");
			for(int i=24;i<90;i++){
				gotoxy(i,12);printf("-"); //For para o prenchimento da parte inferior do menu
			}        
			for(int i=6;i<12;i++){
				gotoxy(90,i);printf("|"); //For para o prenchimento da parte lateral do menu
			} 
			for(int i=6;i<12;i++){
				gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
			} 
			gotoxy(24,5);printf("---------------------------- FILMES ------------------------------");
    		gotoxy(25,6);printf("Digite o Codigo do filme: ");
			scanf("%d", &novo->cod_filme); 
        	fflush(stdin);
        
        	gotoxy(25,7);printf("Digite o nome do filme:");
        	fgets(novo->nome_filme, 80, stdin);
       		fflush(stdin);
        
			gotoxy(25,8);printf("Digite o ano do filme:");
       		fgets(novo->ano, 5, stdin);
        	fflush(stdin);
        
        	gotoxy(25,9);printf("Digite a classifiacação do filme:");
        	fgets(novo->classificacao, 50, stdin);
        	fflush(stdin);

			gotoxy(25,10);printf("Digite o valor do filme: "); 
        	scanf("%f", &novo->valor); 
        	fflush(stdin);
        	gotoxy(25,11);system("pause");
		}
		else{
			system("cls");
			printf("Codigo do Genero Invalido!\n");
			system("pause");
		}
    }
        return novo;
}

void insereInicio_filme(filmes *fil, generos *gen){
    filmes *novo=aloca_filme(gen); 
    filmes *oldHead = fil->prox;
    fil->prox = novo;
    novo->prox = oldHead;
    tam++;
}


void exibe_filme(filmes *fil){
    system("cls");
    if(vazia_filme(fil)){
        gotoxy(24,5);printf("---------------------------- FILMES ---------------------------");
        gotoxy(23,6);printf("| Lista de filmes vazia!                                        |");
        gotoxy(23,7);printf("|");
		gotoxy(87,7);printf("|");
        gotoxy(24,8);printf("---------------------------------------------------------------");
       	gotoxy(25,7);system("pause");
        return;
    }
    filmes *ptr;
    ptr = fil->prox;
    while( ptr != NULL){
    	for(int i=24;i<90;i++){
			gotoxy(i,13);printf("-"); //For para o prenchimento da parte inferior do menu
		}        
		for(int i=6;i<13;i++){
			gotoxy(90,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		for(int i=6;i<13;i++){
			gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
    	gotoxy(24,5);printf("---------------------------- FILMES ------------------------------");
        gotoxy(25,6);printf("Codigo do filme [ %d ]", ptr->cod_filme);
        gotoxy(25,7);printf("Nome do filme: %s", ptr->nome_filme);
       	gotoxy(25,8);printf("Codigo do Genero: %i", ptr->cod_genero);
        gotoxy(25,9);printf("Ano: %s ", ptr->ano);
        gotoxy(25,10);printf("Classificação: %s", ptr->classificacao);
        gotoxy(25,11);printf("Valor: %.5f", ptr->valor);
        ptr = ptr->prox;
        gotoxy(25,12);system("pause");
    }
}

void libera_filme(filmes *fil){
    if(!vazia_filme(fil)){
        filmes *proxfilmes,
        *atual;
        atual = fil->prox;
        while(atual != NULL){
            proxfilmes = atual->prox;
            free(atual);
            atual = proxfilmes;
        }
    }
}

void insere_filme(filmes *fil, generos *gen){
    int pos,
    count;
    printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
    scanf("%d", &pos);
     
    if(pos>0 && pos <= tam){
        if(pos==1)
            insereInicio_filme(fil, gen);
        else{
            filmes *atual = fil->prox,
            *anterior=fil; 
            filmes *novo=aloca_filme(gen);
            for(count=1 ; count < pos ; count++){
                anterior=atual;
                atual=atual->prox;
            }
            anterior->prox=novo;
            novo->prox = atual;
            tam++;
        }  
     }
    else
        printf("Elemento invalido\n\n");  
}

void insere(generos *gen){
    int pos,
    count;
    printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
    scanf("%d", &pos);
     
    if(pos>0 && pos <= tam){
        if(pos==1)
            insereInicio(gen);
        else{
            generos *atual = gen->prox,
            *anterior=gen; 
            generos *novo=aloca();
            for(count=1 ; count < pos ; count++){
                anterior=atual;
                atual=atual->prox;
            }
            anterior->prox=novo;
            novo->prox = atual;
            tam++;
        }  
     }
    else
        printf("Elemento invalido\n\n");  
}

generos *retiraInicio(generos *gen){
    if(gen->prox == NULL){
        printf("gen ja esta vazia\n");
        return NULL;
    }
    else{
        generos *tmp = gen->prox;
        gen->prox = tmp->prox;
        tam--;
        return tmp;
    }    
}

generos *retira(generos *gen){
    int opt,
    count;
    printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
    scanf("%d", &opt);
     
    if(opt>0 && opt <= tam){
        if(opt==1)
            return retiraInicio(gen);
        else{
            generos *atual = gen->prox,
            *anterior=gen; 
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
        printf("Elemento invalido\n\n");
        return NULL;
    }
}

filmes *retiraInicio_filmes(filmes *fil){
    if(fil->prox == NULL){
        printf("fil ja esta vazia\n");
        return NULL;
    }
    else{
        filmes *tmp = fil->prox;
        fil->prox = tmp->prox;
        tam--;
        return tmp;
    }    
}

filmes *retira_filmes(filmes *fil){
    int opt,
    count;
    printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
    scanf("%d", &opt);
     
    if(opt>0 && opt <= tam){
        if(opt==1)
            return retiraInicio_filmes(fil);
        else{
            filmes *atual = fil->prox,
            *anterior=fil; 
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
        printf("Elemento invalido\n\n");
        return NULL;
    }
}
clientes *aloca_cliente(){
    clientes *novo=(clientes *) malloc(sizeof(clientes));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
    	system("cls");
    	for(int i=24;i<90;i++){
			gotoxy(i,15);printf("-"); //For para o prenchimento da parte inferior do menu
		}        
		for(int i=6;i<15;i++){
			gotoxy(90,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		for(int i=6;i<15;i++){
			gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
    	gotoxy(24,5);printf("---------------------------- Clientes ----------------------------");
    	gotoxy(25,6);printf("Digite o Codigo do Cliente:");
        scanf("%d", &novo->cod_cliente); 
        fflush(stdin);
        
        gotoxy(25,7);printf("Digite o nome do cliente:");
        fgets(novo->nome_cliente, 80, stdin);
        fflush(stdin);
        
        gotoxy(25,8);printf("Digite a data de nascimento:");
        fgets(novo->nasc_cliente, 11, stdin);
        fflush(stdin);
        
        gotoxy(25,9);printf("Digite o RG do cliente:");
        fgets(novo->rg_cliente, 13, stdin);
        fflush(stdin);
        
        gotoxy(25,10);printf("Digite o CPF do cliente:");
        fgets(novo->cpf_cliente, 15, stdin);
        fflush(stdin);
        
        gotoxy(25,11);printf("Digite o celular do cliente:");
        fgets(novo->cel_cliente, 16, stdin);
        fflush(stdin);
        
		gotoxy(25,12);printf("Digite o email do cliente:");
        fgets(novo->email_cliente, 50, stdin);
        fflush(stdin);
        
        gotoxy(25,13);printf("Digite o endereço do cliente:");
        fgets(novo->endereco, 50, stdin);
        fflush(stdin);
        gotoxy(25,14);system("pause");
        return novo;
    }
}

void insereInicio_cliente(clientes *clin){
    clientes *novo=aloca_cliente(); 
    clientes *oldHead = clin->prox;
    clin->prox = novo;
    novo->prox = oldHead;
    tam++;
}

void exibe_cliente(clientes *clin){
    system("cls");
    if(vazia_cliente(clin)){
    	gotoxy(24,5);printf("---------------------------- Clientes -------------------------");
        gotoxy(23,6);printf("| lista de Clientes vazia!                                      |");
        gotoxy(23,7);printf("|");
		gotoxy(87,7);printf("|");
        gotoxy(24,8);printf("---------------------------------------------------------------");
        gotoxy(25,7);system("pause");
        return;
    }
    clientes *ptr;
    ptr = clin->prox;
    while( ptr != NULL){
    	for(int i=24;i<90;i++){
			gotoxy(i,15);printf("-"); //For para o prenchimento da parte inferior do menu
		}        
		for(int i=6;i<15;i++){
			gotoxy(90,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		for(int i=6;i<15;i++){
			gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
    	gotoxy(24,5);printf("---------------------------- Clientes ----------------------------");
        gotoxy(25,6);printf("Codigo [ %d ]", ptr->cod_cliente);
        gotoxy(25,7);printf("Nome : %s", ptr->nome_cliente);
        gotoxy(25,8);printf("Nascimento : %s", ptr->nasc_cliente);
        gotoxy(25,9);printf("RG : %s", ptr->rg_cliente);
        gotoxy(25,10);printf("CPF :  %s", ptr->cpf_cliente);
        gotoxy(25,11);printf("Celular : %s", ptr->cel_cliente);
        gotoxy(25,12);printf("E-mail : %s", ptr->email_cliente);
        gotoxy(25,13);printf("Endereço : %s", ptr->endereco);
        ptr = ptr->prox;
        gotoxy(25,14);system("pause");
    }
}

void libera_cliente(clientes *clin){
    if(!vazia_cliente(clin)){
        clientes *proxclientes,
        *atual;
        atual = clin->prox;
        while(atual != NULL){
            proxclientes = atual->prox;
            free(atual);
            atual = proxclientes;
        }
    }
}

funcionarios *aloca_funcionario(){
    funcionarios *novo=(funcionarios *) malloc(sizeof(funcionarios));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
       	system("cls");
    	for(int i=24;i<90;i++){
			gotoxy(i,15);printf("-"); //For para o prenchimento da parte inferior do menu
		}        
		for(int i=6;i<15;i++){
			gotoxy(90,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		for(int i=6;i<15;i++){
			gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		gotoxy(24,5);printf("---------------------------- FUNCIONARIOS-------------------------");
    	gotoxy(25,6);printf("Digite o Codigo do Funcionario: ");
		scanf("%d", &novo->cod_func); 
        fflush(stdin);
        
        gotoxy(25,7);printf("Digite o nome do funcionario:");
        fgets(novo->nome_func, 80, stdin);
       	fflush(stdin);
        
		gotoxy(25,8);printf("Digite a data de nascimento:");
       	fgets(novo->nasc_func, 11, stdin);
        fflush(stdin);
        
        gotoxy(25,9);printf("Digite o RG:");
        fgets(novo->rg_func, 13, stdin);
        fflush(stdin);

		gotoxy(25,10);printf("Digite o CPF: "); 
        fgets(novo->cpf_func, 15, stdin);
        fflush(stdin);
        
        gotoxy(25,11);printf("Digite o Celular: "); 
        fgets(novo->cel_func, 15, stdin);
        fflush(stdin);
        
        gotoxy(25,12);printf("Digite o Email: "); 
        fgets(novo->email_func, 50, stdin);
        fflush(stdin);
        
        gotoxy(25,13);printf("Digite a data de admissão: "); 
        fgets(novo->data_admissao, 11, stdin);
        fflush(stdin);
        
        gotoxy(25,14);system("pause");
        return novo;
    }
}

void insereInicio_funcionario(funcionarios *func){
    funcionarios *novo=aloca_funcionario(); 
    funcionarios *oldHead = func->prox;
    func->prox = novo;
    novo->prox = oldHead;
    tam++;
}

void exibe_funcionario(funcionarios *func){
    system("cls");
    if(vazia_funcionario(func)){
        printf("func vazia!\n\n");
        return;
    }
    funcionarios *ptr;
    ptr = func->prox;
    while( ptr != NULL){
 for(int i=24;i<90;i++){
			gotoxy(i,15);printf("-"); //For para o prenchimento da parte inferior do menu
		}        
		for(int i=6;i<15;i++){
			gotoxy(90,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
		for(int i=6;i<15;i++){
			gotoxy(23,i);printf("|"); //For para o prenchimento da parte lateral do menu
		} 
    	gotoxy(24,5);printf("---------------------------- FUNCIONARIOS ----------------------------");
        gotoxy(25,6);printf("Codigo [ %d ]", ptr->cod_func);
        gotoxy(25,7);printf("Nome : %s", ptr->nome_func);
        gotoxy(25,8);printf("Nascimento : %s", ptr->nasc_func);
        gotoxy(25,9);printf("RG : %s", ptr->rg_func);
        gotoxy(25,10);printf("CPF :  %s", ptr->cpf_func);
        gotoxy(25,11);printf("Celular : %s", ptr->cel_func);
        gotoxy(25,12);printf("E-mail : %s", ptr->email_func);
        gotoxy(25,13);printf("Data Admissão : %s", ptr->data_admissao);
        ptr = ptr->prox;
        gotoxy(25,14);system("pause");
    }
        printf("\n\n");
}

void libera_funcionario(funcionarios *func){
    if(!vazia_funcionario(func)){
        funcionarios *proxfuncionarios,
        *atual;
        atual = func->prox;
        while(atual != NULL){
            proxfuncionarios = atual->prox;
            free(atual);
            atual = proxfuncionarios;
        }
    }
}

locacoes *aloca_locacao(){
    locacoes *novo=(locacoes *) malloc(sizeof(locacoes));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
        printf("Digite o Codigo do locero: "); 
        //scanf("%d", &novo->cod_loc); 
        fflush(stdin);
        
        printf("Digite o nome do locero:");
        //fgets(novo->nome_locero, 80, stdin);
        fflush(stdin);
        return novo;
    }
}

void insereInicio_locacao(locacoes *loc){
    locacoes *novo=aloca_locacao(); 
    locacoes *oldHead = loc->prox;
    loc->prox = novo;
    novo->prox = oldHead;
    tam_loc++;
}

void exibe_locacao(locacoes *loc){
    system("cls");
    if(vazia_locacao(loc)){
        printf("loc vazia!\n\n");
        return;
    }
    locacoes *ptr;
    ptr = loc->prox;
    while( ptr != NULL){
        //printf("Codigo [%d]\n", ptr->cod_locme);
        //printf("Nome:%s\n", ptr->nome_locme);
        ptr = ptr->prox;
    }
        printf("\n\n");
}

void libera_locacao(locacoes *loc){
    if(!vazia_locacao(loc)){
        locacoes *proxlocacoes,
        *atual;
        atual = loc->prox;
        while(atual != NULL){
            proxlocacoes = atual->prox;
            free(atual);
            atual = proxlocacoes;
        }
    }
}

void insere_locacao(locacoes *loc){
    int pos,
    count;
    printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam_loc);
    scanf("%d", &pos);
     
    if(pos>0 && pos <= tam_loc){
        if(pos==1)
            insereInicio_locacao(loc);
        else{
            locacoes *atual = loc->prox,
            *anterior=loc; 
            locacoes *novo=aloca_locacao();
            for(count=1 ; count < pos ; count++){
                anterior=atual;
                atual=atual->prox;
            }
            anterior->prox=novo;
            novo->prox = atual;
            tam_loc++;
        }  
     }
    else
        printf("Elemento invalido\n\n");  
}

int opcao(generos *gen, filmes *fil, clientes *clin, funcionarios *func, locacoes *loc){
    generos *tmp;
    filmes *ptr;
   	system("cls");
   	int posicao = 6, tecla;	
	inicio:
		do{
			system("cls");
			gotoxy(24,22);printf("------------------------------ CONTROLES --------------------------------");
			gotoxy(23,23);printf("| Use as setas para cima e para baixo do teclado para navegar no menu     |");
			gotoxy(23,24);printf("| Aperte ENTER para selecionar a opção desejada                           |");
				for(int i=24;i<97;i++){
					gotoxy(i,25);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			gotoxy(24,5);printf("---------------------------- MENU---------------------------");
			gotoxy(23,6);printf("|                     Cadastro Gênero                        |");
			gotoxy(23,7);printf("|                     Cadastro Filme                         |");
			gotoxy(23,8);printf("|                     Cadastro Cliente                       |");
			gotoxy(23,9);printf("|                     Cadastro Funcionário                   |");
			gotoxy(23,10);printf("|                     Cadastro Locação                       |");
			gotoxy(23,11);printf("|                     Fazer Devolução                        |");
			gotoxy(23,12);printf("|                     Excluir Gênero                         |");
			gotoxy(23,13);printf("|                     Excluir Filme                          |");
			gotoxy(23,14);printf("|                     Excluir Cliente                        |");
			gotoxy(23,15);printf("|                     Excluir Funcionário                    |");
			gotoxy(23,16);printf("|                     Excluir Locação                        |");
			gotoxy(23,17);printf("|                     Listar locação data especifica         |");
			gotoxy(23,18);printf("|                     Listar filmes em atraso                |");
			gotoxy(23,19);printf("|                     Listar devolução                       |");
				for(int i=24;i<84;i++){
					gotoxy(i,20);printf("-"); //For para o prenchimento da parte inferior do menu
				}
			gotoxy(24,posicao);printf("%c%c",62,62);gotoxy(82,posicao);printf("%c%c",60,60);  //setinhas de seleção
			tecla=getch();
				if(tecla == ABAIXO){
					posicao=posicao+1;
					if(posicao==19){
						posicao=6;
					}
				}
				if (tecla == ACIMA){
					posicao=posicao-1;
					if(posicao==5){
						posicao=19;
					}
				}
		}while(tecla!= ENTER);
			switch (posicao){
				case 6:
					system("cls");
	 				insereInicio(gen);
        			exibe(gen);
        			goto inicio;
				break;
				
				case 7:
					insereInicio_filme(fil, gen);
        			exibe_filme(fil);
        			goto inicio;
				break;
				
				case 8:
					insereInicio_cliente(clin);
        			exibe_cliente(clin);
        			goto inicio;
				break;
				
				case 9:
					insereInicio_funcionario(func);
					exibe_funcionario(func);
					goto inicio;
				break;
				
				case 10:
					
					goto inicio;
				break;
				
				case 11:
					
					goto inicio;
				break;	
				
				case 12:
					
					goto inicio;
				break;	
				
				case 13:
					
					goto inicio;
				break;	
				
				case 14:
					
					goto inicio;
				break;
					
				case 15:
					
					goto inicio;
				break;
					
			}	
	return posicao;
} 

int main(){
	system("Color 1A");
	setlocale(LC_ALL,"");
    generos *gen = (generos *) malloc(sizeof(generos));
    filmes *fil = (filmes *) malloc(sizeof(filmes));
    clientes *clin = (clientes *) malloc(sizeof(clientes));
    funcionarios *func = (funcionarios *) malloc(sizeof(funcionarios));
    locacoes *loc = (locacoes *) malloc(sizeof(locacoes));
    
	if(!gen && !fil && !clin && !func && !loc){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
        inicia(gen);
        inicia_filme(fil);
        inicia_cliente(clin);
        inicia_funcionario(func);
        inicia_locacao(loc);
 		opcao(gen, fil, clin, func, loc);
    
        free(gen);
        free(fil);
        free(clin);
        free(func);
        free(loc);
        return 0;
    }
}
