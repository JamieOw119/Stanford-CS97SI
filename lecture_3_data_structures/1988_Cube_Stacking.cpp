#include <iostream>
using namespace std;
const int N = 30001;
int p,x,y,f[N],sum[N],under[N];
char ch;
void init(){
    for(int i=1;i<=N;++i){
        f[i] = i;//初始化父亲结点就是自己
        sum[i] = 1;//初始化每个堆的总cube数是自己1个
        under[i] = 0;//初始化每个cube下面没有cube
    }
}
int getf(int v){
    if(f[v]==v) return v;
    else{
        int temp = getf(f[v]);//先记录当前结点的根结点
        under[v] += under[f[v]];
        f[v] = temp;//路径压缩
        return f[v];
    }
}
void Merge(int u,int v){
    int t1 = getf(u);
    int t2 = getf(v);
    if(t1!=t2){
        f[t1] = t2;//更新父亲结点
        under[t1] = sum[t2];//更新t1的under值
        sum[t2] += sum[t1];//堆中cube数累加
    }
}

int main()
{
    cin >> p;
    init();
    while(p--){
        cin >> ch;
        if(ch=='M'){
            cin >> x >> y;
            Merge(x,y);
        }
        else{
            cin >> x;
            getf(x);
            cout << under[x] << endl;
        }
    }
}