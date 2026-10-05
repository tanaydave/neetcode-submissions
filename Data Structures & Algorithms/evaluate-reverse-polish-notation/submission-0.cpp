class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int num1,num2;
    for(auto t : tokens)
    {
        if(t == "+" || t == "*" || t == "-" || t == "/")
        {
            num2 = st.top();
            st.pop();
            num1 = st.top();
            st.pop();
        
            if (t == "+") st.push(num1 + num2);
            else if (t == "-") st.push(num1 - num2);
            else if (t == "*") st.push(num1 * num2);
            else st.push(num1 / num2);
        }
        else st.push(stoi(t));
    }
    return st.top();
        
    }
};
