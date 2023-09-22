#ifndef RANDOM_HPP
#define RANDOM_HPP

class Random
{
  int first_value;
  int second_value;
public:
  void DefaultRandom(int &num_1, int &num_2);
  void SmeshnoiRandom(int &num_1, int &num_2);
};

#endif //RANDOM_HPP