//
// Created by Roberto Bautista on 08/03/2024.
//

#include "MainGame.h"

void MainGame::startPlaying() {
    cardHandler->prepareGame();
    cardHandler->showMainGame();
    cardHandler->handleUserChoice();
//    cardHandler->printCardsArray();
}
