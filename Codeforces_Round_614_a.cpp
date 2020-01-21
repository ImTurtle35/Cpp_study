#include <iostream>
#include <algorithm>

using namespace std;

bool check;
int t, n, s, k, k_save;
int kfloor[1001];

int main() {
	cin >> t;
	for (int i{ 0 }; i < t; i++) {
		cin >> n >> s >> k;
		for (int j{ 0 }; j <= k-1; j++) {
			cin >> kfloor[j];
		}
		sort(kfloor, kfloor + k);
		if (s > kfloor[k-1] || s < kfloor[0]) {
			cout << 0 << endl;
			continue;
		}
		else {
			for (int i{ 0 }; i <= k-1; i++) {
				if (s <= kfloor[i]) {
					k_save = i;
					break;
				}
			}
			int l = 1;
			if (s != kfloor[k_save]) {
				cout << 0 << endl;
				continue;
			}
			int a = s;
			int up = k_save;
			int b = s - 1;
			int dw = k_save - 1;
			while (true) {
				if (a <= n) {
					if (kfloor[up] == a) {
						a++;
						up++;
					}
					else {
						cout << a - s << endl;
						break;
					}
				}
				if (b >= 1) {
					if (kfloor[dw] == b) {
						b--;
						dw--;
					}
					else {
						cout << s - b << endl;
						break;
					}
				}
			}
		}
	}
}