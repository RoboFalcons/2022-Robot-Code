// uses joysticks or buttons to turn on and off the motors

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

frc::XboxController m_controller{0};
frc::Timer m_timer;
// Names variables and initiallizes within robot() and private:


void teleoperatedInit() override {
    m_timer.Reset;
    m_timer.Start;
}

void teleoperatedPeriodic() override {
    if (joystick.GetRawButtonPressed(0)) {
        m_robotDrive.ArcadeDrive(0.75, 0.0, false);
    }else {
        m_robotDrive.ArcadeDrive(0.0, 0.0, false);
    }
}

//or
void teleoperatedPeriodic() override {
    
if (m_controller) >= .01 {
m_robotDrive.ArcadeDrive(0.9, 0.0, false);
    }else {
        m_robotDrive.ArcadeDrive(0.0, 0.0, false);
    }
}