#include <iostream>
#include <fstream>

#include "canon.hpp"
#include "canvas.hpp"
#include "color.hpp"

/// @brief Constructor for Environment that creates the object with a given gravity and wind vector
/// @param gravity a vector Tuple representing the gravity direction
/// @param wind a vector Tuple representing the wind direction
Environment::Environment(Tuple gravity, Tuple wind)
{

    try
    {
        if (gravity.IsPoint() == false && wind.IsPoint() == false)
        {
            this->gravity = gravity;
            this->wind = wind;
        }
        else
        {
            throw;
        }
    }
    catch (...)
    {
        std::cout << "tuple type error: make sure parameter tuples are of correct type (vector or point)\n";
    }
}

Tuple Environment::GetGravity() 
{
    return this->gravity;
}

Tuple Environment::GetWind() 
{
    return this->wind;
}

/// @brief Sets the gravity vector of the environment
/// @param newGravity a vector tuple representing the gravity direction
void Environment::SetGravity(Tuple newGravity) 
{
    try
    {
        if (newGravity.IsPoint() == false) 
        {
            this->gravity = newGravity;
        }
        else
        {
            throw;
        }
    }
    catch(...)
    {
        std::cout << "tuple type error: newGravity must be a tuple of type Vector. Check if newGravity's w component equals 0\n";
    }
}

void Environment::SetWind(Tuple newWind)
{
try
    {
        if (newWind.IsPoint() == false) 
        {
            this->wind = newWind;
        }
        else
        {
            throw;
        }
    }
    catch(...)
    {
        std::cout << "tuple type error: newWind must be a tuple of type Vector. Check if newWind's w component equals 0\n";
    }
}

/// @brief Construtor for Projectile that creates the object given position point and velocity vector
/// @param position a point Tuple representing the position
/// @param velocity a vector Tuple representing the velocity
Projectile::Projectile(Tuple position, Tuple velocity)
{
  try
    {
        if (position.IsPoint() == true && velocity.IsPoint() == false)
        {
            this->position= position;
            this->velocity = velocity;
        }
        else
        {
            throw;
        }
    }
    catch (...)
    {
        std::cout << "tuple type error: make sure parameter tuples are of correct type (vector or point)\n";
    } 
}

Tuple Projectile::GetPosition() 
{
    return this->position;
}

Tuple Projectile::GetVelocity()
{
    return this->velocity;
}

void Projectile::SetPosition(Tuple newPosition)
{
    try
    {
        if(newPosition.IsPoint() == true)
        {
            this->position = newPosition;
        }
        else
        {
            throw;
        }
    }
    catch (...)
    {
        std::cout << "tuple type error: Positon must be a tuple of type Point. Check if newPositions' w component is equal to 1";
    }
}

void Projectile::SetVelocity(Tuple newVelocity)
{
    try
    {
        if (newVelocity.IsPoint() == false) 
        {
            this->velocity = newVelocity;
        }
        else
        {
            throw;
        }
    }
    catch(...)
    {
        std::cout << "tuple type error: newVelocity must be a tuple of type Vector. Check if newVelocity's w component equals 0\n";
    }
}


Canon::Canon(Projectile projectile, Environment environment)
{
    this->projectile = projectile;
    this->environment = environment;
}

Projectile Canon::GetProjectile()
{
    return this->projectile;
}

Environment Canon::GetEnvironment()
{
    return this->environment;
}

void Canon::SetProjectile(Projectile newProjectile)
{
    this->projectile = newProjectile;
}

void Canon::SetEnvrionment(Environment newEnvironment)
{
    this->environment = newEnvironment;
}

Projectile Canon::Tick(Environment enviornment, Projectile projectile)
{
    Projectile temp = projectile;
    //get all the variables we need out for readability
    Tuple pos = temp.GetPosition();
    Tuple vel = temp.GetVelocity();
    Tuple grav = environment.GetGravity();
    Tuple wind = environment.GetWind();

    pos = pos + vel;
    temp.SetPosition(pos);
    vel = vel + grav + wind;
    temp.SetVelocity(vel);

    return temp;

}

void Canon::ShootCanon()
{
    Tuple pos = this->projectile.GetPosition();
    Tuple vel = this->projectile.GetVelocity();
    Tuple grav = this->environment.GetGravity();
    Tuple wind = this->environment.GetWind();

    std::cout << "Projectile Starting Position: " << pos.GetX() << ", " << pos.GetY() << ", " << pos.GetZ() << "\n";
    std::cout << "Projectile Starting Velocity:: " << vel.GetX() << ", " << vel.GetY() << ", " << vel.GetZ() << "\n";
    std::cout << "Gravity Vector Set To: " << grav.GetX() << ", " << grav.GetY() << ", " << grav.GetZ() << "\n";
    std::cout << "Wind Vector Set To: " << wind.GetX() << ", " << wind.GetY() << ", " << wind.GetZ() << "\n\n";

    std::cout << "Canon Fired!\n";

    Canvas canv(1000, 550);
    Color lineColor(1, 0, 0);

    int tick_count = 0;

    while (this->projectile.GetPosition().GetY() > 0) 
    {
        this->SetProjectile(Tick(this->environment, this->projectile));
        std::cout << tick_count << ") Projectile Position: " << this->projectile.GetPosition().GetX() << ", " 
            << this->GetProjectile().GetPosition().GetY() << ", " 
            << this->GetProjectile().GetPosition().GetZ() << "\n";
        
        int y = (int)this->GetProjectile().GetPosition().GetY() ; 
        int x = (int)this->GetProjectile().GetPosition().GetX();
        if (x > 0 && y > 0)
        {
            canv.WritePixel(x, 550 - y, lineColor);
        }
        
        tick_count++;
    } 

    std::ofstream file;
    file.open("canon.ppm");
    file << canv.CanvasToPPM();
    file.close();
}