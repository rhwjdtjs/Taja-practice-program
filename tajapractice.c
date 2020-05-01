#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

#define wordmax 103//´Ü¾îÀÇ °³¼ö
#define wordtime 23000//´Ü¾î°¡ ¶ß´Â ¼Óµµ

static int tasu;
time_t tasu_startTime = 0, tasu_endTime = 0;
int tasucount(int randint)
{
	double gap=1;

	tasu_endTime = clock();
	
	gap=(tasu_endTime - tasu_startTime)/1000;
	if (gap > 0)
	{
		tasu = LT_count_answers(randint) / gap * 60.0;
	}
	return tasu;
}

time_t startTime = 0, endTime = 0;// °ÔÀÓ ½Ã°£ Á¦ÇÑ

int gap;

void countdown(int t) {
	printf("%d", t); Sleep(1);
	int i;
	for (i = t - 1; i >= 1; i--) {
		printf("\b%d", i);
		Sleep(1);
	}
	printf("\b ");
}

int main(); //¸ÞÀÎ ÇÔ¼ö·Î µ¹¾Æ°¡±â À§ÇØ

void positionT() {
	srand(time(NULL));
	int caps = rand() % 2, alpha = rand() % 26;
	int answer = (caps ? 65 : 95) + alpha, input;
	int prog = 1, miss = 0, hit = 0;
	double acc = 0;
	while (prog <= 20) {
		if (hit > 0)
			acc = (hit - miss) / (double)hit;
		system("clear");
		printf("***********\n");
		printf("     %c     \n", answer);
		printf("***********\n");
		printf("%d¹øÂ° ÀÔ·Â\n", hit + 1);
		printf("ÁøÇàµµ:%d%%\n¿ÀÅ¸¼ö:%d\nÁ¤È®µµ:%.2f%%\n", prog / 20 * 100, miss, acc * 100);
		input = getch();
		if (input == answer) {
			prog++;
			hit++;
			caps = rand() % 2;
			alpha = rand() % 26;
			answer = (caps ? 65 : 95) + alpha, input;
		}
		else if (input == 27) {
			system("clear");
			main();
		}
		else {
			miss++;
			hit++;
		}
	}
	system("clear");
	printf("ÀüÃ¼Å¸¼ö:%d  , ¿ÀÅ¸¼ö:%d , Á¤È®µµ:%.2f%%\n", hit, miss, acc * 100);
	while (1) {
		input = getch();
		if (input == 13) {
			system("clear");
			main();
		}
	}
}

void wordT() {
	//³¹¸» ¿¬½À ÄÚµå
}


char short_para[30][200] = { "To marry is to halve your rights and double your duties.","He makes no friend who never made a foe.","Common sense is the collection of prejudices acquired by age 18.","We thus drift toward unparalleled catastrophes.","Nothing is more despicable than respect based on fear.","Television has proved that people will look at anything rather than each other.","It is only with the heart that one can see rightly.","Love does not consist in gazing at each other, but in looking together in the same direction.","Business? It's quite simple. It's other people's money.","I would as soon leave my son a curse as the almighty dollar.","A great writer is, so to speak, a second government in his country.","You don't live in a world all alone. Your brothers are here too.","A hungry man is not a free man.","To know is nothing at all; to imagine is everything.","Truth is generally the best vindication against slander.","It is my intention to present - through the medium of photography","America is a large, friendly dog in a very small room.","The secret of business is to know something that nobody else knows.","One man with courage makes a majority.","Television has a real problem. They have no page two.","Man is born to live, not to prepare for life. Life itself,","Like all great travellers, I have seen more than I remember, and remember more than I have seen.","The magic of first love is our ignorance that it can ever end.","When men are employed, they are best contented.","When she finally stopped conforming to the conventional picture","Anything you're good at contributes to happiness.","Accurst be he that first invented war.","Since a politician never believes what he says, he is surprised when others believe him.","A woman means by unselfishness chiefly taking trouble for others.","Freedom is a system based on courage." };
char short_input[5][200] = { 0 };
int st_length[5] = { 0, };
int corcnt = 0;

void ST_print(int randint, int T, int save) {
	
	int son = 0;
	for (int i = 0; i <= strlen(short_input[T]); i++) {
		if ((short_para[randint][i] == short_input[T][i]) && short_input[T][i] != '\0')
			son++;
	}
	if (save == 1) {
		corcnt += son;
	}
	int mother = 0;
	for (int i = 0; i <= T; i++) {
		mother += strlen(short_input[i]);
	}
	double gap = 1;

	tasu_endTime = clock();

	gap = (tasu_endTime - tasu_startTime) / 1000;
	if (gap > 0)
	{
		tasu = (corcnt + son) / gap * 60.0;
	}
	system("cls");
	//ÁøÇàµµ, Á¤È®µµ, ÃÖ°íÅ¸¼ö, ÇöÀçÅ¸¼ö Ãâ·Â 
	printf("Á¤È®µµ : %.0f%% ÇöÀçÅ¸¼ö : %d\n", (double)(corcnt + son) / mother * 100, tasu);
	//Á¤´ä Ãâ·Â  
	printf("%s\n\n", short_para[randint]);
	//Áö±Ý±îÁö ÀÔ·ÂµÈ °Í Ãâ·Â
	printf("%s", short_input[T]);

}

void SparagraphT() {
	int T = 0;
	srand(time(NULL)); //½Ãµå ÃÊ±âÈ­
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 200; j++)
			short_input[i][j] = 0; //ÀÔ·Â ¹è¿­ ÃÊ±âÈ­  

	while (T < 5) {
		int randint = rand() % 30, c /*ÀÔ·Â ¹Þ´Â º¯¼ö(c)*/; //·£´ý ÁöÁ¤
		for (int i = 0; i < 5; i++)
			st_length[i] = strlen(short_para[randint]) - 1;//1ºÎÅÍ ¼¾´Ù(±æÀÌ) 
		ST_print(randint, T, 0);
		while (strlen(short_input[T]) <= st_length[T]) {
			if ((c = getch()) == 27) { //ESC Å°  
				system("cls");
				main();
			}
			else if (c == '\b') { //¹é½ºÆäÀÌ½º
				int len = strlen(short_input[T]);
				if (len > 0) {
					short_input[T][len] = NULL;
					short_input[T][len - 1] = NULL;
					ST_print(randint, T, 0);
				}
			}
			else {
				short_input[T][strlen(short_input[T])] = c;
				ST_print(randint, T, 0);
			}
		}
		ST_print(randint, T, 1);
		T++;
	}
}

char long_para[4][10][100] = { "The Middle\n","Take a seat right over there, sat on the stairs\n","Stay or leave, the cabinets are bare and I'm unaware\n","Of just how we got into this mess, got so aggressive\n","I know we meant all good intentions\n", \
"So pull me closer\n","Why don't you pull me close?\n","Why don't you come on over?\n","I can't just let you go\n","Oh baby, why don't you just meet me in the middle?\n", \

"Faint\n","I am a little bit of loneliness, a little bit of disregard\n","Handful of complaints but I can't help the fact\n","That everyone can see these scars\n","I am what I want you to want, what I want you to feel\n", \
"But it's like no matter what I do, I can't convince you\n","To just believe this is real\n","So I, let go watching you turn your back like you always do\n","Face away and pretend I'm not\n","But I'll be here 'cause you're all that I've got\n", \

"Wolves\n","In your eyes, there's a heavy blue\n","One to love and one to lose\n","Sweet divide, a heavy truth\n","Water or wine, don't make me choose\n", \
"I wanna feel the way that we did that summer night\n","Drunk on a feeling, alone with the stars in the sky\n","I've been running through the jungle\n","I've been running with the wolves\n","To get to you, to get to you\n", \

"Butterflies And Hurricanes\n","Change everything you are\n","And everything you were\n","Your number has been called\n","Fights and battles have begun\n", \
"Revenge will surely come\n"," Your hard times are ahead\n","Best, You've got to be the best\n","You've got to change the world\n","And use this chance to be heard\n" };
char long_input[10][100] = { 0 };
int LT_length[10] = { 0 };
int LT_ln = 0, LT_col = 0;

int LT_count_answers(int randint) {
	int corcnt = 0;
	for (int i = 0; i <= LT_ln; i++)
		for (int j = 0; j <= LT_length[i]; j++)
			if (long_para[randint][i][j] == long_input[i][j] && long_input[i][j] != '\n' && long_input[i][j] != '\0')
				corcnt++;
	return corcnt;
}

int LT_count_inputs() {
	int cnt = 0;
	for (int i = 0; i <= LT_ln; i++)
		for (int j = 0; j <= LT_length[i]; j++)
			if (long_input[i][j] != '\n' && long_input[i][j] != '\0')
				cnt++;
	return cnt;
}

void LT_print(int randint, int ln, int col) {
	system("cls");
	//printf("%d %d\n", LT_ln, LT_col); //Çö À§Ä¡ Ã¼Å©(µð¹ö±ë) 
	//Á¤È®µµ, ÇöÀçÅ¸¼ö Ãâ·Â
	printf("Á¤È®µµ : %.0f%% ÇöÀçÅ¸¼ö : %d\n", (float)LT_count_answers(randint) / LT_count_inputs() * 100, tasucount(randint));
	//Á¤´ä Ãâ·Â  
	if (ln < 5) {
		for (int i = 0; i < 5; i++)
		
			printf("%s\n%s\n", long_para[randint][i], long_input[i]);
			printf("\n");
		

	}
	else {
		for (int i = 5; i < 10; i++)
		{
			printf("%s\n%s\n", long_para[randint][i], long_input[i]);
			printf("\n");
		}
	}
	//Áö±Ý±îÁö ÀÔ·ÂµÈ °Í Ãâ·Â
	
}
int main(); //¸ÞÀÎ ÇÔ¼ö·Î µ¹¾Æ°¡±â À§ÇØ 

void LparagraphT() {
	srand(time(NULL)); //½Ãµå ÃÊ±âÈ­
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 100; j++)
			long_input[i][j] = 0; //ÀÔ·Â ¹è¿­ ÃÊ±âÈ­ 
	LT_ln = 0, LT_col = 0; //Çà,¿­ ÃÊ±âÈ­ 
	int randint = rand() % 4, c; //·£´ý ÁöÁ¤ 
					 //°¢ ÁÙÀÇ ±ÛÀÚ¼ö ¼À 
	for (int i = 0; i < 10; i++)
		LT_length[i] = strlen(long_para[randint][i]) - 1;//1ºÎÅÍ ¼¾´Ù(±æÀÌ) 
	LT_print(randint, LT_ln, LT_col);
	while (LT_ln < 10) {
		if ((c = getch()) == 27) { //ESC Å°  
			system("cls");
			main();
		}
		else if (c == '\b') { //¹é½ºÆäÀÌ½º
			if (LT_col > 0 && LT_ln > 0) {
				long_input[LT_ln][LT_col - 1] = 0;
				LT_col--;
			}
			else if (LT_col == 0 && LT_ln > 0) {
				long_input[LT_ln][LT_col - 1] = 0;
				LT_ln--;
				LT_col = LT_length[LT_ln] - 1;
				long_input[LT_ln][LT_col] = 0;
			}
			else if (LT_col > 0 && LT_ln == 0) {
				long_input[LT_ln][LT_col - 1] = 0;
				LT_col--;
			}
			LT_print(randint, LT_ln, LT_col);
		}
		else {
			if (LT_col > LT_length[LT_ln] - 2 && LT_ln <= 10) {
				long_input[LT_ln][LT_col] = c;
				long_input[LT_ln][LT_col + 1] = '\n';
				LT_col = 0;
				LT_ln++;
			}
			else if (LT_col < LT_length[LT_ln] && LT_ln <= 10) {
				long_input[LT_ln][LT_col] = c;
				LT_col++;
			}
			LT_print(randint, LT_ln, LT_col);
		}
	}
}

void delay(clock_t n)

{
	clock_t start = clock();
	while (clock() - start < 1000);

}

void gotoxy(int x, int y)//Ä¿¼­ À§Ä¡ Á¶Á¤ ÇÔ¼ö

{

	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



void help();// µµ¿ò¸»

void gamemain();// °ÔÀÓ¸ÞÀÎ

void printword();//´Ü¾î¶ß°Ô ÇØÁÖ´Â ÇÔ¼ö

void scanword();//´Ü¾î¸¦ ÀÔ·Â ¹Þ´Â ÇÔ¼ö

void design();//°ÔÀÓ µðÀÚÀÎ

void design2();

void start();//°ÔÀÓ ½ÃÀÛ ÃÊ±â È­¸é

void bestscore();//ÃÖ°íÁ¡¼ö °»½Å

void removeCursor();// printf¿¡¼­ ´Ü¾î¸¦ ¶ß°ÔÇÒ¶§ Ä¿¼­ Á¦°Å



char word[256][256] = { "dog", "cat", "bottle", "phone", "robot", "green", "elephant", "include", "sky", "game", "hyomin", "jaemin", "max",//´Ü¾î DB

"knife", "glass", "class", "art", "smart", "bell", "carry", "climb", "between", "blow", "album", "ago", "among", "animal", "any", "box",

"and", "board", "body", "child", "classmate", "city", "boy", "bridge", "clean",

"club", "coat", "bright", "coin", "chopstick", "coffee", "cold", "chance", "chalk", "chair", "cheap", "blue",

"before", "bowl", "aunt", "as", "away", "bicycle", "church", "card", "hold",

"chose", "come", "drink", "give", "get", "hurt", "lay","had", "feed", "lend", "met", "wsing", "throw", "wet", "tell",

"set", "wind", "wear", "write", "spend", "stand", "worn", "win", "sweep", "account", "achieve", "across", "accept", "above", "ability", "abuse",

"abnormal", "absurd", "acceptance", "according", "absent", "nation", "past", "value", "though", "person", "machine", "stand", "null" };

int wordi[250];//ÇÑ ¹ø¶á ´Ü¾îµéÀº ¾È¶ß°Ô ÇØÁÖ±â À§ÇØ ¸¸µé¾î³ð

int x, y;// gotoxy ÀÇ x°ª°ú y°ª

int i;//´Ü¾î ¼ö

int j, k;

int a;//´Ü¾î ¼ö ¿Í °°Àº ¼ö º¯¼ö

int s;//kbhit

int c;//¹Ýº¹¹®¹è¿­

int x2, y2;// x,y°ªÀ» ´Ù½Ã ºÒ·¯¿Ã ¶§ º¯¼ö

int g;

int score1 = 0;//Á¡¼ö

int h;//ÃÊ±âÈ­¸é¿¡¼­ ÀÔ·Â ¹ÞÀ»¶§ º¯¼ö

int f;// »ö±ò

int f2;// »ö±ò °ªÀ» ´Ù½Ã ºÒ·¯¿Ã¶§ º¯¼ö

int sword;

int level = 1;

int bestsc = 0;

char scan[50];

char remem[256][3] = { 0 };//



int main() {

	srand((unsigned)time(NULL));

	system("mode con cols=120 lines=30");

	design();


	Sleep(1500);

	gotoxy(60, 9);



	removeCursor();

	start();

	while (1) {

		gotoxy(45, 24);

		scanf("%d", &h);

		gotoxy(45, 24);



		switch (h)

		{
		case 1: tasu_startTime = clock();
			LparagraphT(); 
			break;
		case 2: countdown(5);
			tasu_startTime = clock();
			SparagraphT();
			break;
		case 3: score1 = 0; startTime = clock(); gamemain(); gap = 0; break;
		case 4: help(); break;
		case 5: bestscore(); break;
		case 6:
			system("cls"); design(); gotoxy(25, 14);    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("        ¼ö°íÇÏ¼Ì½À´Ï´Ù.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); return 0; break;
		default:
			printf("¿Ã¹Ù¸¥ Å°°¡ ¾Æ´Õ´Ï´Ù!");

			break;
		}

	}



}









void design() { //µðÀÚÀÎ ºÒ·¯¿À´Â ÇÔ¼ö

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("|¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬|\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬|\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬|");








}

void design2() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("mode con cols=90 lines=35");
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦­                                 ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");

}
void help() {// µµ¿ò¸» ¸Þ´º ºÒ·¯¿À°Ô ÇØÁÖ´Â ÇÔ¼ö

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	system("cls");

	design();

	gotoxy(30, 7);

	printf("20194032 °íÁ¤¼± 20194033 ÀÌÁö¿¬ Á¦ÀÛ\n");

	gotoxy(20, 9);

	printf("¡¤ È­¸é¿¡ ¶ß´Â ±ÛÀÚµéÀ» ºü¸£°Ô ¹Þ¾Æ¾²¼¼¿ä\n");

	gotoxy(20, 11);

	printf("¡¤ »ö¸¶´Ù Á¡¼ö ¹èÁ¡ÀÌ ´Ù¸¨´Ï´Ù!");

	gotoxy(17, 12);

	printf("( ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

	printf("ÀÌ »ö : 150Á¡ ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

	printf("ÀÌ »ö : 200Á¡ ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

	printf("ÀÌ »ö : 250Á¡ ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	printf("ÀÌ »ö : 300Á¡ ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf(" )");

	gotoxy(20, 14);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("¡¤ 30ÃÊ µ¿¾È °ÔÀÓÀÌ ÁøÇàµË´Ï´Ù!! ³¡³ª¸é ÀÚµ¿À¸·Î Á¾·áµË´Ï´Ù.");

	gotoxy(20, 15);

	printf("¡¤ ÃÖ°íÁ¡¼ö°¡ ÀúÀåµË´Ï´Ù. ¸ÞÀÎ¸Þ´º 3. Á¡¼öº¸±â¿¡¼­ È®ÀÎ °¡´ÉÇÕ´Ï´Ù.\n");

	gotoxy(20, 16);

	printf("¡¤ ¾Æ¹«Å°³ª ´©¸£¸é ¸ÞÀÎ ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.\n");



	g = getch();

	if (_kbhit)

	{

		start();

	}



}





void bestscore() { //Á¡¼öº¸±â ´©¸£¸é ³ª¿À°ÔÇÏ´Â ÇÔ¼ö

	system("cls");

	design();

	if (bestsc < score1)

	{

		bestsc = score1;

	}

	gotoxy(40, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("ÃÖ°íÁ¡¼ö : %d", bestsc);



	gotoxy(28, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("¾Æ¹«Å°³ª ´©¸£¸é ¸ÞÀÎ ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.\n");

	g = getch();

	if (_kbhit)

	{

		start();

	}



}

void gamemain() { // °ÔÀÓ½ÃÀÛÇÏ°í Ä«¿îÆ® ¼¼ÁÖ´Â ÇÔ¼ö

	system("mode con cols=120 lines=30");
	system("cls");
	design();
	gotoxy(25, 9);

	design();
	gotoxy(40, 9);

	printf("3ÃÊ ÈÄ ½ÃÀÛ !!");

	Sleep(1000);

	system("cls");

	design();
	gotoxy(40, 9);

	printf("2ÃÊ ÈÄ ½ÃÀÛ !!");

	Sleep(1000);

	system("cls");

	design();

	gotoxy(40, 9);

	printf("1ÃÊ ÈÄ ½ÃÀÛ !!");

	Sleep(1000);

	system("cls");

	design();

	while (1) {
		printword();
		scanword();
	}

}

void printword() {// ´Ü¾î¸¦ ¶ß°Ô ÇÏ´Â ÇÔ¼ö

	static int check = wordmax;

	x = rand() % 70 + 1; // ´Ü¾î ÁÂÇ¥

	y = rand() % 17 + 3; // ´Ü¾îÁÂÇ¥

	i = rand() % wordmax; //word ¹è¿­¿¡ ÀúÀåµÇ¾îÀÖ´Â ´Ü¾î ºÒ·¯¿ÍÁÖ´Â º¯¼ö

	f = rand() % 4 + 1; // ´Ü¾î»ö±ò ·£´ýÀ¸·Î ÇØÁÖ´Â°Å

	if (wordi[i] != 1) {

		wordi[i] = 1;

		check--;

		gotoxy(x, y);

		for (j = 0; j < 3; j++)

		{

			if (j == 0) {

				remem[i][j] = x;

			}

			else if (j == 1) {

				remem[i][j] = y;

			}

			else if (j == 2) {

				remem[i][j] = f;

			}

		}



		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), f);

		printf("%s ", word[i]);

		gotoxy(75, 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("ÀÌ »ö : 150Á¡\n");

		gotoxy(75, 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		printf("ÀÌ »ö : 200Á¡\n");

		gotoxy(75, 5);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		printf("ÀÌ »ö : 250Á¡\n");

		gotoxy(75, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("ÀÌ »ö : 300Á¡\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	}

}









void scanword() { //´Ü¾î È­¸é¿¡ ÀÔ·Â¹Þ°Ô ÇØÁÖ´Â ÇÔ¼ö

	int p = 0;

	while (p < wordtime) {
		
		p++;

		i = 0;

		int scanc;

		endTime = clock();

		gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);

		if (gap > 30) { //°ÔÀÓÁö¼Ó½Ã°£ 30s

			system("cls");

			design();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			gotoxy(40, 11);

			printf("---°Ô ÀÓ Á¾ ·á---");

			Sleep(2000);

			main();

		}



		if (_kbhit()) {

			scanc = getch();

			if (scanc != 8 && scanc != 13) {

				gotoxy(10, 25);

				scan[sword++] = scanc;

				printf("                 ");

				gotoxy(10, 25);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				printf("%s", scan);

			}

			else if (scanc == 8) {

				gotoxy(1, 25);

				gotoxy(5, 25);

				scan[--sword] = scanc;

				if (sword == -1)

					sword = 0;

				printf("%s", scan);



			}

			else if (scanc == 13) {

				sword = 0;

				gotoxy(1, 25);

				for (i = 0; i <= wordmax; i++)

				{

					if (!strcmp(scan, word[i]))

					{



						x2 = remem[i][0];

						y2 = remem[i][1];

						f2 = remem[i][2];



						gotoxy(x2, y2);

						printf("          ");

						gotoxy(1, 25);

						switch (f2) {

						case 1: score1 += 150; break;

						case 2: score1 += 200; break;

						case 3: score1 += 250; break;

						case 4: score1 += 300; break;

						default: break;

						}

						gotoxy(6, 5);

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

						printf("ÇöÀçÁ¡¼ö :%d", score1);





					}

				}

				for (i = 0; i < 50; i++) {

					scan[i] = NULL;

				}

			}

		}

	}

}

void start() { //¸ÞÀÎ¸Þ´º

	system("cls");

	design();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	gotoxy(25, 3);
	printf("     ¡¼ Å¸ÀÚ¿¬½À ÇÁ·Î±×·¥ ¡½ \n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(25, 4);
	printf("    Á¦ÀÛÀÚ¢° °íÁ¤¼± | ÀÌÁö¿¬           \n");

	gotoxy(25, 8);
	printf("¨ç ±ä ±Û ¿¬½À ½ÃÀÛ\n");

	gotoxy(25, 10);

	printf("¨è ÂªÀº ±Û ¿¬½À ½ÃÀÛ\n");

	gotoxy(25, 12);

	printf("¨é µÎ´õÁö Àâ±â °ÔÀÓ ½ÃÀÛ\n");

	gotoxy(25, 14);

	printf("¨ê µµ¿ò¸»\n");

	gotoxy(25, 16);

	printf("¨ë Á¡¼ö º¸±â(µÎ´õÁö Àâ±â)\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(25, 18);
	printf("¨ì °ÔÀÓÁ¾·á \n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(35, 24);
	printf("   ¢¹          ¢·");

	gotoxy(35, 26);

	printf("¿øÇÏ´Â ¸Þ´º¸¦ ¼±ÅÃÇÏ¼¼¿ä.\n");

}

void removeCursor() //È­¸é¿¡ ´Ü¾î ¶ã¶§ Ä¿¼­ ¾ø¾ÖÁÖ´Â°Í

{

	CONSOLE_CURSOR_INFO curInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	curInfo.bVisible = 0;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}