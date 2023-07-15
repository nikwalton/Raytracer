#include <iostream>

#include "tuple.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "canon.hpp"

int main(int argc, char * argv[]) 
{
    std::cout << "Hello World\n";

    Tuple factory;

    Point pos(0,1,0);
    Vector vel(1,1.8,0);
    Tuple normalizedVel = vel.Normalize() * 11.5;

    Vector grav(0,-0.1,0);
    Vector wind(-0.01, 0, 0);

   Projectile proj(pos, normalizedVel);
   Environment environ(grav,wind);

   Canon canon(proj, environ);
   canon.ShootCanon();
}