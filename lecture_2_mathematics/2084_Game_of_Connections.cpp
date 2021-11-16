#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

const int N = 111;
int a[N][N];		//	a[i]代表i对应的值。a[i][j]对应的是每一位,a[n] n需要大于100，每次多开一点。
int b[N];			//	b[i]是每个i对应的长度
int n;
void catalan() //求卡特兰数
{
    int i, j, len, carry, temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for(i = 2; i <= 100; i++)
    {
		for(j = 0; j < len; j++) 			//乘法
       		a[i][j] = a[i-1][j]*(4*(i-1)+2);
        carry = 0;
        for(j = 0; j < len; j++) 			//处理相乘结果
        {
            temp = a[i][j] + carry;
            a[i][j] = temp % 10;
            carry = temp / 10;
        }
        while(carry) 						//进位处理
        {
            a[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        for(j = len-1; j >= 0; j--) //除法
        {
            temp = carry * 10 + a[i][j];
            a[i][j] = temp/(i+1);
            carry = temp%(i+1);
        }
        while(!a[i][len-1]) 				//高位零处理
        	len --;
        b[i] = len;
    	//cout<< i << "\t" << b[i] <<endl; 
    }
}

int main(){
	catalan();
	while(scanf("%d",&n),n!=-1){
		for(int i = b[n]-1;i >= 0;i--)printf("%d",a[n][i]);
		printf("\n");
	}
	return 0;
}

