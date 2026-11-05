# pragma once
# include <iostream>
# include <algorithm>

using namespace std;

template <typename T>
class undirected_edge 
{
    T v1_; // nodo 1 <-> vertex 1
    T v2_; // nodo 2 <-> vertex 2

    public: 

    // costruttore che garantisce che v1_ < v2_
    undirected_edge(T n1, T n2) 
    { 
        v1_ = min(n1, n2);
        v2_ = max(n1, n2);
    }

    // metodi from() e to()
    T from() const 
    {
        return v1_;
    } // Implementa un metodo from() che restituisce un tipo T e non modificano il nodo
    T to() const 
    {
        return v2_;
    } // Vedi sopra

    // Operatore che permette l'ordinamento degli archi
    /* bool operator<(const undirected_edge& other) const
    { // simile a rational -> check es.3!
        if (v1_ < other.v1_) 
        {
            return true; // Se il primo nodo del grafo è minore del primo nodo dell'altro -> è ordinato
        }
        else if (v1_ > other.v1_) 
        {
            return false; // Altrimenti, non è ordinato
        }
        else 
        {
            if (v2_ <= other.v2_)
            {
                return true; // Se il secondo elemento del primo arco è <= al secondo -> 
            }
            else if (v2_ > other.v2_) 
            {
                return false;
            }
        }
    } */

    // Altrimenti:
    bool operator<(const undirected_edge& other) const
    {
        if (v1_ != other.v1_)
        {
            return v1_ < other.v1_;
        }
        return v2_ < other.v2_;
    }


    // Operatore che verifica se due archi sono uguali
    bool operator==(const undirected_edge& other) const
    {
        if ((v1_ == other.v1_) && (v2_ == other.v2_)) 
        { 
            return true;
        }
        else 
        {
            return false;
        }
    }
};

// Operatore di stampa
template <typename T> 
ostream& operator<<(ostream& os, const undirected_edge<T>& e)
{
    os << '(' << e.from() << "," << e.to() << ")";
    return os;
}