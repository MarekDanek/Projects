#include "pointParticle.h"
#include "velocityVerletIntegrator.h"
#include "vector.h"
#include <cmath>
#include <iostream>
using namespace std;



int main() {
 VelocityVerletIntegrator integrator;
 const double hmotnost_slunce = 1.989e30;
 const double hmotnost_zeme = 5.972e24;
 const double vzdalenost_zeme_slunce = 1.496e11;
 const double rychlost_zeme = 29780.0;


 PointParticle Slunce;
 Slunce.mass = hmotnost_slunce;
 Slunce.position = Vector(0.0, 0.0);
 Slunce.velocity = Vector(0.0, 0.0);



 PointParticle Zeme;
 Zeme.mass = hmotnost_zeme;
 Zeme.position = Vector(vzdalenost_zeme_slunce, 0.0);
 Zeme.velocity = Vector(0.0, rychlost_zeme);

 
 integrator.add(Slunce);   
 integrator.add(Zeme); 
    
 double timeStep = 3600.0;
 double maxTime = 365.25 * 24.0 * 3600.0;
 double startTime = 0.0;

 std::cout << "Spoustim simulaci Slunce a Zeme..." << std::endl;
 std::cout << "Casovy krok (dt): " << timeStep << " s (1 hodina)" << std::endl;
 std::cout << "Celkovy cas (tMax): " << maxTime << " s (1 rok)" << std::endl;

 integrator.run(timeStep, startTime, maxTime);
    
 std::cout << "Simulace dokoncena." << std::endl;

 return 0;
}
