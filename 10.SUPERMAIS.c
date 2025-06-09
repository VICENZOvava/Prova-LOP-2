#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30], categoria[30];
    float valor;
    int quantidade, id;
} produto;

produto estoque[100];
int numvenda = 0;

void cadastrarProduto();
void visualizarProduto();
void realizarCompra();

int main() {
    int opcao;
    int contador = 0;
    
    for (int i = 0; i < 1000; i++) {
        if (contador == 8) contador = 0;
        printf("\033[3%dm%d ", contador, i);
        contador++;
    }

    do {
        printf("\n**** SUPERMERCADO SUPREMAIS ****\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Visualizar Produto\n");
        printf("3 - Realizar Compra\n");
        printf("0 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        system("clear");  

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarProduto();
                break;
            case 3:
                realizarCompra();
                break;
            case 0:
                printf("Obrigado\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

        printf("Pressione Enter para continuar . . .");
        getchar(); 
        getchar();
        system("clear");

    } while (opcao != 0);

    return 0;
}

void cadastrarProduto() {
    printf(" -- CADASTRO DE PRODUTO -- \n");
    printf("Nome do produto: ");
    scanf("%s", estoque[numvenda].nome);
    printf("Categoria do produto: ");
    scanf("%s", estoque[numvenda].categoria);
    printf("Valor do produto: ");
    scanf("%f", &estoque[numvenda].valor);
    printf("Quantidade em estoque: ");
    scanf("%d", &estoque[numvenda].quantidade);
    printf("Digite um ID para o produto: ");
    scanf("%d", &estoque[numvenda].id);
    printf("Produto cadastrado com sucesso!\n");
    numvenda++;
}

void visualizarProduto() {
    printf(" --- Informações dos Produtos ---\n");
    for (int i = 0; i < numvenda; i++) {
        printf("Nome: %s\n", estoque[i].nome);
        printf("Categoria: %s\n", estoque[i].categoria);
        printf("Valor: R$ %.2f\n", estoque[i].valor);
        printf("Quantidade em estoque: %d\n", estoque[i].quantidade);
        printf("ID do produto: %d\n\n", estoque[i].id);
    }
}

void realizarCompra() {
    int idProduto, quantidadeCompra;
    printf("Digite o ID do produto a ser comprado: ");
    scanf("%d", &idProduto);

    int produtoEncontrado = -1;
    for (int i = 0; i < numvenda; i++) {
        if (estoque[i].id == idProduto) {
            produtoEncontrado = i;
            break;
        }
    }

    if (produtoEncontrado == -1) {
        printf("Produto com o ID %d não encontrado.\n", idProduto);
        return;
    }

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra > estoque[produtoEncontrado].quantidade) {
        printf("Quantidade solicitada maior que o estoque disponível. Estoque atual: %d\n", estoque[produtoEncontrado].quantidade);
    } else {
        estoque[produtoEncontrado].quantidade -= quantidadeCompra;
        printf("Compra realizada com sucesso! Quantidade restante no estoque: %d\n", estoque[produtoEncontrado].quantidade);
    }
}
