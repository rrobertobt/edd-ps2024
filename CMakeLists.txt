cmake_minimum_required(VERSION 3.27)
project(edd_ps2024)

set(CMAKE_CXX_STANDARD 17)

add_executable(edd_ps2024 main.cpp
        Structures/Stack/Stack.h
        Structures/Card/Card.cpp
        Structures/Card/Card.h
        Structures/Stack/Stack.cpp
        Structures/Queue/Queue.cpp
        Structures/Queue/Queue.h
        CardsHandler/CardsHandler.cpp
        CardsHandler/CardsHandler.h
        Structures/List/LinkedList.cpp
        Structures/List/LinkedList.h
        MainGame.cpp
        MainGame.h
        Randomizer/Randomizer.cpp
        Randomizer/Randomizer.h)
