#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

class Vertex;

/**
 * Represents an edge in a graph.
 *
 * Maintains pointers to the vertices that the edge originates 
 * from and terminates at. Edges have both a cost and a length,
 * which are both non-negative integers.
 *
 * Follows value semantics, so can be copy constructed.
 */
class Edge {
  public:
    /**
     * Constructs an Edge from the given parameters.
     */
    Edge(Vertex *from, Vertex *to,
            unsigned int cost,
            unsigned int length);

    /*
     * Compares this Edge to another Edge. Suitable for
     * use with a priority queue where Edges with the lowest
     * weight have the highest priority.
     */
    bool operator<(const Edge &right) const;

    // getter for cost
    unsigned int getCost() {
        return this->cost;
    }

    // getter for length
    unsigned int getLength() {
        return this->length;
    }

    // getter for from Vertex*
    Vertex* fromV() {
        return this->from;
    }

    // getter from to Vertex*
    Vertex* toV() {
        return this->to;
    }

    // debug
    void print();

  private:   
    /**
     * Vertex that this Edge originates from.
     */
    Vertex *from;

    /**
     * Vertex that this Edge terminates at.
     */
    Vertex *to;
    /**
     * Cost of this Edge.
     */

    unsigned int cost;

    /**
     * Length of this Edge.
     */
    unsigned int length;
};

#endif
