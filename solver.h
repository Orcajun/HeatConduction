#ifndef HEATCONDUCTION_SOLVER_H_
#define HEATCONDUCTION_SOLVER_H_
#include <vector>
#include "bar.h"

class Solver{
    public: 
    Solver(Bar bar_to_solve);
    std::vector<double> solveBar();
    
    private:
    const double MAX_RESIDUAL{0.00001};
    Bar user_bar;
    const double DT;
    const double BAR_EMMISIVITY;
    
    void printCurrentSolution(std::vector<double> solution, double time_step);
};

#endif // HEATCONDUCTION_SOLVER_H_