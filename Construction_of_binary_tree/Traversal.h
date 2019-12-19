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
            @Time: 2019/12/18 21:39
            @Project_NAME：Data_Structure_Course_Exercise
            @FileName: Traversal.cpp
            @IDE: CLion
*/
#ifndef DATA_STRUCTURE_COURSE_EXERCISE_TRAVERSAL_H
#define DATA_STRUCTURE_COURSE_EXERCISE_TRAVERSAL_H

void post_order(pointer_to_binary_tree_node root)
{
    if (root == nullptr) return;
    post_order(root->left_child);
    post_order(root->right_child);
    cout << root->data << " ";
}

void pre_order(pointer_to_binary_tree_node root)
{
    if (root)
    {
        cout << root->data << " ";
        pre_order(root->left_child);
        pre_order(root->right_child);
    }
}

#endif //DATA_STRUCTURE_COURSE_EXERCISE_TRAVERSAL_H
