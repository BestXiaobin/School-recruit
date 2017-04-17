#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int DataType;
typedef struct
{
	DataType data[MAXSIZE];
	int front;
	int rear;
}SeqQueue;
void InitQueue(SeqQueue * q){ //�ÿն�
	 q->front=q->rear=MAXSIZE-1;
}
int EmptyQueue(SeqQueue * q){//�жӿ�
	if(q->rear==q->front)return 1;
	else return 0;
}
int InQueue(SeqQueue * q,DataType x)
{//����
	if(q->front==(q->rear+1)%MAXSIZE){
		printf("����\n");
	return 0;
	}
	q->rear=(q->rear+1)%MAXSIZE;
	q->data[q->rear]=x;
	return 1;
}
DataType OutQueue(SeqQueue * q){//����
	if(q->rear==q->front){
		printf("�ӿ�����\n");
		exit(0);}
	q->front=(q->front+1)%MAXSIZE;
	return(q->data[q->front]);
}
int main()
{
	SeqQueue a;
	InitQueue(&a);//��ʼ������
	char ch;
	int n=1,k,i,m,j;
	printf("��ӡ����������\n");
	InQueue(&a,'*');//���
	for(i=0;i<4;i++)
	{
	 	InQueue(&a,'*');//���
		for(j=0;j<i+1;j++)
		{
		ch=OutQueue(&a);
		printf("%c",ch);
		InQueue(&a,'*');
		}
	   	printf("\n");
	}
	printf("\n");
	return 0;

}
