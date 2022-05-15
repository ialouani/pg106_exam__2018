#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int value;
};

struct Node *new_node(int v){
  struct Node *n=malloc(sizeof(*n));
  n->left=NULL;
  n->right=NULL;
  n->value=v;
  return n;
}

void print_tree_rec(struct Node *n,int level){
  int i;
  if (n==NULL) return;
  for(i=0;i<level;++i)
    printf(" ");
  printf("%d\n",n->value);
  print_tree_rec(n->left,level+1);
  print_tree_rec(n->right,level+1);
}

void print_tree(struct Node *n){
  print_tree_rec(n,0);
}

void add(struct Node *a, struct Node *b){
  if (b->value<a->value){
    if (a->left==NULL) a->left=b;
    else add(a->left,b);
  } else {
    if (a->right==NULL) a->right=b;
    else add(a->right,b);    
  }
}

struct Node *build_tree(int *values,int s){
  int i;
  if (s<=0) return NULL;
  struct Node *root=new_node(values[0]);
  for(i=1;i<s;++i){
    add(root,new_node(values[i]));
  }
  return root;
}

void free_tree(struct Node *n){
  if (n==NULL) return;
  free_tree(n->left);
  free_tree(n->right);
  free(n);
}


int main(){
  int t[8]={5,4,2,10,11,6,1,8};
  struct Node * n=build_tree(t,8);
  print_tree(n);
  free_tree(n);
}
