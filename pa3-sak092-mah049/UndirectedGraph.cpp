#include "UndirectedGraph.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"

// Method implementations here
typedef std::unordered_map<std::string, Edge> edgeMap;
// constructor
UndirectedGraph::UndirectedGraph(){

}

// destructor
UndirectedGraph::~UndirectedGraph(){
  std::unordered_map<std::string, Vertex*>::iterator vIt;
  std::unordered_map<std::string, Edge>::iterator eIt;
  // delete all verteces
  for (vIt = vertices.begin(); vIt != vertices.end(); ++vIt){
    delete vIt->second;
  }
}

// debug
void UndirectedGraph::print() {
  std::unordered_map<std::string, Vertex*>::iterator it;
  for (it = vertices.begin(); it != vertices.end(); it++){
    std::cout << it->second->getName() << std::endl;
    it->second->print();
  }
  std::cout << std::endl;
}

// insert pair of vertices and corresponding edges to graph
void UndirectedGraph::insert(std::string &name1, std::string &name2, double cost, double time){
  std::unordered_map<std::string,Vertex*>::iterator got1 = this->vertices.find(name1);
  std::unordered_map<std::string,Vertex*>::iterator got2 = this->vertices.find(name2);
  // case where both vertices are new
  if (got1 == this->vertices.end() && got2 == this->vertices.end()) {
    // all new vertices
    Vertex* vertex1 = new Vertex (name1);
    Vertex* vertex2 = new Vertex (name2);
    // all new edges
    Edge edge1(vertex1, vertex2, cost, time);
    Edge edge2(vertex2, vertex1, cost, time);
    // attach edges to vertices
    vertex1->insert(name2, edge1);
    vertex2->insert(name1, edge2);
    // attach vertices to graph
    std::pair<std::string,Vertex*> temp1 (name1,vertex1);
    std::pair<std::string,Vertex*> temp2 (name2,vertex2);
    this->vertices.insert(temp1);
    this->vertices.insert(temp2);
  }
  // case where first is new and second already exists
  else if (got1 == this->vertices.end() && got2 != this->vertices.end()) {
    // new vertex
    Vertex* vertex1 = new Vertex (name1);
    // new edges
    Edge edge1(vertex1, this->vertices.at(name2), cost, time);
    Edge edge2(this->vertices.at(name2), vertex1, cost, time);
    // add edges to new vertex and existing vertex
    vertex1->insert(name2, edge1);
    Vertex* temp = this->vertices.at(name2);
    temp->insert(name1, edge2);
    this->vertices.at(name2) = temp;
    // add new vertex to graph
    std::pair<std::string,Vertex*> temp1 (name1,vertex1);
    this->vertices.insert(temp1);
  }
  // case where first exists and second is new
  else if (got1 != this->vertices.end() && got2 == this->vertices.end()) {
    // new vertex
    Vertex* vertex2 = new Vertex (name2);
    // new edges
    Edge edge1(this->vertices.at(name1), vertex2, cost, time);
    Edge edge2(vertex2, this->vertices.at(name1), cost, time);
    // add edges to vertices
    vertex2->insert(name1, edge2);
    Vertex* temp = this->vertices.at(name1);
    temp->insert(name2, edge1);
    this->vertices.at(name1) = temp;
    // add new vertex to graph
    std::pair<std::string,Vertex*> temp2 (name2,vertex2);
    this->vertices.insert(temp2);
  }
  // case where both exist
  else {
    // new edges
    Edge edge1(this->vertices.at(name1), this->vertices.at(name2), cost, time);
    Edge edge2(this->vertices.at(name2), this->vertices.at(name1), cost, time);
    // add edges to vertices
    Vertex* temp1 = this->vertices.at(name1);
    temp1->insert(name2, edge1);
    this->vertices.at(name1) = temp1;
    Vertex* temp2 = this->vertices.at(name2);
    temp2->insert(name1, edge2);
    this->vertices.at(name2) = temp2;
  }
}

// generate vector of edges representing MST
std::vector<Edge> UndirectedGraph::MST(int count) {
  std::priority_queue<Edge,std::vector<Edge>> queue;
  std::vector<Edge> mstEdges;
  int tempCount = count;
  // push all edges of start vertex to queue
  std::unordered_map<std::string, Vertex*>::iterator itFrom = vertices.begin();
  edgeMap temp (itFrom->second->edges);
  std::unordered_map<std::string, Edge>::iterator it2;
  for (it2 = temp.begin(); it2 != temp.end(); ++it2) {
    queue.push(it2->second);
  }
  itFrom->second->visited = true;
  // prim's algo
  while (!queue.empty() && tempCount>0) {  
    // top edge from queue
    Edge temp = queue.top();
    Vertex* tempV;
    queue.pop();
    // if edge goes to already visited vertex, skip
    if (temp.toV()->visited == true) {
      continue;
    }
    // mark current as visited
    temp.fromV()->visited = true;
    // add current edge to MST vector (one with lowest weight b/c queue)
    mstEdges.push_back(temp);
    // choose next vector to look at
    if(temp.toV()->visited == false)
      tempV = temp.toV();
    else
      tempV = temp.fromV();
    --tempCount; // keep track of how many vertices looked at
    edgeMap tempEdges (tempV->edges);
    // push all edges of next vertex to queue
    std::unordered_map<std::string, Edge>::iterator it3;
    for (it3 = tempEdges.begin(); it3 != tempEdges.end(); ++it3) {
      queue.push(it3->second);
    }
    // mark it as visited
    tempV->visited = true;
  }
  // return that vector
  return mstEdges;
}

// dijkstra's on graph given start vertex
void UndirectedGraph::minTime(int count, std::unordered_map<std::string,Vertex*>::iterator itStart) {

  std::priority_queue<std::pair<Vertex*, unsigned int>,
                      std::vector<std::pair<Vertex*, unsigned int>>,
                      UndirectedGraph::DijkstraVertexComparator> queue;

  int tempCount = count;
  // reset visited flags and distances
  std::unordered_map<std::string,Vertex*>::iterator it;
  for (it = this->vertices.begin(); it != this->vertices.end(); ++it){
    it->second->setVisited(false);
    it->second->setDistance(std::numeric_limits<int>::max());
  }
  // set start vertex to 0 and push to queue
  itStart->second->setDistance(0);
  std::pair<Vertex*,unsigned int> temp (itStart->second,itStart->second->getDistance());
  queue.push(temp);
  // dijkstra's
  while (!queue.empty() && tempCount>0){
    // pop top (lowest distance)
    std::pair<Vertex*,unsigned int> temp = queue.top();
    queue.pop();
    // if we already visted go on.
    if(temp.first->getVisited() == true) { 
      continue;
    }
    tempCount--; // keep track of how many vertices checked
    // go through edges of current vertex
    std::unordered_map<std::string,Edge> tempEdges = temp.first->getEdges();
    std::unordered_map<std::string,Edge>::iterator itEdge;
    for (itEdge = tempEdges.begin(); itEdge != tempEdges.end(); ++itEdge){
      // check all unvisited vertices linked to current one
      Vertex* Y = itEdge->second.toV();
      if (Y->getVisited() == true) {
        continue;
      }
      // update running distance
      unsigned int newDistance = temp.first->getDistance() + itEdge->second.getLength();
      if (newDistance < Y->getDistance()) {
        // new smaller distance so push back to queue
        Y->setDistance(newDistance);
      	std::pair<Vertex*,unsigned int> toInsert (Y,newDistance);
      	queue.push(toInsert);
      }
    }
    // set visited to true
    temp.first->setVisited(true);
  }
}