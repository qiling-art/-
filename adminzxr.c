#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int BookType[6] = { 30, 30, 30, 30, 30, 30 };//各类书可以借阅的时间
int UserType[3] = { 20, 25, 30 };//不同读者可以借阅的图书数量

typedef struct Book {
    char name[100];//书名
    char writer[100];//作者名
    char f_letter;//拼音首字母
    int type;//书的种类，0 科普类 1 教育类 2 小说类 3 传记类 4 历史类 5 诗歌类
    long long Isbn;//书的ISBN码
    long long p_date;//出版日期
    int flag;//判断这本书有没有被借出
    struct Book* next;
}Book;

typedef struct Record {
    Book book;//借阅的书的所有信息
    long long date;//借阅的时间
    struct Record* next;
}Record;

typedef struct User {
    char name[100];//读者名字
    int type;//读者类型 0 本科生 1 研究生 2 博士生
    char f_letter;//读者名字拼音首字母
    long long password;//读者的密码
    long long account;//读者的账号
    int num;//已借阅的书的数量
    Record* record;//用链表来存储借阅了哪些书
    struct User* next;
}User;

typedef struct Administrator {
    char name[100];//管理员名字
    char f_letter;//管理员名字拼音首字母
    long long password;//管理员密码
    long long account;//管理员账号
    struct Administrator* next;
}Admin;

Book* broot;
Record* reroot;
User* uroot;
Admin* aroot;
Book* head_book = NULL;
Book* head_user = NULL;
void AdjustBookType(Book* head, char name[], int new_type);//设置和调整图书所属分类
void AdjustBookBTime(int old_type, int new_time);//设置和调整每类图书的借阅时间
void AdjustUserType(User* head, char name[], int new_type);//设置和调整读者所属分类
void AdjustUserBTime(int old_type, int new_time);//设置和调整每类读者的借阅时间
void AddBook(Book* head, char name[], char writer[], char f_letter, int type, long long Isbn, long long p_date);//增加图书信息
void AddUser(User* head, char name[], int type, char f_letter, long long password, long long account);//增加读者信息
void DeleteBook(Book* head, char name[]);//删除图书信息
void DeleteUser(User* head, char name[]);//删除读者信息
void ModifyBook(Book* head, char name[], int new_type);//修改图书信息
void ModifyUser(User* head, long long account, int new_type);//修改读者信息
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
        AddBook(&head_book, book_name, book_writer, f_letter, book_type, book_isbn, book_p_date);
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
        ModifyBook(&head_book, book_name_mod, new_book_type);
        printf("图书信息修改成功！\n");
        break;
    case 3:
        char book_name_del[100];
        printf("请输入要删除的图书名称：");
        scanf("%s", book_name_del);
        DeleteBook(&head_book, book_name_del);
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
        AddUser(&head_user, user_name, user_type, f_letter_user, user_password, user_account);
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
        DeleteUser(&head_user, user_name_del);
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
        AdjustBookType(head_book, book_name_adjust, new_book_type_adjust);
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
        AdjustUserType(head_user, user_name_adjust, new_user_type_adjust);
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
void AdjustBookType(Book* head, char name[], int new_type)//设置和调整图书所属分类
{
    Book* current = head;// 定义一个指针current，初始化为链表头节点
    while (current != NULL)// 遍历链表
    {
        if (strcmp(current->name, name) == 0)// 如果找到名称匹配的图书
        {
            current->type = new_type;// 将图书的分类调整为新的分类
            printf("%s的类型已调整为%d", name, new_type);
            return;// 退出函数
        }
        current = current->next; // 移动到下一个节点
    }
    printf("不存在图书%s", name);

}
void AdjustBookBTime(int old_type, int new_time)//设置和调整每类图书的借阅时间
{
    if (old_type >= 0 && old_type < 6)
    {
        BookType[old_type] = new_time; // 调整对应类型的图书借阅时间
        printf("%d的借阅时长已调整为%d天", old_type, new_time);
        return; // 退出函数
    }
    else {
        printf("不存在此类型图书\n");
    }
}
void AdjustUserType(User* head, char name[], int new_type)//设置和调整读者所属分类
{
    User* current = head;// 定义一个指针current，初始化为链表头节点
    while (current != NULL)// 遍历链表
    {
        if (strcmp(current->name, name) == 0) {
            current->type = new_type;// 将读者的分类调整为新的分类
            printf("%s的类型已调整为%d", name, new_type);
            return; // 退出函数
        }
        current = current->next;// 移动到下一个节点
    }
    printf("不存在读者%s", name);

}
void AdjustUserBTime(int old_type, int new_time)//设置和调整每类读者的借阅时间
{
    if (old_type >= 0 && old_type < 3) {
        BookType[old_type] = new_time;// 调整对应类型的读者借阅时间
        printf("%d的借阅时长已调整为%d天", old_type, new_time);
        return;// 退出函数
    }
    else {
        printf("不存在此类型读者\n");
    }

}
void AddBook(Book* head, char name[], char writer[], char f_letter, int type, long long Isbn, long long p_date)//增加图书信息
{
    Book* newBook = (Book*)malloc(sizeof(Book));// 动态分配一个新的Book节点
    strcpy(newBook->name, name);// 复制name字段
    strcpy(newBook->writer, writer);// 复制writer字段
    newBook->f_letter = f_letter;// 设置其他字段
    newBook->type = type;
    newBook->Isbn = Isbn;
    newBook->p_date = p_date;
    newBook->next = head;// 将新节点插入到链表头部
    head = newBook;
}
void DeleteBook(Book* head, char name[])//删除图书信息
{
    Book* current = head;
    Book* prev = NULL;
    while (current != NULL && strcmp(current->name, name) != 0)// 遍历链表
    {
        prev = current;
        current = current->next;

    }
    if (current == NULL)// 如果未找到图书
    {
        printf("查无此书\n");
        return;
    }
    if (prev == NULL)// 如果要删除的节点是头节点
    {
        head = current->next;
    }
    else // 否则，将前一个节点的next指向当前节点的下一个节点
    {
        prev->next = current->next;
    }
}
void AddUser(User* head, char name[], int type, char f_letter, long long password, long long account)//增加读者信息
{
    User* newUser = (User*)malloc(sizeof(User));// 动态分配一个新的User节点
    strcpy(newUser->name, name);// 复制name字段
    newUser->type = type;// 设置其他字段
    newUser->f_letter = f_letter;
    newUser->password = password;
    newUser->account = account;
    newUser->num = 0;
    newUser->next = head;// 将新节点插入到链表头部
    head = newUser;
}
void DeleteUser(User* head, char name[])//删除读者信息
{
    User* current = head; // 当前遍历的用户指针
    User* prev = NULL;  // 前一个用户指针
    while (current != NULL && strcmp(current->name, name) != 0) // 遍历链表
    {
        prev = current;// 更新前一个用户指针
        current = current->next;// 移动到下一个用户
    }
    if (current == NULL) // 如果当前用户为无
    {
        printf("查无此人\n");
        return;
    }
    if (prev == NULL) // 如果要删除的是头节点
    {
        head = current->next; // 更新头节点为下一个用户
    }
    else {
        prev->next = current->next; // 否则将指向当前用户的下一个用户
    }
}
void ModifyBook(Book* head, char name[], int new_type)//修改图书信息
{
    Book* current = head; // 当前遍历的图书指针
    Book* prev = NULL;// 前一本图书指针
    while (current != NULL) // 遍历链表
    {
        if (strcmp(current->name, name) == 0) {
            current->type = new_type;
            return;
        }
        prev = current;
        current = current->next;// 移动到下一个节点
    }
}
void ModifyUser(User* head, long long account, int new_type)//修改读者信息
{
    User* current = head;// 当前遍历的用户指针
    User* prev = NULL; // 前一个用户指针
    while (current != NULL)// 遍历链表
    {
        if (current->account == account) {
            current->type = new_type;
            return;
        }
        prev = current;
        current = current->next;// 移动到下一个节点
    }
}
int main()
{
    srand(time(0));
    while (1)
    {
        BaseInforMain();
    }
    system("pause");
    return 0;
}