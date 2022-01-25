#include "math.h"


int map(int valueA, int rangeA_min, int rangeA_max, int rangeB_min, int rangeB_max)
{
  return (rangeB_max-rangeB_min)*(valueA-rangeA_min)/(rangeA_max-rangeA_min)+rangeB_min;
}
