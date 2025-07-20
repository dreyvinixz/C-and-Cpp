#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Produto
struct Produto {
    char nome[30];
    int codigo;
    double preco;
};

// Definição do nó da lista
typedef struct node {
    struct Produto produto;
    struct node* next;
} Node;

// Função para criar um novo nó
Node* criar_no(struct Produto p) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    novo->produto = p;
    novo->next = NULL;
    return novo;
}

// Adiciona um produto ao final da lista
Node* adicionar_produto(Node* head) {
    struct Produto p;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite o codigo do produto: ");
    scanf("%d", &p.codigo);
    printf("Digite o preco do produto: ");
    scanf("%lf", &p.preco);

    Node* novo = criar_no(p);

    if (head == NULL) {
        return novo;
    } else {
        Node* atual = head;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novo;
        return head;
    }
}

// Exibe todos os produtos na lista
void exibir_lista(Node* head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Node* atual = head;
    while (atual != NULL) {
        printf("\nNome: %s\nCodigo: %d\nPreco: R$ %.2f\n", atual->produto.nome, atual->produto.codigo, atual->produto.preco);
        atual = atual->next;
    }
}

// Busca um produto pelo nome
void buscar_por_nome(Node* head, const char* nome) {
    Node* atual = head;
    int encontrado = 0;
    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
            printf("\nProduto encontrado:\nNome: %s\nCodigo: %d\nPreco: R$ %.2f\n", atual->produto.nome, atual->produto.codigo, atual->produto.preco);
            encontrado = 1;
            break;
        }
        atual = atual->next;
    }
    if (!encontrado) {
        printf("Produto com nome '%s' nao encontrado.\n", nome);
    }
}

// Libera a memória da lista
void liberar_lista(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->next;
        free(temp);
    }
}

// Função principal com menu
int main() {
    Node* lista = NULL;
    int opcao;
    char nome_busca[30];

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Exibir todos os produtos\n");
        printf("3 - Buscar produto por nome\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lista = adicionar_produto(lista);
                break;
            case 2:
                exibir_lista(lista);
                break;
            case 3:
                printf("Digite o nome do produto a buscar: ");
                scanf(" %[^\n]", nome_busca);
                buscar_por_nome(lista, nome_busca);
                break;
            case 4:
                liberar_lista(lista);
                printf("Saindo e liberando memoria...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
