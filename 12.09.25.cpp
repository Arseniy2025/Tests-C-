#include <iostream>
using namespace std;
// 3 задание
void insertSort(int arr[], int n, int& counts, int& swaps) {
    counts = 0;
    swaps = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        counts++;
        while (j >= 0) {
            counts++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j = j - 1;
                counts++;
            }
            else {
                break;
            }
        }
        arr[j + 1] = key;
        if (j + 1 != i) swaps++; 
    }
}

void selectionSort(int arr[], int n, int& counts, int& swaps) {
    counts = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            counts++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 10;
    int original[n] = { 64, 34, 25, 12, 22, 11, 90, 88, 76, 50};

    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = original[i];
        arr2[i] = original[i];
    }

    cout << "Исходный массив: ";
    printArray(original, n);
    cout << endl;

    int insComparisons, insSwap;
    insertSort(arr1, n, insComparisons, insSwap);

    cout << "Сортировка вставками:" << endl;
    cout << "Результат: ";
    printArray(arr1, n);
    cout << "Сравнений: " << insComparisons << endl;
    cout << "Обменов: " << insSwap << endl;
    cout << endl;

    int selComparisons, selSwaps;
    selectionSort(arr2, n, selComparisons, selSwaps);

    cout << "Сортировка выбором:" << endl;
    cout << "Результат: ";
    printArray(arr2, n);
    cout << "Сравнений: " << selComparisons << endl;
    cout << "Обменов: " << selSwaps << endl;
    cout << endl;

    cout << "СРАВНЕНИЕ АЛГОРИТМОВ:" << endl;
    cout << "Сортировка вставками - Сравнений: " << insComparisons;
    cout << ", Обменов: " << selSwaps << endl;
    cout << "Сортировка выбором   - Сравнений: " << selComparisons;
    cout << ", Обменов: " << selSwaps << endl;
    cout << endl;

    return 0;
}

// 4 задание
/*int interpolationSearch(int A[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high && x >= A[low] && x <= A[high]){
        int pos = low + ((x - A[low]) * (high - low)) / (A[high] - A[low]);

        if (A[pos] == x) {
            return pos;
        }
        else if (A[pos] < x) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 18;
    int result = interpolationSearch(arr, n, x);

    if (result != -1) {
        cout << "Элемент " << x << " найден на позиции " << result << endl;
    }
    else {
        cout << "Элемент " << x << " не найден" << endl;
    }
    return 0;
}
*/
