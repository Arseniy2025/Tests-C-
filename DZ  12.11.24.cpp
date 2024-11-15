#include <iostream>
using namespace std;


int** transponMatrix(int** matrix, int size_X, int size_Y) {
    
    int** transposedMatrix = new int*[size_Y];
    
    for (int i = 0; i < size_Y; i++) {
        transposedMatrix[i] = new int[size_X];
    }

    
    for (int i = 0; i < size_X; i++) {
        for (int j = 0; j < size_Y; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}


void printMatrix(int** matrix, int size_X, int size_Y) {
    for (int i = 0; i < size_X; i++) {
        for (int j = 0; j < size_Y; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int** getRandomMatrix(int size_X, int size_Y) {
    int** matrix = new int*[size_X];

    for (int i = 0; i < size_X; i++) {
        matrix[i] = new int[size_Y];

        for (int j = 0; j < size_Y; j++) {
            matrix[i][j] = rand() % 9 + 1;  
        }
    }

    return matrix;
}


void freeMatrix(int** matrix, int size_X) {
    for (int i = 0; i < size_X; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size_X = 5;
    int size_Y = 5;
    int** matrix = getRandomMatrix(size_X, size_Y);
    
    cout << "Оригинальная матрица:" << endl;
    printMatrix(matrix, size_X, size_Y);
    
    int** transposedMatrix = transponMatrix(matrix, size_X, size_Y);
    
    cout << "Транспортированная матрица:" << endl;
    printMatrix(transposedMatrix, size_Y, size_X);
    
   
    freeMatrix(matrix, size_X);
    freeMatrix(transposedMatrix, size_Y);
    
    return 0;
}
