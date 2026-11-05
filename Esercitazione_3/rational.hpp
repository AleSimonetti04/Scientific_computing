# pragma once
# include <iostream>
# include <concepts>


template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;

    /* calcolo del MCD via algoritmo di Euclide */
    I MCD_Euclide(I a, I b) {
        if (a < 0) {
            a = -a;
        }
        if (b < 0) {
            b = -b;
        }
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        I n1;
        if (a < b) {
            n1 = a;
        }
        else {
            n1 = b;
        }
        for (I i = n1; i >= 1; i--) {
            if (( a % i == 0) && (b % i == 0)) {
                return i;
            }
        }
        return 1;
    }

    void semplificazione() {
        if (den_ == 0) {
            return;
        }
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
        I div_ = MCD_Euclide(num_, den_);
        num_ = num_/div_;
        den_ = den_/div_;
    }
public:

    /* Costruttore di default */
    rational()
        : num_(I{0}), den_(I{1})
    {}

    /* Costruttore user-defined */
    rational(const I& px, const I& py)
        : num_(px), den_(py)
    {

    /* Check */ 
    if (den_ == 0 && num_ != 0){
            num_ = 1;
        } 

    else if (den_ == 0 && num_ == 0){
        den_ = 0;
        num_ = 0;
        }
    else {
        semplificazione();
    }
    }

    /* Restituiscono i valori di num e den */
    I num() const { return num_; }
    I den() const { return den_; }

    /* Implemento somma */
    /* modifica num_ e den_originari */
    rational& operator+=(const rational& other){
        if ((den_ == 0 && num_ == 1) || (other.den_ == 0 && other.num_ == 1))
        {
            num_ = 1;
            den_ = 0;
        }
        else if ((den_ == 0 && num_ == 0)|| (other.den_ == 0 && other.num_ == 0))
        {
            num_ = 0;
            den_ = 0;
        }

        else
        {
            num_ = (num_*other.den_)+(other.num_*den_);
            den_ = (den_*other.den_); 
        }
        semplificazione();
        return *this;
    }

    /* crea nuovi num_ e den_ */
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    /* Implemento differenza */
    /* modifica num_ e den_originari */
    rational& operator-=(const rational& other){
        if ((den_ == 0 && num_ == 1) || (other.den_ == 0 && other.num_ == 1))
        {
            num_ = 1;
            den_ = 0;
        }
        else if ((den_ == 0 && num_ == 0)|| (other.den_ == 0 && other.num_ == 0))
        {
            num_ = 0;
            den_ = 0;
        }
        else
        {
            num_ = (num_*other.den_)-(other.num_*den_);
            den_ = (den_*other.den_); 
        }
        semplificazione();
        return *this;
    }

    /* crea nuovi num_ e den_ */
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }

    /* Implemento moltiplicazione */
    /* modifica num_ e den_originari */
    rational& operator*=(const rational& other){
        if ((den_ == 0 && num_ == 1) && (other.den_ == 0 && other.num_ == 1))
        {
            num_ = 1;
            den_ = 0;
        }
        else if ((den_ == 0 && num_ == 0) && (other.den_ == 0 && other.num_ == 0))
        {
            num_ = 0;
            den_ = 0;
        }
        else if ((den_==0 && num_==1)&&(other.num_!=1 && other.num_!=0 && other.den_ != 0)){
            num_=1;
            den_=0;
            //caso inf*numero=inf
        }
        else {
            num_ = (num_*other.num_);
            den_ = (den_*other.den_);
        }
        semplificazione();
        return *this;
    }

    /* crea nuovi num_ e den_ */
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }

    /* Implemento divisione */
    /* modifica num_ e den_originari */
    rational& operator/=(const rational& other){
       if ((den_ == 0 && num_ == 1) && (other.den_ == 0 && other.num_ == 1))
        {
            num_ = 1;
            den_ = 0;
        }
        else if ((den_ == 0 && num_ == 0) && (other.den_ == 0 && other.num_ == 0))
        {
            num_ = 0;
            den_ = 0;
        }
        else if ((den_==0 && num_==1)&&(other.num_!=1 && other.num_!=0 && other.den_ != 0)) {
            num_=1;
            den_=0;
            // caso inf/num=inf
        }
        else if ((num_!=1 && num_!=0 && den_ != 0)&&(other.den_==0 && other.num_==0)){
            num_=1;
            den_=0;
            //caso num/zero=inf
        }
        else {
            num_ = (num_*other.den_);
            den_ = (den_*other.num_);
        }
        semplificazione();
        return *this;
    }

    /* crea nuovi num_ e den_ */
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

/* Operatore di stampa */
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
    os << r.num() << "/" << r.den();
    return os;
}
