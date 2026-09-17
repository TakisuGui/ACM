#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N];
int ans[N];

void test1()
{
    stack<int> st;

    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop();

        if(!st.empty())ans[i]=st.top();
        else ans[i]=0;

        st.push(i);
    }

}

void test2()
{
    stack<int> st;
    
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]>=a[i])st.pop();

        if(!st.empty())ans[i]=st.top();

        st.push(i);

    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    test2();

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}