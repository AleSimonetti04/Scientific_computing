# include <iostream>
# include "sorts.hpp"
# include "randfiller.h" 
# include <random>
# include <vector>
# include <string>

using namespace std;

int main() {
    randfiller R;
    vector<int> dim(100);
    R.fill(dim, 100, 8000);

    for (int i = 0; i < 100; i++) {
        vector<int> v(dim[i]); // creo un vettore v di dimensione dim[i] indicato nel ciclo
        
        R.fill(v, -500, 500); // riempio v di elementi random tra -500 e 500
        mergesort(v, 0, v.size() - 1); // ordino il vettore v

        // controllo se è ordinato con is_sorted()
        if (! is_sorted(v)) {
            cerr << "Mergesort non ha funzionato correttamente con i numeri \n";
            return EXIT_FAILURE;
        } 
    }

    cout << "Mergesort ha funzionato correttamente con i numeri \n";

    // stringhe
    
    vector<string> stringa = {"Dave", "Ed", "Andy", "Frank", "Glen", "Hal", "Andy", "Bob", "Carl", "John", "Art", "Louis", "Ben", "Zack", "Mitch", "Jesse", "Tim", "Mike", "Tom", "Will"};
    mergesort(stringa, 0, stringa.size() - 1);

    if (is_sorted(stringa)){
        cout << "Il mergesort ha funzionato correttamente con le stringhe " << endl;
    }
    else {
        cerr << "Il mergesort non ha funzionato correttamente con le stringhe " << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}