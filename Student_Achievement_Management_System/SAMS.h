//
// Created by Tao on 2019/12/9.
//

#ifndef LEARN_DATA_STRUCTURE_SAMS_H
#define LEARN_DATA_STRUCTURE_SAMS_H

#include <vector>
#include <algorithm>
#include <map>
#include <string>
//#include <wsman.h>

using namespace std;
typedef struct Student
{
    int user_id;//学号
    string user_name;//姓名
    int fox_score;//fox成绩
    int c_score;//C语言
    int english_score;//英语成绩
    struct Student *next;
} Student, *pointer_to_Student;

vector<int> fox_score_vector(4, 0);
vector<int> c_score_vector(4, 0);
vector<int> english_score_vector(4, 0);
vector<int> sum_score_vector(4, 0);
map<string, int> map_name_total_score;


bool cmp(int a, int b)
{
    return a > b;
}

void welcome()
{
    cout << "\n";
    cout << "                     ***惟草木之零落兮，恐美人之迟暮*** " << endl;
    cout << "                    ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁" << endl;
    cout << "                    ▏                               |" << endl;
    cout << "                    ▏        1.添加学生              |" << endl;
    cout << "                    ▏        2.打印最高分            |" << endl;
    cout << "                    ▏        3.打印排行榜            |" << endl;
    cout << "                    ▏        4.查找                 |" << endl;//变成课任意插入位置的
    cout << "                    ▏        5.删除                 |" << endl;
    cout << "                    ▏        0.退出                 |" << endl;
    cout << "                    ▏                               |" << endl;
    cout << "                    ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔" << endl;

}

#endif //LEARN_DATA_STRUCTURE_SAMS_H
