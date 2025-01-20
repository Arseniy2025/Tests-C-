#include <iostream>
using namespace std;

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int** createMatrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}


void deleteMatrix(int** matrix, int n) {
    if (matrix) {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

int** rotate90(int** matrix, int n) {
    int** rotated = createMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}



int** rotate180(int** matrix, int n) {
    int** rotated = createMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[n - 1 - i][n - 1 - j] = matrix[i][j];
        }
    }
    return rotated;
}


int** rotate270(int** matrix, int n) {
    int** rotated = createMatrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[n - 1 - j][i] = matrix[i][j];
        }
    }
    return rotated;
}

int** rotateMatrix(int** matrix, int n, int degrees) {
    if (degrees % 360 == 0) {
        return matrix; 
    }
    else if (degrees % 360 == 90) {
        return rotate90(matrix, n);
    }
    else if (degrees % 360 == 180) {
        return rotate180(matrix, n);
    }
    else if (degrees % 360 == 270) {
        return rotate270(matrix, n);
    }
    else {
        cout << "Некорректное значение градусов поворота. Доступны только 0, 90, 180, 270." << endl;
        return matrix; 
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 4;
    int** matrix = createMatrix(n);
    int count = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = count++;
        }
    }

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix, n);


    int degrees;

    cout << "Введите угол поворота (0, 90, 180, 270): ";
    cin >> degrees;

    int** rotated_matrix = rotateMatrix(matrix, n, degrees);

    cout << "Матрица после поворота на " << degrees << " градусов:" << endl;
    printMatrix(rotated_matrix, n);

    
    if (rotated_matrix != matrix) {
        deleteMatrix(rotated_matrix, n);
    }

    deleteMatrix(matrix, n);

    return 0;
}
