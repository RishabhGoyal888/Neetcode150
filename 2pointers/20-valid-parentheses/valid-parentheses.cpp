class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            //if closing bracket
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()){ //if stack already empty therefore false
                    return false;
                } //otherwise check for its respective opening bracket in stack top
                else if(s[i] == ')' && st.top() == '(')
                    st.pop();
                else if(s[i] == '}' && st.top() == '{')
                    st.pop();
                else if(s[i] == ']' && st.top() == '[')
                    st.pop();
                else 
                    return false;
            }
            else
                st.push(s[i]);
        }
        if(st.empty())
            return true; // all parenthesis have closing parenthesis
        return false; //else false
    }
};