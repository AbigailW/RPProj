
CC = clang++
CFLAGS = -Wall -std=c++11
LDFLAGS = -lrt
OBJECTS = main.o Armor.o Container.o Campaign.o Character.o Helper.o Item.o DataTypes.o
#replace this if you want to change the output name
TARGET = test.out

#default is to compile
default: compile

compile: ${TARGET}

Armor.h: Item.h DataTypes.h

Armor.o: Armor.cpp Item.h Armor.h Helper.h
	${CC} ${CFLAGS} -c Armor.cpp

Container.h: Item.h

Container.o: Container.cpp Item.h Container.h
	${CC} ${CFLAGS} -c Container.cpp

Campaign.h: Character.h Armor.h

Campaign.o: Campaign.cpp Campaign.h Character.h Armor.h Helper.h Item.h Container.h
	${CC} ${CFLAGS} -c Campaign.cpp

Character.h: Item.h Container.h DataTypes.h

Character.o: Character.cpp Character.h Helper.h
	${CC} ${CFLAGS} -c Character.cpp

DataTypes.o: DataTypes.cpp DataTypes.h
	${CC} ${CFLAGS} -c DataTypes.cpp

Helper.h: DataTypes.h

Helper.o: Helper.cpp Helper.h
	${CC} ${CFLAGS} -c Helper.cpp

Item.h: DataTypes.h

Item.o: Item.cpp Item.h Helper.h
	${CC} ${CFLAGS} -c Item.cpp

main.o: main.cpp Character.h Armor.h Helper.h Campaign.h
	${CC} ${CFLAGS} -c main.cpp

${TARGET}: ${OBJECTS}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJECTS} ${LDFLAGS}

clean:
	rm *.o ${TARGET}