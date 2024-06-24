#include "vector.hpp"

Tuple Reflect(Tuple in, Tuple normal)
{
  return in - normal * 2 * in.Dot(normal);
}