/*
    PartitionHoare.cpp
*/

#include <iostream>
#include <cmath>
#include <ostream>
#include <utility>
#include <vector>
#include <algorithm>
#include "testPartition.hpp"

int main() {

    // Hoare Partition Wikipedia Algorithm
    int counter = 0;
    testHoarePartition([&counter](std::vector<int>& a, int low, int high)->int {

        int pivot = a[std::floor((low + high) / 2)];
        int left = low - 1;
        int right = high + 1;
        while (true) {

            // move left to the right until value >= pivot
            // which means the value at left must be swapped
            do {
                ++left;
            } while (a[left] < pivot);
     
            // move right to the left until value <= pivot
            // which means the value at right must be swapped
            do {
                --right;
            } while (a[right] > pivot);
     
            // when crossed over, value from [low, right) are all < pivot
            // and values from [right, high]
            if (left >= right) {
                return right;
            }
     
            // swap values at left & right since a[left] >= pivot and a[right] is <= pivot
            std::swap(a[left], a[right]);
            ++counter;
        }
    });
    std::cout << "Hoare: " << counter << '\n';

    // Hoare Partition Try with while https://bit.ly/3mYWHsZ
    counter = 0;
    testHoarePartition([&counter](std::vector<int>& a, int left, int right)->int {

        int pivot = a[std::floor((left + right) / 2)];
        while (left <= right) {

            // move left to the right until value >= pivot
            // which means the value at left must be swapped
            while (a[left] < pivot)
                ++left;

            // move right to the left until value <= pivot
            // which means the value at right must be swapped
            while (a[right] > pivot)
                --right;

            // when crossed over, value from [low, right) are all < pivot
            // and values from [right, high]
            if (left <= right) {
                // swap values at left & right since a[left] >= pivot and a[right] is <= pivot
                std::swap(a[left], a[right]);
                ++counter;
                ++left;
                --right;
            }
        }

        // Note: the implementation is off-by-one from our quicksort for Hoare
        return left - 1;
    });
    std::cout << "Hoare: " << counter << '\n';

    // Hoare Partition Wikipedia Algorithm While Adjusted
    counter = 0;
    testHoarePartition([&counter](std::vector<int>& a, int left, int right)->int {

        int pivot = a[std::floor((left + right) / 2)];
        while (true) {

            // move left to the right until value >= pivot
            // which means the value at left must be swapped
            while (a[left] < pivot)
                ++left;
     
            // move right to the left until value <= pivot
            // which means the value at right must be swapped
            while (a[right] > pivot)
                --right;

            // when crossed over, value from [low, left] are all < pivot
            // and values from (j, high]
            if (left >= right) {
                return right;
            }
     
            // swap values at i & j since a[i] >= pivot and a[j] is <= pivot
            std::swap(a[left], a[right]);
            ++counter;
            ++left;
            --right;
        }
    });
    std::cout << "Hoare: " << counter << '\n';

    // Hoare Partition Wikipedia Algorithm test in while condition
    counter = 0;
    testHoarePartition([&counter](std::vector<int>& a, int low, int high)->int {

        int pivot = a[std::floor((low + high) / 2)];
        int left = low - 1;
        int right = high + 1;

        // move left to the right until value >= pivot
        // which means the value at left must be swapped
        do {
            ++left;
        } while (a[left] < pivot);
 
        // move right to the left until value <= pivot
        // which means the value at right must be swapped
        do {
            --right;
        } while (a[right] > pivot);
     
        // when crossed over, value from [low, right) are all < pivot
        // and values from [right, high]
        while (left < right) {
     
            // swap values at left & right since a[left] >= pivot and a[right] is <= pivot
            std::swap(a[left], a[right]);
            ++counter;

            // move left to the right until value >= pivot
            // which means the value at left must be swapped
            do {
                ++left;
            } while (a[left] < pivot);
     
            // move right to the left until value <= pivot
            // which means the value at right must be swapped
            do {
                --right;
            } while (a[right] > pivot);
        }

        return right;
    });
    std::cout << "Hoare: " << counter << '\n';

    // Hoare Partition Wikipedia Algorithm
    counter = 0;
    testHoarePartition([&counter](std::vector<int>& a, int low, int high)->int {

        int pivot = a[std::floor((low + high) / 2)];
        int left = low - 1;
        int right = high + 1;
        while (true) {

            // move left to the right until value >= pivot
            // which means the value at left must be swapped
            ++left;
            while (a[left] < pivot)
                ++left;

            // move right to the left until value <= pivot
            // which means the value at right must be swapped
            --right;
            while (a[right] > pivot)
                --right;

            // when crossed over, value from [low, right) are all < pivot
            // and values from [right, high]
            if (left >= right) {
                return right;
            }

            // swap values at left & right since a[left] >= pivot and a[right] is <= pivot
            std::swap(a[left], a[right]);
            ++counter;
        }

        return right;
    });
    std::cout << "Hoare: " << counter << '\n';

    return 0;
}
