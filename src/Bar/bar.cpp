#include "bar.h"
#include <iostream>
#include <iomanip>


Bar::Bar(double end_a_temp, double end_b_temp, double bar_initial_temp, double bar_len, double cp, double k, int n_elements):
    temperature(n_elements, bar_initial_temp),
    cp (cp),
    k (k),
    dx (bar_len / static_cast<double>(n_elements)),
    alpha (k / cp)
    {
        temperature.at(0) = end_a_temp;
        temperature.back() = end_b_temp;
    }

void Bar::printBar(){
    for (double i: temperature)
        std::cout << std::setw(10) << i << ' ';
        std::cout << "\n";
}

void Bar::updateTemperature(int position, double new_temperature){
    temperature.at(position) = new_temperature;
}
