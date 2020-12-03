#include<cstdlib>
#include<iostream>

using namespace std;
int ml[2005][2005];
int s[2005][2005];
int main()
{
    int N,M,ans=0;
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++){
            scanf("%d",&ml[i][j]);
            s[i][j]=ml[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            for (int k=1;k<=min(i,j);k++){
                if (s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k]==0) {ans++;}
                else break;
            }
            //printf("%d %d %d %d\n",i,j,k,ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
