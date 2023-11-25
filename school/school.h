#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//����ѧ����Ϣ
typedef struct _Student
{
	int stuNum;
	char name[20];
	int home;
}Student;

//�����Ϣ
typedef struct _Node
{
	Student student;
	struct _Node* next;
}Node;

//����ȫ�ֱ���
extern int permission;//�������ÿһ�εķ���Ȩ�ޣ�ѧ��Ϊ1���̹�Ϊ0��

//������
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
