# include <iostream> 
# include <optional>
# include "Eigen/Eigen"
# include "cg.hpp"

using namespace std;

int main(int argc, char **argv)
{
    // Test su matrice simmetrica e definita positiva 

    Eigen::MatrixXd A(3,3); // definisco la matrice dei coefficienti 3*3
    A << 1.0, 1.0, 0.0,
        1.0, 4.0, 1.0,
        0.0, 1.0, 5.0;
    Eigen::VectorXd b(3); // definisco il vettore dei termini noti 
    b << 2.0, 6.0, 6.0; // così dovrei avere che la soluzione è il vettore unitario

    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(3); // vettore iniziale arbitrario che per comodità
    // scelgo come il vettore nullo
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(3); // soluzione esatta

    double tol = 1e-12; // tolleranza
    auto solution = cg(A, b, x0, tol); // optional avente come valore la soluzione
    // del sistema calcolata con il metodo del gradiente coniugato (cg)

    if (solution.has_value()) // se solution è un vettore con la soluzione -> return true, se c'è nullopt -> return false
    {
        Eigen::VectorXd x_cg = solution.value();
        double err_rel = (x_cg - x_ex).norm() / (x_ex).norm();
        cout << scientific;
        cout << "La soluzione calcolata con CG è: " << x_cg << "\n" << "con errore relativo " << err_rel << "\n";
    }
    else
    {
        cout << "Errore: il metodo del gradiente non può essere applicato su questa matrice" << "\n";
    }
    
    // Test su matrice non simmetrica

    A(0,1) = 32.0;
    Eigen::VectorXd x0_ns = Eigen::VectorXd::Zero(3);
    auto sols = cg(A, b, x0_ns, tol);
    if (! sols.has_value())
    {
        cout << "Test superato: matrice A \n" << A << "\n non accettata (non simmetrica) \n";
    }
    else 
    {
        cout << "La matrice A avrebbe dovuto essere rifiutata: non è simmetrica \n";
    }

    // Test su matrice non definita positiva

    Eigen::MatrixXd N(3,3); // matrice non definita positiva
    N << -1.0, 0.0, 0.0,
        0.0, 2.0, 0.0, 
        0.0, 0.0, 4.0;
    
    Eigen::VectorXd x0_npd = Eigen::VectorXd::Zero(3);
    auto solpd = cg(N, b, x0_npd, tol);
    if (! solpd.has_value())
    {
        cout << "Test superato: matrice A \n"<< N << "\n non accettata (non definita positiva) \n";
    }
    else
    {
        cout << "La matrice A avrebbe dovuto essere rifiutata: non è definita positiva \n";
    }

    return EXIT_SUCCESS;
}