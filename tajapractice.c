#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

#define wordmax 103//欽橫曖 偃熱
#define wordtime 23000//欽橫陛 嗑朝 樓紫

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

time_t startTime = 0, endTime = 0;// 啪歜 衛除 薯и

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

int main(); //詭檣 л熱煎 給嬴陛晦 嬪п

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
		printf("%d廓簞 殮溘\n", hit + 1);
		printf("霞ч紫:%d%%\n螃顫熱:%d\n薑�挾�:%.2f%%\n", prog / 20 * 100, miss, acc * 100);
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
	printf("瞪羹顫熱:%d  , 螃顫熱:%d , 薑�挾�:%.2f%%\n", hit, miss, acc * 100);
	while (1) {
		input = getch();
		if (input == 13) {
			system("clear");
			main();
		}
	}
}

void wordT() {
	//章蜓 翱蝗 囀萄
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
	//霞ч紫, 薑�挾�, 譆堅顫熱, ⑷營顫熱 轎溘 
	printf("薑�挾� : %.0f%% ⑷營顫熱 : %d\n", (double)(corcnt + son) / mother * 100, tasu);
	//薑港 轎溘  
	printf("%s\n\n", short_para[randint]);
	//雖旎梱雖 殮溘脹 匙 轎溘
	printf("%s", short_input[T]);

}

void SparagraphT() {
	int T = 0;
	srand(time(NULL)); //衛萄 蟾晦��
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 200; j++)
			short_input[i][j] = 0; //殮溘 寡翮 蟾晦��  

	while (T < 5) {
		int randint = rand() % 30, c /*殮溘 嫡朝 滲熱(c)*/; //楠渾 雖薑
		for (int i = 0; i < 5; i++)
			st_length[i] = strlen(short_para[randint]) - 1;//1睡攪 撫棻(望檜) 
		ST_print(randint, T, 0);
		while (strlen(short_input[T]) <= st_length[T]) {
			if ((c = getch()) == 27) { //ESC 酈  
				system("cls");
				main();
			}
			else if (c == '\b') { //寥蝶む檜蝶
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
	//printf("%d %d\n", LT_ln, LT_col); //⑷ 嬪纂 羹觼(蛤幗梵) 
	//薑�挾�, ⑷營顫熱 轎溘
	printf("薑�挾� : %.0f%% ⑷營顫熱 : %d\n", (float)LT_count_answers(randint) / LT_count_inputs() * 100, tasucount(randint));
	//薑港 轎溘  
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
	//雖旎梱雖 殮溘脹 匙 轎溘
	
}
int main(); //詭檣 л熱煎 給嬴陛晦 嬪п 

void LparagraphT() {
	srand(time(NULL)); //衛萄 蟾晦��
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 100; j++)
			long_input[i][j] = 0; //殮溘 寡翮 蟾晦�� 
	LT_ln = 0, LT_col = 0; //ч,翮 蟾晦�� 
	int randint = rand() % 4, c; //楠渾 雖薑 
					 //陝 還曖 旋濠熱 撬 
	for (int i = 0; i < 10; i++)
		LT_length[i] = strlen(long_para[randint][i]) - 1;//1睡攪 撫棻(望檜) 
	LT_print(randint, LT_ln, LT_col);
	while (LT_ln < 10) {
		if ((c = getch()) == 27) { //ESC 酈  
			system("cls");
			main();
		}
		else if (c == '\b') { //寥蝶む檜蝶
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

void gotoxy(int x, int y)//醴憮 嬪纂 褻薑 л熱

{

	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



void help();// 紫遺蜓

void gamemain();// 啪歜詭檣

void printword();//欽橫嗑啪 п輿朝 л熱

void scanword();//欽橫蒂 殮溘 嫡朝 л熱

void design();//啪歜 蛤濠檣

void design2();

void start();//啪歜 衛濛 蟾晦 �飛�

void bestscore();//譆堅薄熱 偵褐

void removeCursor();// printf縑憮 欽橫蒂 嗑啪й陽 醴憮 薯剪



char word[256][256] = { "dog", "cat", "bottle", "phone", "robot", "green", "elephant", "include", "sky", "game", "hyomin", "jaemin", "max",//欽橫 DB

"knife", "glass", "class", "art", "smart", "bell", "carry", "climb", "between", "blow", "album", "ago", "among", "animal", "any", "box",

"and", "board", "body", "child", "classmate", "city", "boy", "bridge", "clean",

"club", "coat", "bright", "coin", "chopstick", "coffee", "cold", "chance", "chalk", "chair", "cheap", "blue",

"before", "bowl", "aunt", "as", "away", "bicycle", "church", "card", "hold",

"chose", "come", "drink", "give", "get", "hurt", "lay","had", "feed", "lend", "met", "wsing", "throw", "wet", "tell",

"set", "wind", "wear", "write", "spend", "stand", "worn", "win", "sweep", "account", "achieve", "across", "accept", "above", "ability", "abuse",

"abnormal", "absurd", "acceptance", "according", "absent", "nation", "past", "value", "though", "person", "machine", "stand", "null" };

int wordi[250];//и 廓嗤 欽橫菟擎 寰嗑啪 п輿晦 嬪п 虜菟橫喫

int x, y;// gotoxy 曖 x高婁 y高

int i;//欽橫 熱

int j, k;

int a;//欽橫 熱 諦 偽擎 熱 滲熱

int s;//kbhit

int c;//奩犒僥寡翮

int x2, y2;// x,y高擊 棻衛 碳楝螢 陽 滲熱

int g;

int score1 = 0;//薄熱

int h;//蟾晦�飛橦□� 殮溘 嫡擊陽 滲熱

int f;// 儀梃

int f2;// 儀梃 高擊 棻衛 碳楝螢陽 滲熱

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
			printf("        熱堅ж樟蝗棲棻.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); return 0; break;
		default:
			printf("螢夥艇 酈陛 嬴椎棲棻!");

			break;
		}

	}



}









void design() { //蛤濠檣 碳楝螃朝 л熱

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("|收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收|\n");

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

	printf("|收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收|\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|                                                                                                                    |\n");

	printf("|收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收|");








}

void design2() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("mode con cols=90 lines=35");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("早                                 早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

}
void help() {// 紫遺蜓 詭景 碳楝螃啪 п輿朝 л熱

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	system("cls");

	design();

	gotoxy(30, 7);

	printf("20194032 堅薑摹 20194033 檜雖翱 薯濛\n");

	gotoxy(20, 9);

	printf("﹞ �飛橦� 嗑朝 旋濠菟擊 緒腦啪 嫡嬴噙撮蹂\n");

	gotoxy(20, 11);

	printf("﹞ 儀葆棻 薄熱 寡薄檜 棻落棲棻!");

	gotoxy(17, 12);

	printf("( ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

	printf("檜 儀 : 150薄 ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

	printf("檜 儀 : 200薄 ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

	printf("檜 儀 : 250薄 ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	printf("檜 儀 : 300薄 ");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf(" )");

	gotoxy(20, 14);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("﹞ 30蟾 翕寰 啪歜檜 霞ч腌棲棻!! 部釭賊 濠翕戲煎 謙猿腌棲棻.");

	gotoxy(20, 15);

	printf("﹞ 譆堅薄熱陛 盪濰腌棲棻. 詭檣詭景 3. 薄熱爾晦縑憮 �挫� 陛棟м棲棻.\n");

	gotoxy(20, 16);

	printf("﹞ 嬴鼠酈釭 援腦賊 詭檣 詭景煎 給嬴骨棲棻.\n");



	g = getch();

	if (_kbhit)

	{

		start();

	}



}





void bestscore() { //薄熱爾晦 援腦賊 釭螃啪ж朝 л熱

	system("cls");

	design();

	if (bestsc < score1)

	{

		bestsc = score1;

	}

	gotoxy(40, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("譆堅薄熱 : %d", bestsc);



	gotoxy(28, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("嬴鼠酈釭 援腦賊 詭檣 詭景煎 給嬴骨棲棻.\n");

	g = getch();

	if (_kbhit)

	{

		start();

	}



}

void gamemain() { // 啪歜衛濛ж堅 蘋遴お 撮輿朝 л熱

	system("mode con cols=120 lines=30");
	system("cls");
	design();
	gotoxy(25, 9);

	design();
	gotoxy(40, 9);

	printf("3蟾 �� 衛濛 !!");

	Sleep(1000);

	system("cls");

	design();
	gotoxy(40, 9);

	printf("2蟾 �� 衛濛 !!");

	Sleep(1000);

	system("cls");

	design();

	gotoxy(40, 9);

	printf("1蟾 �� 衛濛 !!");

	Sleep(1000);

	system("cls");

	design();

	while (1) {
		printword();
		scanword();
	}

}

void printword() {// 欽橫蒂 嗑啪 ж朝 л熱

	static int check = wordmax;

	x = rand() % 70 + 1; // 欽橫 謝ル

	y = rand() % 17 + 3; // 欽橫謝ル

	i = rand() % wordmax; //word 寡翮縑 盪濰腎橫氈朝 欽橫 碳楝諦輿朝 滲熱

	f = rand() % 4 + 1; // 欽橫儀梃 楠渾戲煎 п輿朝剪

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
		printf("檜 儀 : 150薄\n");

		gotoxy(75, 4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		printf("檜 儀 : 200薄\n");

		gotoxy(75, 5);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		printf("檜 儀 : 250薄\n");

		gotoxy(75, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("檜 儀 : 300薄\n");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	}

}









void scanword() { //欽橫 �飛橦� 殮溘嫡啪 п輿朝 л熱

	int p = 0;

	while (p < wordtime) {
		
		p++;

		i = 0;

		int scanc;

		endTime = clock();

		gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);

		if (gap > 30) { //啪歜雖樓衛除 30s

			system("cls");

			design();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			gotoxy(40, 11);

			printf("---啪 歜 謙 猿---");

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

						printf("⑷營薄熱 :%d", score1);





					}

				}

				for (i = 0; i < 50; i++) {

					scan[i] = NULL;

				}

			}

		}

	}

}

void start() { //詭檣詭景

	system("cls");

	design();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	gotoxy(25, 3);
	printf("     □ 顫濠翱蝗 Щ煎斜極 ■ \n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(25, 4);
	printf("    薯濛濠１ 堅薑摹 | 檜雖翱           \n");

	gotoxy(25, 8);
	printf("函 曹 旋 翱蝗 衛濛\n");

	gotoxy(25, 10);

	printf("刻 穠擎 旋 翱蝗 衛濛\n");

	gotoxy(25, 12);

	printf("券 舒渦雖 濩晦 啪歜 衛濛\n");

	gotoxy(25, 14);

	printf("刷 紫遺蜓\n");

	gotoxy(25, 16);

	printf("刺 薄熱 爾晦(舒渦雖 濩晦)\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(25, 18);
	printf("到 啪歜謙猿 \n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(35, 24);
	printf("   Ⅰ          ８");

	gotoxy(35, 26);

	printf("錳ж朝 詭景蒂 摹鷗ж撮蹂.\n");

}

void removeCursor() //�飛橦� 欽橫 嗚陽 醴憮 橈擁輿朝匙

{

	CONSOLE_CURSOR_INFO curInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	curInfo.bVisible = 0;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

}