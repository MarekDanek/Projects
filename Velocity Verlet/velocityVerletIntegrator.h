#include "pointParticle.h"
#include <vector>

class VelocityVerletIntegrator{
    public:
        VelocityVerletIntegrator();
        void add(PointParticle& particle);    
        void run(double dt, double t0, double tMax,
                Vector (*forceFunc)(const PointParticle&, const PointParticle&));

    private:
        std::vector<PointParticle*> particles; 
};