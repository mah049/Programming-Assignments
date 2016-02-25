#include <iostream>
#include <fstream>
#include <vector>

#include "HCTree.hpp"

using namespace std;

int main( int argc, char* argv[] ) {
  // valid input check 
  if (argc != 3) {
    cerr<<"Usage: "<<argv[0]<<" infile outfile\n";
    return -1;
  }
  // open file input stream
  ifstream in (argv[1], ios::binary);
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

  vector <int> frequencies;
  unsigned char next;
  int uniqueSymbols = 0; // keep track of how many unique characters
  // vector for frequency of characters
  frequencies = vector <int> (256,0);
  // read in characters from input file
  while (1) {
    next = in.get();
    if (!in.good()) break; // failure or eof
    if (frequencies[next] == 0)
      uniqueSymbols++;
    frequencies[next] += 1;
  }
  if (!in.eof()) {
    cerr<<"There was a problem with the file."<<endl;
    return -1;
  }
  in.close();
  // build huffman tree
  HCTree* test = new HCTree();
  test->build(frequencies);
  
  // write out header
  outStream.writeInt(uniqueSymbols);
  for (unsigned int index=0; index<frequencies.size(); index++){
    if(frequencies[index]!=0){
      outStream.writeByte(index);
      outStream.writeInt(frequencies[index]);
    }
  }
  // encode and write to output file
  in.open(argv[1],ios::binary);
  unsigned char c;
  while(1){
    c = in.get();
    if(!in.good()){
      outStream.flush();
      break;
    }
    test->encode(c,outStream);
  }
  if (!in.eof()) {
    cerr<<"File is bad\n";
    return -1;
  }
  output.close();
  in.close();

  return 0;
}
