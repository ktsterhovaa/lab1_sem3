
#ifndef LR1_DYNAMICARRAY_H
#define LR1_DYNAMICARRAY_H
using namespace std;
#include <cstring>
#include <iostream>
#include "UnqPtr.h"


template<class T>
class DynamicArray {
private:
    int size;
    int capacity;
    UnqPtr<T[]> data;
    UnqPtr<bool[]> defined;  // Задан ли элемент массива?



public:
    //Создание объекта
    DynamicArray(): data(nullptr), size(0), capacity(0){};

    DynamicArray(int size):size(size), capacity(size * 2)
    {
        if (size < 0) throw std::invalid_argument("invalid argument");
        if(size>0)
            data = UnqPtr<T[]>(new T[size]);
    }
    DynamicArray( const UnqPtr<T[]>& items, int count):DynamicArray(count)
    {
        if(items==nullptr)  throw std::invalid_argument("invalid argument");

        for (int i = 0; i < count; i++)
        {
            data[i] = items[i];
        }

    }
    DynamicArray(const T* ptr , int count):DynamicArray(count)
    {
        if(ptr==nullptr) throw std::invalid_argument("invalid argument");
        for(int i=0;i<count;i++)
        {
            data[i]=ptr[i];
        }
    }

    //Декомпозиция
    T get(int index) const {
        if (index < 0 || index >= size) throw std::invalid_argument("invalid argument");
        return data[index];
    }

    int getSize() const {
        return size;
    }

    //Операции


    T operator[](size_t index) const {  // Получение значения
        return get(index);
    }
    T& operator[](int index) { // Оператор индексирования для изменения значения
        if (index < 0 || index >= size) throw std::out_of_range("Invalid index");
        return data[index];
    }
    void set(const T& value,int index)
    {
        if(size<=index || index<0) throw std::out_of_range("Invalid index");
        data[index]=value;
    }
    T& operator[](size_t index) {  // Чтобы делать присваивание так: dynamicArray[1] = 1233;
        if(size<=index || index<0) throw std::out_of_range("Invalid index");
        defined[index] = true;
        return data[index];
    }

    void resize(int newSize) {
        if (newSize < 0) throw std::invalid_argument("invalid argument");
        UnqPtr<T[]> newData(new T[newSize]);


        for (int i = 0; i < std::min(size, newSize); ++i) {
            newData[i] = data[i];
        }

        data = std::move(newData);
        size = newSize;
        capacity = newSize;
    }

    void define_resize(int newSize) {
        for (int i = newSize - 1; i >= 1; i--) {
            defined[i] = defined[i - 1];
        }
    }

    void define_set(int index, bool value) {
        defined[index] = value;
    }
};



#endif //LR1_DYNAMICARRAY_H
