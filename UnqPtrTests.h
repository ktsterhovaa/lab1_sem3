//
// Created by Katya on 26.10.2024.
//

#ifndef LR1_UNQPTRTESTS_H
#define LR1_UNQPTRTESTS_H
#pragma once
#include <cassert>
#include "UnqPtr.h"

// Тест на создание и разыменование указателя
void test_create_and_dereference()
{
    UnqPtr<int> p1(new int(10));
    assert(p1.get() != nullptr);
    assert(*p1 == 10);
    std::cout << "test_create_and_dereference passed.\n";
}

// Тест на перемещение указателя
void test_move_ptr()
{
    UnqPtr<int> p1(new int(20));
    assert(p1.get() != nullptr);

    UnqPtr<int> p2 = std::move(p1);
    assert(p1.get() == nullptr);
    assert(p2.get() != nullptr);
    assert(*p2 == 20);
    std::cout << "test_move_ptr passed.\n";
}


// Тест на работу с массивами
void test_array_support()
{
    auto pArray = UnqPtr<int[]>(new int[5]);
    for (int i = 0; i < 5; ++i) {
        pArray[i] = i;
    }
    for (int i = 0; i < 5; ++i) {
        assert(pArray[i] == i);
    }
    std::cout << "test_array_support passed.\n";
}

// Тест на метод release
void test_release()
{
    UnqPtr<int> p1(new int(50));
    int* raw_ptr = p1.release();

    assert(p1.get() == nullptr);
    assert(raw_ptr != nullptr);

    delete raw_ptr;
    std::cout << "test_release passed.\n";
}

// Тест на метод reset
void test_reset()
{
    UnqPtr<int> p1(new int(60));
    assert(p1.get() != nullptr);

    p1.reset();
    assert(p1.get() == nullptr);
    std::cout << "test_reset passed.\n";
}

// Тест на проверку освобождения ресурса (метод IsFree)
void test_is_free()
{
    UnqPtr<int> p1(new int(70));
    assert(!p1.null());
    p1.reset();
    assert(p1.null());
    std::cout << "test_is_free passed.\n";
}
#endif //LR1_UNQPTRTESTS_H
