// Emin Can ÖZGE
// 1306190022
// Date: 22.12.2019
// Development Environment: Visual Studio 2019 - Version 16.4.2

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int length(int val, string message);

static string lttrs = "";

class links
{
public:
    char name;
    vector <links*>nghbrs;
    string letters = lttrs;
};

void prnt(int maxVal, string& strng, links& source)
{
    strng += source.name;
    if (length(maxVal, strng)) 
	{
        cout << strng << endl;
    }

    for (int i = 0; i < source.nghbrs.size(); i++) 
	{
        prnt(maxVal, strng, *source.nghbrs[i]);
    }

    strng = strng.substr(0, size(strng) - 1);
    if (source.nghbrs.size() == 0) 
	{
        return;
    }
}

int main(int argc, char** argv)
{
    string nodeway = argv[1];

    if (argc != 2) 
	{
        cout << "Wrong parameters entered.";
        exit(1);
    }

    if ((int)nodeway[0] < 48 || (int)nodeway[0] > 57) 
	{
        cout << "Wrong parameters entered.";
        exit(1);
    }

    if ((int)nodeway[size(nodeway) - 1] >= 48 && (int)nodeway[size(nodeway) - 1] <= 57) 
	{
        cout << "Wrong parameters entered.";
        exit(1);
    }

    string lttrs = "";
    char counter[256] = { 0 };

    for (int i = 0; i < size(nodeway); i++)
    {
        if ((int)nodeway[i] < 91 && (int)nodeway[i] >64)
        {
            if (counter[nodeway[i]] == 0)
            {
                lttrs += nodeway[i];
                counter[nodeway[i]]++;
            }
        }
    }

    map<int, links> vrbls;
    string num = "";
    int k = 0;

    for (k; k < size(nodeway); k++)
    {
        if ((int)nodeway[k] >= 48 && (int)nodeway[k] <= 57)
        {
            num += nodeway[k];
        }
        else break;
    }

    string emp;
    string root;
    int maxnum = stoi(num);
    int proc = 0;
    int proc_que[256] = { 0 };

    for (k; k < size(nodeway); k++)
    {
        if ((int)nodeway[k] >= 48 && (int)nodeway[k] <= 57)
        {
            root = emp[0];
            for (int x = 0; x < size(emp); x++)
            {
                if (proc_que[emp[x]] == 0) {
                    vrbls[proc];
                    vrbls[proc].name = emp[x];
                    proc_que[emp[x]] = proc;
                    proc++;
                }
                else continue;
            }

            for (int y = 1; y < size(emp); y++)
            {
                vrbls[proc_que[(int)root[0]]].nghbrs.push_back(&vrbls[proc_que[(int)emp[y]]]);
            }
            emp = "";
            continue;
        }
        else emp += nodeway[k];
    }

    root = emp[0];

    for (int a = 0; a < size(emp); a++)
    {
        if (proc_que[emp[a]] == 0)
        {
            vrbls[proc];
            vrbls[proc].name = emp[a];
            proc_que[emp[a]] = proc;
            proc++;
        }
        else continue;
    }

    for (int a = 1; a < size(emp); a++)
    {
        vrbls[proc_que[(int)root[0]]].nghbrs.push_back(&vrbls[proc_que[(int)emp[a]]]);
    }

    string a = "";
    prnt(maxnum, a, vrbls[0]);
}

int length(int val, string message) 
{
    if (val < message.size()) 
	{
        return 0;
    }
    else return 1;
}