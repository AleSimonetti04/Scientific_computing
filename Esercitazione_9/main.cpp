# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <set>
# include <vector>
# include <cstdlib>
# include "graph_visit.hpp"
# include "undirected_edge.hpp"
# include "undirected_graph2.hpp"

using namespace std;

int main(void)
{

    // Creo il grafo
    undirected_graph<int> graph;
    graph.add_edge(undirected_edge<int> (1, 2));
    graph.add_edge(undirected_edge<int> (1, 3));
    graph.add_edge(undirected_edge<int> (1, 4));
    graph.add_edge(undirected_edge<int> (1, 6));
    graph.add_edge(undirected_edge<int> (2, 4));
    graph.add_edge(undirected_edge<int> (2, 5));
    graph.add_edge(undirected_edge<int> (2, 7));
    graph.add_edge(undirected_edge<int> (3, 6));
    graph.add_edge(undirected_edge<int> (4, 6));
    graph.add_edge(undirected_edge<int> (4, 7));
    graph.add_edge(undirected_edge<int> (5, 7));
    graph.add_edge(undirected_edge<int> (6, 7));
    graph.add_edge(undirected_edge<int> (6, 8));
    graph.add_edge(undirected_edge<int> (7, 9));
    graph.add_edge(undirected_edge<int> (8, 9));


    // test con BFS
    fifo<int> q; // creo la struttura con policy fifo (coda)
    auto bfsG = graph_visit(graph, 1, q); // qui il grafo è graph creato prima
    // il nodo radice/sorgente è 1 e il contenitore è la coda di cui prima

    // Ora stampo l'albero prodotto dalla visita
    for (const auto& edge : bfsG.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "BFS: " << edge << "\n";
    }
    filecreator(bfsG, "bfsT.dot");

    // Ora faccio la stessa cosa con gli altri

    // test con DFS
    lifo<int> s; // creo la struttura con policy lifo (stack)
    auto dfsG = graph_visit(graph, 1, s); // come prima, con la differenza che il contenitore è uno stack ora

    // Ora stampo l'albero prodotto dalla visita
    for (const auto& edge : dfsG.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "DFS: " << edge << "\n";
    }
    filecreator(dfsG, "dfsT.dot");

    // test con recursive_dfs
    auto recursive_dfsG = recursive_dfs(graph, 1);
    for (const auto& edge : recursive_dfsG.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "Recursive_dfs: " << edge << "\n";
    }
    filecreator(recursive_dfsG, "recursive_dfsT.dot");

    // test con Dijkstra 
    auto dijsktraG = dijkstra_wo_weights(graph, 1); // ci sono 9 nodi
    for (const auto& edge : dijsktraG.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "Dijkstra: " << edge << "\n";
    }
    filecreator(dijsktraG, "dijkstraT.dot");

    // Se invece provo con un grafo di stringhe
    undirected_graph<string> str_graph;
    str_graph.add_edge(undirected_edge<string> ("Monday", "Tuesday"));
    str_graph.add_edge(undirected_edge<string> ("Monday", "Thursday"));
    str_graph.add_edge(undirected_edge<string> ("Tuesday", "Thursday"));
    str_graph.add_edge(undirected_edge<string> ("Friday", "Thursday"));
    str_graph.add_edge(undirected_edge<string> ("Tuesday", "Wednesday"));
    str_graph.add_edge(undirected_edge<string> ("Wednesday", "Friday"));
    str_graph.add_edge(undirected_edge<string> ("Friday", "Tuesday"));
    str_graph.add_edge(undirected_edge<string> ("Friday", "Sunday"));

    // test con BFS
    fifo<string> strq; // creo la struttura con policy fifo (coda)
    auto bfsGs= graph_visit(str_graph, string("Friday"), strq); 

    // Ora stampo l'albero prodotto dalla visita
    for (const auto& edge : bfsGs.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "BFS: " << edge << "\n";
    }
    filecreator(bfsGs, "bfs_string.dot");

    // Ora faccio la stessa cosa con gli altri

    // test con DFS
    lifo<string> strs; // creo la struttura con policy lifo (stack)
    auto dfsGs = graph_visit(str_graph, string("Friday"), strs); // come prima, con la differenza che il contenitore è uno stack ora

    // Ora stampo l'albero prodotto dalla visita
    for (const auto& edge : dfsGs.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "DFS: " << edge << "\n";
    }
    filecreator(dfsGs, "dfs_string.dot");

    // test con recursive_dfs
    auto recursive_dfsGs = recursive_dfs(str_graph, string("Friday"));
    for (const auto& edge : recursive_dfsGs.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "Recursive_dfs: " << edge << "\n";
    }
    filecreator(recursive_dfsGs, "recursive_dfs_string.dot");

    // test con Dijkstra 
    auto dijsktraGs = dijkstra_wo_weights(str_graph, string("Friday")); 
    for (const auto& edge : dijsktraGs.all_edges()) // scorro il vettore di tutti gli archi visitati
    {
        cout << "Dijkstra: " << edge << "\n";
    }
    filecreator(dijsktraGs, "dijkstra_string.dot");


    return EXIT_SUCCESS;
}