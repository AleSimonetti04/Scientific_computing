# include <iostream>
# include "rational.hpp" // # include "new_rational.hpp"

using namespace std;

int main() {
    /* segni */
    rational<int> r1(3, -2);
    rational<int> r2(-3,-4);

    cout << "Prova stampa segni (3/-2): " << r1 << endl;
    cout << "Prova stampa segni (-3/-4): " << r2 << endl;

    /* casi speciali */
    rational<int> inf(5,0); 
    rational<int> nan(0,0);

    cout << "Inf (5/0): " << inf << endl;
    cout << "NaN (0/0): " << nan << endl;

    /* test random */
    rational<int> a(1,3);
    rational<int> b(2,9);
    rational<int> c(0,4);

    cout << "Somma 1/3 + 2/9: " << (a+b) << endl;
    cout << "Prodotto 1/3 * inf: " << (a*inf) << endl;
    cout << "Differenza 1/3 - 2/9: " << (a-b) << endl;
    cout << "Prodotto 1/3 * 2/9: " << (a*b) << endl;
    cout << "Divisione 1/3 : 2/9: " << (a/b) << endl;
    cout << "Prodotto 0 * inf: " << (c*inf) << endl; // dovrebbe dare NaN

    return 0;
}

