#include "Edge.hpp"

// Method implementations here

/*
 * Edge constructor. Initializes all fields of new Edge
 */
Edge::Edge(Vertex *from, Vertex *to, unsigned int cost, unsigned int length){
  this->from = from;
  this->to = to;
  this->cost = cost;
  this->length = length;
}

/* 
 * defines operator for priority queue comparator
 */
bool Edge::operator<(const Edge &right) const{
  return this->cost > right.cost;
}

// debug
void Edge::print() {
  std::cout<<", count: "<<cost;
  std::cout<<", length: "<<length<<"\n";
}