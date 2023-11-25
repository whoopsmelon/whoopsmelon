#include "school.h"

//此处为受限的函数（仅教工可访问）

//输入
void inputStudent(Node* head) {

	Node* headers = malloc(sizeof(Node));
	headers->next = NULL;
	printf("请输入学生的学号，姓名，宿舍号 ");
	scanf("%d%s%d", &headers->student.stuNum, headers->student.name, &headers->student.home);
	Node* move = head;
	while (move->next != NULL) {
		move = move->next;
	}
	//将学生插入到尾部
	move->next = headers;

	saveStudent(head);
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
	printf("写入成功，请按“回车键”呼出菜单\n");
}
//修改
void modifyStudent(Node* head) {
	printf("请输入要修改的学生的学号: ");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL) {
		if (move->student.stuNum == stuNum) {
			printf("请输入学生姓名，宿舍号\n");
			scanf("%s%d", move->student.name, &move->student.home);
			saveStudent(head);
			printf("修改成功\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
            printf("请按“回车键”呼出菜单...\n");
			return;
		}
		move = move->next;
	}
	printf("未找到学生信息，请检查学号是否输入正确！\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
	printf("请按“回车键”呼出菜单...\n");
}
//删除
void deleteStudent(Node* head) {
	printf("请输入要删除的学生学号 ");
	int stuNum = 0;
	scanf("%d", &stuNum);
	Node* move = head;
	while (move->next != NULL) {

		if (move->next->student.stuNum == stuNum) {
			Node* dele = move->next;
			move->next = move->next->next;
			free(dele);
			dele = NULL;
			saveStudent(head);
			printf("删除成功\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
            printf("删除成功，请按“回车键”呼出菜单...\n");
			return;
		}

		move = move->next;
	}
	printf("未找到学生信息，请检查学号是否输入正确！\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
	printf("请按“回车键”呼出菜单...\n");
}

//写入
void saveStudent(Node* head) {
	FILE* file = fopen("./student.info", "w");
	Node* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->student, sizeof(Student), 1, file) != 1) {
			printf("写入失败！\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}

//载入
void loadStudent(Node* head) {
    FILE* file = fopen("./student.info", "r");
    if (!file) {
        printf("本机没有搜索到学生文件,请检查根目录！\n");
        return;
    }
    Node* headers = malloc(sizeof(Node));
    headers->next = NULL;
    Node* move = head;
    while (fread(&headers->student, sizeof(Student), 1, file) == 1) {
        move->next = headers;
        move = headers;
        headers = malloc(sizeof(Student));
        headers->next = NULL;
    }
    free(headers);
    fclose(file);
    printf("文件读取成功，程序初始化成功！\n");
}
