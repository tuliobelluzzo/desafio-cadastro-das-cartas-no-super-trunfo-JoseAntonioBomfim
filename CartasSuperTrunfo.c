#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Variáveis globais para armazenar os dados
typedef struct {
    char estado[3];
    char codigoCarta[3];
    char nomeCidade[30];
    double populacao;
    double areaKm;
    double pib;
    int pontosTuristicos;
    double densidadeDemografica;
    double pibPercapita;
} dadosCidade;

dadosCidade cidade[2];

// Função para cálculo da densidade demográfica
double calculaDensidadeDemografica(double populacao, double areaKm) {
    return populacao / areaKm;
}

// Função para cálculo do PIB per capita
double calculoPibPercapita(double pib, double populacao) {
    return pib / populacao;
}

int main() {
    setlocale(LC_ALL, "portuguese");

    // Entrada dos dados
    for (int i = 0; i < 2; i++) {
        printf("\nCódigo do Estado: ");
        scanf("%2s", cidade[i].codigoCarta);
        
        printf("Estado: ");
        scanf("%2s", cidade[i].estado);
        
        printf("Cidade: ");
        scanf("%29s", cidade[i].nomeCidade); // %29s para limitar o tamanho
        
        printf("Insira População: ");
        scanf("%lf", &cidade[i].populacao);

        printf("Insira Área em Km²: ");
        scanf("%lf", &cidade[i].areaKm);

        printf("Insira o PIB em mil: ");
        scanf("%lf", &cidade[i].pib);

        printf("Insira Quantidade de Pontos Turísticos: ");
        scanf("%d", &cidade[i].pontosTuristicos);
    }

    // Cálculo da densidade demográfica e PIB per capita
    for (int i = 0; i < 2; i++) {
        cidade[i].densidadeDemografica = calculaDensidadeDemografica(cidade[i].populacao, cidade[i].areaKm);
        cidade[i].pibPercapita = calculoPibPercapita(cidade[i].pib, cidade[i].populacao);
    }

    // Exibir os dados com densidade demográfica e PIB per capita
    for (int i = 0; i < 2; i++) {
        printf("\n==================================");
        printf("\nCódigo Carta: %s", cidade[i].codigoCarta);
        printf("\nEstado: %s", cidade[i].estado);
        printf("\nCidade: %s", cidade[i].nomeCidade);
        printf("\nPopulação: %.2lf", cidade[i].populacao);
        printf("\nÁrea em Km²: %.2lf", cidade[i].areaKm);
        printf("\nPIB em mil: %.2lf", cidade[i].pib);
        printf("\nQuantidade de Pontos Turísticos: %d", cidade[i].pontosTuristicos);
        printf("\nDensidade Demográfica: %.2lf", cidade[i].densidadeDemografica);
        printf("\nPIB per Capita: %.2lf", cidade[i].pibPercapita);
        printf("\n==================================\n");
    }

    return 0;
}
