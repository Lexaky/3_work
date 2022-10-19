#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Задание 3:
Дан текстовый файл. С консоли считывается строка.
Найти номера всех строк, в которых встречается данная строка.
*/

int main()
{
    setlocale(LC_ALL, "rus");
    const int MAX_SYMBOLS = 256;
    //char *str_check = new char[MAX_SYMBOLS];
    //char *str_read = new char[MAX_SYMBOLS];
    string str_check;
    string str_read;
    char str[MAX_SYMBOLS];
    cout << "Enter string: ";
    cin >> str_check;
    int currentString = 0; //Кол-во строк с встреченной подстрокой
    ifstream file;
    file.open("F.txt", ios::out);

    if (!file)
    {
        cout << "File doesn't opened!" << endl;
        return 0;
    }
    while (!file.eof())
    {
        file.getline(str, MAX_SYMBOLS); currentString++;
        str_read = str;
        if (str_read.length() != 0 && str_check.length() <= str_read.length())
        { //Длина считанной строки не равна 0, подстрока меньше строки из файла
            for (int i = 0; i < str_read.length() - str_check.length(); i++) {
                for (int j = 0; j <= str_check.length(); j++)
                {
                    if (str_read[i] == str_check[j] && str_read[i+1] == str_check[j+1] && str_read[i+2] == str_check[j+2])
                    {
                        cout << str_check << " in " << currentString  << " string" << endl;
                        i = str_read.length() - str_check.length();
                        break;
                    }
                }
            }
        }

    }

    file.close();
    return 0;
}
