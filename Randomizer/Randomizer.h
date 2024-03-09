//
// Created by Roberto Bautista on 08/03/2024.
//

#ifndef EDD_PS2024_RANDOMIZER_H
#define EDD_PS2024_RANDOMIZER_H

const int MAX_RANDOM_NUMBERS = 52;
class Randomizer {
public:
    int randomNums[MAX_RANDOM_NUMBERS];

    void generateRandomNumbers();

    bool isAlreadyUsed(int number);

    int getRandomNumber(int min, int max);

    Randomizer();
};


#endif //EDD_PS2024_RANDOMIZER_H
