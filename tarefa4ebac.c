#include <stdio.h> // Biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <Locale.h> // Biblioteca de aloca�oes de texto por regiao
#include <string.h> // Biblioteca das strings

int registro() // Fun��o responsavel por cadastrar usuarios no sistema
{
	//Cria��o das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usuario
	scanf("%s",cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // Responsavel por criar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf (file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("\n\nDigite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	
	
	printf("\n\nDigite o sobrenome a ser cadastrado: " );
	scanf("%s",sobrenome);	
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	printf("\n\nDigite o Cargo a ser cadastrado:" );
	scanf("%s",cargo);	
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	return 0;
	system("pause");
	
}


int consulta()
{
		
		
	setlocale(LC_ALL, "Portuguese"); // Colocando a regiao do idioma
	//inicio das variaveis
	char cpf[40];
	char conteudo[200];
	
	printf("\n\nDigite o CPF a ser Consultado: ");
	scanf ("%s",cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	
	printf("nao foi possivel realizar a consulta\n\n");	
	
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("Aqui esta o cadastro do usuario: \n\n");
	    printf("%s" , conteudo);
	    printf("\n\n ");
	}
	
	return 1;
	system("pause");
	fclose(file);
}

	

	

int deletar() // Uma pequena altera��o no codigo do professor que esta funcionando melhor, utilizei alguns tutoriais e a IA para chegar nele
{
    char cpf[40];
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    // segundo a IA n�o � necessario o uso do FILE*file - fopen apos o arquivo ser deletado, esta sendo redundante

    if (remove(cpf) == 0) 
	{
        printf("Usuario deletado com sucesso!\n\n");
    }
	 else 
	{
        printf("Erro ao deletar o usuario.\n\n");
        return 1;
    }

    return 0;
}


int teste()
{
	printf("\n\nOp��o Invalida\n\n");
	system("pause");
}


int main()
{
    int opcao=0; // Definindo as variaveis
   
	setlocale(LC_ALL, "Portuguese"); // Colocando a regiao do idioma
	int laco=1;
	for(laco=1;laco=1;) //
   {
   
   		system("cls"); // responsavel por limpar a tela
   
   		printf("### Cartorio Ebac ###\n\n"); // inicio do menu
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes \n");
    	printf("\t2 - Consultar nomes \n");
    	printf("\t3 - Deletar nomes \n\n"); // fim do menu
   		printf("Digite aqui o numero correspondente:");
   
   scanf("%d", &opcao); // armazenando as escolhas do usuario
   
   system("cls"); // Realiza uma limpeza na tela
   
   switch(opcao)   	// Inicio de sele��o do menu
  { 
		case 1:
		registro();
		printf("\n\nRegistrar nomes\n\n"); // chamada da fun�ao registro
		system("pause");
		break;
		
		case 2:
		consulta();
		printf("\n\n Consultar Nomes\n\n"); // chamada da fun�ao consulta
		system("pause");
		break;
		
		case 3:
		deletar();
		printf("\n\nDeletar Nomes\n\n"); // chamada da fun��o deletar
		system("pause");
		break;
		
		case 4:
		teste();
		break;
		
		
		default:
		printf("\n\nOp�ao invalida\n\n"); // Caso selecione uma op��o invalida
 		system("pause");
	}
	}
}
  




  
