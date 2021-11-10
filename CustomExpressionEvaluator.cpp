#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"

CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator() {

}
CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {

}
double CustomExpressionEvaluator::Calculate()
{
    double out;
    for (int i = 0; i < numOperands; i++) {
        if (i == 0) {
            out = opsArray[0] / (i+1);
        }
        else {
            out -= opsArray[i] / (i+1);
        }
    }
    return out;
}

void CustomExpressionEvaluator::LogToScreen()
{
    for (int i = 0; i < numOperands; i++) {
        if (i != numOperands - 1) {
            std::cout << "Op" << i + 1 << ", ";
        }
        else {
            std::cout << "Op" << i + 1;
        }
    }
    std::cout << ": ";
    for (int i = 0; i < numOperands; i++) {
        if (opsArray[i] < 0) {
            std::cout << "(" << opsArray[i] << ")" << "/" << i+1;
        }
        else {
            std::cout << opsArray[i] << "\\" << i+1 ;
        }
        if (i != numOperands - 1) {
            std::cout << " - ";
        }
    }
    std::cout << std::endl;
    std::cout << "-> " << Calculate() << std::endl;
}

void CustomExpressionEvaluator::LogToFile(const std::string& filename)
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
                writeFile << "(" << opsArray[i] << ")" << "/" << i + 1;
            }
            else {
                writeFile << opsArray[i] << "\\" << i + 1;
            }
            if (i != numOperands - 1) {
                writeFile << " - ";
            }
        }
        writeFile << std::endl;
        writeFile << "-> " << Calculate() << std::endl;
    }
    writeFile.close();
}

std::string CustomExpressionEvaluator::getName()
{
    return std::string();
}
