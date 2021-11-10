#include "Summator.h"

Summator::Summator() : ExpressionEvaluator() {

}
Summator::Summator(int n) : ExpressionEvaluator(n) {

}
double Summator::Calculate() {
    double out;
    for (int i = 0; i < numOperands; i++) {
        if (i == 0) {
            out = opsArray[0];
        }
        else {
            out += opsArray[i];
        }
    }
    return out;
}
void Summator::LogToScreen() {
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
            std::cout << "(" << opsArray[i] << ")";
        }
        else {
            std::cout << opsArray[i];
        }
        if (i != numOperands - 1) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
    std::cout << "-> " << Calculate() << std::endl;
}

void Summator::LogToFile(const std::string& filename)
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
                writeFile << " + ";
            }
        }
        writeFile << std::endl;
        writeFile << "-> " << Calculate() << std::endl;
    }
    writeFile.close();
}

void Summator::Shuffle()
{
    int count = 0;
    double tmp;
    int z, y;
    double* minusArr = new double[getN()]; // массив которые собирает номера отрицательных чисел
    for (int i = 0; i < getN(); i++) {
        if (opsArray[i] < 0)  {
            minusArr[count++] = i;
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = 1; j < count; j++) {
            z = minusArr[j];
            y = minusArr[j - 1];
            if ((int)opsArray[z] < (int)opsArray[y]) {
                tmp = opsArray[z];
                opsArray[z] = opsArray[y];
                opsArray[y] = tmp;
            }
        }
    }
}

void Summator::Shuffle(size_t start, size_t finish)
{
    int count = 0;
    double tmp;
    int z, y;
    double* minusArr = new double[getN()]; // массив которые собирает номера отрицательных чисел
    for (int i = start; i < finish; i++) {
        if (opsArray[i] < 0) {
            minusArr[count++] = i;
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = 1; j < count; j++) {
            z = minusArr[j];
            y = minusArr[j - 1];
            if ((int)opsArray[z] < (int)opsArray[y]) {
                tmp = opsArray[z];
                opsArray[z] = opsArray[y];
                opsArray[y] = tmp;
            }
        }
    }
}

std::string Summator::getName()
{
    std::string name = name_;
    return name;
}
