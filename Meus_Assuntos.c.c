#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os us�arios no sistema
{
	//Inicio  da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do us�ario
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" siginifica escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o NOME que deseja cadastrar: "); //Coletando informa��es do us�ario
	scanf("%s",nome); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file,nome);
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o SOBRENOME que deseja cadastra: "); //Coletando informa��es do us�ario
	scanf("%s",sobrenome); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file,sobrenome);
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o CARGO que deseja cadastra: "); //Coletando informa��es do us�ario
	scanf("%s",cargo); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file,cargo);
	fclose(file); // fecha o arquivo
	
	system("pause"); //Pausa a tela
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF que deseja consultar: "); //Coletando informa��es do us�ario
    scanf("%s",cpf); //"%s" refere-se a string
    
    FILE *file;
    file = fopen(cpf, "r"); //"R" ler o arquivo
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, N�o localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do us�ario: ");
		printf("%s", conteudo);
		printf("\n\n"); // "\n" pula uma linha
	}
	
	system("pause"); //Pausa a tela
    
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do us�ario a ser deletado: ");
	scanf("%s",cpf); //"%s" refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"R" ler o arquivo
	
	if(file == NULL)
	{
		printf("Us�ario deletado ou fora de sistema!.\n");
		system("pause"); //Pausa a tela
	}
	
	
}


int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Respons�vel por limpar a tela
	
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cart�rio do Cliente ###\n\n"); //Inicio do menu
	   printf("Escolha uma das op��es do menu abaixo:\n\n");
	   printf("\t1 Registrar nomes\n"); // "\t" dar um espa�amento nas bordas
	   printf("\t2 Consultar nomes\n");
	   printf("\t3 Deletar nomes\n\n");
	   printf("\t4 Sair do sistema\n\n");
	   printf("Escolha a op��o desejada: "); //Fim do menu
	
	   scanf("%d", &opcao); //"%d" armazenando a escolha do usu�rio
	
	   system("cls"); //Respons�vel por limpar a tela
	   
	   
	   switch(opcao) //Inicio da sele��o
       {
           case 1:
           registro(); //Chamada de fun��es
		   break;
		   
		   case 2:
           consulta();
		   break;
		   
		   case 3:
		   deletar();
		   break;
		   
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
		   	
		   default:
		   printf("A��o indisponivel, tente novamente...\n");
		   system("pause"); //Pausa a tela
		   break; 
	   } //Fim da sele��o
    }
}
