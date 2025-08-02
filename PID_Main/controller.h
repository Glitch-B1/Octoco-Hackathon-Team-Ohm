//
// Created by becke on 2025/08/02.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H



class Controller {

public:
    Controller();
    void simulate(double const kpNew, double const kiNew, double const kdNew, double const start, double const end) {
        position = start;
        destination = end;
        kp = kpNew; kd = kdNew; ki = kiNew;
        timestep = 0;
        while (timestep < 1500) {
            update();
            timestep ++;
        }
    };


    void simulateP(double const kpNew, double const kiNew, double const kdNew, double const start, double const end) {
        position = start;
        destination = end;
        if (kpNew < 0) kp = 0;
        if (kdNew < 0) kd = 0;
        if (kiNew < 0) ki = 0;
        if (kiNew > 1) ki = 1;
        if (kpNew > 1) kp = 1;
        if (kdNew > 1) kd = 1;

        kp = (kpNew * 17) + 5;
        kd = (kdNew * 4) + 1.1;
        ki = kiNew * 5;


        timestep = 0;
        while (timestep < length) {
            update();
            timestep ++;
        }
    };


    void output(double * destination) {
        for (int i = 0; i < length/2; ++i) {
            destination[i] = previousPositions[2*i];
        }

    }

protected:

    static const int length = 300;
    const double mass = 1;
    double friction{1};
    double destination{60};
    double position{20};
    double velocity{0};
    double acceleration{0};
    double cumulative{0};
    double lastError{0};

    double kp{5}, ki{1}, kd{1.1};
    double dt {0.01};


    int timestep{0};
    double previousPositions [length] {0};


    void update() {
        double error = destination - position;

        double proportional = error * kp;
        cumulative += error * dt;
        double integral = cumulative * ki;

        double d_error = (error - lastError) / dt;
        double derivative = kd * d_error;

        double force = proportional + integral + derivative - friction * velocity;

        acceleration = force / mass;
        velocity += acceleration * dt;
        position += velocity * dt;

        previousPositions[timestep] = position;
        //previousVelocities[timestep] = velocity;
        //previousAccelerations[timestep] = acceleration;

        lastError = error;
    }




};




#endif //CONTROLLER_H
