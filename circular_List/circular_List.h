#ifndef circListh
#define circListh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../linked_List/aluno.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define ELEMENT_NOT_FOUND -2
#define OUT_OF_RANGE -3
#define OUT_OF_MEMORY -4

typedef struct circularList List;

List* create_circ();
int free_circ(List *circ);
int push_front_circ(List *circ, struct aluno TODO);
int push_back_circ(List *circ, struct aluno TODO);
int pop_front_circ(List *circ);
int pop_back_circ(List *circ);
int size_circ(List *circ);
int front_circ(List *circ, struct aluno *TODO);
int back_circ(List *circ, struct aluno *TODO);
int print_circ(List *circ);
int get_pos_circ(List *circ, int pos, struct aluno *TODO);//
int get_mat_circ(List *circ, int nmat, struct aluno *TODO);
int next_circ(List *circ, struct aluno *TODO);
int insert_circ(List *circ, int pos, struct aluno TODO);
int erase_circ(List *circ, int pos);

#endif