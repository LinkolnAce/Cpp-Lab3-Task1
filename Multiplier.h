#pragma once
#include "ExpressionEvaluator.h"
class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier();
	Multiplier(int n);

	double Calculate() override;
	void LogToScreen() override;
	void LogToFile(const std::string& filename) override;

	std::string getName();
private:
	std::string name_ = "Summator";

};

