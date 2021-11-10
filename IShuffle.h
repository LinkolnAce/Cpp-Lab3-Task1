#pragma once
class IShuffle {
public:
	virtual void Shuffle() = 0;
	virtual void Shuffle(size_t i, size_t j) = 0;


};