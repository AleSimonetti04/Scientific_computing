# include <iostream>
# include <vector>
# include "undirected_graph2.hpp"

using namespace std;

int main(void)
{
    undirected_graph<int> grafo;
    
    // Test add_edge e all_edges
    grafo.add_edge(undirected_edge<int> (4,2));
    grafo.add_edge(undirected_edge<int> (2,7));
    grafo.add_edge(undirected_edge<int> (4,7));
    grafo.add_edge(undirected_edge<int> (2,4));

    if (grafo.all_edges().size() == 3)
    {
        cout << "all_edges ha inserito correttamente 3 archi: (2,4), (2,7), (4,7) \n" ;
    }
    else
    {
        cout << "all_edges non ha funzionato correttamente \n";
        return EXIT_FAILURE;
    }

    // Test neighbours
    auto n2 = grafo.neighbours(2); // se il nodo non esiste dà nullopt 
    // N.B. neighbours prende const (T) int come parametro
    if (n2 && (n2->size() == 2) && (n2->count(4)) && (n2->count(7)))
    {
        cout << "neighbours ha restituito correttamente i 2 vicini di 2, che sono 4 e 7 \n";
    }
    else
    {
        cout << "neighbours non ha funzionato correttamente \n";
        return EXIT_FAILURE;
    }

    // Test all_nodes
    set<int> nodi = grafo.all_nodes();
    if ((nodi.size() == 3) && (nodi.count(2)) && (nodi.count(4)) && (nodi.count(7)))
    {
        cout << "all_nodes ha contato tutti i nodi: 2, 4 e 7 \n";
    }
    else
    {
        cout << "all_nodes non ha funzionato correttamente \n";
        return EXIT_FAILURE;
    }

    // Test edge_number
    undirected_edge<int> arc(2,7);
    auto where = grafo.edge_number(undirected_edge<int> (2,7));
    // Si tratta di un optional<int> che contiene il valore se lo trova, altrimenti nullopt
    auto wrongplace = grafo.edge_number(undirected_edge<int> (3,6));
    
    if (where && grafo.edge_at(*where) == arc)
    {
        cout << "L'arco (2,7) è nella posizione corretta \n";
    }
    else
    {
        cout << "edge_number non ha funzionato correttamente \n";
        return EXIT_FAILURE;
    }

    if (! wrongplace)
    {
        cout << "Questo arco (correttamente) non appartiene al grafo \n";
    }
    else
    {
        cout << "edge_number non ha restituito -1 e quindi non ha funzionato correttamente \n";
        return EXIT_FAILURE;
    }


    // Test edge_at
    auto ed_opt = grafo.edge_at(0);
    auto null = grafo.edge_at(31); // un numero a caso sicuramente non coerente però

    if (ed_opt) // se c'è qualcosa accedo al contenuto con *
    {
        cout << "edge_at ha restituito l'arco in posizione 0: " << *ed_opt << "\n";
    }
    else
    {
        cout << "edge_at non ha trovato nulla \n";
        return EXIT_FAILURE;
    }

    if (! null)
    {
        cout << "edge_at non ha trovato niente, in maniera corretta \n";
    }
    else
    {
        cout << "edge_at ha trovato qualcosa di scorretto \n";
        return EXIT_FAILURE;
    }

    // Test operator-
    undirected_graph<int> grafo2;
    grafo2.add_edge(undirected_edge<int> (2,4));
    
    vector<undirected_edge<int>> diff = grafo - grafo2;

    if (diff.size() == 2)
    {
        cout << "operator- ha eliminato correttamente l'arco presente in ambo i casi: (2,4) \n";
    }
    else
    {
        cout << "operator- non ha funzionato correttamente \n";
        return EXIT_FAILURE;
    }



    return EXIT_SUCCESS;
}
