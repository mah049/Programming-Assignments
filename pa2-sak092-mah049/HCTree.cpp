#include <iostream>
#include <algorithm>
#include <vector>

#include "HCTree.hpp"

using namespace std;
/** Use the Huffman algorithm to build a Huffman coding trie.
 *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
 *  the frequency of occurrence of byte i in the message.
 *  POSTCONDITION:  root points to the root of the trie,
 *  and leaves[i] points to the leaf node containing byte i.
 */
void HCTree::build(const vector<int>& freqs){
  // heap data structure for huffman tree
  priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pQueue;
  // create initial forrest 
  for (unsigned int i=0; i<freqs.size(); i++){
    if(freqs[i]!=0){
      HCNode* temp = new HCNode(freqs[i], (unsigned char)i);
      this->leaves[i] = temp;
      pQueue.push(temp);
    }
  }
  // temp vars for top two we pop off
  HCNode* holderOne;
  HCNode* holderTwo;
  unsigned char temp;
  // creating the huffman tree
  while (pQueue.size()>1){
    // take off top two
    holderOne = pQueue.top();
    pQueue.pop();
    holderTwo = pQueue.top();
    pQueue.pop();
    // figure out which symbol for new parent
    temp = (holderOne->symbol>holderTwo->symbol) ? holderOne->symbol : holderTwo->symbol;
    HCNode* parent = new HCNode(holderOne->count + holderTwo->count,temp);
    // stick them into the tree and stick root back in
    parent->c0 = holderOne;
    parent->c1 = holderTwo;
    holderOne->p = parent;
    holderTwo->p = parent;
    pQueue.push(parent);
  }
  // which one is root
  this->root = pQueue.top();
  //root->print();
}

/** Write to the given BitOutputStream
 *  the sequence of bits coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
void HCTree::encode(byte symbol, BitOutputStream& out) const {
  HCNode* node = this->leaves[symbol];
  if(node == this->root){
    return;
  }
  // work way back up tree
  vector<int> temp;
  while (node != this->root) {
    if(node->p->c1 == node){
      temp.push_back(1);
    }
    else{
      temp.push_back(0);
    } 
    node = node->p;
  }
  // need to reverse bits to get correct encoding
  reverse(temp.begin(), temp.end());
  // write bits out
  for (auto it=temp.begin(); it!=temp.end(); ++it) 
    out.writeBit(*it);
}

/** Return symbol coded in the next sequence of bits from the stream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
int HCTree::decode(BitInputStream& in) const{
  HCNode * holder = this->root;
  int nextBit = 0;
  // using bits to go down tree, decoding
  while(holder->c0 != 0 || holder->c1 != 0){
    nextBit = in.readBit();
    if(nextBit == 0){
      holder = holder->c0;
    }
    else{
      holder = holder->c1;
    }
  }
  return (int)holder->symbol;
}
