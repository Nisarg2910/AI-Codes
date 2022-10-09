//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string lexicographicallySmallest(string str, int k)
    {
        int n = str.length(); // store the length of string.

        if ((n & (n - 1)) == 0) // check that the length is even or odd.
            k /= 2;
        else
            k *= 2;

        if (k >= n) // if k is greater than n than return -1.
            return "-1";

        stack<char> st;

        for (int i = 0; i < n; i++)
        {

            char ch = str[i];

            while (!st.empty() && k > 0 && st.top() > ch)
            {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        // to pop out the extra character from the stack.
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }

        string ans = "";

        // To store the in string.
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // reverse the answer to obatin correct answer, as the it is retrived from stack so it must be reverse.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends