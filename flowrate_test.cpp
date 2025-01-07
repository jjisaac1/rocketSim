    #include <iostream>
    #include <cmath>

    int main(){
        double pressureBottle;
        const double pressureAtm = 101325;
        double nozzleDia;
        const double densityWater = 1000; //kg/m^3
        const double coeffDischarge = 0.8; //standard for typical bottle nozzle
        double vWater;
        double areaNozzle = 0.0000785;
        double qflow;
        double massFlowRate;
        const double pi = 2 * asin(1.0);

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

    vWater = coeffDischarge * sqrt(2 * (pressureBottle - pressureAtm) / densityWater);
    qflow = areaNozzle * vWater;
    massFlowRate = qflow * 1000;

    std::cout << massFlowRate; 


        return 0;
    }