#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node*left,*right;};

struct Node*newNode(int val){
    if(val==-1) return NULL;
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->data=val;node->left=node->right=NULL;
    return node;
}

int height(struct Node*root){
    if(!root) return 0;
    int lh=height(root->left),rh=height(root->right);
    return (lh>rh?lh:rh)+1;
}

struct Node*buildTree(int arr[],int n){
    if(n==0) return NULL;
    struct Node*nodes[n];
    for(int i=0;i<n;i++) nodes[i]=newNode(arr[i]);
    for(int i=0,j=1;j<n;i++){
        if(nodes[i]){
            if(j<n) nodes[i]->left=nodes[j++];
            if(j<n) nodes[i]->right=nodes[j++];
        }
    }
    return nodes[0];
}

int main(){
    int n;scanf("%d",&n);
    int arr[n];for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    struct Node*root=buildTree(arr,n);
    printf("%d\n",height(root));
    return 0;
}