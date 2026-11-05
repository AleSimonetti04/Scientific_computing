# pragma once
# include <iostream>
# include <optional>
# include "Eigen/Eigen"

using namespace std;

optional<Eigen::VectorXd> cg(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd& x, const double& tol)
{
    // In primo luogo controllo che la matrice sia quadrata
    if (A.rows() != A.cols())
    {
        cerr << "Errore: la matrice A non è quadrata, ma ha dimensioni " << A.rows() << "*" << A.cols() << endl;
        return nullopt;
    }

    // Per poter applicare il metodo del gradiente coniugato è necessario che la matrice A sia simmetrica
    // e definita positiva. Serve dunque un check su queste due proprietà. Utilizzo un std::optional

    // Simmetria
    if (! A.isApprox(A.transpose(), 1e-12))
    {
        cerr << "Errore: la matrice A non è simmetrica" << endl;
        return nullopt;
    }

    // Definita positiva
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigsolver(A); // calcola gli autovalori di A sfruttando il fatto che sia simmetrica
    if (eigsolver.eigenvalues().minCoeff() <= 0) 
    {
        cerr << "Errore: la matrice A non è definita positiva" << endl;
        return nullopt;
    }

    // Ometto il check sull'invertibilità:
    // matrici simmetriche e definite positive sono sempre invertibili

    Eigen::VectorXd res = b - (A * x); // residuo iniziale    
    Eigen::VectorXd p = res; // direzione di discesa
    double res_norm_0 = res.norm();
    int k = 0;
    int kmax = 10 * (int)A.rows();
    
    while (k < kmax && res.norm() > tol * res_norm_0)
    {
        const double alpha_k = ((p.transpose() * res) / (p.transpose() * A * p)).value();
        x += alpha_k * p;
        res = b - (A * x);
        const double beta_k = ((p.transpose() * A * res) / (p.transpose() * A * p)).value();
        p = res - (beta_k * p);
        k ++;
    }
    return x;
}

