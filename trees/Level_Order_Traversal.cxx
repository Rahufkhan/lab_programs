#include<stdio.h>
#include<stdlib.h>
struct node{
	char info;
	struct node* llink;
	struct node* rlink;
};
typedef struct node* NODE;
NODE insert_node(NODE root, char data){
	root=(NODE)malloc(sizeof(struct node));
	root->info=data;
	root->llink=NULL;
	root->rlink=NULL;
	if(root==NULL){
		printf("insufficient memory");
	}
	return root;
}
void Level_Order_Traversal(NODE root){
	NODE queue[50],cur;
	int rear=-1, front=0;
	queue[++rear]=root;
	
	while(front<=rear){
		cur=queue[front++];
		printf("%c ",cur->info);
		
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
	NODE root;
	root=insert_node(root, 'A');
	root->llink=insert_node(root, 'B');
	root->llink->llink=insert_node(root, 'D');
	root->llink->llink->llink=insert_node(root, 'G');
	root->llink->llink->rlink=insert_node(root, 'H');	
	root->rlink=insert_node(root, 'C');
    root->rlink->llink=insert_node(root, 'E');
	root->rlink->llink->rlink=insert_node(root, 'I');
	root->rlink->rlink=insert_node(root, 'F');    	
    
	/*       A
			/	\  
		  B	  C
		/		/  \
	  D		E    F
	 /  \		\
   G   H        I
   
   */
	Level_Order_Traversal(root);
}