#include<cstdlib>
#include<iostream>

using namespace std;
struct count{
	int key;
	int count;
} number[1005];
int top;
int main(int argc,char *argv[])
{
	int N;
	int a;
	scanf("%d",&N);
	top=0;
	for (int i=1;i<=N;i++){
		scanf("%d",&a);
		bool flag=false;
		for (int j=1;j<=top;j++){
			if (number[j].key==a){
				number[j].count++;
				flag=true;
			}
		}
		if (!flag){
			number[++top].key=a;
			number[top].count=1;
		}
	}
	for (int i=1;i<top;i++){
		for (int j=i+1;j<=top;j++){
			if (number[i].count<number[j].count || number[i].count==number[j].count && number[i].key>number[j].key)
				swap(number[i],number[j]);	
		}
	}
	for (int i=1;i<=top;i++)
		printf("%d %d\n",number[i].key,number[i].count);
	return 0;
}
