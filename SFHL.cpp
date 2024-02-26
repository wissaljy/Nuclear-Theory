#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Define the variables:
    int A, N, Z;

    // Define values for constants:
    double C0 = -195.09227, C1 = 3.10156, C2 = -0.04386, C3 = 1.4030e-6, C4 = -0.03199;

    // Input mass and atomic number (A, Z)
    std::cout << "Enter the value of Z: ";
    std::cin >> Z;
    std::cout << "Enter the value of A: ";
    std::cin >> A;

    // Calculate neutron number (N)
    N = A - Z;

    // Calculate T_{1/2}
    double T = 2 * M_PI * (C0 + (C1 * A) + (C2 * pow(Z, 2)) + (C3 * pow(Z, 4)) + (C4 * pow(N-Z, 2)) - (((0.13323 * pow(Z, 2)) / pow(A, 1.0 / 3)) - 11.64));
    double halfLife = exp(T);

    // Results in scientific notation
    std::cout << "The calculated spontaneous fission half-life T_{1/2} for (" << Z << ", " << A << ") is: " << std::scientific << std::setprecision(4) << halfLife << " seconds" << std::endl;


    return 0;
}