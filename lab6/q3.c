#include "stdio.h"
#include "stdlib.h"
 
struct RandomListNode {
  int label;
  struct RandomListNode *next;
  struct RandomListNode *random;
};
 
struct RandomListNode *new_node(int val)
{
  struct RandomListNode *node = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
  node->label = val;
  node->next = node->random = NULL;
  return node;
}
 
void insert(struct RandomListNode **head, int val)
{
  struct RandomListNode *node = new_node(val);
  if (*head == NULL) {
    *head = node;
    return;
  }
  struct RandomListNode *tmp = *head;
  while(tmp->next) {
    tmp = tmp->next;
  }
  tmp->next = node;
}
 
void print_it(struct RandomListNode *tmp)
{
  printf("\n");
  while(tmp) {
    printf("%d ", tmp->label);
    tmp = tmp->next;
  }
}
 
struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
  if (head==NULL) {
    return head;
  }
 
  struct RandomListNode *tr = head;
  int len=0;
  while (tr) {
    tr=tr->next;
    len++;
  }
  struct RandomListNode **arr = (struct RandomListNode**)malloc(sizeof(struct RandomListNode)*len);
  tr = head;
  int i=0;
  while(tr) {
    arr[i] = tr;
    i++;
    tr=tr->next;
  }
 
  struct RandomListNode *new_list_head = new_node(0);
 
  struct RandomListNode *tmp = head;
 
  struct RandomListNode *p = new_list_head;
  while (tmp) {
    p->next = new_node(tmp->label);
    p->next->random = tmp;
 
    struct RandomListNode *store = tmp->next;
    tmp->next = p->next;
 
    tmp = store;
    p = p->next;
  }
  // using p again
  p = new_list_head;
 
  while (p->next && p->next->random) {
    struct RandomListNode *store = p->next->random->random;
 
    if (store) {
      p->next->random = store->next;
    } else {
      p->next->random = NULL;
    }
    p = p->next;
  }
  i=1;
  while(i != len) {
    arr[i-1]->next = arr[i];
    i++;
  }
  arr[i-1]->next=NULL;
 
  return new_list_head->next;
}
 
int main()
{
  struct RandomListNode *root = NULL,*root1;
  insert(&root, 1);
  insert(&root, 2);
  insert(&root, 3);
  // 1-->3
  root->random = root->next->next;
  // 2-->3
  root->next->random = root->next->next;
  // 3-->2
  root->next->next->random = root->next;
  print_it(root);
  root1 = copyRandomList(root);
  print_it(root1);
 
  return 0;
}