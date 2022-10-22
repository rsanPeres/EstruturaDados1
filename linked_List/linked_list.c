#ifndef linked_listc
#define linked_listc

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



struct nodeList{
    struct nodeList *next;
    struct aluno al;
};

struct list{  
    int qtdAl;//controle da quantidade de elementos 
    struct nodeList *begin;
   
};

list* linked_list_create(){ 
    list *li; 
    li = malloc(sizeof(list));
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }
    li->begin = NULL;
    li->qtdAl = 0;
    return li;
}

int linked_list_free(list *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }
    if(li->qtdAl == 0){
    free(li);
    return SUCCESS;

    }if(li->qtdAl == 1){
        free(li->begin);
        free(li);
        return SUCCESS;
    }
        struct nodeList *nodeFree, *nodeFree1;
        nodeFree1 = li->begin;

        while(nodeFree1 != NULL){
            nodeFree = nodeFree1;
            free(nodeFree);
            nodeFree1 = nodeFree1->next;
        }
        
        free(li);
        return SUCCESS;

    
    return SUCCESS;
}

int linked_list_push_front(list *li, struct aluno al){
   if(li == NULL){
        return INVALID_NULL_POINTER;
    }
        struct nodeList *nodeFront = malloc(sizeof(struct nodeList));
        if(nodeFront == NULL){
            return OUT_OF_MEMORY;
        }
        nodeFront->al = al;
        nodeFront->next = NULL;

        if(li->qtdAl == 0){
            li->begin = nodeFront;
            li->qtdAl++;
            return SUCCESS;
            
        }
            nodeFront->next = li->begin;
            li->begin = nodeFront; 
            li->qtdAl++;

        return SUCCESS;
}


int linked_list_push_Back(list *li, struct aluno al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }
        struct nodeList *nodeback = malloc(sizeof(struct nodeList));
        if(nodeback == NULL){
            return OUT_OF_MEMORY;
        }
        nodeback->al = al;
        nodeback->next = NULL;

        
    if(li->qtdAl == 0){

        li->begin = nodeback;
        li->qtdAl++;
        return SUCCESS;

    }if(li->qtdAl == 1){

        li->begin->next = nodeback;
        li->qtdAl++;
        return SUCCESS;
    
    }
        struct nodeList *nodeTemp;
        nodeTemp = li->begin;

        while(nodeTemp->next != NULL){
            nodeTemp = nodeTemp->next;
    
        }
        nodeTemp->next = nodeback; 
        li->qtdAl++;
        return SUCCESS;
}

int linked_list_print(list *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;

    }if(li->qtdAl != 0){

        struct nodeList *nodePrint = li->begin;
        int cnt = 1;

        while(nodePrint != NULL && cnt <= li->qtdAl){
            printf("\n***************Aluno n: %d***********\n", cnt);
            printf("Matricula: %d\n", nodePrint->al.matricula);
            printf("Nome: %s\n", nodePrint->al.nome);
            printf("Notas: %f, %f, %f\n", nodePrint->al.n1,
                                      nodePrint->al.n2,
                                      nodePrint->al.n3);
            printf("\n******************************************\n");
            nodePrint = nodePrint->next;
            cnt++;
        }
        
    }

    return SUCCESS;
}
int linked_list_insert(list *li, int pos, struct aluno al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    
    }
    struct nodeList *nodePos = malloc(sizeof(struct nodeList));
    if(nodePos == NULL){
        return INVALID_NULL_POINTER;
    }

        nodePos->al = al; 
        nodePos->next = NULL;
    
        int cont = 1;
        if(li->begin == NULL){
            li->begin = nodePos;
            li->qtdAl++;
            return SUCCESS;
    
        }
        if(pos == 1){
            nodePos->next = li->begin;
            li->begin = nodePos;
            li->qtdAl++;
            return SUCCESS;

        }
            struct nodeList *nodeSearch;
            nodeSearch = li->begin;

            while(nodeSearch->next != NULL && cont != pos - 1){
                nodeSearch = nodeSearch->next;
            }
            nodePos->next = nodeSearch->next;
            nodeSearch->next = nodePos;
            li->qtdAl++;
        
    
        return SUCCESS;
    
}

int linked_list_insert_sorted(list *li, struct aluno al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    
    }
    struct nodeList *nodeSorted = malloc(sizeof(struct nodeList));
    if(nodeSorted == NULL){
        return OUT_OF_MEMORY;

    }
        nodeSorted->al = al;
        nodeSorted->next = NULL;

        if(li->begin == NULL){
            li->begin = nodeSorted;
            li->qtdAl++;
            return SUCCESS;
        
        }
        if(li->begin->al.matricula > nodeSorted->al.matricula){
            nodeSorted->next = li->begin;
            li->begin = nodeSorted;
            li->qtdAl++; 
            return SUCCESS;
        }

            struct nodeList *nodeMenor, *nodeMaior = li->begin;

            while(nodeMaior != NULL && nodeSorted->al.matricula > nodeMaior->al.matricula ){
                nodeMenor = nodeMaior;
                nodeMaior = nodeMaior->next;
            }
            nodeSorted->next = nodeMenor->next;
            nodeMenor->next = nodeSorted; 
            
        li->qtdAl++;
        return SUCCESS;
    
}


int linked_list_size(list *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }
    return li->qtdAl;
}

int linked_list_pop_front(list *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    
    }
    if(li->begin == NULL){
        return OUT_OF_MEMORY;
    }
    li->begin = li->begin->next;
    li->qtdAl--;
    return 0;
}

   int linked_list_pop_back(list *li){
        if(li == NULL){
            return INVALID_NULL_POINTER;
        
        }if(li->begin == NULL){
            return OUT_OF_MEMORY;
        }if(li->begin->next == NULL){
            free(li->begin);
            
        }else{

            struct nodeList *nodePopb = li->begin;

        while(nodePopb->next->next != NULL){
            nodePopb = nodePopb->next;
        }
        nodePopb->next = NULL;
        }
        li->qtdAl--;
        return SUCCESS;
    }

    int linked_list_erase(list *li, int pos){
        if(li == NULL){
            return INVALID_NULL_POINTER;
        }if(li->begin == NULL && pos < 0){
            return OUT_OF_MEMORY;
        
        }else {
            if(pos == 1){
            li->begin = li->begin->next;
            li->qtdAl--;
            return SUCCESS;
            }

            struct nodeList *nodeEr, *nodeErase = li->begin;
            int i = 1;
            while (nodeErase != NULL && i != pos){
                nodeEr = nodeErase;
                nodeErase = nodeErase->next;
                i++;
            }
            if(nodeErase == NULL){
                nodeEr->next = NULL;
                free(nodeErase);
                li->qtdAl--;
                return SUCCESS;
            }
            nodeEr->next = nodeErase->next;
            free(nodeErase);
            li->qtdAl--;
            return SUCCESS;
        }
        
    }

    int linked_list_find_pos(list *li, int mat, struct aluno *al){
        int nmat = mat, i = 1;
        if(li == NULL){
            return INVALID_NULL_POINTER;

        }if(li->begin == NULL){
            return OUT_OF_MEMORY;
        
        }else{
         int nmat = mat, i = 1;
         struct nodeList *nodeFind = li->begin;

         while (nmat != nodeFind->al.matricula && nodeFind != NULL){
             nodeFind = nodeFind->next;
             i++;
         }
         if(nodeFind == NULL){
             return OUT_OF_MEMORY;
         }
         *al = nodeFind->al;
            
        }
        return i;
    }

    int linked_list_find_mat(list *li, int pos, struct aluno *al){
        
        if(li != NULL){
            if(pos > 0 && li->begin != NULL){
                int post = pos;
                int i = 1;

                if(post == 1){
                    *al = li->begin->al;
                    return SUCCESS;
                }else{
            
                    struct nodeList *nodeFpos;
                    nodeFpos = li->begin;

                    while(i != post && nodeFpos != NULL){
                        i++;
                        nodeFpos = nodeFpos->next;
                
                    }if(nodeFpos == NULL){
                        return OUT_OF_MEMORY;
                    }
                    *al = nodeFpos->al;

                    return SUCCESS;
                }
            }

            return OUT_OF_MEMORY;
        
        }
            return INVALID_NULL_POINTER;
    
    }

 int linked_list_front(list *li, struct aluno *al){
     if(li != NULL){
         if(li->begin != NULL){
             *al = li->begin->al;
             return SUCCESS;
         }
         return OUT_OF_MEMORY;
     }
     return INVALID_NULL_POINTER;
 }

 int linked_list_back(list *li, struct aluno *al){
     if(li != NULL){
         if(li->begin != NULL){
             struct nodeList *nodePback = li->begin;
             while(nodePback->next != NULL){
                 nodePback = nodePback->next;
             }
             *al = nodePback->al;
             return SUCCESS;
         }
         return OUT_OF_MEMORY;
     }
     return INVALID_NULL_POINTER;
 }



/**

int consulta_lista_posit(lista *li, int posit, struct aluno *al){
    if(li == NULL || posit < 0 || posit > li->nLista)
        return -1;
    *al = li -> dados[posit-1];
    return 0;
    }

int consulta_lista_matric(lista *li, int mat, struct aluno *al){
    if(li == NULL){
        return -1;
    }
    int i = 0;
    while (i < li->nLista && li->dados[i].matricula != mat){
        i++;
        
    }
    if(i == li->nLista)
        return -1;
    *al = li->dados[i];
    return 0;
}

/**int insere_Lista_ordenada(lista *li, struct aluno al){
    
    if(li == NULL)
        return -1;
    if(li->nLista == li->tamanho)//lista cheia
    {
        int novo_tamanho = li->tamanho + li->tamanho_inicial;
        alterar_tamanho_lista(li, novo_tamanho);
    }

    int i = 0;
    while (i < li->nLista && li->dados[i].matricula < al.matricula){ //procura lugar de inserção 
        i++;
    }
    for(int j = li->nLista - 1; j >= 0; j--){ // movendo elementos p frente
        li->dados[j + 1] = li->dados[k];
    }
    li->dados[i] = al;//colando na ordem
    li->nLista ++;
    return 0;

}

int remove_daLista(lista *li, int mat){
    if(li == NULL || li->nLista == 0)
    return -1;
    int i = 0;
    while(i < li->nLista && li->dados[i].matricula != mat){
        i++;
    }

    if(i == li->nLista)
    return 0;

   for(int j = i; j < li->nLista - 1; j ++){
        li->dados[j] = li->dados[j + 1];
    }
    li->nLista --;
    return 0;

}

int remove_daLista_inicio(lista *li){
    if(li == NULL)
    return -1;
    for(int i = 0; i < li->nLista - 1; i ++){
        li->dados[i] = li->dados[i + 1];
    }
    li->nLista --;
    return 0;

}

int remove_daLista_fim(lista *li){
    if(li == NULL || li->nLista == 0)
        return -1;
    li->nLista --;
    return 0;

}

int tamanho_lista(lista *li){
    if (li == NULL){
        return -1;
    }
    
    return li->nLista;
} 

int lista_cheia(lista *li){
    if(li == NULL)
        return -1;
    if(li->nLista == MAX)
    return 0;
}

int lista_vazia(lista *li){
    if (li == NULL)
        return -1;
    if(li->nLista == 0)
    return 0;
    
}

int remove_lista_otimizado(lista *li, int mat){//para listas sem importância de ordem
    if(li == NULL || li->nLista == 0)
    return -1;
    
    int i = 0;
    while(i < li->nLista && li->dados[i].matricula != mat){
        i++;
    }

    if(i == li->nLista)
    return 0;

    li->nLista --;
    li->dados[i] = li->dados[li->nLista];
    

    return 0;
}

**/
#endif // !l-inked_list


