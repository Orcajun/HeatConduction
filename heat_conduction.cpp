#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<double> createBar(int n_elements, double end_a_temp, double end_b_temp, double bar_initial_temp){
    std::vector<double> bar_values(n_elements, bar_initial_temp);
    bar_values.at(0) = end_a_temp;
    bar_values.back() = end_b_temp;
    return bar_values;
}

void printBar(std::vector<double> bar_vals){
    for (double i: bar_vals)
        std::cout << std::setw(10) << i << ' ';
        std::cout << "\n";
}

int main(){
    double k0 {237.0};  // Thermal conductivity, commonly known as K, W/mK
    double cp {902};  // Thermal capacity, commonly known as Cp, J/kgK
    const double alpha {k0 / cp};
    const double room_temp {22.0};
    
    double end_a_temp {};
    double end_b_temp {};

    std::cout << "Enter a temperature for bar end A: ";
    std::cin >> end_a_temp;
    std::cout << "Enter a temperature for bar end B: ";
    std::cin >> end_b_temp;

    std::vector<double> bar_vals = createBar(5, end_a_temp, end_b_temp, room_temp);

    std::cout << "Bar initial condition:" << "\n";
    printBar(bar_vals);

    std::vector<double> next_bar_vals = bar_vals; 
    const double dx {0.1};
    const double dt {(9 * dx * dx)/(20 * alpha)};
    const double const_term { (alpha * dt)/ (dx*dx) };

    std::vector<double> residuals(bar_vals.size(), 0.0);
    double max_residual {0.0};
    double t_current {dt};
    //for (int i {0}; i<10; i++){
    while (max_residual > 0.000001 || t_current == dt){
        for (int j = 1; j < bar_vals.size() - 1; j++){
            next_bar_vals.at(j) = bar_vals.at(j) + const_term * (bar_vals.at(j+1) - 2*bar_vals.at(j) + bar_vals.at(j-1));
            residuals.at(j) = std::abs(bar_vals.at(j) - next_bar_vals.at(j));
            max_residual = *std::max_element(residuals.begin(), residuals.end());
        }
        printBar(next_bar_vals);

        t_current += dt;
        bar_vals = next_bar_vals;

    }
    printBar(next_bar_vals);
    return 0;
}