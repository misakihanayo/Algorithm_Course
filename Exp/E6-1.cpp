#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
char T[10005];
char P[1000005];
int nextT[10005];
int main()
{
    int num_of_cases;
    cin >> num_of_cases;
    getchar();
    while (num_of_cases--){
        cin.getline(T,10000);
        cin.getline(P,1000005);
        int lengthT=strlen(T);
        int lengthP=strlen(P);
        nextT[0]=-1;
        int k=-1;
        for (int i=1;i<lengthT;i++){
            while (k>0 && T[k+1]!=T[i]){
                k=nextT[k];
            }
            if (T[k+1]==T[i]) k++;
            nextT[i]=k;
        }
        k=-1;
        int ans=0;
        for (int i=0;i<lengthP;i++){
            while (k>0 && T[k+1]!=P[i]) k=nextT[k];
            if (T[k+1]==P[i]) k++;
            if (k==lengthT-1){
                ans++;
                k=nextT[k];
            }
        }
        cout << ans << endl;
    }
    return 0;
}