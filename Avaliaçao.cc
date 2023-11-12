#include <stdio.h>


int validaQuantidade() {
    int quantidade;
    while (1) {
        printf("Informe a quantidade de peças fabricadas: ");
        if (scanf("%d", &quantidade) != 1 || quantidade < 0) {
            while (getchar() != '\n'); 
            printf("Quantidade inválida. Digite um número não negativo.\n");
        } else {
            return quantidade;
        }
    }
}

float calculaSalario(int quantidade) {
    const float salarioBase = 600.0;
    float adicional = 0.0;

    if (quantidade > 50) {
        adicional += 0.50 * (quantidade - 50);
    }

    if (quantidade > 80) {
        adicional += 0.75 * (quantidade - 80);
    }

    return salarioBase + adicional;
}

void mostraFinal(const char* nome, float salario) {
    printf("O funcionário %s receberá um salário de R$ %.2f.\n", nome, salario);
}

int main() {
    int numeroFuncionarios;

    printf("Informe o número de funcionários: ");
    scanf("%d", &numeroFuncionarios);

    for (int i = 0; i < numeroFuncionarios; ++i) {
        char nome[50];
        printf("Informe o nome do funcionário %d: ", i + 1);
        scanf("%s", nome);

        int quantidade = validaQuantidade();
        float salario = calculaSalario(quantidade);

        mostraFinal(nome, salario);
    }

    return 0;
}