#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30], banda[30], genero[30];
    float valor;
    int quantidade, ano, id;
} produto;

produto estoque[100];
int numvenda = 0;

void cadastrarProduto();
void visualizarProduto();
void realizarCompra();
void pesquisarPorGenero();

int main() {
    int opcao;
    int contador = 0;
    
    for (int i = 0; i < 1000; i++) {
        if (contador == 8) contador = 0;
        printf("\033[3%dm%d ", contador, i);
        contador++;
    }

    do {
        printf("\n**** Som e arte ****\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Visualizar Produto\n");
        printf("3 - Realizar Compra\n");
        printf("4 - Pesquisar Por Genero \n");
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
            case 4:
            pesquisarPorGenero();
            break;
            case 0:
                printf("Obrigado\n");
                break;
            default:
                printf("Opção invalida\n");
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
    scanf("%s", estoque[numvenda].banda);
    printf("Valor do produto: ");
    scanf("%s", estoque[numvenda].genero);
    printf("Quantidade em estoque: ");
    scanf("%d", &estoque[numvenda].quantidade);
    printf("Digite o ano do produto: ");
    scanf("%d", &estoque[numvenda].ano);
    printf("Digite o valor do produto: ");
    scanf("%f", &estoque[numvenda].valor);
     printf("Digite um ID para o produto: ");
    scanf("%d", &estoque[numvenda].id);
    printf("Produto cadastrado com sucesso!\n");
    numvenda++;
}

void visualizarProduto() {
    printf(" --- Informações dos Produtos ---\n");
    for (int i = 0; i < numvenda; i++) {
        printf("Nome: %s\n", estoque[i].nome);
        printf("Banda: %s\n", estoque[i].banda);
        printf("Valor: R$ %.2f\n", estoque[i].valor);
        printf("Quantidade em estoque: %d\n", estoque[i].quantidade);
        printf("id do podruto: %d\n", estoque[i].id);
        printf("ano do produto: %d\n\n", estoque[i].ano);
        printf("genero do produto: %s\n\n", estoque[i].genero);
    }
}

void realizarCompra() {
    int idCD, quantidadeVenda;
    printf("Digite o ID do CD a ser vendido: ");
    scanf("%d", &idCD);

    int cdEncontrado = -1;
    for (int i = 0; i < numvenda; i++) {
        if (estoque[i].id == idCD) {
            cdEncontrado = i;
            break;
        }
    }

    if (cdEncontrado == -1) {
        printf("CD com ID %d não encontrado.\n", idCD);
        return;
    }

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidadeVenda);

    if (quantidadeVenda > estoque[cdEncontrado].quantidade) {
        printf("Quantidade solicitada maior que o estoque disponivel. Estoque atual: %d\n", estoque[cdEncontrado].quantidade);
    } else {
        estoque[cdEncontrado].quantidade -= quantidadeVenda;
        float valorTotal = quantidadeVenda * estoque[cdEncontrado].valor;
        printf("Venda realizada com sucesso! Quantidade restante no estoque: %d\n", estoque[cdEncontrado].quantidade);
        printf("Valor total pago: R$ %.2f\n", valorTotal);
    }
}
void pesquisarPorGenero() {
    char generoPesquisa[30];
    printf("Digite o genero musical para pesquisar: ");
    scanf("%s", generoPesquisa);

    printf("\nCDs encontrados no genero %s:\n", generoPesquisa);
    for (int i = 0; i < numvenda; i++){
        if (strcmp(estoque[i].genero, generoPesquisa ) == 0){
            printf("Banda: %s \n Ano: %d \n Valor: R$ %.2f \n Estoque: %d \n ID: %d\n",estoque[i].banda, estoque[i].ano, estoque[i].valor, estoque[i].quantidade, estoque[i].id);
                   
        }
    }
}


//USEI STRCMP PARA COMPARA NO E GPT ROBSO JURO PRA VC