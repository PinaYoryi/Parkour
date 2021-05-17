#include <iostream>
#include <PinaMotor.h>

#include "ComponentFactoryRegistration.h"

#include "Lifetime.h"
#include "DroneAI.h"
#include "ShootingAI.h"
#include "DronMissile.h"
#include "Floor.h"

#if (defined _DEBUG)
#include <crtdbg.h>
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
#else
#include <windows.h>
int WINAPI
WinMain(HINSTANCE zhInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif
    std::cout << "Hello World!\n";
    ComponentFactoryRegistrations::ComponentFactoryRegistration<Lifetime>("lifetime");
    ComponentFactoryRegistrations::ComponentFactoryRegistration<Floor>("floor");
    ComponentFactoryRegistrations::ComponentFactoryRegistration<DroneAI>("droneai");
    ComponentFactoryRegistrations::ComponentFactoryRegistration<ShootingAI>("shotai");
    ComponentFactoryRegistrations::ComponentFactoryRegistration<DronMissile>("dronmissile");
    PinaMotor motor;
    motor.init("Test");

    motor.launch("startscene.lua");

    motor.close();
}