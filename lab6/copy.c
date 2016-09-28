/*Piyush Anand
B15226
lab 6
ques 3*/
#include "stdio.h"
#include "stdlib.h"
 
typedef struct RandomListNode {
  int label;
  struct RandomListNode *next;
  struct RandomListNode *random;
}listnode;
 
listnode *new_node(int val)
{
  listnode *node = (listnode*)malloc(sizeof(listnode));
  node->label = val;
  node->next =NULL;
  node->random = NULL;
  return node;
}


void printit(listnode *temp)
{
	listnode *tmp = temp;
  while(tmp!=NULL) 
  {
  	// printf("hey");
    printf("%d ",tmp->label);
    // printf("%p \n",tmp->random);
    tmp = tmp->next;
  }
  printf("\n");
}

void insert(listnode **head, int val)
{
  listnode *node = new_node(val);
  if (*head == NULL) {
    *head = node;
    return;
  }
  listnode *tmp = *head;
  while(tmp->next!=NULL) {
    tmp = tmp->next;
  }
  tmp->next = node;
  // node->next=NULL;
}
 
int main()
{
  listnode *head1;
  listnode *head=NULL;
  int n;
  listnode *temp,*prev;
  printf("enter no. of elements : ");
  scanf("%d",&n);
  int i,j=1,k;
  for(i=0;i<n;i++)
  {
  	printf("enter element: ");
  	scanf("%d",&j);
  	insert(&head,j);
  }
  // printit(head);
  prev=head;
  for(i=0;i<n;i++)
  {
  	printf("To which node random pointer of %d points ? \n",(i+1));
  	scanf("%d",&k);
  	temp=head;
  	j=1;
  	while(j<k)
  	{
  		temp=temp->next;
  		j++;
  	}
  	prev->random=temp;
  	prev=prev->next;
  }
  printf("Original List:\n");
  printit(head);

  temp=head;
  // printf("hey\n");
  while(temp!=NULL)
  {
  		listnode *node=new_node(temp->label);
  		node->next=temp->next;
  		temp->next=node;
  		temp=(temp->next)->next;
  }
  // printf("hey\n");
  prev=head;
  temp=head->next;
  while(prev!=NULL)
  {
  		temp->random=prev->random->next;
  		if(temp->next!=NULL)
  		temp=(temp->next)->next;
  		prev=(prev->next)->next;
  }
  head1=head->next;
  temp=head;
  prev=head1;
  while(temp!=NULL)
  {
  	temp->next=(temp->next)->next;
  	if((prev->next)!=NULL)
  	prev->next=(prev->next)->next;
  	
  	prev=prev->next;
  	temp=temp->next;
  }
  	printf("Copied List: \n");
  // head1 = copyRandomList(head);
  	// printit(head);
  printit(head1);
  return 0;
}