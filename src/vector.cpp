#include "vector.hpp"

Tuple Reflect(Vector in, Vector normal)
{
  return in - normal * 2 * in.Dot(normal);
}