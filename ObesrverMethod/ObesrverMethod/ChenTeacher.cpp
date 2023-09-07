#include"ChenTeacher.h"
#include<list>
using namespace std;

void ChenTeacher::Attach(shared_ptr<Student>student)
{   
    list_student_.push_back(student);
}

void ChenTeacher::Detach(shared_ptr<Student>student)
{
    list_student_.remove(student); 
}

void ChenTeacher::Notify()
{
    
    HowManyStudent();
    for (auto iterator = list_student_.begin(); iterator != list_student_.end();) {
        if ((*iterator) != nullptr) {
            (*iterator)->Update(message_);
        }
        ++iterator;
    }
    
}

void ChenTeacher::CreateMessage(string message)
{
    this->message_ = message;
    Notify();
    
}

void ChenTeacher::TakeHomeWork(const string& student_homework)
{
    student_homework_message = student_homework;
    PrintStudentHomeWork();
}

void ChenTeacher::HowManyStudent()
{
    for (const auto& student : list_student_) {
        cout << "Student Name: " << student->name << endl;
    }
    cout << "There are " << list_student_.size() << " Studeents in the list.\n";
    
}

void ChenTeacher::SomeBusinessLogic()
{
    
    this->message_ = "change message";
    Notify();
    cout << "I'm about to do some thing important\n";
    
}

void ChenTeacher::PrintStudentHomeWork()
{
    cout << "Teacher \"" << this->teacher_name << "\": 收到了该学生的 --> " << this->student_homework_message << "\n";
}
