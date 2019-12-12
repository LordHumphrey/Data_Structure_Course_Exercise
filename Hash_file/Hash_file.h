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
            @Time: 2019/12/12 17:13
            @Project_NAME：Data_Structure_Course_Exercise
            @FileName: Hash_file.cpp
            @IDE: CLion
*/
#ifndef DATA_STRUCTURE_COURSE_EXERCISE_HASH_FILE_H
#define DATA_STRUCTURE_COURSE_EXERCISE_HASH_FILE_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct synonyms_node
{
    int data;
    struct synonyms_node *next;
} synonyms_node, *pointer_to_synonyms_node;

vector<pointer_to_synonyms_node> vector_pointer_to_synonyms(6, nullptr);

int get_hash_position(int data);

void insert_to_hash_file();

void write_vector_to_file(vector<pointer_to_synonyms_node> toBeWrite, const string &fileName);

void write_vector_to_file(vector<pointer_to_synonyms_node> toBeWrite, const string &fileName)
{
    ofstream establish_index_file;
    establish_index_file.open("D:\\" + fileName, ios_base::binary);
//    for (auto i :toBeWrite)
//    {
//        establish_index_file << "0x" << i << ",";
//    }
    pointer_to_synonyms_node list_pointer_to_synonyms_node[toBeWrite.size()];
    for (int i = 0; i < toBeWrite.size(); i++)
    {
        list_pointer_to_synonyms_node[i] = toBeWrite[i];
    }
    establish_index_file.write((const char *) list_pointer_to_synonyms_node, toBeWrite.size());
}


#endif //DATA_STRUCTURE_COURSE_EXERCISE_HASH_FILE_H
