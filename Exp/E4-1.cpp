#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
int N,R;
int maxpos;
int village[maxn];
int f[maxn],g[maxn];
int main(){
    scanf("%d%d",&N,&R);
    R=R;
    for (int i=1;i<=N;i++){
        scanf("%d",&village[i]);
    }
    sort(village+1,village+N+1);
    for (int i=1,j=1;i<=N;i++){
        while (village[j]+R<village[i]) j++;
        f[i]=g[i-1]+1;
        g[i]=f[j-1]+1;
        for (int k=j;k<=i;k++){
            if (g[i]>f[k]+1) g[i]=f[k]+1;
            if (f[i]>g[k]) f[i]=g[k];
        }
        if (f[i]>g[i]) f[i]=g[i];
    }
    printf("%d\n",f[N]);
    return 0;
}