#include<iostream>
#include<string>
#include<memory>
#include<map>
#include<functional>
#include<Windows.h>
#include"Student.h"
#include"Teacher.h"
#include"YchStudent.h"
#include"ChenTeacher.h"


using namespace std;

int YchStudent::static_number_ = 0;
map<int, function<void()>>PersonChooseMap;

shared_ptr<YchStudent>student1 = make_shared<YchStudent>();
shared_ptr<YchStudent>student2 = make_shared<YchStudent>();
shared_ptr<YchStudent>student3 = make_shared<YchStudent>();

shared_ptr<ChenTeacher>teacher1 = make_shared<ChenTeacher>();
shared_ptr<ChenTeacher>teacher2 = make_shared<ChenTeacher>();
shared_ptr<ChenTeacher>teacher3 = make_shared<ChenTeacher>();

ChenTeacher chen_teacher;
YchStudent ych_student;

void StudentFunction();
void TeacherFunction();
void PersonChooseFunction(int flag)
{
    PersonChooseMap[1] = StudentFunction;
    PersonChooseMap[2] = TeacherFunction;

    PersonChooseMap[flag]();
}
void CheckTeacherNum()
{
    ych_student.TeacherNum();
    Sleep(3000);
    StudentFunction();

}

void CheckStudentNum()
{
    chen_teacher.HowManyStudent();
    Sleep(3000);
    TeacherFunction();
}
//添加学生
void AddStudent(ChenTeacher& chen_teacher)
{

    int flag = 0;
    string studentname;

    cout << "1.添加学生1" << endl;
    cout << "2.添加学生2" << endl;
    cout << "3.添加学生3" << endl;
    cout << "4.退出添加" << endl;
    cin >> flag;
    if (flag==1)
    {
        cout << "输入学生1姓名：" << endl;
        cin >> studentname;
        student1->name = studentname;
        student1->number_ = studentname;
        chen_teacher.Attach(student1);
        AddStudent(chen_teacher);
        //CheckTeacherNum();
    }
    else if (flag==2)
    {
        cout << "输入学生3姓名：" << endl;
        cin >> studentname;
        student2->name = studentname;
        student2->number_ = studentname;
        chen_teacher.Attach(student2);
        AddStudent(chen_teacher);
    }
    else if (flag ==3)
    {
        cout << "输入学生2姓名：" << endl;
        cin >> studentname;
        student3->name = studentname;
        student3->number_ = studentname;
        chen_teacher.Attach(student3);
        AddStudent(chen_teacher);

    }
    else
    {

        TeacherFunction();
    }

}

void EarseStudent(ChenTeacher& chen_teacher)
{
    int flag = 0;
    string studentname;

    cout << "1.删除学生1" << endl;
    cout << "2.删除学生2" << endl;
    cout << "3.删除学生3" << endl;
    cout << "4.退出删除" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "删除学生1姓名：" << endl;
        cin >> studentname;
        student1->name = studentname;
        
        chen_teacher.Detach(student1);
        EarseStudent(chen_teacher);
    }
    else if (flag == 2)
    {
        cout << "删除学生2姓名：" << endl;
        cin >> studentname;
        student2->name = studentname;
        chen_teacher.Detach(student2);
        EarseStudent(chen_teacher);
    }
    else if (flag == 3)
    {
        cout << "删除学生3姓名：" << endl;
        cin >> studentname;
        student3->name = studentname;
        chen_teacher.Detach(student3);
        EarseStudent(chen_teacher);

    }
    else
    {
        TeacherFunction();
    }
}

//删除老师
void eraseTeacher(YchStudent& ych_student)
{
    int flag = 0;
    string teachername;

    cout << "1.删除老师1" << endl;
    cout << "2.删除老师2" << endl;
    cout << "3.删除老师3" << endl;
    cout << "4.退出删除" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "删除老师1姓名：" << endl;
        cin >> teachername;
        teacher1->name = teachername;
        ych_student.Earse(teacher1);
        eraseTeacher(ych_student);
    }
    else if (flag == 2)
    {
        cout << "删除老师2姓名：" << endl;
        cin >> teachername;
        teacher2->name = teachername;
        ych_student.Earse(teacher2);
        eraseTeacher(ych_student);
    }
    else if (flag == 3)
    {
        cout << "删除老师3姓名：" << endl;
        cin >> teachername;
        teacher3->name = teachername;
        ych_student.Earse(teacher3);
        eraseTeacher(ych_student);

    }
    else
    {
        StudentFunction();
    }
}

void addTeacher(YchStudent& ych_student)
{
    int flag = 0;
    string teachername;
    system("cls");
    cout << "1.添加老师1" << endl;
    cout << "2.添加老师2" << endl;
    cout << "3.添加老师3" << endl;
    cout << "4.退出添加" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "添加老师1姓名：" << endl;
        cin >> teachername;
        teacher1->name = teachername;
        teacher1->teacher_name = teachername;
        ych_student.Add(teacher1);
        addTeacher(ych_student);

    }
    else if (flag == 2)
    {
        cout << "添加老师2姓名：" << endl;
        cin >> teachername;
        teacher2->name = teachername;
        teacher2->teacher_name = teachername;
        ych_student.Add(teacher2);
        addTeacher(ych_student);
        //AddStudent(chen_teacher);
    }
    else if (flag == 3)
    {
        cout << "添加老师3姓名：" << endl;
        cin >> teachername;
        teacher3->name = teachername;
        teacher3->teacher_name = teachername;
        ych_student.Add(teacher3);
        addTeacher(ych_student);
        //AddStudent(chen_teacher);

    }
    else
    {
        StudentFunction();
    }
}

void AddHomeWork(ChenTeacher& chen_teacher)
{
    cout << "请输入作业：" << endl;
    string homework;
    cin >> homework;
    chen_teacher.CreateMessage(homework);
}

//上交作业
void TurnHomeWork(YchStudent& ych_student)
{
    cout << "请输入作业：" << endl;
    string home_work;
    cin >> home_work;
    ych_student.HomeWork(home_work);
}

void StudentFunction()
{
    system("cls");
    int flag = 0;
    cout << "------------------------------" << endl;
    cout << "1.添加老师" << endl;
    cout << "2.查看老师" << endl;
    cout << "3.删除老师" << endl;
    cout << "4.上交作业" << endl;
    cout << "------------------------------" << endl;

    cin >> flag;
    if (flag==1)
    {
        addTeacher(ych_student);
    }
    else if (flag==2)
    {
        CheckTeacherNum();
    }
    else if(flag==3)
    {
        eraseTeacher(ych_student);
    }
    else if (flag == 4)
    {
        TurnHomeWork(ych_student);
    }
}

void TeacherFunction()
{
    system("cls");
    int flag = 0;
    cout << "------------------------------" << endl;
    cout << "1.添加学生" << endl;
    cout << "2.查看学生" << endl;
    cout << "3.删除学生" << endl;
    cout << "4.发送作业" << endl;
    cout << "------------------------------" << endl;

    cin >> flag;
    if (flag==1)
    {
        AddStudent(chen_teacher);
    }
    else if (flag==2)
    {
        CheckStudentNum();
    }
    else if (flag == 3)
    {
        EarseStudent(chen_teacher);
    }
    else if (flag == 4)
    {
        AddHomeWork(chen_teacher);
    }

}

void PersonChoose()
{

    int flag = 0;
    cout << "请选择你想要扮演的角色！" << endl;
    cout << "------------------------------" << endl;
    cout << "1.学生" << endl;
    cout << "2.老师" << endl;
    cout << "------------------------------" << endl;

    cout << "请选择你想要扮演的角色的序号：" << endl;
    cin >> flag;
    PersonChooseFunction(flag);

}
int main()
{
    PersonChoose();

    return 0;
}