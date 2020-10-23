#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
struct node{
    int key;
    int id;
    int value;
    node *left,*right;
} *root,pool[1000005];
int top;
void insert(node *&root,int id,int key){
    if (!root){
        node *tmp=&pool[top++];
        tmp->key=key;
        tmp->id=id;
        tmp->value=1;
        tmp->left=tmp->right=NULL;
        root=tmp;
        return;
    }
    root->value++;
    if (key<=root->key){
        insert(root->left,id,key);
    }
    else {
        insert(root->right,id,key);
    }
}
int query(node *root,int key){
    if (!root) return -1;
    if (root->key==key) return root->id;
    if (root->key<=key) return query(root->right,key);
    return query(root->left,key);
}
int main()
{
    char p[10];
    int id,k;
    int iter;
    while (scanf("%s",p)){
        if (strcmp(p,"INSERT")==0){
            scanf("%d%d",&id,&k);
            insert(root,id,k);
        }
        else if (strcmp(p,"FIND")==0){
            scanf("%d",&k);
            printf("%d\n",query(root,k));
        }
        else break;
    }
    return 0;
}
