#pragma once
#include "ILoggable.h"
#include "IShuffle.h"
#include <iostream>



class ExpressionEvaluator : public ILoggable
{
public:
	ExpressionEvaluator();
	ExpressionEvaluator(int n);
	
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);


	virtual double Calculate() = 0;

	size_t getN();

	virtual ~ExpressionEvaluator();

protected:
	size_t numOperands;
	double* opsArray;
};

