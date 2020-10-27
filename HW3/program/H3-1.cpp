#include<cstdlib>
#include<iostream>

using namespace std;
int N,k;
int hash_key[10005];
int main()
{
	scanf("%d%d",&N,&k);
	int a;
	for (int i=1;i<=N;i++){
		scanf("%d",&a);
		hash_key[a]++;
	}
	a=-1;
	while (k) k-=hash_key[++a];
	printf("%d\n",a);
	return 0;
}

