#include <iostream>
#include <string> 

int main() 
{


double massFrame;
double massFlowRate = 4; //ansys to get value
double pressureBottle;
double diaBottle;
double diaNozzle;
double massFuel;
std::string startKey;
do{

    std::cout << "How to use the program: \n";
    std::cout << "Given that you have built a rocket, enter the valid parameters that will be asked of below: \n\n";

    std::cout << "*********Rocket Simulation**********\n";
 
    do{
        std::cout << "Mass of rocket frame (kg): ";
        std::cin >> massFrame; 

        std::cin.clear();               
        fflush(stdin);

        if(massFrame <= 0 || massFrame > 10){
            std::cout << "Invalid input, try again \n";  
        }
    }while(massFrame <= 0 || massFrame > 10);


    do{
        std::cout << "Mass of water used (kg): ";
        std::cin >> massFuel;   

        std::cin.clear();               
        fflush(stdin);

        if(massFuel <= 0 || massFuel > 10){
            std::cout << "Invalid input, try again \n";  
        }

    }while(massFuel <= 0 || massFuel > 10);


    do{
        std::cout << "Pressure of bottle pumped to (<80psi): ";
        std::cin >> pressureBottle; 

        std::cin.clear();               
        fflush(stdin);

        if(pressureBottle <= 0 || pressureBottle > 200){
            std::cout << "Invalid input, try again \n";  
        }

    }while(pressureBottle <= 0 || pressureBottle > 200);


    do{
        std::cout << "Diameter of the bottle (m): ";
        std::cin >> diaBottle; 

        std::cin.clear();               
        fflush(stdin);

        if(diaBottle <= 0 || diaBottle > 10){
            std::cout << "Invalid input, try again \n";  
        }

    }while(diaBottle <= 0 || diaBottle > 10);


    do{
        std::cout << "Diameter of the nozzle (m): ";
        std::cin >> diaNozzle; 

        std::cin.clear();               
        fflush(stdin);

        if(diaNozzle <= 0 || diaNozzle > 5){
            std::cout << "Invalid input, try again \n";  
        }

    }while(diaNozzle <= 0 || diaNozzle > 5);

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

return 0;

}
