#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
int N;
int codes[2*MAX+10];
int signs[2][MAX+10];
int ans[2][MAX+10];

bool Foo(int s, int first)
{
	int i, j, n;
	i = j = s;
	if(codes[first*N+s]*signs[first][0] < 0)
		return false;
	ans[first][0] = codes[first*N+s];
	for(n = 1; n < N; ++n)
	{
		if(codes[first*N+j]*signs[first][n] > 0)
		{
			--i;
			if(i < 0)
				return false;
			ans[first][n] = codes[first*N+i];
		}
		else
		{
			++j;
			if(j >= N)
				return false;
			ans[first][n] = codes[first*N+j];
		}
	}
	return true;
}

int main()
{
	//ifstream cin("test.txt");
	int i, j, n;
	cin >> N;
	for(n = 0; n < 2*N; ++n)
		cin >> codes[n];
	for(n = 0; n < N; ++n)
	{
		cin >> i;
		signs[0][n] = 2*(i==1||i==4)-1;
		signs[1][n] = 2*(i<=2)-1;
	}
	sort(codes, codes+2*N);
	j = signs[0][N-1];
	for(n = N-1; n >= 0; --n, j*=-1)
		codes[n] *= j;
	j = signs[1][N-1];
	for(n = 2*N-1; n >= N; --n, j*=-1)
		codes[n] *= j;
	bool done[2];
	done[0] = done[1] = false;
	int left1 = 0; int left2 = 0;
	for(i = 0; i < N-1; ++i)
	{
		if(signs[0][i]==signs[0][i+1])
			++left1;
		if(signs[1][i]==signs[1][i+1])
			++left2;
	}
	done[0] = Foo(left1, 0);
	done[1] = Foo(left2, 1);
	if(!done[0] || !done[1])
		cout << 0 << endl;
	else
	{
		for(i = 0; i < N; ++i)
		{
			if(ans[0][i] > 0)
				cout << "+";
			cout << ans[0][i] << " ";
			if(ans[1][i] > 0)
				cout << "+";
			cout << ans[1][i] << endl;
		}
	}
	return 0;
}

/*
#include<cstdio>
#include<algorithm>

using namespace std;

int n, a[20001], u[20001], x[20001], y[20001];
int l1, r1, zff[20001], l2, r2;
int xsum, ysum;

bool cmp(int x, int y) {
	return x < y;
}

void zf(int x) {
	if (x == 1) printf("+");
		else printf("-");
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
	
	sort(a + 1, a + 2 * n + 1, cmp);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &u[i]);
		
		if (u[i] & 1) {//记录xy坐标正负性
			if (u[i] / 2) x[i] = y[i] = -1;
				else x[i] = y[i] = 1;
		}
		else if (u[i] / 2 == 1) {
			x[i] = -1;
			y[i] = 1;
		}
		else {
			x[i] = 1;
			y[i] = -1;
		}
		
		if (i > 1) {//统计要多少个小的
			if (x[i] == x[i - 1]) l1++;
			if (y[i] == y[i - 1]) l2++;
		}
	}
	r1 = l1 + 1;
	r2 = l2 + 1;
	
	zff[n] = x[n];//得出数的正负
	zff[n + n] = y[n];
	for (int i = n - 1; i >= 1; i--) {
		zff[i] = zff[i + 1] * -1;
		zff[n + i] = zff[n + i + 1] * -1;
	}
	
	zf(zff[r1]);//先处理第一个数
	printf("%d ", a[r1]);
	r1++;
	zf(zff[n + r2]);
	printf("%d\n", a[n + r2]);
	r2++;
	for (int i = 2; i <= n; i++) {
		if (zff[r1 - 1] * x[i] < 0) {//选大的
			zf(zff[r1]);
			printf("%d ", a[r1]);
			r1++;
		}
		else {//选小的
			zf(zff[l1]);
			printf("%d ", a[l1]);
			l1--;
		}
		if (zff[n + r2 - 1] * y[i] < 0) {//同理
			zf(zff[n + r2]);
			printf("%d\n", a[n + r2]);
			r2++;
		}
		else {
			zf(zff[n + l2]);
			printf("%d\n", a[n + l2]);
			l2--;
		}
	}
	
	return 0;
}*/
