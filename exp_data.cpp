#include <iostream>
#include <fstream>
#include <cmath> 
#include <iomanip> 

int main() { 
    std::ofstream fichier("exp_data.csv");
    if (!fichier) { 
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    }

    fichier << "x,y\n";  // BON saut de ligne

    double x_min = -2.0;
    double x_max = 2.0;
    double pas = 0.2;

    for (double x = x_min; x <= x_max; x += pas) {
        double y = std::exp(x);
        fichier << std::fixed << std::setprecision(4) << x << "," << y << "\n"; // BON saut de ligne
    }

    fichier.close();
    std::cout << "Fichier 'exp_data.csv' généré avec succès !" << std::endl;
    return 0;
}