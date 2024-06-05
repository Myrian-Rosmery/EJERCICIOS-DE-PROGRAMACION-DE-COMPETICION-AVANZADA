#include <iostream>
#include <vector>

// Función de utilidad para imprimir un subconjunto
void imprimirSubconjunto(const std::vector<int>& subconjunto) {
    std::cout << "{ ";
    for (int num : subconjunto) {
        std::cout << num << " ";
    }
    std::cout << "}" << std::endl;
}

// Función recursiva para generar todos los subconjuntos
void generarSubconjuntos(const std::vector<int>& arr, std::vector<int>& subconjunto, int index, int& totalSubconjuntos) {
    // Imprimir el subconjunto actual
    imprimirSubconjunto(subconjunto);
    // Incrementar el contador de subconjuntos
    totalSubconjuntos++;

    // Generar todos los subconjuntos posibles a partir del índice actual
    for (int i = index; i < arr.size(); ++i) {
        // Incluir el elemento arr[i] en el subconjunto
        subconjunto.push_back(arr[i]);

        // Recursivamente generar subconjuntos con el elemento incluido
        generarSubconjuntos(arr, subconjunto, i + 1, totalSubconjuntos);

        // Excluir el elemento arr[i] del subconjunto (backtracking)
        subconjunto.pop_back();
    }
}

// Función principal para generar y mostrar todos los subconjuntos
void generarTodosLosSubconjuntos(const std::vector<int>& arr) {
    std::vector<int> subconjunto;
    int totalSubconjuntos = 0;
    generarSubconjuntos(arr, subconjunto, 0, totalSubconjuntos);
    std::cout << "Total de subconjuntos: " << totalSubconjuntos << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3,4,7,8}; // Ejemplo de arreglo
    std::cout << "Todos los subconjuntos posibles:" << std::endl;
    generarTodosLosSubconjuntos(arr);
    return 0;
}
