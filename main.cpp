
#include"Summator.h"
#include"Multiplier.h"
#include"CustomExpressionEvaluator.h"

int main() {
	
	std::string path = "log.txt";

	ExpressionEvaluator* evaluator[3];
	
	evaluator[0] = new CustomExpressionEvaluator(6);
	double arr2[6] = { 5, 16, -3, 10, 12 };
	evaluator[0]->setOperands(arr2, 6);

	evaluator[1] = new Summator(2);
	evaluator[1]->setOperand(0, 39.1);
	evaluator[1]->setOperand(1, -12.7);
	
	evaluator[2] = new Multiplier(4);
	double arr[4] = { -4.5, 2, 3, -10 };
	evaluator[2]->setOperands(arr, 4);

	for (auto& eval : evaluator) {
		eval->LogToFile(path);
		eval->LogToScreen();
	}

	for (auto& eval : evaluator) {
		IShuffle* shufflable = dynamic_cast<IShuffle*>(eval);
		if (shufflable != nullptr) {
			std::cout << "Before shuffling: " << std::endl;
			eval->LogToScreen();
			shufflable->Shuffle();
			std::cout << "After shuffling: " << std::endl;
			eval->LogToScreen();
		}
	}


	

	
	
	return 0;
}