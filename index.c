#include <stdio.h>
#include <math.h>
#include <string.h>

struct produto {
    char nome[100];
    double valor;
    int quantidade;
};

int contador =0;

void adicionarProduto(struct produto prods[], struct produto p);
void venderProduto(struct produto prods[], char nome[], int qnt);
void reporEstoque(struct produto prods[], char nome[], int qnt);
void imprimirProdutos(struct produto prods[]);

int main() {

    struct produto prods[100];
    int num;

    printf("Seja bem vindo de volta a sua conveniência o que deseja hoje? \n [1] Adicionar produto \n [2] Vender produto \n [3] Repor produto \n [4] Imprimir produtos \n [5] Sair ");
    scanf("%d", &num);


    while(num != 5 ){


        switch (num) {

            case 1:{

                struct produto novoProduto;
                printf("Digite o nome do produto: \n");
                scanf(" %[^\n]", novoProduto.nome);
                printf("Digite o valor do produto: \n");
                scanf(" %lf", &novoProduto.valor);
                printf("Digite a quantidade: ");
                scanf(" %d", &novoProduto.quantidade);
                adicionarProduto(prods, novoProduto);
                break;

            }

            case 2: {

                char name[100];
                double qnt;
                printf("Digite o nome do produto que deseja: \n ");
                scanf(" %s", &name);
                printf("Digite a quantidade que deseja vender: ");
                scanf(" %lf", &qnt);
                venderProduto( prods,  name, qnt);
                break;

            }

            case 3: {

                char name2[100];
                double qnt2;

                printf("Digite o nome do produto que deseja: \n");
                scanf(" %s", &name2);
                printf("Digite a quantidade que deseja vender: ");
                scanf(" %lf", &qnt2);
                reporEstoque( prods,  name2, qnt2);
                break;


            }

            case 4: {


                imprimirProdutos(prods);
                break;

            }

            case 5: {
                break;
            }


        }
        printf("Deseja mais alguma coisa? \n [1] Adicionar produto \n [2] Vender produto \n [3] Repor produto \n [4] Imprimir produtos \n [5] Sair ");
        scanf(" %d", &num);

    }


}

void adicionarProduto(struct produto prods[], struct produto p){
    prods[contador] = p;
    contador++;
}

void venderProduto(struct produto prods[], char name[], int qnt){
    int i;
    for(i = 0; i < contador; i++){
        if(strcmp(prods[i].nome, name) == 0){
            if(prods[i].quantidade >= qnt){
                prods[i].quantidade -= qnt;
            }
            else{
                printf("Não há produtos suficientes!");
            }
        }
    }
}

void reporEstoque(struct produto prods[], char name2[], int qnt2){
    int i;
    for(i = 0; i < contador; i++){
        if(strcmp(prods[i].nome, name2) == 0){
            prods[i].quantidade += qnt2;
        }
    }
}

void imprimirProdutos(struct produto prods[]) {
    printf("Produtos disponíveis:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d - Nome: %s\n", (i + 1), prods[i].nome);
        printf("Valor: %.2lf\n", prods[i].valor);
        printf("Quantidade: %d\n\n", prods[i].quantidade);
    }
}

