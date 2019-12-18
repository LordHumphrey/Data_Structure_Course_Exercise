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
            @Time: 2019/12/10 14:04
            @Project_NAME：Learn_Data_Structure
            @FileName: Construction_of_binary_tree.cpp
            @IDE: CLion
*/
#ifndef LEARN_DATA_STRUCTURE_CONSTRUCTION_OF_BINARY_TREE_H
#define LEARN_DATA_STRUCTURE_CONSTRUCTION_OF_BINARY_TREE_H

#include <iostream>
#include<vector>

using namespace std;
typedef struct binary_tree_node
{
    int data;
    struct binary_tree_node *left_child, *right_child;

} binary_tree_node, *pointer_to_binary_tree_node;

void welcome()
{
    cout << "\n";
    cout << "                  ***Wasting time is robbing oneself.*** " << endl;
    cout << "                    -----------------------------------------------" << endl;
    cout << "                    |                                              |" << endl;
    cout << "                    |        1.Sequence and Middle order           |" << endl;
    cout << "                    |        2.Postorder and Middle order(todo)    |"
         << endl;//todo: Postorder and Middle order
    cout << "                    |        3.Pre and Middle order                |" << endl;
    cout << "                    |        4.One-click Boom                      |" << endl;
    cout << "                    |        0.Exit                                |" << endl;
    cout << "                    ----------------------------------------------- " << endl;

}

pointer_to_binary_tree_node
create_with_pre_and_middle_order(vector<int> pre_order, vector<int> middle_order, int pre_first,
                                 int pre_last,
                                 int in_first, int in_last)

#endif //LEARN_DATA_STRUCTURE_CONSTRUCTION_OF_BINARY_TREE_H