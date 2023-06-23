#include <iostream>

#include "canon.h"

int main(int argc, char * argv[]) 
{
    std::cout << "Hello World\n";

    Tuple factory;

    Tuple pos = factory.Point(0,1,0);
    Tuple vel = factory.Vector(1,1,0).Normalize();
    Tuple grav = factory.Vector(0,-0.1,0);
    Tuple wind = factory.Vector(-0.01,0,0);

   Projectile proj(pos, vel);
   Environment environ(grav,wind);

   Canon canon(proj, environ);
   canon.ShootCanon();
}