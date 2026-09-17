#include<iostream>
#include<cmath> 
using namespace std;
int f[2]{ 11,21 };
int a[114514], n = 0;
int main() {
	char temp;
	while (1) {
		cin >> temp;
		if (temp == 'E') {
			break;
		}
		else if (temp == 'W') {
			a[n++] = 1;
		}
		else if (temp == 'L') {
			a[n++] = 0;
		}
	}
	for (int k=0; k < 2; k++) {
		int w = 0, l = 0;
		for (int i = 0; i <n; i++) {
			if (a[i] == 1) {
				w++;
			}
			else if (a[i] == 0) {
				l++;
			}
			if ((max(w, l) >= f[k]) && abs(w - l) >= 2) {
				cout << w << ":" << l << "\n";
				w = l = 0;
			}
		}
		cout << w << ":" << l << "\n";
		if (k == 0) cout << endl; 
	}
	return 0;
}