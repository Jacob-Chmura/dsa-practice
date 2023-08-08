#include <deque>

class Solution {

public:
    int countStudents(vector<int>& students, vector<int>&sandwiches){
        std::deque<int> student_q, sandwich_q;
        for(int i = 0; i < students.size();++i){
            student_q.push_back(students[i]);
            sandwich_q.push_back(sandwiches[i]);
        }
        
        int num_fed = 0, num_failed = 0;
        while(!sandwich_q.empty()){
            if(num_failed == student_q.size()) break;
            if(student_q.front() == sandwich_q.front()){
                student_q.pop_front();
                sandwich_q.pop_front();
                num_failed = 0;
                ++num_fed;
            }
            else{
                student_q.push_back(student_q.front());
                student_q.pop_front();
                ++num_failed;
            }
        }
        return student_q.size();
    }
};
