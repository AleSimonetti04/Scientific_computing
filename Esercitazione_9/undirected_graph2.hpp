# pragma once
# include <iostream>
# include <map>
# include <set>
# include <vector>
# include <optional>
# include <algorithm>
# include "undirected_edge.hpp"

using namespace std;

template <typename T>
class undirected_graph 
{
    map<T, set<T>> a_list; // rappresentazione duale del grafo mediante lista di adiacenza:
    // che è alla fine un dizionario avente come chiave un tipo T, cioè UN NODO
    // e come valore un insieme di tipi T, che è l'insieme di tutti i nodi vicini (N.B. non si parla di adiacenti) 
    // al nostro nodo.
    vector<undirected_edge<T>> e_vec; // vettore degli archi                  
    public:

    // Costruttore di default
    undirected_graph() = default;   

    // Costruttore di copia
    undirected_graph(const undirected_graph& other) 
    {
        a_list = other.a_list;
        e_vec = other.e_vec;
    }

    // Neighbours prende in pasto un nodo e restituisce tutti i vicini di quel nodo prendendoli dalla lista di adiacenza
    optional<set<T>> neighbours(const T& n) const
    {
        auto itor = a_list.find(n);
        if (itor == a_list.end())
        {
            return nullopt; 
            // Se si entra nell'if, vuol dire che l'iteratore è arrivato alla fine  
            // della lista di adiacenza e non ha trovato il nodo. 
        }
        return itor -> second; // Se non si entra, vuol dire che l'
        // iteratore ha trovato un match e quindi viene restituito 
        // second, che è il set dei vicini del nodo inserito.
    }

    // Add edge prende in pasto un arco per aggiungerlo al grafo
    void add_edge(const undirected_edge<T>& edge)
    {   
        for (const auto& e : e_vec)
        {
            if (e == edge)
            {
                return; 
                // Se l'arco passato esiste già in e_vec, non si ritorna niente
            }
        }
        // Altrimenti, se l'arco passato non esiste, a partire dall'inizio
        auto itor = e_vec.begin();
        while ((itor != e_vec.end()) && (*itor < edge))
        // Scorro il vettore finché non trovo un arco più grande nel senso di operator< 
        // implementato in undirected_edge.hpp
        {
            itor ++;
        }
        e_vec.insert(itor, edge); // lo inserisco nel vettore e metto i nodi nella lista di adiacenza
        a_list[edge.from()].insert(edge.to());
        a_list[edge.to()].insert(edge.from());
    }

    // All edges: restituisce il vettore di tutti gli archi
    vector<undirected_edge<T>> all_edges() const
    {
        return e_vec; // il vettore è già ordinato da prima
    }

    // All nodes: restituisce il set di tutti i nodi
    set<T> all_nodes() const 
    { 
        set<T> nodes;
        // per ogni coppia "c" chiave-valore nel(dizionario)la lista di adiacenza 
        for (const auto& c : a_list)
        {
            nodes.insert(c.first); // Dalla documentazione, per prendere la chiave posso usare .first
        }
        return nodes;
    }

    // edge number prende in pasto un arco e restituisce la numerazione all'interno del grafo,
    // se questo esiste, nullopt se non esiste
    // Usiamo const per dire che non modifichiamo né il parametro né all'interno del metodo
    optional<int> edge_number(const undirected_edge<T>& edge) const
    { 
        for (int i = 0; i < (int)e_vec.size(); i++)
        {
            if (e_vec[i] == edge) 
            {
            return i;
            }
        }
        return nullopt;// se il confronto non dà esito positivo 
    }

    // edge at: prende un int e restituisce l'arco ad esso corrispondente se l'indice è ammissibile
    // nullopt se invece è fuori
    optional<undirected_edge<T>> edge_at(int j) const
    {
        if ((j < 0) || (j >= (int)e_vec.size())) 
        {
            return nullopt;
        }
        return e_vec[j];
    }

    // Operator-: prende in pasto due grafi G, G' e ne restituisce la differenza
    vector<undirected_edge<T>> operator-(const undirected_graph<T>& other) const
    {
        vector<undirected_edge<T>> diff; // creo il vettore degli archi che differiscono
        for (const auto& edge : e_vec) // per ogni elemento dentro e_vec senza modificarlo o copiarlo (-> &)
        {
            if (! other.edge_number(edge)) // Se l'arco non è in other, coerentemente con nullopt
            {
                diff.push_back(edge); // lo aggiungo al vettore
            }
        }
        return diff;
    }

};
