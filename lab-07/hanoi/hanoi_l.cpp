#include <iostream>
#include <string>

void hanoi_l(int n, std::string start, std::string end, std::string temp)
{
    if(n > 0){
        hanoi_l(n - 1, start, end, temp);
        std::cout << "Move disk " << n << " from " << start << " to " << end << "\n";
        hanoi_l(n - 1, start, end, temp);
    }
    return 0;
}