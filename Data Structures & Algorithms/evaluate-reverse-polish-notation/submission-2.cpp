class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops = {"+", "-", "*", "/"};
        stack<int> stk;
        for(auto t : tokens){
            if(ops.find(t) != ops.end()){
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                if(t == "+")stk.push(num1+num2);
                if(t == "-")stk.push(num1-num2);
                if(t == "*")stk.push(num1*num2);
                if(t == "/")stk.push(num1/num2);
            } else {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};
