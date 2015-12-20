<img src="gobots.jpg" alt="Barrage" width="140" height="140">
Pathfinder
=======
Pathfinder is a pattern matching routing library for HTTP URI's. Pathfinder will be the next generation routing library for [Haywire](https://github.com/kellabyte/haywire) once complete. Since pattern matching and parsing URI's is a fairly generic thing I decided to extract what will be my latest work into it's own library.

## Goals
The goals for Pathfinder is similar to Haywire. The goal is to route URI's as fast as possible with as little resources as possible.

## Requirements
#### Ubuntu
```
sudo apt-get install cmake scons
```
#### Mac OSX
```
xcode-select --install
brew install cmake scons
```
## Building
```
./make.sh
```

## Running tests
```
./build/test
```
