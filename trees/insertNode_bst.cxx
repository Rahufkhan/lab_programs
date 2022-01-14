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

NODE insertNode_bst(NODE root, int data){
	NODE temp ,prev,cur;
	if(root==NULL){
	    temp=insert_node(root, data);
		return temp;
	}
	temp=insert_node(root, data);
	prev=NULL;
	cur=root;
	while(cur!=NULL){
		prev=cur;
		if(data==cur->info){
			printf("Duplication item not allowed");
			free(temp);
			return root;
		}
		
		if(data<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;
		
	}
	if(data<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	
	return root;
}

void Level_Order_Traversal(NODE root){
	NODE queue[100],cur;
	int rear=-1, front=0;
	queue[++rear]=root;
	
	while(front<=rear){
		cur=queue[front++];
		printf("%d ",cur->info);
		
		if(cur->llink!=NULL){
			queue[++rear]=cur->llink;
		}
		if(cur->rlink!=NULL){
			queue[++rear]=cur->rlink;
		}
	}
}

int main()
{
	NODE root=NULL;
	root=insertNode_bst(root,100);
	insertNode_bst(root,50);
	insertNode_bst(root,200);
	insertNode_bst(root,25);
	insertNode_bst(root,90);
	insertNode_bst(root,150);
	insertNode_bst(root,300);
	insertNode_bst(root,80);
	insertNode_bst(root,140);
	insertNode_bst(root,180);

	/*
					100
			     /	      \
			 50     	  200
		    /   \          /     \
		25     90	150   300
				/		/	\
			 80	 140  180
	*/
	
	Level_Order_Traversal(root);
	
}