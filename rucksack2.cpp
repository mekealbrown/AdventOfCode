#include <bits/utility.h>
#include <cctype>
#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <string.h>
#include <utility>
#include <vector>


void strSearch(std::string s1, std::string s2, std::string s3, char &letter)
{
    std::string temp{""};
    for (int i{0}; i < s1.length(); ++i)
    {
        for (int j{0}; j < s2.length() + 1; ++j)
        {
            if (s1[i] == s2[j])
            {
                temp += s2[j];
            }
        }
    }
    for (int k{0}; k < temp.length(); ++k)
    {
        for (int l{0}; l < s3.length(); ++l)
        {
            if (temp[k] == s3[l])
            {
                letter = s3[l];
            }
        }
    }
}

void letterVals(char c, int &x)
{
    char start = 'A';
    for (size_t i{0}; i < 58; ++i)
    {
        if (c == start && start > 96)
        {
            x = start - 96;
            break;
        }
        else if (c == start && start < 97)
        {
            x = start - 38;
            break;
        }
        ++start;
    }
}

int main()
{
    std::string s, testStr1{""}, testStr2{""}, testStr3{""};
    std::ifstream infile("day3.txt", std::ios::in);
    char common;
    int length, letterValue, count{0}, sum{0};
    std::cout << "working...\n";
    while (std::getline(infile, s))
    {
        switch (count) {
            case 0:
                testStr1 = s;
                ++count;
                break;
            case 1:
                testStr2 = s;
                ++count;
                break;
            case 2:
                testStr3 = s;
                ++count;
                break;
        }
        if (count == 3)
        {
            strSearch(testStr1, testStr2, testStr3, common);
            letterVals(common, letterValue);
            sum += letterValue;
            count = 0;
        }
        
    }
    std::cout << "Part 2: " << sum << std::endl;
    return 0;
}