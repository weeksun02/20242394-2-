#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <time.h>

#define LEN_MIN 15
#define LEN_MAX 50
#define STM_MIN 0
#define STM_MAX 5
#define PROB_MIN 10
#define PROB_MAX 90
#define AGGRO_MIN 0
#define AGGRO_MAX 9
//������ �̵�����
#define MOVE_LEFT 1
#define MOVE_STAY 0
//������ ���ݴ��
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
//������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2
//void intro();
void enter1();
void enter2();
void enter3();
void busanhang2();
void busanhang3();
void busanhang31();
void sangtea();
void sangtea2();
void moveall();
void sangtea3();
void start();
void start2();
void ask1();
void sangtea4();
int magro = 1;
int sagro = 1;
int moving = 0;
int stamina=6;
int length = 0;
int cprob = 0;
int zprob = 0;
int c = 0;
int z = 0;
int m = 0;
int j = 0;
int space = 0;
int sspace = 0;
int ssspace = 0;
int percent = 0;
char train[50];
char ctizen[50];
char zombie[50];
char ctizom[50];
int main(void) {
	srand((unsigned int)time(NULL));
	z = length - 3;
	c = length - 6;
	m = length - 2;
	space = c - 1;
	sspace = m - z;

	//intro();
	enter1();
	enter2();
	enter3();



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
start();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
while (1) {
	percent = rand() % 100 + 1;
		

	moveall();
	ask1();
	start2();
	
	Sleep(4000); ///sleep���ֱ�!!!
	
	j++;
}

return 0;
}

void stop() {
	if (c == 1) {
		printf("\nSUCCESS!\ncitizen(s) escaped to the next train\n");
		exit(0);
	}
	if (sspace == 0) {
		printf("\nGAME OVER!\nCitizen(s) has(have) been attacked by a zombi\n");
		exit(0);
	}
}
void perccent() {
	if (percent < (100 - cprob)) {
		c -= 1;
		sagro += 1;
	}
	else {
		sagro -= 1;
	}
	if (sagro > magro) {
		if (j % 2 == 0) {
			z -= 1;
			ssspace += 1;
			
		}
	}
	else if (sagro < magro) {
		if (j % 2 == 0) {
			z -= 1;
			ssspace += 1;

		}
	}

	if (sagro < AGGRO_MIN) {
		sagro = AGGRO_MIN;
	}
	else if (sagro > AGGRO_MAX) {
		sagro = AGGRO_MAX;
	}
}
void cctizen() {
	
	for (int i = 0; i < c - 1; i++) {
		ctizen[i] = ' ';
	}
	for (int i = 0; i < c - 1; i++) {
		printf("%c", ctizen[i]);
	}
}
void zzombie() {
	
	for (int i = 0; i < ssspace; i++) {
		zombie[i] = ' ';
	}
	for (int i = 0; i < ssspace; i++) {
		printf("%c", zombie[i]);
	}
}
void cctizzom() {
	sspace = z - c-1;
	for (int i = 0; i < sspace; i++) {
		ctizom[i] = ' ';
	}
	for (int i = 0; i < sspace; i++) {
		printf("%c", ctizom[i]);
	}
}
void start2() {
	printf("#");
	cctizen();
	printf("c");
	cctizzom();
	printf("z");
	zzombie();
	printf("m");
	printf("#");

}
void busanhang2() { //�ι�° �� ����ϴ� �Լ�
	
	perccent();
	printf("#");
	cctizen();
	printf("c");
	cctizzom();
	printf("z");
	zzombie();
	printf("m");
	printf("#");

}

void busanhang3() { //������ �ʴ� ����
	for (int i = 1; i <= length; i++) {
		train[i] = '#';
	}
}
void busanhang31() {
	for (int i = 1; i <= length; i++) {
		printf("%c", train[i]);
	}
}
void sangtea() {
	if (percent < (100 - cprob)) { //�ùλ������
		printf("citizen : stay %d -> %d(agro:%d)\n", c + 1, c,sagro);
	}
	else {
		printf("citizen : stay %d(agro:%d)\n", c,sagro);
	}
	if (percent < zprob) { 	//����������-����������
		sangtea2();
	}
	else { //����������-���ڸ��϶�
		sangtea3();
	}
}
void sangtea3() {
	if (j % 2 == 0) {
		printf("zombie : stay %d\n",z);
	}
	else {
		printf("zombie : stay %d (Can not move)\n", z);
	}
}
void sangtea2() {
	if (j % 2 == 0) {
		printf("zombie : stay %d -> %d\n", z + 1, z);
	}
	else {
		printf("zombie : stay %d (Can not move)\n", z);
	}
}
void sangtea4() {
	
		printf("madongseok: stay %d(aggro: %d,stamina: %d",m,magro,stamina);
	
}
void ask1() {
	int moving = 0;
	printf("madongseok move(0:stay, 1:left)>>>");
	scanf_s("%d ", &moving);
	if (moving == MOVE_LEFT) {
		m -= 1;
		ssspace -= 1;
		magro += 1;

	}
	else if (moving == MOVE_STAY) {
		magro -= 1;
	}
	if (magro < AGGRO_MIN) {
		magro = AGGRO_MIN;
	}
	else if (magro > AGGRO_MAX) {
		magro = AGGRO_MAX;
	}
	
}
void moveall() {
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	busanhang2();
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	sangtea();
	stop();
}
void start() {
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	start2();
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
}
void intro() {
printf("�� ");
Sleep(1000);
printf("��");
Sleep(1000);
printf("��");
Sleep(1000);
printf("��");
Sleep(1000);
printf("��");
Sleep(1000);
printf("~!\n");
Sleep(1000);
printf("=====================\n");
printf("= �λ��� GAME START =\n");
printf("=====================\n");
Sleep(2000);
}
void enter1() {

	while (LEN_MIN > length || LEN_MAX < length) {
		printf("train length(15~50) >>  ");
		scanf_s("%d", &length);
	}	
}
void enter2() {
	
	while (STM_MIN > stamina || stamina > STM_MAX) {
		printf("madongseok stamina(0~5) >> ");
		scanf_s("%d", &stamina);
	}
}
void enter3() {
	while (PROB_MIN > cprob || PROB_MAX < cprob) {
		printf("percentile probability citizen'cp'(10~90) >> ");
		scanf_s("%d", &cprob);
	}
	
}