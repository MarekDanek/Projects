#include "pointParticle.h"
#include <vector>
#pragma once

class VelocityVerletIntegrator{
    public:
        VelocityVerletIntegrator() {};
        void add(PointParticle& pointParticle);    
        void run(double dt, double t0, double tMax);
        Vector gravitationalForce(PointParticle pointParticle1, PointParticle pointParticle2);

    private:
        std::vector<PointParticle> pointParticles; 
        void CalculateAccelerations(std::vector<PointParticle>& container);
        void CalculateNewPositions(const std::vector<PointParticle>& cont1, std::vector<PointParticle>& cont2, double dt);
        void CalculateNewVelocities(std::vector<PointParticle>& cont1, std::vector<PointParticle>& cont2, double dt);
                             
                              
                              
};