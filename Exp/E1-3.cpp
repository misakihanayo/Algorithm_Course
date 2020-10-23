#include<cstdlib>
#include<iostream>

using namespace std;
const int maxn=10000005;
int pos[maxn];
void quick_sort(int left,int right){    
    if (left>=right) return;
    int l=left,r=right-1;
    while (l<=r){
        if (pos[l]>pos[right]){
            swap(pos[l],pos[r]);
            r--;
        }
        else l++;
    }
    swap(pos[l],pos[right]);
    quick_sort(left,l-1);
    quick_sort(l+1,right);
}
int main()
{
    int N;
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
    	scanf("%d",&pos[i]);
    }
    quick_sort(1,N);
    int maxq=0;
    for (int i=2;i<=N;i++){
    	if (pos[i]-pos[i-1]>maxq) maxq=pos[i]-pos[i-1];
    }
    printf("%d\n",maxq);
    return 0;
}

