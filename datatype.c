typedef struct Book {
    char* name;//书名
    char* writer;//作者名
    char f_letter;//拼音首字母
    int type;//书的种类
    long long Isbn;//书的ISBN码
    long long p_date;//出版日期
}Book;

typedef struct User {
    char* name;//读者名字
    int type;//读者类型
    char f_letter;//读者名字拼音首字母
    long long password;//读者的密码
    char* account;//读者的账号
}User;

typedef struct Administrator {
    char* name;//管理员名字
    char f_letter;//管理员名字拼音首字母
    long long password;//管理员密码
    char* account;//管理员账号
}Admin;