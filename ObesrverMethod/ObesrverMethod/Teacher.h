#pragma once
#include <iostream>
#include <list>
#include <string>
#include"Teacher.h"
#include"Student.h"
using namespace std;


class Teacher {
public:
    virtual ~Teacher() {};
    virtual void Attach(shared_ptr<Student>student) = 0;
    virtual void Detach(shared_ptr<Student>student) = 0;
    virtual void Notify() = 0;
   
    string name;
};

