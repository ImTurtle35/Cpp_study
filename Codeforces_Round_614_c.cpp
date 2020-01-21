#include <iostream>
#include <string>

using namespace std;

int n, q, r, c, obstacle;
int maze[3][100001];

void check1(int rn, int cn) {
	if (rn == 1) {
		if (maze[2][cn + 1] == 1)
			obstacle++;
		if (maze[2][cn - 1] == 1)
			obstacle++;
		if (maze[2][c] == 1)
			obstacle++;
	}
	else if (rn == 2) {
		if (maze[1][cn + 1] == 1)
			obstacle++;
		if (maze[1][cn - 1] == 1)
			obstacle++;
		if (maze[1][c] == 1)
			obstacle++;
	}
}

void check2(int rn, int cn) {
	if (rn == 1) {
		if (maze[2][cn + 1] == 1)
			obstacle--;
		if (maze[2][cn - 1] == 1)
			obstacle--;
		if (maze[2][c] == 1)
			obstacle--;
	}
	else if (rn == 2) {
		if (maze[1][cn + 1] == 1)
			obstacle--;
		if (maze[1][cn - 1] == 1)
			obstacle--;
		if (maze[1][c] == 1)
			obstacle--;
	}
}

int main() {
	cin >> n >> q;
	for (int i{ 1 }; i <= q; i++) {
		cin >> r >> c;
		if (maze[r][c] == 0) {
			maze[r][c] = 1;
			check1(r, c);
		}
		else if (maze[r][c] == 1) {
			maze[r][c] = 0;
			check2(r, c);
		}
		if (obstacle == 0) {
			cout << "Yes" << endl;
		}
		else if (obstacle >= 0) {
			cout << "No" << endl;
		}
	}
}