#include<stdio.h> //�����
#include<windows.h> //Ŀ�� �̵� 
#include<conio.h> //getch()�Լ�

// Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 //�����̽���
#define ESC 27

int before_fileprint();//�浹�� ������ �������� �鵹�� ������ �������� ���� �Լ� 
void before_game();//������ �̰�� ����� ������ �ҷ����� �Լ�
void Fileprint(int win); //������ �̱�� ���� �̱����� �г��Ӱ� ��¥�� �Է��ϴ� �Լ�
void backboard(); //��������� �� ���� ����ϴ� �Լ�
void draw_put_stone(int Board[20][20]); //�ǿ� ���� ���� ����ϴ� �Լ�
void Erase_stone(int x, int y); // ���� �̵���ų �� ��µǾ��ִ� ���� ���ִ� �Լ�
void Put_stone(int Board[20][20], int x, int y); //���� ���� �� �鵹 �浹�� �ٲ����ϹǷ� location���� ������ �̿��ؼ� �浹 �鵹�� �ٲ�
void Put_key(int Board[20][20], char move_key, int *x, int *y);//ȭ��ǥ Ű�� �̿��ؼ� ������, �����̽��ٸ� ������ Put_stone�Լ��� �Ѿ
int win_check(int Board[20][20]);//�浹�� �̰���� �鵹�� �̰���� Ȯ���ϴ� �Լ�
void gotoxy(int x, int y);//�ܼ��� ��ǥ���� �̿��� �Լ�
int key();//����ȭ�鿡�� ���� A,W,S,DŰ�� �������ִ� �Լ�
int menu();//����ȭ�� ����Լ�, ���ϰ��� ���� ����� �������� �޶���
void gameinformation();//�������� ����Լ�
void console();//�ܼ��� ũ��,�̸��� ���ϰ� Ŀ���� �������� �����ִ� �Լ�
void game();//������� �Լ�
void draw_stone();//�������� location�� ���� �̿��ؼ� ���� �̿��ϰ��ִ� ���� ������ ���
int location = 1;//���� ������ ���������� �������� 1=�鵹 2=�浹

FILE *fp;//���� ����¿� �� ������

int main() { //�����Լ�

	while (1) { //while���� �̿��� ���� ����
		console();//�ܼ� ũ�� ������
		int menuCode = menu();//�޴�ȭ���� ����ϰ� �� ���ϰ��� ������.
		if (menuCode == 0) {//menuCode�� ���� 0�̸� ���ӽ��� 
			game();
		}
		else if (menuCode == 1) {//menuCode�� ���� 1�̸� �������� ��� 
			gameinformation();//�������� ����Լ�
		}
		else if (menuCode == 2) {//menuCode�� ���� 2�̸� �ܼ�����
			system("cls");//ȭ���� ����
			return 0;//����
		}
		else if (menuCode == 3) {
			before_game();//������ �̰�� ������� ������ ���� �Լ�
		}
	}
}

void before_game() {//������ �̰�� ����� ������ �ҷ����� �Լ�
	while (1) {
		int code = before_fileprint();
		if (code == 0) {
			system("cls");
			fp = fopen("White.txt", "r");
			while (1) {
				char ch;
				ch = fgetc(fp);
				if (ch == EOF) {
					break;
				}
				putchar(ch);
			}
			fclose(fp);
			system("pause");
		}
		else if (code == 1) {
			system("cls");
			fp = fopen("Black.txt", "r");
			while (1) {
				char ch;
				ch = fgetc(fp);
				if (ch == EOF) {
					break;
				}
				putchar(ch);
			}
			fclose(fp);
			system("pause");
		}
		else if (code == 2) {
			return 0;
		}
	}
}

int before_fileprint() {//�浹�� ������ �������� �鵹�� ������ �������� ���� �Լ�
	system("cls");
	int x = 25;
	int y = 12;
	gotoxy(x - 2, y);
	printf("> �� ��");
	gotoxy(x, y + 1);
	printf("�� ��");
	gotoxy(x, y + 2);
	printf("���� ȭ��");
	while (1) {
		int n = key();
		switch (n) {
		case UP: {
			if (y > 12) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 12;
		}
		}
	}
}

void gameinformation() {
	system("cls");
	printf("\n\n\n\n");
	printf("	             ������ : �ڽ���\n");
	printf("                   ���� �帣 : �������\n\n\n");
	printf("                  �޴�ȭ��Ű : A, S, W, D\n\n");
	printf("    �̵�Ű: ȭ��ǥ (��)��, (�Ʒ�)��, (������)��, (����)�� \n");
	printf("	         �ٵϵ� �α� : �����̽���\n\n\n");
	printf("        �����̽��ٸ� ������ ���� ȭ������ ���ư��ϴ�.\n");
	while (1) {
		if (key() == SUBMIT) {//�����̽��ٸ� ������ ����ȭ������ �̵�
			break;//�Լ� ����
		}
	}
}

void gotoxy(int x, int y) {//�ܼ� ��ǥ���� �̿��ϴ� �Լ�

	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int key() {
	char temp = getch();//getch()�� Ű���� ����

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
	else if (temp == 27) {
		return ESC;
	}
}

int menu() {//����ȭ�� ����Լ�
	int x = 25;
	int y = 12;//���ڵ��� ��ġ�� ���ϱ����� x=25, y=12�� ����
	gotoxy(x - 2, y);
	printf("> �� �� �� ��");
	gotoxy(x, y + 1);
	printf("�� �� �� ��");
	gotoxy(x, y + 2);
	printf("   �� ��   ");
	gotoxy(x, y + 3);
	printf(" �ߴ� ����");
	while (1) {
		int n = key();
		switch (n) {
		case UP: {// WŰ
			if (y > 12) {//���ӽ��� �� �ƴ϶�� ���� �� �� �ְ���
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);//�ֿܼ����� ���� ��ǥ���� �۱� ������ y--������ 
				printf(">");//x-2�� ����� �ٽ�>�� ��������ν� >�� ���Ʒ��� �����̴� ��ó�����̰���.
			}
			break; //if���� �������� ���� �� caseŻ��
		}

		case DOWN: {// SŰ
			if (y < 15) {//�շ� �� �ƴ϶�� �ؿ��� ������ �� �ְ���
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);//�ֿܼ����� �Ʒ��� ��ǥ���� ũ�� ������ y++�� ����
				printf(">");//x-2�� ����� �ٽ�>�� ��������ν� >�� ���Ʒ��� �����̴� ��ó�����̰���.
			}
			break;//if���� �������� ���� �� caseŻ��
		}

		case SUBMIT: {//�����̽���
			return y - 12; //�����̽��ٸ� ������ ���ӽ���, ��������, ���� �� �ϳ��� �����ϰԵǰ� �װ��� �������� ��Ÿ��
		}
		}
	}
}

void console() {//�ܼ�ũ��, �̸� ���� Ŀ�������Ÿ��� ���ִ� �Լ�
	system("mode con cols=60 lines=20 | title �������");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}

void backboard() { //������ ��� �Լ�
	system("cls");
	int i, j;

	printf("��");
	for (i = 0; i < 34; ++i) {
		printf("��");
	}
	printf("��\n");

	for (i = 0; i < 34; ++i) {
		printf("��");
		for (j = 0; j < 34; ++j) {
			printf("��");
		}
		printf("��\n");
	}
	printf("��");
	for (i = 0; i < 34; ++i) {
		printf("��");
	}
	printf("��\n");
	gotoxy(42, 2);
	printf("19�� �ٵ���");
	gotoxy(41, 5);
	printf("ESC = ����ȭ��");

}

void draw_stone() {//���������� �̿��� �� ���� ���
	if (location == 1) {
		printf("��");
	}
	else {
		printf("��");
	}
}

int win_check(int Board[20][20]) {//����� �̰���� üũ�ϴ� �Լ� �鵹�� �̱�� 1�� ���� �浹�� �̱�� 2�� ����
	int i;
	int j;
	for (i = 2; i < 18; i++) {
		for (j = 0; j < 20; j++) {
			if (Board[j][i - 2] == 1 && Board[j][i - 1] == 1 && Board[j][i] == 1 && Board[j][i + 1] == 1 && Board[j][i + 2] == 1) {
				gotoxy(40, 10);
				printf("*** �鵹 �¸� ***");
				getch();
				return 1;
			}
			else if (Board[j][i - 2] == 2 && Board[j][i - 1] == 2 && Board[j][i] == 2 && Board[j][i + 1] == 2 && Board[j][i + 2] == 2) {
				gotoxy(40, 10);
				printf("*** �浹 �¸� ***");
				getch();
				return 2;
			}

			else if (Board[i - 2][j] == 1 && Board[i - 1][j] == 1 && Board[i][j] == 1 && Board[i + 1][j] == 1 && Board[i + 2][j] == 1) {
				gotoxy(40, 10);
				printf("*** �鵹 �¸� ***");
				getch();
				return 1;
			}
			else if (Board[i - 2][j] == 2 && Board[i - 1][j] == 2 && Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i + 2][j] == 2) {
				gotoxy(40, 10);
				printf("*** �浹 �¸� ***");
				getch();
				return 2;
			}
		}
	}

	for (i = 2; i < 18; i++) {
		for (j = 2; j < 18; j++) {
			if (Board[j - 2][i - 2] == 1 && Board[j - 1][i - 1] == 1 && Board[j][i] == 1 && Board[j + 1][i + 1] == 1 && Board[j + 2][i + 2] == 1) {
				gotoxy(40, 10);
				printf("*** �鵹 �¸� ***");
				getch();
				return 1;
			}
			else if (Board[j - 2][i - 2] == 2 && Board[j - 1][i - 1] == 2 && Board[j][i] == 2 && Board[j + 1][i + 1] == 2 && Board[j + 2][i + 2] == 2) {
				gotoxy(40, 10);
				printf("*** �浹 �¸� ***");
				getch();
				return 2;
			}

			else if (Board[j + 2][i - 2] == 1 && Board[j + 1][i - 1] == 1 && Board[j][i] == 1 && Board[j - 1][i + 1] == 1 && Board[j - 2][i + 2] == 1) {
				gotoxy(40, 10);
				printf("*** �鵹 �¸� ***");
				getch();
				return 1;
			}
			else if (Board[j + 2][i - 2] == 2 && Board[j + 1][i - 1] == 2 && Board[j][i] == 2 && Board[j - 1][i + 1] == 2 && Board[j - 2][i + 2] == 2) {
				gotoxy(40, 10);
				printf("*** �浹 �¸� ***");
				getch();
				return 2;
			}
		}
	}
	return 0;
}

void Erase_stone(int x, int y) {//��ǥ���� ���� ���� �ű涧 ������ǥ�� ���� ��µǾ��ִµ� �� ��µ� ���� ����� �Լ�
	gotoxy(x, y);

	if (x == 0 && y == 0) {
		printf("��");
	}
	else if (x == 36 && y == 0) {
		printf("��");
	}
	else if (x == 0 && y == 18) {
		printf("��");
	}
	else if (x == 36 && y == 18) {
		printf("��");
	}
	else if (x == 0) {
		printf("��");
	}
	else if (y == 0) {
		printf("��");
	}
	else if (x == 36) {
		printf("��");
	}
	else if (y == 18) {
		printf("��");
	}
	else {
		printf("��");
	}
}

void Put_key(int Board[20][20], char move_key, int *x, int *y) {//Ŀ���̵��� ó���ϴ� �Լ� 
	switch (move_key) {
	case 72://���� ����Ű
		if (*y - 1 < 0) {
			break;
		}
		else {
			*y -= 1;
			break;
		}
	case 80://�Ʒ��� ����Ű
		if (*y + 1 > 18) {
			break;
		}
		else {
			*y += 1;
			break;
		}
	case 75://���� ����Ű
		if (*x - 2 < 0) {
			break;
		}
		else {
			*x -= 2;
			break;
		}
	case 77://������ ����Ű
		if (*x + 2 > 36) {
			break;
		}
		else {
			*x += 2;
			break;
		}
	case 32://�����̽���
		Put_stone(Board, *x, *y);//�� ���� �Լ� ȣ��, ���� Board�� ��ǥ x, y�� �Ű������� ����
		break;
	default:
		break; //�������� ó������ ����
	}
}

void Put_stone(int Board[20][20], int x, int y) { //�� ���� �Լ�
	if (Board[y][x / 2] == 0) {
		if (location == 1) {//�������� location�� 1�� ��� 
			Board[y][x / 2] = 1; //Board[y][x/2]=1�� ����. Board[����][����], ���δ� 2����Ʈ�� ��ĭ�̱� ������ ������ 2�� ��
			location = 2; //�������� location�� 2�� �ʱ�ȭ
		}
		else {//1�� �ƴҰ��
			Board[y][x / 2] = 2; //Board[y][x/2]=1�� ����. Board[����][����], ���δ� 2����Ʈ�� ��ĭ�̱� ������ ������ 2�� ��
			location = 1; //�������� location�� 1�� �ʱ�ȭ
		}
	}
}

void draw_put_stone(int Board[20][20]) {//���� ����ϴ� �Լ�
	int i;
	int j;
	for (i = 0; i < 20; ++i) {//����for������ Board��ü�� �˻�
		for (j = 0; j < 20; ++j) {
			if (Board[j][i] == 1) {
				gotoxy(i * 2, j); //���δ� 2����Ʈ�� ��ĭ�̱� ������ i*2�� ����
				printf("��"); //Board���� 1�� ������ �鵹 ���
			}
			else if (Board[j][i] == 2) {
				gotoxy(i * 2, j); //���δ� 2����Ʈ�� ��ĭ�̱� ������ i*2�� ����
				printf("��"); //Board���� 2�� ������ �浹 ���
			}
		}
	}
}

void game() {//�����Լ�
	int arr[20][20] = { 0, }; //�������� Ȱ���ϱ����� �迭 ���� 19*19(��)
	int x = 0, y = 0; //��ǥ�� �� �迭�� ��ġ�� ��Ÿ�������� ���� ����
	char move_key;// ȭ��ǥŰ�� ���� ���� ����
	int win;//win_check�Լ��� ���ϰ��� �����ϴ� �������� ����

	backboard(); //������ ��� 19*19(��)
	gotoxy(x, y);//���� ��ġ�� �ʱ�ȭ ������
	draw_stone();//ó�� ���� �׷��� location�� 1�̸� �鵹 2�̸� �浹
	do {//do~while���� �̿��Ͽ� ESCŰ�� ������ �ʴ��� ��� �����Ŵ
		move_key = getch();//ȭ��ǥ Ű�� ����
		Erase_stone(x, y);//���� �̵���ų�� ��µǾ� �ִ� ������ ���� ����
		Put_key(arr, move_key, &x, &y);//��ǥ���� ���� ���� �̵���Ŵ
		draw_put_stone(arr);//���� ���
		if (win = win_check(arr)) {//���� ����ϰ��� �̰���� ������ üũ�ϴ� �Լ�, ���ϰ��� 1�̸� if�� ���� 0�̸� ������������
			Fileprint(win);
			return 0;//���� ����
		}
		gotoxy(x, y);//�̵��� ��ǥ���� ����
		draw_stone();//���� ������ �� �ڸ����� ���� �������� �����̰���
	} while (move_key != 27);//move_key�� ESC(27)�̸� ���� ���� ����ȭ������ �̵���
}

void Fileprint(int win) {//������ �� ������ ������� �г��Ӱ� ��¥�� ������������� �����Ű�� �Լ�
	system("cls");
	char Nickname[1000] = { 0, };
	char Day[1000] = { 0, };
	if (win == 1) { //�鵹�� �̰��� ��� White.txt�� ��¥ ,�г����� �Է��Ͽ� ����
		gotoxy(20, 10);
		printf("***�鵹 �¸�***");
		gotoxy(20, 12);
		printf("��¥ �Է� : ");
		gets_s(Day, sizeof(Day));
		gotoxy(18, 14);
		printf("�г��� �Է�: ");
		gets_s(Nickname, sizeof(Nickname));
		fp = fopen("White.txt", "a+");
		fprintf(fp, "***�鵹 �¸�***\n");
		fprintf(fp, "��¥ �Է� : ");
		fprintf(fp, "%s\n", Day);
		fprintf(fp, "�г��� : ");
		fprintf(fp, "%s\n", Nickname);
		fclose(fp);
	}
	else if (win == 2) { //�浹�� �̰��� ��� Black.txt�� ��¥ ,�г����� �Է��Ͽ� ����
		gotoxy(20, 10);
		printf("***�浹 �¸�***");
		gotoxy(20, 12);
		printf("��¥ �Է� : ");
		gets_s(Day, sizeof(Day));
		gotoxy(18, 14);
		printf("�г��� �Է�: ");
		gets_s(Nickname, sizeof(Nickname));
		fp = fopen("Black.txt", "a+");
		fprintf(fp, "***�浹 �¸�***\n");
		fprintf(fp, "��¥ �Է� : ");
		fprintf(fp, "%s\n", Day);
		fprintf(fp, "�г��� : ");
		fprintf(fp, "%s\n", Nickname);
		fclose(fp);
	}
}
