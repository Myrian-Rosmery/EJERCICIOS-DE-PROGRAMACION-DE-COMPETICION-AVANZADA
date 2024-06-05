#include <iostream>
#include <vector>

void imprimirSubconjunto(const std::vector<int>& subconjunto, int size) {
    std::cout << "{ ";
    for (int i = 0; i < size; ++i) {
        std::cout << subconjunto[i] << " ";
    }
    std::cout << "}" << std::endl;
}
void generarSubconjuntos(const std::vector<int>& arr, std::vector<int>& subconjunto, int index, int currentSize, int& totalSubconjuntos) {
    imprimirSubconjunto(subconjunto, currentSize);
    totalSubconjuntos++;

    for (int i = index; i < arr.size(); ++i) {

        subconjunto[currentSize] = arr[i];

        generarSubconjuntos(arr, subconjunto, i + 1, currentSize + 1, totalSubconjuntos);
    }
}


void generarTodosLosSubconjuntos(const std::vector<int>& arr) {
    std::vector<int> subconjunto(arr.size());
    int totalSubconjuntos = 0;
    generarSubconjuntos(arr, subconjunto, 0, 0, totalSubconjuntos);
    std::cout << "Total de subconjuntos: " << totalSubconjuntos << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3,4}; // Ejemplo de arreglo
    std::cout << "Todos los subconjuntos posibles:" << std::endl;
    generarTodosLosSubconjuntos(arr);
    return 0;
}
