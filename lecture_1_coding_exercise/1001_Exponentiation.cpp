/*#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define LEN 1000

void multiply(int num[], int &num_len)
{
    int *res = (int*)malloc(sizeof(int)*LEN);
    memset(res, 0, sizeof(int)*LEN);

    for(int i=0; i<num_len; i++)
    {
        for(int j=0; j<num_len; j++)
        {
            int tmp = num[j] * num[i];
            res[i+j] += tmp % 10;
            res[i+j+1] += tmp / 10;
        }
    }

    int new_len = num_len * 2 - 1;
    memset(num, 0, sizeof(num));
    memcpy(num, res, sizeof(char)*new_len);
}

int main(int argc, char const *argv[])
{
    int integer[LEN], decimal[LEN], exporant;
    string base;

    while(cin>>base>>exporant)
    {
        int dot_index = base.find('.');
        string integer_str = base.substr(0, dot_index);
        string decimal_str = base.substr(dot_index+1, base.length()-1);
        
        int index = 0;
        for(string::iterator it=integer_str.end()-1; it!=integer_str.begin()-1; it--)
        {
            integer[index++] = (int)(*it-'0');   
        }
        index = 0;
        for(string::iterator it=decimal_str.end()-1; it!=decimal_str.begin()-1; it--)
        {
            decimal[index++] = (int)(*it-'0');   
        }
        int int_len = integer_str.length(), dec_len = decimal_str.length();

        while(exporant--)
        {
            multiply(integer, int_len);
            multiply(decimal, dec_len);
        }

        for(int i=int_len-1; i>=0; i--)
        {
            cout<<integer[i];
        }
        cout<<'.';
        for(int i=dec_len-1; i>=0; i--)
        {
            cout<<decimal[i];
        }
        cout<<endl;
    }

    return 0;
}*/

#include <stdio.h>
#include <string.h>
const int N = 200;
 
int main() {
	char num[6]; //存放输入字符串 
	long number; //将输入的字符串转为不带小数点的整数 
	int n,point,count;  
	int a[N]; //存储运算结果
	while (scanf("%s%d", num, &n) == 2) {
		number = 0; point = -1; count = 0;
		
		//输入设置 
		int note1,note2; //去除字符串前面和后面多余的0 
		for (int i = 0; i <= 5; i++) {
			if (num[i] != '0') {
				note1 = i;
				break;
			} 		
		}	
		for (int i = 5; i >= 0; i--) {
			if (num[i] != '0') {
				note2 = i;
				break;
			} 		
		}
		for (int i = note1; i <= note2; i++) {
			if (num[i] != '.') {
				number = number*10 + (num[i]-48);
			}
		}
		for (int i = note2; i >= note1; i--) {
			if (num[i] != '.') {
				a[count++] = num[i]-48;		
			}
		}
		for (int i = note1; i <= note2; i++) {
			if (num[i] == '.') {
				point = (note2-i)*n;
				break;
			}
		}
 
		//运算 
		long s,d;
		for (int k = 1; k < n; k++) {
			d = 0;
			for (int i = 0; i < count; i++) {
				s = a[i]*number+d;	
				a[i] = s%10;
				d = s/10;
			}
			while (d != 0) {
				a[count++] = d % 10;
				d /= 10;
			}
		}
		
		//输出设置	
		bool flag = true;
		if (count < point) {  
			flag = false;
			printf(".");
			while (point != count) {
				point--;
				printf("0");
			}
		}
		for (int i = count-1; i >= 0; i--) {
			if (flag == true && i == point-1) printf(".");
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}

