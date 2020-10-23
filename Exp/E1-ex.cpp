#include<cstdlib>
#include<iostream>

using namespace std;
const int maxn=1000005;
int N,K;
int a[maxn],bitree[maxn];
int lowbit(int i){
	return (-i)&i;
}
int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		for (int j=i;j<=N;j+=lowbit(j)){
			if (a[i]>bitree[j]) bitree[j]=a[i];
		}
	}
	int ans=0;
	for (int i=1;i+K-1<=N;i++){
		ans=0;
		for (int j=i+K-1;j>=i;){
			if (j-lowbit(j)>i){
				ans=bitree[j]>ans?bitree[j]:ans;
				j-=lowbit(j);
			}
			else{
				ans=a[j]>ans?a[j]:ans;
				j--;
			}
		}
		printf("%d",ans);
		if (i+K-1<N) printf(" "); 
	}
	return 0;
}

