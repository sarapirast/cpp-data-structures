#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

  void PlayerScores::store(const std::vector<int> &vector){
    originalSize = vector.size();
    for (int i=0; i<vector.size(); i++){
        if (vector[i] != 0) //if non zero add to efficient score
            efficientScores[i]= vector[i];
    }
  }


  // Calculates the sum of the other efficient vector with this efficient
  // vector.
  // Assume that the other vector is the same size as this vector.
  int PlayerScores::calculateCompoundScore(PlayerScores &otherPlayerScores){
    int res= 0;
    for (int i= 0; i< originalSize; i++){
        //if i exists then get the score, if not its 0;
        int scores1= (efficientScores.find(i) != efficientScores.end()) ? efficientScores[i] : 0;
        int score2 = (otherPlayerScores.efficientScores.find(i) != otherPlayerScores.efficientScores.end()) ? otherPlayerScores.efficientScores[i] : 0;
        res += (scores1 + score2);
    }
    return res;
  }




  // Converts the efficient scores to an inefficient vector, i.e. the zero
  // values are back.

  std::vector<int> PlayerScores::convertToVector(){
    std::vector<int> res(originalSize, 0);
    for (const auto& i : efficientScores) {
        res[i.first] = i.second; //efficient scores is map so can use this, first is key, second is val
    }
    return res;    
  }
