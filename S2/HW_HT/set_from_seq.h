//
// Created by bihonda on 18/01/2024.
//

#ifndef HW_HT_SET_FROM_SEQ_H
#define HW_HT_SET_FROM_SEQ_H


#include "ForwardList.h"
#include <iostream>

template <typename T>
class set_from_seq {
private:
    ForwardList<T> S;

public:
    set_from_seq() {}

    int size() {
        return S.size();
    }

    void build(const ForwardList<T>& A) {
        S = A;
    }

    void insert(const T& x) {
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == x) {
                S[i] = x;
                return;
            }
        }
        S.push_back(x);
    }

    void remove(const T& k) {
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == k) {
                S.pop_front();
                return;
            }
        }
    }

    T find(const T& k) {
        for (const auto& x : S) {
            if (x == k) {
                return x;
            }
        }
        return T();
    }

    T find_min() {
        if (S.empty()) {
            throw out_of_range("Set vacío");
        }

        T out = S.front();
        for (const auto& x : S) {
            if (x < out) {
                out = x;
            }
        }
        return out;
    }

    T find_max() {
        if (S.empty()) {
            throw out_of_range("Set vacío");
        }

        T out = S.front();
        for (const auto& x : S) {
            if (x > out) {
                out = x;
            }
        }
        return out;
    }

    T find_next(const T& k) {
        T out;
        for (const auto& x : S) {
            if (x > k) {
                if (out == T() || x < out) {
                    out = x;
                }
            }
        }
        return out;
    }

    T find_prev(const T& k) {
        T out;
        for (const auto& x : S) {
            if (x < k) {
                if (out == T() || x > out) {
                    out = x;
                }
            }
        }
        return out;
    }

    ForwardList<T> iter_ord() {
        ForwardList<T> result;
        T x = find_min();
        while (x != T()) {
            result.push_back(x);
            x = find_next(x);
        }
        return result;
    }
};


#endif //HW_HT_SET_FROM_SEQ_H
