#include <stdio.h>
#include <string.h>

#define MAX 50

struct filmes {
    char nomeFilme;
    int tipo;
    int status;
};

void menu(struct filmes f1[MAX], int *cont);
void adicionarFilme(struct filmes f1[MAX], int *cont);
void atualizarStatus(struct filmes f1[MAX], int *cont);
void consultarCatalogo(struct filmes f1[MAX], int *cont);
void exluirEntrada(struct filmes f1[MAX], int *cont);

int main() {
    struct filmes f1[MAX];
    int cont = 0;
    menu(f1, &cont);
}

void menu(struct filmes f1[MAX], int *cont) {
    int opcao = 0;

    do {
        printf("\n[1] - Adicionar série ou filme\n");
        printf("[2] - Atualizar Status\n");
        printf("[3] - Consultar Catálogo\n");
        printf("[4] - Excluir Entrada\n");
        printf("[5] - Sair\n");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                adicionarFilme(f1, cont);
                break;
            case 2:
                atualizarStatus(f1, cont);
                break;
            case 3:
                consultarCatalogo(f1, cont);
                break;
            case 4:
                exluirEntrada(f1, cont);
                break;
            default:
                if (opcao != 5) {
                    printf("Opção inválida!\n");
                }
                break;
        }

    } while (opcao != 5);
}

void adicionarFilme(struct filmes f1[MAX], int *cont) {
    char nome;
    

    printf("Digite o nome do filme (um único caractere): ");
    scanf("%c", &nome);
    getchar(); 

    f1[*cont].nomeFilme = nome;

   
    for (int i = 0; i < *cont; i++) {
        if (f1[i].nomeFilme == f1[*cont].nomeFilme) {
            printf("Esse filme já está cadastrado.\n");
            return;
        }
    }

    
    printf("\nQual o tipo que você deseja adicionar:\n");
    printf("[1] - Série\n");
    printf("[2] - Filme\n");
    scanf("%d", &f1[*cont].tipo);
    getchar();  

    printf("\nQual é o status do filme/série que está adicionando?\n");
    printf("[1] - Não iniciado\n");
    printf("[2] - Assistindo\n");
    printf("[3] - Concluído\n");
    scanf("%d", &f1[*cont].status);
    getchar();  

    (*cont)++; 
}

void atualizarStatus(struct filmes f1[MAX], int *cont) {
    char nome;
    int status = 0;


    printf("Digite o nome do filme/série que deseja mudar o status: ");
    scanf("%c", &nome);
    getchar();

    for (int i = 0; i < *cont; i++) {
        if (f1[i].nomeFilme == nome) {
            printf("\nQual o status atual dele:\n");
            printf("[1] - Não iniciado\n");
            printf("[2] - Assistindo\n");
            printf("[3] - Concluído\n");
            scanf("%d", &status);
            getchar();

            if (status == f1[i].status) {
                printf("Esse filme/série já está com esse status.\n");
            } else {
                f1[i].status = status;
                printf("Status atualizado.\n");
            }
            return; 
        }
    }

    printf("Não existe cadastro desse filme/série.\n");
}

void consultarCatalogo(struct filmes f1[MAX], int *cont) {
    for (int i = 0; i < *cont; i++) {
        if (f1[i].status == 1) {
            printf("Não iniciado: %c\n", f1[i].nomeFilme);
        } else if (f1[i].status == 2) {
            printf("Assistindo: %c\n", f1[i].nomeFilme);
        } else if (f1[i].status == 3) {
            printf("Concluído: %c\n", f1[i].nomeFilme);
        }
    }
}

void exluirEntrada(struct filmes f1[MAX], int *cont) {
    char nome;
    
    printf("Qual o nome do filme que deseja excluir? ");
    scanf("%c", &nome);
    getchar();  

    for (int i = 0; i < *cont; i++) {
        if (f1[i].nomeFilme == nome) {
            for (int j = i; j < *cont - 1; j++) {
                f1[j] = f1[j + 1];
            }
            (*cont)--;
            printf("Filme excluído com sucesso.\n");
            return;
        }
    }

    printf("Filme não encontrado.\n");
}
