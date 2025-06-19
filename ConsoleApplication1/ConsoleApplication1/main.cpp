#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <string>

bool largerThanFour(int num) {
    return num > 4;
}

bool lessThanEight(int num) {
    return num < 8;
}

std::string spacePrint(std::string a, int b) {
    return std::move(a) + std::to_string(b) + ' ';
}

int subtruct(int num) {
    static int prev;
    int res = prev - num;
    prev = num;
    return res;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 9, 10, 11};
    std::cout << std::count(vec.begin(), vec.end(), 4) << std::endl;
    std::cout << std::count_if(vec.begin(), vec.end(), largerThanFour) << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), lessThanEight), vec.end());
    std::cout << std::accumulate(vec.begin(), vec.end(), std::string(), spacePrint);
    std::vector<int> vec2;
    std::accumulate(vec.begin(), vec.end(), vec2, subtruct);
    


    return 0;
}
