#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/Timer/h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/phoenix/motorcontrol/can/PWMSparkMax.h>

public: 
Robot() {
    m_right.SetInverted(true);
    m_roboDrive.SetExpiration(100_ms);
    //invert 1 side to have the same voltages to move forward at the same polarity
    m_timer.Start();

}

private:
// robot drive system
ctre::phoenix::motorcontrol::can::PWMSparkMax.h m_left{1};
ctre::phoenix::motorcontrol::can::PWMSparkMax.h m_right{2};
frc::differentialDrive m_robotDrive{m_left, m_right};

frc::Joystick m_stick{0};
frc::Timer m_timer;
// Names variables and initiallizes within robot() and private:

void RobotInit() {}

void AutonomousInit() override {
    m_timer.Reset();
    m_timer.Start();
}

void AutonomousPeriodic() override {
    //drive 2 sec
    if (m_timer.Get() < 2_s) {
        m_robotdrive.ArcadeDrive(0.5, 0.0, false);
    }else {
        //stop robot
        m_robotDrive.ArcadeDrive(0.0, 0.0, false);
    }
}
