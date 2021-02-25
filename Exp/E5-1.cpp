#include<cstdlib>
#include<iostream>
#include<map>
#define maxn 1000005
#define maxm 10000005
using namespace std;
int N,M;
struct graph{
    int s,t,l;
} edge[maxm];
int pa[maxn];
bool cmp(graph a,graph b){
    return a.l<b.l;
}
int findf(int p){
    if (pa[p]==p) return p;
    else return pa[p]=findf(pa[p]);
}
int kruskal(){
    int p=0;
    int ans=0;
    for (int i=1;i<=N;i++) pa[i]=i;
    for (int i=1;i<=M;i++){
        int sp=findf(edge[i].s);
        int tp=findf(edge[i].t);
        if (sp==tp) continue;
        p++;
        if (sp>tp) swap(sp,tp);
        pa[tp]=sp;
        ans+=edge[i].l;
        if (p==N-1) break;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++){
        scanf("%d%d%d",&edge[i].s,&edge[i].t,&edge[i].l);
    }
    sort(edge+1,edge+M+1,cmp);
    printf("%d\n",kruskal());
    return 0;
}
