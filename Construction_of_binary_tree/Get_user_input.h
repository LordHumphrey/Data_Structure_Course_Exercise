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


#include "Construction_of_binary_tree.h"
#include <vector>

using namespace std;
vector<int> vector_middle_order;
vector<int> vector_pre_drder;
vector<int> vector_postamble_order;
vector<int> vector_sequence_order;

void get_sequence_order(int length);

void get_middle_order(int length);

void get_pre_order(int length);

void get_postorder(int length);


void get_sequence_order(int length)
{
    int data;
    std::cout << "Please input sequence order:";
    for (int i = 0; i < length; i++)
    {
        std::cin >> data;
        vector_sequence_order.push_back(data);
    }
}

void get_middle_order(int length)
{
    int data;
    std::cout << "Please input middle order:";
    for (int i = 0; i < length; i++)
    {
        std::cin >> data;
        vector_middle_order.push_back(data);
    }
}

void get_pre_order(int length)
{
    int data;
    std::cout << "Please input pre drder:";
    for (int i = 0; i < length; i++)
    {
        std::cin >> data;
        vector_pre_drder.push_back(data);
    }
}

void get_postorder(int length)
{
    int data;
    std::cout << "Please input postorder:";
    for (int i = 0; i < length; i++)
    {
        std::cin >> data;
        vector_postamble_order.push_back(data);
    }
}

#endif //LEARN_DATA_STRUCTURE_GET_USER_INPUT_H
