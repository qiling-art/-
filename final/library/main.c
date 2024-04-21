#include"allfunctions.h"

void BaseInforMain()//基本信息管理
{
    int choice;
    printf("图书馆管理员系统：\n");
    printf("1.增加图书信息\n");
    printf("2.修改图书信息\n");
    printf("3.删除图书信息\n");
    printf("4.增加读者信息\n");
    printf("5.修改读者信息\n");
    printf("6.删除读者信息\n");
    printf("0.退出管理员系统\n");
    printf("请选择操作：");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char book_name[100], book_writer[100];
        char f_letter;
        int book_type;
        long long book_isbn, book_p_date;
        printf("请输入图书名称：");
        scanf("%s", book_name);
        printf("请输入图书作者：");
        scanf("%s", book_writer);
        printf("请输入图书首字母：");
        scanf(" %c", &f_letter);
        printf("请输入图书类型：");
        scanf("%d", &book_type);
        printf("请输入图书ISBN：");
        scanf("%lld", &book_isbn);
        printf("请输入图书出版日期：");
        scanf("%lld", &book_p_date);
        AddBook(&broot, book_name, book_writer, f_letter, book_type, book_isbn, book_p_date);
        printf("图书信息添加成功！\n");
        break;
    case 2:
        char book_name_mod[100], new_book_name[100], new_book_writer[100];
        char new_f_letter;
        int new_book_type;
        printf("请输入要修改的图书名称：");
        scanf("%s", book_name_mod);
        printf("请输入新的图书类型：");
        scanf("%d", &new_book_type);
        ModifyBook(&broot, book_name_mod, new_book_type);
        printf("图书信息修改成功！\n");
        break;
    case 3:
        char book_name_del[100];
        printf("请输入要删除的图书名称：");
        scanf("%s", book_name_del);
        DeleteBook(&broot, book_name_del);
        printf("图书信息删除成功！\n");
        break;
    case 4:
        char user_name[100], f_letter_user;
        int user_type;
        long long user_password, user_account;
        int num_books;
        printf("请输入读者姓名：");
        scanf("%s", user_name);
        printf("请输入读者类型：");
        scanf("%d", &user_type);
        printf("请输入读者首字母：");
        scanf(" %c", &f_letter_user);
        printf("请输入读者密码：");
        scanf("%lld", &user_password);
        long long t = rand() % 10000000000;
        user_account = t;
        AddUser(&uroot, user_name, user_type, f_letter_user, user_password, user_account);
        printf("读者信息添加成功！\n");
        break;
    case 5:
        long long account;
        int new_user_type;
        printf("请输入将要修改的用户账户:");
        scanf("%lld", &account);
        printf("请输入修改后的类型:");
        scanf("%d", &new_user_type);
        ModifyUser(uroot, account, new_user_type);
        printf("读者信息修改成功！\n");
        break;
    case 6:
        char user_name_del[100];
        printf("请输入要删除的读者姓名：");
        scanf("%s", user_name_del);
        DeleteUser(&uroot, user_name_del);
        printf("读者信息删除成功！\n");
        break;
    case 0:
        return 0;
    default:
        printf("请重新选择。\n");

    }

}

void BookTypeMain() //图书分类管理
{
    int choice;
    printf("图书馆图书分类系统：\n");
    printf("1.设置和调整图书所属分类\n");
    printf("2.设置和调整每类图书的借阅时间\n");
    printf("0.退出图书分类系统");
    printf("请选择操作：");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char book_name_adjust[100];
        int new_book_type_adjust;
        printf("请输入要调整类型的图书名称：");
        scanf("%s", book_name_adjust);
        printf("请输入新的图书类型：");
        scanf("%d", &new_book_type_adjust);
        AdjustBookType(broot, book_name_adjust, new_book_type_adjust);
        printf("图书类型调整成功！\n");
        break;
    case 2:
        int old_book_type_adjust, new_book_time_adjust;
        printf("请输入要调整借阅时间的图书当前类型：");
        scanf("%d", &old_book_type_adjust);
        printf("请输入新的图书借阅时间：");
        scanf("%d", &new_book_time_adjust);
        AdjustBookBTime(old_book_type_adjust, new_book_time_adjust);
        printf("图书借阅时间调整成功！\n");
        break;
    case 0:
        return 0;
    default:
        printf("请重新选择。\n");

    }
}

void UserTypeMain() //读者分类管理
{
    int choice;
    printf("图书馆读者分类系统：\n");
    printf("1.设置和调整读者所属分类\n");
    printf("2.设置和调整每类读者的借阅时间\n");
    printf("0.退出读者分类系统");
    printf("请选择操作：");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char user_name_adjust[100];
        int new_user_type_adjust;
        printf("请输入要调整类型的读者姓名：");
        scanf("%s", user_name_adjust);
        printf("请输入新的读者类型：");
        scanf("%d", &new_user_type_adjust);
        AdjustUserType(uroot, user_name_adjust, new_user_type_adjust);
        printf("读者类型调整成功！\n");
        break;
    case 2:
        int old_user_type_adjust, new_user_time_adjust;
        printf("请输入要调整借阅时间的读者当前类型：");
        scanf("%d", &old_user_type_adjust);
        printf("请输入新的读者借阅时间：");
        scanf("%d", &new_user_time_adjust);
        AdjustUserBTime(old_user_type_adjust, new_user_time_adjust);
        printf("读者借阅时间调整成功！\n");
        break;
    case 0:
        return 0;
    default:
        printf("请重新选择。\n");

    }

}

int main() {

}