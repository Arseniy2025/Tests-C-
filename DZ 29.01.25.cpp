#include <iostream>
using namespace std;

int sumMatrix(int** matrix, int rows, int cols) {
    if (matrix == nullptr || rows <= 0 || cols <= 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int rows = 3;
    int cols = 3;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

    cout << "Сумма элементов матрицы 1: " << sumMatrix(matrix, rows, cols) << endl;


    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
