#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int BookType[6] = { 30, 30, 30, 30, 30, 30 };//各类书可以借阅的时间
int UserType[3] = { 20, 25, 30 };//不同读者可以借阅的图书数量

typedef struct Book {
    char name[100];//书名
    char writer[100];//作者名
    char f_letter;//拼音首字母
    int type;//书的种类，0 科普类 1 教育类 2 小说类 3 传记类 4 历史类 5 诗歌类
    long long Isbn;//书的ISBN码s
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

Book* broot = NULL;
Record* reroot = NULL;
User* uroot = NULL;
Admin* aroot = NULL;

Book* Create_Book(Book* node, char name[], char writer[], char f_letter, int type, long long Isbn, long long date, int flag) {
    if (node == NULL) {
        Book* p = (Book*)malloc(sizeof(Book));
        strcpy(p->name, name);
        strcpy(p->writer, writer);
        p->f_letter = f_letter;
        p->type = type;
        p->Isbn = Isbn;
        p->p_date = date;
        p->flag = flag;
        p->next = NULL;
        return p;
    }
    node->next = Create_Book(node->next, name, writer, f_letter, type, Isbn, date, flag);
    return node;
}

User* Create_User(User* node, char name[], int type, char f_letter, long long password, long long account, int num) {
    if (node == NULL) {
        User* p = (User*)malloc(sizeof(User));
        strcpy(p->name, name);
        p->type = type;
        p->f_letter = f_letter;
        p->password = password;
        p->account = account;
        p->num = num;
        p->record = NULL;
        p->next = NULL;
    }
    node->next = Create_User(node->next, name, type, f_letter, password, account, num);
    return node;
}

Admin* Create_Admin(Admin* node, char name[], char f_letter, long long password, long long account) {
    if (node == NULL) {
        Admin* p = (Admin*)malloc(sizeof(Admin));
        strcpy(p->name, name);
        p->f_letter = f_letter;
        p->password = password;
        p->account = account;
        p->next = NULL;
        return p;
    }
    node->next = Create_Admin(node->next, name, f_letter, password, account);
    return node;
}

void Load_Infor(char fileb[], char fileu[], char filea[]) {
    FILE* fb = fopen(fileb, "r");
    char name[100], writer[100], f_letter;
    int type;
    long long Isbn, date, password, account;
    int flag, num;
    while (!feof(fb)) {
        fscanf(fb, "%s %s %c %d %lld %lld %d", name, writer, &f_letter, &type, &Isbn, &date, &flag);
        broot = Create_Book(broot, name, writer, f_letter, type, Isbn, date, flag);
    }
    FILE* fu = fopen(fileu, "r");
    while (!feof(fu)) {
        fscanf(fu, "%s %d %c %lld %lld %d", name, type, &f_letter, &password, &account, &num);
        uroot = Create_User(uroot, name, type, f_letter, password, account, num);
    }
    FILE* fa = fopen(filea, "r");
    while (!feof(fa)) {
        fscanf(fa, "%s %c %lld %lld", name, &f_letter, &password, &account);
        aroot = Create_Admin(aroot, name, f_letter, password, account);
    }
}

int Borrow(char uname[], long long account, char bname[], User* u_root, Book* b_root, long long date) //针对读者进行借阅操作 返回值代表借阅是否成功
{
    if (u_root == NULL || b_root == NULL) return 0;
    User* p = u_root;
    Book* q = b_root;
    while (p && account != p->account) {
        p = p->next;
    }
    if (p == NULL) return 0;
    if (p->num >= UserType[p->type]) return 0;//如果借阅书籍达到上限，借阅失败
    while (q && (strcmp(q->name, bname) != 0 || q->flag == 1)) {
        q = q->next;
    }//分别查找对应的读者和没有被借出的书
    if (q == NULL) return 0;
    Record* record = (Record*)malloc(sizeof(Record));
    strcpy(record->book.name, q->name);
    strcpy(record->book.writer, q->writer);
    record->book.f_letter = q->f_letter;
    record->book.type = q->type;
    record->book.Isbn = q->Isbn;
    record->book.p_date = q->p_date;
    q->flag = 1;
    record->book.flag = 1;
    record->book.next = NULL;
    record->date = date;
    record->next = NULL;
    if (p->record == NULL) {
        p->record = record;
    }
    else {
        Record* t = p->record;
        while (t->next) {
            t = t->next;
        }
        t->next = record;
    }
    p->num++;
    //为读者增加借阅记录
    if (reroot == NULL) {
        reroot = record;
    }
    else {
        Record* r = reroot;
        while (r) {
            r = r->next;
        }
        r = record;//在总体的借阅记录上增加一次借阅记录
    }
    return 1;
}

int Return(char uname[], long long account, char bname[], long long isbn, User* u_root, Book* b_root)
//进行读者还书操作，返回值为操作是否成功
{
    if (u_root == NULL || b_root == NULL) return 0;
    User* p = u_root;
    while (p && account != p->account) {
        p = p->next;
    }//查找读者
    if (p == NULL) return 0;
    if (p->record == NULL) return 0;
    if (p->record->book.Isbn == isbn) {
        p->record = p->record->next;
        p->num--;
        return 1;
    }
    Record* q = p->record;
    while (q && isbn != q->book.Isbn) {
        q = q->next;
    }
    if (q == NULL) return 0;
    Record* pre = p->record;
    while (pre && pre->next != q) {
        pre = pre->next;
    }
    pre->next = q->next;
    free(q);//查找并删除相应记录
    Book* t = b_root;
    while (t && t->Isbn != isbn) {
        t = t->next;
    }
    t->flag = 0;
    p->num--;//更新书籍以及读者信息
    return 1;
}

int U_Maintain(long long account, long long password, User* u_root)
//维护读者的密码
{
    if (u_root == NULL) return 0;
    User* p = u_root;
    while (p && p->account != account) {
        p = p->next;
    }
    if (p == NULL) return 0;
    p->password = password;
    return 1;
}

void Print_Record(char name[], long long account, User* u_root)
//输出用户的所有借阅书籍的名字
{
    if (u_root == NULL) return;
    User* p = u_root;
    while (p != NULL && p->account != account) {
        p = p->next;
    }
    if (p->record == NULL) return;
    Record* q = p->record;
    while (q) {
        printf("%s %lld\n", q->book.name, q->book.Isbn);
        q = q->next;
    }
}

int Search_Record(char uname[], long long account, char bname[], User* u_root)
//具体查询用户是否借阅过某本书
{
    if (u_root == NULL) return 0;
    User* p = u_root;
    while (p && p->account != account) {
        p = p->next;
        if (p == NULL) return 0;
    }
    if (p->record == NULL) return 0;
    Record* q = p->record;
    while (q && strcmp(q->book.name, bname) != 0) {
        q = q->next;
        if (q == NULL) return 0;
    }
    return 1;
}

int Count(char uname[], long long account, User* u_root)
//统计并输出用户借阅的书籍总数
{
    if (u_root == NULL) return 0;
    User* p = u_root;
    while (p && p->account != account) {
        p = p->next;
        if (p == NULL) return 0;
    }
    printf("该用户一共借阅了%d本书\n", p->num);
    return 1;
}

Record* merge(Record* left, Record* right) //归并
{
    Record dummy;
    Record* tail = &dummy;
    while (left && right) {
        if (left->book.f_letter <= right->book.f_letter) {
            tail->next = left;
            left = left->next;
        }
        else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    tail->next = left ? left : right;
    return dummy.next;
}

Record* sort(Record* head, int n) {
    if (n <= 1) return head;
    int mid = n / 2;
    Record* midNode = head;
    for (int i = 0; i < mid - 1; ++i) {
        midNode = midNode->next;
    }
    Record* rightHead = midNode->next;
    midNode->next = NULL;
    Record* left = sort(head, mid);
    Record* right = sort(rightHead, n - mid);
    return merge(left, right);
}

void Sort_Record(char uname[], long long account, User* u_root) //对读者的借阅记录进行排序
{
    User* p = u_root;
    while (p && p->account != account) {
        p = p->next;
    }
    if (p == NULL || p->record == NULL) return;

    int n = 0;
    Record* q = p->record;
    while (q) {
        q = q->next;
        ++n;
    }
    p->record = sort(p->record, n);
}


void Writer_Search(Book* b_root) {
    char name[100];
    scanf("%s", name);
    Book* p = b_root;
    while (p) {
        if (strstr(p->writer, name) != NULL) {
            printf("%s:%s\n", p->name, p->writer);
        }
        p = p->next;
    }
}

void Book_Search(Book* b_root) {
    char name[100];
    scanf("%s", name);
    Book* p = b_root;
    while (p) {
        if (strstr(p->name, name) != NULL) {
            printf("%s:%s\n", p->name, p->writer);
        }
        p = p->next;
    }
}

void Elastic_Search(Book* b_root) //模糊查询
{
    int flag;
    printf("查询作者请按1，查询书籍请按2:");
    scanf("%d", &flag);
    switch (flag) {
    case 1:
        printf("请输入作者的姓名或其中的一部分：");
        Writer_Search(b_root);
        break;
    case 2:
        printf("请输入书的名字或其中的一部分：");
        Book_Search(b_root);
        break;
    }
}

//以上是读者的功能
int Search_All_Record(Book k)//某本书的借阅记录
{
    Record* p = reroot;
    int num = 0;
    while (p) {
        if (strcmp(k.name, p->book.name))
            num++;
        p = p->next;
    }
    return num;
}
int Search_Type_Record(int type)//某类书的借阅记录
{
    Record* p = reroot;
    int num = 0;
    while (p)
    {
        if (type == p->book.type)num++;
        p = p->next;
    }
    return num;
}
Record* All_sort(Record* head)//对所有记录进行排序
{
    Record* p = reroot;
    int num = 0;
    while (p)
    {
        num++;
        p = p->next;
    }
    return sort(reroot, num);
}
int A_Maintain(long long account, long long password, Admin* a_root)
//维护管理员的密码
{
    a_root->password = password;
    return 1;
}
int Reset_Password(long long account)
{
    return U_Maintain(account, 123456, uroot) == 1 ? 1 : 0;
}
/*备份函数 1: 复制成功；2: 复制失败*/
int copyFile(char* fileRead, char* fileWrite) {
    FILE* fpRead;
    FILE* fpWrite;
    int bufferLen = 1024;
    char* buffer = (char*)malloc(bufferLen * sizeof(char));  // 开辟缓存
    int readCount;
    fpRead = fopen(fileRead, "rt");
    fpWrite = fopen(fileWrite, "wt");
    if (fpRead == NULL || fpWrite == NULL) {
        printf("Cannot open file!\n");
    }
    // 不断从fileRead读取内容，放在缓冲区，再将缓冲区的内容写入fileWrite
    while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0) {
        fwrite(buffer, readCount, 1, fpWrite);
    }
    free(buffer);
    fclose(fpRead);
    fclose(fpWrite);
    return 1;
}

void File_Cope(char* fileRead, char* fileWrite)//文件备份函数
{
    if (copyFile(fileRead, fileWrite)) {
        printf("恭喜你，文件备份成功！\n");
    }
    else {
        printf("文件备份失败！\n");
    }

}