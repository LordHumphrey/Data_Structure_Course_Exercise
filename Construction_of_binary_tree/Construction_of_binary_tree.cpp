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
            ·ð×æ±£ÓÓ       ÓÀÎÞBUG
            
            @Author: Tao
            @Time: 2019/12/10 14:01
            @Project_NAME£ºLearn_Data_Structure
            @FileName: Construction_of_binary_tree.cpp
            @IDE: CLion
*/
#include "Construction_of_binary_tree.h"
#include "get_user_input.h"

char layer[50], in[50], pre[50];

int n, idx = 0;
//pointer_to_binary_tree_node create_with_sequence_and_middle_order(const vector<char> &sequence_order, int left, int right)
//{
//
//    if (left > right || sequence_order.empty())
//    {
//        return nullptr;
//    }
//    auto root = new binary_tree_node;
//    root->left_child = nullptr;
//    root->right_child = nullptr;
//    root->data = sequence_order[0];
//    int root_position;
//    for (root_position = left; root_position <= right; root_position++)
//    {
//        if (vector_middle_order[root_position] == vector_sequence_order[0])
//        {
//            break;
//        }
//    }
//    int left_tree = root_position - left;
//    int right_tree = right - root_position;
//    vector<char> left_tree_node, right_tree_node;
//    vector<char>::iterator m;
//    for (m = vector_sequence_order.begin(); m != vector_sequence_order.end(); m++)
//    {
//        int left_or_not = 0;
//        for (int j = left; j < root_position; j++)
//        {
//            if (vector_middle_order[j] == *m)
//            {
//                left_tree_node.push_back(*m);
//                left_or_not = 1;
//                break;
//            }
//        }
//        if (left_or_not == 0)
//        {
//            for (int j = root_position + 1; j <= right; j++)
//            {
//                if (vector_middle_order[j] == *m)
//                {
//                    right_tree_node.push_back(*m);
//                    break;
//                }
//            }
//        }
//    }
//    root->left_child = create_with_sequence_and_middle_order(left_tree_node, left, root_position - 1);
//    root->right_child = create_with_sequence_and_middle_order(right_tree_node, root_position + 1, right);
//    return root;
//}

pointer_to_binary_tree_node create_with_sequence_and_middle_order(int ll, int lr, int inl, int inr)
{
    if (inl > inr)
        return nullptr;
    auto root = new binary_tree_node;
    int i, j = 0;
    bool f = false;
    for (i = ll; i <= lr; i++)
    {
        f = false;
        for (j = inl; j <= inr; j++)
        {
            if (layer[i] == in[j])
            {
                root->data = in[j];
                root->left_child = nullptr;
                root->right_child = nullptr;
                f = true;
                break;
            }
        }
        if (f) break;
    }
    if (!f) return nullptr;
    if (j > inl) root->left_child = create_with_sequence_and_middle_order(0, n - 1, inl, j - 1);
    if (j < inr) root->right_child = create_with_sequence_and_middle_order(0, n - 1, j + 1, inr);
    return root;
}

void postOrder(pointer_to_binary_tree_node root)
{
    if (root == nullptr) return;
    postOrder(root->left_child);
    postOrder(root->right_child);
    cout << root->data << endl;
}


int main()
{

    get_user_input();
    pointer_to_binary_tree_node my_binary_tree;
    pointer_to_binary_tree_node root = create_with_sequence_and_middle_order(0, vector_sequence_order.size(), 0,
                                                                             vector_sequence_order.size());
    postOrder(root);
}
