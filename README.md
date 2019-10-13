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
fgfs --generic=socket,in,1,,10540,udp,binary-protocol
```

second terminal:

```
./cas
```
