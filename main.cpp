#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

/*
La complejidad de este algoritmo es O(n^2) ya que
se recorre el arreglo n veces y en cada iteración se recorre el arreglo
de nuevo, por lo que el tiempo de ejecución es n * n = n^2
*/

int main() {
    int nums[] = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Arreglo inicial: " << std::endl;
    for (int i : nums)
        std::cout << i << " ";
    std::cout << std::endl;

    // Se necesita el tamaño del arreglo para poder recorrerlo
    int size = sizeof(nums) / sizeof(nums[0]);
    bubbleSort(nums, size);

    std::cout << "Arreglo ordenado: " << std::endl;
    for (int i : nums)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
