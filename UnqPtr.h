
#ifndef LR1_UNQPTR_H
#define LR1_UNQPTR_H
#pragma once
#include <utility>
#include <cstddef>

template <typename T>
class UnqPtr{
private:
    T* ptr; //указатель на объект
public:
    // Конструктор
    explicit UnqPtr(T* p = nullptr): ptr(p){}
    // Деструктор
    ~UnqPtr() {
        delete ptr;
    }
    // Запрет копирования
    UnqPtr(const UnqPtr&) = delete;
    // Конструктор перемещения
    UnqPtr(UnqPtr && other) noexcept : ptr(other.ptr){
        other.ptr = nullptr;
    }
    // Оператор присваивания
    UnqPtr & operator = (UnqPtr && other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    // доступ к объекту
    T & operator *() const {
        return *ptr;
    }
    T* operator ->() const {
        return ptr;
    }
    T* get() const {
        return ptr;
    }
    // метод для освобождения управления
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
    // метод для сброса указателя
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
    // метод для обмена указателями
    void swap(UnqPtr & other) noexcept {
        std::swap(ptr, other.ptr);
    }
    bool null() const {
        return ptr == nullptr;
    }
};
template<typename T>
class UnqPtr<T[]> {
private:
    T *ptr;

public:
    // Конструктор
    explicit UnqPtr(T *p = nullptr) : ptr(p) {}

    // Деструктор
    ~UnqPtr() {
        delete[] ptr;
    }

    // Запрет копирования
    UnqPtr(const UnqPtr&) = delete;
    UnqPtr& operator=(const UnqPtr&) = delete;

    // Конструктор перемещения
    UnqPtr(UnqPtr &&other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Оператор присваивания перемещением
    UnqPtr& operator=(UnqPtr &&other) noexcept {
        if (this != &other) {
            delete[] ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Доступ к элементам
    T& operator[](std::size_t index) {
        return ptr[index];
    }

    const T& operator[](std::size_t index) const {
        return ptr[index];
    }

    // Получить сырой указатель
    T* get() const {
        return ptr;
    }

    // Метод для освобождения управления
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Метод для сброса указателя
    void reset(T *p = nullptr) {
        delete[] ptr;
        ptr = p;
    }

    // Метод для обмена указателями
    void swap(UnqPtr &other) noexcept {
        std::swap(ptr, other.ptr);
    }

    // Проверить, является ли указатель ненулевым
    bool null() const {
        return ptr == nullptr;
    }

};




#endif //LR1_UNQPTR_H
