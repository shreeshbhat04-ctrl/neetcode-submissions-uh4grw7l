class MinStack {
public:
stack<int>normst;
stack<int>mini;
    MinStack() {
        
    }
    
    void push(int val) {
        normst.push(val);
        if(mini.empty()||val<=mini.top()){
            mini.push(val);
        }
    }
    
    void pop() {
        if(normst.empty())return;
        int v=normst.top();
        normst.pop();
        
        if(!mini.empty() &&mini.top()==v){
            mini.pop();
        }
    }
    
    int top() {
       return normst.top(); 
    }
    
    int getMin() {
        return mini.top();
    }
};
