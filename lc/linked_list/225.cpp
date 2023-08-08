#include <queue>

class MyStack {
    public:
        void push(int x) {
            int sz=q.size();
            q.push(x);
            while(sz--){
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int result=top();
            q.pop();
            return result;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }

    private:
        std::queue<int> q;
};
