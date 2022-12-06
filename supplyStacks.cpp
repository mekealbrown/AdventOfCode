#include <cctype>
#include <cstdio>
#include <cstring>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"
#include "queue.h"

int main()
{
    std::string hold;
    std::ifstream infile("day5.txt", std::ios::in);
    Stack<std::string> columns[9];
    Queue<std::string> inData;
    bool flag{false}; //to start getting move data in
    while (std::getline(infile, hold))
    {
        int a , b , c;
        if (hold.length() == 0)
        {
            flag = true;
            continue;
        }
        if (flag == false)
        {
            inData.push(hold);
        }
        else if (flag == false)
        {
            sscanf(hold.c_str(), "%d %d %d", &a, &b, &c);
        }
    }
    //while (inData.isEmpty() != true)
    //{
    //    //std::cout << "data: " << inData.pop() << "\n";
    //}
}