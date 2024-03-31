#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int BookType[6] = { 30, 30, 30, 30, 30, 30};//各类书可以借阅的时间
int UserType[3] = { 20, 25, 30};//不同读者可以借阅的图书数量

typedef struct Book {
    char* name;//书名
    char* writer;//作者名
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
    Record* next;
}Record;

typedef struct User {
    char* name;//读者名字
    int type;//读者类型 0 本科生 1 研究生 2 博士生
    char f_letter;//读者名字拼音首字母
    long long password;//读者的密码
    long long account;//读者的账号
    int num;//已借阅的书的数量
    Record* record;//用链表来存储借阅了哪些书
    struct User* next;
}User;

typedef struct Administrator {
    char* name;//管理员名字
    char f_letter;//管理员名字拼音首字母
    long long password;//管理员密码
    long long account;//管理员账号
    struct Administrator* next;
}Admin;

Book* broot;
Record* reroot;
User* uroot;
Admin* aroot;

int Borrow(char* uname, char* account, char* bname, User* uroot, Book* broot, long long date) //针对读者进行借阅操作 返回值代表借阅是否成功
{
    User* p = uroot;
    Book* q = broot;
    while (p && (strcmp(p->name, uname) != 0 || strcmp(account, p->account) != 0)) {
        p = p->next;
        if (p == NULL) return 0;
    }
    if (p->num > UserType[p->type]) return 0;//如果借阅书籍达到上限，借阅失败
    while (q && (strcmp(q->name, bname) != 0 || q->flag == 1)) {
        q = q->next;
        if (q == NULL) return 0;
    }//分别查找对应的读者和没有被借出的书
    Book book;
    strcpy(book.name, q->name);
    strcpy(book.writer, q->writer);
    book.f_letter = q->f_letter;
    book.type = q->type;
    book.Isbn = q->Isbn;
    book.p_date = q->p_date;
    q->flag = 1;
    book.flag = 1;
    book.next = NULL;
    Record* record;
    record->book = book;
    record->date = date;
    record->next = NULL;
    if (p->record == NULL) {
        p->record = record;
        return 1;
    }
    Record* t = p->record;
    while (t != NULL) {
        if (t->next == NULL) break;
        t = t->next;
    }
    t->next = record;
    p->num++;
    //为读者增加借阅记录
    if (reroot == NULL) {
        reroot = record;
    }
    Record* r = reroot;
    while (r) {
        if (r->next = NULL) break;
        r = r->next;
    }
    r->next = record;//在总体的借阅记录上增加一次借阅记录
    return 1;
}

int Return(char* uname, char* account, char* bname, long long isbn, User* uroot, Book* broot) 
//进行读者还书操作，返回值为操作是否成功
{
    User* p = uroot;
    while (p && (strcmp(uname, p->name) != 0 || strcmp(account, p->account) != 0)) {
        p = p->next;
        if (p == NULL) return 0;
    }//查找读者
    if (p->record == NULL) return 0;
    if (p->record->book.Isbn = isbn) {
        p->record->next = p->record->next->next;
    }
    Record* q = p->record;
    while (q && isbn != q->book.Isbn) {
        q = q->next;
        if (q == NULL) return 0;
    }
    Record* pre = p->record;
    while (pre && pre->next != q) {
        pre = pre->next;
    }
    pre->next = q->next;
    free(q);//查找并删除相应记录
    Book* t = broot;
    while (t && t->Isbn != isbn) {
        t = t->next;
    }
    t->flag = 0;
    p->num--;//更新书籍以及读者信息
    return 1;
}

int U_Maintain(char* name, long long account, long long password, User* uroot) 
//维护读者的密码
{
    User* p = uroot;
    while (p && p->account != account) {
        p = p->next;
        if (p = NULL) return 0;
    }
    p->password = password;
    return 1;
}

int main() {

}