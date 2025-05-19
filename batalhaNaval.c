#include <stdio.h>

// --- Definições de Constantes Globais ---
#define TAMANHO_TABULEIRO 10 // Define a dimensão (linhas e colunas) do tabuleiro do jogo.
#define TAMANHO_NAVIO 3      // Define o comprimento padrão dos navios a serem posicionados.
#define AGUA 0               // Valor numérico que representa uma célula vazia (água) no tabuleiro.
#define NAVIO 3              // Valor numérico que representa uma célula ocupada por parte de um navio.

int main() {
    // --- 1. Declaração e Inicialização do Tabuleiro ---
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Matriz 10x10.

    printf("Inicializando o tabuleiro %dx%d com o valor AGUA (%d)...\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO, AGUA);

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) { // Loop para linhas.
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Loop para colunas.
            tabuleiro[i][j] = AGUA;                  // Atribui AGUA (0) à célula [i][j].
        }
    }
    printf("Tabuleiro inicializado com sucesso.\n\n");

    // --- 2. Definição e Posicionamento dos Navios ---
    // Navio 1: Posicionamento Horizontal
    int navio1_linha_inicial = 1;     // Linha (índice 1).
    int navio1_coluna_inicial = 1;    // Coluna (índice 1).

    printf("Posicionando Navio 1 (Horizontal, tamanho %d) na linha %d, coluna inicial %d...\n", TAMANHO_NAVIO, navio1_linha_inicial, navio1_coluna_inicial);
    for (int k = 0; k < TAMANHO_NAVIO; k++) { // Itera sobre cada parte do navio.
        if ((navio1_coluna_inicial + k) < TAMANHO_TABULEIRO) { // Verifica limite da coluna.
             tabuleiro[navio1_linha_inicial][navio1_coluna_inicial + k] = NAVIO; // Marca com NAVIO (3).
        } else {
            printf("Erro: Navio 1 (Horizontal) excederia os limites do tabuleiro na coluna %d.\n", navio1_coluna_inicial + k);
        }
    }

    // Navio 2: Posicionamento Vertical
    int navio2_linha_inicial = 3;     // Linha (índice 3).
    int navio2_coluna_inicial = 5;    // Coluna (índice 5).

    printf("Posicionando Navio 2 (Vertical, tamanho %d) na linha inicial %d, coluna %d...\n", TAMANHO_NAVIO, navio2_linha_inicial, navio2_coluna_inicial);
    for (int k = 0; k < TAMANHO_NAVIO; k++) { // Itera sobre cada parte do navio.
         if ((navio2_linha_inicial + k) < TAMANHO_TABULEIRO) { // Verifica limite da linha.
            tabuleiro[navio2_linha_inicial + k][navio2_coluna_inicial] = NAVIO; // Marca com NAVIO (3).
        } else {
            printf("Erro: Navio 2 (Vertical) excederia os limites do tabuleiro na linha %d.\n", navio2_linha_inicial + k);
        }
    }
    printf("Navios posicionados com sucesso.\n\n");

    // --- 3. Exibição do Tabuleiro no Console com Índices de Linha e Coluna ---
    printf("--- Tabuleiro Batalha Naval (%dx%d) ---\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO); // Título do tabuleiro.

    // Imprime os índices das colunas (0 a 9) no topo do tabuleiro.
    printf("   "); // Imprime três espaços para alinhar com os dados do tabuleiro (considerando o espaço para os índices das linhas).
                   // Se os índices das linhas forem de dois dígitos (ex: 10), ajuste este espaçamento.
    for (int col_idx = 0; col_idx < TAMANHO_TABULEIRO; col_idx++) { // Loop para iterar de 0 a 9 (índices de coluna).
        printf("%2d ", col_idx); // Imprime o índice da coluna. '%2d' formata para ocupar 2 espaços, alinhando números de 1 e 2 dígitos.
                                 // Adiciona um espaço após cada número para separação.
    }
    printf("\n"); // Pula para a próxima linha após imprimir todos os índices das colunas.

    // Imprime uma linha separadora abaixo dos índices das colunas (opcional, para estética).
    printf("   "); // Alinhamento.
    for (int k = 0; k < TAMANHO_TABULEIRO; k++) { // Loop para desenhar a linha.
        printf("---"); // Três traços por coluna (ajuste conforme o '%2d ' acima).
    }
    printf("\n"); // Nova linha.

    // Utiliza loops aninhados para percorrer e imprimir cada célula do tabuleiro, precedida pelo índice da linha.
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {     // Loop externo: itera sobre as linhas (índice 'i' de 0 a 9).
        printf("%2d|", i); // Imprime o índice da linha atual. '%2d' garante alinhamento para números de 1 e 2 dígitos.
                           // Seguido por uma barra vertical '|' para separar o índice dos dados do tabuleiro.
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Loop interno: itera sobre as colunas (índice 'j' de 0 a 9).
            printf("%2d ", tabuleiro[i][j]);          // Imprime o valor da célula [i][j] (0 para água, 3 para navio).
                                                      // '%2d ' formata para ocupar 2 espaços e adiciona um espaço para separação.
        }
        printf("\n"); // Imprime um caractere de nova linha ao final de cada linha do tabuleiro, para formatar a exibição.
    }
    printf("---------------------------------------\n"); // Linha decorativa final (ajuste o comprimento se necessário).
    printf("Legenda: %d = Agua, %d = Navio\n", AGUA, NAVIO); // Adiciona uma legenda para os valores.

    return 0; // Retorna 0 para o sistema operacional, indicando que o programa foi executado com sucesso.
}
