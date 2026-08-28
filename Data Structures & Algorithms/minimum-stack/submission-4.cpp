class MinStack {
    private:
    std::vector<int> stack;
    std::vector<int> minstack;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        //if its the first element or if its less than the min push_back
        //duplicates
        if(minstack.empty()){
            minstack.push_back(val);
        } else if( val <= minstack.back()){
            minstack.push_back(val);
        }
    }
    
    void pop() {
        if(stack.back() == minstack.back()){
            minstack.pop_back();
        }
        stack.pop_back();
        
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minstack.back();
    }
};
