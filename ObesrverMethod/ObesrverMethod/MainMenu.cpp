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
//���ѧ��
void AddStudent(ChenTeacher& chen_teacher)
{

    int flag = 0;
    string studentname;

    cout << "1.���ѧ��1" << endl;
    cout << "2.���ѧ��2" << endl;
    cout << "3.���ѧ��3" << endl;
    cout << "4.�˳����" << endl;
    cin >> flag;
    if (flag==1)
    {
        cout << "����ѧ��1������" << endl;
        cin >> studentname;
        student1->name = studentname;
        student1->number_ = studentname;
        chen_teacher.Attach(student1);
        AddStudent(chen_teacher);
        //CheckTeacherNum();
    }
    else if (flag==2)
    {
        cout << "����ѧ��3������" << endl;
        cin >> studentname;
        student2->name = studentname;
        student2->number_ = studentname;
        chen_teacher.Attach(student2);
        AddStudent(chen_teacher);
    }
    else if (flag ==3)
    {
        cout << "����ѧ��2������" << endl;
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

    cout << "1.ɾ��ѧ��1" << endl;
    cout << "2.ɾ��ѧ��2" << endl;
    cout << "3.ɾ��ѧ��3" << endl;
    cout << "4.�˳�ɾ��" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "ɾ��ѧ��1������" << endl;
        cin >> studentname;
        student1->name = studentname;
        
        chen_teacher.Detach(student1);
        EarseStudent(chen_teacher);
    }
    else if (flag == 2)
    {
        cout << "ɾ��ѧ��2������" << endl;
        cin >> studentname;
        student2->name = studentname;
        chen_teacher.Detach(student2);
        EarseStudent(chen_teacher);
    }
    else if (flag == 3)
    {
        cout << "ɾ��ѧ��3������" << endl;
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

//ɾ����ʦ
void eraseTeacher(YchStudent& ych_student)
{
    int flag = 0;
    string teachername;

    cout << "1.ɾ����ʦ1" << endl;
    cout << "2.ɾ����ʦ2" << endl;
    cout << "3.ɾ����ʦ3" << endl;
    cout << "4.�˳�ɾ��" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "ɾ����ʦ1������" << endl;
        cin >> teachername;
        teacher1->name = teachername;
        ych_student.Earse(teacher1);
        eraseTeacher(ych_student);
    }
    else if (flag == 2)
    {
        cout << "ɾ����ʦ2������" << endl;
        cin >> teachername;
        teacher2->name = teachername;
        ych_student.Earse(teacher2);
        eraseTeacher(ych_student);
    }
    else if (flag == 3)
    {
        cout << "ɾ����ʦ3������" << endl;
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
    cout << "1.�����ʦ1" << endl;
    cout << "2.�����ʦ2" << endl;
    cout << "3.�����ʦ3" << endl;
    cout << "4.�˳����" << endl;
    cin >> flag;
    if (flag == 1)
    {
        cout << "�����ʦ1������" << endl;
        cin >> teachername;
        teacher1->name = teachername;
        teacher1->teacher_name = teachername;
        ych_student.Add(teacher1);
        addTeacher(ych_student);

    }
    else if (flag == 2)
    {
        cout << "�����ʦ2������" << endl;
        cin >> teachername;
        teacher2->name = teachername;
        teacher2->teacher_name = teachername;
        ych_student.Add(teacher2);
        addTeacher(ych_student);
        //AddStudent(chen_teacher);
    }
    else if (flag == 3)
    {
        cout << "�����ʦ3������" << endl;
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
    cout << "��������ҵ��" << endl;
    string homework;
    cin >> homework;
    chen_teacher.CreateMessage(homework);
}

//�Ͻ���ҵ
void TurnHomeWork(YchStudent& ych_student)
{
    cout << "��������ҵ��" << endl;
    string home_work;
    cin >> home_work;
    ych_student.HomeWork(home_work);
}

void StudentFunction()
{
    system("cls");
    int flag = 0;
    cout << "------------------------------" << endl;
    cout << "1.�����ʦ" << endl;
    cout << "2.�鿴��ʦ" << endl;
    cout << "3.ɾ����ʦ" << endl;
    cout << "4.�Ͻ���ҵ" << endl;
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
    cout << "1.���ѧ��" << endl;
    cout << "2.�鿴ѧ��" << endl;
    cout << "3.ɾ��ѧ��" << endl;
    cout << "4.������ҵ" << endl;
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
    cout << "��ѡ������Ҫ���ݵĽ�ɫ��" << endl;
    cout << "------------------------------" << endl;
    cout << "1.ѧ��" << endl;
    cout << "2.��ʦ" << endl;
    cout << "------------------------------" << endl;

    cout << "��ѡ������Ҫ���ݵĽ�ɫ����ţ�" << endl;
    cin >> flag;
    PersonChooseFunction(flag);

}
int main()
{
    PersonChoose();

    return 0;
}