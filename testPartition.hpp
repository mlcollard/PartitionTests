/*
    testPartition.cpp
*/

#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <bitset>

template <typename Partition>
void testHoarePartition(Partition partition) {

    std::function<void(std::vector<int>& a, int low, int high)> sortinner;
    sortinner = [&partition,&sortinner](std::vector<int>& a, int low, int high) {

        if (low >= high)
            return;

        auto p = partition(a, low, high);
        sortinner(a, low, p);
        sortinner(a, p + 1, high);
    };

    // convenience form for tests
    auto sort = [&sortinner](std::vector<int>& a) {
        sortinner(a, 0, a.size() - 1);
    };

    constexpr int SIZE = 8;
    for (int i = 0; i < std::pow(2, SIZE); ++i) {
        std::bitset<SIZE> bs = i;

        std::vector<int> num;
        for (auto c : bs.to_string())
            num.push_back(c - '0');
        std::reverse(num.begin(), num.end());

        sort(num);

        // output error
        if (!std::is_sorted(num.begin(), num.end())) {
            std::cerr << "Partition error: ";
            for (int i = 0; i < SIZE; ++i)
                std::cerr << num[i];
            std::cerr << '\n';
        }
        assert(std::is_sorted(num.begin(), num.end()));
    }
}

template <typename Partition>
void testLomutoPartition(Partition partition) {

    std::function<void(std::vector<int>& a, int low, int high)> sortinner;
    sortinner = [&partition,&sortinner](std::vector<int>& a, int low, int high) {

        if (low >= high)
            return;

        auto p = partition(a, low, high);
        sortinner(a, low, p - 1);
        sortinner(a, p + 1, high);
    };

    // convenience form for tests
    auto sort = [&sortinner](std::vector<int>& a) {
        sortinner(a, 0, a.size() - 1);
    };

    const int SIZE = 10;
    for (int i = 0; i < std::pow(2, SIZE); ++i) {
        int n = i;
        std::vector<int> num;
        while (n) {
            if (n % 2) {
                num.push_back(1);
            }
            else {
                num.push_back(0);
            }
            n = n / 2;
        }
        for (int i = num.size(); i < SIZE; ++i)
            num.push_back(0);

        std::reverse(num.begin(), num.end());
        sort(num);
        if (!std::is_sorted(num.begin(), num.end())) {
            std::cerr << "Partition error: ";
            for (int i = 0; i < SIZE; ++i)
                std::cerr << num[i];
            std::cerr << '\n';
        }
        assert(std::is_sorted(num.begin(), num.end()));
    }
}
