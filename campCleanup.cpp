#include <cstddef>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    std::string s;
    std::ifstream infile("day4.txt", std::ios::in);
    int final{0};
    while (std::getline(infile, s))
    {
        int a, b, c, d;
        sscanf(s.c_str(), "%d-%d, %d-%d", &a, &b, &c, &d);
        
        if (a >= c && b <= d || c >= a && d <= b)
        {
            ++final;
        } 
    }
    std::cout << "final: " << final << std::endl;
}




//int hold2{num4 - num3}; int hold1{num2 - num1};
        //int test{0}, print{0};
        //if (hold1 >= hold2)
        //{
        //    for (size_t i{0}; i < hold2 + 1; ++i)
        //    {
        //        for (int k{0}; k < hold1 + 1; ++k)
        //        {
        //            //std::cout << "num1: " << num1 << " num3: " << num3 << std::endl;
        //            if (num3 == num1)
        //            {
        //                ++test;
        //            }
        //            ++num1;
        //        }
        //        ++num3;
        //        num1 = n1;
        //        //std::cout << "loop done...\n"; 
        //    }
        //    //std::cout << "test: " << test << std::endl;
        //    if (test > 0) //change to '== hold2 + 1' for part1 solution
        //    {
        //        std::cout << "added to final...\n\n";
        //        ++final;
        //    }
        //}
        //else if (hold2 >= hold1)
        //{
        //    std::cout << "second conditional...\n";
        //    for (size_t j{0}; j < hold1 + 1; ++j)
        //    {
        //        for (int l{0}; l < hold2 + 1; ++l)
        //        {
        //            if (num1 == num3)
        //            {
        //                ++test;
        //            }
        //            ++num3;
        //        }
        //        ++num1;
        //        num3 = n3;
        //    }
        //    if (test > 0 ) //change to '== hold1 + 1' for part1 solution
        //    {
        //        std::cout << "added to final...\n\n";
        //        ++final;
        //    }
        //}
        //num1 = num2 = num3 = num4 = test = 0;
        ////std::cout << "next line...\n\n";