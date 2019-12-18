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
    int count = 0;
    cout << "Please number of node you want to insert:";
    cin >> count;
    for (count; count > 0; count--)
    {
        cout << "Please input data you want to insert:";
        cin >> data;
        auto new_node = new synonyms_node;
        new_node->data = data;
        new_node->next = nullptr;
        if (!vector_pointer_to_synonyms[get_hash_position(data)])
        {
            vector_pointer_to_synonyms[get_hash_position(data)] = new_node;
        } else
        {
            new_node->next = vector_pointer_to_synonyms[get_hash_position(data)]->next;
            vector_pointer_to_synonyms[get_hash_position(data)]->next = new_node;
        }
    }
    write_vector_to_file(vector_pointer_to_synonyms, "index.txt");
    write_link_list_to_file(vector_pointer_to_synonyms, "synonyms_node.txt");
}

void delete_synonyms()
{
    int target = 0;
    cout << "Please input the data you want to delete:";
    cin >> target;
    auto position = get_hash_position(target);
    pointer_to_synonyms_node synonyms_node = vector_pointer_to_synonyms[position];
    while (synonyms_node)
    {
        if (synonyms_node->data == target)
        {
            synonyms_node->data = -1;
            synonyms_node = synonyms_node->next;

        } else
        {
            synonyms_node = synonyms_node->next;
        }
    }
    cout << "Delete success!" << endl;

}

void show_file_list()
{
    pointer_to_synonyms_node synonyms_node;
    for (int i = 0; i < vector_pointer_to_synonyms.size(); i++)
    {
        cout << i << ":";
        synonyms_node = vector_pointer_to_synonyms[i];
        while (synonyms_node)
        {
            if (synonyms_node->data == -2)
            {
                synonyms_node = synonyms_node->next;
            }
            if (synonyms_node->data)
            {

                if (synonyms_node->data != -1)
                {
                    cout << synonyms_node->data << " ";
                    synonyms_node = synonyms_node->next;
                } else
                {
                    synonyms_node = synonyms_node->next;
                }
            }
        }
        cout << endl;
    }
}

void find_element()
{
    int target = 0;
    cout << "Please input the target you want to find:";
    cin >> target;
    pointer_to_synonyms_node synonyms_node;
    for (int i = 0; i < vector_pointer_to_synonyms.size(); i++)
    {
        synonyms_node = vector_pointer_to_synonyms[i];
        while (synonyms_node)
        {
            if (synonyms_node->data == target)
            {
                cout << "Its location is:" << i;
                cout << endl;
                synonyms_node = synonyms_node->next;
            } else
            {
                synonyms_node = synonyms_node->next;
            }
        }
    }
}

int get_hash_position(int data)
{
    int position = 0;
    return position = data % 5;
}

void read_link_list_from_file(const string &fileName)
{
    vector<int> splited_data;
    string line_data;
    ifstream read_link_list_from_file;
    read_link_list_from_file.open("D:\\" + fileName, ios_base::binary);
    int count = 0;
    while (read_link_list_from_file)
    {
        getline(read_link_list_from_file, line_data, '\n');
        if (line_data != " ")
        {

            std::regex ws_re("\\s+"); // whitespace
            std::vector<std::string> v(std::sregex_token_iterator(line_data.begin(), line_data.end(), ws_re, -1),
                                       std::sregex_token_iterator());
            vector_pointer_to_synonyms[count] = new synonyms_node;
            vector_pointer_to_synonyms[count]->data = -2;
            pointer_to_synonyms_node tail;
            pointer_to_synonyms_node new_node;
            tail = vector_pointer_to_synonyms[count];
            for (auto i:v)
            {
                new_node = new synonyms_node;
                int data = -1;
                istringstream is(i);
                is >> data;
                new_node->data = data;
                tail->next = new_node;
                tail = new_node;
            }
            tail->next = nullptr;
        }
        count++;
    }
}

int main()
{
    while (true)
    {
        welcome();

        cout << "Please input:";
        char to_do_what;
        cin >> to_do_what;
        system("cls");
        switch (to_do_what)
        {
            case '1':
                insert_to_hash_file();
                break;
            case '2':
                find_element();
                break;
            case '3':
                delete_synonyms();
                break;
            case '4':
                read_link_list_from_file("synonyms_node.txt");
                break;
            case '5':
                show_file_list();
                break;
            case '0':
                return 0;
            default:
                break;
        }
    }
}