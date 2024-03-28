// Table.h 
#pragma once 
#include "Job.h" 
#include "vec.h"
#include <iostream> 
using namespace std;

class Table {
private:
    vec v;
    int employes;
    T* current;

public:
    Table(int employes);
    ~Table();
    T* begin();
    T* end();
    int lenght();
    int getsize();
    T* insert(const T& item);
    T* erase(T* pos);
    void clear();
    int remove(const T& item);
    int find(const T& item);
    int replace(const T& OLD, const T& NEW);
    void bubblesort();
    int input(T buf);
    void output();
};