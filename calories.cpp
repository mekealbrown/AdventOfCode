//#include <cstddef>
//#include <fstream>
//#include <ios>
//#include <string>
//#include <iostream>
//#include <utility>
//#include <vector>
//
//int main()
//{
//    //std::vector<std::string> data;
//    //std::ifstream infile("day1.txt");
//    //std::string temp;
//    //while (std::getline(infile,temp))
//    //{
//    //    data.push_back(temp);
//    //}
//    //int sum{0}, winner1{0}, winner2{0}, winner3{0};
//    //for (const auto& i : data)
//    //{
//    //    if (!i.empty())
//    //    {
//    //        sum += std::stoi(i);
//    //        std::cout << "sum: " << sum << std::endl;
//    //    }
//    //    else 
//    //    {
//    //        if (sum > winner1)
//    //        {
//    //            winner3 = winner2;
//    //            winner2 = winner1;
//    //            winner1 = sum;
//    //        }
//    //        else if (sum > winner2)
//    //        {
//    //            winner2 = sum;
//    //        }
//    //        else if (sum > winner3)
//    //        {
//    //            winner3 = sum;
//    //        }
//    //        sum = 0;
//    //    }
//    //    std::cout << "1: " << winner1 << " 2: " << winner2 << " 3: " << winner3 << std::endl << std::endl;
//    //}
//    //std::cout << "Total Among Top 3: " << winner1 + winner2 + winner3 << "\n";
//}
//
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

int main() {
    std::vector<int> data = {0};
    std::ifstream infile("day1.txt", std::ios::in);
    std::string temp;

    while (std::getline(infile, temp)) 
    {
        std::cout << "hey\n";
        if (temp == "") {       
            data.push_back(0);    
        } else {     
            data.back() += std::stoi(temp);     
            std::cout << "hey\n";    
        }
    }

  std::partial_sort(data.begin(), data.begin() + 3, data.end(), std::greater<int>{});
  std::cout << "Part 1: " << data[0] << '\n';
  std::cout << "Part 2: " << std::accumulate(data.begin(), data.begin() + 3, 0) << '\n';

  return 0;
}