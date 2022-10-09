#include <bits/stdc++.h>
using namespace std;

// Function to find the number
// of the drops that come out of the
// pipe
int drops(int length, int position[],
		int speed[], int n)
{
	// stores position and time
	// taken by a single
	// drop to reach the end as a pair
	vector<pair<int, double> > m(n);

	int i;
	for (i = 0; i < n; i++) {

		// calculates distance needs to be
		// covered by the ith drop
		int p = length - position[i];

		// inserts initial position of the
		// ith drop to the pair
		m[i].first = position[i];

		// inserts time taken by ith
		// drop to reach
		// the end to the pair
		m[i].second = p * 1.0 / speed[i];
	}

	// sorts the pair according to increasing
	// order of their positions
	sort(m.begin(), m.end());
	int k = 0; // counter for no of final drops


	int curr_max = m[n-1].second;
	// we traverse the array demo
	// right to left
	// to determine the slower drop
	for (i = n - 2; i >= 0; i--)
	{
		// checks for next slower drop
		if (m[i].second > curr_max)
		{
			k++;
			curr_max=m[i].second;
		}
	}

	// calculating residual
	// drops in the pipe
	k++;
	return k;
}

// Driver Code
int main()
{
	// length of pipe
	int length = 12;

	// position of droplets
	int position[] = { 10, 8, 0, 5, 3 };

	// speed of each droplets
	int speed[] = { 2, 4, 1, 1, 3 };
	int n = sizeof(speed)/sizeof(speed[0]);
	cout << drops(length, position, speed, n);
	return 0;
}
