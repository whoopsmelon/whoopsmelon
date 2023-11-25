#include "school.h"
void read_1()//读取总菜单的输入
{
    char i = _getch();

    switch (i)
    {
        case '1':
            welcome_2();
            read_2();
            break;
        case '2':
            login();
            welcome_1();
            read_1();
            break;
    }
}

int permission;//全局变量

void read_2()//学生信息
{
    //创建头结点
    Node* head = malloc(sizeof(Node));
    head->next = NULL;
    loadStudent(head);
    while(1){
        char i = _getch();

        switch (i)
        {
            case '1':
                if(permission == 1)
                {
                    printf("您没有权限访问！\n");
                    welcome_2();
                    break;
                }
                else
                {
                    inputStudent(head);
                    break;
                }
            case '2':
                printStudent(head);
                break;
            case '3':
                countStudent(head);
                break;
            case '4':
                findStudent(head);
                break;
            case '5':
                if(permission == 1)
                {
                    printf("您没有权限访问！\n");
                    welcome_2();
                    break;
                }
                else
                {
                    modifyStudent(head);
                    break;
                }
            case '6':
                if(permission == 1)
                {
                    printf("您没有权限访问！\n");
                    welcome_2();
                    break;
                }
                else
                {
                    deleteStudent(head);
                    break;
                }
            case '7':
                system("cls");
                printf("即将退出程序\n");
                welcome_1();
                read_1();
                break;
            default:
                welcome_2();
                printf("请选择您要办理的项目\n");
                break;
        }
    }
}
