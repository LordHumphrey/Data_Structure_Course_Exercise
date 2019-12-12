/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
            
            @Author: Tao
            @Time: 2019/12/12 9:17
            @Project_NAME：Learn_Data_Structure
            @FileName: Driving_route.cpp
            @IDE: CLion
*/

// 因为既可以走大路，又可以走小路，所以把两种路分开来看，各用一个数组存储。
// 由于连续走小路时，疲劳值增加连续小路的总长度的平方，所以首先用FLoyd算法将走小路进行归并一下，以后在计算的时候就只需要考虑三种情况：
// 1.大路+大路  ，2.小路+大路  ，3.大路+小路。用两个数组dis和dis1分别存储大路和小路到达i点时的最小疲劳值，最后取n处的两者的最小值
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

#define inf 0x3f3f3f3f
using namespace std;

int N, M;
int g[501][501];
long long g1[501][501];  //大路和小路
long long dis[501], dis1[501];
bool vis[501];

void SPFA(int s)
{
    queue<int> Q;
    dis[s] = 0;
    dis1[s] = 0;
    Q.push(s);
    vis[s] = 1;
    while (!Q.empty())
    {
        long long tep = Q.front();
        Q.pop();
        vis[tep] = 0;
        for (int i = 1; i <= N; i++)
        {
            if (dis[i] > dis[tep] + g[tep][i])  //大路+大路
            {
                dis[i] = dis[tep] + g[tep][i];
                if (vis[i] == 0)
                {
                    Q.push(i);
                    vis[i] = 1;
                }
            }
            if (dis[i] > dis1[tep] + g[tep][i])  //小路+大路
            {
                dis[i] = dis1[tep] + g[tep][i];
                if (vis[i] == 0)
                {
                    Q.push(i);
                    vis[i] = 1;
                }
            }
            if (g1[tep][i] != inf)  //可以走小路,由于之前已经把小路进行了归并，所以只考虑之前走的是大路
            {
                if (dis1[i] > dis[tep] + g1[tep][i] * g1[tep][i])
                {
                    dis1[i] = dis[tep] + g1[tep][i] * g1[tep][i];
                    if (vis[i] == 0)
                    {
                        Q.push(i);
                        vis[i] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    int t, a, b, c;
    scanf("%d %d", &N, &M);
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    memset(dis1, inf, sizeof(dis1));
    memset(g, inf, sizeof(g));
    memset(g1, inf, sizeof(g1));
    while (M--)
    {
        scanf("%d %d %d %d", &t, &a, &b, &c);
        if (t == 1 && c < g1[a][b])
            g1[a][b] = g1[b][a] = c;
        else if (t == 0 && c < g[a][b])
            g[a][b] = g[b][a] = c;
    }
    for (int i = 1; i <= N; i++) //这里用floyd事先计算好只走小路时两两点之间的最短距离
        for (int j = i + 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (k == i || k == j)
                    continue;
                if (g1[i][j] > g1[i][k] + g1[k][j])
                    g1[i][j] = g1[j][i] = g1[i][k] + g1[k][j];
            }
        }
    SPFA(1);
    printf("%lld\n", min(dis[N], dis1[N]));
    return 0;
}
