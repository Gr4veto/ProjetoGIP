/*
Matéria: ALGORITMOS E LOGICA DE PROGRAMACAO - T01
Prof: MARCIONILO JOSE DA SILVA

Aluno: 
WESLEY COSTA DA SILVA   - Matrícula: 20210064582

Unidade III - Projeto: Controle de acesso
Linguagem C

___________!ATENÇÃO!______________

No menu principal, escolha a opção
"informações do sistema", para ver
informações sobre o funcionamento
do condomínio e sobre a finalidade
do programa. 
__________________________________
*/

/*

ANOTAÇÕES SOBRE O ANDAMENTO:

- Até agora o menu principal funciona;
- Menu CADASTRAR funcionando perfeitamente;
- Menu EXIBIR DOCUMENTO funcionado perfeitamente;
- Menu BUSCAR funcionando perfeitamente;
- Menu excluir cadastro ok.

*/

#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

//Marcadores de funções:
void menu();
void cadastrar();//função para verificar qual apartamento será cadastrado
void cadastrar_1(); //pergunta se deseja voltar ou sair
void alterar();//para auxiliar na exclusão
void eliminar(int y, int z); //para exclusão
void buscar();//pergunta qual dado será pesquisado
void buscar_1(); //analisa o dado
void sair();//finaliza o código
void pular_linha();
int buscar_str(char str[]);//comparador de strings, para auxiliar nas buscas
void abrir_arq();//para facilitar a abertura do arquivo durante o código
void user(int y, int z);//Cadastra os usuários nos apartamentos
void ler_doc(); //Mostra todos os apartamentos do 101 ao 502 e os dados cadastrados, caso não haja cadastro mostra "*"
void info();//informações sobre o programa e logística do condominio

//Estruturas:

struct chaves{
	char controle[100], tag[100];
	// acesso: Livre/limitado	
};
struct cadastro{
	// status: Proprietário, inquilino ou diarista
	char status[20], nome[50], email[50], acesso[9]; 
	//int controle, tag; 
	struct chaves key;
};

struct apto{
	int num; //numero do apto(01 ou 02)
	struct cadastro pessoa[4];// 4 moradores
};

typedef struct apto apto;
apto ap[10];

//variáveis globais:

int x = 0, p = 0, g = 1, h = 100; //x será usado como aux para os menus, p, g e h serão utilizados como aux para preencher o número dos aptos
FILE *f, *ler;
char v, trav[2], virg[2]; //v é uma variável auxiliar para guardar caracteres, trav e virg são constantes de virgula e travessão 

//Função principal:
int main(void){
setlocale(LC_ALL, "Portuguese");
	
//preenchendo os números dos apartamentos
//(101, 102,201,202,...,502):
for(p = 0; p <= 10; p++){
	
    ap[p].num = 0;//ex: 100+1 = 101
  
}

for(p = 0; p <= 10; p++ && g++){
	
    ap[p].num = h+g;//ex: 100+1 = 101
    //printf("%d\n", ap[p].num);
	if(g == 2){//verifica se g atingiu 2(numero de ap por andar)
		g = 0;//zera g, mas sera somado 1 no inicio do laço
		h = h+100;//sobe um andar
	}
}

//tela de inicialização:		
	printf("\t|GIP SOFT|\n");//nome do soft
	printf("---------------------------\n\tBem vindo\t\n\t   ao\t\nGraveto Imperial Park Soft\n---------------------------\n\n"); //Boas vindas
	system("pause"); //Aguardar interação do usuário
	
while(1){//loop infinito para não acabar o programa enquanto não for solicitado pelo usuário

		
	menu();//abrir menu principal
	fclose(f);
}
	
}


//Função para o menu principal
void menu(){
	char c;
	abrir_arq();	
	system("cls");//Sempre que essa função aparecer, estará limpando a tela
	int n = 9;//variável para decisão
	
	printf(":::::: MENU PRINCIPAL ::::::\n\n");
	printf("1. Cadastrar\n2. Remover cadastros\n3. Buscar\n4. Exibir documento\n5. Informações do sistema\n\n0. Sair\n\n");
	printf("Digite: ");
	scanf("%d", &n);
	
	switch (n){//condicional para escolher os menus do soft
		case 1:
			cadastrar();
			break;
		case 3:
			buscar();
			break;
		case 2:
			alterar();
			break;
		case 4:
			ler_doc();
			fclose(f);
			break;
		case 5:
			info();
			break;
		case 0:
			system("cls");
			printf("\t|GIP SOFT|\n");
			printf("----------------------------\n   Obrigado e até logo :)\n----------------------------\n\n");
			system("pause");
			system("cls");
			exit(1);
		default:
		system("cls");
		printf("!!! Comando inválido !!!\nEntre com alguma das opções :)\n\n");
		system("pause");
	}
		
}

//Função para realizar cadastro de usuário
void cadastrar(){
	system("cls");
	int n = 9, apt = 0, j = 0, tam = 0, tam2 =0, cont = 0;
	char c, ifen = '-', virgula = ',';//utilizados para testes
//	rewind(f);//ir ao início do arquivo
	
	printf(":::::: CADASTRAR ::::::\n");
	printf("Digite o ap(ex: 101) ou escolha:\n1. Voltar\n0. Sair\n\nDigite: ");
	scanf("%d", &apt);
	fflush(stdin);

		switch (apt){//verificar qual apto foi selecionado
			case 101:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				//user(0,0);
				
		fscanf(f,"%c",&v);//posiciona o ponteiro
		//fscanf(f,"%c",&v);
	
	//printf("%cg", v);
	
	//verifica se há morador no APTO
		if(v != '-'){
			if(v == '\n'){ //verificação de controle para o programador, não interfere no programa
				system("pause");
			}
			//Solicita os dados ao usuário:
		
			fflush(stdin);
			printf("\nCadastro - Morador 0%d\n", j+1);
			printf("Status: ");
			gets(ap[0].pessoa[0].status);
			fflush(stdin);
			printf("Nome..: ");
			gets(ap[0].pessoa[0].nome);
			fflush(stdin);
			printf("Email.: ");
			gets(ap[0].pessoa[0].email);
			fflush(stdin);
			printf("Acesso: ");
			gets(ap[0].pessoa[0].acesso);
			fflush(stdin);
			printf("-----------------------\n");
			
			//aqui vamos atribuir como endereço das chaves:
			//controle: status+nome
			//tag: nome+status
			strcat(strcpy(ap[0].pessoa[0].key.controle, ap[0].pessoa[0].status), ap[0].pessoa[0].nome);
			strcat(strcpy(ap[0].pessoa[0].key.tag, ap[0].pessoa[0].nome), ap[0].pessoa[0].status);
			tam++;
			
			fclose(f);//fecha arquivo em modo leitura
			abrir_arq();//abre arquivo em modo gravação	
				
			//gravando dados no arquivo
				
					fprintf(f,"- ");
		
				fprintf(f,"%s", ap[0].pessoa[0].status);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].nome);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].email);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].acesso);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].key.controle);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].key.tag);
				fprintf(f," ");
				fputc(',', f);
				fprintf(f," ");
				
			fprintf(f,"+");
			printf("Cadastro: Check :)\n\n");
			printf("Ocupação: %d/4\n\n", j+1);
			system("pause");
			fclose(f);	
		//else do if '-'	
		}else{
			
			printf("Apto ocupado! \n1. Cadastrar novo morador\n2. Voltar\nDigite: ");
		scanf("%d", &n);
		
		switch(n){// verificação
			case 1:
				j = 1;// 1º vaga a ser ocupada
			while(j < 4){//verificando se há vaga
			fscanf(f,"%c",&c);
		    cont++;
			if(c == '-'){//cada '-' significa uma vaga ocupada
			j++;
			}
			if(c == '+'){
				break;
			}	
			}
			
		
		if(j < 4){//se houver vaga
		tam = j;
		tam2 = j;
		
		//leva o ponteiro até o local de gravação
	
				fclose(f);
				abrir_arq();
				fseek(f, cont*sizeof(char), SEEK_SET);
				/*if(j>=2){
					fseek(f, (cont-18)*sizeof(char), SEEK_SET);
				}*/
				
				
			//solicita dados ao usuário				
			fflush(stdin);
			printf("\nCadastro - Morador 0%d\n", j+1);
			printf("Status: ");
			gets(ap[0].pessoa[0].status);
			fflush(stdin);
			printf("Nome..: ");
			gets(ap[0].pessoa[0].nome);
			fflush(stdin);
			printf("Email.: ");
			gets(ap[0].pessoa[0].email);
			fflush(stdin);
			printf("Acesso: ");
			gets(ap[0].pessoa[0].acesso);
			fflush(stdin);
			printf("-----------------------\n");
			
			//aqui vamos atribuir como endereço das chaves:
			//controle: status+nome
			//tag: nome+status
			strcat(strcpy(ap[0].pessoa[0].key.controle, ap[0].pessoa[0].status), ap[0].pessoa[0].nome);
			strcat(strcpy(ap[0].pessoa[0].key.tag, ap[0].pessoa[0].nome), ap[0].pessoa[0].status);
			tam++;
			
			//gravando dados no arquivo
				
				fprintf(f,"- ");
				fprintf(f,"%s", ap[0].pessoa[0].status);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].nome);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].email);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].acesso);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].key.controle);
				fprintf(f," ");
				fprintf(f,"%s", ap[0].pessoa[0].key.tag);
				fprintf(f," ");
				fputc(',', f);
				fprintf(f," ");
				
			
			fprintf(f,"+");
		//	fprintf(f,"\n");
			printf("Cadastro: Check :)\n\n");
			printf("Ocupação: %d/4\n\n", j+1);
			fclose(f);
			system("pause");
	
	//esse é o caso onde o apto está totalmente ocupado		
		}else{
					
			printf("\nEsse apartamento encontra-se totalmente ocupado!\nElimine-o antes de escrever ou escolha outro APTO livre :)\n\n");
			system("pause");
			cadastrar_1();
			cadastrar();
		}
		break;
		
		case 2:
		system("cls");	
		break;		
		}		
			
		}//fim do else '-'
		fclose(f);
				break; //fim do case 101
				/*agora começa a analise dos demais aptos, o cadastro segue da mesma maneira na função "user",
				essa analise é feita para pular as linhas e posicionar o ponteiro nos locais adequados
				tendo em vista que cada linha é um apto*/
			case 102:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(0,1);
				break;
			case 201:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(1,2);
				break;
			case 202:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(2,3);
				break;
			case 301:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(3,4);
				break;
			case 302:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(4,5);
				break;
			case 401:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(5,6);
				break;
			case 402:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(6,7);
				break;
			case 501:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(7,8);
				break;
			case 502:
				system("cls");
				printf(":::::: CADASTRAR ::::::\n");
				user(8,9);
				break;
			case 1:
				fclose(f);
				menu();
				break;
			case 0:
				system("cls");
				printf("\t|GIP SOFT|\n");
				printf("----------------------------\n   Obrigado e até logo :)\n----------------------------\n\n");
				exit(1);
		}
	//fim do else apt 101
fclose(f); // ao fim do cadastro, fecha o arquivo para guardar dados
}


//função de verificação durante o cadastramento, quando o apto está cheio
void cadastrar_1(){
	int n = 9;
	printf("\n1. Menu; 0. Sair: ");
		fflush(stdin);
    	scanf("%d", &n);
	switch (n){
		case 1:
			fclose(f);
			menu();
			break;
		case 0:
			system("cls");
			printf("\t|GIP SOFT|\n");
			printf("----------------------------\n   Obrigado e até logo :)\n----------------------------\n\n");
			exit(1);
		}
}


//função para alterar cadastros:
void alterar(){
	system("cls");
	int n = 9;
	char i[50];
	printf(":::::: REMOVER CADASTRO ::::::\n");
	printf("Digite o numero do APTO que deseja limpar ou escolha:\n3. voltar\n0. Sair\n\n");
	printf("Digite: ");
	scanf("%d", &n);
	
	switch (n){ //Essa condicional define qual linha será resetada, tendo em vista que cada linha é uma APTO
		case 101:
			eliminar(0,0);
			break;
		case 102:
			eliminar(0,1);
			break;
		case 201:
			eliminar(1,2);
			break;
		case 202:
			eliminar(2,3);
			break;
		case 301:
			eliminar(3,4);
			break;
		case 302:
			eliminar(4,5);
			break;
		case 401:
			eliminar(5,6);
			break;
		case 402:
			eliminar(6,7);
			break;
		case 501:
			eliminar(7,8);
			break;
		case 502:
			eliminar(8,9);
			break;
		case 3:
			fclose(f);
			menu();
			break;
		case 0:
			system("cls");
			printf("\t|GIP SOFT|\n");
			printf("----------------------------\n   Obrigado e até logo :)\n----------------------------\n\n");
			exit(1);
		default:
		system("cls");
		printf("!!! Comando inválido !!!\nEntre com alguma das opções :)\n\n");
		system("pause");
		alterar();
	}
	
	system("pause");
}

//função para buscar cadastros:
void buscar(){
	system("cls");
	int n = 9;
	printf(":::::: BUSCA POR ::::::\n\n");
	printf("1. Email\n2. Tag\n3. Controle\n\n4. voltar\n0. Sair\n\n");
	printf("Digite: ");
	scanf("%d", &n);
	
		switch (n){ //verifica qual tipo de busca é desejada
			case 1:
				x = 0;
				buscar_1();
				break;
			case 2:
				x = 1;
				buscar_1();
				break;
			case 3:
				x = 1;
				buscar_1();
				break;
			case 4:
				fclose(f);
				menu();
				break;
			case 0:
				system("cls");
				printf("----------------------------\n   Obrigado e até logo :)\n----------------------------\n\n");
				exit(1);
			default:
				system("cls");
				printf("\t|GIP SOFT|\n");
				printf("!!! Comando inválido !!!\nEntre com alguma das opções :)\n\n");
				system("pause");
				buscar();
	}
}

//função complemento da função buscar:
void buscar_1(){
	system("cls");
	char i[50], j; //onde será guardada a chave
	char n[2][15] = {"de email", "da chave"};
	printf(":::::: BUSCAR ::::::\n\n");
	printf("Digite o endereço %s ou pressione:\n1. Voltar\n0. Sair.\n\n", n[x]);
	fflush(stdin);//limpar buffer do teclado
	printf("Digite: ");
	gets(i);
	j = i[0];//salvando o primeiro caractere da string para verificar se o usuário solicitou troca de menu
	
	
	
	if(i[1] == '\0'){ //if para evitar conflito caso o email ou endereço comece com '1' ou '0'
	
		switch (j){//switch para interagir entre os menus
			case '1':
				buscar();
				break;
			case '0':
				system("cls");
				printf("----------------------------\n   Obrigado e até logo :)\n----------------------------\n\n");
				exit(1);
			default:
				system("cls");
				printf("\t|GIP SOFT|\n");
				printf("!!! Comando inválido !!!\nEntre com alguma das opções :)\n\n");
				system("pause");
				buscar_1();
	}
}
buscar_str(i); // verifica a informação e devolve os dados do usuário ou indica que os dados indicados não contém no arquivo
}

//abrir arquivo
void abrir_arq(){ 
	f = fopen("GIP.txt","r+");
	ler = fopen("GIP.txt","r");//teste de leitura
	if(f == NULL){ //verificando se o arquivo foi aberto com sucesso
 			printf("\nNão encontramos o banco de dados!\nCriando novo arquivo...\n\n");
 			system("pause");
 			system("cls");
 			f = fopen("GIP.txt","w+");
 			ler = fopen("GIP.txt","r");//testando leitura
 			//separando os aptos, são 10 apto e separando também as strings para serem lidas caso os apto esteja vazio
 			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
 			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
			fclose(f); //guardando
			f = fopen("GIP.txt","r+"); //reabrindo arquivo
			system("cls"); //INSTRUÇÕES para preencher o cadastro
			printf("::::INSTRUÇÕES DE PRIMEIRO USO::::\n\nExemplo para como preencher a ficha \nde cadastro:\n\nStatus..: Proprietario/Inquilino/Diarista\nNome....: Primeiro_nome(sem espaços)\nEmail...: email_do_morador\nAcesso..: Livre/Limitado\n\n");
			printf("As chaves são cadastradas automaticamete e \ntem como padrão o seguinte formato:\n\nControle: StatusPrimeiro_nome\nTAG.....: Primeiro_nomeStatus\n\n");
			system("pause");
			system("cls"); 		
					 }
}

//função para pular linha, auxiliando na leitura do arquivo
void pular_linha(){
	//pular linha com o FSCANF: avançando caractere a caractere até encontrar o fim da linha
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
}

//função para buscar string comparando uma a uma
int buscar_str(char str[]){
	abrir_arq();
	int ret = 0, cont =0;
	char str1[50], c;
	
		fscanf(f,"%s",str1);
		while(1){
			ret = strcmp(str,str1);
		//	printf("%s\n", str);
		//	printf("%s\n\n", str1);
			cont++;
			if(ret == 0 || feof(f)){
				break;
			}
			fscanf(f,"%s",str1);		
		}
		
	//	printf("%s\n", str);
	//	printf("%s\n", str1);
	//	printf("%d\n", ret);
	//	printf("%d\n", cont);
	//	system("pause");
	
	int q = -2; //valor para negativar o numero de bytes do 'char' e voltar no arquivo com a função fseek
	if(ret == 0){
		while(c != '-'){//procurar o inicio dos dados do usuário
		fseek(f, -2, SEEK_CUR);//volta até o inicio dos dados do user que é indicado pelo ifen
		fscanf(f,"%c",&c);
	//	printf("%c", c);
		}
		
	//	system("pause");
		printf("______________________________");//exibe as informações do usuário
		printf("\nDados do morador:\n\n");
		fscanf(f," %s %s %s %s %s %s", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag );
		printf("Status..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag );
		system("pause");
		
	}
		else{
			printf("______________________________\n");
			printf("\nEssa informação não se encontra no banco de dados!\nTente novamente :)\n\n");
			system("pause");
		}
		rewind(f);//retorna o ponteiro ao inicio do arquivo
		fclose(f);
		return cont;
}	

//função para cadastro dos usuários nos apto(102,201,202,...,501,502):
void user(int y, int z){
	int b = 0, ponteiro = 0, cont;
	int n = 9, apt = 0, j = 0, tam = 0, tam2 =0, a = 0;
	char c, ifen = '-', virgula = ',';
	
	//leva o ponteiro até o apto desejado:
	while(b < z){//se z for maior que b, significa que não se trata do apto 101, devemos nos locomover até o apto solicitado
		while(c != '\n'){
			fscanf(f,"%c",&c);
			ponteiro++;
		}
		fscanf(f,"%c",&c);
		ponteiro++;
		b++;	
	}
	
	//Alinhando o ponteiro no fim da linha:
		switch (y){
			case 0:
				break;	
			case 1:
				ponteiro++;	
				break;
			case 2:
				ponteiro++;
				ponteiro++;
				break;
			case 3:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 4:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 5:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 6:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 7:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 8:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
		}
/*	ponteiro++;	
	ponteiro++;
	ponteiro++;
	ponteiro++;
	ponteiro++;*/
	
	//printf("%cg", c); //printf para teste
	
	//verifica se há morador no APTO
		if(c != '-'){
			if(c == '\n'){//verificando se o ponteiro n caiu em uma quebra de linha
				system("pause");
			}
			//Solicita os dados ao usuário:
		
			fflush(stdin);
			printf("\nCadastro - Morador 0%d\n", j+1);
			printf("Status: ");
			gets(ap[y].pessoa[j].status);
			fflush(stdin);
			printf("Nome..: ");
			gets(ap[y].pessoa[j].nome);
			fflush(stdin);
			printf("Email.: ");
			gets(ap[y].pessoa[j].email);
			fflush(stdin);
			printf("Acesso: ");
			gets(ap[y].pessoa[j].acesso);
			fflush(stdin);
			printf("-----------------------\n");
			
			//aqui vamos atribuir como endereço das chaves:
			//controle: status+nome
			//tag: nome+status
			strcat(strcpy(ap[y].pessoa[0].key.controle, ap[y].pessoa[0].status), ap[y].pessoa[0].nome);
			strcat(strcpy(ap[y].pessoa[0].key.tag, ap[y].pessoa[0].nome), ap[y].pessoa[0].status);
			tam++;
			
			fclose(f);
			abrir_arq();
			fseek(f, ponteiro*sizeof(char), SEEK_SET);//função para mover ponterio caractere a caractere
				
		
				fprintf(f,"- ");
				fprintf(f,"%s", ap[y].pessoa[j].status);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[0].nome);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[0].email);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[0].acesso);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[0].key.controle);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[0].key.tag);
				fprintf(f," ");
				fputc(',', f);
				fprintf(f," ");
				
			fprintf(f,"+");
			printf("Cadastro: Check :)\n\n");
			printf("Ocupação: %d/4\n\n", j+1);
			system("pause");
			fclose(f);	
		//else do if '-'	
		}else{
			
			printf("Apto ocupado! \n1. Cadastrar novo morador\n2. Voltar\nDigite: ");
		scanf("%d", &n);
		
		switch(n){// verificação
			case 1:
				j = 1;// 1º vaga a ser ocupada
			while(j < 4){//verificando se há vaga
			fscanf(f,"%c",&c);
		    cont++;
		    ponteiro++;
			if(c == '-'){//cada '-' significa uma vaga ocupada
			j++;
			}
			if(c == '+'){
				break;
			}	
			}
			ponteiro++;
			ponteiro++;
			ponteiro++;
		
		if(j < 4){//se houver vaga
		tam = j;
		tam2 = j;
		
		//leva o ponteiro até o local de gravação
				fclose(f);
				abrir_arq();
				fseek(f, (ponteiro-4)*sizeof(char), SEEK_SET);			
		
			fflush(stdin);
			printf("\nCadastro - Morador 0%d\n", j+1);
			printf("Status: ");
			gets(ap[y].pessoa[j].status);
			fflush(stdin);
			printf("Nome..: ");
			gets(ap[y].pessoa[j].nome);
			fflush(stdin);
			printf("Email.: ");
			gets(ap[y].pessoa[j].email);
			fflush(stdin);
			printf("Acesso: ");
			gets(ap[y].pessoa[j].acesso);
			fflush(stdin);
			printf("-----------------------\n");
			
			//aqui vamos atribuir como endereço das chaves:
			//controle: status+nome
			//tag: nome+status
			strcat(strcpy(ap[y].pessoa[j].key.controle, ap[y].pessoa[j].status), ap[y].pessoa[j].nome);
			strcat(strcpy(ap[y].pessoa[j].key.tag, ap[y].pessoa[j].nome), ap[y].pessoa[j].status);
			tam++;
				
			//gravando dados no arquivo
				
				fprintf(f," - ");
				fprintf(f,"%s", ap[y].pessoa[j].status);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[j].nome);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[j].email);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[j].acesso);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[j].key.controle);
				fprintf(f," ");
				fprintf(f,"%s", ap[y].pessoa[j].key.tag);
				fprintf(f," ");
				fputc(',', f);
				fprintf(f," ");
				
			fprintf(f,"+");
		//	fprintf(f,"\n");
			printf("Cadastro: Check :)\n\n");
			printf("Ocupação: %d/4\n\n", j+1);
			system("pause");
			
		}else{
			
			printf("\nEsse apartamento encontra-se totalmente ocupado!\nElimine-o antes de escrever ou escolha outro APTO livre :)\n\n");
			system("pause");
			cadastrar_1();
			cadastrar();
		}
		break;
		
		case 2:
		system("cls");	
		break;		
		}		
			
		}//fim do else '-'
		fclose(f);
}

void ler_doc(){ //ler o doc por inteiro e mostrar os cadastros dos apto
	char c;
	int aux = -1;
	
	system("cls");
	printf("::::Dados cadastrados::::\n(Onde houver '*', significa vazio.)\n\n");
		
	printf("APTO 101\n");

		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", trav, ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);

	printf("APTO 102\n");
		while(v != '\n'){//para pular linha/mudar de apto
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);
	
		printf("APTO 201\n");
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
	
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);
		
		printf("APTO 202\n");
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		
	
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);
		
		printf("APTO 301\n");
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		
	
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);

		printf("APTO 302\n");
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		
	
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);

		printf("APTO 401\n");
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		
	
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);

		printf("APTO 402\n");
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		
	
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);

	printf("APTO 501\n");
	while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		

		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);

		printf("APTO 502\n");
		while(v != '\n'){
			fscanf(f,"%c",&v);
		}
		fscanf(f,"%c",&v);
		
		fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",  ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, virg, trav, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, virg, trav, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, virg, trav, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag, virg);
		printf("Morador 01:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 02:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 03:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\nMorador 04:\nStatus..: %s\nNome....: %s\nEmail...: %s\nAcesso..: %s\nControle: %s\nTAG.....: %s\n\n", ap[0].pessoa[0].status, ap[0].pessoa[0].nome, ap[0].pessoa[0].email, ap[0].pessoa[0].acesso, ap[0].pessoa[0].key.controle, ap[0].pessoa[0].key.tag, ap[0].pessoa[1].status, ap[0].pessoa[1].nome, ap[0].pessoa[1].email, ap[0].pessoa[1].acesso, ap[0].pessoa[1].key.controle, ap[0].pessoa[1].key.tag, ap[0].pessoa[2].status, ap[0].pessoa[2].nome, ap[0].pessoa[2].email, ap[0].pessoa[2].acesso, ap[0].pessoa[2].key.controle, ap[0].pessoa[2].key.tag, ap[0].pessoa[3].status, ap[0].pessoa[3].nome, ap[0].pessoa[3].email, ap[0].pessoa[3].acesso, ap[0].pessoa[3].key.controle, ap[0].pessoa[3].key.tag);
		fclose(f);
	system("pause");
	system("cls");
}

//função para exibir informações do sistema:
void info(){
	system("cls");
	
	printf("Projeto: Controle de acesso\nCondomínio: Graveto Imperial Park I\n\n");
	
	printf("|DESCRIÇÃO DO Condomínio|\n\n");
	printf("APTOS(10):\n101-102-201-202-301-302-401-402-501-502;\nCada apartamento comporta até 4 pessoas;\n\n");
	
	printf("(1 de 4)\n");
	system("pause");
	system("cls");
	
	printf("|DESCRIÇÃO DO ACESSO|\n\n");
	printf("Existe um portão automotivo e uma eclusa\npedestres para acesso ao Condomínio.\n\n");
	printf("Chaves de acesso: Controle(automotivo) e TAG(pedestre).\n\n");
	printf("As chaves de acesso devem receber como endereço: \n- controle: status+nome\n- tag: nome+status\nPara que possa ser feito o controle de acesso.\n\n");
	
	printf("(2 de 4)\n");
	system("pause");
	system("cls");
	
	printf("|DESCRIÇÃO DO CADASTRO DE usuário|\n\n");
	printf("- Cada usuário terá direito a:  1 controle e 1 TAG;\n\n");
	
	printf("|FICHA DE CADASTRO|\n(4 usuários por apto)\n\n");
	printf("- Proprietário, inquilino ou diarista;\n- Nome e email;\n- Acesso: Livre/Limitado;\n- Chaves(controle e tag);\n\n");
	
	printf("(3 de 4)\n");
	system("pause");
	system("cls");
	
	printf("|PROGRAMA|\n\n");
	
	printf("Deve ser desenvolvido um programa que seja capaz de gravar e armazenar os\n");
	printf("dados dos cadastros dos usuários, vinculando a eles suas respectivas chaves,\n");
	printf("como também, o programa deve ser capaz de identificar o usuário pelos seguintes\n");
	printf("dados:\n\n- Email ou endereço da chave;\n\n");

	printf("O programa também deve ser capaz de criar e apagar cadastros.\n\n");
	
	printf("(4 de 4)\n");
	system("pause");
}

void eliminar(int y, int z){
	int b = 0, ponteiro = 0;
	char c;
	//leva o ponteiro até o apto desejado:
//leva o ponteiro até o apto desejado:
	while(b < z){//se z for maior que b, significa que não se trata do apto 101, devemos nos locomover até o apto solicitado
		while(c != '\n'){
			fscanf(f,"%c",&c);
			ponteiro++;
		}
		fscanf(f,"%c",&c);
		ponteiro++;
		b++;	
	}
	
	//Alinhando o ponteiro no fim da linha:
		switch (y){
			case 0:
				break;	
			case 1:
				ponteiro++;	
				break;
			case 2:
				ponteiro++;
				ponteiro++;
				break;
			case 3:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 4:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 5:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 6:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 7:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
			case 8:
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				ponteiro++;
				break;
		}
			
			if(z == 0){//se se tratar do apto101
			fclose(f);//fecha arquivo em modo leitura
			abrir_arq();//abre arquivo em modo gravação	
			}else{//se não, fecha e abre o arquivo e move o ponteiro até o local de gravação
				fclose(f);
				abrir_arq();
				fseek(f, ponteiro*sizeof(char), SEEK_SET);//função para mover ponterio caractere a caractere
			}
	//a linha abaixo é uma linha padrão, utilizada para resetar o apto escolhido		
	fputs("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n",f);
fclose(f);
printf("Cadastros do apto selecionado eliminados com sucesso!\n\n");	
	
}
