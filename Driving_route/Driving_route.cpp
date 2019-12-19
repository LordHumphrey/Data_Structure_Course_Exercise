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

#define inf 0x3f3f3f3f //无穷大量
using namespace std;

int N, M;
int road_matrix[100][100];
long long trod_matrix[100][100];  //大路和小路
long long road[100], trod[100];
bool visited_or_not[100];

void Shortest_path(int s)
{
    queue<int> Q;
    road[s] = 0;
    trod[s] = 0;
    Q.push(s);
    visited_or_not[s] = true;
    while (!Q.empty())
    {
        long long tep = Q.front();
        Q.pop();
        visited_or_not[tep] = false;
        for (int i = 1; i <= N; i++)
        {
            if (road[i] > road[tep] + road_matrix[tep][i])  //大路+大路
            {
                road[i] = road[tep] + road_matrix[tep][i];
                if (visited_or_not[i] == 0)
                {
                    Q.push(i);
                    visited_or_not[i] = true;
                }
            }
            if (road[i] > trod[tep] + road_matrix[tep][i])  //小路+大路
            {
                road[i] = trod[tep] + road_matrix[tep][i];
                if (visited_or_not[i] == 0)
                {
                    Q.push(i);
                    visited_or_not[i] = true;
                }
            }
            if (trod_matrix[tep][i] != inf)  //可以走小路,由于之前已经把小路进行了归并，所以只考虑之前走的是大路
            {
                if (trod[i] > road[tep] + trod_matrix[tep][i] * trod_matrix[tep][i])
                {
                    trod[i] = road[tep] + trod_matrix[tep][i] * trod_matrix[tep][i];
                    if (visited_or_not[i] == 0)
                    {
                        Q.push(i);
                        visited_or_not[i] = true;
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
    memset(visited_or_not, 0, sizeof(visited_or_not)); //初始化数组
    memset(road, inf, sizeof(road));
    memset(trod, inf, sizeof(trod));
    memset(road_matrix, inf, sizeof(road_matrix));
    memset(trod_matrix, inf, sizeof(trod_matrix));
    while (M--)
    {
        scanf("%d %d %d %d", &t, &a, &b, &c);
        if (t == 1 && c < trod_matrix[a][b])
            trod_matrix[a][b] = trod_matrix[b][a] = c;
        else if (t == 0 && c < road_matrix[a][b])
            road_matrix[a][b] = road_matrix[b][a] = c;
    }
    for (int i = 1; i <= N; i++) //这里用floyd事先计算好只走小路时两两点之间的最短距离
        for (int j = i + 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (k == i || k == j)
                {
                    continue;
                }
                if (trod_matrix[i][j] > trod_matrix[i][k] + trod_matrix[k][j])
                {
                    trod_matrix[i][j] = trod_matrix[j][i] = trod_matrix[i][k] + trod_matrix[k][j];
                }
            }
        }
    Shortest_path(1);
    printf("%lld\n", min(road[N], trod[N]));
    return 0;
}

//样例输入
//6 7
//1 1 2 3
//1 2 3 2
//0 1 3 30
//0 3 4 20
//0 4 5 30
//1 3 5 6
//1 5 6 1
//样例输出
//76
