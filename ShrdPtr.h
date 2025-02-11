#ifndef LR1_SHRDPTR_H
#define LR1_SHRDPTR_H
#pragma once
#include <iostream>
#include <utility>

template <typename T>
class ShrdPtr{
private:
    T* ptr;
    size_t *referenceCount;
    void release(){
        if (referenceCount && --referenceCount == 0) {
            delete ptr;
            delete referenceCount;
        }
    }
public:
    // Конструктор по умолчанию
    ShrdPtr() : ptr(nullptr), referenceCount(nullptr) {}

    // Конструктор с указателем
    explicit ShrdPtr(T* p) : ptr(p), referenceCount(new size_t(1)) {}

    // Конструктор копирования
    ShrdPtr(const ShrdPtr & other) : ptr(other.ptr), referenceCount(other.referenceCount) {
        if (referenceCount) {
            ++(*referenceCount);
        }
    }

    // Конструктор перемещения
    ShrdPtr(ShrdPtr && other) noexcept : ptr(other.ptr), referenceCount(other.referenceCount) {
        other.ptr = nullptr;
        other.referenceCount = nullptr;
    }

    //Деструктор
    ~ShrdPtr() {
        release();
    }

    // Оператор присваивания (копирования)
    ShrdPtr & operator = (const ShrdPtr & other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            referenceCount = other.referenceCount;
            if (referenceCount) {
                ++(*referenceCount);
            }
        }
        return *this;
    }

    // Оператор присваивания (перемещения)
    ShrdPtr & operator = (ShrdPtr && other) noexcept {
        if (this != other){
            release();
            ptr = other.ptr;
            referenceCount = other.referenceCount;
            other.ptr = nullptr;
            other.referenceCount = nullptr;
        }
        return *this;
    }
    // Доступ к объекту
    T& operator * () const {
        return *ptr;
    }

    T* operator -> () const {
        return ptr;
    }

    // получить текущее количество ссылок
    size_t useCount() const {
        return referenceCount ? *referenceCount : 0;
    }

    // Проверить, является ли указатель ненулевым
    bool null() const {
        return ptr == nullptr;
    }

    // Передать указатель на управляемый объект
    T* get() const {
        return ptr;
    }

    void reset(T* p = nullptr) {
        release();
        ptr = p;
        referenceCount = (p) ? new size_t(1) : nullptr; //новый счетчик ссылок, если p не nullptr
    }


};
template<typename T>
class ShrdPtr <T[]> {
private:
    T* ptr;
    size_t *referenceCount;
    void release() {
        if (referenceCount && --referenceCount == 0) {
            delete[] ptr;
            delete referenceCount;
        }
    }
public:
    // Конструктор
    explicit ShrdPtr(T *p = nullptr) : ptr(p), referenceCount(new size_t(1)) {}
    // Конструктор копирования
    ShrdPtr(const ShrdPtr &other)
            : ptr(other.ptr), referenceCount(other.referenceCount) {
        if (referenceCount) {
            ++(*referenceCount);
        }
    }
    // Конструктор перемещения
    ShrdPtr(ShrdPtr && other) noexcept : ptr(other.ptr), referenceCount(other.referenceCount) {
        other.ptr = nullptr;
        other.referenceCount = nullptr;
    }
    // Оператор присваивания (перемещения)
    ShrdPtr & operator = (ShrdPtr && other) noexcept {
        if (this != other){
            release();
            ptr = other.ptr;
            referenceCount = other.referenceCount;
            other.ptr = nullptr;
            other.referenceCount = nullptr;
        }
        return *this;
    }

    // Деструктор
    ~ShrdPtr() {
        release();
    }
    // Доступ к объекту
    T& operator * () const {
        return *ptr;
    }

    T* operator -> () const {
        return ptr;
    }
    // Проверить, является ли указатель ненулевым
    bool null() const {
        return ptr == nullptr;
    }

    // Передать указатель на управляемый объект
    T* get() const {
        return ptr;
    }

    void reset(T* p = nullptr) {
        release();
        ptr = p;
        referenceCount = (p) ? new size_t(1) : nullptr; //новый счетчик ссылок, если p не nullptr
    }
};



#endif //LR1_SHRDPTR_H
