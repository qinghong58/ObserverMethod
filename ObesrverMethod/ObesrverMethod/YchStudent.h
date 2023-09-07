#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Student.h"
#include"ChenTeacher.h"
using namespace std;

class YchStudent : public Student {

private:

    list<shared_ptr<ChenTeacher>> list_teacher_ = {
        //学生列表初始化的数据
            //JiaTeacher = make_shared<ChenTeacher>(),
            //YanTeacher = make_shared<ChenTeacher>(),
            //WangTeacher = make_shared<ChenTeacher>()
    };

    string message_from_teacher_;
    string homework_message;
    ChenTeacher* chent_teacher_;
    static int static_number_;


public:

    string number_;

    virtual ~YchStudent() {
    }
    shared_ptr<YchStudent>thisPtr = std::make_shared<YchStudent>(*this);
    //shared_ptr<YchStudent>thisPtr;
    YchStudent(ChenTeacher* subject) : chent_teacher_(subject) {
       // shared_ptr<YchStudent>this = make_shared<YchStudent>();


        //chent_teacher_->Attach(thisPtr);

        //std::cout << "Hi, I'm the Observer \"" << ++YchStudent::static_number_ << "\".\n";

        //this->number_ = YchStudent::static_number_;

        //thisPtr = std::make_shared<YchStudent>(*this);
    }

    YchStudent() = default;

    void TeacherNum();

    void Update(const string& message_from_teacher) override;

    void Add(shared_ptr<ChenTeacher>teacher);

    void Earse(shared_ptr<ChenTeacher>teacher);

    void HomeWork(string homework);

    void HomeWorkToTeacher();

    void PrintInfo();


};

