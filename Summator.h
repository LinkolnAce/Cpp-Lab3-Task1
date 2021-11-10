#pragma once
#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator, public IShuffle
{
public:
	Summator();
	Summator(int n);

	double Calculate() override;
	void LogToScreen() override;
	void LogToFile(const std::string& filename) override;

	void Shuffle();
	void Shuffle(size_t i, size_t j);

	std::string getName();
private:
	std::string name_ = "Summator";

};

