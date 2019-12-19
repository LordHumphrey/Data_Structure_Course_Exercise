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
            @Time: 2019/12/9 13:57
            @Project_NAME：Learn_Data_Structure
            @FileName: SAMS.cpp
            @IDE: CLion
*/
#include <iostream>
#include "SAMS.h"

using namespace std;


void get_data(pointer_to_Student &header_student) //获取待添加的信息
{
    header_student = new Student;
    int to_add_student_number;
    cout << "请输入要增加的学生数:";
    cin >> to_add_student_number;
    pointer_to_Student new_node, p = header_student;
    for (int i = 0; i < to_add_student_number; i++)
    {
        new_node = new Student;
        cout << "请输入姓名:";
        cin >> new_node->user_name;
        cout << "请输入学号:";
        cin >> new_node->user_id;
        cout << "请输入Fox成绩:";
        cin >> new_node->fox_score;
        cout << "请输入C成绩:";
        cin >> new_node->c_score;
        cout << "请输入英语成绩:";
        cin >> new_node->english_score;
        fox_score_vector[i] = new_node->fox_score;
        c_score_vector[i] = new_node->c_score;
        english_score_vector[i] = new_node->english_score;
        sum_score_vector[i] = new_node->fox_score + new_node->c_score + new_node->english_score;
        map_name_total_score[new_node->user_name] = sum_score_vector[i];
        new_node->next = p->next;
        p->next = new_node;
    }
    cout << "全部处理完成，要不要打赏~" << endl;
    system("cls");

}

void print_total_score_descending() // 打印最高成绩
{
    int max_total_score = *max_element(sum_score_vector.begin(), sum_score_vector.end());
    sort(sum_score_vector.begin(), sum_score_vector.end(), cmp);
    system("cls");
    for (auto i = map_name_total_score.begin(); i != map_name_total_score.end(); i++)
    {
        if (i->second == max_total_score)
        {
            cout << "成绩最高获得者是:" << i->first << " 最高成绩为:" << i->second << endl;
        }
    }
}

void print_achievement_ranking() //打印排行榜
{
    sort(sum_score_vector.begin(), sum_score_vector.end(), cmp);
    system("cls");
    for (auto j = 0; j < sum_score_vector.size(); j++)
    {
        for (auto i = map_name_total_score.begin(); i != map_name_total_score.end(); i++)
        {
            if (i->second == sum_score_vector[j])
            {
                cout << "第" << j + 1 << "名是:" << i->first << " 成绩为:" << i->second << endl;
            }
        }
    }
}

void search_by_user_id(pointer_to_Student header_student) //通过学号查找
{
    header_student = header_student->next;
    int target_user_id = 0;
    search:
    system("cls");
    cout << "请输入带查询学号:";
    cin >> target_user_id;
    while (header_student)
    {
        if (header_student->user_id == target_user_id)
        {
            cout << "找到啦~" << endl;
            cout << "目标姓名:" << header_student->user_name;
            cout << "总分" << map_name_total_score[header_student->user_name] << endl;
            break;
        } else
        {
            header_student = header_student->next;
        }
    }
    if (header_student == nullptr)
    {
        cout << "没找到呀~再给你一次机会" << endl;
    }
    char continue_or_not;
    cout << "是否继续查询:";
    cin >> continue_or_not;
    if (continue_or_not == 'y' || continue_or_not == 'Y')
    {
        goto search;
    } else
    {
        return;
    }
}

void delete_student(pointer_to_Student &header_student) //通过学号删除学生
{
    pointer_to_Student forward_node = header_student;
    header_student = header_student->next;
    int to_delete_student_user_id = 0;
    system("cls");
    cout << "请输入待删除学生学号(数据无价，谨慎操作~):" << endl;
    cin >> to_delete_student_user_id;
    while (header_student)
    {
        if (header_student->user_id == to_delete_student_user_id)
        {
            cout << "已经删除~" << endl;
            forward_node->next = header_student->next;
            break;
        } else
        {
            forward_node = header_student;
            header_student = header_student->next;
        }
    }
}


int main()
{
    pointer_to_Student pointer_Student = nullptr;
//    get_data(pointer_Student);
//    print_total_score_descending();
//    print_achievement_ranking();
//    search_by_user_id(pointer_Student);

    while (true)
    {
        welcome();

        cout << "请输入:";
        char to_do_what;
        cin >> to_do_what;
        system("cls");

        switch (to_do_what)
        {
            case '1':
                get_data(pointer_Student);
                break;
            case '2':
                print_total_score_descending();
                system("cls");
                break;
            case '3':
                print_achievement_ranking();
                system("cls");
                break;
            case '4':
                search_by_user_id(pointer_Student);
                system("cls");
                break;
//            case '5':
//                delete_student(pointer_Student);
//                break;
            case '0':
                return 0;
            default:
                break;
        }
    }
}