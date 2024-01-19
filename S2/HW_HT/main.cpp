#include "Hash_Table_Set.h"
#include "iostream"

int main() {
    Hash_Table_Set<int, std::string> hashTable;

    // Insertar elementos
    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(3, "Three");

    // Mostrar el tamaño de la tabla
    std::cout << "Tamaño de la tabla: " << hashTable.len() << std::endl;

    // Acceder y mostrar elementos
    try {
        std::cout << "Elemento con clave 2: " << hashTable.find(2) << std::endl;
        std::cout << "Elemento mínimo: " << hashTable.find_min().second << std::endl;
        std::cout << "Elemento máximo: " << hashTable.find_max().second << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // Iterar sobre la tabla
    auto iterOrder = hashTable.iter_order();
    std::cout << "Iteración sobre la tabla:" << std::endl;
    for (const auto& entry : iterOrder) {
        std::cout << "Clave: " << entry.first << ", Valor: " << entry.second << std::endl;
    }

    // Eliminar un elemento
    try {
        hashTable.remove(2);
        std::cout << "Elemento con clave 2 eliminado." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // Mostrar el tamaño de la tabla después de eliminar
    std::cout << "Tamaño de la tabla después de eliminar: " << hashTable.len() << std::endl;

    return 0;
}
