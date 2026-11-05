# pragma once
# include <iostream>
# include <stack>
# include <queue>
# include <map>
# include <set>
# include <vector>
# include <limits>
# include <cstdlib>
# include <string>
# include "undirected_edge.hpp"
# include "undirected_graph2.hpp"

using namespace std; 

template<typename T>
class fifo 
{
    queue<T> c; // Utilizzo direttamente la struttura queue della STL
public:
    // costruttore di default
    fifo() = default; 
    
    // put(): inserisce un nuovo elemento nel contenitore
    void put(const T& x)
    { 
        c.push(x); // Utilizzo push() già implementato in queue
    }

    // get(): rimuove un elemento dal contenitore
    T get(void)
    {
        T x = c.front(); // Prendo l'elemento in testa
        c.pop(); // Utilizzo pop() già implementato in queue
        return x;
    }

    // empty() : determina se il contenitore è vuoto
    bool empty(void) const
    {
        return c.empty(); // Utilizzo empty() già implementato 
    }
};

template<typename T>
class lifo
{
    stack<T> p;
public: 
    // costruttore di default
    lifo() = default;

    // put(): inserisce un nuovo elemento nel contenitore
    void put(const T& x)
    {
        p.push(x);
    }

    // get(): rimuove un elemento dal contenitore
    T get(void)
    {
        T x = p.top(); // Prendo l'elemento in cima -> LIFO
        p.pop(); // Utilizzo pop() già implementato
        return x;
    }

    // empty() : determina se il contenitore è vuoto
    bool empty(void) const
    {
        return p.empty(); // Utilizzo empty() già implementato 
    }
};

// Implemento la funzione graph_visit()

template<typename T, typename Container>
undirected_graph<T> graph_visit(const undirected_graph<T>& graph, T root, Container C)
{
    undirected_graph<T> tree; // dichiaro l'albero che rappresenta tutte le visite
    map<T, bool> reached; // qui inserisco i nodi che ho già visitato

    C.put(root); // inserisco nel contenitore come prima cosa il nodo radice/sorgente
    reached[root] = true; // inserisco tra i visitati la radice 
    while (! C.empty())
    {
        T node = C.get();
        // con get() estraggo dal contenitore il prossimo nodo da visitare. 
        // questo passaggio spiega perché non c'è bisogno di creare due funzioni distinte 
        // per BFS, DFS: get() lavora su entrambi i tipi di contenitore che 
        // abbiamo visto prima (pila e coda) e quindi permette di fare visita in ampiezza
        // o in profondità a seconda del caso.
        // A questo punto ci servono tutti i vicini del nodo che abbiamo estratto:
        // -> lista di adiacenza, che abbiamo già dentro il grafo

        auto neighbours = graph.neighbours(node); // neighbours prende in pasto il nodo di cui 
        // vogliamo trovare i vicini
        if (neighbours) // se neighbours contiene un set di nodi (vicini) (controllo imposto dall'uso di std::optional)
        {
            for (const auto& n : *neighbours) // scorro la mappa e dereferenzio per accedere al set di vicini
            {
                if (! reached[n]) // se il nodo non c'è oppure non è ancora stato visitato dalla mappa (= false)
                {
                    reached[n] = true; // aggiorno e segno che è stato visitato
                    C.put(n); // lo aggiungo al contenitore
                    tree.add_edge(undirected_edge<T> (node, n)); // creo un nuovo arco nell'albero
                }
            }
        }
    }
    return tree; // ritorna l'albero
};

// Nell'implementazione della recursive dfs implemento prima una funzione 
// ausiliaria che tiene conto dello stato della visita. Questa viene chiamata
// ricorsivamente ogni volta che viene trovato un nodo non visitato. 

template<typename T>
void dfs_step(const undirected_graph<T>& graph, const T& node, map<T, bool>& reached, undirected_graph<T>& tree)
{
    reached[node] = true; // segno subito che il nodo è stato visitato
    auto neighbours = graph.neighbours(node);

    if(neighbours)
    {
        for (const auto& n : *neighbours) // se trovo un vicino non trovato prima
        {
            if (! reached[n])
            {
                reached[n] = true; // lo segno come visitato
                tree.add_edge(undirected_edge<T> (node, n));
                dfs_step(graph, n, reached, tree); // qui c'è la chiamata ricorsiva che poi viene sfruttata in recursive_dfs()
            }
        }
    }
    return;
}

// Implemento la funzione recursive_dfs()
template<typename T>
undirected_graph<T> recursive_dfs(const undirected_graph<T>& graph, const T& root)
{
    undirected_graph<T> tree; // L'albero in cui metto i nodi
    map<T, bool> reached; // La mappa dei nodi raggiunti
    reached[root] = true; // Segno la radice come visitata
    // a questo punto passo alla chiamata ricorsiva ->
    dfs_step(graph, root, reached, tree);
    return tree;
}

// Infine l'algoritmo di Dijkstra
template<typename T>
undirected_graph<T> dijkstra_wo_weights(const undirected_graph<T>& graph, T root) //int n) n è il numero totale di nodi
{
    undirected_graph<T> tree;
    map<T, int> dist; // creo la mappa delle distanze e la mappa dei nodi precedenti
    map<T, T> pred; // a differenza dello pseudocodice visto, evito di usare -1 perché non fungerebbe da valore sentinella
    // setto a infinito la distanza iniziale
    for (const auto& node : graph.all_nodes())
    {
        dist[node] = numeric_limits<int>::max();
    }

    // L'algoritmo di Dijkstra usa una coda con priorità
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq; 
    // questa scrittura significa che la priority queue memorizza, utilizzando come contenitore
    // un std::vector, coppie distanza-nodo settando la priorità dal più piccolo al più grande

    pred[root] = root; // il predecessore della radice è la radice stessa
    dist[root] = 0; // la distanza tra la radice e la radice è 0
    pq.push({0, root}); 

    while (! pq.empty()) // finché la coda non è vuota
    {
        T u = pq.top().second; // indico con u il nodo con la distanza minore
        int distance = pq.top().first; // recall: coppie distanza nodo: first -> distanza, second -> nodo
        pq.pop(); // estraggo dalla cima della priority queue

        if (distance > dist[u]) // siccome nella priority queue ci sono anche le vecchie distanze più lunghe
        // in coda, così faccio in modo che queste vengano saltate a favore di quella più breve. 
        // Se distance > dist[u] -> vai avanti
        {
            continue;
        }
        auto neighbours = graph.neighbours(u); // prendo i vicini del nodo u tramite
        // la solita lista di adiacenza
        if (neighbours) // se neighbours contiene un set di nodi
        {
            for (const auto& w : *neighbours) // per ogni nodo nella lista di adiacenza
            {
                if (dist.find(w) == dist.end() || dist[w] > dist[u] + 1) // (il peso è posto uguale a 1)
                // se il nodo w non è nella mappa ovvero non è stato raggiunto oppure
                // se il percorso via u + 1 è piu corto di quello già conosciuto via w
                {
                    dist[w] = dist[u] + 1; // aggiorno la distanza minima
                    pred[w] = u; // aggiorno il predecessore e quindi la 'priorità' della coda
                    // pq.DecreaseKey(w,dist[w]); // update priorità di w con nuova distanza
                    // NON ESISTE DecreaseKey per le priority queue
                    // Soluzione alternativa:
                    pq.push({dist[w], w});
                }
            }
        }
    }

    // A questo punto, nel vettore pred abbiamo tutti i predecessori da cui passa il percorso minimo.
    // Solo ora devo fare il grafo. Se l'avessi fatto prima, Dijkstra avrebbe potuto cambiare percorso
    // Ora che ha concluso posso prendere tutti i nodi nel vettore dei predecessori, costruire gli archi
    // tra di essi e aggiungerli mediante add_edge() all'albero

    for (const auto& [node, ancestor] : pred) // per ogni coppia 
    {
        if (node != root) 
        // se il nodo ha un predecessore e non è la radice 
        {
            tree.add_edge(undirected_edge<T> (ancestor, node)); // aggiungo all'albero un arco tra il predecessore e il nodo
        }
    }
    return tree;
}

template<typename T>
void filecreator(const undirected_graph<T>& graph, const string& filename)
{
    ofstream dot_file(filename);
    dot_file << "graph MyGraph {" << endl;
    for (const auto& edge : graph.all_edges())
    {
        dot_file << " " << edge.from() << " -- " << edge.to() << ";" << endl;
    }
    dot_file << "}" << endl;
    dot_file.close();
}
