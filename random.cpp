#include <random>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> v = {7, 5, 16, 8};
    v.push_back(17);
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 9);
    std::cout << dist(rd)<< '\n';

    std::cout << v[1] << '\n';
    return 0;
}
