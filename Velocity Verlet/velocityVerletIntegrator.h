#include "pointParticle.h"
#include <vector>

class VelocityVerletIntegrator{
    public:
        VelocityVerletIntegrator() {};
        void add(PointParticle& pointParticle);    
        void run(double dt, double t0, double tMax);
        double gravitationalForce(PointParticle pointParticle1, PointParticle pointParticle2);

    private:
        std::vector<PointParticle> pointParticles; 
};