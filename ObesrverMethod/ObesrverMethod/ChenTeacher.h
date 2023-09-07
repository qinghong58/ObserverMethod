#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Teacher.h"
#include"Student.h"

using namespace std;

class ChenTeacher : public Teacher {

private:

    list<shared_ptr<Student>> list_student_ ;
    string message_;

    string student_homework_message;

public:
    string teacher_name;
    virtual ~ChenTeacher() {
    }

    //void InsertStudent(const std::shared_ptr<Student>& student) {
    //    list_student_.push_back(student);
    //}

    //void RemoveStudent(const std::shared_ptr<Student>& student) {
    //    list_student_.remove(student);
    //}

    //const list<std::shared_ptr<Student>> &GetStudentList() const {
    //    return list_student_;
    //}

    void Attach(shared_ptr<Student>student);

    void Detach(shared_ptr<Student>student);

    void Notify() override;

    void CreateMessage(string message = "Empty");

    void HowManyStudent(); 

    void TakeHomeWork(const string& student_homework);

    void SomeBusinessLogic();

    void PrintStudentHomeWork();


};

