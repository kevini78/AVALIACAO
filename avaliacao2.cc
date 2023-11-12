#include <stdio.h>

// Função para validar o sexo (M ou F)
char validaSexo() {
    char sexo;
    do {
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &sexo);

        if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f') {
            return sexo;
        } else {
            printf("Sexo inválido. Digite M para masculino ou F para feminino.\n");
        }
    } while (1);
}

// Função para validar o salário (deve ser maior que R$1,00)
float validaSalario() {
    float salario;
    do {
        printf("Informe o salário: R$ ");
        scanf("%f", &salario);

        if (salario <= 1.0) {
            printf("Salário inválido. Digite um valor maior que R$1,00.\n");
        } else {
            return salario;
        }
    } while (1);
}

// Sub-algoritmo para classificar o salário em relação ao salário mínimo
char classificaSalario(float salario, float salarioMinimo) {
    if (salario > salarioMinimo) {
        return 'A'; // Acima
    } else if (salario == salarioMinimo) {
        return 'I'; // Igual
    } else {
        return 'B'; // Abaixo
    }
}

// Sub-algoritmo para mostrar os resultados finais para cada assalariado
void mostraClassificacao(float salario, char sexo, char classificacao) {
    printf("Salário: R$ %.2f\n", salario);

    printf("Classificação em relação ao salário mínimo: ");
    switch (classificacao) {
        case 'A':
            printf("Acima\n");
            break;
        case 'I':
            printf("Igual\n");
            break;
        case 'B':
            printf("Abaixo\n");
            break;
    }

    printf("Sexo: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
    printf("--------------------------------------\n");
}

int main() {
    const float salarioMinimo = 1400.0;
    int quantidadeAbaixo = 0, quantidadeAcima = 0;

    int totalAssalariados;
    printf("Informe o número total de assalariados: ");
    scanf("%d", &totalAssalariados);

    for (int i = 0; i < totalAssalariados; ++i) {
        char sexo = validaSexo();
        float salario = validaSalario();
        char classificacao = classificaSalario(salario, salarioMinimo);

        mostraClassificacao(salario, sexo, classificacao);

        if (classificacao == 'B') {
            quantidadeAbaixo++;
        } else if (classificacao == 'A') {
            quantidadeAcima++;
        }
    }

    printf("--------------------------------------\n");
    printf("Quantidade de assalariados abaixo do salário mínimo: %d\n", quantidadeAbaixo);
    printf("Quantidade de assalariados acima do salário mínimo: %d\n", quantidadeAcima);

    return 0;
}