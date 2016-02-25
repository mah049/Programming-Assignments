#include "Vertex.hpp"

// Method implementations here

// constructor. initializes all fields
Vertex::Vertex(std::string &name){
  this->name = name;
  this->visited = false;
  this->distance = std::numeric_limits<int>::max();
}

// attach edge to vertex
void Vertex::insert(std::string &name, Edge edge){
  std::pair<std::string,Edge> temp (name,edge);
  edges.insert(temp);
}

// debug
void Vertex::print(){
  std::cout<<this->name<<"'s distance: "<<this->distance<<"\n";
  std::unordered_map<std::string, Edge> localEdges (getEdges());
  std::unordered_map<std::string, Edge>::iterator it;
  std::cout<<this->name<<"'s edges:\n";
  for (it = localEdges.begin(); it != localEdges.end(); ++it){
    Edge temp = it->second;
    std::cout<<temp.fromV()->getName();
    std::cout<<", "<<temp.toV()->getName();
    temp.print();
  }
  std::cout << "\n";
}
