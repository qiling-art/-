#include"allfunctions.h"

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

int main() {

}