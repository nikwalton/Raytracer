#include <iostream>

#include "tuple.h"
#include "vector.h"
#include "point.h"
#include "canon.h"

int main(int argc, char * argv[]) 
{
    std::cout << "Hello World\n";

    Tuple factory;

    Point pos(0,1,0);
    Vector vel(1,1,0);
    Tuple normalizedVel = vel.Normalize();

    Vector grav(0,-0.1,0);
    Vector wind(-0.01, 0, 0);

   Projectile proj(pos, normalizedVel);
   Environment environ(grav,wind);

   Canon canon(proj, environ);
   canon.ShootCanon();
}