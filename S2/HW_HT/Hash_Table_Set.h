//
// Created by bihonda on 18/01/2024.
//

#ifndef HW_HT_HASH_TABLE_SET_H
#define HW_HT_HASH_TABLE_SET_H

#include "set_from_seq.h"  // Asegúrate de incluir el encabezado de Set_from_Seq
#include "ForwardList.h"  // Asegúrate de incluir el encabezado de ForwardList
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

template <typename T>
class Hash_Table_Set {
private:
    set_from_seq<ForwardList<T>> chain_set;
    std::vector<ForwardList<T>> A;
    int size;
    int r;
    int p;
    int a;
    int upper;  // Add this line
    int lower;  // Add this line

    void _compute_bounds() {
        // Implementa la función _compute_bounds
        upper = A.size();
        lower = A.size() * 100 * 100 / (r * r);
    }

    void _resize(int n) {
        // Implementa la función _resize
        if (lower >= n || n >= upper) {
            int f = r / 100;
            if (r % 100) {
                f += 1;
            }
            int m = std::max(n, 1) * f;
            A = std::vector<ForwardList<T>>(m, chain_set);
            for (const auto& x : *this) {
                int h = _hash(x.key, m);
                A[h].insert(x);
            }
            _compute_bounds();
        }
    }

    int _hash(int k, int m) {
        // Implementa la función _hash
        return ((a * k) % p) % m;
    }

public:
    // Constructor
    Hash_Table_Set(int r = 200) : chain_set(), A(), size(0), r(r), p(2147483647) {
        // Inicializa el generador de números aleatorios
        srand(static_cast<unsigned>(time(nullptr)));

        // Inicializa a con un valor aleatorio en el rango [1, p - 1]
        a = rand() % (p - 1) + 1;

        _compute_bounds();
        _resize(0);
    }

    // Destructor
    ~Hash_Table_Set() = default;

    // Función que devuelve el tamaño de la tabla hash
    int len() const {
        return size;
    }

    // Iterador que recorre la tabla hash
    set_from_seq<ForwardList<T>> iter() const {
        set_from_seq<ForwardList<T>> result;
        for (const auto& X : A) {
            result.build(X);
        }
        return result;
    }

    // Función que construye la tabla hash a partir de una secuencia X
    void build(const set_from_seq<ForwardList<T>>& X) {
        for (const auto& x : X) {
            insert(x);
        }
    }

    // Función de búsqueda en la tabla hash
    T find(int k) const {
        int h = _hash(k, A.size());
        return A[h].find(k);
    }

    // Función de inserción en la tabla hash
    bool insert(const T& x) {
        _resize(size + 1);
        int h = _hash(x.key, A.size());
        bool added = A[h].insert(x);
        if (added) {
            size += 1;
        }
        return added;
    }

    // Función de eliminación en la tabla hash
    T remove(int k) {
        assert(len() > 0);
        int h = _hash(k, A.size());
        T result = A[h].remove(k);
        size -= 1;
        _resize(size);
        return result;
    }

    T find_min() const {
        T out = T();
        for (const auto& x : *this) {
            if (out.key == -1 || x.key < out.key) {
                out = x;
            }
        }
        return out;
    }

    T find_max() const {
        T out = T();
        for (const auto& x : *this) {
            if (out.key == -1 || x.key > out.key) {
                out = x;
            }
        }
        return out;
    }

    T find_next(int k) const {
        T out = T();
        for (const auto& x : *this) {
            if (x.key > k) {
                if (out.key == -1 || x.key < out.key) {
                    out = x;
                }
            }
        }
        return out;
    }

    T find_prev(int k) const {
        T out = T();
        for (const auto& x : *this) {
            if (x.key < k) {
                if (out.key == -1 || x.key > out.key) {
                    out = x;
                }
            }
        }
        return out;
    }

    set_from_seq<ForwardList<T>> iter_order() const {
        set_from_seq<ForwardList<T>> result;
        T x = find_min();
        while (x.key != -1) {
            result.insert(x);
            x = find_next(x.key);
        }
        return result;
    }
};


#endif //HW_HT_HASH_TABLE_SET_H
