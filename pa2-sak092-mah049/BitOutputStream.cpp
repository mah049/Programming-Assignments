#include <iostream>
#include "BitOutputStream.hpp"

using namespace std;
// write bits from buffer to output stream
void BitOutputStream::writeBit(int bit){
  if(this->bufi == 8){
    this->flush();
  }

  this->buf = this->buf | ((bit&1)<<this->bufi);
  bufi++;
}
// write lowest byte of int to output stream
void BitOutputStream::writeByte(int b){
  //byte is 8 bits
  unsigned char toStore = 0;
  //ints are 32 bits we want the least sig
  unsigned int byteHolder = b & 0x000000FF;
  toStore |= byteHolder;
  out.put(toStore);
}
// write int to output stream
void BitOutputStream::writeInt(int i){
  unsigned int temp = i;
  out.write((char*)&temp, sizeof(temp));
}
