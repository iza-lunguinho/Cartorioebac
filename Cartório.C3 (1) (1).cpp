#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respos�vel por cuidar das string

int registro() //fun��o repons�vel pot cadstrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando infoma��o do usu�rio
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file, cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen (arquivo, "a"); // "a" de atualiza��o
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo [200];
	
	printf("digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{   
	printf ("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as infoma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	
	
	char cpf[40];
	
	printf("Digite o CPF o ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
	
	

}

int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opc�o:"); //fim do menu
	
        scanf("%d" , &opcao); //armazenando a esolha do usu�rio 
    
        system("cls"); //responsavel por limpar a tela
    
	    
        switch(opcao)  //inicio da sele��o do menu
        {
        	case 1:
        	registro(); //chama de fun��o
			break;
			
			case 2:
		    consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistemaa\n");
			return 0;
			break; 
			
			
			default:
			printf("Essa op��o n�o esta disponivel!\n");	
			system("pause");
			break;	
			
	
			
		}

    } 
       
	
}
