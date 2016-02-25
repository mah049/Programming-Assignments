#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "UndirectedGraph.hpp"

#define TWO 2

/**
 * Entry point into the netplan program.
 *
 * Usage:
 *   ./netplan infile
 *
 */
int main(int argc, char **argv) {
  // make sure correct input
  if (argc != TWO) {
    std::cerr << "Usage: " << argv[0] << " infile" << std::endl;
    return EXIT_FAILURE;
  }
  // read file in
  std::ifstream in(argv[1]);
  if (!in) {
    std::cerr << "Unable to open file for reading." << std::endl;
    return EXIT_FAILURE;
  }
  // initizalize all possible network graph
  UndirectedGraph g; 
  // vars for reading in and calculating output
  std::string v1;
  std::string v2;
  unsigned totalCost = 0;
  double cost;
  double time;
  unsigned int minCost = 0;
  int count = 0;
  unsigned int minTimeG = 0;
  unsigned int minTimeMST = 0;
  
  // read all input
  while(in.good()) {
    in >> v1 >> v2 >> cost >> time;
    if(!in.good()) break;
    //add the vertices v1 and v2 to the graph
    g.insert(v1, v2, cost, time);
    count++;
  } 
  if(!in.eof()){
    std::cerr << "File is broken." << std::endl;
    return EXIT_FAILURE;
  }
  in.close();
  // total cost of graph
  totalCost = g.cost()/TWO;
  // generate edges of MST
  std::vector<Edge> minTree = g.MST(count);
  std::vector<Edge>::iterator it;
  // total cost of MST
  for (it = minTree.begin(); it != minTree.end(); ++it) {
    Edge temp = *it;
    minCost += temp.getCost();
  }
  // create graph for MST
  UndirectedGraph minTreeGraph;
  for (it = minTree.begin(); it != minTree.end(); ++it) {
    std::string name1 = it->fromV()->getName();
    std::string name2 = it->toV()->getName();
    minTreeGraph.insert(name1, name2, it->getCost(), it->getLength());
  }
  // calculate minimum transit time for all possible networks graph
  std::unordered_map<std::string,Vertex*> tempVertices (g.getVertices());
  std::unordered_map<std::string,Vertex*>::iterator it1;
  for (it1 = tempVertices.begin(); it1 != tempVertices.end(); ++it1) {
    // call Dijkstra's on each Vertex
    g.minTime(count, it1);
    std::unordered_map<std::string,Vertex*>::iterator it2;
    for (it2 = tempVertices.begin(); it2 != tempVertices.end(); ++it2) {
      if (it1 == it2) {
        continue;
      }
      minTimeG += it2->second->getDistance();
    }
  }
  // calculate minimum transit time for MST
  std::unordered_map<std::string,Vertex*> tempVertices1 (minTreeGraph.getVertices());
  for (it1 = tempVertices1.begin(); it1 != tempVertices1.end(); ++it1) {
    // call Dijkstra's on each Vertex
    minTreeGraph.minTime(count, it1);
    std::unordered_map<std::string,Vertex*>::iterator it2;
    for (it2 = tempVertices1.begin(); it2 != tempVertices1.end(); ++it2) {
      if (it1 == it2) {
        continue;
      }
      minTimeMST += it2->second->getDistance();
    }
  }
  // output
  std::cout << totalCost << std::endl;
  std::cout << minCost << std::endl;
  std::cout << totalCost-minCost << std::endl;
  std::cout << minTimeG << std::endl;
  std::cout << minTimeMST << std::endl;
  std::cout << minTimeMST-minTimeG << std::endl;
  return EXIT_SUCCESS;
}
