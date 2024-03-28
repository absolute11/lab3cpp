// Table.cpp 
#include "Table.h" 
#include <iostream> 
using namespace std;
Table::Table(int employes1) :v(employes1) {
    employes = employes1;
    current=begin();
}
void Table::clear() {
    v.resize(0);
}
Table::~Table() {
    /*clear();
    delete[] m;*/
}
T* Table::begin() {
    return v.begin();
}
T* Table::end() {
    return current;
}
int Table::lenght() {
    return current - begin();
}
int Table::getsize() {
    return v.getsize();
}
T* Table::insert(const T& item) {
    if (lenght() >= v.getsize()) {
        v.resize(2 * lenght());
        current = begin() + lenght();
    }
    *current++ = item->copy();
    return current;
}
T* Table::erase(T* pos) {
    T* i;
    delete* pos; 
    for (i = pos; i < current - 1; i++) {
        *i = *(i + 1);
        
    }
    current--;
    return pos;
    
}
int Table::remove(const T& item) {
    T* i = begin();
    T* j = begin();
    int n = 0;
    while (i < current) {
        if (!(*i)->equal(*item)) {
            *j++ = *i++; // Копируем элемент, если он не равен удаляемому
        }
        else {
            delete* i++; // Освобождаем память для удаляемого элемента
            n++;
        }
    }
    current = j; // Обновляем указатель current
    return n;
}
int Table::find(const T& item) {
    for (T* i = begin(); i < end(); i++) {
        if ((*i)->equal(*item)) {
            return i - begin(); // Возвращаем позицию относительно начала вектора
        }
    }
    return -1;
}
int Table::replace(const T& OLD, const T& NEW) {
    int count = 0;
    for (T* i = begin(); i < end(); i++) {
        if ((*i)->equal(*OLD)) {
            delete(*i);
            (*i) = NEW->copy();
            count++;
        }



    }
    return count;
}
int Table::input(T buf) {
    int count = 0;
    for (count; count < getsize() && buf->input(); count++) {
        insert(buf->copy());
        cin.clear();

    }
    return count;


}
void Table::output() {
    for (T* i = begin(); i < end(); i++) {
        (*i)->output();

    }
}
void Table::bubblesort() {
    Job::bubblesort(begin(), lenght());  // Вызываем метод сортировки пузырьком из класса Job 
}