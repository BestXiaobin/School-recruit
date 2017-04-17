#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 105;
const int inf = 9999999;
int s[maxn];//������¼ĳһ���Ƿ񱻷��ʹ�
int map[maxn][maxn];//��ͼ
int dis[maxn];//��ԭ�㵽ĳһ�������̾���(һ��ʼ�ǹ������)
int n;
int target;

/**
 * ���ش�v---->��target�����·��
 */
int dijkstra(int v)
{
    int i;
    for(i = 1 ; i <= n ; ++i) //��ʼ��
    {
        s[i] = 0;//һ��ʼ�����еĵ��δ�����ʹ�
        dis[i] = map[v][i];
    }
    for(i = 1 ; i < n ; ++i)
    {
        int min = inf;
        int pos;
        int j;
        for(j = 1 ; j <= n ; ++j) //Ѱ��Ŀǰ�����·������С��
        {
            if(!s[j] && dis[j] < min)
            {
                min = dis[j];
                pos = j;
            }
        }
        s[pos] = 1;
        for(j = 1 ; j <= n ; j++) //����u�����е��ڽӵı�
        {
            if(!s[j] && dis[j] > dis[pos] + map[pos][j])
            {
                dis[j] = dis[pos] + map[pos][j];//�Ա߽����ɳ�
            }
        }
    }
    return dis[target];
}

int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        int i;
        int j;
        for(i = 1 ; i <= n ; ++i)
        {
            for(j = 1 ; j <= n ; ++j)
            {
                if(i == j)
                {
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j] = inf;
                }
            }
        }
        for(i = 1 ; i <= m ; ++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            map[a][b] = map[b][a] = c;//����Ĭ��������ͼ��������Ҫ��������������,ֻ��һ�������ϵĴ����WA
        }
        target = n;
        int result = dijkstra(1);
        printf("%d\n",result);
    }

    return 0;
}
