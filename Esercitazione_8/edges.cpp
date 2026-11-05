# include <iostream>
# include <string>
# include "undirected_edge.hpp"

using namespace std;

int main(void)
{
    // Test per l'ordinamento dei nodi in uno stesso arco
    undirected_edge<int> arco1(4, 2);
    if ((arco1.from() == 2) && (arco1.to() == 4))
    {
        cout << "L'arco viene riscritto come (2,4)\n";
    }
    else
    {
        cout << "L'arco non viene riscritto \n";
        return EXIT_FAILURE;
    }

    // Test per operator<
    undirected_edge<int> arco2(2,7);
    if (arco1 < arco2)
    {
        cout << "Operator< funziona: (2,4) < (2,7) \n";
    }
    else
    {
        cout << "Operator< non funziona: la tesi non è valida \n";
        return EXIT_FAILURE;
    }

    // Test per operator==
    undirected_edge<int> arco_1(2,4);
    if (arco1 == arco_1)
    {
        cout << "Operator== funziona: gli archi sono uguali  \n";
    }
    else
    {
        cout << "Operator== non funziona: la tesi non è valida \n";
        return EXIT_FAILURE;
    }

    // Test per operator<<
    cout << arco1 << "\n";


    return EXIT_SUCCESS;
}