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
#include <sstream>
#include <regex>

using namespace std;

typedef struct synonyms_node
{
    int data;
    struct synonyms_node *next;
} synonyms_node, *pointer_to_synonyms_node;

vector<pointer_to_synonyms_node> vector_pointer_to_synonyms(6, nullptr);

pointer_to_synonyms_node list_pointer_to_synonyms_node[100];

int get_hash_position(int data);

void insert_to_hash_file();

void write_vector_to_file(vector<pointer_to_synonyms_node> toBeWrite, const string &fileName);

void read_link_list_from_file(const string &fileName);

void write_vector_to_file(vector<pointer_to_synonyms_node> toBeWrite, const string &fileName)
{
    ofstream write_binary_file;
    write_binary_file.open("D:\\" + fileName, ios_base::binary);
    for (int i = 0; i < vector_pointer_to_synonyms.size(); i++)
    {
        write_binary_file << i << endl;
    }
    write_binary_file.close();
}

void write_link_list_to_file(vector<pointer_to_synonyms_node> toBeWrite, const string &fileName)
{
    ofstream write_binary_file;
    write_binary_file.open("D:\\" + fileName, ios_base::binary);
    pointer_to_synonyms_node temp;
    for (auto i:toBeWrite)
    {
        if (i)
        {
            temp = i;
            while (temp)
            {
                write_binary_file << temp->data << " ";
                temp = temp->next;
            }
            write_binary_file << endl;
        } else
        {
            write_binary_file << endl;
        }
    }
    write_binary_file.close();
}


void welcome()
{
    cout << "\n";
    cout << "                  ***Wasting time is robbing oneself.*** " << endl;
    cout << "                    --------------------------------" << endl;
    cout << "                    |                               |" << endl;
    cout << "                    |        1.Insert data          |" << endl;
    cout << "                    |        2.Find data            |" << endl;
    cout << "                    |        3.Deltese data         |" << endl;
    cout << "                    |        4.Load from File       |" << endl;
    cout << "                    |        5.Print                |" << endl;
    cout << "                    |        0.Exit                 |" << endl;
    cout << "                    -------------------------------- " << endl;
   
}

#endif //DATA_STRUCTURE_COURSE_EXERCISE_HASH_FILE_H
