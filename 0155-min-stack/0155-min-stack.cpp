class MinStack {
public:
    stack<pair<int,int>>s;          // <element,min>
    MinStack() {}
    
    void push(int x) {
        if(!s.empty()){
            int min= s.top().second;
        if(x>min){
            s.push({x,min});
        }
        else{
            s.push({x,x});
        }
        }
        else{
            s.push({x,x});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */