#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int n,x1,y1,x2,y2;

int main()
{
    cin>>n>>x1>>y1>>x2>>y2;

    if(n==2)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    if((y1!=1&&y2!=1)&&(y1!=n&&y2!=n)&&y1==y2) cout<<"-1"<<endl;
    
    else if(y1==1&&y2==1)
    {
        while(y1<n)
        {
            cout<<"R";
            y1++;
        }
        if(x1==1) cout<<"D"; else cout<<"U";
        while(y1>1)
        {
            cout<<"L";
            y1--;
        }
        
    }

    else if(y1==n&&y2==n)
    {
        while(y1>1)
        {
            cout<<"L";
            y1--;
        }
        if(x1==1) cout<<"D"; else cout<<"U";
        while(y1<n)
        {
            cout<<"R";
            y1++;
        }
        
    }

    else if((x1-1==x2&&y1+1==y2)||(x1+1==x2&&y1-1==y2)||(x1+1==x2&&y1+1==y2)||(x1-1==x2&&y1-1==y2)) cout<<"-1"<<endl;

    else
    {
        bool f=false;
        string s;
        if(y1>y2)
        {
            swap(y1,y2);
            swap(x1,x2);
            f=true;
        }

        int tempy=y1;
        int tempx=x1;
        while(tempy>1)
        {
            s+='L';
            tempy--;
        }
        if(x1==1) 
        {
            s+="D";
            tempx++; 
        }
        else 
        {
            s+="U";
            tempx--;
        }
        while(tempy<y1)
        {
            s+='R';
            tempy++;
        }

        while(tempy<y2)
        {
            s+='R';
            tempy++;
            if(tempy>=y2&&tempx!=x2) break;
            else if(tempy>=y2&&tempx==x2)
            {
                cout<<"-1"<<endl;
                return 0;
            }

            if(tempx==2)
            {
                s+='U';
                tempx--;

                s+='R';
                tempy++;
                if(tempy>=y2&&tempx!=x2) break;
                else if(tempy>=y2&&tempx==x2)
                {
                    cout<<"-1"<<endl;
                    return 0;
                }

                s+='D';
                tempx++;
            }
            else
            {
                s+='D';
                tempx++;

                s+='R';
                tempy++;
                if(tempy>=y2&&tempx!=x2) break;
                else if(tempy>=y2&&tempx==x2)
                {
                    cout<<"-1"<<endl;
                    return 0;
                }
                s+='U';
                tempx--;
            }
        }

        while(tempy<n)
        {
            s+='R';
            tempy++;
        }
        if(tempx==1)
        {
            s+="D";
            tempx++; 
        }
        else 
        {
            s+="U";
            tempx--;
        }
        while(tempy>y2)
        {
            s+='L';
            tempy--;
        }

        if(f)
        {
            reverse(s.begin(), s.end());
            for (auto&c:s) 
            {
                if (c=='L') c='R';
                else if(c=='R') c='L';
                else if(c=='U') c='D';
                else if(c=='D') c='U';
            }
        }

        cout<<s<<endl;
    }

  
    return 0;

}