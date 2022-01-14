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

void preorder(NODE root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}

void postorder(NODE root){
	if(root==NULL){
		return;
	}
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d ",root->info);
}

void inorder(NODE root){
	if(root==NULL){
		return;
	}
	inorder(root->llink);
	printf("%d ",root->info);
	inorder(root->rlink);
}
int main()
{
	NODE root;
	root=insert_node(root,1);
	root->llink=insert_node(root,2);
	root->rlink=insert_node(root,3);
	

	/*		  1
				/  \
			  2	3
	*/	
		 		
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	inorder(root);
}