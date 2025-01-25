#include <iostream>

using namespace std;

 
void findSaddlePoints(int** matrix, int rows, int cols) {
    if (matrix == nullptr || rows <= 0 || cols <= 0) return;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int cur = matrix[i][j];

            
            bool RowMin = true;
            for (int k = 0; k < cols; ++k) {
                if (matrix[i][k] < cur) {
                    RowMin = false;
                    break;
                }
            }

            
            bool ColMax = true;
            for (int k = 0; k < rows; ++k) {
                if (matrix[k][j] > cur) {
                    ColMax = false;
                    break;
                }
            }

            
            if (RowMin && ColMax) {
                cout << "Найдена седловая точка: (" << i << ", " << j << ") - значение: " << cur << endl;
            }
        }
    }
}


int** createMatrix(int rows, int cols, int values[]) {
    if (rows <= 0 || cols <= 0) return nullptr;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    int k = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = values[k++];
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int rows, int cols)
{
    if (matrix == nullptr || rows <= 0 || cols <= 0) return;

    cout << "Матрица:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void deleteMatrix(int** matrix, int rows)
{
    if (matrix == nullptr) return;

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int rows = 3;
    int cols = 3;

    int values[] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

   
    int** matrix = createMatrix(rows, cols, values);

    printMatrix(matrix, rows, cols);

    findSaddlePoints(matrix, rows, cols);

    deleteMatrix(matrix, rows);
    
    return 0;
}
