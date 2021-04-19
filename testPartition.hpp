/*
    testPartition.cpp
*/

#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <bitset>

// Tests a sort
template <typename Sort>
void testSort(Sort sort) {

    constexpr int SIZE = 12;
    for (int i = 0; i < std::pow(2, SIZE); ++i) {

        std::vector<int> num;
        for (auto c : std::bitset<SIZE>(i).to_string())
            num.push_back(c - '0');
        std::reverse(num.begin(), num.end());

        // perform the sort on this value in sequenc
        sort(num, 0, num.size() - 1);

        // output and if no error overwrite line on next output
        std::cout << '\r';
        std::copy(num.begin(), num.end(), std::ostream_iterator<int>(std::cout, ""));
        assert(std::is_sorted(num.begin(), num.end()));
    }
}

// Tests a Lomuto Partitition in a Quicksort
template <typename Partition>
void testLomutoPartition(Partition partition) {

    std::function<void(std::vector<int>& a, int low, int high)> sort =
    [&](auto& a, int low, int high) {

        if (low >= high)
            return;

        auto p = partition(a, low, high);
        sort(a, low, p - 1);
        sort(a, p + 1, high);
    };

    // test the sort
    testSort(sort);
}

// Tests a Hoare Partitition in a Quicksort
template <typename Partition>
void testHoarePartition(Partition partition) {

    std::function<void(std::vector<int>& a, int low, int high)> sort =
    [&](auto& a, int low, int high) {

        if (low >= high)
            return;

        auto p = partition(a, low, high);
        sort(a, low, p);
        sort(a, p + 1, high);
    };

    // test the sort
    testSort(sort);
}
