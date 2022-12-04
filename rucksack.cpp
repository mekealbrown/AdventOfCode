#include <bits/utility.h>
#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <utility>
#include <vector>


char strSearch(std::string s1, std::string s2)
{
    for (int i{0}; i < s1.length(); ++i)
    {
        if (s2.find(s1[i]) != std::string::npos)
        {
            return s1[i];
        }
    }
    return ' ';
}

void letterVals(char c, int &x)
{
    char start = 'A';
    std::cout << "char value: " << c << std::endl;
    for (size_t i{0}; i < 58; ++i)
    {
        if (c == start && start > 96)
        {
            x = start - 96;
            std::cout << "first if x: " << x << std::endl << std::endl;
            break;
        }
        else if (c == start && start < 97)
        {
            x = start - 38;
            std::cout << "second if x: " << x << std::endl << std::endl;
            break;
        }
        ++start;
    }
}

int main()
{
    std::string s, subStr1, subStr2;
    std::ifstream infile("day3.txt", std::ios::in);
    char common;
    int length, letterValue, count{0}, sum{0};
    std::cout << "working...\n";
    while (std::getline(infile, s))
    {
        subStr1 = s.substr(0,(s.length()/2));
        subStr2 = s.substr(s.length()/2);
        common = strSearch(subStr1, subStr2);
        letterVals(common, letterValue);
        sum += letterValue;
        ++count;
    }
    std::cout << "Part 1: " << sum << std::endl;
    return 0;
}