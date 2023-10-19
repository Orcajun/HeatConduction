#include <iostream>
#include <vector>

#include "Bar/bar.h"
#include "Solvers/solver.h"

int main(){
    
    double end_a_temp {};
    double end_b_temp {};

    std::cout << "Enter a temperature for bar end A: ";
    std::cin >> end_a_temp;
    std::cout << "Enter a temperature for bar end B: ";
    std::cin >> end_b_temp;

    Bar user_bar(end_a_temp, end_b_temp, 23.0, 1.0, 902.0, 237.0, 10);

    std::cout << "Bar initial condition:" << "\n";
    user_bar.printBar();

    Solver bar_solver {user_bar};
    bar_solver.solveBar();
    return 0;
}