#include <ios>
#include <iostream>
#include <fstream>
#include <string>

void getData(std::string *str, int &len)
{
    std::ifstream indata; 
    int count{0};
    indata.open("test.txt", std::ios::in); 
    if(!indata) 
    { 
      std::cerr << "Error: file could not be opened" << std::endl;
      exit(1);
    }
    while (1) 
    {
        if (indata.eof())
        {
            break;
        }
        indata >> str[count]; 
        ++count;
        
        //std::cout << count << "\n";
    }
    len = count;
    indata.close();
    //std::cout << "End-of-file reached.." << std::endl;
}

int processData(std::string *ptr, int len)
{
//    int count{0}, totalScore{0}, round{0};
//    while (len - 2)
//    {
//        if (ptr[count + 1] == "X")
//        {
//            switch (round) 
//            {
//                case 0:
//                    totalScore += 2 + 6;        //round 0 we want to win 
//                    break;
//                case 1:
//                    totalScore += 3 + 0;         //round 1 we want to lose
//                    break;
//                case 2:
//                    totalScore += 1 + 3;
//                    break;
//            }
//
//        }
//        if (ptr)
//        if (round == 3)
//        {
//            round = 0;
//        }
//    }
    int totalScore{0}, count{0};
    std::cout << "working...\n";
    while (len) 
    {
        if (ptr[count] == "A")
        {
            if (ptr[count + 1] == "X")
            {
                totalScore += 3 + 0;
            }
            else if (ptr[count + 1] == "Y")
            {
                totalScore += 1 + 3;
            }
            else if (ptr[count + 1] == "Z")
            {
                totalScore += 2 + 6;
            }
        }
        else if (ptr[count] == "B")
        {
            if (ptr[count + 1] == "X")
            {
                totalScore += 1 + 0;
            }
            else if (ptr[count + 1] == "Y")
            {
                totalScore += 2 + 3;
            }
            else if (ptr[count + 1] == "Z")
            {
                totalScore += 3 + 6;
            }
        }
        else if (ptr[count] == "C")
        {
            if (ptr[count + 1] == "X")
            {
                totalScore += 2 + 0;
            }
            else if (ptr[count + 1] == "Y")
            {
                totalScore += 3 + 3;
            }
            else if (ptr[count + 1] == "Z")
            {
                totalScore += 1 + 6;
            }
        }
        count += 2;
        len -= 2;
    }
    return totalScore;
}


int main()
{
    int len;
    std::string *str = new std::string[10000];
    getData(str, len);
    std::string *nStr = new std::string[len];
    for (int i{0}; i < len; ++i)
    {
        nStr[i] = str[i];
    }
    delete [] str;
    int total = processData(nStr, len);
    std::cout << total << "\n";
}