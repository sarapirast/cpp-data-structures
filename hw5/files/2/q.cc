#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

/**
   * Populates the successors_ and predecessors_ using edges_.
   * It is already called in the constructor.
   */
void Graph::PopulateSuccessorsAndPredecessors(){
  //bellman needs predecessor helper? function gets successor and predessors not finding the shortest path
  for (const auto i: edges_){
    int beg= i.first;
    int end= i.second;

    successors_[beg].push_back(end);
    predecessors_[end].push_back(beg);
  }
}



/**
   * Finds the shortest paths from the given start node to all other nodes in
   * the graph.
   * It also checks for negative cycles.
   *
   * @param start The start node.
   * @param distances A vector to store the distances from the start node to all
   * other nodes.
   * @return true if there was a negative cycle and false otherwise.
   */
  bool Graph::FindShortestDistance(int start, std::vector<int>& distances){
    distances.clear();
    for (size_t i=0;i<nodes_.size();++i){
      distances.push_back(std::numeric_limits<int>::max()); //inf
    }
    bool nedge=false;
    for (const auto& i:weights_){
      if (i.second<0){
        nedge=true;
        break;
      }
    }
    if (nedge){
      return BellmanFord(start,distances);
    }
    else {
      Dijkstra(start,distances);
      return false;
    }
}
 
 
 /**
   * Performs the BFS algorithm on the graph and stores the distances from the
   * start node to all other nodes in the `distances` vector.
   *
   * @param start The start node.
   * @param distances A vector to store the distances from the start node to all
   * other nodes.
   */

  //lecture 8
void Graph::BFS(int start, std::vector<int>& distances){
  distances.clear();
  for (size_t i=0;i<nodes_.size();++i){
    distances.push_back(std::numeric_limits<int>::max());
  }
  std::queue<int> q;
  distances[start]=0;
  q.push(start);
  while (!q.empty()){
    int cur=q.front();
    q.pop();
    for (const auto& i:successors_[cur]){
      if (distances[i]== std::numeric_limits<int>::max()){ //if not visited inf
      distances[i]= distances[cur]+1;
      q.push(i);
      }
    }
  }
}




  /**
   * Performs the Dijkstra algorithm on the graph and stores the distances from
   * the start node to all other nodes in the `distances` vector.
   *
   * @param start The start node.
   * @param distances A vector to store the distances from the start node to all
   * other nodes.
   */
void Graph::Dijkstra(int start, std::vector<int>& distances){
  distances.clear();
  for (size_t i=0;i<nodes_.size();++i){
    distances.push_back(std::numeric_limits<int>::max());
  }
  distances[start]= 0;
  std::unordered_map<int,bool> visited;
  while (true){
    int curn=-1;
    int curd=std::numeric_limits<int>::max();
    for (int i:nodes_){
      if (!visited[i]&&distances[i]<curd){
        curn=i;
        curd=distances[i];
      }
    }
    if (curn==-1){
      break;
    }
    visited[curn]=true;
    for (int i:successors_[curn]){
      auto it= weights_.find({curn,i}); //got help with this
      int ew= (it!=weights_.end())?it->second:1;
      int ndist=distances[curn]+ew;
      if (ndist<distances[i]){
        distances[i]=ndist;
      }
    }
  }
}



/**
   * Performs the Bellman-Ford algorithm on the graph and stores the distances
   * from the start node to all other nodes in the `distances` vector.
   * It also checks for negative cycles.
   *
   * @param start The start node.
   * @param distances A vector to store the distances from the start node to all
   * other nodes.
   * @return true if there was a negative cycle and false otherwise.
   */
bool Graph::BellmanFord(int start, std::vector<int>& distances){
  distances.clear();
  for (size_t i=0;i<nodes_.size();++i){
    distances.push_back(std::numeric_limits<int>::max());
  }
  distances[start]= 0;
  for (int i=0;i<nodes_.size()-1;i++){
    for (const auto& j:edges_){
      int x=j.first;
      int y=j.second;
      auto it=weights_.find(j);
      int weight= (it!=weights_.end())?it->second:1;
      if (distances[x]!=std::numeric_limits<int>::max()&&distances[x]+weight<distances[y]){
        distances[y]= distances[x]+weight;
      }
    }
  }
  for (const auto& i:edges_){
    int x=i.first;
    int y=i.second;
    auto it= weights_.find(i);
    int weight= (it!=weights_.end())?it->second:1;
    if (distances[x]!=std::numeric_limits<int>::max()&&distances[x]+weight<distances[y]){
      return true;
    }
  }

  return false;
}