#include <iostream>
#include <string>

bool isNumber(const std::string& s)
{
    for (char const &ch : s) 
    {
        if (std::isdigit(ch) == 0) 
        {
            return false;
        }
    }
    return true;
}

struct tim
{
    int h, m, s;
};

void add(tim t1, tim t2)
{
    tim t;
    t.h = t1.h + t2.h;
    t.m = t1.m + t2.m;
    t.s = t1.s + t2.s;

    if(t.s > 59)
    {
        t.s = t.s - 60;
        t.m = t.m + 1;
    }

    if(t.m > 59)
    {
        t.m = t.m - 60;
        t.h = t.h + 1;
    }

    if(t.h < 0)
    {
        t.m = 60 - t.m;
        t.s = 60 - t.s;
    }

    std::cout << "Result of addition = " << t.h << ":" << t.m << ":" << t.s; 
}

void subtract(tim t1, tim t2)
{
    tim t;
    t.h = t1.h - t2.h;
    t.m = t1.m - t2.m;
    t.s = t1.s - t2.s;

    if(t.s < 0)
    {
        t.s = t.s + 60;
        t.m = t.m - 1;
    }

    if(t.m < 0)
    {
        t.m = t.m + 60;
        t.h = t.h - 1;
    }

    if(t.h < 0)
    {
        t.m = 60 - t.m;
        t.s = 60 - t.s;
    }

    std::cout << "Result of subtraction = " << t.h << ":" << t.m << ":" << t.s;
}

int tosec(tim t1)
{
    return (((t1.h * 60) + t1.m) * 60 + t1.s);
}

void compare(tim t1, tim t2) //Not really sure whether I understood it
{
    if(tosec(t1) > tosec(t2))
    {
        std::cout << "Time 1 > Time 2";
    }
    else
    {
        std::cout << "Time 1 < Time 2"; 
    }
}

void totime(int s)
{
    tim t;
    
    t.m = s / 60;
    t.s = s - (t.m * 60);
    t.h = t.m / 60;
    t.m = t.m - (t.h * 60);
    
    std::cout << s << "s = " << t.h << ":" << t.m << ":" << t.s;
}

int main(int argc, char* argv[])
{
    if(argc < 3 || argc == 4 || argc == 6 || argc == 7 || argc > 8)
    {
        std::cerr << "The program should be called:\n"
                  << "`time <operation> <time 1> [<time 2>]`\n"
                  << "Where:\n"
                  << "- operation - one of the following: add, sub, cmp, tosec, totime\n"
                  << "- time - three numbers separated by a space: hours, minutes, seconds\n"
                  << "- in case of totime <time 1> should be a just number of seconds";
        return 1;
    }

    std::string op = argv[1];

    if(op == "totime" && argc != 3)
    {
        std::cerr << "Error: Inproper operation name or not enough/too many arguments for selected function(in case of totime <time 1> should be a just number of seconds)\n";
        return 1;
    }
    else if(op == "totime" && !isNumber(argv[2]))
    {
        std::cerr << "Error: Provided amount of seconds is not a number\n";
        return 1;
    }
    else if(op == "totime" && argc == 3)
    {
        int s = std::stoi(argv[2]);
        totime(s);
        return 0;
    }

    if(!isNumber(argv[2]) || !isNumber(argv[3]) || !isNumber(argv[4]))
    {
        std::cerr << "Error: One of the values of time is not a number\n";
        return 1;
    }
    else if(argc == 8)
    {
        if(!isNumber(argv[5]) || !isNumber(argv[6]) || !isNumber(argv[7]))
        {
            std::cerr << "Error: One of the values of time is not a number\n";
        return 1;
        }
    }

    tim t1, t2;
        
    t1.h = std::stoi(argv[2]);
    t1.m = std::stoi(argv[3]);
    t1.s = std::stoi(argv[4]);

    if(t1.m > 59 || t1.s > 59 || t1.m < 0 || t1.s < 0) // Assumed number of hours can be negative since it just points to the past, but it's a quick fix
    {
            std::cerr << "Error: Wrong time format\n";
            return 1;
    }
    
    if(argc == 8)
    {
        t2.h = std::stoi(argv[5]);
        t2.m = std::stoi(argv[6]);
        t2.s = std::stoi(argv[7]);
        if(t2.m > 59 || t2.s > 59 || t2.m < 0 || t2.s < 0)
        {
            std::cerr << "Error: Wrong time format\n";
            return 1;
        }
    }

    if(op == "add" && argc == 8) 
    {
        add(t1, t2);
    } 
    else if(op == "sub" && argc == 8) 
    {
        subtract(t1, t2);
    } 
    else if(op == "cmp" && argc == 8) 
    {
        compare(t1, t2);
    } 
    else if(op == "tosec" && argc == 5)
    {
        std::cout << tosec(t1);
    }
    else 
    {
        std::cerr << "Error: Inproper operation name or not enough/too many arguments for selected function(in case of totime <time 1> should be a just number of seconds)\n";
        return 1;
    }
}