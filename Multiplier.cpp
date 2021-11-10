#include "Multiplier.h"
Multiplier::Multiplier() {

}
Multiplier::Multiplier(int n) : ExpressionEvaluator(n) {

}
double Multiplier::Calculate()
{
    double out;
    for (int i = 0; i < numOperands; i++) {
        if(i == 0){
            out = opsArray[0];
        }
        else {
            out *= opsArray[i];
        }
    }
    return out;
}

void Multiplier::LogToScreen()
{
    for (int i = 0; i < numOperands; i++) {
        std::cout << "Op" << i << ", ";
    }
    std::cout << ": ";
    for (int i = 0; i < numOperands; i++) {
        if (opsArray[i] < 0) {
            std::cout << "(" << opsArray[i] << ")";
        }
        else {
            std::cout << opsArray[i];
        }
        if (i != numOperands - 1) {
            std::cout << " * ";
        }
    }
    std::cout << std::endl;
    std::cout << "-> " << Calculate() << std::endl;
}

void Multiplier::LogToFile(const std::string& filename)
{
    std::ofstream writeFile;
    writeFile.open(filename, std::ios::app);
    if (writeFile.is_open()) {
        for (int i = 0; i < numOperands; i++) {
            if (i != numOperands - 1) {
                writeFile << "Op" << i + 1 << ", ";
            }
            else {
                writeFile << "Op" << i + 1;
            }
        }
        writeFile << ": ";
        for (int i = 0; i < numOperands; i++) {
            if (opsArray[i] < 0) {
                writeFile << "(" << opsArray[i] << ")";
            }
            else {
                writeFile << opsArray[i];
            }
            if (i != numOperands - 1) {
                writeFile << " * ";
            }
        }
        writeFile << std::endl;
        writeFile << "-> " << Calculate() << std::endl;
    }
    writeFile.close();
}

std::string Multiplier::getName()
{
    std::string name = name_;
    return name;
}
