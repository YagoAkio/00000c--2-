#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FOUNDATION_SIZE 4
#define TABLEAU_SIZE 7
#define DECK_SIZE 52

// Defini��o de uma carta
typedef struct {
    char suit;
    char rank;
} Card;

// Defini��o de uma pilha
typedef struct {
    Card cards[DECK_SIZE];
    int top;
} Stack;

// Inicializa uma pilha vazia
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Adiciona uma carta � pilha
void push(Stack *stack, Card card) {
    stack->cards[++stack->top] = card;
}

// Remove e retorna a carta do topo da pilha
Card pop(Stack *stack) {
    return stack->cards[stack->top--];
}

// Embaralha as cartas no baralho
void shuffle(Card *deck, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Inicializa o baralho com cartas
void initializeDeck(Card *deck) {
    char suits[] = {'C', 'D', 'H', 'S'};
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

    int index = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            deck[index].suit = suits[suit];
            deck[index].rank = ranks[rank];
            index++;
        }
    }
}

// Distribui cartas iniciais para o tableau
void dealTableau(Card *deck, Stack *tableau) {
    int tableauSize = TABLEAU_SIZE;

    for (int i = 0; i < tableauSize; i++) {
        for (int j = i; j < tableauSize; j++) {
            push(&tableau[j], deck[i * tableauSize + j]);
        }
        tableau[i].top = tableauSize - 1;
    }
}

void displayTableau(Stack tableau[TABLEAU_SIZE]) {
    for (int i = 0; i < TABLEAU_SIZE; i++) {
        printf("Tableau %d: ", i + 1);
        for (int j = 0; j <= tableau[i].top; j++) {
            printf("%c%c ", tableau[i].cards[j].rank, tableau[i].cards[j].suit);
        }
        printf("\n");
    }
    printf("\n");
}

// Move uma carta do tableau para a foundation
void moveCard(Stack *source, Stack *destination) {
    if (source->top >= 0) {
        Card card = pop(source);
        push(destination, card);
    } else {
        printf("Fonte vazia. Movimento inv�lido.\n");
    }
}

// Fun��o principal do jogo
int main() {
    Card deck[DECK_SIZE];
    Stack tableau[TABLEAU_SIZE];
    Stack foundation[FOUNDATION_SIZE];

    initializeDeck(deck);
    shuffle(deck, DECK_SIZE);

    for (int i = 0; i < TABLEAU_SIZE; i++) {
        initializeStack(&tableau[i]);
    }

    for (int i = 0; i < FOUNDATION_SIZE; i++) {
        initializeStack(&foundation[i]);
    }

    dealTableau(deck, tableau);

    int sourceTableau, destTableau;

    while (1) {
        // Exibe o estado atual do jogo
        displayTableau(tableau);

        // Solicita ao jogador um movimento
        printf("Digite o n�mero da pilha de origem (1 a 7) e o n�mero da pilha de destino (1 a 4): ");
        scanf("%d %d", &sourceTableau, &destTableau);

        // Converte para �ndices de array
        sourceTableau--;
        destTableau--;

        // Verifica se os �ndices s�o v�lidos
        if (sourceTableau >= 0 && sourceTableau < TABLEAU_SIZE && destTableau >= 0 && destTableau < FOUNDATION_SIZE) {
            // Realiza o movimento
            moveCard(&tableau[sourceTableau], &foundation[destTableau]);
        } else {
            printf("�ndices inv�lidos. Tente novamente.\n");
        }
    }

    return 0;
}
