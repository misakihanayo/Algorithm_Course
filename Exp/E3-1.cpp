#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int x,y;
    int maxvalue;
} p[10005];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main()
{
    int N;
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].maxvalue=1;    
    }
    sort(p+1,p+N+1,cmp);
    int maxv=0;
    for (int i=1;i<=N;i++){
        for (int j=i-1;j>=1;j--){
            if (p[i].x>=p[j].x && p[i].y>=p[j].y){
                if (p[i].maxvalue<p[j].maxvalue+1)
                    p[i].maxvalue=p[j].maxvalue+1;
            }
        }
        if (p[i].maxvalue>maxv) maxv=p[i].maxvalue;
    }
    printf("%d\n",maxv);
    return 0;
}