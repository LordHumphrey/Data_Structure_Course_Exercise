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
            @Time: 2019/12/12 14:35
            @Project_NAME：Learn_Data_Structure
            @FileName: Hash_file.cpp
            @IDE: CLion
*/
#include "Hash_file.h"


void insert_to_hash_file()
{
    int data;
    cout << "Please input data you want to insert:";
    cin >> data;
    auto new_node = new synonyms_node;
    new_node->data = data;
    if (!vector_pointer_to_synonyms[get_hash_position(data)])
    {
        vector_pointer_to_synonyms[get_hash_position(data)] = new_node;
    } else
    {
        new_node->next = vector_pointer_to_synonyms[get_hash_position(data)]->next;
        vector_pointer_to_synonyms[get_hash_position(data)]->next = new_node;
    }
    write_vector_to_file(vector_pointer_to_synonyms, "index.dat");
}

int get_hash_position(int data)
{
    int position = 0;
    return position = data % 5;
}

int main()
{
//    string file_name;
//    cout << "Please input filename:";
//    cin >> file_name;
    for (int i = 0; i < 3; i++)
    {
        insert_to_hash_file();

    }
}