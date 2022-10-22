#ifndef linked_listh
#define linked_listh

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "aluno.h"

typedef struct list list;
list* linked_list_create();// ponteiro pq ta oculto no ponto.c//

int linked_list_free(list *li);//

int linked_list_push_front(list *li, struct aluno al);

int linked_list_push_Back(list *li, struct aluno al);//

int linked_list_print(list *li);

int linked_list_insert(list *li, int pos, struct aluno al);

int linked_list_insert_sorted(list *li, struct aluno al);
///
int linked_list_size(list *li);

int linked_list_pop_front(list *li);

int linked_list_pop_back(list *li);

int linked_list_erase(list *li, int pos);

int linked_list_find_pos(list *li, int mat, struct aluno *al);

int linked_list_find_mat(list *li, int nmat, struct aluno *al);

int linked_list_front(list *li, struct aluno *al);

int linked_list_back(list *li, struct aluno *al);
///////////////////////////////////
int linked_list_get_pos(list *li, int *pos);
/**
int imprime_lista(lista *li);//
int insere_lista_inicio(lista *li, struct aluno al);//
//int consulta_lista_posit(lista *li, int posit, struct aluno *al);//
//int consulta_lista_matric(lista *li, int mat, struct aluno *al);//
//int insere_Lista_ordenada(lista *li, struct aluno al);//
int remove_daLista(lista *li, int mat);//
int remove_daLista_inicio(lista *li);//
int remove_daLista_fim(lista *li);
int tamanho_lista(lista *li);//
int lista_cheia(lista *li);//
int remove_lista_otimizado(lista *li, int mat);//
*/
#endif // DEBUG
