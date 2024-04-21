#include"allfunctions.h"
#include<stdio.h>
#include<stdlib.h>

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

void Window();//用户界面显示
void Function();//系统选择
void Window1();//图书管理员系统界面
void Window2();//学生系统界面

void Function1();//图书管理员登录
void Function2();//学生登录
void Adland();

void Adxinjian();
void Adxiugai();
void Stland();
void Stxinjian();
void Stxiugai();

int Admatch(long long account, long long password);
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

int Admatch(long long m, long long a)//匹配数据库中的账号密码
{
    FILE* fp;
    int n = 0, i = 0;
    long long zhanghao;
    long long  password;

    if ((fp = fopen("Adland.txt", "r")) == NULL)
    {
        system("cls");
        printf("\n 还未存在用户!请新建账户");
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
        fclose(fp); // 关闭文件
        return 0;
    }
}

void Window()
{
    printf("\n\n\t    欢迎使用图书管理系统\n\n");
    printf("**********************************************");
    printf("\n\n\t\t请选择系统\n\n");
    printf("\n\n\t\t1.图书管理员系统\n\n");
    printf("\n\n\t\t2.学生系统\n\n");
    printf("\n\n\t\t3.退出系统\n\n");
    printf("\n\n\t    请按键选择，回车确定\n");
    printf("**********************************************\n");
    return;
}
void Window1()
{
    printf("\n\n\t    欢迎使用图书管理员登录系统\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.登录系统\n\n");
    printf("\n\n\t\t2.创建账号\n\n");
    printf("\n\n\t\t3.修改密码\n\n");
    printf("\n\n\t\t4.退出系统\n\n");
    printf("\n\n\t    请按键选择，回车确定\n");
    printf("**********************************************\n");
    return;
}
void Window2()
{
    printf("\n\n\t    欢迎使用学生系统\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.登录系统\n\n");
    printf("\n\n\t\t2.创建账号\n\n");
    printf("\n\n\t\t3.修改密码\n\n");
    printf("\n\n\t\t4.退出系统\n\n");
    printf("\n\n\t    请按键选择，回车确定\n");
    printf("**********************************************\n");
    return;
}
void Function1()
{
    char choose;
    system("cls");
    Window1();
    scanf(" %c", &choose);
    switch (choose)//功能函数
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
    switch (choose)//功能函数
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
void Function()//用户功能函数
{
    char choose;
    Window();
    scanf(" %c", &choose);
    switch (choose)//功能函数
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
        printf("\n请输入账号:\n");
        scanf("%lld", &zhanghao);
        printf("确认输入请安回车，重新输入请按ECS");
        hit = _getch();//暂停程序当i接收后继续下一条指令
        for (; hit != 13 && hit != 27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
        {
            hit = _getch();
        }
    } while (hit == 27);
    printf("\n请输入密码:\n");
    scanf("%lld", &password);
    i = Admatch(zhanghao, password);
    if (i == 1)
    {
        printf("登陆成功!按任意键继续");
        _getch();
        BaseInforMain();

    }
    else
    {
        if (i == -1)
        {
            printf("密码错误!");
            _getch();
            Adland();
        }
        if (i == 0)
            printf("不存在此用户");
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