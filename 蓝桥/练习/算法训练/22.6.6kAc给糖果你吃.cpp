#include<stdio.h>
//22.6.6À¶ÇÅ±­ kAc¸øÌÇ¹ûÄã³Ô 
#include<stdlib.h>
struct node
{
	int data;
	node* next;
};

node* insert(node* head,int x)
{
	node* f=head,*p;
	if(head==NULL)
	{
		head=(node*)malloc(sizeof(node));
		head->data=x;
		head->next=NULL;
	}
	else
	{
		p=(node*)malloc(sizeof(node));
		p->data=x;
		p->next=NULL;
		if(f->data<x)
		{
			p->next=head;
			head=p;
		}
		else{
			while(f->next!=NULL)
			{
				if(f->next->data<x)
				{
					p->next=f->next;
					f->next=p;
					break;
				}
				f=f->next;
			}
		if(f->next==NULL)
		{
			f->next=p;
		}
		}
	}
	return head;
}

int main()
{
	node *head=NULL,*p;
	int n,m;
	long long sum=0;
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		head=insert(head,k);
	}
	for(i=0;i<m;i++)

	{
		sum+=head->data;
		p=head;
		head=head->next;
		free(p);
	}
	printf("%lld",sum);
	system("pause");
	return 0;
}
