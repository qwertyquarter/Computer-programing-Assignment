// covid_19.c : 코로나 정보 국가별 통계

#define _CRT_SECURE_NO_WARNINGS		// Visual Studio
#include <stdio.h>
#include <string.h>
#include "covid.h"


char filename[] = "covid.txt";		// 저장할 파일명

int main(void)
{
	int m;

	while (1)
	{
		system("cls");		// 전체 화면을 지움(초기화)

		printf("원하는 카테고리를 고르시오.\n\n");		// 메인 메뉴
		printf("1. 원하는 국가의 전체 정보\n");
		printf("2. 원하는 국가의 특정 정보\n");
		printf("3. 상위 15개 국의 전체 정보\n");
		printf("4. 저장(전체 정보)\n");
		printf("5. 종료\n");
		printf("------------------\n");
		printf("선택>> ");

		scanf("%d", &m);
		if (m == 5) break;			// 종료

		switch (m)
		{
		case 1:
			nation_infomation();	//  원하는 국가의 전체 정보
			break;
		case 2:
			nation_infomation_2();	// 원하는 국가의 특정 정보
			break;
		case 3:
			total_infomation();		// 상위 15개 국의 전체 정보
			break;
		case 4:
			save(filename);			// 파일에 저장
		}

	}
}
