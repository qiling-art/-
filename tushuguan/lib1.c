//#include <stdio.h>
//#include <stdlib.h>//���а���system����
//#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
//#include <string.h>//�����ַ�����
//#include <math.h>
//#pragma warning(disable:4996)
//#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
//#define LEN1 sizeof(struct reader)//�йض�����Ϣ�Ľṹ��
//#define LEN2 sizeof(struct land)//�йص�¼ϵͳ�Ľṹ��
//
//
//struct book//ͼ����Ϣ
//{
//	char num[20], nam[20], aut[20], pub[20], cat[20];
//	int  many;
//	float price;
//	struct book* next;
//};
//
//struct reader//���߽�����Ϣ
//{
//	int jnum;
//	char jnam[20], time[20], tsnam[20];
//	struct reader* next;
//};
//struct land//��¼��Ϣ
//{
//	int zhanghao;
//	char password[20];
//	struct land* next;
//};
//
//
//
//int tjzs();//ͳ��library�ı���������
//void xg(int, char[]);
//void mainmenu();//��ʾ���˵�
//void tsmenu();//��ʾͼ����Ϣ�˵�
//void jmenu();//��ʾ������Ϣ�˵�
//void lmenu();//��ʾ��¼�˵�
//
//void main1();// ���˵�����
//void tsmain();//ͼ��˵�����
//void cxts();//��ѯͼ��
//void zjts();//����ͼ��
//void scts();//ɾ��ͼ��
//void llts();//���ͼ��
//
//void jmain();//���߽�����Ϣ
//void js();//����
//void hs();//����
//void cxjs();//��ѯ����
//void lljs();// ����������
//
//void land();//��¼����ϵͳ
//void xinjian();//�����˺�����
//void xgmm();//�޸�����
//void lmain();//��¼���溯��
//
//
//int tjzs()//ͳ��ͼ���ı�����
//{
//	FILE* fp;
//	int txcl = 0, n;
//	float tprice = 0;
//	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, tchuban[20] = { '\0' }, tkind[20] = { '\0' }, tshuhao[20] = { '\0' };
//	fp = fopen("library.txt", "r");//���ļ�
//	for (n = 0; !feof(fp); n++)//������ļ�
//		fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);
//	n--;
//	fclose(fp);//�ر��ļ�
//	return (n);//���ظ���
//}
//
//
//int tjdzzs()//ͳ���Ķ��߱���������
//
//{
//	FILE* fp;
//	int zhenghao = 0, n;
//	char mingzi[20] = { '\0' }, riqi[20] = { '\0' }, zname[20] = { '\0' };
//	fp = fopen("reader.txt", "r");//���ļ�
//	for (n = 0; !feof(fp); n++)//������ļ�
//		fscanf(fp, "%d%s%s%s ", &zhenghao, &mingzi, &riqi, &zname);
//	n--;
//	fclose(fp);//�ر��ļ�
//	return (n);//���ظ���
//}
//
//
//int tjzs3()//ͳ���˺������ı�����
//{
//	FILE* fp;
//	int zhao = 0, n;
//	char mm[20] = { '\0' };
//	fp = fopen("land.txt", "r");//���ļ�
//	for (n = 0; !feof(fp); n++)//������ļ�
//		fscanf(fp, "%d %s", &zhao, mm);
//	n--;
//	fclose(fp);//�ر��ļ�
//	return (n);//���ظ���
//}
//
//
//void mainmenu()//���˵�
//{
//	system("cls");
//
//	printf("**************************************************");
//
//	printf("\n\n 1.ͼ��ϵͳ\n\n");
//
//	printf("\n\n 2.����ϵͳ\n\n");
//
//	printf("\n\n 3.�˳�ϵͳ\n\n");
//
//	printf("\n\n �밴��ѡ�񣬻س�ȷ��\n");
//
//	printf("*************************************************\n");
//
//	return;
//}
//
//
//void tsmenu() //ͼ�����Ϣ�˵�
//{
//	system("cls");
//
//	printf("****************************************************");
//
//	printf("\n 1.����ͼ��\n\n");
//
//	printf("\n 2.ɾ��ͼ��\n\n");
//
//	printf("\n 3.��ѯͼ��\n\n");
//
//	printf("\n 4.������\n\n");
//
//	printf("\n 5.������һ��\n\n");
//
//	printf("\n �밴��ѡ�񣬻س�ȷ��\n");
//
//	printf("***************************************************\n");
//
//	return;
//
//}
//
//
//void main1()
//{
//	void tsmian();
//	void jmain();
//	char choose;
//	mainmenu();
//	scanf(" %c", &choose);
//	switch (choose)//���ܺ���
//	{
//	case'1':
//		tsmain();
//		break;
//	case'2':
//		jmain();
//		break;
//	case'3':
//		system("cls");
//		getch();
//		exit(0);
//		system("cls");
//		break;
//	}
//}
//
//
//void tsmain()
//{
//	void zjts();
//	void scts();
//	void ctts();
//	void llts();
//	char choose;
//	tsmenu();
//	scanf(" %c", &choose);
//	for (;;)
//	{
//		switch (choose)
//		{
//		case'1':
//			zjts();
//			break;
//		case'2':
//			scts();
//			break;
//		case'3':
//			cxts();
//			break;
//		case'4':
//			llts();
//			break;
//		case'5':
//			main1();
//			break;
//		}
//	}
//}
//
//
//void zjts()//����ͼ��
//{
//	FILE* fp;
//	char i;
//	int many = 0;
//	float price = 0;
//	char  nam[20] = { '\0' }, aut[20] = { '\0' }, cat[20] = { '\0' }, pub[20] = { '\0' }, num[20] = { '\0' };
//	system("cls");
//
//	if ((fp = fopen("library.txt", "r")) == NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
//	{
//		fp = fopen("library.txt", "w");
//		fclose(fp);
//	}
//	fp = fopen("library.txt", "a");
//
//	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ��� ������ ����");
//
//	for (; i != 27;)//Ϊ��ʵ������һ�κ�esc�˳�
//	{
//		printf("������:\n");
//		scanf("%s%s%s%s%s%d%f", num, nam, aut, pub, cat, &many, &price);
//		fprintf(fp, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", num, nam, aut, pub, cat, many, price);
//		printf("���������밴�س������������밴Esc\n");
//		i = getch();//��ͣ����i���պ������һ��ָ��
//		for (; i != 13 && i != 27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
//			i = getch();
//	}
//
//	fclose(fp);
//	printf("\n����ɹ����������������һ��!");
//	getch();
//	tsmain();//������һ��
//}
//
//void scts()//ɾ��ͼ��
//{
//	struct book* head = NULL;
//	struct book* p, * p1, * p2;
//	int tmany = 0, n = 0, j, k;
//	float tprice = 0;
//	char  tnam[20] = { '\0' }, taut[20] = { '\0' }, tcat[20] = { '\0' }, tpub[20] = { '\0' }, tnum[20] = { '\0' };
//	char jjnam[20] = { '\0' };
//	char i;
//	FILE* fp;
//	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�
//	{
//		system("cls");
//		printf("\n��¼�ļ�������!�����������");
//		getch();
//		tsmain();
//	}
//
//	else//ʵ��ɾ���Ĺ���
//	{
//		system("cls");
//		printf("\n��������Ҫɾ��������:");//����ɾ��ͼ������
//		scanf("%s", jjnam);
//		printf("\nȷ��ɾ����س���ȡ���밴Esc\n");
//		i = getch();
//		for (; i != 13 && i != 27;)
//			i = getch();
//		if (i == 27)
//			tsmain();
//		fp = fopen("library.txt", "r");
//		j = tjzs();
//
//		for (k = 0; k < j; k++)
//		{
//			fscanf(fp, "%s%s%s%s%s%d%f", tnum, tnam, taut, tpub, tcat, &tmany, &tprice);
//			if (strcmp(jjnam, tnam))//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
//			{
//				n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
//				if (n == 1)//��������
//				{
//					p1 = p2 = (struct book*)malloc(LEN);
//					head = p1;
//				}
//				else
//				{
//					p2->next = p1;
//					p2 = p1;
//					p1 = (struct book*)malloc(LEN);//�½�����
//				}
//
//				strcpy(p1->num, tnum);//�������
//				strcpy(p1->nam, tnam);//��������
//				strcpy(p1->aut, taut);//������������
//				strcpy(p1->pub, tpub);//���Ƴ�����
//				strcpy(p1->cat, tcat);//�������
//				p1->many = tmany;//���Ƹ���
//				p1->price = tprice;//���Ƶ���
//			}
//		}
//		if (n == 0)//���ͼ��ֻ��һ������һ��պú�Ҫɾ������ͬ
//		{
//			head = NULL;
//		}
//		else//������������ʣ��һ������ռ䣬���Է��
//		{
//			p2->next = p1;
//			p1->next = NULL;
//			fclose(fp);
//		}
//	}
//
//	fp = fopen("library.txt", "w");//����ļ���ֻд�򿪣�Ȼ��ر�
//	fclose(fp);
//	fp = fopen("library.txt", "a");//׷���ļ�
//	p = head;
//
//	for (; p != NULL;)//���������ݸ��ǵ��ļ�
//	{
//		fprintf(fp, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", p->num, p->nam, p->aut, p->pub, p->cat, p->many, p->price);
//		p = p->next;
//	}
//	fclose(fp);
//	system("cls");
//	printf("\nɾ���ɹ� \n�������������һ��\n");
//	getch();//������һ��
//	tsmain();
//}
//
//
//void cxts()//��ѯͼ��
//{
//	FILE* fp;
//	int k = 0, many = 0, m = 0, n = 0;
//	float price = 0;
//	char  nam[20] = { '\0' }, aut[20] = { '\0' }, cat[20] = { '\0' }, pub[20] = { '\0' }, num[20] = { '\0' };
//	char i;
//	char chazhao[20] = { '\0' };
//	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�
//	{
//		system("cls");
//		printf("\n��¼�ļ�������!�����������");
//		getch();
//		tsmain();
//	}
//	system("cls");
//	printf("���������,����,���߻�����ѯ��\n");
//	scanf("%s", chazhao);
//	system("cls");
//	m = tjzs();
//
//	for (n = 0; n < m; n++)
//	{
//		fscanf(fp, "%s%s%s%s%s%d%f", num, nam, aut, pub, cat, &many, &price);
//		if (!strcmp(chazhao, num) || !strcmp(chazhao, nam) || !strcmp(chazhao, aut) || !strcmp(chazhao, cat))
//		{
//			if (k == 0)
//			{
//				printf("��ѯ���:\n\n");
//				printf("���\t����\t����\t\t������\t\t���\t\t�ִ���\t����\n");
//			}
//			printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", num, nam, aut, pub, cat, many, price);
//			k++;
//		}
//	}
//	if (k == 0)//�ļ���Ϊ��������޼�¼��������һ��
//	{
//		system("cls");
//		printf("\n�޷��ϼ�¼!\n");
//		getch();
//		tsmain();
//	}
//	fclose(fp);//��ѯ����
//	getch();
//	tsmain();
//}
//
//
//void llts()//���ͼ��
//{
//	FILE* fp;
//	int n = 0;
//	int k = 0, m = 0, many = 0;
//	float price = 0;
//	char  nam[20] = { '\0' }, aut[20] = { '\0' }, cat[20] = { '\0' }, pub[20] = { '\0' }, num[20] = { '\0' };
//	char i;
//	if ((fp = fopen("library.txt", "r")) == NULL)//���ļ�
//	{
//		system("cls");
//		printf("\n��¼�ļ�������!�����������");
//		getch();//����
//		tsmain();
//	}
//	n = tjzs();
//	if (n == 0)
//	{
//		system("cls");
//		printf("\n���κμ�¼!");
//	}
//
//	fp = fopen("library.txt", "r");//��ֻ���ļ�
//	system("cls");
//	printf("���\t����\t����\t\t������\t\t���\t\t�����\t����\n");
//
//	for (m = 0; m < n; m++)//�������
//	{
//		fscanf(fp, "%s%s%s%s%s%d%f", num, nam, aut, pub, cat, &many, &price);
//		printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", num, nam, aut, pub, cat, many, price);
//	}
//	fclose(fp);
//	printf("\n�����������\n");
//	getch();
//	tsmain();
//}
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`!~~~~~~~~~~~~~~~~~~~~~
//
//void jmenu()//��ʾ����˵�
//{
//	system("cls");
//	printf("*****************************************************");
//	printf("\n\n 1.����Ǽ�\n\n");
//	printf("\n\n 2.����Ǽ�\n\n");
//	printf("\n\n 3.��������鿴\n\n");
//	printf("\n\n 4.��ѯ����\n\n");
//	printf("\n\n 5.������һ��\n\n");
//	printf("\n\n �밴��ѡ�񣬻س�ȷ��\n");
//	printf("****************************************************");
//	return;
//}
//
//
//void jmain()//����ϵͳ����
//{
//	void js();
//	void hs();
//	void lljs();
//	void cxjs();
//	char choose;
//	jmenu();
//	scanf(" %c", &choose);
//	for (;;)
//	{
//		switch (choose)
//		{
//		case'1':
//			js();
//			break;
//		case'2':
//			hs();
//			break;
//		case'3':
//			lljs();
//			break;
//		case'4':
//			cxjs();
//			break;
//		case'5':
//			main1();
//			break;
//		}
//	}
//
//}
//
//
//
//void js()//���麯��
//{
//	FILE* fp, * fp3;
//	struct book* head = NULL;
//	struct book* p, * p1, * p2;
//	int i, loop, k, n = 0, flag = 0, s = 0;
//	int jnum = 0;
//	int many = 0;
//	float tprice = 0;
//	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, tchuban[20] = { '\0' }, tkind[20] = { '\0' }, tshuhao[20] = { '\0' },
//		ttname[20] = { '\0' }, mingzi[20] = { '\0' }, riqi[20] = { '\0' }, zname[20] = { '\0' };
//	char hit = 0;
//
//	system("cls");
//	if ((fp = fopen("library.txt", "r")) == NULL)
//	{
//		system("cls");
//		printf("\n ͼ����޿��!��������˳�!");
//		getch();
//		exit(0);
//	}
//	else
//	{
//		printf("\n�������������:\n������:");
//		scanf("%s", zname);
//		k = tjzs();//ͳ��ͼ����ļ�����
//
//		for (i = 0; i < k; i++)//�Ƚ�ͼ����Ϣ�����������Ŀ��
//		{
//			fscanf(fp, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &many, &tprice);
//			n++;
//			if (n == 1)
//			{
//				p1 = p2 = (struct book*)malloc(LEN);
//				head = p1;
//			}
//			else
//			{
//				p2->next = p1;
//				p2 = p1;
//				p1 = (struct book*)malloc(LEN);
//
//			}
//			strcpy(p1->num, tshuhao);//�������
//			strcpy(p1->nam, tname);//��������
//			strcpy(p1->aut, tauthor);//��������
//			strcpy(p1->pub, tchuban);//���Ƴ�����
//			strcpy(p1->cat, tkind);//�������
//			p1->many = many;//�����ִ���
//			p1->price = tprice;//���Ƶ���
//		}
//		if (n == 0)
//			head = NULL;
//		else
//		{
//			p2->next = p1;
//			p1->next = NULL;
//			fclose(fp);
//		}
//
//	}
//	p = head;
//
//	for (; p != NULL;)
//	{
//		if (!(strcmp(p->nam, zname)))//�ж�Ҫ������Ƿ���ڣ���ǵ���1�����ڿ���һ
//		{
//
//			flag = 1;
//			loop = p->many;
//			(p->many)--;
//		}
//		p = p->next;
//	}
//	if (flag && (loop > 0))//���ڱ����ͼ�����ִ�������0���ѿ�����仯�����������ļ�
//	{
//
//		fp = fopen("library.txt", "w");
//		fclose(fp);
//		fp = fopen("library.txt", "a");
//		p = head;
//
//		for (; p != NULL;)
//		{
//			fprintf(fp, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n", p->num, p->nam, p->aut, p->pub, p->cat, p->many, p->price);
//			p = p->next;
//		}
//		free(p);
//		fclose(fp);
//
//		if ((fp3 = fopen("reader.txt", "r")) == NULL)//�������ļ��д��������Ϣ
//		{
//			fp3 = fopen("reader.txt", "w");//��ֻ���ļ�
//			fclose(fp3);
//		}
//		fp3 = fopen("reader.txt", "a");
//
//		printf("\n�밴���¸�ʽ���������Ϣ:\n ֤�� ���� �������� ��������\n������:");//¼�������Ϣ
//		scanf("%d %s %s %s", &jnum, mingzi, riqi, zname);
//		fprintf(fp3, "\n%-8d%-23s%-18s%-10s\n", jnum, mingzi, riqi, zname);
//		fclose(fp3);
//		printf("����ɹ�!���������ڹ黹�����������������\n");
//		getch();//����
//		jmain();//���ý���ϵͳ
//	}
//	else
//	{
//		if (flag != 0)
//			printf("�����ѱ�����!�����������!");//������������ѱ�����
//		else
//			printf("�����޴���!�����������");
//	}
//	getch();//����
//	jmain();//���ý���ϵͳ
//
//}
//
//
//void hs()//���麯��
//{
//	FILE* fp, * fp3;
//	struct reader* head = NULL;
//	struct reader* p, * p1, * p2;
//	struct book* lhead1 = NULL;
//	struct book* zp1, * lp1, * lp2;
//	int txcl = 0, i;
//	float tprice = 0;
//	char tname[20] = { '\0' }, tauthor[20] = { '\0' }, tkind[20] = { '\0' },
//		tchuban[20] = { '\0' }, ttname[20] = { '\0' }, tshuhao[20] = { '\0' };
//	int ttzhenghao = 0, tzhenghao = 0, n = 0, k = 0, t = 0, flag = 0;
//	char tmingzi[20] = { '\0' }, triqi[20] = { '\0' }, tzname[20] = { '\0' }, ttzname[20] = { '\0' };
//	char hitkey = 0;
//	system("cls");
//	{
//		if ((fp = fopen("reader.txt", "r")) == NULL)//�����ڶ����ļ�����������ܻ���
//		{
//			system("cls");
//			printf("\n �����ڽ�����!��������˳�!");
//			getch();
//			system("cls");
//			jmain();
//		}
//
//		else
//		{
//			{
//				printf("\n���������֤�ź�����:\n������:");
//				scanf("%d %s", &ttzhenghao, ttzname);//���뻹��֤�ź�����
//				k = tjdzzs();//��ȡ�����ļ�����Ϣ����
//				for (i = 0; i < k; i++)//��ȡ�����ļ�����Ϣ
//				{
//					fscanf(fp, "%d%s%s%s\n ", &tzhenghao, tmingzi, triqi, tzname);
//					if ((ttzhenghao == tzhenghao) && !strcmp(ttzname, tzname))//���֤���������ڣ�����Ϊ1
//						flag = 1;
//				}
//				fclose(fp);
//				fp = fopen("reader.txt", "r");//�򿪶����ļ���ɾ��������Ϣ
//				if (flag)
//				{
//					for (i = 0; i < k; i++)//�������ļ����Ƶ�����
//					{
//						fscanf(fp, "%d%s%s%s\n ", &tzhenghao, tmingzi, triqi, tzname);//��ȡ�ļ���Ϣ
//						if (!((ttzhenghao == tzhenghao) && !strcmp(ttzname, tzname)))
//						{
//							n++;
//							if (n == 1)
//							{
//								p1 = p2 = (struct reader*)malloc(LEN1);//�½�����
//								head = p1;
//							}
//							else
//							{
//								p2->next = p1;
//								p2 = p1;
//								p1 = (struct reader*)malloc(LEN1);//�½�����
//							}
//							p1->jnum = tzhenghao;//����֤��
//							strcpy(p1->jnam, tmingzi);//���ƶ�������
//							strcpy(p1->time, triqi);//������
//							strcpy(p1->tsnam, tzname);//��������
//						}
//					}
//					if (n == 0)
//						head = NULL;
//					else
//					{
//						p2->next = p1;
//						p1->next = NULL;
//						fclose(fp);
//					}
//					fp = fopen("reader.txt", "w");//��ն����ļ�
//					fclose(fp);
//					fp = fopen("reader.txt", "a");//׷����Ϣ
//					p = head;
//					for (; p != NULL;)//���������ݸ��Ƕ����ļ�
//					{
//						fprintf(fp, "\n%-8d%-23s%-18s%-10s\n", p->jnum, p->jnam, p->time, p->tsnam);
//						p = p->next;
//					}
//					free(p);
//					fclose(fp);
//				}
//			}
//		}
//	}
//
//	if (flag)//���Ϊ1��������ʱ���Ŀ��
//	{
//		{
//			{
//				printf("ȷ�ϻ����밴�س�!");
//				for (; hitkey != 13 && hitkey != 27;)
//					hitkey = getch();
//				if (hitkey == 13)
//					printf("�ɹ�!�����������!");
//				n = 0; flag = 0;
//				fp3 = fopen("library.txt", "r");//��ͼ����ļ�
//				k = tjzs();//��ȡͼ����ļ�����
//				for (i = 0; i < k; i++)//��ͼ����ļ����Ƶ�����
//				{
//					fscanf(fp3, "%s%s%s%s%s%d%f", tshuhao, tname, tauthor, tchuban, tkind, &txcl, &tprice);//��ȡ��Ϣ
//					n++;
//					if (n == 1)
//					{
//						lp1 = lp2 = (struct book*)malloc(LEN);//�½�����
//						lhead1 = lp1;
//					}
//					else
//					{
//						lp2->next = lp1;
//						lp2 = lp1;
//						lp1 = (struct book*)malloc(LEN);//�½�����
//					}
//					strcpy(lp1->num, tshuhao);//�������
//					strcpy(lp1->nam, tname);//��������
//					strcpy(lp1->aut, tauthor);//��������
//					strcpy(lp1->pub, tchuban);//���Ƴ�����
//					strcpy(lp1->cat, tkind);//�������
//					lp1->many = txcl; //�����ִ���
//					lp1->price = tprice;//���Ƶ���
//				}
//				if (n == 0)
//				{
//					lhead1 = NULL;
//				}
//				else
//				{
//					lp2->next = lp1;
//					lp1->next = NULL;
//					fclose(fp3);
//				}
//			}
//		}
//		zp1 = lhead1;
//		for (; zp1 != NULL;)
//		{
//			if (!(strcmp(zp1->nam, ttzname)))//Ѱ��������ͬ
//				++(zp1->many);//�ִ�����1
//			zp1 = zp1->next;
//		}
//		fp3 = fopen("library.txt", "w");//���ͼ����ļ�
//		fclose(fp);
//		fp3 = fopen("library.txt", "a");//׷����Ϣ
//		zp1 = lhead1;
//		for (; zp1 != NULL;)//���������ݸ���ͼ����ļ�
//		{
//			fprintf(fp3, "%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",
//				zp1->num, zp1->nam, zp1->aut, zp1->pub, zp1->cat, zp1->many, zp1->price);
//			zp1 = zp1->next;
//		}
//		fclose(fp3);
//		getch();//����
//		jmain();//���ý���ϵͳ
//	}
//	else
//		printf("�����ڴ���Ϣ!�����������!");
//	getch();//����
//	jmain();//���ý���ϵͳ
//}
//
//
//void lljs()//��ʾ�����������
//
//{
//	FILE* fp;
//	int zhenghao = 0, xcl = 0, n = 0, i = 0, j = 0;
//	char mingzi[20] = { '\0' }, riqi[20] = { '\0' }, zname[20] = { '\0' };
//	if ((fp = fopen("reader.txt", "r")) == NULL)//�򿪶����ļ���
//	{
//		system("cls");
//		printf("\n��¼�ļ�������!�����������");
//		getch();
//		jmain();
//	}
//	n = tjdzzs();
//	if (n == 0)
//	{
//		system("cls");
//		printf("\n���κμ�¼!");
//	}
//	fp = fopen("reader.txt", "r");
//	system("cls");
//	printf("\n֤��\t��������\t\t��������\t����\n");
//	for (; !feof(fp);)//����ļ���Ϣ
//	{
//		fscanf(fp, "%d%s%s%s\n ", &zhenghao, mingzi, riqi, zname);
//		printf("\n%-8d%-23s%-18s%-10s\n", zhenghao, mingzi, riqi, zname);
//	}
//	fclose(fp);
//	printf("\n�����������\n");
//	getch();//����
//	jmain();//���ý���ϵͳ
//}
//
//
//void cxjs()//��ѯ����
//{
//	FILE* fp;
//	int jsnum = 0, k = 0, many = 0, m = 0, n = 0;
//
//	char  jsnam[20] = { '\0' }, jstime[20] = { '\0' }, tsnam[20] = { '\0' };
//	char i;
//	char chazhao[20] = { '\0' };
//	if ((fp = fopen("reader.txt", "r")) == NULL)//���ļ�
//	{
//		system("cls");
//		printf("\n��¼�ļ�������!�����������");
//		getch();
//		jmain();
//	}
//	system("cls");
//	printf("������֤�Ż�������ѯ��\n");
//	scanf("%s", chazhao);
//	system("cls");
//	m = tjzs();
//	for (n = 0; n < m; n++)
//	{
//		fscanf(fp, "%d%s%s%s", &jsnum, jsnam, jstime, tsnam);
//		if (!strcmp(chazhao, jsnam) || (atoi(chazhao) == jsnum))
//		{
//			if (k == 0)
//			{
//				printf("��ѯ���:\n\n");
//				printf("\n֤��\t��������\t\t��������\t����\n");
//			}
//			printf("\n%-8d%-23s%-18s%-10s\n", jsnum, jsnam, jstime, tsnam);
//			k++;
//		}
//	}
//	if (k == 0)//�ļ���Ϊ��������޼�¼��������һ��
//	{
//		system("cls");
//		printf("\n�޷��ϼ�¼!\n");
//		getch();
//		jmain();
//	}
//	fclose(fp);//��ѯ����
//	getch();
//	jmain();
//}
//
//
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//
//void lmenu()//��ʾ��¼�˵�
//{
//
//
//	printf("\n\n\t    ��ӭʹ�û�Ա��¼ϵͳ\n\n");
//	printf("**********************************************");
//	printf("\n\n\t\t1.��¼ϵͳ\n\n");
//	printf("\n\n\t\t2.�����˺�\n\n");
//	printf("\n\n\t\t3.�޸�����\n\n");
//	printf("\n\n\t\t4.�˳�ϵͳ\n\n");
//	printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
//	printf("**********************************************");
//	return;
//}
//
//
//void lmain()//��¼���ܺ���
//{
//	void land();
//	void xinjian();
//	char choose;
//	lmenu();
//	scanf(" %c", &choose);
//	switch (choose)//���ܺ���
//	{
//	case'1':
//		land();
//		break;
//	case'2':
//		xinjian();
//		break;
//	case'3':
//		xgmm();
//		break;
//	case'4':
//		system("cls");
//		getch();
//		exit(0);
//		system("cls");
//		break;
//	}
//}
//
//
//
//void xinjian()//�½��˻�����
//{
//	FILE* fp;
//	int zhanghao;
//	char password[20], password1[20];
//	char hit = 0;
//	if ((fp = fopen("land.txt", "r")) == NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
//	{
//		fp = fopen("land.txt", "w");
//		fclose(fp);
//	}
//	system("cls");
//	fp = fopen("land.txt", "a");
//	for (;;)//������������ȷ�ϣ�������ͬ����ȷ��
//	{
//		printf("\n�밴���¸�ʽ�����˻�:\nѧ�� ����\n");
//		printf("������:");
//		scanf("%d %s", &zhanghao, password);
//		printf("�ٴ���������:\n");
//		scanf("%s", password1);
//		if (strcmp(password, password1) == 0)
//		{
//			fprintf(fp, "%d %s\n", zhanghao, password);
//			break;
//		}
//		else
//		{
//			printf("�����������벻һ�£������������س����˳���ESC");
//			hit = getch();
//			if (hit = 27)
//				system("cls");
//			lmain();
//		}
//	}
//	fclose(fp);
//	printf("�����ɹ��������������");
//	getch();
//	system("cls");
//	lmain();
//}
//
//
//
//int match(int m, char a[20])//ƥ�����ݿ��е��˺�����
//{
//	FILE* fp;
//	int n = 0, i = 0;
//	int zhanghao;
//	char password[20];
//
//	if ((fp = fopen("land.txt", "r")) == NULL)//�����ڶ����ļ�
//	{
//		system("cls");
//		printf("\n ��δ�����û�!���½��˻�");
//		getch();
//		system("cls");
//		lmain();
//
//	}
//
//
//	for (; !feof(fp);)
//	{
//		fscanf(fp, "%d%s", &zhanghao, password);
//		if (m == zhanghao)
//		{
//			if (strcmp(a, password) == 0)
//				return 1;
//			else
//			{
//				return -1;
//			}
//		}
//	}
//	return 0;
//}
//
//void land()//�����˻�����ĵ�¼����
//{
//	int zhanghao;
//	char password[20];
//	int i = 2, j, k, n;
//	char hit = 0;
//	system("cls");
//	do
//	{
//		printf("\n�������˺�:\n");
//		scanf("%d", &zhanghao);
//		printf("ȷ�������밲�س������������밴ECS");
//		hit = getch();//��ͣ����i���պ������һ��ָ��
//		for (; hit != 13 && hit != 27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
//		{
//			hit = getch();
//		}
//	} while (hit == 27);
//	printf("\n����������:\n");
//	scanf("%s", password);
//	i = match(zhanghao, password);
//	if (i == 1)
//	{
//		printf("��½�ɹ�!�����������");
//		getch();
//		main1();
//	}
//	else
//	{
//		if (i == -1)
//		{
//			printf("�������!");
//			getch();
//			land();
//		}
//		if (i == 0)
//			printf("�����ڴ��û�");
//		getch();
//		system("cls");
//		lmain();
//	}
//}
//
//void xg(int z, char m[20])//�޸ĺ���
//{
//	FILE* fp;
//	int zhanghao1, n=0, j, k;
//	char mima1[20];
//	struct land* head, * p, * p1, * p2;
//
//	fp = fopen("land.txt", "r");
//	j = tjzs3();
//
//	for (k = 0; k <= j; k++)
//	{
//		fscanf(fp, "%d %s", &zhanghao1, mima1);
//		if (z != zhanghao1)//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
//		{
//			n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
//			if (n == 1)//��������
//			{
//				p1 = p2 = (struct land*)malloc(LEN2);
//				head = p1;
//			}
//			else
//			{
//				p2->next = p1;
//				p2 = p1;
//				p1 = (struct land*)malloc(LEN2);//�½�����
//			}
//			p1->zhanghao = zhanghao1;
//			strcpy(p1->password, mima1);//�����˺�����
//		}
//	}
//	if (n == 0)
//	{
//		head = NULL;
//	}
//	else//������������ʣ��һ������ռ䣬���Է��
//	{
//		p2->next = p1;
//		p1->next = NULL;
//		fclose(fp);
//	}
//	fp = fopen("land.txt", "w");//����ļ���ֻд�򿪣�Ȼ��ر�
//	fclose(fp);
//	fp = fopen("land.txt", "a");//׷���ļ�
//	p = head;
//	for (; p != NULL;)//���������ݸ��ǵ��ļ�
//	{
//		fprintf(fp, "%d %s%\n", p->zhanghao, p->password);
//		p = p->next;
//	}
//	fprintf(fp, "%d %s\n", z, m);
//	fclose(fp);
//	system("cls");
//
//}
//
//
//
//void xgmm()//�޸�����
//{
//
//	FILE* fp;
//	int zh = 0, k = 0, many = 0, m = 0, n = 0;
//	int chazhao, hit;
//	char mima[20] = { '\0' }, password1[20] = { '\0' };
//	char  mm[20] = { '\0' };
//	char i;
//
//	if ((fp = fopen("land.txt", "r")) == NULL)//���ļ�
//	{
//		system("cls");
//		printf("\n��¼�ļ�������!�����������");
//		getch();
//		system("cls");
//		lmain();
//	}
//	system("cls");
//	printf("����������ʺź;����룺\n");
//	scanf("%d %s", &chazhao, mima);
//	m = tjzs3();
//	for (n = 0; n <= m; n++)
//	{
//		fscanf(fp, "%d %s", &zh, mm);
//		if (zh == chazhao)
//		{
//			if (!strcmp(mm, mima))
//			{
//				printf("�������µ�����");
//				scanf("%s", mima);
//				printf("�ٴ���������:\n");
//				scanf("%s", password1);
//				if (strcmp(mima, password1) == 0)
//				{
//					xg(chazhao, mima);
//					getch();
//					lmain();
//					system("cls");
//				}
//				else
//				{
//					printf("�����������벻һ��,��������˳�");
//					hit = getch();
//					system("cls");
//					lmain();
//
//				}
//			}
//			else
//			{
//				printf("��������󣬰���������أ�");
//				getch();
//				system("cls");
//				lmain();
//
//			}
//
//		}
//	}
//	printf("�����ڴ��˺ţ������������");
//	fclose(fp);//�޸Ľ���
//	getch();
//	system("cls");
//	lmain();
//}
//
//
//
//int main()
//{
//	system("color 1F");
//	lmain();
//	return 0;
//}
//
