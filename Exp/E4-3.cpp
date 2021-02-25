#include<cstdlib>
#include<iostream>

using namespace std;
int N,k;
struct list{
    int curt;
    list *next;
}*datahead[10005],*datatail[10005];
int cache[1005],top;
int a[10005];
int main()
{
    scanf("%d%d",&N,&k);
    for (int i=1;i<=N;i++){
        scanf("%d",&a[i]);
        list *tmp=new list;
        tmp->curt=i;
        tmp->next=NULL;
        if (!datatail[a[i]]) datahead[a[i]]=datatail[a[i]]=tmp;
        else{
            datatail[a[i]]->next=tmp;
            datatail[a[i]]=tmp;
        }
    }
    int ans=0;
    for (int i=1;i<=N;i++){
        bool flag=false;
        for (int j=1;j<=top;j++){
            if (cache[j]==a[i]){flag=true;break;}
        }
        if (!flag){
            ans++;
            if (top<k) cache[++top]=a[i];
            else{
                int kick;
                int maxnexttime=0;
                for (int j=1;j<=top;j++){
                    if (datahead[cache[j]]){
                        if (datahead[cache[j]]->curt>maxnexttime){
                            maxnexttime=datahead[cache[j]]->curt;
                            kick=j;
                        }
                    }
                    else{
                        maxnexttime=N+1;
                        kick=j;
                    }
                }
                cache[kick]=a[i];
            }
        }
        if (datahead[a[i]]) datahead[a[i]]=datahead[a[i]]->next;
    }
    printf("%d\n",ans);
    return 0;
}
