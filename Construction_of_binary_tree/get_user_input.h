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
            @Time: 2019/12/10 15:13
            @Project_NAME：Learn_Data_Structure
            @FileName: get_user_input.cpp
            @IDE: CLion
*/
#ifndef LEARN_DATA_STRUCTURE_GET_USER_INPUT_H
#define LEARN_DATA_STRUCTURE_GET_USER_INPUT_H

#include"Construction_of_binary_tree.h"
#include <vector>

using namespace std;
vector<char> vector_middle_order;
vector<char> vector_frame_drder;
vector<char> vector_postamble_order;
vector<char> vector_sequence_order;

void get_sequence_order(int length);

void get_middle_order(int length);

void get_frame_order(int length);

void get_postorder(int length);

void get_user_input()
{
    welcome();

    cout << "请输入操作:";
    char to_do_what;
    cin >> to_do_what;
    system("cls");
    int length;
    cout << "请输入树的节点个数:";
    cin >> length;
    switch (to_do_what)
    {
        case '1':
            get_sequence_order(length);
            get_middle_order(length);
            break;
        case '2':
            get_middle_order(length);
            get_postorder(length);
            break;
        case '3':
            get_frame_order(length);
            get_middle_order(length);
            break;
        case '4':
            cout << "Boom!你死了~" << endl;
            break;
        case '0':
            return;
        default:
            break;
    }
}

void get_sequence_order(int length)
{
    char data;
    cout << "请输入层序遍历:";
    for (int i = 0; i < length; i++)
    {
        cin >> data;
        vector_sequence_order.push_back(data);
    }
}

void get_middle_order(int length)
{
    char data;
    cout << "请输入中序遍历:" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> data;
        vector_middle_order.push_back(data);
    }
}

void get_frame_order(int length)
{
    char data;
    cout << "请输入前序遍历:" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> data;
        vector_frame_drder.push_back(data);
    }
}

void get_postorder(int length)
{
    char data;
    cout << "请输入后序遍历:" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> data;
        vector_postamble_order.push_back(data);
    }
}

#endif //LEARN_DATA_STRUCTURE_GET_USER_INPUT_H
