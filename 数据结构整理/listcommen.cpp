/*
  Ѱ������������Ĺ������������ཻ���⣩.
  �������ϳ��ĵ�������a��b��Ϊ���ҳ��ڵ�node����node in a����node in b��
  ����ƿռ�ʹ�þ���С���㷨����c/c++/java��α���ʾ�����ԣ�
*/
#include<stdio.h>
#include<stdlib.h>
typedef int size_t;
struct node
{
    int v;
    node *next;
};
/*
��������ĳ���
����Ϊ�� ����0
*/
size_t listLen(node * p)
{
    size_t num = 0;
    while(p!=NULL)
    {
        num++;
        p = p->next;
    }
    return num;
}
// ����ҵ��� �򷵻�ָ�� ָ�򹫹��ڵ�
// ��������� �򷵻ؿ�ָ��
node * findFirstCommenNode(node * pheada, node * pheadb)
{
    size_t lenA = listLen(pheada);
    size_t lenB = listLen(pheadb);

    node * plistA = pheada;
    node * plistB = pheadb;
    //�������ȣ���plistA ָ��ϳ���һ������
    if (lenA < lenB)
    {
        plistB = pheada;
        plistA = pheadb;
        size_t t = lenA;
        lenA = lenB;
        lenB = t;
    }
    while(lenA > lenB)
    {
        plistA = plistA->next;
        --lenA;
    }
    //һ������
    //Ѱ�ҹ����ڵ�
    while (plistA!=NULL && plistA != plistB)
    {
        plistA = plistA->next;
        plistB = plistB->next;
    }
    return plistA;
}
