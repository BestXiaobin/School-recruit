#include <iostream>
#include <climits>
using namespace std;
//�������ҳ���
int IsUgly(int num)//�ж��Ƿ���
{
	while (num %2 == 0)
	{
		num /= 2;
	}
	while (num %3 == 0)
	{
		num /= 3;
	}
	while (num %5 == 0)
	{
		num /= 5;
	}
	if (num == 1)
		return 1;
	else
		return 0;//not an ugly number
}
void  GetUglyNumber(int index)
{//�ҵ���index������
	int i , time =0 ;
	if (index < 1)
	{
		cout << "error input " << endl;
//		exit(EXIT_FAILURE);
	}
	for (i=1 ; i< INT_MAX && time < index ; i++)
	{
		if ( IsUgly(i) )
		{
			time ++ ;
		//	cout << i << " " ;
		}
	}
	cout << i-1 << endl;
}
int main()
{
	int Number;
	cout << "Input a number : " ;
	cin >> Number ;
	GetUglyNumber(Number);
	return 0;
}
