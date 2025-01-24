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
    for (int j = 0; j < 4; j++) {
        if (figure.field[3][j] == 1) {
            canMove = false;
        }
    }
    if (canMove) {

        for (int i = 3; i > 0; --i) {
            for (int j = 0; j < 4; ++j) {
                figure.field[i][j] = figure.field[i - 1][j];
            }
        }
        for (int j = 0; j < 4; j++) {
            figure.field[0][j] = 0;
        }
        return true;
    }
    else {
        return false;
    }
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












int main() {
    setlocale(LC_ALL, "Russian");
    Figure allFigures[7];
    createFigures(allFigures);

    const int count = 4;
    for (int i = 0; i < count; ++i) {
        Figure currentFigure = allFigures[i % 7]; 

        cout << "Начальная фигура: " << endl;
        printFigure(currentFigure);

        for (int k = 0; k < 3; k++) {
            if (Down(currentFigure)) {
                cout << "Фигура после сдвига вниз: " << endl;
                printFigure(currentFigure);
            }
            else {
                cout << "Нельзя сдвинуть фигуру" << endl;
                break;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        Figure currentFigure = allFigures[i % 7];

        cout << "Начальная фигура: " << endl;
        printFigure(currentFigure);

        cout << "Фигура после поворота на 90 градусов: " << endl;
        Rotate(currentFigure);
        printFigure(currentFigure);
    }
    
    
    return 0;
}
