#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

void cadastrar_carta(Carta *c) {
    printf("Digite o estado: ");
    scanf("%s", c->estado);
    printf("Digite o codigo da carta: ");
    scanf("%d", &c->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", c->nome);
    printf("Digite a populacao: ");
    scanf("%d", &c->populacao);
    printf("Digite a area: ");
    scanf("%f", &c->area);
    printf("Digite o PIB: ");
    scanf("%f", &c->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &c->pontos_turisticos);
}

void exibir_carta(Carta c) {
    printf("\nEstado: %s\n", c.estado);
    printf("Codigo: %d\n", c.codigo);
    printf("Nome: %s\n", c.nome);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
}

int main() {
    Carta c1, c2;
    int opcao;

    printf("Cadastro da primeira carta:\n");
    cadastrar_carta(&c1);

    printf("\nCadastro da segunda carta:\n");
    cadastrar_carta(&c2);

    printf("\nEscolha a propriedade para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    scanf("%d", &opcao);

    printf("\nPropriedades da primeira carta:\n");
    exibir_carta(c1);

    printf("\nPropriedades da segunda carta:\n");
    exibir_carta(c2);

    switch (opcao) {
        case 1:
            if (c1.populacao > c2.populacao)
                printf("\nA primeira carta venceu na populacao.\n");
            else
                printf("\nA segunda carta venceu na populacao.\n");
            break;
        case 2:
            if (c1.area > c2.area)
                printf("\nA primeira carta venceu na area.\n");
            else
                printf("\nA segunda carta venceu na area.\n");
            break;
        case 3:
            if (c1.pib > c2.pib)
                printf("\nA primeira carta venceu no PIB.\n");
            else
                printf("\nA segunda carta venceu no PIB.\n");
            break;
        case 4:
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf("\nA primeira carta venceu no numero de pontos turisticos.\n");
            else
                printf("\nA segunda carta venceu no numero de pontos turisticos.\n");
            break;
        case 5: {
            float densidade1 = c1.populacao / c1.area;
            float densidade2 = c2.populacao / c2.area;
            if (densidade1 < densidade2)
                printf("\nA primeira carta venceu na densidade populacional.\n");
            else
                printf("\nA segunda carta venceu na densidade populacional.\n");
            break;
        }
        default:
            printf("\nOpcao invalida.\n");
    }

    return 0;
}

