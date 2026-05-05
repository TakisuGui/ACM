#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;

vector<int> a(N);

int n;




int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.begin()+n);

    auto new_end=unique(a.begin(),a.begin()+n);

    int new_size = new_end - a.begin();

    cout<<new_size<<endl;

     for(int i = 0; i < new_size; i++) {
        cout << a[i] << " ";
    }

    return 0;
}