#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int BookType[6] = { 30, 30, 30, 30, 30, 30 };//��������Խ��ĵ�ʱ��
int UserType[3] = { 20, 25, 30 };//��ͬ���߿��Խ��ĵ�ͼ������

typedef struct Book {
    char name[100];//����
    char writer[100];//������
    char f_letter;//ƴ������ĸ
    int type;//������࣬0 ������ 1 ������ 2 С˵�� 3 ������ 4 ��ʷ�� 5 ʫ����
    long long Isbn;//���ISBN��s
    long long p_date;//��������
    int flag;//�ж��Ȿ����û�б����
    struct Book* next;
}Book;

typedef struct Record {
    Book book;//���ĵ����������Ϣ
    long long date;//���ĵ�ʱ��
    struct Record* next;
}Record;

typedef struct User {
    char name[100];//��������
    int type;//�������� 0 ������ 1 �о��� 2 ��ʿ��
    char f_letter;//��������ƴ������ĸ
    long long password;//���ߵ�����
    long long account;//���ߵ��˺�
    int num;//�ѽ��ĵ��������
    Record* record;//���������洢��������Щ��
    struct User* next;
}User;

typedef struct Administrator {
    char name[100];//����Ա����
    char f_letter;//����Ա����ƴ������ĸ
    long long password;//����Ա����
    long long account;//����Ա�˺�
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

int Borrow(char uname[], long long account, char bname[], User* u_root, Book* b_root, long long date) //��Զ��߽��н��Ĳ��� ����ֵ��������Ƿ�ɹ�
{
    if (u_root == NULL || b_root == NULL) return 0;
    User* p = u_root;
    Book* q = b_root;
    while (p && account != p->account) {
        p = p->next;
    }
    if (p == NULL) return 0;
    if (p->num >= UserType[p->type]) return 0;//��������鼮�ﵽ���ޣ�����ʧ��
    while (q && (strcmp(q->name, bname) != 0 || q->flag == 1)) {
        q = q->next;
    }//�ֱ���Ҷ�Ӧ�Ķ��ߺ�û�б��������
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
    //Ϊ�������ӽ��ļ�¼
    if (reroot == NULL) {
        reroot = record;
    }
    else {
        Record* r = reroot;
        while (r) {
            r = r->next;
        }
        r = record;//������Ľ��ļ�¼������һ�ν��ļ�¼
    }
    return 1;
}

int Return(char uname[], long long account, char bname[], long long isbn, User* u_root, Book* b_root)
//���ж��߻������������ֵΪ�����Ƿ�ɹ�
{
    if (u_root == NULL || b_root == NULL) return 0;
    User* p = u_root;
    while (p && account != p->account) {
        p = p->next;
    }//���Ҷ���
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
    free(q);//���Ҳ�ɾ����Ӧ��¼
    Book* t = b_root;
    while (t && t->Isbn != isbn) {
        t = t->next;
    }
    t->flag = 0;
    p->num--;//�����鼮�Լ�������Ϣ
    return 1;
}

int U_Maintain(long long account, long long password, User* u_root)
//ά�����ߵ�����
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
//����û������н����鼮������
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
//�����ѯ�û��Ƿ���Ĺ�ĳ����
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
//ͳ�Ʋ�����û����ĵ��鼮����
{
    if (u_root == NULL) return 0;
    User* p = u_root;
    while (p && p->account != account) {
        p = p->next;
        if (p == NULL) return 0;
    }
    printf("���û�һ��������%d����\n", p->num);
    return 1;
}

Record* merge(Record* left, Record* right) //�鲢
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

void Sort_Record(char uname[], long long account, User* u_root) //�Զ��ߵĽ��ļ�¼��������
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

void Elastic_Search(Book* b_root) //ģ����ѯ
{
    int flag;
    printf("��ѯ�����밴1����ѯ�鼮�밴2:");
    scanf("%d", &flag);
    switch (flag) {
    case 1:
        printf("���������ߵ����������е�һ���֣�");
        Writer_Search(b_root);
        break;
    case 2:
        printf("������������ֻ����е�һ���֣�");
        Book_Search(b_root);
        break;
    }
}

//�����Ƕ��ߵĹ���
int Search_All_Record(Book k)//ĳ����Ľ��ļ�¼
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
int Search_Type_Record(int type)//ĳ����Ľ��ļ�¼
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
Record* All_sort(Record* head)//�����м�¼��������
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
//ά������Ա������
{
    a_root->password = password;
    return 1;
}
int Reset_Password(long long account)
{
    return U_Maintain(account, 123456, uroot) == 1 ? 1 : 0;
}
/*���ݺ��� 1: ���Ƴɹ���2: ����ʧ��*/
int copyFile(char* fileRead, char* fileWrite) {
    FILE* fpRead;
    FILE* fpWrite;
    int bufferLen = 1024;
    char* buffer = (char*)malloc(bufferLen * sizeof(char));  // ���ٻ���
    int readCount;
    fpRead = fopen(fileRead, "rt");
    fpWrite = fopen(fileWrite, "wt");
    if (fpRead == NULL || fpWrite == NULL) {
        printf("Cannot open file!\n");
    }
    // ���ϴ�fileRead��ȡ���ݣ����ڻ��������ٽ�������������д��fileWrite
    while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0) {
        fwrite(buffer, readCount, 1, fpWrite);
    }
    free(buffer);
    fclose(fpRead);
    fclose(fpWrite);
    return 1;
}

void File_Cope(char* fileRead, char* fileWrite)//�ļ����ݺ���
{
    if (copyFile(fileRead, fileWrite)) {
        printf("��ϲ�㣬�ļ����ݳɹ���\n");
    }
    else {
        printf("�ļ�����ʧ�ܣ�\n");
    }

}




void AdjustBookType(Book* head, char name[], int new_type)//���ú͵���ͼ����������
{
    Book* current = head;// ����һ��ָ��current����ʼ��Ϊ����ͷ�ڵ�
    while (current != NULL)// ��������
    {
        if (strcmp(current->name, name) == 0)// ����ҵ�����ƥ���ͼ��
        {
            current->type = new_type;// ��ͼ��ķ������Ϊ�µķ���
            printf("%s�������ѵ���Ϊ%d", name, new_type);
            return;// �˳�����
        }
        current = current->next; // �ƶ�����һ���ڵ�
    }
    printf("������ͼ��%s", name);

}
void AdjustBookBTime(int old_type, int new_time)//���ú͵���ÿ��ͼ��Ľ���ʱ��
{
    if (old_type >= 0 && old_type < 6)
    {
        BookType[old_type] = new_time; // ������Ӧ���͵�ͼ�����ʱ��
        printf("%d�Ľ���ʱ���ѵ���Ϊ%d��", old_type, new_time);
        return; // �˳�����
    }
    else {
        printf("�����ڴ�����ͼ��\n");
    }
}
void AdjustUserType(User* head, char name[], int new_type)//���ú͵���������������
{
    User* current = head;// ����һ��ָ��current����ʼ��Ϊ����ͷ�ڵ�
    while (current != NULL)// ��������
    {
        if (strcmp(current->name, name) == 0) {
            current->type = new_type;// �����ߵķ������Ϊ�µķ���
            printf("%s�������ѵ���Ϊ%d", name, new_type);
            return; // �˳�����
        }
        current = current->next;// �ƶ�����һ���ڵ�
    }
    printf("�����ڶ���%s", name);

}
void AdjustUserBTime(int old_type, int new_time)//���ú͵���ÿ����ߵĽ���ʱ��
{
    if (old_type >= 0 && old_type < 3) {
        BookType[old_type] = new_time;// ������Ӧ���͵Ķ��߽���ʱ��
        printf("%d�Ľ���ʱ���ѵ���Ϊ%d��", old_type, new_time);
        return;// �˳�����
    }
    else {
        printf("�����ڴ����Ͷ���\n");
    }

}
void AddBook(Book* head, char name[], char writer[], char f_letter, int type, long long Isbn, long long p_date)//����ͼ����Ϣ
{
    Book* newBook = (Book*)malloc(sizeof(Book));// ��̬����һ���µ�Book�ڵ�
    strcpy(newBook->name, name);// ����name�ֶ�
    strcpy(newBook->writer, writer);// ����writer�ֶ�
    newBook->f_letter = f_letter;// ���������ֶ�
    newBook->type = type;
    newBook->Isbn = Isbn;
    newBook->p_date = p_date;
    newBook->next = head;// ���½ڵ���뵽����ͷ��
    head = newBook;
}
void DeleteBook(Book* head, char name[])//ɾ��ͼ����Ϣ
{
    Book* current = head;
    Book* prev = NULL;
    while (current != NULL && strcmp(current->name, name) != 0)// ��������
    {
        prev = current;
        current = current->next;

    }
    if (current == NULL)// ���δ�ҵ�ͼ��
    {
        printf("���޴���\n");
        return;
    }
    if (prev == NULL)// ���Ҫɾ���Ľڵ���ͷ�ڵ�
    {
        head = current->next;
    }
    else // ���򣬽�ǰһ���ڵ��nextָ��ǰ�ڵ����һ���ڵ�
    {
        prev->next = current->next;
    }
}
void AddUser(User* head, char name[], int type, char f_letter, long long password, long long account)//���Ӷ�����Ϣ
{
    User* newUser = (User*)malloc(sizeof(User));// ��̬����һ���µ�User�ڵ�
    strcpy(newUser->name, name);// ����name�ֶ�
    newUser->type = type;// ���������ֶ�
    newUser->f_letter = f_letter;
    newUser->password = password;
    newUser->account = account;
    newUser->num = 0;
    newUser->next = head;// ���½ڵ���뵽����ͷ��
    head = newUser;
}
void DeleteUser(User* head, char name[])//ɾ��������Ϣ
{
    User* current = head; // ��ǰ�������û�ָ��
    User* prev = NULL;  // ǰһ���û�ָ��
    while (current != NULL && strcmp(current->name, name) != 0) // ��������
    {
        prev = current;// ����ǰһ���û�ָ��
        current = current->next;// �ƶ�����һ���û�
    }
    if (current == NULL) // �����ǰ�û�Ϊ��
    {
        printf("���޴���\n");
        return;
    }
    if (prev == NULL) // ���Ҫɾ������ͷ�ڵ�
    {
        head = current->next; // ����ͷ�ڵ�Ϊ��һ���û�
    }
    else {
        prev->next = current->next; // ����ָ��ǰ�û�����һ���û�
    }
}
void ModifyBook(Book* head, char name[], int new_type)//�޸�ͼ����Ϣ
{
    Book* current = head; // ��ǰ������ͼ��ָ��
    Book* prev = NULL;// ǰһ��ͼ��ָ��
    while (current != NULL) // ��������
    {
        if (strcmp(current->name, name) == 0) {
            current->type = new_type;
            return;
        }
        prev = current;
        current = current->next;// �ƶ�����һ���ڵ�
    }
}
void ModifyUser(User* head, long long account, int new_type)//�޸Ķ�����Ϣ
{
    User* current = head;// ��ǰ�������û�ָ��
    User* prev = NULL; // ǰһ���û�ָ��
    while (current != NULL)// ��������
    {
        if (current->account == account) {
            current->type = new_type;
            return;
        }
        prev = current;
        current = current->next;// �ƶ�����һ���ڵ�
    }
}