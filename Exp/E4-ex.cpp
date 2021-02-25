#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
int p[200005];
int main(){
    scanf("%d%d",&N,&M);
    int l=0,r=20000000;
    for (int i=1;i<=N;i++){
        scanf("%d",&p[i]);
    }
    sort(p+1,p+N+1);
    while (l<r){
        int tmp=(l+r+1)/2;
        int prev=p[1];
        int count=M;
        for (int i=2;i<=N;i++){
            if (p[i]-prev<tmp){
                count--;
                if (count<0) break;
            }
            else{
                prev=p[i];
            }
        }
        if (count<0) r=tmp-1;
        else l=tmp;
    }
    printf("%d\n",l);
    return 0;
}