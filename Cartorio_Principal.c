#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas "strings"

int registro(){  //Função responsável pelo cadastro dos usuários no sistema
	
	//inicio da criação de vriáveis
	char arquivo[40]; 
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de vriáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf);  
	
	strcpy(arquivo, cpf); // Esse comando copia os valores das strings "cpf" para "arquivo"
	
	FILE *file;  //criando o arquivo
	file = fopen(arquivo, "w");  //criando o arquivo (w de "write")
	fprintf(file, cpf); // pedimos para salvar o valor da variavel cpf dentro do arquivo
	fprintf(file, ", "); // colocando uma "," entre as informações digitadas pelo usuario
	fclose(file);  // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);	
	
	file = fopen(arquivo, "a"); // "a" é para atualizar um informação
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

int consulta (){ //função para a consulta de usuários no sistema
	
	setlocale(LC_ALL,"Portuguese"); //definindo linguagem
	
	//inicio da criação de vriáveis 
	char cpf[40];
	char conteudo[200];
	char *token;  //cria um ponteiro do tipo char com o nome de token
	//fim da criação de vriáveis
	
	printf("Digite o CPF a ser consultado: "); 
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // abre e lê o arquivo
	
	if(file == NULL) // Se o arquivo não tiver o valor do cpf dentro dele
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado !\n");
	}
	

	
	while(fgets(conteudo, 200, file) != NULL) //salva os carateres dentro da variavel "conteudo" enquanto não for NULL		
	{
		printf("\nEssas são as informações do usuário: \n");
		
		token = strtok(conteudo, ", "); //esse comando pula uma linha durante a impressão da string
		printf("CPF: %s\n", token);		// 2 parametros: string a ser dividida e quando dividi-la						
		
		token = strtok(NULL, ", ");  //Primeiro parametro agora é NULL para evitar um "loop infinito"
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

int deletar(){ //função para deletar usuários do sistema
	
	//inicio da criação de variáveis
	char cpf[40];
	//fim da criação de variáveis
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;   
	file = fopen(cpf, "r"); // abre e lê o arquivo
	fclose(file);   // fecha o arquivo
	
	if(file == NULL) //se o arquivo não estiver no sistema
	{	
		printf("\nO usuário não se encontra no sistema !\n");
		system("pause");
	}else
		{
		if(remove(cpf) == 0) //tenta deletar o arquivo cpf
			{
			printf("\nUsuário deletado com sucesso !\n"); //sucesso
			system("pause");
			}else
				{
					printf("\nErro ao deletar o usuário !\n"); //erro
					system("pause");
				}
				
		} 
}

int main (){ //função "main"
	
	// inicio da criação de variáveis
	int opcao = 0; 
	int laco = 1;
	// fim da criação de variáveis
	
	for(laco = 1; laco = 1;){ //laço do menu
		
		system("cls"); // Limpa a tela
			
		setlocale(LC_ALL,"Portuguese"); //definindo linguagem
	
		printf("### Cartório da EBAC ### \n\n");  //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");  // fim do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //coletando opção desejada pelo usuário
	
		system("cls");
		
		switch(opcao){ // inicio da seleção do menu
		
			case 1:
			registro(); // chamada de funções
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
			
			default: // essa é uma opção que não satisfaz nenhum dos casos
			printf("Essa opção não está disponível\n");
			system("pause");
			
		} // fim da seleção do menu
			
	}
	//printf("Esse software é de livre uso\n");
}
