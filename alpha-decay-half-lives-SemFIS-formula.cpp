// SemFIS formula for alpha-decay

// Ref: https://doi.org/10.1103/PhysRevC.74.014312
// Ref: https://doi.org/10.1103/PhysRevC.101.024607

//=================================================================================================================================================================

#include <iostream>
#include <cmath>
#include <iomanip>


// SemFIS CALCULATION
int main() {
    // Define variables:
    int A, Z, N, Q, A_d, Z_d, N_d;
    double x, K_s, T;

    // Input mass and atomic number (A, Z, Q)
    std::cout << "Enter the value of Z: ";
    std::cin >> Z;
    std::cout << "Enter the value of A: ";
    std::cin >> A;
    std::cout << "Enter the value of Q: ";
    std::cin >> Q;

    // Calculate neutron number (N)
    N = A - Z;
    A_d = A - 4;
    Z_d = Z - 2;
    N_d = N - 2;

    // Calculate x:
    x = (0.432 * Q) * ((1.5874 + pow(A_d, 1.0 / 3.0)) / Z_d);

    // Function to calculate K_s:
    K_s = (2.52956 * Z_d) * sqrt(A_d / (A * Q)) * (acos(sqrt(x)) - sqrt(x * (1 - x)));

    // Function to calculate T_{1/2}:
    double halflife = (0.43429) * (K_s * x) - 20.446;
    T = exp(halflife);

    // Results in scientific notation
    std::cout << "The calculated alpha-decay half-life T_{1/2} for (" << Z << ", " << A << ") is: " << std::scientific << std::setprecision(4) << T << " seconds" << std::endl;

    return 0;
}
