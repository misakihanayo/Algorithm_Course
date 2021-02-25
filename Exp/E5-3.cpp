#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
using namespace std;
struct Node{
    int e,c;
    bool flag;
    Node *next,*opt;
} *edge[100005],pool[2000005];
int top;int queue[100005],level[100005];
int S,T;
int N,M;
int mp[505][505];
void build(int f,int e,int l)
{
    Node *p=&pool[++top],*q=&pool[++top];
    p->e=e;p->c=l;p->flag=false;p->next=edge[f];edge[f]=p;p->opt=q;
    q->e=f;q->c=0;q->flag=true;q->next=edge[e];edge[e]=q;q->opt=p;
}
bool makelevel()
{
    int x=0,bot;
    memset(level,0xff,sizeof(level));
    queue[0]=S;
    level[queue[0]]=0;bot=1;
    for (int top=0;top<bot;top++){
        x=queue[top];
        for (Node *p=edge[x];p;p=p->next)
            if (p->c && level[p->e]==-1)
                level[queue[bot++]=p->e]=level[x]+1;
    }
    return level[T]!=-1;
}
int find(int u,int alpha)
{
    if (u==T) return alpha;
    int t,w;
    w=0;
    for (Node *p=edge[u];p && w<alpha;p=p->next){
        if (p->c>0 && level[p->e]==level[u]+1){
            if (t=find(p->e,min(p->c,alpha-w))){
                p->c-=t;
                p->opt->c+=t;
                w+=t;
            }
        }
    }
    if (!w) level[u]=-1;
    return w;
}
void dinic()
{
    int res=0,t;
    while (makelevel()){
        while (t=find(S,2147483647)){res+=t;}
    }
    printf("%d\n",res);
}
int main(int argc,char *argv[])
{
    scanf("%d%d%d%d",&N,&M,&S,&T);
    top=0;
    for (int i=1;i<=M;i++){
        int f,e,l;
        scanf("%d%d%d",&f,&e,&l);
        mp[f][e]+=l;
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            if (mp[i][j]>0) build(i,j,mp[i][j]);
        }
    }
    build(0,S,100000000);
    build(T,N+1,10000000);
    S=0;
    T=N+1;
    dinic();
    return 0;
}