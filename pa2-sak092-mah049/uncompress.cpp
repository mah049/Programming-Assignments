#include <iostream>
#include <fstream>
#include <vector>

#include "HCTree.hpp"

using namespace std;

int main ( int argc, char* argv[] ) {
  // valid input check 
  if (argc != 3) {
    cerr<<"Usage: "<<argv[0]<<" infile outfile\n";
    return -1;
  }
  // bit input stream
  ifstream in;
  BitInputStream inStream = BitInputStream(in);
  in.open(argv[1], ios::binary);
  if (!in.is_open()) {
    cerr<<"File could not be opened\n";
    return -1;
  }
  // bit output stream
  ofstream output;
  BitOutputStream outStream = BitOutputStream(output);
  output.open(argv[2],ios::binary);

  in.seekg(0, ios::end);
  int length = in.tellg();
  if (length == 0) {
    output.close();
    in.close();
    return 0;
  }
  in.seekg(0, ios::beg);
  if (length == 1) {
    output.put(in.get());
    output.close();
    in.close();
    return 0;
  }

  // vector for character frequencies
  vector <int> frequencies;
  unsigned char next;
  frequencies = vector <int> (256,0);
  // recreate frequency vector 
  int size = inStream.readInt(); // # unique characters
  int i = 0; // total count
  for (int count=0; count<size; ++count) {
    next = inStream.readByte();
    frequencies[next] = inStream.readInt();
    i += frequencies[next]; // total count
  }
  // rebuild huffman tree
  HCTree* test = new HCTree();
  test->build(frequencies);
  
  // decode and output to file
  for(int count=0; count<i; count++) {
    unsigned char temp = test->decode(inStream);
    if(!in.good()){
      outStream.flush();
    }
    outStream.writeByte(temp);
  }
  output.close();
  in.close();

  return 0;
}
