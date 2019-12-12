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
    char data;
    struct binary_tree_node *left_child, *right_child;

} binary_tree_node, *pointer_to_binary_tree_node;

void welcome()
{
    cout << "\n";
    cout << "                     ***惟草木之零落兮，恐美人之迟暮*** " << endl;
    cout << "                    ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁" << endl;
    cout << "                    ▏                               |" << endl;
    cout << "                    ▏        1.层序和中序              |" << endl;
    cout << "                    ▏        2.后序和中序            |" << endl;
    cout << "                    ▏        3.前序和中序            |" << endl;
    cout << "                    ▏        4.一键爆炸                |" << endl;//变成课任意插入位置的
    cout << "                    ▏        0. 退出                 |" << endl;
    cout << "                    ▏                               |" << endl;
    cout << "                    ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔" << endl;

}

void sequence_and_middle_order();

void postorder_and_middleorder();

void preamble_and_middle_order();


#endif //LEARN_DATA_STRUCTURE_CONSTRUCTION_OF_BINARY_TREE_H
