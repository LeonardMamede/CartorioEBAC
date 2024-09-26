#include <stdio.h> //BIBLIOTECA DE COMINICAÇÃO COM O USUÁRIO
#include <stdlib.h>//BIBLIOTECA DE ALOCAÇÃO DE ESPAÇO EM MEMÓRIA
#include <locale.h>//BIBLIOTECA DE ALOCAÇÕES DE TEXTO POR REGIÃO
#include <string.h>//BIBLIOTECA RESPONSÁVEL POR CUIDAR DOS STRING
int registro ()
{
    setlocale(LC_ALL, "Portuguese");

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o seu CPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //RESPOSÁVEL POR COPIAR OS VALORES DAS STRING

    FILE *file; //CRIA O ARQUIVO
    file = fopen(arquivo, "w"); // CRIA O ARQUIVO
    fprintf(file,cpf);//SALVA O VALOR DA VARIAVEL
    fclose(file);// FECHAR O ARQUIVO

    file = fopen(arquivo, "a");//PARA INCLUIR ( PARA ATUALIZAR)
    fprintf(file,",");
    fclose(file);

    printf("Digite o seu nome: ");
    scanf("%s",nome);

    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite seu sobrenome: ");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Qual é seu cargo? ");
    scanf("%s",cargo);

    file = fopen (arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");

}
int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite seu CPF: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("CPF não localizado!.\n");
    }
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}

int deleta ()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema! \n ");
        system("pause");
    }
}
int main()
{
    int opcao = 0; // DEFININDO VARIAVEL
    int x=1;

    for(x=1;x=1;)
    {
        system("cls");
        setlocale(LC_ALL, "Portuguese");
        printf("*** Cartório da EBAC ***\n\n"); // INICIO DO MENU
        printf("Escolha a opção desejada do menu:\n\n ");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do Sistema\n\n");// FIM DO MENU

        printf("Qual é opção desejada? ");

        scanf("%d", &opcao);// ARMAZENANDO A ESCOLHA DO USUARIO

        system("cls");

    switch(opcao)
    {
        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deleta();
            break;

        case 4:
            printf("Obrigado por utilizar o sistema! \n");
            return 0;
            break;

        default:
            printf("Opção não encontrada !\n");
            system("pause");
            break;

    }


    }                                            // FIM DE SELEÇÃO
}

