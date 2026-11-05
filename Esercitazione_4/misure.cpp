# include <iostream>
# include <vector>
# include <algorithm>
# include "sorts.hpp"
# include "randfiller.h"
# include "timecounter.h"

using namespace std;

int main() {
    randfiller R;
    timecounter T;

    for (int k = 4; k <= 8192; k = 2*k) { 
        // A questo punto mi creo il vettore da ordinare
        vector<int> v(k);
        R.fill(v, -10000, 10000);

        // Ne faccio una copia per ciascun algoritmo da testare
        vector<int> vb = v; // per bubblesort
        vector<int> vi = v; // per insertionsort
        vector<int> vs = v; // per selectionsort
        vector<int> vstd = v; // per la funzione di ordinamento della libreria standard
        
        // Tempi bubblesort
        T.tic();
        bubblesort(vb);
        double tb = T.toc();

        // Tempi insertionsort
        T.tic();
        insertionsort(vi);
        double ti = T.toc();

        // Tempi selectionsort
        T.tic();
        selectionsort(vs);
        double ts = T.toc();

        // Tempi std::sort
        T.tic();
        std::sort(vstd.begin(), vstd.end());
        double tstd = T.toc();

        /* Stampa tempi: test per vedere se funziona
        cout << "Per vettori di " << k << " elementi" << endl;
        cout << "bubblesort impiega " << tb << " secondi" << endl;
        cout << "insertionsort impiega " << ti << " secondi" << endl;
        cout << "selectionsort impiega " << ts << " secondi" << endl;
        cout << "la funzione sort della libreria standard impiega " << tstd << " secondi" << endl;
        */ 

        // Stampa più comoda per mettere i dati su matlab
        cout << k << " " << tb << " " << ti << " " << ts << " " << tstd << endl;
    }

    return 0;
}