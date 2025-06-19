#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <string>
#include <sstream>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 9, 10, 11};
    std::cout << std::count(vec.begin(), vec.end(), 4) << std::endl;
    std::cout << std::count_if(vec.begin(), vec.end(), std::bind(std::isgreater<int, int>, std::placeholders::_1, 4)) << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), std::bind(std::isgreater<int, int>, 8, std::placeholders::_1)), vec.end());
    std::for_each(vec.begin(), vec.end(), std::bind(printf, "%d ", std::placeholders::_1));
    std::vector<int> vec2;
    std::transform(vec.begin() == vec.end() ? vec.begin() : std::next(vec.begin()), vec.end(), vec.cbegin(), std::back_inserter(vec2), std::minus<int>());
    std::for_each(vec2.begin(), vec2.end(), std::bind(printf, "%d ", std::placeholders::_1));
    std::cout << std::endl;
    std::cout << std::accumulate(vec2.begin(), vec2.end(), 0) << std::endl;
    return 0;
}
