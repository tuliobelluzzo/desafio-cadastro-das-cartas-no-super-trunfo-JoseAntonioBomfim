#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char pais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para calcular densidade
void calcularDensidade(struct Carta *carta) {
    carta->densidadeDemografica = carta->area > 0 ? carta->populacao / carta->area : 0;
}

// Função para exibir uma carta
void exibirCarta(struct Carta c) {
    printf("País: %s\n", c.pais);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões R$\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade demográfica: %.2f hab/km²\n", c.densidadeDemografica);
    printf("\n");
}

// Função para obter valor numérico do atributo
float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Nome do atributo para exibição
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade demográfica";
        default: return "Desconhecido";
    }
}

// Compara um único atributo (com exceção para densidade)
int compararAtributo(float v1, float v2, int atributo) {
    if (atributo == 5) {
        return (v1 < v2) ? 1 : (v1 > v2) ? 2 : 0;
    } else {
        return (v1 > v2) ? 1 : (v1 < v2) ? 2 : 0;
    }
}

int main() {
    // Duas cartas cadastradas
    struct Carta carta1 = {"Brasil", 213000000, 8515770, 18700.5, 25, 0};
    struct Carta carta2 = {"Argentina", 45380000, 2780400, 4880.2, 18, 0};

    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int opcao1 = 0, opcao2 = 0;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n\n");

    // Exibe as cartas
    printf("Carta 1:\n"); exibirCarta(carta1);
    printf("Carta 2:\n"); exibirCarta(carta2);

    // MENU - escolha do primeiro atributo
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade demográfica (menor vence)\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Validação
    if (opcao1 < 1 || opcao1 > 5) {
        printf("Atributo inválido. Encerrando.\n");
        return 1;
    }

    // MENU - escolha do segundo atributo (removendo o primeiro)
    printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1)
            printf("%d - %s\n", i, nomeAtributo(i));
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
        printf("Atributo inválido ou repetido. Encerrando.\n");
        return 1;
    }

    // Comparações individuais
    float v1_a1 = obterValor(carta1, opcao1);
    float v2_a1 = obterValor(carta2, opcao1);
    float v1_a2 = obterValor(carta1, opcao2);
    float v2_a2 = obterValor(carta2, opcao2);

    printf("\n=== COMPARAÇÃO DOS ATRIBUTOS ===\n");
    printf("Atributo 1: %s\n", nomeAtributo(opcao1));
    printf("%s: %.2f\n", carta1.pais, v1_a1);
    printf("%s: %.2f\n", carta2.pais, v2_a1);

    printf("\nAtributo 2: %s\n", nomeAtributo(opcao2));
    printf("%s: %.2f\n", carta1.pais, v1_a2);
    printf("%s: %.2f\n", carta2.pais, v2_a2);

    // Soma dos valores
    float soma1 = v1_a1 + v1_a2;
    float soma2 = v2_a1 + v2_a2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.pais, soma1);
    printf("%s: %.2f\n", carta2.pais, soma2);

    // Resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    if (soma1 > soma2) {
        printf("Vencedor: %s\n", carta1.pais);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s\n", carta2.pais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
