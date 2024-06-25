#include <stdio.h>
#include <string.h>

#define ROW 15
#define COL 15

void initializeGrid(char grid[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Enter a character for grid[%d][%d]: ", i, j);
            scanf(" %c", &grid[i][j]);
        }
    }
}

void printGrid(char grid[ROW][COL], int found[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (found[i][j] == 1) {
                printf("%c", grid[i][j]);
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    char grid[ROW][COL];
    char word[20];
    int found[ROW][COL] = {0}; // 0: Kelime bulunmadı, 1: Kelime bulundu

    initializeGrid(grid);

    printf("Enter a word to search: ");
    scanf("%s", word);

    int wordLen = strlen(word);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == word[0]) {
                // Check horizontally
                if (j + wordLen <= COL) {
                    int k;
                    for (k = 0; k < wordLen; k++) {
                        if (grid[i][j + k] != word[k]) {
                            break;
                        }
                    }
                    if (k == wordLen) {
                        for (k = 0; k < wordLen; k++) {
                            found[i][j + k] = 1;
                        }
                    }
                }

                // Check vertically
                if (i + wordLen <= ROW) {
                    int k;
                    for (k = 0; k < wordLen; k++) {
                        if (grid[i + k][j] != word[k]) {
                            break;
                        }
                    }
                    if (k == wordLen) {
                        for (k = 0; k < wordLen; k++) {
                            found[i + k][j] = 1;
                        }
                    }
                }
            }
        }
    }

    printf("Result:\n");
    printGrid(grid, found);

    return 0;
}
