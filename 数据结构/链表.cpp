//单调递增链表
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct list{
	int n;
	struct list *next;
};

void insert(struct list *head, int n)
{
	struct list *p,*q,*point;
	point = (struct list *)malloc(sizeof(struct list));
	point->n = n;
	point->next = NULL;
	head->n += 1;//存链表长度 
	if(head->next==NULL)
	{
		head->next = point;
	}
	else
	{
		p = head;
		q = head->next;
		while(q->n < n)
		{
			p = q;
			q = q->next;
			if(q==NULL)
			{
				p->next = point;
			}
		}
		p->next = point;
		point->next = q;
	}
}

//链表翻转,注意插入的时候point->next是否为NULL 
void reverse_list(struct list *head)
{
	struct list *pre,*cur,*temp;
	cur = head->next;
	pre = NULL;

	while(cur)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	head->next = pre; 
}

int main()
{
	struct list *head,*temp;
	head = (struct list *)malloc(sizeof(struct list));
	head->n = 0;
	head->next = NULL;
	for(int i=100; i>=0; i--)
	{
		insert(head, i);
	}
	
	reverse_list(head);
	
	temp = head->next;
	for(int i=0; i<head->n; i++)
	{
		cout << temp->n << endl;
		temp = temp->next;
	}
	
	return 0;
}