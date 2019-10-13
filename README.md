# Cosmo Autopilot Simulator

## Prerequisite

FlightGear:

```
sudo add-apt-repository ppa:saiarcot895/flightgear
sudo apt-get update
sudo apt install flightgear
```

## Build Cosmo

```
cd sim/
make
```

## Run

first terminal:

```
fgfs --timeofday=morning --geometry=640x480 --generic=socket,in,1,,6789,udp,binary-protocol
```

second terminal:

```
./cas
```
