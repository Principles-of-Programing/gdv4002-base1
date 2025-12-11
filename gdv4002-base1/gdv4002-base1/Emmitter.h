#pragma once
#include "GameObject2D.h"
#include <random>
class Emmitter : public GameObject2D

{
private:
	float emitTimeInterval;
	float emitCounter;
	unsigned long long particleNumber; //monotonically increasing particle index index / number used to set key

	GLuint asteroids[8];
	//random number generation
	std::mt19937 gen;

	//random number distributions
	std::uniform_int_distribution<int> spriteDist;
	std::uniform_real_distribution<float> normDist; 
	std::uniform_real_distribution<float> scaleDist;
	
public:
	Emmitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval);
	void update(double tDelta) override;
	void render() override;
};

