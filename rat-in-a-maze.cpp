#include <iostream>
using namespace std;
int count = 0;

bool ratInMaze(char maze[10][10], int sol[][10], int i, int j, int m, int n) {
	//Base case
	if(i == m-1 && j == n-1) {
		sol[i][j] = 1;

		//Print the paths
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		count += 1;
		cout << endl;
		return true;
	}

	//Recursive case

	//Rat shuold be inside the maze
	if(i >= m || j >= n)
		return false;

	if(maze[i][j] == 'X')
		return false;

	//Assume solution exists through current cell
	sol[i][j] = 1;

	bool rightSuccess = ratInMaze(maze, sol, i, j+1, m, n);
	bool downSuccess = ratInMaze(maze, sol, i+1, j, m, n);

	//Backtracking
	sol[i][j] = 0;

	if(rightSuccess || downSuccess)
		return true;

	//cout << "Number of paths: " << count << endl;
	return false;
}

int main() {
	int m = 4, n = 4;
	//int pathCount = 0;
	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};

	int sol[10][10] = {0};

	bool ans = ratInMaze(maze, sol, 0, 0, m, n);

	if(ans == false)
		cout << "Path doesn't exist!" << endl;

	cout << "Number of paths: " << count << endl;

	return 0;
}