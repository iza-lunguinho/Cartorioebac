#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocaçao de espaço em memória 
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca resposável por cuidar das string

int registro() //função reponsável pot cadstrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando infomação do usuário
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file, cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen (arquivo, "a"); // "a" de atualização
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
	printf ("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as infomações do usuário: ");
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
		printf("o usuário não se encontra no sistema!. \n");
		system("pause");
	}
	
	

}

int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n");
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opcão:"); //fim do menu
	
        scanf("%d" , &opcao); //armazenando a esolha do usuário 
    
        system("cls"); //responsavel por limpar a tela
    
	    
        switch(opcao)  //inicio da seleção do menu
        {
        	case 1:
        	registro(); //chama de função
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
			printf("Essa opção não esta disponivel!\n");	
			system("pause");
			break;	
			
	
			
		}

    } 
       
	
}
