class Solution {
    public:
        bool isValid(string s){
            std::stack<char> stack;
            for(auto c : s){
                if (c == ')'){
                    if (stack.empty() or stack.top() != '(') return false;
                    stack.pop();
                } else if (c == '}'){
                    if (stack.empty() or stack.top() != '{') return false;
                    stack.pop();
                } else if (c == ']'){
                    if (stack.empty() or stack.top() != '[') return false;
                    stack.pop();
                } else{
                    stack.push(c);
                }
            };
            return stack.empty();
        }
};
