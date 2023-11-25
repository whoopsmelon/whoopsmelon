#include "school.h"

//�˴�Ϊ���޵ĺ��������̹��ɷ��ʣ�

//����
void inputStudent(Node* head) {

	Node* headers = malloc(sizeof(Node));
	headers->next = NULL;
	printf("������ѧ����ѧ�ţ������������ ");
	scanf("%d%s%d", &headers->student.stuNum, headers->student.name, &headers->student.home);
	Node* move = head;
	while (move->next != NULL) {
		move = move->next;
	}
	//��ѧ�����뵽β��
	move->next = headers;

	saveStudent(head);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
	printf("д��ɹ����밴���س����������˵�\n");
}
//�޸�
void modifyStudent(Node* head) {
	printf("������Ҫ�޸ĵ�ѧ����ѧ��: ");
	int stuNum;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL) {
		if (move->student.stuNum == stuNum) {
			printf("������ѧ�������������\n");
			scanf("%s%d", move->student.name, &move->student.home);
			saveStudent(head);
			printf("�޸ĳɹ�\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
            printf("�밴���س����������˵�...\n");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�ѧ����Ϣ������ѧ���Ƿ�������ȷ��\n");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
	printf("�밴���س����������˵�...\n");
}
//ɾ��
void deleteStudent(Node* head) {
	printf("������Ҫɾ����ѧ��ѧ�� ");
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
			printf("ɾ���ɹ�\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
            printf("ɾ���ɹ����밴���س����������˵�...\n");
			return;
		}

		move = move->next;
	}
	printf("δ�ҵ�ѧ����Ϣ������ѧ���Ƿ�������ȷ��\n");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
	printf("�밴���س����������˵�...\n");
}

//д��
void saveStudent(Node* head) {
	FILE* file = fopen("./student.info", "w");
	Node* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->student, sizeof(Student), 1, file) != 1) {
			printf("д��ʧ�ܣ�\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}

//����
void loadStudent(Node* head) {
    FILE* file = fopen("./student.info", "r");
    if (!file) {
        printf("����û��������ѧ���ļ�,�����Ŀ¼��\n");
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
    printf("�ļ���ȡ�ɹ��������ʼ���ɹ���\n");
}
