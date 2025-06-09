#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30], sabor[30], genero[30], bairro[30], nomeCL[30], rua[30];
    float valor;
    int quantidade, ano, id, idCL, ncasa;
} produto;

produto estoque[100]; 
produto clientes[100];
int numvenda = 0, numclientes = 0;

void cadastrarPizza();
void cadastrarCliente();
void listarProdutos();
void listarClientes();
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
        printf("\n**** MOSTRA PIaZZA ****\n");
        printf("1 - Cadastrar PIZZA\n");
        printf("2 - Cadastrar CLIENTE\n");
        printf("3 - LISTAR PIZZAS \n");
        printf("4 - LISTAR CLIENTES \n");
        printf("5 - Realizar compra \n");
        printf("0 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        system("clear");  

        switch (opcao) {
            case 1:
                cadastrarPizza();
                break;
            case 2:
                cadastrarCliente();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                listarClientes();
                break;
            case 5:
                realizarCompra();
                break;
            case 0:
                printf("Obrigado\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

        printf("Pressione Enter para continuar . . .");
        getchar(); 
        getchar();
        system("clear");

    } while (opcao != 0);

    return 0;
}

void cadastrarPizza() {
    printf(" -- CADASTRO DE PRODUTO -- \n");
    printf("Nome da pizza: ");
    scanf("%s", estoque[numvenda].nome);
    printf("Sabor da pizza: ");
    scanf("%s", estoque[numvenda].sabor);
    printf("Digite o valor do produto: ");
    scanf("%f", &estoque[numvenda].valor);
    printf("Digite um ID para o produto: ");
    scanf("%d", &estoque[numvenda].id);
    printf("Produto cadastrado com sucesso!\n");
    numvenda++;
}

void cadastrarCliente() {
    printf(" -- CADASTRO DE CLIENTE -- \n");
    printf("Nome do cliente: ");
    scanf("%s", clientes[numclientes].nomeCL);
    printf("Bairro: ");
    scanf("%s", clientes[numclientes].bairro);
    printf("Rua: ");
    scanf("%s", clientes[numclientes].rua);
    printf("Digite o numero da casa: ");
    scanf("%d", &clientes[numclientes].ncasa);
    printf("Digite um ID para o Cliente: ");
    scanf("%d", &clientes[numclientes].idCL);
    printf("Cliente cadastrado com sucesso!\n");
    numclientes++;
}

void listarProdutos() {
    printf(" --- Pizzas cadastradas ---\n");
    for (int i = 0; i < numvenda; i++) {
        printf("Nome da pizza: %s\n", estoque[i].nome);
        printf("Sabor da pizza: %s\n", estoque[i].sabor);
        printf("Valor: R$ %.2f\n", estoque[i].valor);
        printf("ID do produto: %d\n", estoque[i].id);
        printf("Quantidade em estoque: %d\n", estoque[i].quantidade);
    }
}

void listarClientes() {
    printf(" --- Clientes cadastrados ---\n");
    for (int i = 0; i < numclientes; i++) {
        printf("Nome do cliente: %s\n", clientes[i].nomeCL);
        printf("Bairro: %s\n", clientes[i].bairro);
        printf("Rua: %s\n", clientes[i].rua);
        printf("Numero da casa: %d\n", clientes[i].ncasa);
        printf("ID do cliente: %d\n", clientes[i].idCL);
        printf(" --- Clientes cadastrados ---\n");
    }
}

void realizarCompra() {
    int idP, quantidadeVenda, idcliente;
    printf("Digite o ID do cliente: ");
    scanf("%d", &idcliente);

    int clienteEncontrado = -1;
    for (int i = 0; i < numclientes; i++) {
        if (clientes[i].idCL == idcliente) {
            clienteEncontrado = i;
            break;
        }
    }

    if (clienteEncontrado == -1) {
        printf("Cliente com ID %d não encontrado. Por favor, cadastre-se primeiro.\n", idcliente);
        return;
    }

    printf("Digite o ID da pizza: ");
    scanf("%d", &idP);
    
    int pizzaEncontrada = -1;
    for(int i = 0; i < numvenda; i++) {
        if (estoque[i].id == idP) {
            pizzaEncontrada = i;
            break;
        }
    }
    
    if (pizzaEncontrada == -1) {
        printf("Pizza com ID %d não encontrada.\n", idP);
        return;
    }

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidadeVenda);

    if (quantidadeVenda > estoque[pizzaEncontrada].quantidade) {
        printf("Quantidade solicitada maior que o estoque disponível. Estoque atual: %d\n", estoque[pizzaEncontrada].quantidade);
    } else {
        estoque[pizzaEncontrada].quantidade -= quantidadeVenda;
        float valorTotal = quantidadeVenda * estoque[pizzaEncontrada].valor;
        printf("Venda realizada com sucesso! Valor total a ser pago: R$ %.2f\n", valorTotal);
    }
}


