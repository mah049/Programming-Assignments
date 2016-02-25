#include <iostream>

#include "BitInputStream.hpp"

using namespace std;
// read byte into buffer and output each bit
int BitInputStream::readBit(){
  if(this->bufi == 8){
    this->buf= in.get();
    this->bufi = 0;
  }

  int retVal = 0;
  retVal = (this->buf)>>this->bufi & 1;
  bufi++;

  return retVal;
}
// read byte from input stream
unsigned char BitInputStream::readByte(){
  return in.get();
}
// read int from input stream
int BitInputStream::readInt(){
  int temp;
  in.read((char*)&temp, sizeof(temp));
  return temp;
}
