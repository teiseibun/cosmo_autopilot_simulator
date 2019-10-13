EXECUTABLE=cas

LDFLAGS=

SRC=main.cpp \
	fg_link.cpp

CFLAGS=-I./

all:
	g++ $(LDFLAGS) -o $(EXECUTABLE) $(CFLAGS) $(SRC)

clean:
	rm  $(EXECUTABLE)

install_protocol:
	cp binary-protocol.xml /usr/share/games/flightgear/Protocol

