#include"YchStudent.h"

using namespace std;

void YchStudent::Add(shared_ptr<ChenTeacher> teacher)
{
    list_teacher_.push_back(teacher);
}

void YchStudent::TeacherNum()
{
    for (const auto& student : list_teacher_) {
        cout << "Teacher Name: " << student->name << endl;
    }
    cout << "There are " << list_teacher_.size() << " Teachers in the list.\n";
}

void YchStudent::Update(const string& message_from_teacher)
{
    
    message_from_teacher_ = message_from_teacher;
    PrintInfo();
    
}

void YchStudent::Earse(shared_ptr<ChenTeacher> teacher)
{
    list_teacher_.remove(teacher);
}

void YchStudent::HomeWork(string homework)
{
    homework_message = homework;
    HomeWorkToTeacher();

}

void YchStudent::HomeWorkToTeacher()
{
    TeacherNum();
    for (auto iterator = list_teacher_.begin(); iterator != list_teacher_.end();) {
        if ((*iterator) != nullptr) {
            (*iterator)->TakeHomeWork(homework_message);
        }
        ++iterator;
    }
}


void YchStudent::PrintInfo()
{
 
    cout << "Student \"" << this->number_ << "\": ÊÕµ½ÁË --> " << this->message_from_teacher_ << "\n";
    
}


//struct CounterBase
//{
//    std::atomic<int> sharedCount{0}, weakCount{ 0 };
//};
//template<class T>
//struct Shared_ptr
//{
//public:
//
//    Shared_ptr(T* ptr) :ptr(ptr), counter(new CounterBase){}
//        T& operator*()
//    {
//        return *ptr;
//    }
//    T* operator->()
//    {
//        return ptr;
//    }
//
//    T* Get()const
//    {
//        return ptr;
//    }
//private:
//    T* ptr = nullptr;
//    CounterBase* counter;
//};
//
//void fun()
//{
//    Shared_ptr<int> ptr1 = new int;
//    int data = *ptr1;
//    Shared_ptr<YchStudent> ptr2 = new YchStudent(nullptr);
//    ptr2->PrintInfo();
//
//}