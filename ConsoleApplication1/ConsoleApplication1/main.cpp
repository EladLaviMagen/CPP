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


int subtructFromPrev(int num) {
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
    std::cout << std::accumulate(vec.begin(), vec.end(), std::string(), spacePrint) << std::endl;
    std::vector<int> vec2;
    ///Regarding section 7 because the first element does not have an element before it, I treat it like there is a 0 prior to it.
    std::transform(vec.cbegin(), vec.cend(), std::back_inserter(vec2), subtructFromPrev);
    std::cout << std::accumulate(vec2.begin(), vec2.end(), std::string(), spacePrint) << std::endl;
    std::cout << std::accumulate(vec2.begin(), vec2.end(), 0) << std::endl;
    return 0;
}
