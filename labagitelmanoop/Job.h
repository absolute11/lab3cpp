// Job.h 
#pragma once 
#include <iostream> 
#include "MyString.h"
#include <cstring> 
#include "MyDate.h"

class Job {
private:
    MyString name;
    MyString position;
    int age;
    double salary;
    MyDate hireDate;

public:

    Job* copy();
    Job(const Job& other);
    Job();
    ~Job();
    int input();
    void output();
    static int CMP(Job& job, Job& job1);
    static void bubblesort(Job** Jobs, int n);
    Job* copy() const;   
    bool equal(const Job& other) const;
};
typedef Job* T;