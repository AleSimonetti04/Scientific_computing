# include <iostream>
# include "sorts.hpp"
# include "randfiller.h" 
# include <random>
# include <vector>

using namespace std;

int main() {
    randfiller R;
    vector<int> dim(100);
    R.fill(dim, 100, 8000);

    for (int i = 0; i < 100; i++) {
        vector<int> v(dim[i]); // creo un vettore v di dimensione dim[i] indicato nel ciclo
        
        R.fill(v, 1, 1000); // riempio v di elementi random tra 1 e 1000
        bubblesort(v); // ordino il vettore v

        // controllo se è ordinato con is_sorted()
        if (! is_sorted(v)) {
            cerr << "Bubblesort non ha funzionato correttamente con i numeri \n";
            return EXIT_FAILURE;
        } 
    }

    cout << "Bubblesort ha funzionato correttamente con i numeri \n";

    // stringhe
    
    vector<string> stringa = {"Dave", "Ed", "Andy", "Frank", "Glen", "Hal", "Andy", "Bob", "Carl", "John", "Art", "Louis", "Ben", "Zack", "Mitch", "Jesse", "Tim", "Mike", "Tom", "Will"};
    bubblesort(stringa);

    if (is_sorted(stringa)){
        cout << "Il bubblesort ha funzionato correttamente con le stringhe " << endl;
    }
    else {
        cerr << "Il bubblesort non ha funzionato correttamente con le stringhe " << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}