#pragma once
#include "ExpressionEvaluator.h"
class CustomExpressionEvaluator : public ExpressionEvaluator
{
public:
	CustomExpressionEvaluator();
	CustomExpressionEvaluator(int n);

	double Calculate() override;
	void LogToScreen() override;
	void LogToFile(const std::string& filename) override;

	std::string getName();
private:
	std::string name_ = "CustomExpressionEvaluator";
};

