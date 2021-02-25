#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N;
struct work{
    int st;
    int tm;
} tasks[100005];
bool cmp(work a,work b){
    return a.st<b.st;
}
int ans;
priority_queue<int,vector<int>,greater<int> > que;
int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        scanf("%d%d",&tasks[i].st,&tasks[i].tm);
    }
    sort(tasks+1,tasks+N+1,cmp);
    for (int i=1;i<=N;i++){
        int curtime=tasks[i].st-tasks[i-1].st;
        while (!que.empty() && curtime>0){
            int tmp=que.top();
            que.pop();
            if (curtime>=tmp){
                ans+=tmp*(que.size()+1);
                curtime-=tmp;
            }
            else{
                ans+=curtime*(que.size()+1);
                tmp-=curtime;
                que.push(tmp);
                break;
            }
        }
        que.push(tasks[i].tm);
    }
    while (!que.empty()){
        int tmp=que.top();
        que.pop();
        ans+=tmp*(que.size()+1);
    }
    printf("%d\n",ans);
    return 0;
}
