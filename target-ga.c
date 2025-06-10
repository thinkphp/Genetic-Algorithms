#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TARGET "Hello, world!"
#define POP_SIZE 200
#define MUTATION_RATE 0.01
#define CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,.!? "
#define INTERVAL_USEC 50000

const int geneLength = sizeof(TARGET) - 1;

char randomChar() {
    return CHARSET[rand() % strlen(CHARSET)];
}

void randomGene(char *gene) {
    for (int i = 0; i < geneLength; i++)
        gene[i] = randomChar();
    gene[geneLength] = '\0';
}

double fitness(const char *gene) {
    int score = 0;
    for (int i = 0; i < geneLength; i++) {
        if (gene[i] == TARGET[i]) score++;
    }
    return (double)score / geneLength;
}

void mutate(char *gene) {
    for (int i = 0; i < geneLength; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            gene[i] = randomChar();
        }
    }
}

void crossover(const char *a, const char *b, char *child) {
    int midpoint = rand() % geneLength;
    for (int i = 0; i < geneLength; i++) {
        child[i] = i < midpoint ? a[i] : b[i];
    }
    child[geneLength] = '\0';
    mutate(child);
}

int compare(const void *a, const void *b) {
    double fa = ((double *)a)[0];
    double fb = ((double *)b)[0];
    return fb > fa ? 1 : -1;
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    srand(time(NULL));

    char population[POP_SIZE][geneLength + 1];
    double fitnessScores[POP_SIZE];
    int generation = 0;

    for (int i = 0; i < POP_SIZE; i++)
        randomGene(population[i]);

    while (1) {
        generation++;

        // Evaluate fitness
        for (int i = 0; i < POP_SIZE; i++)
            fitnessScores[i] = fitness(population[i]);

        // Find best
        int bestIdx = 0;
        for (int i = 1; i < POP_SIZE; i++) {
            if (fitnessScores[i] > fitnessScores[bestIdx])
                bestIdx = i;
        }

        // Display
        clear();
        mvprintw(1, 2, "Target: %s", TARGET);
        mvprintw(2, 2, "Generation: %d", generation);
        mvprintw(3, 2, "Best Match: %s", population[bestIdx]);
        mvprintw(4, 2, "Fitness: %.2f%%", fitnessScores[bestIdx] * 100);
        refresh();

        if (strcmp(population[bestIdx], TARGET) == 0) {
            break;
        }

        // Selection (top 20%)
        int parentsCount = POP_SIZE * 0.2;
        int indices[POP_SIZE];
        for (int i = 0; i < POP_SIZE; i++) indices[i] = i;
        for (int i = 0; i < POP_SIZE - 1; i++) {
            for (int j = i + 1; j < POP_SIZE; j++) {
                if (fitnessScores[indices[j]] > fitnessScores[indices[i]]) {
                    int tmp = indices[i];
                    indices[i] = indices[j];
                    indices[j] = tmp;
                }
            }
        }

        // Reproduce
        char newPopulation[POP_SIZE][geneLength + 1];
        for (int i = 0; i < POP_SIZE; i++) {
            char *a = population[indices[rand() % parentsCount]];
            char *b = population[indices[rand() % parentsCount]];
            crossover(a, b, newPopulation[i]);
        }

        memcpy(population, newPopulation, sizeof(population));

        usleep(INTERVAL_USEC);
    }

    mvprintw(6, 2, "Target reached in %d generations! Press any key to exit...", generation);
    refresh();
    getch();
    endwin();
    return 0;
}
