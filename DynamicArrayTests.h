
#ifndef LR1_DYNAMICARRAYTESTS_H
#define LR1_DYNAMICARRAYTESTS_H
#pragma once
#include <cassert>
#include <iostream>
#include "DynamicArray.h"

// Тесты
void test_empty_array() {
    DynamicArray<int> arr;
    assert(arr.getSize() == 0);
    std::cout << "test_empty_array passed.\n";
}

void test_array_with_size() {
    DynamicArray<int> arr(5);
    assert(arr.getSize() == 5);
    std::cout << "test_array_with_size passed.\n";
}

void test_array_with_elements() {
    int initial_elements[] = {1, 2, 3, 4, 5};
    DynamicArray<int> arr(initial_elements, 5);
    assert(arr.getSize() == 5);

    for (int i = 0; i < 5; i++) {

        assert(arr.get(i) == initial_elements[i]);
    }
    std::cout << "test_array_with_elements passed.\n";
}

void test_get_method() {
    int initial_elements[] = {10, 20, 30};
    DynamicArray<int> arr(initial_elements, 3);
    assert(arr.get(0) == 10);
    assert(arr.get(1) == 20);
    assert(arr.get(2) == 30);
    std::cout << "test_get_method passed.\n";
}

void test_set_method() {
    DynamicArray<int> arr(3);
    arr.set(100, 0);
    arr.set(200, 1);
    arr.set(300, 2);
    assert(arr.get(0) == 100);
    assert(arr.get(1) == 200);
    assert(arr.get(2) == 300);
    std::cout << "test_set_method passed.\n";
}

void test_index_operator() {
    DynamicArray<int> arr(4);
    arr.set(10, 0);
    arr.set(20, 1);
    arr.set(30, 2);
    arr.set(40, 3);
    assert(arr[0] == 10);
    assert(arr[1] == 20);
    assert(arr[2] == 30);
    assert(arr[3] == 40);
    arr[1] = 100;
    assert(arr[1] == 100);
    std::cout << "test_index_operator passed.\n";
}

void test_resize() {
    DynamicArray<int> arr(3);
    arr.set(1, 0);
    arr.set(2, 1);
    arr.set(3, 2);

    arr.resize(5);
    assert(arr.getSize() == 5);

    arr.resize(2);
    assert(arr.getSize() == 2);

    try {
        arr.get(4);
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "test_resize passed.\n";
    }
}

void test_exceptions() {
    try {
        DynamicArray<int> arr(-5);
        assert(false);
    } catch (const std::invalid_argument&) {
        std::cout << "Caught invalid_argument for negative size.\n";
    }

    DynamicArray<int> arr(3);
    try {
        arr.get(10);
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "Caught out_of_range for invalid index.\n";
    }

    try {
        arr.set(100, 10);
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "Caught out_of_range for invalid set index.\n";
    }

    std::cout << "test_exceptions passed.\n";
}


#endif //LR1_DYNAMICARRAYTESTS_H
