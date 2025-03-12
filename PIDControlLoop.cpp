#include <iostream>

class PID {
public:
    PID(double kp, double ki, double kd) : Kp(kp), Ki(ki), Kd(kd), prev_error(0), integral(0) {}

    double compute(double setpoint, double measured) {
        double error = setpoint - measured;
        integral += error;
        double derivative = error - prev_error;
        prev_error = error;
        return Kp * error + Ki * integral + Kd * derivative;
    }

private:
    double Kp, Ki, Kd, prev_error, integral;
};

int main() {
    PID pid(1.0, 0.1, 0.05);
    double setpoint = 100, measured = 90;

    for (int i = 0; i < 10; i++) {
        double output = pid.compute(setpoint, measured);
        measured += output * 0.1; // Simulated response
        std::cout << "Iteration " << i << " - Output: " << output << " - Measured: " << measured << std::endl;
    }

    return 0;
}
