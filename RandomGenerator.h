#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class RandomGenerator {
private:
    std::random_device _rd;
    std::mt19937 _mt;
    std::uniform_real_distribution<double> _distribution;

public:
    RandomGenerator(double from, double to);

    double get();
};


#endif // RANDOM_H
