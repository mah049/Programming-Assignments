#ifndef UNDIRECTEDGRAPH_HPP
#define UNDIRECTEDGRAPH_HPP

#include <string>
#include <unordered_map>
#include <iostream>
#include <iostream>
#include <queue>
#include <vector>
#include <limits>

#include "Vertex.hpp"

/**
 * Implements an undirected graph. Any edge in the graph
 * represents a bidirectional connection between two vertices.
 * 
 * Implements methods for producing a minimum spanning tree of the
 * graph, as well as calculating the total length of the shortest
 * paths between each pair of vertices.
 */
class UndirectedGraph {
  public:
    /**
     * Constructs an empty UndirectedGraph with no vertices and
     * no edges.
     */
    UndirectedGraph();

    /**
     * Destructs an UndirectedGraph.
     */
    ~UndirectedGraph();

    // insert function that inserts pair of vertices and attaches
    void insert(std::string &name1, std::string &name2, double cost, double time); 

    // debug
    void print();

    // for gettting total cost
    unsigned int cost() {
      unsigned int total = 0;
      // go through vertices and get cost of all edges
      std::unordered_map<std::string, Vertex*>::iterator it;
      for (it = vertices.begin(); it != vertices.end(); ++it) {
        total += it->second->cost();
      }
      return total;
    }

    // MST generator
    std::vector<Edge> MST(int count);

    // Dijkstra's
    void minTime(int count, std::unordered_map<std::string,Vertex*>::iterator itStart);

    // getter for vertices hashmap
    std::unordered_map<std::string,Vertex*> getVertices() {
      return this->vertices;
    }
    
  private:
    /**
     * Comparison functor for use with Dijkstra's algorithm. Allows Vertices
     * to be added to a priority queue more than once, with different weights.
     */
    class DijkstraVertexComparator {
      public:
        bool operator()(const std::pair<Vertex*, unsigned int> &left,
                const std::pair<Vertex*, unsigned int> &right) {
	        return left.second > right.second;
	      }
    };
    
    /**
     * Map of vertex name to Vertex.
     */
    std::unordered_map<std::string, Vertex*> vertices;
};

#endif
