#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "stack.h"
#include "queue.h"




int main()
{
    Stack<std::string> a, b, c, d, e, f, g, h ,i;
    Stack<std::string> part2;
    std::string s;
    int x, y, z;
    a.push("M");  a.push("J"); a.push("C"); a.push("B"); a.push("F"); a.push("R"); a.push("L"); a.push("H");
    b.push("Z"); b.push("C"); b.push("D");
    c.push("H");c.push("J");c.push("F");c.push("C");c.push("N");c.push("J");c.push("W");
    d.push("P");d.push("J");d.push("D");d.push("M");d.push("T");d.push("S");d.push("B");
    e.push("N");e.push("C");e.push("D");e.push("R");e.push("J");
    f.push("W");f.push("L");f.push("D");f.push("Q");f.push("P");f.push("J");f.push("G");f.push("Z");
    g.push("P");g.push("Z");g.push("T");g.push("F");g.push("R");g.push("H"); 
    h.push("L");h.push("V");h.push("M");h.push("G");
    i.push("C");i.push("B");i.push("G");i.push("P");i.push("F");i.push("Q");i.push("R");i.push("J");

    std::string hold, temp;
    char test;
    int count{1};
    std::ifstream infile{"day1.txt", std::ios::in};
    while (std::getline(infile, s))
    {
        
        test = s[1];
        //std::cout << "test = " << test << "\n";
        std::cout << "line = " << count++ << "\n";
        if (test != ',')
        {
            temp = s[0];
            temp += s[1];
           // std::cout << "values: " << s[4] << " " << s[6] << "\n";
            x = std::stoi(temp); y = atoi(&s[3]); z = atoi(&s[5]);
           // std::cout << "x = " << x << "\n" << "y = " << y << "\n" << "z = " << z << "\n";
        }
        else  
        {
            x = atoi(&s[0]); y = atoi(&s[2]); z = atoi(&s[4]);
           //std::cout << "x = " << x << "\n" << "y = " << y << "\n" << "z = " << z << "\n";

        }
        for (int k{0}; k < x; ++k)
        {
            //std::cout << "working...\n";
            //std::cout << "z = " << z << "\n";
            if (y == 1) {hold = a.pop();}
            else if (y == 2) {hold = b.pop();}
            else if (y == 3) {hold = c.pop();}
            else if (y == 4) {hold = d.pop();}
            else if (y == 5) {hold = e.pop();}
            else if (y == 6) {hold = f.pop();}
            else if (y == 7) {hold = g.pop();}
            else if (y == 8) {hold = h.pop();}
            else if (y == 9) {hold = i.pop();}

            part2.push(hold);
        }
        for (int j{0}; j < x; ++j)
        {
            if (z == 1) {a.push(part2.pop());}
            else if (z == 2) {b.push(part2.pop());}
            else if (z == 3) {c.push(part2.pop());}
            else if (z == 4) {d.push(part2.pop());}
            else if (z == 5) {e.push(part2.pop());}
            else if (z == 6) {f.push(part2.pop());}
            else if (z == 7) {g.push(part2.pop());}
            else if (z == 8) {h.push(part2.pop());}
            else if (z == 9) {i.push(part2.pop());}
        }
        std::cout << "a: ";a.print(); std::cout << "\n"; std::cout << "b: ";b.print(); std::cout << "\n"; std::cout << "c: ";c.print(); std::cout << "\n"; std::cout << "d: ";d.print(); std::cout << "\n"; std::cout << "e: ";e.print(); std::cout << "\n"; std::cout << "f: ";f.print(); std::cout << "\n"; std::cout << "g: ";g.print(); std::cout << "\n"; std::cout << "h: ";h.print(); std::cout << "\n"; std::cout << "i: ";i.print(); std::cout << "\n";
        std::cout << "\n";
    }
   // std::cout << "Answer: " << a.pop() << b.pop() << c.pop()<< d.pop()<< e.pop()<< f.pop()<< g.pop()<< h.pop()<< i.pop() << "\n";
}

