// 코로나 관련 구조체: 국가 확진자 사망자 완치자 치료중
struct covid {
	char nation[20];			// 국가
	int coronic;				// 확진자
	int dead;					// 사망자
	int complete_healer;		// 완치자
	int treatment;				//치료중
};

#define	N	15	// 나라 수

void nation_infomation();		// 원하는 국가의 전체 정보
void nation_infomation_2();		// 원하는 국가의 특정 정보
void total_infomation();		// 상위 15개 국의 전체 정보
void save(char *filename);		// 파일에 저장
