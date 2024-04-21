#include"allfunctions.h"
#include<stdio.h>
#include<stdlib.h>

void BaseInforMain()//������Ϣ����
{
    int choice;
    printf("ͼ��ݹ���Աϵͳ��\n");
    printf("1.����ͼ����Ϣ\n");
    printf("2.�޸�ͼ����Ϣ\n");
    printf("3.ɾ��ͼ����Ϣ\n");
    printf("4.���Ӷ�����Ϣ\n");
    printf("5.�޸Ķ�����Ϣ\n");
    printf("6.ɾ��������Ϣ\n");
    printf("0.�˳�����Աϵͳ\n");
    printf("��ѡ�������");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char book_name[100], book_writer[100];
        char f_letter;
        int book_type;
        long long book_isbn, book_p_date;
        printf("������ͼ�����ƣ�");
        scanf("%s", book_name);
        printf("������ͼ�����ߣ�");
        scanf("%s", book_writer);
        printf("������ͼ������ĸ��");
        scanf(" %c", &f_letter);
        printf("������ͼ�����ͣ�");
        scanf("%d", &book_type);
        printf("������ͼ��ISBN��");
        scanf("%lld", &book_isbn);
        printf("������ͼ��������ڣ�");
        scanf("%lld", &book_p_date);
        AddBook(&broot, book_name, book_writer, f_letter, book_type, book_isbn, book_p_date);
        printf("ͼ����Ϣ��ӳɹ���\n");
        break;
    case 2:
        char book_name_mod[100], new_book_name[100], new_book_writer[100];
        char new_f_letter;
        int new_book_type;
        printf("������Ҫ�޸ĵ�ͼ�����ƣ�");
        scanf("%s", book_name_mod);
        printf("�������µ�ͼ�����ͣ�");
        scanf("%d", &new_book_type);
        ModifyBook(&broot, book_name_mod, new_book_type);
        printf("ͼ����Ϣ�޸ĳɹ���\n");
        break;
    case 3:
        char book_name_del[100];
        printf("������Ҫɾ����ͼ�����ƣ�");
        scanf("%s", book_name_del);
        DeleteBook(&broot, book_name_del);
        printf("ͼ����Ϣɾ���ɹ���\n");
        break;
    case 4:
        char user_name[100], f_letter_user;
        int user_type;
        long long user_password, user_account;
        int num_books;
        printf("���������������");
        scanf("%s", user_name);
        printf("������������ͣ�");
        scanf("%d", &user_type);
        printf("�������������ĸ��");
        scanf(" %c", &f_letter_user);
        printf("������������룺");
        scanf("%lld", &user_password);
        long long t = rand() % 10000000000;
        user_account = t;
        AddUser(&uroot, user_name, user_type, f_letter_user, user_password, user_account);
        printf("������Ϣ��ӳɹ���\n");
        break;
    case 5:
        long long account;
        int new_user_type;
        printf("�����뽫Ҫ�޸ĵ��û��˻�:");
        scanf("%lld", &account);
        printf("�������޸ĺ������:");
        scanf("%d", &new_user_type);
        ModifyUser(uroot, account, new_user_type);
        printf("������Ϣ�޸ĳɹ���\n");
        break;
    case 6:
        char user_name_del[100];
        printf("������Ҫɾ���Ķ���������");
        scanf("%s", user_name_del);
        DeleteUser(&uroot, user_name_del);
        printf("������Ϣɾ���ɹ���\n");
        break;
    case 0:
        return 0;
    default:
        printf("������ѡ��\n");

    }

}

void BookTypeMain() //ͼ��������
{
    int choice;
    printf("ͼ���ͼ�����ϵͳ��\n");
    printf("1.���ú͵���ͼ����������\n");
    printf("2.���ú͵���ÿ��ͼ��Ľ���ʱ��\n");
    printf("0.�˳�ͼ�����ϵͳ");
    printf("��ѡ�������");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char book_name_adjust[100];
        int new_book_type_adjust;
        printf("������Ҫ�������͵�ͼ�����ƣ�");
        scanf("%s", book_name_adjust);
        printf("�������µ�ͼ�����ͣ�");
        scanf("%d", &new_book_type_adjust);
        AdjustBookType(broot, book_name_adjust, new_book_type_adjust);
        printf("ͼ�����͵����ɹ���\n");
        break;
    case 2:
        int old_book_type_adjust, new_book_time_adjust;
        printf("������Ҫ��������ʱ���ͼ�鵱ǰ���ͣ�");
        scanf("%d", &old_book_type_adjust);
        printf("�������µ�ͼ�����ʱ�䣺");
        scanf("%d", &new_book_time_adjust);
        AdjustBookBTime(old_book_type_adjust, new_book_time_adjust);
        printf("ͼ�����ʱ������ɹ���\n");
        break;
    case 0:
        return 0;
    default:
        printf("������ѡ��\n");

    }
}

void UserTypeMain() //���߷������
{
    int choice;
    printf("ͼ��ݶ��߷���ϵͳ��\n");
    printf("1.���ú͵���������������\n");
    printf("2.���ú͵���ÿ����ߵĽ���ʱ��\n");
    printf("0.�˳����߷���ϵͳ");
    printf("��ѡ�������");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char user_name_adjust[100];
        int new_user_type_adjust;
        printf("������Ҫ�������͵Ķ���������");
        scanf("%s", user_name_adjust);
        printf("�������µĶ������ͣ�");
        scanf("%d", &new_user_type_adjust);
        AdjustUserType(uroot, user_name_adjust, new_user_type_adjust);
        printf("�������͵����ɹ���\n");
        break;
    case 2:
        int old_user_type_adjust, new_user_time_adjust;
        printf("������Ҫ��������ʱ��Ķ��ߵ�ǰ���ͣ�");
        scanf("%d", &old_user_type_adjust);
        printf("�������µĶ��߽���ʱ�䣺");
        scanf("%d", &new_user_time_adjust);
        AdjustUserBTime(old_user_type_adjust, new_user_time_adjust);
        printf("���߽���ʱ������ɹ���\n");
        break;
    case 0:
        return 0;
    default:
        printf("������ѡ��\n");

    }

}

void Window();//�û�������ʾ
void Function();//ϵͳѡ��
void Window1();//ͼ�����Աϵͳ����
void Window2();//ѧ��ϵͳ����

void Function1();//ͼ�����Ա��¼
void Function2();//ѧ����¼
void Adland();

void Adxinjian();
void Adxiugai();
void Stland();
void Stxinjian();
void Stxiugai();

int Admatch(long long account, long long password);
void BaseInforMain()//������Ϣ����
{
    int choice;
    printf("ͼ��ݹ���Աϵͳ��\n");
    printf("1.����ͼ����Ϣ\n");
    printf("2.�޸�ͼ����Ϣ\n");
    printf("3.ɾ��ͼ����Ϣ\n");
    printf("4.���Ӷ�����Ϣ\n");
    printf("5.�޸Ķ�����Ϣ\n");
    printf("6.ɾ��������Ϣ\n");
    printf("0.�˳�����Աϵͳ\n");
    printf("��ѡ�������");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char book_name[100], book_writer[100];
        char f_letter;
        int book_type;
        long long book_isbn, book_p_date;
        printf("������ͼ�����ƣ�");
        scanf("%s", book_name);
        printf("������ͼ�����ߣ�");
        scanf("%s", book_writer);
        printf("������ͼ������ĸ��");
        scanf(" %c", &f_letter);
        printf("������ͼ�����ͣ�");
        scanf("%d", &book_type);
        printf("������ͼ��ISBN��");
        scanf("%lld", &book_isbn);
        printf("������ͼ��������ڣ�");
        scanf("%lld", &book_p_date);
        AddBook(&broot, book_name, book_writer, f_letter, book_type, book_isbn, book_p_date);
        printf("ͼ����Ϣ��ӳɹ���\n");
        break;
    case 2:
        char book_name_mod[100], new_book_name[100], new_book_writer[100];
        char new_f_letter;
        int new_book_type;
        printf("������Ҫ�޸ĵ�ͼ�����ƣ�");
        scanf("%s", book_name_mod);
        printf("�������µ�ͼ�����ͣ�");
        scanf("%d", &new_book_type);
        ModifyBook(&broot, book_name_mod, new_book_type);
        printf("ͼ����Ϣ�޸ĳɹ���\n");
        break;
    case 3:
        char book_name_del[100];
        printf("������Ҫɾ����ͼ�����ƣ�");
        scanf("%s", book_name_del);
        DeleteBook(&broot, book_name_del);
        printf("ͼ����Ϣɾ���ɹ���\n");
        break;
    case 4:
        char user_name[100], f_letter_user;
        int user_type;
        long long user_password, user_account;
        int num_books;
        printf("���������������");
        scanf("%s", user_name);
        printf("������������ͣ�");
        scanf("%d", &user_type);
        printf("�������������ĸ��");
        scanf(" %c", &f_letter_user);
        printf("������������룺");
        scanf("%lld", &user_password);
        long long t = rand() % 10000000000;
        user_account = t;
        AddUser(&uroot, user_name, user_type, f_letter_user, user_password, user_account);
        printf("������Ϣ��ӳɹ���\n");
        break;
    case 5:
        long long account;
        int new_user_type;
        printf("�����뽫Ҫ�޸ĵ��û��˻�:");
        scanf("%lld", &account);
        printf("�������޸ĺ������:");
        scanf("%d", &new_user_type);
        ModifyUser(uroot, account, new_user_type);
        printf("������Ϣ�޸ĳɹ���\n");
        break;
    case 6:
        char user_name_del[100];
        printf("������Ҫɾ���Ķ���������");
        scanf("%s", user_name_del);
        DeleteUser(&uroot, user_name_del);
        printf("������Ϣɾ���ɹ���\n");
        break;
    case 0:
        return 0;
    default:
        printf("������ѡ��\n");

    }

}

int Admatch(long long m, long long a)//ƥ�����ݿ��е��˺�����
{
    FILE* fp;
    int n = 0, i = 0;
    long long zhanghao;
    long long  password;

    if ((fp = fopen("Adland.txt", "r")) == NULL)
    {
        system("cls");
        printf("\n ��δ�����û�!���½��˻�");
        _getch();
        system("cls");
        Function1();
    }
    else
    {
        for (; !feof(fp);)
        {
            fscanf(fp, "%lld %lld", &zhanghao, &password);
            if (m == zhanghao)
            {
                if (a == password)
                    return 1;
                else
                {
                    return -1;
                }
            }
        }
        fclose(fp); // �ر��ļ�
        return 0;
    }
}

void Window()
{
    printf("\n\n\t    ��ӭʹ��ͼ�����ϵͳ\n\n");
    printf("**********************************************");
    printf("\n\n\t\t��ѡ��ϵͳ\n\n");
    printf("\n\n\t\t1.ͼ�����Աϵͳ\n\n");
    printf("\n\n\t\t2.ѧ��ϵͳ\n\n");
    printf("\n\n\t\t3.�˳�ϵͳ\n\n");
    printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
    printf("**********************************************\n");
    return;
}
void Window1()
{
    printf("\n\n\t    ��ӭʹ��ͼ�����Ա��¼ϵͳ\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.��¼ϵͳ\n\n");
    printf("\n\n\t\t2.�����˺�\n\n");
    printf("\n\n\t\t3.�޸�����\n\n");
    printf("\n\n\t\t4.�˳�ϵͳ\n\n");
    printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
    printf("**********************************************\n");
    return;
}
void Window2()
{
    printf("\n\n\t    ��ӭʹ��ѧ��ϵͳ\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.��¼ϵͳ\n\n");
    printf("\n\n\t\t2.�����˺�\n\n");
    printf("\n\n\t\t3.�޸�����\n\n");
    printf("\n\n\t\t4.�˳�ϵͳ\n\n");
    printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
    printf("**********************************************\n");
    return;
}
void Function1()
{
    char choose;
    system("cls");
    Window1();
    scanf(" %c", &choose);
    switch (choose)//���ܺ���
    {
    case'1':
        Adland();
        break;
    case'2':
        Adxinjian();
        break;
    case'3':
        Adxiugai();
        break;
    case'4':
        system("cls");
        _getch();
        exit(0);
        system("cls");
        break;
    }

}
void Function2()
{
    char choose;
    system("cls");
    Window2();
    scanf(" %c", &choose);
    switch (choose)//���ܺ���
    {
    case'1':
        Stland();
        break;
    case'2':
        Stxinjian();
        break;
    case'3':
        Stxiugai();
        break;
    case'4':
        system("cls");
        _getch();
        exit(0);
        system("cls");
        break;
    }
}
void Function()//�û����ܺ���
{
    char choose;
    Window();
    scanf(" %c", &choose);
    switch (choose)//���ܺ���
    {
    case'1':
        Function1();
        break;
    case'2':
        Function2();
        break;

    case'3':
        system("cls");
        _getch();
        exit(0);
        system("cls");
        break;
    }

}
void Adland()
{

    long long  zhanghao;
    long long password;
    int i = 2, j, k, n;
    char hit = 0;
    system("cls");
    do
    {
        printf("\n�������˺�:\n");
        scanf("%lld", &zhanghao);
        printf("ȷ�������밲�س������������밴ECS");
        hit = _getch();//��ͣ����i���պ������һ��ָ��
        for (; hit != 13 && hit != 27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
        {
            hit = _getch();
        }
    } while (hit == 27);
    printf("\n����������:\n");
    scanf("%lld", &password);
    i = Admatch(zhanghao, password);
    if (i == 1)
    {
        printf("��½�ɹ�!�����������");
        _getch();
        BaseInforMain();

    }
    else
    {
        if (i == -1)
        {
            printf("�������!");
            _getch();
            Adland();
        }
        if (i == 0)
            printf("�����ڴ��û�");
        _getch();
        system("cls");

    }
}
void Adxinjian()
{

}
void Adxiugai()
{

}
void Stland()
{

}
void Stxinjian()
{

}
void Stxiugai()
{ 

}

int main()
{
    system("color 4E");
    Function();
    system("pause");
    return 0;
}