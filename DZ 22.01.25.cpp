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

int main() {
    const int count = 7;
    Figure randomFigures[count];
    generateRandomFigures(randomFigures, count);


    for (int i = 0; i < count; ++i) {
        printFigure(randomFigures[i]);
    }

    return 0;
}




