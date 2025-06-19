#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    // Constantes physiques
    const double m = 1.0;         
    const double k = 1.0;         
    const double omega2 = k / m;  

    // Conditions initiales
    double x = 1.0; 
    double v = 0.0; 

    // Temps
    double t = 0.0;
    const double dt = 0.01;       // pas de temps
    const double Tmax = 20.0;     
    int steps = Tmax / dt;

    // Pour sauvegarder les données
    std::ofstream file("oscillateur.csv");
    file << "t,x,v\n";

    // Boucle d'intégration
    for (int i = 0; i < steps; ++i) {
        file << t << "," << x << "," << v << "\n";

        double a = -omega2 * x;
        v += a * dt;
        x += v * dt;
        t += dt;
    }

    file.close();
    std::cout << "Simulation terminée. Résultats dans 'oscillateur.csv'.\n";
    return 0;
}