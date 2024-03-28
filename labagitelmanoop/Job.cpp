// Job.cpp
#include "Job.h"
using namespace std;
Job::Job() : age(0), salary(0.0) {
}
Job::~Job() {
    
}
int Job::input() {
    char boof[256];    cout << "Введите имя и фамилию: ";
    name.input();
    
    cout << "Введите позицию сотрудника: ";
    position.input();
    cout << "Введите возраст сотрудника: ";
    cin >> age;
    cout << "Введите зарплату: ";
    cin >> salary;
    cout << "Введите дату найма (день месяц год): ";
    hireDate.input();
    cin.ignore();
    return 1;
}

void Job::output() {
    cout << "Имя и фамилия: ";
    name.output(); 
    cout << "Позиция: ";
    position.output(); 
    cout << "Возраст: " << age << endl;
    cout << "Зарплата: " << salary << endl;
    cout << "-------------------------" << endl;
    cout << "Дата найма: ";
    hireDate.output(); // Вывод даты
    cout << "-------------------------" << endl;
}
int Job::CMP(Job& job, Job& job1) {
    int nameCompare = job.name.cmp(job1.name);
    int positionCompare = job.position.cmp(job1.position);
    if (nameCompare == 0) {
        if (positionCompare == 0) {
            if (job.age == job1.age) {
                if (job.salary == job1.salary) {
                    return 0;
                }
                else {
                    return (job.salary < job1.salary) ? -1 : 1;
                }
            }
            else {
                return (job.age < job1.age) ? -1 : 1;
            }
        }
        else {
            return positionCompare;
        }
    }
    else {
        return nameCompare;
    }
}
void Job::bubblesort(Job** Jobs, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (CMP(*Jobs[j], *Jobs[j + 1]) > 0) {
                Job* temp = Jobs[j];
                Jobs[j] = Jobs[j + 1];
                Jobs[j + 1] = temp;
            }
        }
    }
}
Job::Job(const Job& other)
    : name(other.name), position(other.position), age(other.age), salary(other.salary), hireDate(other.hireDate) {
    // Теперь hireDate тоже копируется
}
Job* Job::copy() {
    Job* newJob = new Job();
    newJob->age = this->age;
    newJob->salary = this->salary;
    newJob->name.assign(this->name);
    newJob->position.assign(this->position);
    newJob->hireDate.assign(this->hireDate); // Добавьте это
    return newJob;
}
bool Job::equal(const Job& other) const {
    return (name.equal(other.name) && position.equal(other.position) && age == other.age && salary == other.salary && hireDate.equal(other.hireDate));
    // Теперь также сравнивается hireDate
}