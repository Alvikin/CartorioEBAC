#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas "strings"

int registro(){  //Fun��o respons�vel pelo cadastro dos usu�rios no sistema
	
	//inicio da cria��o de vri�veis
	char arquivo[40]; 
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vri�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf);  
	
	strcpy(arquivo, cpf); // Esse comando copia os valores das strings "cpf" para "arquivo"
	
	FILE *file;  //criando o arquivo
	file = fopen(arquivo, "w");  //criando o arquivo (w de "write")
	fprintf(file, cpf); // pedimos para salvar o valor da variavel cpf dentro do arquivo
	fprintf(file, ", "); // colocando uma "," entre as informa��es digitadas pelo usuario
	fclose(file);  // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);	
	
	file = fopen(arquivo, "a"); // "a" � para atualizar um informa��o
	fprintf(file, nome);
	fprintf(file, ", ");
	fclose(file);
		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);		
		
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);	
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
			
	system("pause");
		
}

int consulta (){ //fun��o para a consulta de usu�rios no sistema
	
	setlocale(LC_ALL,"Portuguese"); //definindo linguagem
	
	//inicio da cria��o de vri�veis 
	char cpf[40];
	char conteudo[200];
	char *token;  //cria um ponteiro do tipo char com o nome de token
	//fim da cria��o de vri�veis
	
	printf("Digite o CPF a ser consultado: "); 
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // abre e l� o arquivo
	
	if(file == NULL) // Se o arquivo n�o tiver o valor do cpf dentro dele
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado !\n");
	}
	

	
	while(fgets(conteudo, 200, file) != NULL) //salva os carateres dentro da variavel "conteudo" enquanto n�o for NULL		
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		
		token = strtok(conteudo, ", "); //esse comando pula uma linha durante a impress�o da string
		printf("CPF: %s\n", token);		// 2 parametros: string a ser dividida e quando dividi-la						
		
		token = strtok(NULL, ", ");  //Primeiro parametro agora � NULL para evitar um "loop infinito"
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ", ");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ", ");
		printf("Cargo: %s\n", token);		
		
	}
	
	printf("\n");
	fclose(file);   // fecha arquivo
	system("pause");
	
}

int deletar(){ //fun��o para deletar usu�rios do sistema
	
	//inicio da cria��o de vari�veis
	char cpf[40];
	//fim da cria��o de vari�veis
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;   
	file = fopen(cpf, "r"); // abre e l� o arquivo
	fclose(file);   // fecha o arquivo
	
	if(file == NULL) //se o arquivo n�o estiver no sistema
	{	
		printf("\nO usu�rio n�o se encontra no sistema !\n");
		system("pause");
	}else
		{
		if(remove(cpf) == 0) //tenta deletar o arquivo cpf
			{
			printf("\nUsu�rio deletado com sucesso !\n"); //sucesso
			system("pause");
			}else
				{
					printf("\nErro ao deletar o usu�rio !\n"); //erro
					system("pause");
				}
				
		} 
}

int main (){ //fun��o "main"
	
	// inicio da cria��o de vari�veis
	int opcao = 0; 
	int laco = 1;
	// fim da cria��o de vari�veis
	
	for(laco = 1; laco = 1;){ //la�o do menu
		
		system("cls"); // Limpa a tela
			
		setlocale(LC_ALL,"Portuguese"); //definindo linguagem
	
		printf("### Cart�rio da EBAC ### \n\n");  //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");  // fim do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //coletando op��o desejada pelo usu�rio
	
		system("cls");
		
		switch(opcao){ // inicio da sele��o do menu
		
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema !\n");
			return 0;
			break;
			
			default: // essa � uma op��o que n�o satisfaz nenhum dos casos
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			
		} // fim da sele��o do menu
			
	}
	//printf("Esse software � de livre uso\n");
}
