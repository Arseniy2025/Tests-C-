#include <iostream>
using namespace std;

struct Figure {
    int id;
    int field[4][4];
};


void createFigures(Figure figures[7]) {

    figures[0].id = 0;
    int field_I[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            figures[0].field[i][j] = field_I[i][j];
        }
    }


    figures[1].id = 1;
    int field_J[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            figures[1].field[i][j] = field_J[i][j];
        }
    }


    figures[2].id = 2;
    int field_L[4][4] = {
       {0, 0, 1, 0},
       {1, 1, 1, 0},
       {0, 0, 0, 0},
       {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            figures[2].field[i][j] = field_L[i][j];
        }
    }

    figures[3].id = 3;
    int field_O[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            figures[3].field[i][j] = field_O[i][j];
        }
    }


    figures[4].id = 4;
    int field_S[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            figures[4].field[i][j] = field_S[i][j];
        }
    }

    figures[5].id = 5;
    int field_T[4][4] = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            figures[5].field[i][j] = field_T[i][j];
        }
    }

    figures[6].id = 6;
    int field_Z[4][4] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            figures[6].field[i][j] = field_Z[i][j];
        }
    }
}

static unsigned int seed = 12345; 
unsigned int myRand() {
    seed = (1103515245 * seed + 12345);
    return seed;
}

void generateRandomFigures(Figure randomFigures[], int count) {
    Figure allFigures[7];
    createFigures(allFigures);

    for (int i = 0; i < count; ++i) {
        int randomIndex = myRand() % 7;
        randomFigures[i] = allFigures[randomIndex];
    }
}

void printFigure( Figure& figure) {
    cout << "Figure ID: " << figure.id << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << figure.field[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Down(Figure& figure) {

    bool canMove = true;

    for (int row = 3; row > 0; --row) {
        for (int col = 0; col < 4; ++col) {
            if (figure.field[row][col] == 1 && figure.field[row - 1][col] == 1) {
                continue;
            }
            else if (figure.field[row][col] == 1 && figure.field[row - 1][col] == 0 && row > 0)
            {

                continue;

            }
            else if (figure.field[row][col] == 1 && row == 0)
            {
                canMove = false;
                break;
            }
        }
        if (!canMove)
            break;
    }
    if (canMove) {
        for (int row = 3; row > 0; --row) {
            for (int col = 0; col < 4; ++col) {
                if (figure.field[row - 1][col] == 1 && figure.field[row][col] == 0) {
                    figure.field[row][col] = 1;
                    figure.field[row - 1][col] = 0;
                }
            }
        }
    }

    return canMove;
}


void Rotate(Figure& figure) {
    int coordinate[16][2];
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (figure.field[i][j] == 1) {
                coordinate[count][0] = i;
                coordinate[count][1] = j;
                count++;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            figure.field[i][j] = 0;
        }
    }

    for (int k = 0; k < count; ++k) {
        int newR = coordinate[k][1];
        int newC = 3 - coordinate[k][0];
        if (newR >= 0 && newR < 4 && newC >= 0 && newC < 4) {
            figure.field[newR][newC] = 1;
        }
    }
}

void mFigures(int board[20][10], Figure& figure, int row, int col) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (figure.field[i][j] == 1) {
                int boardRow = row + i;
                int boardCol = col + j;
                if (boardRow >= 0 && boardRow < 20 && boardCol >= 0 && boardCol < 10)
                    board[boardRow][boardCol] = 1;
            }
        }
    }
}

void printBoard(int board[20][10]) {
    cout << "Текущая доска: " << endl;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Figure allFigures[7];
    createFigures(allFigures);
    int gameBoard[20][10] = { 0 };
    const int count = 4;
    for (int i = 0; i < count; ++i) {
        Figure currentFigure = allFigures[i % 7];
        int row = 0;
        int col = 3;

        cout << "Начальная фигура:" << endl;
        printFigure(currentFigure);

        cout << "Фигура после поворота:" << endl;
        Rotate(currentFigure);
        printFigure(currentFigure);

        for (int k = 0; k < 3; k++) {
            if (Down(currentFigure)) {
                cout << "Фигура после сдвига вниз:" << endl;
                printFigure(currentFigure);
                
            }
            else {
                cout << "Нельзя сдвинуть фигуру" << endl;
                break;
            }
        }
        mFigures(gameBoard, currentFigure, row, col);
        cout << "Игровое поле после слияния: " << endl;
        printBoard(gameBoard);
    }
    return 0;
}








/*int main() {
    const int count = 5;
    Figure randomFigures[count];
    generateRandomFigures(randomFigures, count);


    for (int i = 0; i < count; ++i) {
        printFigure(randomFigures[i]);
    }

    return 0;
}
*/
