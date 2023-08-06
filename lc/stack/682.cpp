#include <stdlib.h>

class Solution {
public:
    int calPoints(vector<string>& operations){
        vector<int> scores;

        for(int i = 0; i < operations.size(); ++i){
            if(operations[i] == "+"){
                scores.push_back(scores[scores.size()-1] + scores[scores.size()-2]);
            } else if (operations[i] == "D"){
                scores.push_back(2 * scores[scores.size()-1]);
            } else if (operations[i] == "C"){
                scores.pop_back();
            } else{
                scores.push_back(std::stoi(operations[i]));
            }
        }
        int final_score = 0;
        for(auto score : scores) final_score += score;
        return final_score;
    }
};
