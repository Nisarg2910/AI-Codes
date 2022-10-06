//Problem Statement/:-https://workat.tech/problem-solving/practice/evaluate-reverse-polish-notation

int evalRPN(vector<string> &tokens) {
	stack<int> s;
	for(int i=0;i<tokens.size();i++)
	{
		if(tokens[i]=="+")
		{
			int sum = s.top();
			s.pop();
			sum += s.top();
			s.pop();
			s.push(sum);
		}
		else if(tokens[i]=="-")
		{
			int diff = s.top();
			s.pop();
			s.top() -= diff;
		}
		else if(tokens[i]=="*")
		{
			int mul = s.top();
			s.pop();
			s.top() *= mul;
		}
		else if(tokens[i]=="/")
		{
			int div = s.top();
			s.pop();
			s.top() /= div;
		}
		else
		{
			int num = stoi(tokens[i]);
			s.push(num);
		}
	}
	return s.top();
}