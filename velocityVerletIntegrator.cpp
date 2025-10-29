#include "velocityVerletIntegrator.h"
#include <iostream>
#include <cmath>
    
void VelocityVerletIntegrator::add(PointParticle& pointParticle)
{
    pointParticles.push_back(pointParticle);
}

double VelocityVerletIntegrator::gravitationalForce(PointParticle pointParticle1, PointParticle pointParticle2)
{
    
}

void VelocityVerletIntegrator::run(double dt, double d0, double tMax)
{

}

