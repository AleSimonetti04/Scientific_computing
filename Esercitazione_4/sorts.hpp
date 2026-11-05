# pragma once
# include <algorithm>
# include <concepts>
# include <optional>
# include <vector>

using namespace std;

template<typename T>
//std::optional<T>
void bubblesort(vector<T>& A) {
    for (int i = 0; i < (int)A.size() - 1; i++) {
        for (int j = (int)A.size() - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
            }
        }
    }
}

template<typename T>
//std::optional<T>
void insertionsort(vector<T>& A) {
    for (int j = 1; j < (int)A.size(); j++) {
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

template<typename T>
//std::optional<T>
void selectionsort(vector<T>& A) {
    for (int i = 0; i < (int)A.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < (int)A.size(); j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        swap(A[i], A[min_index]);
    }
}

template<typename T>
//std::optional<T>
bool is_sorted(vector<T>& A) {
    if ((int)A.size() < 2) {
        return true; // se la lunghezza è 0 oppure 1, è sempre ordinato
    }
    for (int i = 0; i < (int)A.size() - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}


