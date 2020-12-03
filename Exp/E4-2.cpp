#include<cstdlib>
#include<iostream>
#include<stack>
#include<algorithm>
#define maxn 100005
#define maxt 100000005
using namespace std;
int N;
struct tasks{
    int st;
    int ed;
    int tm;
} p[maxn];
bool cmp(tasks a,tasks b){
    return a.ed<b.ed || a.ed==b.ed && a.tm<b.tm;
}
stack <tasks> sta;
int main()
{
    scanf("%d",&N);
    int ans=0;
    for (int i=1;i<=N;i++){
        scanf("%d%d",&p[i].st,&p[i].tm);
        p[i].ed=p[i].st+p[i].tm-1;
        ans+=p[i].tm;
    }
    sort(p+1,p+N+1,cmp);
    for (int i=1;i<=N;i++){
        while (!sta.empty()){
            if (sta.top().ed>=p[i].st){
                if (p[i].st>sta.top().st) p[i].st=sta.top().st;
                p[i].tm+=sta.top().tm;
                sta.pop();
            }
            else break;
        }
        ans+=p[i].st+p[i].tm-1-p[i].ed;
        p[i].ed=p[i].st+p[i].tm-1;
        sta.push(p[i]);
    }
    printf("%d\n",ans);
    return 0;
}
