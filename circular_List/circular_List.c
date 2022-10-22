#ifndef circularListc
#define circularListc

#include "circular_List.h"

typedef struct nodeCircular{
    struct nodeCircular *next;
    struct aluno al;
} NodeCir;

struct circularList{
    int size;
    struct nodeCircular *end;
    struct nodeCircular *next;
};

List *create_circ(){

    List *circ = malloc(sizeof(List));
    if (circ != NULL){

        circ->end = NULL;
        circ->size = 0;
    }
    return circ;
}

int free_circ(List *circ){
    if (circ == NULL)    {
        return INVALID_NULL_POINTER;
    }
    if (circ->size == 0){
        free(circ);
        return SUCCESS;
    }
    NodeCir *circFree, *cirFree = circ->end;
    while (circ->size != 0){
        circFree = cirFree;
        free(circFree);
        cirFree = cirFree->next;
        circ->size--;
    }
    return SUCCESS;
}

int push_front_circ(List *circ, struct aluno al){
    if (circ != NULL){
        NodeCir *nodeFront = malloc(sizeof(NodeCir));
        nodeFront->al = al;

        if (nodeFront == NULL){
            return OUT_OF_RANGE;
        }

        if (circ->end == NULL){
            circ->end = nodeFront;
            nodeFront->next = nodeFront;
        }
        else{
            nodeFront->next = circ->end->next;
            circ->end->next = nodeFront;
        }
        circ->size++;
        return SUCCESS;
    }
}

int push_back_circ(List *circ, struct aluno al){
    if(circ == NULL){
        return INVALID_NULL_POINTER;
    }
    
    NodeCir *nodeBack = malloc(sizeof(NodeCir));
    if(nodeBack == NULL){
        return OUT_OF_RANGE;
    }
    nodeBack->al = al;

    if(circ->size == 0){
        nodeBack->next = nodeBack;
        circ->end = nodeBack;

    }else{
        nodeBack->next = circ->end->next;  
        circ->end->next = nodeBack;
        circ->end = nodeBack;
    
    }
    circ->size++;
    return SUCCESS;
}

int insert_circ(List *circ, int pos, struct aluno al){
    if(circ == NULL){
        return OUT_OF_RANGE;
    }
    NodeCir *nodeBpos = malloc(sizeof(NodeCir));
    if(nodeBpos == NULL){
        return OUT_OF_MEMORY;
    }
    nodeBpos->al = al;
    if(pos == 1){
        nodeBpos->next = circ->end->next;
        circ->end->next = nodeBpos;
        circ->size++;
        return SUCCESS;
    }
    if(pos > circ->size){
        nodeBpos->next = circ->end;
        circ->end = nodeBpos;
        circ->size++;
        return SUCCESS;        
    }

    NodeCir *nodeAux, *nodepos = circ->end->next;
    int cont = 1;
    while (cont <= circ->size && cont != pos){
        nodeAux = nodepos;
        nodepos = nodepos->next;
        cont ++;
    }
    if(cont > circ->size || cont != pos){
        return OUT_OF_MEMORY;
    }
    nodeAux->next = nodeBpos;
    nodeBpos->next = nodepos;
    circ->size++;
    return SUCCESS;

}


int pop_front_circ(List *circ){
    if(circ == NULL && circ->end == NULL){
        return OUT_OF_RANGE;
    }

    if(circ->size == 1){
        free(circ->end);
    }else{
        NodeCir *popFront = circ->end->next;
        circ->end->next = popFront->next;
        free(popFront);
    }
        circ->size--;
        return SUCCESS;

}

int pop_back_circ(List *circ){
    if(circ == NULL){
        return INVALID_NULL_POINTER;
    }if(circ->size == 1){
        free(circ->end);

    }else{
    NodeCir *popBack = circ->end->next;
    while (popBack->next != circ->end){
        popBack = popBack->next;
    }
    popBack->next = circ->end->next;
    circ->end = popBack;

    }
    circ->size--;
    return SUCCESS;
}

int erase_circ(List *circ, int pos){
    if(circ == NULL){
        return INVALID_NULL_POINTER;
    }
    if(pos > circ->size){
        return OUT_OF_MEMORY;
    }
    if(circ->size == 1 && pos == 1){
        free(circ->end);
        circ->size = 0;
        return SUCCESS;
    }
    
    NodeCir *nodeAux, *nodepos = circ->end->next;
    int cont = 1;
    while (cont <= circ->size && cont != pos){
        nodeAux = nodepos;
        nodepos = nodepos->next;
        cont ++;
    }
    if(cont > circ->size || cont != pos){
        return OUT_OF_MEMORY;
    }
    nodeAux->next = nodepos->next;
    free(nodepos);
    circ->size--;
    return SUCCESS;

}

int front_circ(List *circ, struct aluno *al){
    if(circ == NULL && circ->size == 0){
         return OUT_OF_MEMORY;
    }
    *al = circ->end->next->al;
    return SUCCESS;
}

int back_circ(List *circ, struct aluno *al){
    if(circ == NULL && circ->size == 0){
         return OUT_OF_MEMORY;
    }
    *al = circ->end->al;
    return SUCCESS;
}

int get_pos_circ(List *circ, int pos, struct aluno *al){
    if(circ == NULL && circ->size == 0){
         return OUT_OF_MEMORY;
    }
    
    int post = pos;
    if(post < 0 && post > circ->size){
        return OUT_OF_MEMORY;
    }
    if(post == 1){
        *al = circ->end->next->al;
        return SUCCESS;
    }
    if(post = circ->size){
        *al = circ->end->al;
    }

    NodeCir *nodeSe = circ->end->next;
    int cont = 1;
    while (cont <= circ->size && cont != post){
        nodeSe = nodeSe->next;
        cont++;
    }
    if(cont > circ->size){
        return ELEMENT_NOT_FOUND;
    }
    *al = nodeSe->al;
    return SUCCESS;    
    
}

int get_mat_circ(List *circ, int nmat, struct aluno *al){
    if(circ == NULL && nmat < 0){
        return INVALID_NULL_POINTER;
    }
    if(circ->size == 0){
        return OUT_OF_RANGE;
    }
    if(circ->end->al.matricula == nmat){
        *al = circ->end->al;
        return SUCCESS;
    }
    NodeCir *nodeMat = circ->end;
    int cont;
    while(cont <= circ->size && nodeMat->al.matricula != nmat){
        nodeMat = nodeMat->next;
        cont++;
    }
    if(cont == circ->size && nodeMat->al.matricula != nmat){
        return OUT_OF_RANGE;
    }
    *al = nodeMat->al;
    return SUCCESS;
}

int size_circ(List *circ){
    if(circ == NULL){
        return INVALID_NULL_POINTER;
    }
    return circ->size;
}

int print_circ(List *circ){
    if (circ == NULL && circ->end == NULL){
        return OUT_OF_MEMORY;
    }

    NodeCir *nodePrint = circ->end->next;
    int cnt = circ->size;

    while (cnt != 0){
        printf("\n*****************Aluno******************\n");
        printf("Matricula: %d\n", nodePrint->al.matricula);
        printf("Nome: %s\n", nodePrint->al.nome);
        printf("Notas: %.2f, %.2f, %.2f\n", nodePrint->al.n1,
               nodePrint->al.n2,
               nodePrint->al.n3);
        printf("\n******************************************\n");
        nodePrint = nodePrint->next;
        cnt--;

    }
    return SUCCESS;
}

int next_circ(List *circ, struct aluno *al){
    if(circ == NULL){
        return INVALID_NULL_POINTER;
    }
        *al = circ->next->al;
        circ->next = circ->next->next;
        return SUCCESS;

}

#endif