#include<stdlib.h>
#include<stdio.h>
int flag[5000005];
int t;
int findp(int x){
    if (flag[x]==x) return x;
    else return flag[x]=findp(flag[x]);
}
int check(int l,int r){
    int lp=findp(l);
    int rp=findp(r);
    if (lp==rp) return 1;
    return 0;
}
void merge(int l,int r){
    int lp=findp(l);
    int rp=findp(r);
    if (lp>rp){
        t=lp;
        lp=rp;
        rp=t;
    }
    flag[rp]=lp;
}
int main()
{
    int N,M,k;
    int a,b,i;
    scanf("%d%d%d",&N,&k,&M);
    for (i=1;i<=N;i++){
        flag[i]=i;
    }
    for (i=1;i<=M;i++){
        scanf("%d%d",&a,&b);
        merge(a+1,b+1);
    }
    for (int i=1;i<=k;i++){
        scanf("%d%d",&a,&b);
        printf("%d",check(a+1,b+1));
        if (i<k) printf(" ");
    }
    return 0;
}
//为什么这个实验居然会出并查集的题目啊.jpeg