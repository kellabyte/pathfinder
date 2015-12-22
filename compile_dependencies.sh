#!/bin/bash
cwd=$(pwd)
unamestr=$(uname)
sudo="sudo"

if [[ "${unamestr}" =~ "CYGWIN" ]] ; then
  # no need for sudo in a Cygwin environment
  sudo=""
fi

scons=$(command -v scons)
cmake=$(command -v cmake)
if [[ $scons == "" || $cmake == "" ]]
then
  echo "ERROR: scons and cmake not found"
  echo "Pathfinder requires these programs for compilation"
  exit
fi

if [ ! -d "${cwd}/lib" ]; then
  mkdir ${cwd}/lib
fi

if [ ! -d "${cwd}/lib/check-0.10.0" ]; then
  cd ${cwd}/lib
  wget -O check.tar.gz http://sourceforge.net/projects/check/files/latest/download
  tar xzf check.tar.gz
  cd check-0.10.0
  ./configure
  make
  cd ${cwd}
fi

# Getting libart
if [ ! -d "$(cwd)/lib/libart" ]; then
  echo "git clone https://github.com/armon/libart.git ${cwd}/lib/libart"
  git clone https://github.com/armon/libart.git ${cwd}/lib/libart
  cd ${cwd}/lib/libart/deps/check-0.9.8/
  ./configure
  make
  ${sudo} make install
  cd ${cwd}/lib/libart
  scons
  cd ${cwd}
fi
