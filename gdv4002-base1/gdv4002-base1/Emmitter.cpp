#include "Emmitter.h"
#include "asteroids.h"
#include "Engine.h"

using namespace std;

Emmitter::Emmitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval)
    : GameObject2D(initPosition, 0.0f, initSize, 0)
{
    this->emitTimeInterval = emitTimeInterval;
    emitCounter = emitTimeInterval;
    particleNumber = 0;

    for (int i = 0; i < 8; i++) {
        string filename = "resources\\textures\\asteroid" + to_string(i) + ".png";
        asteroidTextures[i] = loadTexture(filename.c_str());
        if (asteroidTextures[i] > 0) {
            printf("Loaded texture: %s with ID %u\n", filename.c_str(), asteroidTextures[i]);
        }
        else {
            fprintf(stderr, "Failed to load texture: %s\n", filename.c_str());
        }
    }

    // Initialize random number generator
    random_device rd;
    gen = mt19937(rd());

    // Random number distributions
    spriteDist = uniform_int_distribution<int>(0, 7);
    normDist = uniform_real_distribution<float>(-1.0f, 1.0f);
    scaleDist = uniform_real_distribution<float>(0.05f, 0.2f);
    massDist = uniform_real_distribution<float>(0.005f, 0.08f);
}

// Override render but do nothing
void Emmitter::render() {}

void Emmitter::update(double tDelta)
{
    emitCounter += static_cast<float>(tDelta);

    while (emitCounter >= emitTimeInterval) {
        emitCounter -= emitTimeInterval;

        float x = position.x + normDist(gen) * size.x;
        float y = position.y + normDist(gen) * size.y;
        float scale = scaleDist(gen);
        float mass = massDist(gen);
        float rotationSpeed = glm::radians(normDist(gen) * 45.0f);
        int spriteIndex = spriteDist(gen);

        auto newasteroid = new asteroids(
            glm::vec2(x, y),
            normDist(gen) * glm::radians(360.0f),
            glm::vec2(scale, scale),
            asteroidTextures[spriteIndex],
            mass,
            glm::vec2(normDist(gen) * 0.5f, normDist(gen) * 0.5f),
            rotationSpeed
        );

        string key = "asteroid";
        if (particleNumber > 0) {
            key += to_string(particleNumber);
        }

        particleNumber++;
        addObject(key.c_str(), newasteroid);
    }
}
