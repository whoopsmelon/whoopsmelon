#include "school.h"
//�˴�Ϊͨ�ú���������Ȩ�ޣ�

//��ӡ
void printStudent(Node* head) {
	Node* move = head->next;
	while (move != NULL) {
		printf("ѧ��:%d ����:%s �����:%d\n", move->student.stuNum, move->student.name, move->student.home);
		move = move->next;
	}
	//��ͣ����
	system("pause");
	printf("���Ǵ�ӡ�����һ��\n");
	//��տ���̨
	system("cls");
	printf("�밴���س����������˵�...\n");
}
//����
void countStudent(Node* head) {
	int count = 0;
	Node* move = head->next;
	while (move != NULL) {
		count++;
		move = move->next;
	}
	printf("��סѧ����������Ϊ:%d\n", count);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
	printf("�밴���س����������˵�...\n");
}
//��ѯ
void findStudent(Node* head) {
	printf("������Ҫ���ҵ�ѧ����ѧ��: ");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL) {
		if (stuNum == move->student.stuNum) {
			printf("ѧ��: %d ����:%s �����:%d\n", move->student.stuNum, move->student.name, move->student.home);
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			printf("�밴���س����������˵�...\n");
			return;
		}
		move = move->next;
	}
	printf("����ѧ����Ϣ�����ֶ����\n");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
	printf("�밴���س����������˵�...\n");
}



