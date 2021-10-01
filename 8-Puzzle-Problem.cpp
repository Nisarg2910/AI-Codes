#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
#define N 3	// this can be change by default it set to 3 to make 8 puzzle but if you want 4x4 then use 4 here and so on.

struct Node
{
	Node* parent;

	// matrix to store 
	int mat[N][N];
 
	int x, y;

	// misplaced matrix 
	int cost;

	// count the number of moves
	int level;
};

// displaying matrix of every step to get final goal state. 
void printMatrix(int mat[N][N])
{
	cout<<"-------------\n";
	for (int i = 0; i < N; i++)
	{
		cout<<"|";
		for (int j = 0; j < N; j++)
		{
			cout<<" "<<mat[i][j]<<" |";
			if(j==2)
			{
				cout<<endl;
				cout<<"-------------\n";
			}
		}
	}
	cout<<endl;
}

// new node function 
Node* newNode(int mat[N][N], int x, int y, int newX,
	int newY, int level, Node* parent)
{
	Node* node = new Node; 
	node->parent = parent;

	//data transfer from parent node to current node 
	memcpy(node->mat, mat, sizeof node->mat);

	// position change by 1 
	swap(node->mat[x][y], node->mat[newX][newY]);
	node->cost = INT_MAX; 
	node->level = level;

	// update new blank tile cordinates 
	node->x = newX;
	node->y = newY;

	return node;
}
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to calculate the number of misplaced tiles  
int calculateCost(int initial[N][N], int final[N][N])
{
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (initial[i][j] && initial[i][j] != final[i][j])
				count++;
	return count;
}

// check function, that help to identify the valid matrix or not 
int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

// printing path to root node.
void printPath(Node* root)
{
	if (root == NULL)
		return;
	printPath(root->parent);
	printMatrix(root->mat);
	cout<<endl;
}

//order the heap. we use comparasion object 
struct comp
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
	}
};

 
//calling function 
void solve(int initial[N][N], int x, int y,
	int final[N][N])
{
	// using priority queue in order to store a current node
	priority_queue<Node*, std::vector<Node*>, comp> pq;

	// calculating cost
	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);

	//push the current(live) nodes 
	pq.push(root);

	// Finds a live node with least cost, 
	// add its childrens to list of live nodes and 
	// finally deletes it from the list. 
	while (!pq.empty())
	{ 
		Node* min = pq.top();

		// node current is deleted. 
		pq.pop(); 
		if (min->cost == 0)
		{
			// displaying the path from root to destination. 
			printPath(min);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if (isSafe(min->x + row[i], min->y + col[i]))
			{ 
				Node* child = newNode(min->mat, min->x,
					min->y, min->x + row[i],
					min->y + col[i],
					min->level + 1, min);
				child->cost = calculateCost(child->mat, final);
				pq.push(child);	//adding child here 
			}
		}
	}
} 
int main()
{
	int initial[N][N];
	//this is goal state box. which is hardcoded in order to compare with given box values.
	int goal[N][N] =
	{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8}
	};
	// here 0 representing the space !
	cout<<"\t\t\t\t\t*****WELCOME TO 8 PUZZLE GAME*****\n\nInstructions: You have to put the value(0-8) in given 9 box(put 0 for space).Remember do not repeat any number then according to input value as sample box.\nfrom that state it give you all the steps to reach at Goal state.\n\n'Goal STATE'\n";
	cout<<"-------------\n";
	for(int i=0;i<N;i++)
	{
		cout<<"|";
		for(int j=0;j<N;j++)
		{
			cout<<" "<<goal[i][j]<<" |";
			if(j==2)
			{
				cout<<endl;
				cout<<"-------------";
				cout<<endl;
			}
		}
	}
	cout<<endl;
	cout<<"Sample Box : \n-------------\n|1x1|1x2|1x3|\n-------------\n|2x1|2x2|2x3|\n-------------\n|3x1|3x2|3x3|\n-------------\n\n";
	cout<<"Remember not every matrix that you enter to solve has a solution, few have no solution!\n"<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<"Enter value(0-8)'no repeat' at place ("<<i+1<<","<<j+1<<") : ";
			cin>>initial[i][j];
			cout<<endl;
		}
	}
	// use the titles as blank for initial state.
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(initial[i][j] == 0)	//getting location of space by put condition where it was entered in matrix.
			{
				break;
			}
		}
		if(initial[i][j] == 0)
		{
			break;
		}
	}
	int x =i, y = j;	// this gives the program location of space from it start moving the puzzle and solve it.
	cout<<"\n| Steps to Reach Final Goal |\n\nInitial State(Given Matrix) : \n";
	solve(initial, x, y, goal);
	cout<<endl<<"Exit : ";
	system("pause");
	return 0;
}
