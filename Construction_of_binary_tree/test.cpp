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
            @Time: 2019/12/11 11:50
            @Project_NAME：Learn_Data_Structure
            @FileName: temp.cpp
            @IDE: CLion
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 10000;

struct tree
{
    tree *l, *r;
    int data;

    tree()
    {
        l = r = nullptr;
        data = 0;
    }
};

int layer[maxn], in[maxn];

//前序遍历
void PreOrder(tree *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        PreOrder(root->l);
        PreOrder(root->r);
    }
}

//后序遍历
void PostOrder(tree *root)
{
    if (root != nullptr)
    {
        PostOrder(root->l);
        PostOrder(root->r);
        cout << root->data << " ";
    }
}

//从 0 开始
tree *CreateTree(int *layer, int *in, int t)
{
    if (t == 0) return nullptr;
    int Llayer[maxn], Rlayer[maxn];
    int Lin[maxn], Rin[maxn];
    tree *node = new tree;
    node->data = layer[0];
    //find the place of the root
    int i;
    for (i = 0; i < t; i++)
        if (in[i] == layer[0])
            break;
    //in order
    int cnt = 0;
    for (int j = 0; j < i; j++)
        Lin[cnt++] = in[j];
    cnt = 0;
    for (int j = i + 1; j < t; j++)
        Rin[cnt++] = in[j];
    cnt--;

    //layer order
    int Llayercnt = 0;
    int Rlayercnt = 0;
    for (int j = 1; j < t; j++)
        for (int k = 0; k < i; k++)
            if (layer[j] == in[k])
                Llayer[Llayercnt++] = layer[j];
    for (int j = 1; j < t; j++)
        for (int k = i; k < t; k++)
            if (layer[j] == in[k])
                Rlayer[Rlayercnt++] = layer[j];
    node->l = CreateTree(Llayer, Lin, Llayercnt);
    node->r = CreateTree(Rlayer, Rin, Rlayercnt);
    return node;
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> layer[i];
    for (int i = 0; i < n; i++)cin >> in[i];
    tree *root;
    root = CreateTree(layer, in, n);
    PreOrder(root);
    cout << endl;
    PostOrder(root);

    return 0;
}