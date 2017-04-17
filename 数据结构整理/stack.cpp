/*ʹ��ջʵ������ת��*/
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct snode
{
  DataType data;
  struct snode *next;
}LinkStack;

//�ÿ�ջ��
LinkStack * InitStack()
{
    return NULL;
}

int EmptyStack(LinkStack *Top)
{
    return (Top==NULL?1:0);
}

LinkStack *Push(LinkStack *Top,DataType x)
{
    LinkStack *p;
    p=(LinkStack *)malloc(sizeof(LinkStack));
    p->data=x;
    p->next=Top;/*��������ջ��û�и���ͷ��㣬������ִ�н�ջ����ʱ���½�㽫��Ϊ��ǰջ������ˣ������޸�ջ��ָ��Top��*/
    Top=p;
    return (Top);
}

LinkStack *Pop(LinkStack *Top,DataType *x)
{
    LinkStack *p;
    if(Top==NULL)
    {
        printf("error");
        return NULL;
    }
    p=Top;
    *x=p->data;
    Top=Top->next;
    free(p);
    return Top;
}

DataType GetTop(LinkStack *Top){
  if(Top==NULL){
    printf("error");
  }
  else
    return Top->data;
}

void ConverDtoR(int N,int r)
{
  int x;
  LinkStack *s;
  s=InitStack();
  while(N)
  {
    x=N%r;
    s=Push(s,x);
    printf("%d",x);
    N/=r;
  }
  printf("\n");
  printf("ת�����%d������ֵΪ��",r);
  while(!EmptyStack(s))
  {
      s=Pop(s,&x);
      printf("%d",x);
  }
}

int main()
{
  int num,j;
  printf("��������Ҫת��������");
  scanf("%d",&num);
  printf("��������Ҫת���Ľ���");
  scanf("%d",&j);
  ConverDtoR(num,j);
  return 0;
}
