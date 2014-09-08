#include "Helper.h"
#include <random>

// Seed with a real random value, if available
static std::random_device rd;

int rollDice(const int number, const int sides) {
    // Choose a random mean between 1 and sides
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(1, sides);
    return uniform_dist(e1);
}