<img src="gobots.jpg" alt="Barrage" width="140" height="140">
Pathfinder
=======
Pathfinder is a pattern matching routing library for HTTP URIs. Pathfinder will be the next generation routing library for [Haywire](https://github.com/kellabyte/haywire) once complete. Since pattern matching and parsing URIs is a fairly generic thing I decided to extract what will be my latest work into its own library.

## Goals
The goals for Pathfinder is similar to those for Haywire. The goal is to route URIs as fast as possible with as little resources as possible.

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
