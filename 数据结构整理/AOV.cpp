/********* �������� ************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define LL long long

const int INF = 1e9+7;
const int VM = 503;// ��ĸ���

bool G[VM][VM];//ͼ
int deg[VM];//������������  ����

void toposort(int n)  //��������
{
    int k = 0;
    for (int i = 1; i <= n; i++)  //������|G.V|�β���
    {
        for (int j = 1; j <= n; j++)  //�������еĶ���  �����Ϊ0��
        {
            if (deg[j] == 0)  //�ҵ�
            {
                printf("%d%c", j, i == n ? '\n' : ' ');//���
                deg[j]--;//ȥ�������  ��deg[j] = -1;
                k = j;//��¼�����
                break;//����ѭ��
            }
        }
        for (int j = 1; j <= n; j++)//�������еĵ�
            if (G[k][j] == true)  //�ұ��˵��ܹ��ĵ�
            {
                G[k][j] = false;//���Ϊ�ҵ���
                deg[j]--;//�����������-1
            }
    }
}

int main()
{
    int n, m;

    while (scanf("%d %d", &n, &m) == 2)  //�������룬 ��ȡn, m
    {
        memset(G, 0, sizeof(G));//��ʼ��
        memset(deg, 0, sizeof(deg));//��ʼ��
        while (m--)
        {
            int u, v;
            scanf("%d %d", &u, &v);//��ȡ u,v  u��ܹ�v
            if(G[u][v] == false)  //��ֹ�ر� �����ͬһ�����ִ�ܶ�Σ�Ҳ̫��v������
            {
                G[u][v] = true;//���Ϊ��
                deg[v]++;//v�����++   һ�˳�ǹ�붴�ˡ�
            }
        }
        toposort(n);//���ú���
    }
    return 0;
}
