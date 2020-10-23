#include<cstdlib>
#include<iostream>
#include<cstring>
#define module 10000019;
using namespace std;
struct node{
    int key;
    int value;
    node *left,*right;
} *root,pool[1000005];
int top;
int get_left_value(node *root){
    if (root->left) return root->left->value;
    else return 0;
}
int insert(node *&root,int key){
    if (!root){
        node *tmp=&pool[top++];
        tmp->key=key;
        tmp->value=1;
        tmp->left=tmp->right=NULL;
        root=tmp;
        return 1;
    }
    root->value++;
    if (key<root->key){
        return insert(root->left,key);
    }
    else {
        return get_left_value(root)+1+insert(root->right,key);
    }
}
int main()
{
    int N,a;
    int count=0;
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        scanf("%d",&a);
        count+=i-insert(root,a);
        count%=module;
    }
    printf("%d\n",count);
    return 0;
}
