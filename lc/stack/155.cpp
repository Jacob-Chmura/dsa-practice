class MinStack {
    public:
        void push(int val){
            _stack.push(val);
            if(_min_stack.empty() || val < _min_stack.top()){
                _min_stack.push(val);
            }
        }

        void pop() {
            if(_stack.top() == _min_stack.top()){
                _min_stack.pop();
            }
            _stack.pop();
        }

        int top() {
            return _stack.top();
        }

        int getMin(){
            return _min_stack.top();
        }

    private:
        std::stack<int> _stack, _min_stack;
};
