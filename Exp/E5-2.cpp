#include<cstdlib>
#include<iostream>
#include<queue>
#define maxn 100005
#define maxm 1000005
using namespace std;
struct node{
    int nextnode,dist;
    node *next;
} *edge[maxn],pool[maxm*2];
int top;
int N,M,S,T;
void addedge(int f,int e,int l){
    node *tmp=&pool[top++];
    tmp->nextnode=e;
    tmp->dist=l;
    tmp->next=edge[f];
    edge[f]=tmp;
}
int dist[maxn];
bool flag[maxn];
struct v{
    int edge,value;
    friend bool operator < (v a,v b){
        return a.value > b.value;
    }
};
priority_queue<v> que;
int dijkstra(){
    for (int i=1;i<=N;i++){dist[i]=2147483647;flag[i]=false;}
    int nextnode=S;
    dist[S]=0;
    while (nextnode){
        flag[nextnode]=true;
        if (nextnode==T) break;
        for (node *p=edge[nextnode];p;p=p->next){
            if (dist[nextnode]+p->dist<dist[p->nextnode]){
                dist[p->nextnode]=dist[nextnode]+p->dist;
                v tmp;
                tmp.edge=p->nextnode;
                tmp.value=dist[p->nextnode];
                que.push(tmp);
            }
        }
        while (flag[que.top().edge]) que.pop();
        if (que.empty()) break;
        nextnode=que.top().edge;
        que.pop();
    }
    if (flag[T]) return dist[T];
    else return -1;
}
int main()
{
    scanf("%d%d%d%d",&N,&M,&S,&T);
    for (int i=1;i<=M;i++){
        int f,e,l;
        scanf("%d%d%d",&f,&e,&l);
        addedge(f,e,l);
    }
    printf("%d\n",dijkstra());
    return 0;
}
