#include "school.h"
//此处为通用函数（无需权限）

//打印
void printStudent(Node* head) {
	Node* move = head->next;
	while (move != NULL) {
		printf("学号:%d 姓名:%s 宿舍号:%d\n", move->student.stuNum, move->student.name, move->student.home);
		move = move->next;
	}
	//暂停程序
	system("pause");
	printf("这是打印的最后一行\n");
	//清空控制台
	system("cls");
	printf("请按“回车键”呼出菜单...\n");
}
//计数
void countStudent(Node* head) {
	int count = 0;
	Node* move = head->next;
	while (move != NULL) {
		count++;
		move = move->next;
	}
	printf("入住学生的总人数为:%d\n", count);
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
	printf("请按“回车键”呼出菜单...\n");
}
//查询
void findStudent(Node* head) {
	printf("请输入要查找的学生的学号: ");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL) {
		if (stuNum == move->student.stuNum) {
			printf("学号: %d 姓名:%s 宿舍号:%d\n", move->student.stuNum, move->student.name, move->student.home);
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			printf("请按“回车键”呼出菜单...\n");
			return;
		}
		move = move->next;
	}
	printf("暂无学生信息，请手动添加\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
	printf("请按“回车键”呼出菜单...\n");
}



