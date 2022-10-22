#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(){
    printf("************* Lista de alunos ***************\n");
    printf("a. Inserir ao Inicio\n");
    printf("b. Inserir ao Final\n");
    printf("c. Inserir por posição\n");
    printf("d. Inserir Ordenadamente\n");
    printf("e. Consulta por Matricula\n");
    printf("f. Consulta por Posição\n");
    printf("g. Remover da Lista pela posição: \n");
    printf("h. Remover do Inicio\n");
    printf("i. Remover do Fim\n");
    printf("j. Tamanho da Lista\n");
    printf("k. Retorna primeiro da lista: \n");
    printf("l. Retorna ultimo da lista: \n");
    printf("s. Sair e romover a lista\n");
    printf("************* *************** ***************\n\n");
}

int main()
{

    list *list = linked_list_create();

    struct aluno alunoNovo;
    int resul;
    int pos = 0;
    int nmat = 0;

    char option;
    while (1){

        menu();

        printf("digite a opção desejada: ");
        scanf(" %c", &option);
        printf("\n\n");

        switch (option){
        case 'a':

            printf("Digite a matricula do aluno: ");
            scanf("%d", &alunoNovo.matricula);
            printf("Digite o nome do aluno: ");
            getchar();
            fgets(alunoNovo.nome, 30, stdin);
            printf("Digite as três notas do aluno: ");
            scanf("%f %f %f", &alunoNovo.n1, &alunoNovo.n2, &alunoNovo.n3);

            resul = linked_list_push_front(list, alunoNovo);

            printf("%d\n", resul);

            linked_list_print(list);

            break;

        case 'b':

            printf("Digite a matricula do aluno: ");
            scanf("%d", &alunoNovo.matricula);
            printf("Digite o nome do aluno: ");
            getchar();
            fgets(alunoNovo.nome, 30, stdin);
            printf("Digite as três notas do aluno: ");
            scanf("%f %f %f", &alunoNovo.n1, &alunoNovo.n2, &alunoNovo.n3);

            resul = linked_list_push_Back(list, alunoNovo);

            printf("%d", resul);

            resul = linked_list_print(list);
            break;

        case 'c':

            printf("digite a posição para inserção do aluno: ");
            scanf("%d", &pos);
            printf("Digite a matricula do aluno: ");
            scanf("%d", &alunoNovo.matricula);
            printf("Digite o nome do aluno: ");
            getchar();
            fgets(alunoNovo.nome, 30, stdin);
            printf("Digite as três notas do aluno: ");
            scanf("%f %f %f", &alunoNovo.n1, &alunoNovo.n2, &alunoNovo.n3);

            resul = linked_list_insert(list, pos, alunoNovo);

            printf("%d\n", resul);

            resul = linked_list_print(list);

            break;

        case 'd':

            printf("Digite a matricula do aluno: ");
            scanf("%d", &alunoNovo.matricula);
            printf("Digite o nome do aluno: ");
            getchar();
            fgets(alunoNovo.nome, 30, stdin);
            printf("Digite as três notas do aluno: ");
            scanf("%f %f %f", &alunoNovo.n1, &alunoNovo.n2, &alunoNovo.n3);

            resul = linked_list_insert_sorted(list, alunoNovo);

            printf("%d\n", resul);

            linked_list_print(list);

            break;

        case 'e':
            printf("digite o numero de matricula: ");
            scanf("%d", &nmat);
            resul = linked_list_find_pos(list, nmat, &alunoNovo);

            printf("\nO aluno está na posição %d\n", resul);
            printf("Matricula do aluno: %d\n", alunoNovo.matricula);
            printf("Nome do aluno: %s\n", alunoNovo.nome);
            printf("Notas: %.2f, %.2f, %.2f\n", alunoNovo.n1,
                                                alunoNovo.n2,
                                                alunoNovo.n3);

            break;

        case 'f':

            printf("digite a posição do aluno: ");
            scanf("%d", &pos);
            resul = linked_list_find_mat(list, pos, &alunoNovo);

            printf("\nO aluno na posição %d é: \n", pos);
            printf("Matricula do aluno: %d\n", alunoNovo.matricula);
            printf("Nome do aluno: %s\n", alunoNovo.nome);
            printf("Notas: %.2f, %.2f, %.2f\n", alunoNovo.n1,
                                                alunoNovo.n2,
                                                alunoNovo.n3);

            break;

        case 'g':

            printf("digite a posição do aluno que deseja apagar: ");
            scanf("%d", &pos);
            resul = linked_list_erase(list, pos);
            linked_list_print(list);

            break;

        case 'h':
            resul = linked_list_pop_front(list);
            printf("%d\n\n", resul);
            linked_list_print(list);
            break;

        case 'i':
            resul = linked_list_pop_back(list);

            linked_list_print(list);
            break;

        case 'j':

            resul = linked_list_size(list);
            printf("A lista possui %d alunos cadastrados\n\n", resul);
            printf("%d", resul);
            break;

        case 'k':
            resul = linked_list_front(list, &alunoNovo);

            printf("Matricula do aluno: %d\n", alunoNovo.matricula);
            printf("Nome do aluno: %s\n", alunoNovo.nome);
            printf("Notas: %.2f, %.2f, %.2f\n", alunoNovo.n1,
                                                alunoNovo.n2,
                                                alunoNovo.n3);
            printf("%d", resul);
            break;

        case 'l':
            resul = linked_list_back(list, &alunoNovo);
            
            printf("Matricula do aluno: %d\n", alunoNovo.matricula);
            printf("Nome do aluno: %s\n", alunoNovo.nome);
            printf("Notas: %.2f, %.2f, %.2f\n", alunoNovo.n1,
                                                alunoNovo.n2,
                                                alunoNovo.n3);
            printf("%d", resul);
            break;

        case 's':

            resul = linked_list_free(list);
            printf("%d\n", resul);
            return 0;
        }
        
    }
    return 0;
}