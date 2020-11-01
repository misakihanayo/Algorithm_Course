#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int flag[100005];
int opp[100005];
struct combine{
    int l,r,w;
} obj[1000005];
bool cmp(combine a,combine b){
    return a.w>b.w;
}
int findp(int x){
    if (flag[x]==x) return x;
    else return flag[x]=findp(flag[x]);
}
bool check(int l,int r){
    int lp=findp(l);
    int rp=findp(r);
    if (lp==rp) return false;
    return true;
}
void merge(int l,int r){
    int lp=findp(l);
    int rp=findp(r);
    if (lp>rp) swap(lp,rp);
    flag[rp]=lp;
}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++){
        scanf("%d%d%d",&obj[i].l,&obj[i].r,&obj[i].w);
    }
    for (int i=1;i<=N;i++){
        flag[i]=i;
    }
    sort(obj+1,obj+M+1,cmp);
    bool boom=true;
    for (int i=1;i<=M;i++){
        if (!check(obj[i].l,obj[i].r)){
            printf("%d\n",obj[i].w);
            boom=false;
            break;
        }
        if (!opp[obj[i].l]) opp[obj[i].l]=obj[i].r;
        else merge(opp[obj[i].l],obj[i].r);
        if (!opp[obj[i].r]) opp[obj[i].r]=obj[i].l;
        else merge(opp[obj[i].r],obj[i].l);
    }
    if (boom) printf("0\n");
    return 0;
}
//为什么这个实验居然会出并查集的题目啊.jpeg