//
// Created by Roberto Bautista on 08/03/2024.
//
#include <stdlib.h>
#include "Randomizer.h"

int Randomizer::getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

bool Randomizer::isAlreadyUsed(int number) {
    for (int i = 0; i < MAX_RANDOM_NUMBERS; i++) {
        if (randomNums[i] == number) {
            return true;
        }
    }
    return false;
}

void Randomizer::generateRandomNumbers() {
    for (int & randomNum : randomNums) {
        randomNum = -1;
    }
    for (int & randomNum : randomNums) {
        int random = getRandomNumber(0, MAX_RANDOM_NUMBERS - 1);
        while (isAlreadyUsed(random)) {
            random = getRandomNumber(0, MAX_RANDOM_NUMBERS - 1);
        }
        randomNum = random;
    }
}

Randomizer::Randomizer() {
    generateRandomNumbers();
}
