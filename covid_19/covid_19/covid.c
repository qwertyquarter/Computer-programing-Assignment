#define _CRT_SECURE_NO_WARNINGS	/// Visual Studio
#include <stdio.h>
#include "covid.h"


// 코로나 관련 구조체 배열: 국가 확진자 사망자 완치자 치료중
struct covid list[] = {
	{ "미국", 87246309, 1035675,  83014518, 3196116 },
	{ "인도", 43213435, 524757, 42648308, 40370 },
	{ "브라질", 31417341,668007,  30178187, 571147 },
	{ "프랑스", 29753370, 148710, 29206240, 398420 },
	{ "독일", 26802782, 140115, 25870800, 791867 },
	{ "영국", 22382352, 179217, 22019878, 183257 },
	{ "러시아", 18373184, 379955, 17791081, 202148 },
	{ "대한민국", 18218078, 24351, 17969644, 224083 },
	{ "이탈리아", 17611607, 167305, 16820881, 623421 },
	{ "터키", 15072747, 98965, 14971256, 2526 },
	{ "스페인", 12478994, 107108, 11939322, 432564 },
	{ "베트남", 10729681, 43082, 9540598, 1146001 },
	{ "아르헨티나",  9276618, 128973, 8895999, 251646 },
	{ "일본",  9023920, 30866, 8825014, 168040 },
	{ "네덜란드", 8101839, 22332, 8042086, 37421 } };

void nation_infomation()		// 원하는 국가의 전체 정보에 대한 함수
{
	int i, n;

	printf("\n원하는 나라를 고르시오.\n");

	for (i = 0; i < N; i++)
		printf("%2d. %s\n", i + 1, list[i].nation);
	printf("선택>> ");
	scanf("%d", &n);

	if (n<1 || n > N)
		return;

	printf("\n");
	printf("---------------------\n");
	printf("국  가 : %s\n", list[n - 1].nation);
	printf("확진자 : %8d\n", list[n - 1].coronic);
	printf("사망자 : %8d\n", list[n	 - 1].dead);
	printf("완치자 : %8d\n", list[n - 1].complete_healer);
	printf("치료중 : %8d\n", list[n - 1].treatment);
	printf("---------------------\n");

	system("pause");
}

void nation_infomation_2()		// 원하는 국가의 특정 정보에 대한 함수
{
	int i, n, n2;

	printf("\n원하는 나라를 고르시오.\n");

	for (i = 0; i < N; i++)
		printf("%2d. %s\n", i + 1, list[i].nation);
	printf("선택>> ");
	scanf("%d", &n);

	if (n<1 || n > N)
		return;

	printf("\n\n");
	printf("원하는 정보를 고르시오.\n\n");
	printf("1. 확진자\n");
	printf("2. 사망자\n");
	printf("3. 완치자\n");
	printf("4. 치료중\n");
	printf("선택>> ");
	scanf("%d", &n2);


	printf("\n");
	printf("---------------------\n");
	printf("국  가 : %s\n", list[n - 1].nation);
	if (n2 == 1)
		printf("확진자 : %8d\n", list[n - 1].coronic);
	if (n2 == 2)
		printf("사망자 : %8d\n", list[n - 1].dead);
	if (n2 == 3)
		printf("완치자 : %8d\n", list[n - 1].complete_healer);
	if (n2 == 4)
		printf("치료중 : %8d\n", list[n - 1].treatment);
	printf("---------------------\n");
	printf("\n");

	system("pause");
}


void total_infomation()			// 상위 15개 국의 전체 정보에 대한 함수
{
	int i;
	struct covid* p = &list[0];		// 구조체 포인터 변수

	printf("확진자 기준 상위 15개 국가의 정보를 알려드립니다.\n");
	printf("6월 12일 00:00 기준\n");

	printf("\n");
	printf("국가 확진자 사망자 완치자 치료중\n");
	printf("-----------------------------------------------------\n");
	for (i = 0; i < N; i++)
	{
		printf("%-10s %8d %8d %8d %8d\n",
			list[i].nation, p->coronic, p->dead, p->complete_healer, p->treatment);
		p++;	 // 구조체 포인터를 1 증가
	}
	printf("\n");

	system("pause");
}


void save(char *filename)		// 파일에 저장하는 함수
{
	int i;
	FILE* fp;

	if ((fp = fopen(filename, "wt")) == NULL)
	{
		printf("저장할 수 없습니다.");
		return;
	}

	fprintf(fp, "확진자 기준 상위 15개 국가의 정보를 알려드립니다.\n");
	fprintf(fp, "6월 12일 00:00 기준\n");

	fprintf(fp, "\n");
	fprintf(fp, "국가           확진자	  사망자     완치자    치료중\n");
	fprintf(fp, "-----------------------------------------------------\n");
	for (i = 0; i < N; i++)
		fprintf(fp, "%-10s   %8d   %8d   %8d  %8d\n",
			list[i].nation, list[i].coronic, list[i].dead, list[i].complete_healer, list[i].treatment);
	fprintf(fp, "\n");
	fclose(fp);

	printf("\n저장되었습니다.\n\n");
	system("pause");
}
