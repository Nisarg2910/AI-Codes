//Problem Statement/:-https://workat.tech/problem-solving/practice/balanced-parentheses

bool isBalancedParentheses(string x) {
    // add your logic here
	stack<char> s;
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='(')
            s.push(')');
        else if(x[i]=='[')
            s.push(']');
        else if(x[i]=='{')
            s.push('}');
        else if(x[i]==')' || x[i]=='}' || x[i]==']')
        {
            if(s.empty() || s.top()!=x[i])
                return false;
            else if(x[i]==s.top())
                s.pop();
        }
	}
    if(s.empty())
        return true;
    return false;
}