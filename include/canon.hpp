// a little fun canon to shoot vector based projectiles out, just used to test drive the tuple class
//everything needed to run the canon is in canon.h and canon.cpp rather than splitting up all the classes needed
//to keep the raytracer lib more lean since this shouldnt be used outside of toying around
#include "tuple.hpp"

class Environment {
public:
  Environment() {}
  Environment(Tuple gravity, Tuple wind);


  Tuple GetGravity();
  Tuple GetWind();

  void SetGravity(Tuple newGravity);
  void SetWind(Tuple newWind);
private:
  Tuple gravity;
  Tuple wind;
};

class Projectile {
public:
  Projectile() {}
  Projectile(Tuple position, Tuple velocity);


  Tuple GetPosition();
  Tuple GetVelocity();

  void SetPosition(Tuple newPositon);
  void SetVelocity(Tuple newVelocity);
private:
  Tuple position;
  Tuple velocity;
};

class Canon {
public:
  Canon() {}
  Canon(Projectile projectile, Environment environment);

  Projectile GetProjectile();
  Environment GetEnvironment();

  void SetProjectile(Projectile newProjectile);
  void SetEnvrionment(Environment newEnvironment);


  Projectile Tick(Environment environment, Projectile projectile);
  void ShootCanon();

private:
  Projectile projectile;
  Environment environment;
};