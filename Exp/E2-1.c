#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int key;
    int heap;
    struct node *left,*right;
} *root;
int top;
struct node* insert(struct node *root,int key){
    if (!root){
        struct node *tmp=(struct node*)malloc(sizeof(struct node));
        tmp->key=key;
        tmp->heap=rand();
        tmp->left=tmp->right=NULL;
        root=tmp;
        return tmp;
    }
    if (key==root->key) return root;
    else if (key<=root->key){
        root->left=insert(root->left,key);
        if (root->left->heap<root->heap){
            struct node *tmp=root->left;
            root->left=tmp->right;
            tmp->right=root;
            root=tmp;
        }
        return root;
    }
    else{
        root->right=insert(root->right,key);
        if (root->right->heap<root->heap){
            struct node *tmp=root->right;
            root->right=tmp->left;
            tmp->left=root;
            root=tmp;
        }
        return root;
    }
}
int find_upper(struct node *root,int key,int cur_upper){
    if (!root) return cur_upper;
    if (root->key==key) return key;
    if (root->key>key) return find_upper(root->left,key,cur_upper);
    else if (root->key>cur_upper) return find_upper(root->right,key,root->key);
    else return find_upper(root->right,key,cur_upper);
}
int main()
{
    char s[10];
    int key;
    while (~scanf("%s",s)){
        if (!strcmp(s,"INSERT")){
            scanf("%d",&key);
            root=insert(root,key);
        }
        else if (!strcmp(s,"FIND")){
            scanf("%d",&key);
            printf("%d\n",find_upper(root,key,0));
        }
        else break;
    }
    return 0;
}
