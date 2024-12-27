#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usúarios no sistema
{
	//Inicio  da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usúario
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" siginifica escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o NOME que deseja cadastrar: "); //Coletando informações do usúario
	scanf("%s",nome); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file,nome);
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o SOBRENOME que deseja cadastra: "); //Coletando informações do usúario
	scanf("%s",sobrenome); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file,sobrenome);
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o CARGO que deseja cadastra: "); //Coletando informações do usúario
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
    
    printf("Digite o CPF que deseja consultar: "); //Coletando informações do usúario
    scanf("%s",cpf); //"%s" refere-se a string
    
    FILE *file;
    file = fopen(cpf, "r"); //"R" ler o arquivo
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, Não localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usúario: ");
		printf("%s", conteudo);
		printf("\n\n"); // "\n" pula uma linha
	}
	
	system("pause"); //Pausa a tela
    
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usúario a ser deletado: ");
	scanf("%s",cpf); //"%s" refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"R" ler o arquivo
	
	if(file == NULL)
	{
		printf("Usúario deletado ou fora de sistema!.\n");
		system("pause"); //Pausa a tela
	}
	
	
}


int main()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Responsável por limpar a tela
	
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cartório do Cliente ###\n\n"); //Inicio do menu
	   printf("Escolha uma das opções do menu abaixo:\n\n");
	   printf("\t1 Registrar nomes\n"); // "\t" dar um espaçamento nas bordas
	   printf("\t2 Consultar nomes\n");
	   printf("\t3 Deletar nomes\n\n");
	   printf("\t4 Sair do sistema\n\n");
	   printf("Escolha a opção desejada: "); //Fim do menu
	
	   scanf("%d", &opcao); //"%d" armazenando a escolha do usuário
	
	   system("cls"); //Responsável por limpar a tela
	   
	   
	   switch(opcao) //Inicio da seleção
       {
           case 1:
           registro(); //Chamada de funções
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
		   printf("Ação indisponivel, tente novamente...\n");
		   system("pause"); //Pausa a tela
		   break; 
	   } //Fim da seleção
    }
}
