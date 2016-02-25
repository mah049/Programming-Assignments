#include "HCNode.hpp"
// override < operator for the huffman tree's priority queue
bool HCNode::operator<(HCNode const & other) {
  if(count != other.count)
    return count>other.count;
  return symbol>other.symbol;
}
