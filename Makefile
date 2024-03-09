CPP = g++
TARGET = program

all: .all-post

.all-post: CardsHandler.o Randomizer.o Card.o LinkedList.o Queue.o Stack.o MainGame.o main.o
	$(CPP) CardsHandler.o Randomizer.o Card.o LinkedList.o Queue.o Stack.o MainGame.o main.o -o $(TARGET)

CardsHandler.o: ./CardsHandler/CardsHandler.cpp ./CardsHandler/CardsHandler.h
	$(CPP) -c ./CardsHandler/CardsHandler.cpp

Randomizer.o: ./Randomizer/Randomizer.cpp ./Randomizer/Randomizer.h
	$(CPP) -c ./Randomizer/Randomizer.cpp

Card.o: ./Structures/Card/Card.cpp ./Structures/Card/Card.h
	$(CPP) -c ./Structures/Card/Card.cpp

LinkedList.o: ./Structures/List/LinkedList.cpp ./Structures/List/LinkedList.h
	$(CPP) -c ./Structures/List/LinkedList.cpp

Queue.o: ./Structures/Queue/Queue.cpp ./Structures/Queue/Queue.h
	$(CPP) -c ./Structures/Queue/Queue.cpp

Stack.o: ./Structures/Stack/Stack.cpp ./Structures/Stack/Stack.h
	$(CPP) -c ./Structures/Stack/Stack.cpp

MainGame.o: MainGame.cpp MainGame.h
	$(CPP) -c MainGame.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

main.o: main.cpp

clean:
	rm -rf *.o