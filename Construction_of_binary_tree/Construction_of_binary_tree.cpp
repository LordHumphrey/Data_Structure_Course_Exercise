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
            @Time: 2019/12/10 14:01
            @Project_NAME：Learn_Data_Structure
            @FileName: Construction_of_binary_tree.cpp
            @IDE: CLion
*/
#include "Construction_of_binary_tree.h"
#include "Get_user_input.h"
#include "Traversal.h"

pointer_to_binary_tree_node my_binary_tree;

pointer_to_binary_tree_node
create_with_pre_and_middle_order(vector<int> pre_order, vector<int> middle_order, int pre_first,
                                 int pre_last,
                                 int in_first, int in_last)
{
    int count = 0;
    int left_length, right_lenth;
    auto T = new binary_tree_node;
    T->data = pre_order[pre_first];
    T->left_child = nullptr;
    T->right_child = nullptr;
    while (middle_order[count] != pre_order[pre_first])
    {
        count++;
    }
    left_length = count - in_first;
    right_lenth = in_last - count;
    if (left_length != 0)
    {
        T->left_child = create_with_pre_and_middle_order(pre_order, middle_order, pre_first + 1,
                                                         pre_first + left_length,
                                                         in_first, in_first + left_length - 1);
    } else
    {
        T->left_child = nullptr;
    }
    if (right_lenth != 0)
    {
        T->right_child = create_with_pre_and_middle_order(pre_order, middle_order, pre_last - right_lenth + 1,
                                                          pre_last,
                                                          in_last - right_lenth + 1, in_last);
    } else
    {
        T->right_child = nullptr;
    }


    return T;
}

void generate_pre_oeder()
{

}

void get_user_input()
{
    welcome();

    cout << "Please input:";
    char to_do_what;
    cin >> to_do_what;
    system("cls");
    int length;
    cout << "Please input the number of binarytree node:";
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
            get_pre_order(length);
            get_middle_order(length);
            my_binary_tree = create_with_pre_and_middle_order(vector_pre_drder,
                                                              vector_middle_order, 0,
                                                              length - 1, 0, length - 1);
            break;
        case '4':
            cout << "Boom~" << endl;
            break;
        case '0':
            return;
        default:
            break;
    }
}

int main()
{
    get_user_input();
    cout << "The Post order is:";
    post_order(my_binary_tree);
}
