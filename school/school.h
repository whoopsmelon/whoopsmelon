#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//定义学生信息
typedef struct _Student
{
	int stuNum;
	char name[20];
	int home;
}Student;

//结点信息
typedef struct _Node
{
	Student student;
	struct _Node* next;
}Node;

//定义全局变量
extern int permission;//用于审查每一次的访问权限，学生为1，教工为0；

//函数集
void welcome_1();
void welcome_2();
void inputStudent(Node* head);
void printStudent(Node* head);
void countStudent(Node* head);
void findStudent(Node* head);
void saveStudent(Node* head);
void loadStudent(Node* head);
void modifyStudent(Node* head);
void deleteStudent(Node* head);

#endif // SCHOOL_H_INCLUDED
