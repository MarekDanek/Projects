#include "velocityVerletIntegrator.h"
#include "pointParticle.h"
#include "vector.h"
#include <iostream>
#include <cmath>
    
void VelocityVerletIntegrator::add(PointParticle& pointParticle)
{
    pointParticles.push_back(pointParticle);
}

Vector VelocityVerletIntegrator::gravitationalForce(PointParticle pointParticle1, PointParticle pointParticle2)
{
    double G = 6.67430e-11;
    double vectorX_1_to_2 = pointParticle2.position.get_x() - pointParticle1.position.get_x();
    double vectorY_1_to_2 = pointParticle2.position.get_y() - pointParticle1.position.get_y();

    Vector vector_i_to_j(vectorX_1_to_2, vectorY_1_to_2);


    const double epsilon_sq = 1e-12; //pro stabilitu
    double distanceSquared_i_and_j = vector_i_to_j.SquareLenVector() + epsilon_sq;

    double distance_i_and_j = std::sqrt(distanceSquared_i_and_j);

    double distanceCubed_i_and_j = distance_i_and_j * distanceSquared_i_and_j;

    double sila_skalarni_cast = (G * pointParticle1.mass * pointParticle2.mass) / distanceCubed_i_and_j;

    Vector finalni_sila = vector_i_to_j.ScaleVector(sila_skalarni_cast);

    return finalni_sila;
                             
}



void VelocityVerletIntegrator::CalculateAccelerations(std::vector<PointParticle>& container){
    for (size_t i = 0; i < container.size(); ++i) {

      Vector total_force(0.0, 0.0);

     for (size_t j = 0; j < container.size(); ++j) {

        if (i == j) {
         continue; 
        }

  Vector force_ij = gravitationalForce(container[i], container[j]);
 
  double new_total_force_x = total_force.get_x() + force_ij.get_x();
  double new_total_force_y = total_force.get_y() + force_ij.get_y();
  total_force.set_x(new_total_force_x);
  total_force.set_y(new_total_force_y);
 }
 
 double particle_mass = container[i].mass;
 double inverse_mass = 1.0 / particle_mass;
 
 Vector new_acceleration = total_force.ScaleVector(inverse_mass);
 
 container[i].acceleration.set_x(new_acceleration.get_x());
 container[i].acceleration.set_y(new_acceleration.get_y());
 }
}



void VelocityVerletIntegrator::CalculateNewPositions(const std::vector<PointParticle>& cont1, std::vector<PointParticle>& cont2, double dt)  
{

    for (size_t i = 0; i < cont1.size(); ++i) {
        
        const Vector& old_position_in_t = cont1[i].position;
        const Vector& old_speed_in_t = cont1[i].velocity;
        const Vector& old_acceleration_in_t = cont1[i].acceleration;
        
        Vector speedMultiT = old_speed_in_t.ScaleVector(dt);

        double half_dt_squared = 0.5 * dt * dt;

        Vector accMultiT = old_acceleration_in_t.ScaleVector(half_dt_squared);
        
        double newPositon_X = old_position_in_t.get_x() 
                             + speedMultiT.get_x() 
                             + accMultiT.get_x();
                                 
        double newPositon_Y = old_position_in_t.get_y() 
                             + speedMultiT.get_y() 
                             + accMultiT.get_y();
        
        cont2[i].position.set_x(newPositon_X);
        cont2[i].position.set_y(newPositon_Y);
    }
}


void VelocityVerletIntegrator::CalculateNewVelocities(std::vector<PointParticle>& cont1, std::vector<PointParticle>& cont2, double dt)   
{
    double half_dt = 0.5 * dt;

    for (size_t i = 0; i < cont1.size(); ++i) {
        
        const Vector& old_velocity = cont1[i].velocity;
        const Vector& old_acceleration = cont1[i].acceleration;
        const Vector& new_acceleration = cont2[i].acceleration;
        
        double sum_acceleration_x = old_acceleration.get_x() + new_acceleration.get_x();
        double sum_acceleration_y = old_acceleration.get_y() + new_acceleration.get_y();
                                 
        Vector acceleration_sum(sum_acceleration_x, sum_acceleration_y);


        Vector velocity_change = acceleration_sum.ScaleVector(half_dt);

        double new_velocity_x = old_velocity.get_x() + velocity_change.get_x();
        double new_velocity_y = old_velocity.get_y() + velocity_change.get_y();

        cont2[i].velocity.set_x(new_velocity_x);
        cont2[i].velocity.set_y(new_velocity_y);
    }
}




void VelocityVerletIntegrator::run(double dt, double t0, double tMax)
{
   std::vector<PointParticle> container1 = pointParticles;
   std::vector<PointParticle> container2 = pointParticles;

   if (container1.empty()) {
        std::cout << "empty container" << std::endl;
        return;
    }

   container1 = container2;

   CalculateAccelerations(container1);
   
   int steps_per_print = 720; 
   int step_counter = 0;

   for (double t = t0; t < tMax; t += dt) 
   {
        CalculateNewPositions(container1, container2, dt);

        CalculateAccelerations(container2);

        CalculateNewVelocities(container1, container2, dt);

        container1.swap(container2);
 
        step_counter++;
        if (step_counter >= steps_per_print)
        {
          
            std::cout << "Cas: " << (t + dt) / (3600.0 * 24.0) << " dni"
                      << ", Pozice Zeme [x]: " << container1[1].position.get_x() 
                      << ", Pozice Zeme [y]: " << container1[1].position.get_y()
                      << std::endl;
            
            step_counter = 0; 
        }
     
   }
  pointParticles = container1;
}

