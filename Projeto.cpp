#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espaco em memoria 
#include <locale.h> //biblioteca de aloca�oes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings


int cadastrar() //Fun��o responsavel por cadastrar os usuario no sistema

{	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o cpf para cadastro: "); //coletando informa��o do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //criar arquivo
	file =fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo para variavel
	fclose(file); //fechar o arquivo
	
	file= fopen(arquivo, "a"); //fopen para abrir arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome para cadastrar:"); // digita��o do nome do usuario
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file); //fclose significa fechar arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: "); //digitar o sobrenome do usuario
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: "); //cargo do usuario
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausar a op��o na qual foi escolhida
	
}

int exibir() //op��o responsavel por exibir o usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para cunsulta: "); //consultar CPF do usuario
	scanf("%s",cpf);
	
	FILE *file; //"FILE" significa criar arquivo file
	file = fopen(cpf,"r");
	
	if(file == NULL) // NULL significa nulo, sem valor
	
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! .\n");
	
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int apagar() //responsavel por apagar usuario cadastrado no sistema
{
	char cpf[40];
	
	printf("Digite o CPF a se apagado"); //op��o de apagar CPF cadastrado
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema!. \n"); //op��o n�o encontrada ou ja apagada
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //responsavel por deletar
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Ebac Biblioteca de Login ###\n\n"); //Inicio de menu
		printf("Menu de Op��es:\n\n");
		printf("\t1 - Cadastrar Usuario\n");
		printf("\t2 - Exibir Usuarios\n");
		printf("\t3 - Apagar Usuario cadastrado\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("opcao: "); //Fim do menu
	
		scanf("%d", &opcao);
	
		system("cls"); //armagenando a esscolha do usuario
	
		switch(opcao) //inicio da sele��o do menu
		{	
			case 1:
			cadastrar(); //chamada da fun��o cadastrar
			break;
		
			case 2:
			exibir(); //chamada da fun��o exibir 
			break;
		
			case 3:
			apagar(); //chamada da fun��o apagar
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
			default:
			printf("Essa Op��o n�o esta disponivel no momento!\n");
			system("pause");
			break;
		} //fim da sele��o
	
	}
}
