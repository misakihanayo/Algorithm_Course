#include<stdio.h>
int hash1[20000005];
int hash2[20000005];
int key[10000005];
int cal_hash(char *p){
    int i,c=0;
    for (i=0;p[i];i++){
        c=c*26+p[i]-'a';
    }
    return c;
}
int main()
{
    int N,k;
    char p[8];
    int i,s1,s2,t,h,cnt;
    scanf("%d%d",&N,&k);
    for (i=1;i<=N;i++){
        scanf("%s",p);
        key[i]=cal_hash(p);
    }
    s1=s2=1;
    h=0;
    cnt=0;
    for (i=1;i<=N;i++){
        if (!hash1[key[i]]) h++;
        hash1[key[i]]++;
        hash2[key[i]]++;
        if (h==k){
            while (hash2[key[s2]]-1){
                hash2[key[s2]]--;
                s2++;
            }
            cnt+=s2-s1+1;
        }
        else if (h>k) {
            while (s1<=s2){
                hash1[key[s1]]--;
                s1++;
            }
            hash2[key[s2]]--;
            s2++;
            h--;
            while (hash2[key[s2]]-1){
                hash2[key[s2]]--;
                s2++;
            }
            cnt+=s2-s1+1;
        }
        //printf("s1=%d s2=%d h=%d\n",s1,s2,h);
    }
    printf("%d\n",cnt);
    return 0;
}