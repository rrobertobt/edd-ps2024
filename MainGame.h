//
// Created by Roberto Bautista on 08/03/2024.
//

#ifndef EDD_PS2024_MAINGAME_H
#define EDD_PS2024_MAINGAME_H
#include "./CardsHandler/CardsHandler.h"


class MainGame {
    CardsHandler *cardHandler = new CardsHandler();

public:
    void startPlaying();

};


#endif //EDD_PS2024_MAINGAME_H
