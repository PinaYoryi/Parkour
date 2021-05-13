#include <iostream>
#include <PinaMotor.h>
int main()
{
    std::cout << "Hello World!\n";
    PinaMotor motor;
    motor.init("Test");

    motor.launch("myscript.lua");

    motor.close();
}