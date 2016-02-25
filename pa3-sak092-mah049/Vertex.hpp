#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <unordered_map>
#include <iostream>
#include <cstring>
#include <string>
#include <limits>

#include "Edge.hpp"

/**
 * Represents a Vertex in a graph.
 *
 * Vertices are connected to other Vertices via Edges. Each Vertex
 * maintains a collection of all Edges that originate from it.
 */
class Vertex {
    // Graph needs access to Edge map for Dijkstra/Prim algorithms.
    friend class UndirectedGraph;
    
  public:
    /**
     * Initialize the Vertex with the given name.
     */
    Vertex(std::string &name);

    // attach edge to vertex
    void insert(std::string &name, Edge edge);

    // debug
    void print();

    // getting costs of all edges for this vertex
    unsigned int cost() {
      unsigned int runningTotal = 0;
      std::unordered_map<std::string, Edge>::iterator it;
      for (it = this->edges.begin(); it != this->edges.end(); ++it) {
        runningTotal += it->second.getCost();
      }
      return runningTotal;
    }

    // getter for distance
    unsigned int getDistance() {
      return this->distance;
    }

    // setter for distance
    void setDistance(unsigned int blah) {
      this->distance = blah;
    }

    // getter for name
    std::string getName() {
      return this->name;
    }

    // getter for edge hashmap
    std::unordered_map<std::string, Edge> getEdges() {
      return this->edges;
    }

    // getter for visited flag
    bool getVisited() {
      return this->visited;
    }

    // setter for visited flag
    void setVisited(bool blah) {
      this->visited = blah;
    }

  private:
    /**
     * Name of this Vertex.
     */
    std::string name;
    
    /**
     * Distance of this Vertex from initial Vertex.
     * Used by Dijkstra's algorithm.
     */
    unsigned int distance;
    
    /**
     * Whether this node has been visited.
     * Used by Prim's algorithm.
     */
    bool visited;

    /**
     * Map of adjacent Vertex name to Edge describing the adjacency.
     */
    std::unordered_map<std::string, Edge> edges;
};

#endif
