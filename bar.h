#ifndef HEATCONDUCTION_BAR_H_
#define HEATCONDUCTION_BAR_H_

#include <vector>

class Bar{
    public:
        std::vector<double> temperature;
        const double alpha;
        const double k;
        const double cp;
        const double dx;

    public:
    Bar(double end_a_temp, double end_b_temp, double bar_initial_temp, double bar_len, double cp, double k, int n_elements);
    public: void printBar();
    void updateTemperature(int position, double temperature);
};


#endif  // HEATCONDUCTION_BAR_H_
