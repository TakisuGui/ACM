#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;

//打表找规律
int dp[N][N];

void ini()
{
    for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			dp[i][j]=-1;
}

int sg(int a,int b)
{
    if(a==1&&b==1) return 0;
    if(dp[a][b]!=-1) return dp[a][b];

    vector<bool> appera(N+2,false);

    if(a>1)
    {
        for(int i=1;i<=a-1;i++) appera[sg(i,a-i)]=true;
    }
    if(b>1)
    {
        for(int i=1;i<=b-1;i++) appera[sg(i,b-i)]=true;
    }

    int ans=0;
    for(int k=0;k<=max(a,b);k++)
    {
        if(!appera[k]){ans=k; break;}
    }

    dp[a][b]=ans;
    return ans;
}

void test() {
    ini();
    cout << "   ";
    for (int i = 1; i <= 9; i++) cout << setw(3) << i;
    cout << "\n----------------------------\n";

    for (int a = 1; a <= 9; a++) {
        cout << a << " |";
        for (int b = 1; b <= 9; b++) {
            cout << setw(3) << sg(a, b);
        }
        cout << endl;
    }
}

int lowZero(int status) {
    int ans = 0;
    while (status > 0) {
        if ((status & 1) == 0) {
            break;
        }
        status >>= 1;
        ans++;
    }
    return ans;
}

void solve()
{
    int n; cin>>n;
    int sgSum=0;
    for (int j=1; j<=n; j+=2) 
    {
        int a,b; cin>>a>>b;
        sgSum^=lowZero((a-1) | (b-1));
    }

    cout<< (sgSum==0 ? "NO" : "YES")<<endl;
}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

