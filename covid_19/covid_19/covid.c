#define _CRT_SECURE_NO_WARNINGS	/// Visual Studio
#include <stdio.h>
#include "covid.h"


// �ڷγ� ���� ����ü �迭: ���� Ȯ���� ����� ��ġ�� ġ����
struct covid list[] = {
	{ "�̱�", 87246309, 1035675,  83014518, 3196116 },
	{ "�ε�", 43213435, 524757, 42648308, 40370 },
	{ "�����", 31417341,668007,  30178187, 571147 },
	{ "������", 29753370, 148710, 29206240, 398420 },
	{ "����", 26802782, 140115, 25870800, 791867 },
	{ "����", 22382352, 179217, 22019878, 183257 },
	{ "���þ�", 18373184, 379955, 17791081, 202148 },
	{ "���ѹα�", 18218078, 24351, 17969644, 224083 },
	{ "��Ż����", 17611607, 167305, 16820881, 623421 },
	{ "��Ű", 15072747, 98965, 14971256, 2526 },
	{ "������", 12478994, 107108, 11939322, 432564 },
	{ "��Ʈ��", 10729681, 43082, 9540598, 1146001 },
	{ "�Ƹ���Ƽ��",  9276618, 128973, 8895999, 251646 },
	{ "�Ϻ�",  9023920, 30866, 8825014, 168040 },
	{ "�״�����", 8101839, 22332, 8042086, 37421 } };

void nation_infomation()		// ���ϴ� ������ ��ü ������ ���� �Լ�
{
	int i, n;

	printf("\n���ϴ� ���� ���ÿ�.\n");

	for (i = 0; i < N; i++)
		printf("%2d. %s\n", i + 1, list[i].nation);
	printf("����>> ");
	scanf("%d", &n);

	if (n<1 || n > N)
		return;

	printf("\n");
	printf("---------------------\n");
	printf("��  �� : %s\n", list[n - 1].nation);
	printf("Ȯ���� : %8d\n", list[n - 1].coronic);
	printf("����� : %8d\n", list[n	 - 1].dead);
	printf("��ġ�� : %8d\n", list[n - 1].complete_healer);
	printf("ġ���� : %8d\n", list[n - 1].treatment);
	printf("---------------------\n");

	system("pause");
}

void nation_infomation_2()		// ���ϴ� ������ Ư�� ������ ���� �Լ�
{
	int i, n, n2;

	printf("\n���ϴ� ���� ���ÿ�.\n");

	for (i = 0; i < N; i++)
		printf("%2d. %s\n", i + 1, list[i].nation);
	printf("����>> ");
	scanf("%d", &n);

	if (n<1 || n > N)
		return;

	printf("\n\n");
	printf("���ϴ� ������ ���ÿ�.\n\n");
	printf("1. Ȯ����\n");
	printf("2. �����\n");
	printf("3. ��ġ��\n");
	printf("4. ġ����\n");
	printf("����>> ");
	scanf("%d", &n2);


	printf("\n");
	printf("---------------------\n");
	printf("��  �� : %s\n", list[n - 1].nation);
	if (n2 == 1)
		printf("Ȯ���� : %8d\n", list[n - 1].coronic);
	if (n2 == 2)
		printf("����� : %8d\n", list[n - 1].dead);
	if (n2 == 3)
		printf("��ġ�� : %8d\n", list[n - 1].complete_healer);
	if (n2 == 4)
		printf("ġ���� : %8d\n", list[n - 1].treatment);
	printf("---------------------\n");
	printf("\n");

	system("pause");
}


void total_infomation()			// ���� 15�� ���� ��ü ������ ���� �Լ�
{
	int i;
	struct covid* p = &list[0];		// ����ü ������ ����

	printf("Ȯ���� ���� ���� 15�� ������ ������ �˷��帳�ϴ�.\n");
	printf("6�� 12�� 00:00 ����\n");

	printf("\n");
	printf("���� Ȯ���� ����� ��ġ�� ġ����\n");
	printf("-----------------------------------------------------\n");
	for (i = 0; i < N; i++)
	{
		printf("%-10s %8d %8d %8d %8d\n",
			list[i].nation, p->coronic, p->dead, p->complete_healer, p->treatment);
		p++;	 // ����ü �����͸� 1 ����
	}
	printf("\n");

	system("pause");
}


void save(char *filename)		// ���Ͽ� �����ϴ� �Լ�
{
	int i;
	FILE* fp;

	if ((fp = fopen(filename, "wt")) == NULL)
	{
		printf("������ �� �����ϴ�.");
		return;
	}

	fprintf(fp, "Ȯ���� ���� ���� 15�� ������ ������ �˷��帳�ϴ�.\n");
	fprintf(fp, "6�� 12�� 00:00 ����\n");

	fprintf(fp, "\n");
	fprintf(fp, "����           Ȯ����	  �����     ��ġ��    ġ����\n");
	fprintf(fp, "-----------------------------------------------------\n");
	for (i = 0; i < N; i++)
		fprintf(fp, "%-10s   %8d   %8d   %8d  %8d\n",
			list[i].nation, list[i].coronic, list[i].dead, list[i].complete_healer, list[i].treatment);
	fprintf(fp, "\n");
	fclose(fp);

	printf("\n����Ǿ����ϴ�.\n\n");
	system("pause");
}
