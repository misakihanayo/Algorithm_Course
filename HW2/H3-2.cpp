#include<cstdlib>
#include<iostream>

using namespace std;
struct student{
    int id;
    int math;
    int eng;
    int score;
    void getscore(){
        score=math+eng;
    }
} stu[2500100];
void swap(student &a,student &b){
    student tmp;
    tmp=a;
    a=b;
    b=tmp;
}
bool cmp(student a,student b){
    if (a.score>b.score) return false;
    else if (a.score==b.score){
        if (a.math>b.math) return false;
        else if (a.math==b.math){
            if (a.eng>b.eng) return false;
            else if (a.eng==b.eng){
                if (a.id>b.id) return false;
            }
        }
    }
    return true;
}
void quick_sort(int left,int right){
    if (left>=right) return;
    int l=left,r=right-1;
    while (l<=r){
        if (cmp(stu[l],stu[right])){
            swap(stu[l],stu[r]);
            r--;
        }
        else l++;
    }
    swap(stu[l],stu[right]);
    quick_sort(left,l-1);
    quick_sort(l+1,right);
}
int main()
{
    int N;
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        scanf("%d%d%d",&stu[i].id,&stu[i].math,&stu[i].eng);
        stu[i].getscore();
    }
    quick_sort(1,N);
    for (int i=1;i<=N;i++){
        printf("%d ",stu[i].id);
    }
    return 0;
}
