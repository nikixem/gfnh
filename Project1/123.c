
#include <stdio.h>
#include <stdlib.h>
#define ROWS 20 // число строк 
#define COLS 20 // число столбцов 
#define ALIVE 'O' // символ для живой клетки
#define DEAD ' ' // символ для мертвой клетки
// проверка границ игрового поля
int isValidCell(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}
// функция для инициализации игрового поля
void initGameBoard(char gameBoard[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = DEAD;
        }
    }
}
// выводы игрового поля на экран
void printGameBoard(char gameBoard[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// обновление состояния клеток на основе правил игры "Жизнь"
void updateGameBoard(char gameBoard[][COLS]) {
    char newGameBoard[ROWS][COLS]; // временное поле для хранения нового состояния клетки
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int aliveNeighbors = 0;

            // проверяем всех клетки рядом с текущей
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) {
                        continue; // пропускаем текущую клетку
                    }

                    int neighborX = i + k;
                    int neighborY = j + l;

                    if (isValidCell(neighborX, neighborY) && gameBoard[neighborX][neighborY] == ALIVE) {
                        aliveNeighbors++;
                    }
                }
            }

            // обновляем клетки на основе правил игры
            if (gameBoard[i][j] == ALIVE) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGameBoard[i][j] = DEAD;  // мертвая клетка по причине недостатка или перенаселения
                }
                else {
                    newGameBoard[i][j] = ALIVE;  // живая
                }
            }
            else {
                if (aliveNeighbors == 3) {
                    newGameBoard[i][j] = ALIVE;  // новая калетка
                }
                else {
                    newGameBoard[i][j] = DEAD;  // мертвая клетка
                }
            }
        }
    }

    // копируем новые клетки в оригинальное поле
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = newGameBoard[i][j];
        }
    }

}
int main() {
    char gameBoard[ROWS][COLS];
    initGameBoard(gameBoard);

    // начальное состояние поля 
    gameBoard[1][1] = ALIVE;
    gameBoard[2][2] = ALIVE;
    gameBoard[2][3] = ALIVE;
    gameBoard[3][1] = ALIVE;
    gameBoard[3][2] = ALIVE;

    // цикл игры 
    while (1) {
        system("clear"); // очистка экрана
        printGameBoard(gameBoard);
        updateGameBoard(gameBoard);
    }

    return 0;

}