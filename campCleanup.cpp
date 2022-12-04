#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>


int main()
{
    std::string s, str1{""}, str2{""}, str3{""}, str4{""};
    std::ifstream infile("day4.txt", std::ios::in);
    int num1, num2, num3, num4, count{0}, result{0}, final{0}, n1, n2, n3, n4;
    bool first{true};
    while (std::getline(infile, s))
    {
        str1 = str2 = str3 = str4 = "";
        for (size_t i{0}; i < s.length(); ++i)
        {
            if (s[i] == '-')
            {
                first = false;
                ++count;
                continue;
            }
            else if (s[i] == ',')
            {
                first = true;
                ++count;
                continue;
            }
            switch (count) {
                case 0:
                    str1 += s[i];
                    break;
                case 1:
                    str2 += s[i];
                    break;
                case 2:
                    str3 += s[i];
                    break;
                case 3:
                    str4 += s[i];
                    break;       
            }
        }
        count = 0;
        num1 = n1 = std::stoi(str1); num2 = n2 = std::stoi(str2); 
        num3 = n3 = std::stoi(str3); num4 = n4 = std::stoi(str4);
        int hold2{num4 - num3}; int hold1{num2 - num1};
        int test{0}, print{0};
        if (hold1 >= hold2)
        {
            for (size_t i{0}; i < hold2 + 1; ++i)
            {
                for (int k{0}; k < hold1 + 1; ++k)
                {
                    //std::cout << "num1: " << num1 << " num3: " << num3 << std::endl;
                    if (num3 == num1)
                    {
                        ++test;
                    }
                    ++num1;
                }
                ++num3;
                num1 = n1;
                //std::cout << "loop done...\n"; 
            }
            //std::cout << "test: " << test << std::endl;
            if (test > 0) //change to '== hold2 + 1' for part1 solution
            {
                std::cout << "added to final...\n\n";
                ++final;
            }
        }
        else if (hold2 >= hold1)
        {
            std::cout << "second conditional...\n";
            for (size_t j{0}; j < hold1 + 1; ++j)
            {
                for (int l{0}; l < hold2 + 1; ++l)
                {
                    if (num1 == num3)
                    {
                        ++test;
                    }
                    ++num3;
                }
                ++num1;
                num3 = n3;
            }
            if (test > 0 ) //change to '== hold1 + 1' for part1 solution
            {
                std::cout << "added to final...\n\n";
                ++final;
            }
        }
        num1 = num2 = num3 = num4 = test = 0;
        //std::cout << "next line...\n\n";
    }
    std::cout << "final: " << final << std::endl;
}