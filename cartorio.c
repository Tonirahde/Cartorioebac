#include <stdio.h> //biblioteca de comunicacao de usuario
#include <stdlib.h>  //biblioteca de alocacao de espaco em memoria 
#include <locale.h> // biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings


int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{	
	//Inicio criacao de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criacam de variaveis
	
	printf("Digite o seu CPF "); // Coletando irnformacao do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE*file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e atualiza
	fprintf(file,","); // acrescenta uma virgula a string
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu sobrenome ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);	
	
	printf("Digite o cargo a ser cadastrado ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo nao localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa sao as informacoes do usuario ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
		
	if (file == NULL)
	{
		printf("O usuario nao foi encontrado no sistema\n");
		system("pause");
			
	}
	

}
	
	int main()
{
		
	int laco=1;
	int opcao=0; //Definindo as variaveis
	
	for(laco=1;laco=1;)	
	{
		
		system("cls"); // Responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem 
	
	
		printf("### Cartorio da EBAC ###\n\n");	//Inicio do menu	
				
		printf("Escolha a opçao desejada do menu: \n\n");
		printf("\t1 - Registar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair do sistema \n");
		printf(" Opcao :"); // Fim do menu
	
		scanf("%d", &opcao); //Armazenando a opcao do usuario
	
		system("cls");
		
		
		switch(opcao) //inicio da selecao do menu
		{
			case 1:	
				registro(); //chama as funcoes
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar nosso sistema!");
				return 0;
			break;
			
			default:
			printf("Essa opcao nao esta disponivel\n\n");
			system("pause");
			break;
		}	//fim da selecao
	
					
	
			printf("Esse softare foi feito por Antonio Rahde\n"); // Assinaturo do lindo programador hehe
	}
}
