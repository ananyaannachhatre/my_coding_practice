class MinStack {
    public:
        MinStack() {
               
            }
            
            
            void push(int val) {
                stack.push(val);
                if (minStack.empty()) {
                    minStack.push(val);
                } else {
                    minStack.push(std::min(val, minStack.top()));
                }
            }
            
            
            void pop() {
                if (!stack.empty()) {
                    stack.pop();
                    minStack.pop();
                }
            }
            
           
            int top() {
                return stack.top();
            }
            
            
            int getMin() {
                return minStack.top();
            }

        private:
            std::stack<int> stack;        
            std::stack<int> minStack;     
        };

