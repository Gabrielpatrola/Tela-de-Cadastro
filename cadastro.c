/*************************************************************************
Nome da Disciplina: Estrutura de Dados
Nome Professor: Leonair Neves Sousa
Nome Aluno: Gabriel Augusto Queiroz de Almeida
Turma: VE1
RGA: 201611901002
Data Entrega:
*************************************************************************/

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
generos *aloca(){
    generos *novo=(generos *) malloc(sizeof(generos));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
        printf("Digite o Codigo do Genero: "); 
		scanf("%d", &novo->cod_gen); 
		fflush(stdin);
		
		printf("Digite o nome do genero:");
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
        printf("gen vazia!\n\n");
        return;
    }
    generos *tmp;
    tmp = gen->prox;
    while( tmp != NULL){
        printf("Codigo [%d]\n", tmp->cod_gen);
        printf("Nome:%s\n", tmp->nome_genero);
        tmp = tmp->prox;
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
filmes *aloca_filme(generos *gen){
	int aux;
	generos *tmp;
    filmes *novo=(filmes *) malloc(sizeof(filmes));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
    	if(vazia(gen) == 0){
    	printf("Digite o codigo do genero");
    	scanf("%d", &aux);
    	tmp = gen->prox;
    	while( tmp != NULL){
    		if (tmp->cod_gen == aux){
    			novo->cod_genero == aux;
    			printf("Digite o Codigo do filme: "); 
        		scanf("%d", &novo->cod_filme); 
        		fflush(stdin);
        
        		printf("Digite o nome do filme:");
        		fgets(novo->nome_filme, 80, stdin);
       			fflush(stdin);
        
				printf("Digite o ano do filme:");
       		 	fgets(novo->ano, 5, stdin);
        		fflush(stdin);
        
        		printf("Digite a classifiacação do filme:");
        		fgets(novo->classificacao, 50, stdin);
        		fflush(stdin);

				printf("Digite o valor do filme: "); 
        		scanf("%f", &novo->valor); 
        		fflush(stdin);
			}tmp = tmp->prox;
			else{
				printf("erro no codigo");
			}
		}
		printf("erro");
		system("pause");	
    }
        return novo;
    }
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
        printf("filme vazio!\n\n");
        return;
    }
    filmes *ptr;
    ptr = fil->prox;
    while( ptr != NULL){
        printf("\nCodigo do filme [%d]\n", ptr->cod_filme);
        printf("Nome do filme:%s", ptr->nome_filme);
        printf("Codigo do Genero:%s", ptr->cod_genero);
        printf("Ano: [%s]", ptr->ano);
        printf("\nClassificação: %s", ptr->classificacao);
        printf("Valor: %.5f", ptr->valor);
        ptr = ptr->prox;
    }
        printf("\n\n");
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

int menu(){
    int opt;
    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Zerar gen\n");
    printf("2. Exibir gen\n");
    printf("3. Adicionar generos no inicio\n");
    printf("4. Adicionar generos no final\n");
    printf("5. Escolher onde inserir\n");
    printf("6. Retirar do inicio\n");
    printf("7. Retirar do fim\n");
    printf("8. Escolher de onde tirar\n");
    printf("Opcao: "); scanf("%d", &opt);
     
    return opt;
}

void opcao(generos *gen, filmes *fil, clientes *clin, funcionarios *func, locacoes *loc, int op){
    generos *tmp;
    filmes *ptr;
    
    switch(op){
    case 0:
    	libera(gen);
    break;
       
    case 1:
        libera(gen);
        inicia(gen);
    break;
          
    case 2:
        exibe(gen);
    break;
          
    case 3:
        insereInicio(gen);
        exibe(gen);
    break;  
           
    case 4:
		insereInicio_filme(fil, gen);
        exibe_filme(fil);
    break;
           
    case 5:
        insere(gen);
    break;
          
    case 6:
        tmp= retiraInicio(gen);
        //printf("Retirado: %3d\n\n", tmp->cod_gen);
    break;
           
    case 7:

    break;
          
    case 8:
        tmp= retira(gen);
        printf("Retirado: %3d\n\n", tmp->cod_gen);
    break;
          
    default:
        printf("Comando invalido\n\n");
    }
}

int main(){
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
        int opt;
        do{
        	opt=menu();
            opcao(gen, fil, clin, func, loc,opt);
        }while(opt);
        free(gen);
        free(fil);
        return 0;
    }
}
