# include <iostream>
# include <vector>
# include <algorithm>
# include "sorts.hpp"
# include "randfiller.h"
# include "timecounter.h"

using namespace std;

int main(void) {
    randfiller R;
    timecounter T;
    
    for (int k = 0; k <= 400; k += 5) { 
        vector<vector<int>> v(100, vector<int>(k)); // un vettore di 100 vettori con k interi 
        
        // Ora riempiamo
        for (int i = 0; i < 100; i++) {
            R.fill(v[i], -500, 500); // i vettori sono riempiti con elementi positivi e negativi compresi tra -10000 e 10000
        } 

        // Ora, come già fatto nell'esercitazione 4, per ciascun algoritmo creo una copia dei dati (in questo caso non più vettori, ma un vettore di vettori)
        vector<vector<int>> vb = v; // per bubblesort
        vector<vector<int>> vi = v; // per insertionsort
        vector<vector<int>> vs = v; // per selectionsort
        vector<vector<int>> vstd = v; // per la funzione di ordinamento della libreria standard
        vector<vector<int>> vm = v; // per mergesort
        vector<vector<int>> vq = v; // per quicksort
        vector<vector<int>> vmq = v; // per quicksort modificato

        // Ora per ciascun algoritmo misuriamo i tempi

        // Tempi bubblesort
        T.tic(); 
        for (int j = 0; j < 100; j++) {
            bubblesort(vb[j]); // Ordiniamo con bubblesort ogni elemento del vettore di vettori
        }
        double avg_tb = T.toc()/100;

        // Tempi insertionsort
        T.tic(); 
        for (int j = 0; j < 100; j++) {
            insertionsort(vi[j], 0, k - 1); // Ordiniamo con insertionsort ogni elemento del vettore di vettori
        }
        double avg_ti = T.toc()/100;

        // Tempi selectionsort
        T.tic(); 
        for (int j = 0; j < 100; j++) {
            selectionsort(vs[j]); // Ordiniamo con selectionsort ogni elemento del vettore di vettori
        }
        double avg_ts = T.toc()/100;

        // Tempi mergesort
        T.tic(); 
        for (int j = 0; j < 100; j++) {
            mergesort(vm[j], 0, k - 1); // Ordiniamo con mergesort ogni elemento del vettore di vettori
        }
        double avg_tm = T.toc()/100;

        // Tempi quicksort
        T.tic(); 
        for (int j = 0; j < 100; j++) {
            quicksort(vq[j], 0, k - 1); // Ordiniamo con quicksort ogni elemento del vettore di vettori
        }
        double avg_tq = T.toc()/100;

        // Tempi std::sort
        T.tic(); 
        for (int j = 0; j < 100; j++) {
            sort(vstd[j].begin(), vstd[j].end()); // Ordiniamo con std::sort ogni elemento del vettore di vettori
        }
        double avg_tstd = T.toc()/100;

        // Tempi quicksort modificato
        T.tic();
        for (int j = 0; j < 100; j++) {
            modified_quicksort(vmq[j], 0, k - 1); // Ordiniamo con quicksort modificato ogni elemento del vettore di vettori
        }
        double avg_tmq = T.toc()/100;

        // Stampa tempi medi
        cout << k << " " << avg_tb << " " << avg_ti << " " << avg_ts << " " << avg_tm << " " << avg_tq << " " << avg_tstd << " " << avg_tmq << "\n";
        
        if (avg_ti < avg_tq) {
            cout << "All'iterazione " << k << " insertionsort è più veloce di quicksort\n";
        }
    }
    return 0;
}