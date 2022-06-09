#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(double from, double to)
    : _mt(_rd()),
      _distribution(from, to)
{
}

double RandomGenerator::get() {
    return _distribution(_mt);
}
