#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define M 255
int LCS(char query[], char text[])
{
    int len_query=strlen(query),len_text=strlen(text);

    //����c��¼ƥ�����,ģ���ά����
    char c[len_text];
    int len, i, j;
    len=0;

    for(i=0; i<len_query; i++)
    {
        //�����������֮ǰ����Ԫ�س���ģ���Ϊ�����Ԫ����Ҫ����ǰ���Ԫ�ؼ���
        for(j=len_text-1; j>=0; j--)
        {
            if(query[i] == text[j])
            {
                if(i==0 || j==0)
                    c[j]=1;
                else
                    c[j]=c[j-1]+1;
            }
            else
                c[j] = 0;

            if(c[j] > len)
                len=c[j];
        }
    }
    return len;
}

int main()
{
    char str1[M],str2[M];
    printf("�������ַ���query:");

    scanf("%s", str1);
    printf("�������ַ���text:");

    scanf("%s", str2);
    printf("���󳤶�Ϊ:");

    printf("%d\n",LCS(str1,str2));
    return 0;

}
