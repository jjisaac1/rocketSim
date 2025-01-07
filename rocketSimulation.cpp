#include <iostream>
#include <cmath>
#include <string> 

//Things that still need to be done: precision, fix the altitude error value

double coastingTime(double gravity, double kValue, double massFrame, double burnVelocity); 

int main(){

const double airDensity = 1.226;
const double pressureAtm = 101325;
const double dragCoeff = 0.64; //ansys was used to get value
const double gravity = 9.81; 
const double pi = 2 * asin(1.0);
const double densityWater = 1000; //kg/m^3
const double coeffDischarge = 0.8; //standard for typical bottle nozzle

double massFrame;
double massFlowRate; 
double pressureBottle;
double diaBottle;
double diaNozzle;
double massFuel;
double massTotalChanging;
double veloWater;
double qflow;
std::string startKey;

do{

    std::cout << "\nHow to use the program: \n";
    std::cout << "Given that you have built a rocket, enter the valid parameters that will be asked of below: \n\n";

    std::cout << "*********Rocket Simulation**********\n";
 
    do{
        std::cout << "Mass of rocket frame (kg): ";
        std::cin >> massFrame; 

        std::cin.clear();               
        fflush(stdin);

        if(massFrame <= 0 || massFrame > 2){
            std::cout << "Invalid input, try again \n";  
        }
    }while(massFrame <= 0 || massFrame > 2);


    do{
        std::cout << "Mass of water used (kg): ";
        std::cin >> massFuel;   

        std::cin.clear();               
        fflush(stdin);

        if(massFuel <= 0 || massFuel > 2){
            std::cout << "Invalid input, try again \n";  
        }

    }while(massFuel <= 0 || massFuel > 2);


    do{
        std::cout << "What is the pressure of the bottle (psi): ";
        std::cin >> pressureBottle; 

        std::cin.clear();               
        fflush(stdin);

        if(pressureBottle <= 0 || pressureBottle > 150){
            std::cout << "Invalid input, try again \n";  
        }
    }while(pressureBottle <= 0 || pressureBottle > 150);

    pressureBottle = pressureBottle * 6894.76;


    do{
        std::cout << "Diameter of the bottle (m): ";
        std::cin >> diaBottle; 

        std::cin.clear();               
        fflush(stdin);

        if(diaBottle <= 0 || diaBottle > 1){
            std::cout << "Invalid input, try again \n";  
        }

    }while(diaBottle <= 0 || diaBottle > 1);


    do{
        std::cout << "Diameter of the nozzle (m): ";
        std::cin >> diaNozzle; 

        std::cin.clear();               
        fflush(stdin);

        if(diaNozzle <= 0 || diaNozzle > 0.05){
            std::cout << "Invalid input, try again \n";  
        }

    }while(diaNozzle <= 0 || diaNozzle > 0.05);


std::cout << "****************************\n\n";
std::cout << "*************Data***********\n";


    double areaBottle = pi * pow(diaBottle,2) / 4;
    double areaNozzle = pi * pow(diaNozzle,2) / 4;

std::cout << "Crosssection area of the bottle: " << areaBottle << '\n';
std::cout << "Crosssection area of the nozzle: " << areaNozzle << '\n';
std::cout << "Drag coefficient of the rocket: " << dragCoeff << '\n';
std::cout << "Air density: " << airDensity << '\n'; 

    double massTotal = massFrame + massFuel;
    double massTotalChanging = massFrame + massFuel - massFuel / 2;

std::cout << "Total mass of the rocket + fuel: " << massTotal << '\n';

    veloWater = coeffDischarge * sqrt(2 * (pressureBottle - pressureAtm) / densityWater);
    qflow = areaNozzle * veloWater;
    massFlowRate = qflow * 1000;

std::cout << "The mass flow rate is: " << massFlowRate << '\n';

    double kValue = 0.5 * airDensity * dragCoeff * areaBottle;

    double thrust = massFlowRate * veloWater + (pressureBottle - pressureAtm) * areaNozzle;
    double impulse = massTotalChanging * (veloWater + (pressureBottle - pressureAtm) * areaNozzle / massFlowRate);
    double burnTime = impulse / thrust; 

std::cout << "Thrust of the rocket initial: " << thrust << '\n'; 
std::cout << "Impulse of the rocket initial: " << impulse << '\n'; 

    double qValue = (sqrt(thrust -  massTotalChanging)) / kValue;
    double xValue = 2 * (kValue * qValue / massTotalChanging);

    double burnVelocity = qValue * (1 - exp(-xValue * burnTime)) / (1 +  exp(-xValue * burnTime));

    double burnAlt = (-massTotalChanging / 2 * kValue) * log((thrust - massTotalChanging * gravity - kValue * pow(burnVelocity, 2) / thrust - massTotalChanging * gravity));
    double coastingAlt = (massFrame / 2* kValue) * log((massFrame * gravity + kValue * pow(burnVelocity, 2) / massFrame * gravity));
    double totalAlt = (burnAlt + coastingAlt) * 10000;

std::cout << "Total altitude reached (m): " << totalAlt << '\n'; 
std::cout << "Average velocity during propulsion phase: " << burnVelocity << '\n'; 
std::cout << "Average velocity of the water leaving the nozzle: " << veloWater << '\n'; 


    double totalFlightTime = coastingTime(gravity, kValue, massFrame, burnVelocity) + burnTime;

std::cout << "Flight time to apogee: " << totalFlightTime << '\n'; 
std::cout << "****************************\n\n";

do{ 
    std::cout << "Type (start) to continue or (exit) to leave: ";
    std::getline(std::cin >> std::ws, startKey); 

    std::cin.clear();               
    fflush(stdin);

    if(startKey != "start" && startKey != "Start" && startKey != "exit" && startKey != "Exit"){
        std::cout << "Invalid input, try again. \n";
    }
}while(startKey != "start" && startKey != "Start" && startKey != "exit" && startKey != "Exit"); 


}while(startKey == "start" || startKey == "Start");

std::cout << "Simulation concluded \n"; 

return 0;
}



//mass of the propellant added to the bottle which adds to mass total
double coastingTime(double gravity, double kValue, double massFrame, double burnVelocity){

double qAvalue = sqrt(massFrame * gravity / kValue);
double qBvalue = sqrt(gravity * kValue / massFrame);
double coastingTime = atan(burnVelocity / qAvalue) / qBvalue;

return coastingTime;

}


