// �ڷγ� ���� ����ü: ���� Ȯ���� ����� ��ġ�� ġ����
struct covid {
	char nation[20];			// ����
	int coronic;				// Ȯ����
	int dead;					// �����
	int complete_healer;		// ��ġ��
	int treatment;				//ġ����
};

#define	N	15	// ���� ��

void nation_infomation();		// ���ϴ� ������ ��ü ����
void nation_infomation_2();		// ���ϴ� ������ Ư�� ����
void total_infomation();		// ���� 15�� ���� ��ü ����
void save(char *filename);		// ���Ͽ� ����
