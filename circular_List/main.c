#include "circular_List.h"
#include <stdio.h>

void menu(){

    printf("\na. Criar um TODO com alta prioridade");
    printf("\nb. Criar um TODO com baixa prioridade");
    printf("\nc. Inserir um TODO com posição específica");
    printf("\nd. TODO feito?? Remover o primeiro TODO");
    printf("\ne. Desisti do Ultimo TODO =((( Remover TODO");
    printf("\nf. O.o Remover um TODO pela posição");
    printf("\ng. Não sei nem por onde começar.....Ver o primeiro TODO");
    printf("\nh. Será que posso desistir de um??....Ver o ultimo TODO");
    printf("\ni. Ver um TODO pela posição");
    printf("\nj. Ver o TODO pelo código de prioridade");
    printf("\nk. Ver o proximo TODO a ser feito");
    printf("\nl. Enrolar e ver tudo que tem pra fazer....Imprimir os TODOs... e desesperar");
    printf("\nm. Desesperar......Ver quantidade de TODO listados");
    printf("\ns. Desistir do TODO");
    printf("\n\n******************************************\n");


}


int main(){
    List *circ = create_circ();
    if(circ == NULL){
        return INVALID_NULL_POINTER;
    }
    struct aluno TODO;

    int test = 0, i = 0, j = 0, post = 0, codigo = 0;

    printf("\n\n************************\n");
    printf("***** TODO list *****\n");

    printf("\nInsira um primeiro TODO");
    printf("\nDigite o código de prioridade (apenas números): ");
    scanf("%d", &TODO.matricula);
    printf("\nDigite o nome do seu TODO: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", TODO.nome);
    printf("\nDigite as horas necessárias para realizar seu TODO: ");
    scanf("%f", &TODO.n1);
    printf("\nDigite as horas já trabalhadas no seu TODO: ");
    scanf("%f", &TODO.n2);
    printf("\nDigite as horas que faltam para finalizar seu TODO: ");
    scanf("%f", &TODO.n2);

    test = push_front_circ(circ, TODO);


    char op;
    while (1){
        
        menu();
        printf("\n\nO que deseja fazer a seguir: \n");
        scanf("%c", &op);

        switch (op){
            case 'a':
                TODO.matricula = i;
                i++;
                printf("\nDigite o nome do seu TODO: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]", TODO.nome);
                printf("\nDigite as horas necessárias para realizar seu TODO: ");
                scanf("%f", &TODO.n1);
                printf("\nDigite as horas já trabalhadas no seu TODO: ");
                scanf("%f", &TODO.n2);
                printf("\nDigite as horas que faltam para finalizar seu TODO: ");
                scanf("%f", &TODO.n2);

                test = push_front_circ(circ, TODO);
                if(test == SUCCESS){
                    printf("\n\nTODO inserido com sucesso");
                }else{
                    printf("\n\nTente novamente");
                }
                break;
        
            case 'b':
                TODO.matricula = j + i;
                j++;
                printf("\nDigite o nome do seu TODO: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]", TODO.nome);
                printf("\nDigite as horas necessárias para realizar seu TODO: ");
                scanf("%f", &TODO.n1);
                printf("\nDigite as horas já trabalhadas no seu TODO: ");
                scanf("%f", &TODO.n2);
                printf("\nDigite as horas que faltam para finalizar seu TODO: ");
                scanf("%f", &TODO.n2);

                test = push_front_circ(circ, TODO);
                if(test == SUCCESS){
                    printf("\n\nTODO inserido com sucesso");
                }else{
                    printf("\n\nTente novamente");
                }
                    break;
    
            case 'c':
                printf("\nDigite a posição desejada: ");
                scanf("%d", &post);
                printf("\nDigite o código de prioridade (apenas números): ");
                scanf("%d", TODO.matricula);
                printf("\nDigite o nome do seu TODO: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]", TODO.nome);
                printf("\nDigite as horas necessárias para realizar seu TODO: ");
                scanf("%f", &TODO.n1);
                printf("\nDigite as horas já trabalhadas no seu TODO: ");
                scanf("%f", &TODO.n2);
                printf("\nDigite as horas que faltam para finalizar seu TODO: ");
                scanf("%f", &TODO.n2);

                test = push_front_circ(circ, TODO);
                if(test == SUCCESS){
                    printf("\n\nTODO inserido com sucesso");
                }else{
                    printf("\n\nTente novamente");
                }
                    break;

            case 'd':

                test = pop_front_circ(circ);
                if(test == SUCCESS){
                    printf("\n\nParabens pelo avanço");
                }else{
                    printf("\n\nERRO: algo não quer que vc diminua os afazeres");
                }

                break;

            case 'e':
                test = pop_back_circ(circ);
                if(test == SUCCESS){
                    printf("\n\nPena que desistiu, tem mais...");
                }else{
                    printf("\n\nERRO: algo não quer que vc desista, tente novamente");
                }
                break;

            case 'f':

                printf("\ndigite a posição do TODO: ");
                scanf("%d", &post);

                test = erase_circ(circ, post);
                if(test == SUCCESS){
                    printf("\n\nPena que desistiu, tem mais...");
                }else{
                    printf("\n\nERRO: algo não quer que vc desista, tente novamente");
                }
                break;

            case 'g':

                test = front_circ(circ, &TODO);
                
                if(test == SUCCESS){
                    printf("\n*****************Primeiro TODO******************\n");
                    printf("Código de prioridade: %d\n", TODO.matricula);
                    printf("O que preciso fazer: %s\n", TODO.nome);
                    printf("Horas necessárias: %.2f, Horas trabalhadas: %.2f, Falta: %.2f\n", TODO.n1,
                        TODO.n2,
                        TODO.n3);
                    printf("\n******************************************\n");

                }else{
                    printf("\n\nERRO: você está mais perdido que....");
                }
                break;

            case 'h':
                test = back_circ(circ, &TODO);
                if(test == SUCCESS){
                    printf("\n*****************Ultimo TODO******************\n");
                    printf("Código de prioridade: %d\n", TODO.matricula);
                    printf("O que preciso fazer: %s\n", TODO.nome);
                    printf("Horas necessárias: %.2f, Horas trabalhadas: %.2f, Falta: %.2f\n", TODO.n1,
                        TODO.n2,
                        TODO.n3);
                    printf("\n******************************************\n");

                }else{
                    printf("\n\nERRO: deixa pra lá....");
                }

                break;

            case 'i':

                printf("\ndigite a posição do TODO: ");
                scanf("%d", &post);

                test = get_pos_circ(circ, post, &TODO);

                if(test == SUCCESS){
                    printf("\n*****************Ultimo TODO******************\n");
                    printf("Código de prioridade: %d\n", TODO.matricula);
                    printf("O que preciso fazer: %s\n", TODO.nome);
                    printf("Horas necessárias: %.2f, Horas trabalhadas: %.2f, Falta: %.2f\n", TODO.n1,
                        TODO.n2,
                        TODO.n3);
                    printf("\n******************************************\n");

                }else{
                    printf("\n\nERRO: deixa pra lá....");
                }
                break;

            case 'j':

                printf("\nDigite o código do TODO: ");
                scanf("%d", &codigo);

                test = get_mat_circ(circ, codigo, &TODO);

                if(test == SUCCESS){
                    printf("\n*****************Ultimo TODO******************\n");
                    printf("Código de prioridade: %d\n", TODO.matricula);
                    printf("O que preciso fazer: %s\n", TODO.nome);
                    printf("Horas necessárias: %.2f, Horas trabalhadas: %.2f, Falta: %.2f\n", TODO.n1,
                        TODO.n2,
                        TODO.n3);
                    printf("\n******************************************\n");

                }else{
                    printf("\n\nERRO: deixa pra lá....");
                }
                break;

            case 'k':

                test = next_circ(circ, &TODO);

                if(test == SUCCESS){
                        printf("\n*****************Proximo TODO******************\n");
                        printf("Código de prioridade: %d\n", TODO.matricula);
                        printf("O que preciso fazer: %s\n", TODO.nome);
                        printf("Horas necessárias: %.2f, Horas trabalhadas: %.2f, Falta: %.2f\n", TODO.n1,
                            TODO.n2,
                            TODO.n3);
                        printf("\n******************************************\n");

                    }else{
                        printf("\n\nERRO: tô de folga....");
                    }
                    break;
 
            case 'l':

                test = print_circ(circ);
                if(test != SUCCESS){
                    printf("\n\nERRO: com certeza não tem nada pra fazer, partiu Netflix");
                }

                break;

            case 'm':
                printf("\n\nCerteza que quer fazer isso???... tarde demais");

                test = size_circ(circ);
                if(test != INVALID_NULL_POINTER){
                    printf("\n\nVocê tem %d atividades para fazer..", test);
                } else{
                    printf("\n\nERRO: com certeza não tem nada pra fazer, partiu Netflix");
                }

                break;

            case 's':

                printf("\n\nNão faça isso.... ¬¬'");
                test = free_circ(circ);
                if(test == SUCCESS){
                    printf("\n\Você vai se afogar me apagando");
                    return 0;
                }else{
                    printf("\n\Impossível se livrar de mim, era só uma fachada...");
                    break;
                }
    

            default:
                break;
        }
    
    }
    return 0;

}