# pragma once
# include <algorithm>
# include <concepts>
# include <optional>
# include <vector>
# include <cmath>


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
    return;
}

template<typename T>
//std::optional<T>
void insertionsort(vector<T>& A, int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        T key = A[i];
        int j = i - 1;
        while (j >= p && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
    return;
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
    return;
}

template <typename T>
void merge(vector<T>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    // T inf = 1e9
    // Vettori di supporto
    vector<T> L(n1);
    vector<T> R(n2);
    //Si copiano i dati nei vettori di supporto
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) { 
        R[j] = A[q + j + 1];
    }
    // Si uniscono i vettori di supporto in A
    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
        A[k] = L[i];
        i++;
    }
    else {
        A[k] = R[j];
        j++;
    }
    k++;
   }
   // Se presenti, si copiano i rimanenti elementi di L 
   while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
   }
   // Idem per R
   while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
   }
    return;
}

template<typename T>
void mergesort(vector<T>& A, int p, int r) {
    if (p < r) {
        int q =  p + (r - p)/2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
    return;
}

template <typename T>
int partition(vector<T>& A, int p, int r) {
    T pivot = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= pivot) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

template <typename T>
void quicksort(vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
    return;
}

template <typename T>
void modified_quicksort(vector<T>& A, int p, int r) {
    const int thr = 200;
    while (p < r) {
        if (r - p + 1 < thr) {
            insertionsort(A, p, r); // dim del vettore che sto ordinando < soglia -> insertion
            break;
        }
        else {
            int q = partition(A, p, r);
            if (q - p < r - q) {
                modified_quicksort(A, p, q - 1);
                p = q + 1;
            } 
            else {
                modified_quicksort(A, q + 1, r);
                r = q - 1;
            }
        }
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

