#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student {
public:
    virtual ~Student() {};
    virtual void Update(const std::string& message_from_teacher) = 0;

    string name;
};


