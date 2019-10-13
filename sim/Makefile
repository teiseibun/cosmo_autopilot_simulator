EXECUTABLE=cas

LDFLAGS=

SRC=main.cpp \
	fg_link.cpp

CFLAGS=-I./

all:
	g++ $(LDFLAGS) -o $(EXECUTABLE) $(CFLAGS) $(SRC)

clean:
	rm  $(EXECUTABLE)

launch:
	fgfs --timeofday=morning --geometry=640x480 --generic=socket,in,1,,6789,udp,fgfs_input \
	     --generic=socket,out,40,localhost,6666,udp,fgfs_output

install_protocol:
	cp protocol/fgfs_input.xml /usr/share/games/flightgear/Protocol
	cp protocol/fgfs_output.xml /usr/share/games/flightgear/Protocol


