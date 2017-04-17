/*****************************/
#if(0)
#include <cstdio>
#include <cstdlib>
#define MAXN 10000 + 10
using namespace std;

int par[MAXN], Rank[MAXN];
typedef struct
{
    int a, b, price;
} Node;
Node a[MAXN];

int cmp(const void*a, const void *b)
{
    return ((Node*)a)->price - ((Node*)b)->price;
}

void Init(int n)
{
    for(int i = 0; i < n; i++)
    {
        Rank[i] = 0;
        par[i] = i;
    }
}

int find(int x)
{
    int root = x;
    while(root != par[root]) root = par[root];
    while(x != root)
    {
        int t = par[x];
        par[x] = root;
        x = t;
    }
    return root;
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(Rank[x] < Rank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}
//nΪ�ߵ�������mΪ��ׯ������
int Kruskal(int n, int m)
{
    int nEdge = 0, res = 0;
    //���߰���Ȩֵ��С��������
    qsort(a, n, sizeof(a[0]), cmp);
    for(int i = 0; i < n && nEdge != m - 1; i++)
    {
        //�жϵ�ǰ�����ߵ������˵��Ƿ�����ͬһ����
        if(find(a[i].a) != find(a[i].b))
        {
            unite(a[i].a, a[i].b);
            res += a[i].price;
            nEdge++;
        }
    }
    //�������ߵ�����С��m - 1,�����������ͼ����ͨ,�ȼ��ڲ�������С������
    if(nEdge < m-1) res = -1;
    return res;
}
int main()
{
    int n, m, ans;
    while(scanf("%d%d", &n, &m), n)
    {e
        Init(m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].price);
            //����ׯ��ű�Ϊ0~m-1���������ֻ�Ǹ���ϰ�ߣ����Ǳ�Ҫ�ģ�
            a[i].a--;
            a[i].b--;
        }
        ans = Kruskal(n, m);
        if(ans == -1) printf("?\n");
        else printf("%d\n", ans);
    }
    return 0;
}


#endif
/******************************************/
#if(1)
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int u[101];
int v[101];
int w[101];
int p[101];
int r[101];
int n,m;
bool cmp(int i,int j)
{
    return w[i]<w[j];
}
int found(int x)
{
    return p[x]==x?x:p[x]=found(p[x]);
}
int Kruskal()
{
    int i;
    for(i=1; i<=n; i++)
        p[i]=i;
    for(i=0; i<m; i++)
        r[i]=i;
    sort(r,r+m,cmp);//����Ȩֵ��С����
    int ans = 0;
    for(i=0; i<m; i++)
    {
        int e = r[i];
        int x = found(u[e]);
        int y = found(v[e]);
        if(x!=y)
        {
            printf("%d %d %d\n",u[e],v[e],w[e]);
            ans+=w[e];
            p[x]=y;
        }
    }
    return ans;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=0; i<m; i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    printf("%d\n",Kruskal());
    return 0;
}
#endif
