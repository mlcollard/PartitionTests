/*
    PartitionLomuto.cpp
*/

#include <iostream>
#include <cmath>
#include <ostream>
#include <utility>
#include <vector>
#include <algorithm>
#include "testPartition.hpp"

int main() {

    // Lomuto Partition Wikipedia Algorithm
    int counter = 0;
    testLomutoPartition([&counter](auto& a, int low, int high)->int {

        int pivot = a[high];
        int i = low;
        for (int j = low; j <= high; ++j) {
            if (a[j] < pivot) {
                std::swap(a[i], a[j]);
                ++counter;
                ++i;
            }
        }
        std::swap(a[i], a[high]);
        ++counter;

        return i;
    });
    std::cout << "Lomuto: " << counter << '\n';

    // Lomuto Partition Wikipedia Algorithm Rewrite
    counter = 0;
    testLomutoPartition([&counter](auto& a, int low, int high)->int {

        int pivot = a[high];
        int i = low;
        int left2 = low;
        while (left2 <= high) {

            if (a[left2] < pivot) {
                std::swap(a[i], a[left2]);
                ++counter;
                ++i;
            }
            ++left2;
        }
        std::swap(a[i], a[high]);
        ++counter;

        return i;
    });
    std::cout << "Lomuto: " << counter << '\n';

    return 0;
}
