#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <iostream>

#include "solver.h"
#include "bar.h"


Solver::Solver(Bar bar_to_solve): 
    user_bar{bar_to_solve}, 
    DT{(9 * bar_to_solve.dx * bar_to_solve.dx)/(20 * bar_to_solve.alpha)},
    BAR_EMMISIVITY{(bar_to_solve.alpha * DT)/ (bar_to_solve.dx*bar_to_solve.dx)}
{};

std::vector<double> Solver::solveBar(){
    std::vector<double> current_temperature = user_bar.temperature;
    std::vector<double> next_temperature = user_bar.temperature;

    std::vector<double> residuals(user_bar.temperature.size(), 0.0);
    double current_max_residual {0.0};
    double t_current {DT};

    while (current_max_residual > MAX_RESIDUAL || t_current == DT){
        for (int j = 1; j < current_temperature.size() - 1; j++){

            next_temperature.at(j) = current_temperature.at(j) + BAR_EMMISIVITY * (current_temperature.at(j+1) - 2*current_temperature.at(j) + current_temperature.at(j-1));
            residuals.at(j) = std::abs(current_temperature.at(j) - next_temperature.at(j));
            current_max_residual = *std::max_element(residuals.begin(), residuals.end());
        }
        printCurrentSolution(next_temperature, t_current);
        t_current += DT;
        current_temperature = next_temperature;
    }
    return current_temperature;
}

void Solver::printCurrentSolution(std::vector<double> solution, double time_step){
    std::cout << "dt: " << std::setw(10) << time_step << " |";
    for (double i: solution)
        std::cout << std::setw(10) << i << ' ';
        std::cout << "\n";
}