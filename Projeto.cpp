#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaco em memoria 
#include <locale.h> //biblioteca de alocaçoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings


int cadastrar() //Função responsavel por cadastrar os usuario no sistema

{	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o cpf para cadastro: "); //coletando informação do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //criar arquivo
	file =fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo para variavel
	fclose(file); //fechar o arquivo
	
	file= fopen(arquivo, "a"); //fopen para abrir arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome para cadastrar:"); // digitação do nome do usuario
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
	
	system("pause"); //pausar a opção na qual foi escolhida
	
}

int exibir() //opção responsavel por exibir o usuarios no sistema
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
		printf("Não foi possivel abrir o arquivo, não localizado! .\n");
	
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int apagar() //responsavel por apagar usuario cadastrado no sistema
{
	char cpf[40];
	
	printf("Digite o CPF a se apagado"); //opção de apagar CPF cadastrado
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema!. \n"); //opção não encontrada ou ja apagada
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
		printf("Menu de Opções:\n\n");
		printf("\t1 - Cadastrar Usuario\n");
		printf("\t2 - Exibir Usuarios\n");
		printf("\t3 - Apagar Usuario cadastrado\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("opcao: "); //Fim do menu
	
		scanf("%d", &opcao);
	
		system("cls"); //armagenando a esscolha do usuario
	
		switch(opcao) //inicio da seleção do menu
		{	
			case 1:
			cadastrar(); //chamada da função cadastrar
			break;
		
			case 2:
			exibir(); //chamada da função exibir 
			break;
		
			case 3:
			apagar(); //chamada da função apagar
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
			default:
			printf("Essa Opção não esta disponivel no momento!\n");
			system("pause");
			break;
		} //fim da seleção
	
	}
}
