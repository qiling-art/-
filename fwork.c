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
    long long Isbn;//书的ISBN码s
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
    if (uroot == NULL || broot == NULL) return 0;
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
        return 1;
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
    if (uroot == NULL || broot == NULL) return 0;
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
    if (uroot == NULL) return 0;
    User* p = uroot;
    while (p && p->account != account) {
        p = p->next;
        if (p = NULL) return 0;
    }
    p->password = password;
    return 1;
}

void Print_Record(char* name, long long account, User* uroot) 
//输出用户的所有借阅书籍的名字
{
    if (uroot == NULL) return;
     User* p = uroot;
     while (p && p->account != account) {
        p = p->next;
        if (p == NULL) return;
     }
     if (p->record == NULL) return;
     Record* q = p->record;
     while (q) {
        printf("%s\n", q->book.name);
        q = q->next;
     }
}

int Search_Record(char* uname, long long account, char* bname, User* uroot) 
//具体查询用户是否借阅过某本书
{
    if (uroot == NULL) return 0;
    User* p = uroot;
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

int Count(char* uname, long long account, User* uroot) 
//统计并输出用户借阅的书籍总数
{
    if (uroot == NULL) return 0;
    User* p = uroot;
    while (p && p->account != account) {
        p = p->next;
        if (p == NULL) return 0;
    }
    printf("该用户一共借阅了%d本书\n", p->num);
    return 1;
}

Record* sort(Record* head, int n) 
//使用归并排序
{
    if (n <= 1) return;
    int l = n / 2, r = n - l;
    Record *p1 = head, *p2;
    for (int i = 1; i < l; i++) {
        p1 = p1->next;
    }
    p2 = p1->next;
    p1->next = NULL;
    p1 = sort(p1, l);
    p2 = sort(p2, r);
    Record ret, *p;
    ret.next = NULL;
    p = &ret;
    while (p1 || p2) {
        if (p2 == NULL || p1->book.f_letter <= p2->book.f_letter) {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        else {
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
    }
    return ret.next;
} 

void Sort_Record(char* uname, long long account, User* uroot) 
//对读者的借阅记录进行排序
{
    User* p = uroot;
    while (p && p->account != account) {
        p = p->next;
    }
    Record* q = p->record;
    int n = 0;
    while (q) {
        q = q->next;
        n++;
    }
    return sort(p->record, n);
}

//以上是读者的功能
int Search_All_Record(Book k)//某本书的借阅记录
{
	Record* p = reroot;
	int num = 0;
	while (p) {
		if(strcmp(k.name,p->book.name)num++;
			p=p->next;
	}
	return num;
}
int Search_Type_Record(int type)//某类书的借阅记录
{
	Record *p=reroot;
	int num=0;
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


int main() {

}