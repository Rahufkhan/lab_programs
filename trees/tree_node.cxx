#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* llink;
	struct node* rlink;
};
typedef struct node* NODE;
NODE insert_node(NODE root, int data){
	root=(NODE)malloc(sizeof(struct node));
	root->info=data;
	root->llink=NULL;
	root->rlink=NULL;
	if(root==NULL){
		printf("insufficient memory");
	}
	return root;
}
int main()
{
	NODE root;
	root=insertNode_bst(root,1);
	root->llink=insertNode_bst(root,2);
	root->rlink=insertNode_bst(root,3);
	
}