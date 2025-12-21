
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>

int readIntFromLine(const std::string &prompt)
{
    using namespace std;
    string line;
    int value;
    for (;;)
    {
        cout << prompt << flush;
        if (!getline(cin, line))
        {
            cin.clear();
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }
        stringstream ss(line);
        if (ss >> value)
        {
            string rest;
            if (!(ss >> rest))
                return value;
        }

        cout << "输入无效，请输入一个整数。" << endl;
    }
}

int main(void)
{
    using namespace std;

    for (;;)
    {
        cout << "======================" << endl;
        cout << "请选择功能：" << endl;
        cout << "1) hakimi 加法小程序" << endl;
        cout << "2) hakimi学你说话" << endl;
        cout << "3) 退出 (或 输入 q)" << endl;
        cout << "by 卢本伟" << endl;
        cout << "qq 3178644407"<<endl;
        cout << "输入选项编号并回车：" << endl;
        string choice;
        if (!getline(cin, choice))
        {
            cin.clear();
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }
        auto trim = [](string &s) {
            size_t a = s.find_first_not_of(" \t\r\n");
            size_t b = s.find_last_not_of(" \t\r\n");
            if (a == string::npos) { s.clear(); return; }
            s = s.substr(a, b - a + 1);
        };
        trim(choice);

        if (choice == "1")
        {
            int hakimi = readIntFromLine("tell me how many hakimi do you have? ");
            cout << "现在你太有hakimi了 我给你114514个" << endl;
            hakimi = 114514 + hakimi;
            cout << "所以你有" << hakimi << "个hakimi了" << endl;
            cout << "智障hakimi小程序 by卢本伟 去吧小子" << endl;
            cout << "按回车返回主菜单..." << endl;
            string tmp;
            getline(cin, tmp);
        }
        else if (choice == "2")
        {
            cout << "我学你说话（输入内容将被回显）。输入 \":q\" 或 \"exit\" 或单独的 \"q\" 返回主菜单。" << endl;
            for (;;)
            {
                cout << "> " << flush;
                string line;
                if (!getline(cin, line))
                {
                    cin.clear();
                    this_thread::sleep_for(chrono::milliseconds(100));
                    continue;
                }

                string t = line;
                trim(t);
                if (t == ":q" || t == "exit" || t == "q" || t == "Q")
                {
                    cout << "返回主菜单..." << endl;
                    break;
                }

                cout << line << endl;
            }
        }
        else if (choice == "3" || choice == "q" || choice == "Q")
        {
            cout << "退出程序..." << endl;
            break;
        }
        else
        {
            cout << "无效选项，请重试。" << endl;
        }
    }

    return 114514;
}