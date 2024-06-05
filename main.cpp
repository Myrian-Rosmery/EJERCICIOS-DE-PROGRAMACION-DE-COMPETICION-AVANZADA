#include <iostream>
#include <vector>

void imprimirSubconjunto(const std::vector<int>& subconjunto) {
    std::cout << "{ ";
    for (int num : subconjunto) {
        std::cout << num << " ";
    }
    std::cout << "}" << std::endl;
}

void generarSubconjuntos(const std::vector<int>& arr, std::vector<int>& subconjunto, int index, int& totalSubconjuntos) {
    
    imprimirSubconjunto(subconjunto);
    
    totalSubconjuntos++;

    
    for (int i = index; i < arr.size(); ++i) {
        
        subconjunto.push_back(arr[i]);

        generarSubconjuntos(arr, subconjunto, i + 1, totalSubconjuntos);

        subconjunto.pop_back();
    }
}


void generarTodosLosSubconjuntos(const std::vector<int>& arr) {
    std::vector<int> subconjunto;
    int totalSubconjuntos = 0;
    generarSubconjuntos(arr, subconjunto, 0, totalSubconjuntos);
    std::cout << "Total de subconjuntos: " << totalSubconjuntos << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3,4,7,8}; 
    std::cout << "Todos los subconjuntos posibles:" << std::endl;
    generarTodosLosSubconjuntos(arr);
    return 0;
}
