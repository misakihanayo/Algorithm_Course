#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 10005
using namespace std;

stack<int>sta;
vector<int>gra[N];
vector<int>gra_[N];
map<int,bool> flag[N];
int maxn[N],tmp[N];
int degree[N];
int dfn[N],low[N],now,vis[N],sum;
int f[N];
int n,m;

void ini(void)
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    now=sum=0;
    for(int i=1;i<=n;i++)
        gra[i].clear();
    while(sta.empty()==0)
        sta.pop();
}

void tarjan(int s,int p)
{
    vis[s]=2;
    dfn[s]=low[s]=++now;
    sta.push(s);
    for(int i=0;i<gra[s].size();i++)
    {
        int t=gra[s][i];
        if(!dfn[t])
            tarjan(t,s),low[s]=MIN(low[s],low[t]);
        else
            if(vis[t]==2)
                low[s]=MIN(low[s],dfn[t]);
    }
    if(low[s]==dfn[s])
    {
        sum++;
        while(!sta.empty())
        {
            int t=sta.top();
            sta.pop();
            vis[t]=1;
            f[t]=sum;
            if(t==s)break;
        }
    }
}

void re(void)
{
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        gra[a].push_back(b);
    }
}

void run(void)
{
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i,0);
}
void mkg()
{
    for (int i=1;i<=n;i++){
        maxn[f[i]]++;
        for (int p=0;p<gra[i].size();p++){
            if (f[gra[i][p]]!=f[i] && !flag[f[i]][f[gra[i][p]]]){
                gra_[f[i]].push_back(f[gra[i][p]]);
                flag[f[i]][f[gra[i][p]]]=true;
            }
        }
    }
    for (int i=1;i<=sum;i++){
        for (int p=0;p<gra_[i].size();p++){
            degree[gra_[i][p]]++;
        }
    }
    int ans=0;
    for (int i=1;i<=sum;i++){
        for (int j=1;j<=sum;j++){
            if (degree[j]==0){
                maxn[j]+=tmp[j];
                degree[j]=-1;
                if (maxn[j]>ans) ans=maxn[j];
                for (int p=0;p<gra_[j].size();p++){
                    degree[gra_[j][p]]--;
                    if (tmp[gra_[j][p]]<maxn[j]) tmp[gra_[j][p]]=maxn[j];
                }
                break;
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d%d",&n,&m);
    ini();
    re();
    run();
    mkg();
}