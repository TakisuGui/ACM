#include<iostream>
using namespace std;
int main() {
int n,m;
cin>>n>>m;
int a[n][n];
int p=1;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        a[i][j]=p;
        p++;
    }
}
int x,y,r,z;
for(int q=0;q<m;q++){
    cin>>x>>y>>r>>z;
    x--;
    y--;
    int temp[n][n];
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j] = a[i][j];
            }
        }
    if(z==1){
        for(int t=2*r+1;t>=3;t=t-2){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i==x-r||i==x+r||j==y-r||j==y+r)&&(i>=y-r&&i<=y+r&&j<=x+r&&j>=x-r)){
                        int layer=(2*r+1-t)/2;
                        int start_i = y - r + layer;  
                        int start_j = x - r + layer;
                        int local_i = i - start_i;
                        int local_j = j - start_j;
                        int new_local_i = local_j;
                        int new_local_j = t-1-local_i;
                        int new_i = start_i + new_local_i;   
                         int new_j = start_j + new_local_j;  
                        temp[new_i][new_j]=a[i][j];
                    }
                }
            }
             for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        a[i][j] = temp[i][j];
                    }
                }
            r--;
        }
    }
    else{
        for(int t=2*r+1;t>=3;t=t-2){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i==x-r||i==x+r||j==y-r||j==y+r)&&(i>=y-r&&i<=y+r&&j<=x+r&&j>=x-r)){
                        int layer = (2*r+1 - t) / 2;
                int start_i = y - r + layer;  // 行起始
                int start_j = x - r + layer;  // 列起始
                
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if((i==y-r||i==y+r||j==x-r||j==x+r)&&
                           (i>=y-r&&i<=y+r&&j>=x-r&&j<=x+r)){
                            // 转换为局部坐标
                            int local_i = i - start_i + 1;
                            int local_j = j - start_j + 1;
                            int new_local_i = t - local_j + 1;  // 修正公式
                            int new_local_j = local_i;
                            // 转换回全局坐标
                            int new_i = start_i + new_local_i - 1;
                            int new_j = start_j + new_local_j - 1;
                        temp[new_i][new_j]=a[i][j];
                    }
                }
            }
            for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        a[i][j] = temp[i][j];
                    }
                }
            r--;
        }
      }
     }
    }
}
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ",a[i][j]);
    }
    printf("\n");
}
return 0;
}