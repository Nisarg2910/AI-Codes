import java.util.*;

public class WaterJug{

	class State{
		int first, second;
		State(int f, int s){
			first = f;
			second = s;
		}
	}

	void BFS(int a, int b, int target){
		int m[][] = new int[1000][1000];
		for(int[] i : m){
			Arrays.fill(i, -1);
		}
		boolean isSolvable = false;
		Vector<State> path = new Vector<State>();
		Queue<State> q = new LinkedList<State>(); 
      	q.add(new State( 0, 0 ));
		while (!q.isEmpty()) {
                 State u = q.peek();
			q.poll();
			if ((u.first > a || u.second > b ||
				u.first < 0 || u.second < 0))
				continue;
			if (m[u.first][u.second] > -1)
				continue;
			path.add(new State( u.first, u.second ));
                  m[u.first][u.second] = 1;
			if (u.first == target || u.second == target) {
				isSolvable = true;
				if (u.first == target) {
					if (u.second != 0)
						path.add(new State(u.first, 0 ));
				}
				else {
					if (u.first != 0)
						path.add(new State( 0, u.second ));
				}
				int sz = path.size();
				for (int i = 0; i < sz; i++)
					System.out.println("(" + path.get(i).first
						+ ", " + path.get(i).second + ")");
				break;
			}
			q.add(new State( u.first, b )); // fill Jug2
			q.add(new State( a, u.second )); // fill Jug1
			for (int ap = 0; ap <= Math.max(a, b); ap++) {
				int c = u.first + ap;
				int d = u.second - ap;
				if (c == a || (d == 0 && d >= 0))
					q.add(new State( c, d ));
				c = u.first - ap;
				d = u.second + ap;
				if ((c == 0 && c >= 0) || d == b)
					q.add(new State( c, d ));
			}
			q.add(new State( a, 0 )); // Empty Jug2
			q.add(new State( 0, b )); // Empty Jug1
		}
		if (!isSolvable)
			System.out.print("No solution");
	}

	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Capacity of 2 jugs and goal state:");
		WaterJug object = new WaterJug();
		object.BFS(sc.nextInt(), sc.nextInt(), sc.nextInt());

	}
}