#include <stdio.h> // Biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <Locale.h> // Biblioteca de alocaçoes de texto por regiao
#include <string.h> // Biblioteca das strings

int registro() // Função responsavel por cadastrar usuarios no sistema
{
	//Criação das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char resposta;
	
	do{
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuario
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
	
	printf("\n Cadastro Realizado com sucesso!\n\n");
	printf("Deseja cadastrar novamente? (S/N): ");
	scanf("%c",&resposta);
	}
	while (resposta == "s" || resposta =="S");
	
	
	return 0;
	system("pause");
	system("cls");
}



int consulta()		
{
		char resposta;
		do
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
	
	
	printf("Deseja Realizar outra consulta? (S/N): ");
	scanf("%c",&resposta);
		}
		while (resposta == "s" || resposta =="S");
	
		return 1;
		system("pause");
		system("cls");
		
}


	

	

int deletar() // Uma pequena alteração no codigo do professor que esta funcionando melhor, utilizei alguns tutoriais e a IA para chegar nele
{
	
	char resposta;
    char cpf[40];
    
	
		do
		{
	
	printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    // segundo a IA não é necessario o uso do FILE*file - fopen apos o arquivo ser deletado, esta sendo redundante

    if (remove(cpf) == 0) 
	{
        printf("Usuario deletado com sucesso!\n\n");
    }
	 else 
	{
        printf("Erro ao deletar o usuario.\n\n");
        return 1;
    }
	printf("Deseja deletar outro cadastro? (S/N): ");
	scanf("%c",&resposta);
		}
		while (resposta == "s" || resposta =="S");
	
		return 1;
		system("pause");
		system("cls");
    return 0;
}


int teste()
{
	printf("\n\nOpção Invalida\n\n");
	system("pause");
}


int main()
{
    setlocale(LC_ALL, "Portuguese"); // Colocando a regiao do idioma   
    int opcao=0; // Definindo as variaveis
	int laco=1;
	char senhadigitada[10] ="a";
	int comparacao;
	
	printf("### Cartorio Ebac ###\n\n");
	printf("login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{ 
		system("cls");
		for(laco=1;laco=1;) //
  		{
   
   		
   
   		printf("### Cartorio Ebac ###\n\n"); // inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes \n");
    	printf("\t2 - Consultar nomes \n");
    	printf("\t3 - Deletar nomes \n\n"); 
    	printf("\t4 - Sair do sistema\n\n");// fim do menu
   		printf("Digite aqui o numero correspondente:");
   
   scanf("%d", &opcao); // armazenando as escolhas do usuario
   
   system("cls"); // Realiza uma limpeza na tela
   
   switch(opcao)   	// Inicio de seleção do menu
  			{ 
		case 1:
		registro();
		printf("\n\nRegistrar nomes\n\n"); // chamada da funçao registro
		system("pause");
		break;
		
		case 2:
		consulta();
		printf("\n\n Consultar Nomes\n\n"); // chamada da funçao consulta
		system("pause");
		break;
		
		case 3:
		deletar();
		printf("\n\nDeletar Nomes\n\n"); // chamada da função deletar
		system("pause");
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		
		default:
		printf("\n\nOpçao invalida\n\n"); // Caso selecione uma opção invalida
 		system("pause");
			}
		}
	}
	
	else
	printf("senha incorreta");
	
}




  
