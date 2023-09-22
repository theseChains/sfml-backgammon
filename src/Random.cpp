#include "Random.hpp"
#include <random>

void Random::DefaultRandom(int &num_1, int &num_2){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(1, 6);
  num_1 = distr(gen);
  num_2 = distr(gen);
}

void Random::SmeshnoiRandom(int &num_1, int &num_2){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(1, 6);
  num_1 = distr(gen);
  num_2 = distr(gen);
  while(num_1 == num_2){
    num_2 = distr(gen);
  }
}