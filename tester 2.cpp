    #include <iostream>
    #include <cmath>

    int main(){

        double burnAlt;
        double coastingAlt;
        double totalAlt; 

    double burnAlt = (-0.550 / 2 * 0.29) * log((13.1 - 0.550 * 9.81 - 0.29 * pow(12.3, 2) / 13.1 - 0.550 * 9.81));
    double coastingAlt = (0.25 / 2* 0.29) * log((0.25 * 9.81 + 0.29 * pow(12.3, 2) / 0.25 * 9.81));
    double totalAlt = burnAlt + coastingAlt;

    std::cout << totalAlt; 


        return 0;
    }
