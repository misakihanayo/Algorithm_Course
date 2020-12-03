#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    int value;
    int heap;
    struct node *left,*right;
} *root,pool[2000005];
int top;
int getvalue(struct node *root){
    if (root) return root->value;
    else return 0;
}
struct node* insert(struct node *root,int key){
    struct node *tmp;
    if (!root){
        tmp=&pool[top++];
        tmp->key=key;
        tmp->value=1;
        tmp->heap=rand();
        tmp->left=tmp->right=NULL;
        return tmp;
    }
    ++root->value;
    if (key<=root->key){
        root->left=insert(root->left,key);
        if (root->heap>root->left->heap){
            tmp=root->left;
            root->left=tmp->right;
            tmp->right=root;
            root->value=getvalue(root->left)+getvalue(root->right)+1;
            tmp->value=getvalue(tmp->left)+getvalue(tmp->right)+1;
            root=tmp;
        }
        return root;
    }
    else{
        root->right=insert(root->right,key);
        if (root->heap>root->right->heap){
            tmp=root->right;
            root->right=tmp->left;
            tmp->left=root;
            root->value=getvalue(root->left)+getvalue(root->right)+1;
            tmp->value=getvalue(tmp->left)+getvalue(tmp->right)+1;
            root=tmp;
        }
        return root;
    }
}
struct node* merge(struct node *L,struct node *R){
    if (!L) return R;
    else if (!R) return L;
    if (L->heap<R->heap){
        L->right=merge(L->right,R);
        L->value=getvalue(L->left)+getvalue(L->right)+1;
        return L;
    }
    else{
        R->left=merge(L,R->left);
        R->value=getvalue(R->left)+getvalue(R->right)+1;
        return R;
    }
}
struct node* delete(struct node *root,int key){
    if (root->key==key){
        root=merge(root->left,root->right);
    }
    else if (key<root->key){
        if (root->left)
            root->left=delete(root->left,key);
    }
    else{
        if (root->right)
            root->right=delete(root->right,key);
    }
    if (root) root->value=getvalue(root->left)+getvalue(root->right)+1;
    return root;
}
int query(struct node *root,int rank){
    int cur_rank=getvalue(root->left)+1;
    if (cur_rank==rank) return root->key;
    else if (cur_rank<rank) return query(root->right,rank-cur_rank);
    else return query(root->left,rank);
}
int main()
{
    int N;
    char method;int time;
    scanf("%d",&N);
    getchar();
    while (N--){
        method=getchar();
    	getchar();
	    scanf("%d",&time);
        if (method=='I'){
            root=insert(root,time);
        }
        else if (method=='D'){
            root=delete(root,time);
        }
        else{
            printf("%d\n",query(root,time));
        }
	getchar();
    }
    return 0;
}
