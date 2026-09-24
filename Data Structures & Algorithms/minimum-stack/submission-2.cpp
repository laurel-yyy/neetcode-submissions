class MinStack {
public:
        stack<int> minstk;
        stack<int> stk;
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if(minstk.empty() || minstk.top() >= val){
            minstk.push(val);
        }
    }
    
    void pop() {
        if(stk.empty())return;
        if(stk.top() == minstk.top()) minstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
