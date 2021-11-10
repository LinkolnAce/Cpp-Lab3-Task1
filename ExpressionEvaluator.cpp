#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator()
{
	opsArray = new double[20]();
	numOperands = 20;
	
}
ExpressionEvaluator::ExpressionEvaluator(int n){
	while (n <= 0) {
		std::cout << "Input correct amount of operands" << std::endl;
		std::cin >> n;
	}
	
	opsArray = new double[n]();
	numOperands = n;
}

void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	opsArray[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n)
{
	if (n > numOperands) {
		n = numOperands;
	}
	for (size_t i = 0; i < n; i++) {
		opsArray[i] = ops[i];
	}
}



size_t ExpressionEvaluator::getN()
{
	return numOperands;
}

ExpressionEvaluator::~ExpressionEvaluator()
{
	delete opsArray;
}


