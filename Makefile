CPP=g++
CFLAGS=-O3
LDFLAGS=`sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
EXEC=first

all: ${EXEC}

${EXEC}: ${EXEC}.o
	${CPP} $(CFLAGS) -o ${EXEC} ${EXEC}.o ${LDFLAGS}

${EXEC}.o: ${EXEC}.cpp
	${CPP} $(CFLAGS) -o ${EXEC}.o -c ${EXEC}.cpp


clean:  
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}
