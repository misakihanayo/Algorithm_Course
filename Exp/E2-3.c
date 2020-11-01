#include<stdio.h>
#include<stdlib.h>
struct node{
    int l,r;
    struct node *left,*right;
} *root;
int query(struct node *root,int l,int r){
    if (!root) return 1;
    if (l<root->l){
        if (root->l<=r) return 0;
        return query(root->left,l,r);
    }
    else if (root->l==l) return 0;
    else {
        if (root->r>=l) return 0;
        return query(root->right,l,r);
    }
}
struct node* insert(struct node *root,int l,int r){
    struct node *tmp;
    if (!root){
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->l=l;tmp->r=r;
        tmp->left=tmp->right=NULL;
        root=tmp;
        return root;
    }
    if (l<root->l){
        root->left=insert(root->left,l,r);
        return root;
    }
    else {
        root->right=insert(root->right,l,r);
        return root;
    }
}
int main()
{
    int N;
    int i,l,r;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%d%d",&l,&r);
        if (query(root,l,r)){
            printf("0\n");
            root=insert(root,l,r);
        }
        else printf("-1\n");
    }
    return 0;
}
