#include<cstdlib>
#include<iostream>

using namespace std;
int p[205][205];
int a[205];
int s[205];
int cal(int l,int r){
    if (p[l][r]>=0) return p[l][r];
    int ret=2147483647,tmp=0;
    for (int i=l;i<r;i++){
        tmp=cal(l,i)+cal(i+1,r)+s[r]-s[l-1];
        if (tmp<ret) ret=tmp;
    }
    p[l][r]=ret;
    return ret;
}
int main()
{
    int N;
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            p[i][j]=-1;
    for (int i=1;i<=N;i++){
        scanf("%d",&a[i]);
        p[i][i]=0;
        s[i]=s[i-1]+a[i];
    }
    printf("%d\n",cal(1,N));
    return 0;
}
