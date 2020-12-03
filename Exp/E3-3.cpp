#include<cstdlib>
#include<iostream>

using namespace std;
int dp[10005];
int w[10005],v[10005];
int top;
int main()
{
    int n,W;
    scanf("%d%d",&n,&W);
    for (int i=1;i<=n;i++){
        int wi,vi,numi;
        scanf("%d%d%d",&wi,&vi,&numi);
        for (int j=1;j<=numi;j<<=1){
            w[++top]=wi*j;
            v[  top]=vi*j;
            numi-=j;
        }
        w[++top]=wi*numi;
        v[top]=vi*numi;
    }
    for (int i=1;i<=top;i++){
        for (int j=W;j>=w[i];j--){
            if (dp[j]<dp[j-w[i]]+v[i])
                dp[j]=dp[j-w[i]]+v[i];
        }
    }
    printf("%d\n",dp[W]);
    return 0;
}
