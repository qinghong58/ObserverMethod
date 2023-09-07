1.项目名称
校园管理系统
2.项目介绍
项目本身是基于观察者模式实现。主要实现了两种人物的选择，包括老师和学生。老师可以添加自己的学生，学生也可以添加自己的任课教师。然后老师可以下发作业，学生可以上交作业。

3.项目架构说明
ChenTeacher.h：继承抽象类的具体类。实现老师的一些功能。包括下发作业，添加学生，删除学生，查看自己的学生列表等功能。
Student.h：学生抽象基类。实现了一些自己的方法和和自己的信息。
Teacher.h：老师的抽象基类。实现了一些自己的方法和和自己的信息。
YchStudent.h：继承学生抽象类。实现学生的一些功能。包括上交作业，添加老师，删除老师，查看自己的自己的老师列表等功能。
ChenTeacher.cpp：主要就是ChenTeacher类的具体方法实现。
YchStudent.cpp：主要就是YchStudent类的具体方法实现。
MainMenu就是项目的整体运行流程的一个实现。
4.使用说明
首先进入项目，根据自己所选的角色进行界面的跳转。老师就是负责发作业，添加到自己的班里学生，然后收到学生拿到作业的消息就行。学生就是保证上交的作业，能够让自己列表的老师收到。我们进入角色界面首先需要添加角色到各自的列表，不然可能没有返回结果。
5.过程总结
对我来说，这个项目的建造过程是相对短暂的，因为上个适配器的代码让我又痛苦又快乐，痛苦的是错误的发生，快乐的是学到了知识。然后这个代码有之前技术的铺垫，导致进展可能相对快了一些。然后就是这个代码还是用了很多条件语句。这点之后会继续弥补。然后也学到了很多知识。


PS：一些注释代码没有删除，是我想以后能继续看到现在自己的思路，希望老师别介意。