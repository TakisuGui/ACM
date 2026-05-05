#include<iostream>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d",&n,&m);
	char a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
    if(m==1&&n==1){
        if(a[0][0]!='*')
        printf("0");
        else{
            printf("%c",a[0][0]);
        }
        return 0;
    }
      if(n == 1) {
        for (int j = 0; j < m; j++) {
            if(a[0][j] == '*') continue;
            int boom = 0;
            if(j > 0 && a[0][j-1] == '*') boom++;
            if(j < m-1 && a[0][j+1] == '*') boom++;
            a[0][j] = boom + '0';
        }
        for (int j = 0; j < m; j++) {
            printf("%c", a[0][j]);
        }
        printf("\n");
        return 0;
    }
    if(m == 1) {
        for (int i = 0; i < n; i++) {
            if(a[i][0] == '*') continue;
            int boom = 0;
            if(i > 0 && a[i-1][0] == '*') boom++;
            if(i < n-1 && a[i+1][0] == '*') boom++;
            a[i][0] = boom + '0';
        }
        for (int i = 0; i < n; i++) {
            printf("%c", a[i][0]);
            printf("\n");
        }
        return 0;
    }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
               if(a[i][j]=='*'){
            continue;
        }
			if (i != 0 && j != 0 && i != n - 1 && j != m - 1) {
				char boom = 0;
				if (a[i - 1][j] == '*') {
					boom++;
				}
				if (a[i + 1][j] == '*') {
					boom++;
				}
				if (a[i][j - 1] == '*') {
					boom++;
				}
				if (a[i][j + 1] == '*') {
					boom++;
				}
                if (a[i - 1][j-1] == '*') {
					boom++;
				}
				if (a[i + 1][j+1] == '*') {
					boom++;
				}
				if (a[i+1][j - 1] == '*') {
					boom++;
				}
				if (a[i-1][j + 1] == '*') {
					boom++;
				}
				a[i][j] = boom +'0';
			}
			else if (i == 0 && j == 0) {
				char boom = 0;
				if (a[i + 1][j] == '*') {
					boom++;
				}
				if (a[i][j + 1] == '*') {
					boom++;
				}
                if (a[i+1][j + 1] == '*') {
					boom++;
				}
				a[i][j] = boom+'0';
			}
			else if (i == n - 1 && j == 0) {
				char boom = 0;
				if (a[i - 1][j] == '*') {
					boom++;
				}
				if (a[i][j + 1] == '*') {
					boom++;
				}
                if (a[i-1][j + 1] == '*') {
					boom++;
				}
				a[i][j] = boom+'0';
			}
			else if (i == 0 && j == m - 1) {
				char boom = 0;
				if (a[i][j - 1] == '*') {
					boom++;
				}
				if (a[i + 1][j] == '*') {
					boom++;
				}
                if (a[i+1][j -1] == '*') {
					boom++;
				}
				a[i][j] = boom+'0';
			}
			else if (i == n - 1 && j == m - 1) {
				char boom = 0;
				if (a[i][j - 1] == '*') {
					boom++;
				}
				if (a[i - 1][j] == '*') {
					boom++;
				}
                if (a[i-1][j-1] == '*') {
					boom++;
				}
				a[i][j] = boom+'0';
			}
			else if (i == 0 && j != 0 && j != m - 1) {
				char boom = 0;
				if (a[i][j - 1] == '*') {
					boom++;
				}
				if (a[i][j + 1] == '*') {
					boom++;
				}
				if (a[i + 1][j] == '*') {
					boom++;
				}
                if (a[i+1][j + 1] == '*') {
					boom++;
				}
                if (a[i+1][j - 1] == '*') {
					boom++;
				}
				a[i][j] = boom +'0';
			}
			else if (i == n - 1 && j != 0 && j != m - 1) {
				char boom = 0;
				if (a[i][j - 1] == '*') {
					boom++;
				}
				if (a[i][j + 1] == '*') {
					boom++;
				}
				if (a[i - 1][j] == '*') {
					boom++;
				}
                if (a[i-1][j + 1] == '*') {
					boom++;
				}
                if (a[i-1][j -1] == '*') {
					boom++;
				}
				a[i][j] = boom+'0';
			}
			else if (i != 0 && i != n - 1 && j == 0) {
				char boom = 0;
				if (a[i - 1][j] == '*') {
					boom++;
				}
				if (a[i + 1][j] == '*') {
					boom++;
				}
				if (a[i][j + 1] == '*') {
					boom++;
				}
                if (a[i+1][j + 1] == '*') {
					boom++;
				}
                if (a[i-1][j +1] == '*') {
					boom++;
				}
				a[i][j] = boom+'0';
			}
			else if (i != 0 && i != n - 1 && j == m - 1) {
				char boom = 0;
				if (a[i - 1][j] == '*') {
					boom++;
				}
				if (a[i + 1][j] == '*') {
					boom++;
				}
				if (a[i][j - 1] == '*') {
					boom++;
				}
                if (a[i-1][j -1] == '*') {
					boom++;
				}
                if (a[i+1][j -1] == '*') {
					boom++;
				}
				a[i][j] = boom+'0';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", a[i][j]);
		}
        printf("\n");
	}
	return 0;
}