#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include<windows.h>
#pragma warning(disable : 4996)
using namespace std;

constexpr char Enter = 13, Backspace = 8, Esc = 27, Delete = 83, Up = 72, Down = 80, Left = 75, Right = 77;
unsigned char ch;

struct menu {
	char arr[27];
	menu* next, * prev;
};

//������� ���� ����� � �����
enum ConsoleColor {
	Black, Blue,
	Green, Cyan,
	Red, Magenta,
	Brown, LightGray,
	DarkGray, LightBlue,
	LightGreen, LightCyan,
	LightRed, LightMagenta,
	Yellow, White
};
//��������� ����� ������ � ����
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//����� ������� "sudoku"
inline void sudoku() {
	//cout << endl;
	SetColor(Cyan, Black);
	cout << setfill(' ') << setw(103) << "               _       _          " << endl;
	cout << setw(103) << "              | |     | |         " << endl;
	cout << setw(103) << " ___ _   _  __| | ___ | | ___   _ " << endl;
	cout << setw(103) << "/ __| | | |/ _` |/ _ \\| |/ / | | |" << endl;
	cout << setw(103) << "\\__ \\ |_| | (_| | (_) |   <| |_| |" << endl;
	cout << setw(103) << "|___/\\__,_|\\__,_|\\___/|_|\\_\\\\__,_|" << endl << endl;
	SetColor(White, Black);
}
//����� ������� "no answer"
inline void noAnswer() {
	sudoku();
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	SetColor(Magenta, Black);
	cout << setfill(' ') << setw(110) << " _ __   ___     __ _ _ __  _____      _____ _ __ " << endl;
	cout << setw(110) << "| '_ \\ / _ \\   / _` | '_ \\/ __\\ \\ /\\ / / _ \\ '__|" << endl;
	cout << setw(110) << "| | | | (_) | | (_| | | | \\__ \\\\ V  V /  __/ |   " << endl;
	cout << setw(110) << "|_| |_|\\___/   \\__,_|_| |_|___/ \\_/\\_/ \\___|_|   " << endl << endl;
	SetColor(White, Black);

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< setw(105) << "��� ����������� ������� ����� �������";
}
//����� ������� "many decisions"
inline void manyDecisions() {
	sudoku();
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	SetColor(Magenta, Black);
	cout << setfill(' ') << setw(121) << "                                   _           _     _                 " << endl;
	cout << setw(121) << "                                  | |         (_)   (_)                " << endl;
	cout << setw(121) << " _ __ ___   __ _ _ __  _   _    __| | ___  ___ _ ___ _  ___  _ __  ___ " << endl;
	cout << setw(121) << "| '_ ` _ \\ / _` | '_ \\| | | |  / _` |/ _ \\/ __| / __| |/ _ \\| '_ \\/ __|" << endl;
	cout << setw(121) << "| | | | | | (_| | | | | |_| | | (_| |  __/ (__| \\__ \\ | (_) | | | \\__ \\" << endl;
	cout << setw(121) << "|_| |_| |_|\\__,_|_| |_|\\__, |  \\__,_|\\___|\\___|_|___/_|\\___/|_| |_|___/" << endl;
	cout << setw(121) << "                        __/ |                                          " << endl;
	cout << setw(121) << "                       |___/                                           " << endl;
	SetColor(White, Black);

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< setw(105) << "��� ����������� ������� ����� �������";
}
//����� ������� "no file with that name"
inline void noFile() {
	sudoku();
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	SetColor(Magenta, Black);
	cout << setfill(' ') << setw(135) << "                __ _ _                 _ _   _       _   _           _                                " << endl;
	cout << setw(135) << "               / _(_) |               (_) | | |     | | | |         | |                               " << endl;
	cout << setw(135) << " _ __   ___   | |_ _| | ___  __      ___| |_| |__   | |_| |__   __ _| |_   _ __   __ _ _ __ ___   ___ " << endl;
	cout << setw(135) << "| '_ \\ / _ \\  |  _| | |/ _ \\ \\ \\ /\\ / / | __| '_ \\  | __| '_ \\ / _` | __| | '_ \\ / _` | '_ ` _ \\ / _ \\" << endl;
	cout << setw(135) << "| | | | (_) | | | | | |  __/  \\ V  V /| | |_| | | | | |_| | | | (_| | |_  | | | | (_| | | | | | |  __/" << endl;
	cout << setw(135) << "|_| |_|\\___/  |_| |_|_|\\___|   \\_/\\_/ |_|\\__|_| |_|  \\__|_| |_|\\__,_|\\__| |_| |_|\\__,_|_| |_| |_|\\___|" << endl << endl;
	SetColor(White, Black);

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< setw(105) << "��� ����������� ������� ����� �������";
}
//����� ������� "no save"
inline void noSave() {
	sudoku();
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	SetColor(Magenta, Black);
	cout << setfill(' ') << setw(103) << " _ __   ___    ___  __ ___   _____ " << endl;
	cout << setw(103) << "| '_ \\ / _ \\  / __|/ _` \\ \\ / / _ \\" << endl;
	cout << setw(103) << "| | | | (_) | \\__ \\ (_| |\\ V /  __/" << endl;
	cout << setw(103) << "|_| |_|\\___/  |___/\\__,_| \\_/ \\___|" << endl;
	SetColor(White, Black);

	Sleep(1100);
}
//����� ������� " level passed"
inline void levelPassed() {
	sudoku();
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	SetColor(Magenta, Black);
	cout << setfill(' ') << setw(113) << " _                _                                _ " << endl;
	cout << setw(113) << "| |              | |                              | |" << endl;
	cout << setw(113) << "| | _____   _____| |  _ __   __ _ ___ ___  ___  __| |" << endl;
	cout << setw(113) << "| |/ _ \\ \\ / / _ \\ | | '_ \\ / _` / __/ __|/ _ \\/ _` |" << endl;
	cout << setw(113) << "| |  __/\\ V /  __/ | | |_) | (_| \\__ \\__ \\  __/ (_| |" << endl;
	cout << setw(113) << "|_|\\___| \\_/ \\___|_| | .__/ \\__,_|___/___/\\___|\\__,_|" << endl;
	cout << setw(113) << "                     | |                             " << endl;
	cout << setw(113) << "                     |_|                             " << endl;
	SetColor(White, Black);

	Sleep(1100);
}

//����� ������� ���������� �� ���� � ������� � �������� #������
inline void print(const unsigned char grid[9][9], const unsigned char sol_grid[9][9]) {
	sudoku();
	for (int i = 0; i < 9; ++i) {
		if (i % 3 == 0) cout << setw(9) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";
		else {
			cout << setw(9) << setfill(' ') << ' ' << "#";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
		}
		cout << setw(8) << setfill(' ') << ' ';
		if (i % 3 == 0) cout << setw(73) << setfill('#') << "#";
		else {
			cout << "#";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
		}
		cout << endl;

		cout << setw(9) << setfill(' ') << ' ';
		for (int j = 0; j < 9; ++j)
			if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
			else cout << "|" << setw(8) << setfill(' ');
		cout << '#' << setw(8) << setfill(' ') << ' ';
		for (int j = 0; j < 9; ++j) {
			if (j % 3 == 0) cout << "#";
			else cout << "|";
			if (grid[i][j] != 0) {
				SetColor(Blue, Black);
				cout << ' ' << setw(6) << setfill('*') << ' ';
				SetColor(White, Black);
			}
			else cout << "   " << grid[i][j] << "   ";
		}
		cout << "#" << endl;


		cout << setw(9) << setfill(' ') << ' ';
		for (int j = 0; j < 9; ++j) {
			if (j % 3 == 0) cout << "#";
			else cout << "|";
			if (grid[i][j] == 0) cout << setw(8) << setfill(' ');
			else cout << "   " << grid[i][j] << "   ";
		}
		cout << '#' << setw(8) << setfill(' ') << ' ';
		for (int j = 0; j < 9; ++j) {
			if (j % 3 == 0) cout << "#";
			else cout << "|";
			if (sol_grid[i][j] != 0) cout << "   " << sol_grid[i][j] << "   ";
			else
				if (grid[i][j] != 0) {
					SetColor(Blue, Black);
					cout << " * ";
					SetColor(White, Black);
					cout << grid[i][j];
					SetColor(Blue, Black);
					cout << " * ";
					SetColor(White, Black);
				}
				else
					cout << setw(8) << setfill(' ');
		}
		cout << "#" << endl;

		cout << setw(9) << setfill(' ') << ' ';
		for (int j = 0; j < 9; ++j)
			if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
			else cout << "|" << setw(8) << setfill(' ');
		cout << '#' << setw(8) << setfill(' ') << ' ';
		for (int j = 0; j < 9; ++j) {
			if (j % 3 == 0) cout << "#";
			else cout << "|";
			if (grid[i][j] != 0) {
				SetColor(Blue, Black);
				cout << ' ' << setw(6) << setfill('*') << ' ';
				SetColor(White, Black);
			}
			else cout << "   " << grid[i][j] << "   ";
		}
		cout << "#" << endl;
	}
	cout << setw(9) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";
	cout << setw(8) << setfill(' ') << ' ';
	cout << setw(73) << setfill('#') << "#";
}
//����� ������� � �������� "many decisions"
inline void print_manyDecisions(const unsigned char grid[9][9]) {
	sudoku();
	for (int i = 0; i < 9; ++i) {
		if (i % 3 == 0) cout << "    " << setw(73) << setfill('#') << "#";
		else {
			cout << "    #";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
			if (i == 4) {
				cout << "         ";
				SetColor(Magenta, Black);
				cout << " _ __ ___   __ _ _ __  _   _    __| | ___  ___ _ ___ _  ___  _ __  ___ ";
				SetColor(White, Black);
			}
			if (i == 5) {
				cout << "         ";
				SetColor(Magenta, Black);
				cout << "                        __/ |                                          ";
				SetColor(White, Black);
			}
		}
		cout << endl;

		cout << "    ";
		for (int j = 0; j < 9; ++j)
			if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
			else cout << "|" << setw(8) << setfill(' ');
		if (i == 4) {
			cout << '#' << "         ";
			SetColor(Magenta, Black);
			cout << "| '_ ` _ \\ / _` | '_ \\| | | |  / _` |/ _ \\/ __| / __| |/ _ \\| '_ \\/ __|" << endl;
			SetColor(White, Black);
		}
		else
			if (i == 5) {
				cout << '#' << "         ";
				SetColor(Magenta, Black);
				cout << "                       |___/                                           " << endl;
				SetColor(White, Black);
			}
			else cout << '#' << endl;

		cout << "    ";
		for (int j = 0; j < 9; ++j) {
			if (j % 3 == 0) cout << "#";
			else cout << "|";
			cout << "   " << grid[i][j] << "   ";
		}
		if (i == 4) {
			cout << '#' << "         ";
			SetColor(Magenta, Black);
			cout << "| | | | | | (_| | | | | |_| | | (_| |  __/ (__| \\__ \\ | (_) | | | \\__ \\" << endl;
			SetColor(White, Black);
		}
		else
			if (i == 3) {
				cout << '#' << "         ";
				SetColor(Magenta, Black);
				cout << "                                   _           _     _                 " << endl;
				SetColor(White, Black);
			}
			else cout << '#' << endl;

		cout << "    ";
		for (int j = 0; j < 9; ++j)
			if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
			else cout << "|" << setw(8) << setfill(' ');
		if (i == 4) {
			cout << '#' << "         ";
			SetColor(Magenta, Black);
			cout << "|_| |_| |_|\\__,_|_| |_|\\__, |  \\__,_|\\___|\\___|_|___/_|\\___/|_| |_|___/" << endl;
			SetColor(White, Black);
		}
		else
			if (i == 3) {
				cout << '#' << "         ";
				SetColor(Magenta, Black);
				cout << "                                  | |         (_)   (_)                " << endl;
				SetColor(White, Black);
			}
			else cout << '#' << endl;
	}
	cout << "    " << setw(73) << setfill('#') << "#";
}
//����� ������� � �������� "no answer"
inline void print_noAnswer(const unsigned char grid[9][9]) {
	sudoku();
	for (int i = 0; i < 9; ++i) {
		if (i % 3 == 0) cout << "    " << setw(73) << setfill('#') << "#";
		else {
			cout << "    #";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
			cout << setw(24) << setfill('�') << "#";
			if (i == 4) {
				SetColor(Magenta, Black);
				cout << setfill(' ') << setw(73) << " _ __   ___     __ _ _ __  _____      _____ _ __ ";
				SetColor(White, Black);
			}
		}
		cout << endl;

		cout << "    ";
		for (int j = 0; j < 9; ++j)
			if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
			else cout << "|" << setw(8) << setfill(' ');
		//cout << "#" << endl;
		if (i == 4) {
			cout << '#';
			SetColor(Magenta, Black);
			cout << setw(73) << "| '_ \\ / _ \\   / _` | '_ \\/ __\\ \\ /\\ / / _ \\ '__|" << endl;
			SetColor(White, Black);
		}
		else cout << "#" << endl;

		cout << "    ";
		for (int j = 0; j < 9; ++j) {
			if (j % 3 == 0) cout << "#";
			else cout << "|";
			cout << "   " << grid[i][j] << "   ";
		}
		if (i == 4) {
			cout << '#';
			SetColor(Magenta, Black);
			cout << setw(73) << "| | | | (_) | | (_| | | | \\__ \\\\ V  V /  __/ |   " << endl;
			SetColor(White, Black);
		}
		else cout << "#" << endl;

		cout << "    ";
		for (int j = 0; j < 9; ++j)
			if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
			else cout << "|" << setw(8) << setfill(' ');
		if (i == 4) {
			cout << '#';
			SetColor(Magenta, Black);
			cout << setw(73) << "|_| |_|\\___/   \\__,_|_| |_|___/ \\_/\\_/ \\___|_|   " << endl;
			SetColor(White, Black);
		}
		else cout << "#" << endl;
	}
	cout << "    " << setw(73) << setfill('#') << "#";
}

//������ ������� ��� ����������� �������
inline void read(unsigned char grid[9][9]) {
	unsigned char  row = 4, col = 4;
	do {
		sudoku();
		for (int i = 0; i < 9; ++i) {
			if (i % 3 == 0) cout << setw(50) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";
			else {
				cout << setw(50) << setfill(' ') << ' ' << "#";
				cout << setw(24) << setfill('�') << "#";
				cout << setw(24) << setfill('�') << "#";
				cout << setw(24) << setfill('�') << "#";

			}
			cout << endl;

			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j)
				if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
				else cout << "|" << setw(8) << setfill(' ');
			cout << "#" << endl;

			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j) {
				if (j % 3 == 0) cout << "#";
				else cout << "|";
				if (i == row && j == col)
					if (grid[i][j] == 0) cout << " [   ] ";
					else cout << " [ " << grid[i][j] << " ] ";
				else
					if (grid[i][j] == 0) cout << setw(8) << setfill(' ');
					else cout << "   " << grid[i][j] << "   ";
			}
			cout << "#" << endl;

			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j)
				if (j % 3 == 0) cout << "#" << setw(8) << setfill(' ');
				else cout << "|" << setw(8) << setfill(' ');
			cout << "#" << endl;
		}
		cout << setw(50) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";

		ch = _getch();

		//����������� �� ����
		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			case Up:
				if (row != 0) --row;
				else row = 8;
				break;
			case Down:
				if (row != 8) ++row;
				else row = 0;
				break;
			case Right:
				if (col != 8) ++col;
				else col = 0;
				break;
			case Left:
				if (col != 0) --col;
				else col = 8;
				break;
			}
		}

		//�������� ����� �� ����
		if (ch >= '1' && ch <= '9')
			grid[row][col] = ch;

		//�������� ����� � ����
		if (ch == Backspace)
			grid[row][col] = 0;
		system("cls");
	} while (ch != Enter && ch != Esc);
}
//������ ����� �����
inline void read(char file_name[31]) {
	int ind = 0, otst;
	bool err_NoName = false, err_More30 = false;
	do {
		sudoku();
		cout << setw(95) << "������� ��� �����:" << endl;
		otst = (172 - ind + (ind % 2 != 0 ? 1 : 0)) / 2 + ind;
		cout << setw(otst) << file_name << endl;
		if (err_NoName) cout << setw(96) << "��� ����� �� �������" << endl;
		if (err_More30) cout << setw(110) << "��� ����� ������ ��������� �� ����� 30 ��������" << endl;
		err_More30 = err_NoName = false;

		ch = _getch();

		//���������� � ��� ����� ��������� � �������� ��������� ����, ����
		if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			if (ind < 30) file_name[ind++] = ch;
			else err_More30 = true;

		//�������� �� ����� ����� ��������
		if (ch == Backspace) {
			if (ind > 0) file_name[--ind] = '\0';

		}

		//�������� �� ������������ �����
		if (ch == Enter) {
			if (file_name[0] == '\0') {
				err_NoName = true;
				ch = 0;
			}
		}
		system("cls");
	} while (ch != Enter && ch != Esc);
}

//��������� ����� �� ��������� �� ������ ����� ���� �������
bool check(unsigned char grid[9][9], unsigned char sol_grid[9][9], const int& row, const int& col, const unsigned char& val) {
	//�������� �� ���������� ������� �������� � ������
	for (int i = 0; i < 9; ++i)
		if (grid[row][i] == val || sol_grid[row][i] == val) return false;

	//�������� �� ���������� ������� �������� � �������
	for (int i = 0; i < 9; ++i)
		if (grid[i][col] == val || sol_grid[i][col] == val) return false;

	//�������� �� ���������� ������� �������� � ������
	int startX = row / 3 * 3;
	int startY = col / 3 * 3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (grid[startX + i][startY + j] == val || sol_grid[startX + i][startY + j] == val) return false;

	return true;
}
//������ ������
void solution(unsigned char grid[9][9], unsigned char sol_grid[9][9], unsigned char ans[9][9], int& ansCount, const int& row, const int& col) {
	if (ansCount > 1) return;
	if (row == 9 && col == 0) {

		//��������� ������� � ������� �������
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				ans[i][j] = sol_grid[i][j];

		//�������������� ������� �����1
		++ansCount;
		return;
	}

	if (grid[row][col] > 0)
		if (col < 8) solution(grid, sol_grid, ans, ansCount, row, col + 1);
		else solution(grid, sol_grid, ans, ansCount, row + 1, 0);

	for (unsigned char value = '1'; value <= '9'; ++value)
		if (check(grid, sol_grid, row, col, value)) {
			sol_grid[row][col] = value;
			if (col < 8) solution(grid, sol_grid, ans, ansCount, row, col + 1);
			else solution(grid, sol_grid, ans, ansCount, row + 1, 0);
			sol_grid[row][col] = 0;
		}
}

//���������������� �������
inline void transposing(unsigned char grid[9][9]) {
	unsigned char temp;
	for (int i = 0; i < 9; ++i)
		for (int j = i; j < 9; ++j) {
			temp = grid[i][j];
			grid[i][j] = grid[j][i];
			grid[j][i] = temp;
		}
}
//������ ������� ��� ������ � ����� ������
inline void swap_rows_small(unsigned char grid[9][9], const unsigned char& row1, const unsigned char& row2) {
	unsigned char temp;
	for (int i = 0; i < 9; ++i) {
		temp = grid[row1][i];
		grid[row1][i] = grid[row2][i];
		grid[row2][i] = temp;
	}
}
//������ ������� ��� ������� � ����� ������
inline void swap_cols_small(unsigned char grid[9][9], const unsigned char& col1, const unsigned char& col2) {
	unsigned char temp;
	for (int i = 0; i < 9; ++i) {
		temp = grid[i][col1];
		grid[i][col1] = grid[i][col2];
		grid[i][col2] = temp;
	}
}
//������ ������� ��� ������ �� �����������
inline void swap_rows_area(unsigned char grid[9][9], const unsigned char& row1, const unsigned char& row2) {
	unsigned char temp1, temp2, temp3;
	for (int i = 0; i < 9; ++i) {
		temp1 = grid[row1 * 3][i];
		temp2 = grid[row1 * 3 + 1][i];
		temp3 = grid[row1 * 3 + 2][i];
		grid[row1 * 3][i] = grid[row2 * 3][i];
		grid[row1 * 3 + 1][i] = grid[row2 * 3 + 1][i];
		grid[row1 * 3 + 2][i] = grid[row2 * 3 + 2][i];
		grid[row2 * 3][i] = temp1;
		grid[row2 * 3 + 1][i] = temp2;
		grid[row2 * 3 + 2][i] = temp3;
	}
}
//������ ������� ��� ������ �� ���������
inline void swap_cols_area(unsigned char grid[9][9], const unsigned char& col1, const unsigned char& col2) {
	unsigned char temp1, temp2, temp3;
	for (int i = 0; i < 9; ++i) {
		temp1 = grid[i][col1 * 3];
		temp2 = grid[i][col1 * 3 + 1];
		temp3 = grid[i][col1 * 3 + 2];
		grid[i][col1 * 3] = grid[i][col2 * 3];
		grid[i][col1 * 3 + 1] = grid[i][col2 * 3 + 1];
		grid[i][col1 * 3 + 2] = grid[i][col2 * 3 + 2];
		grid[i][col2 * 3] = temp1;
		grid[i][col2 * 3 + 1] = temp2;
		grid[i][col2 * 3 + 2] = temp3;
	}
}

/*
1 - ������� ����� ��������� �������� ������ - 0,97�
2 - ������� ����� ��������� �������� ������ - 1,9�
3 - ������� ����� ��������� �������� ������ - 2,9�
4 - ������� ����� ��������� ����������� ������ - 3,75�
*/

//���������� ���������� �������
void Generation(unsigned char grid[9][9], const unsigned char& complexity) {
	//��������� "�������" �������
	/*
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			grid[i][j] = (i / 3 + j + (i % 3 == 0 ? 1 : (i % 3 == 1 ? 4 : 7))) != 9 ? (i / 3 + j + (i % 3 == 0 ? 1 : (i % 3 == 1 ? 4 : 7))) % 9 : 9;
			grid[i][j] += (int)'0';
		}
	*/
	grid[0][0] = '4'; grid[0][1] = '2'; grid[0][2] = '7'; grid[0][3] = '1'; grid[0][4] = '3'; grid[0][5] = '9'; grid[0][6] = '5'; grid[0][7] = '6'; grid[0][8] = '8';
	grid[1][0] = '9'; grid[1][1] = '1'; grid[1][2] = '5'; grid[1][3] = '8'; grid[1][4] = '7'; grid[1][5] = '6'; grid[1][6] = '3'; grid[1][7] = '4'; grid[1][8] = '2';
	grid[2][0] = '6'; grid[2][1] = '8'; grid[2][2] = '3'; grid[2][3] = '5'; grid[2][4] = '4'; grid[2][5] = '2'; grid[2][6] = '1'; grid[2][7] = '9'; grid[2][8] = '7';
	grid[3][0] = '2'; grid[3][1] = '5'; grid[3][2] = '6'; grid[3][3] = '9'; grid[3][4] = '1'; grid[3][5] = '8'; grid[3][6] = '4'; grid[3][7] = '7'; grid[3][8] = '3';
	grid[4][0] = '3'; grid[4][1] = '4'; grid[4][2] = '9'; grid[4][3] = '2'; grid[4][4] = '6'; grid[4][5] = '7'; grid[4][6] = '8'; grid[4][7] = '5'; grid[4][8] = '1';
	grid[5][0] = '8'; grid[5][1] = '7'; grid[5][2] = '1'; grid[5][3] = '4'; grid[5][4] = '5'; grid[5][5] = '3'; grid[5][6] = '9'; grid[5][7] = '2'; grid[5][8] = '6';
	grid[6][0] = '5'; grid[6][1] = '9'; grid[6][2] = '8'; grid[6][3] = '6'; grid[6][4] = '2'; grid[6][5] = '1'; grid[6][6] = '7'; grid[6][7] = '3'; grid[6][8] = '4';
	grid[7][0] = '7'; grid[7][1] = '6'; grid[7][2] = '4'; grid[7][3] = '3'; grid[7][4] = '8'; grid[7][5] = '5'; grid[7][6] = '2'; grid[7][7] = '1'; grid[7][8] = '9';
	grid[8][0] = '1'; grid[8][1] = '3'; grid[8][2] = '2'; grid[8][3] = '7'; grid[8][4] = '9'; grid[8][5] = '4'; grid[8][6] = '6'; grid[8][7] = '8'; grid[8][8] = '5';

	int randX, randY, randR, trans, ansCount, temp;
	unsigned char sol_grid[9][9] = { '\0' }, ans[9][9] = { '\0' };
	//10 ��� ������������ ��������� ������ � ������ ������������� �������
	for (int i = 0; i < 20; ++i) {
		randX = rand() % 3;
		randY = rand() % 3;
		randR = rand() % 3;
		swap_rows_small(grid, randR * 3 + randX, randR * 3 + randY);

		if (i % 2 == 1) {
			randX = rand() % 3;
			randY = rand() % 3;
			trans = rand() % 2;
			swap_cols_area(grid, randX, randY);
			if (trans) transposing(grid);
		}

		randX = rand() % 3;
		randY = rand() % 3;
		randR = rand() % 3;
		swap_cols_small(grid, randR * 3 + randX, randR * 3 + randY);
	
		if (i % 2) {
			randX = rand() % 3;
			randY = rand() % 3;
			trans = rand() % 2;
			swap_rows_area(grid, randX, randY);
			if (trans) transposing(grid);
		}
	}
	/*
	//10 ��� ������������ ��������� ������� � ������ ������������� �������
	for (int i = 0; i < 10; ++i) {
		randX = rand() % 3;
		randY = rand() % 3;
		randR = rand() % 3;
		trans = rand() % 2;
		swap_cols_small(grid, randR * 3 + randX, randR * 3 + randY);
		if (trans) transposing(grid);
	}
	*/
	/*
	//7 ��� ������������ ��������� ������  �� ����������� � ������ ������������� �������
	for (int i = 0; i < 7; ++i) {
		randX = rand() % 3;
		randY = rand() % 3;
		trans = rand() % 2;
		swap_rows_area(grid, randX, randY);
		if (trans) transposing(grid);
	}
	//7 ��� ������������ ��������� ������  �� ��������� � ������ ������������� �������
	for (int i = 0; i < 7; ++i) {
		randX = rand() % 3;
		randY = rand() % 3;
		trans = rand() % 2;
		swap_cols_area(grid, randX, randY);
		if (trans) transposing(grid);
	}
	*/

	unsigned char count = 81, countSave = 0;
	bool  see_grid[9][9] = { false };
	//������� �������
	if (complexity == 1) {
		randX = rand() % 6;
		count -= 30 + randX;
	}
	else
		//������� �������
		if (complexity == 2) {
			randX = rand() % 6;
			count -= 25 + randX;
		}
		else
			//������� �������
			if (complexity == 3) {
				randX = rand() % 6;
				count -= 20 + randX;
			}
			else
				//���������� �������
				if (complexity == 4)
					while (true) {
						randX = rand() % 9;
						randY = rand() % 9;
						if (see_grid[randX][randY] == false) {
							see_grid[randX][randY] = true;
							ansCount = 0;
							for (int i = 0; i < 9; ++i)
								for (int j = 0; j < 9; ++j)
									sol_grid[i][j] = ans[i][j] = '\0';

							temp = grid[randX][randY];
							grid[randX][randY] = '\0';
							solution(grid, sol_grid, ans, ansCount, 0, 0);
							if (ansCount != 1) grid[randX][randY] = temp;
						}

						count = 0;
						for (int i = 0; i < 9; ++i)
							for (int j = 0; j < 9; ++j)
								if (see_grid[i][j]) ++count;

						if (count == 81) {
							count = 0;
							break;
						}
					}



	while (count != 0) {
		randX = rand() % 9;
		randY = rand() % 9;
		if (see_grid[randX][randY] == false) {
			see_grid[randX][randY] = true;
			ansCount = 0;
			for (int i = 0; i < 9; ++i)
				for (int j = 0; j < 9; ++j)
					sol_grid[i][j] = ans[i][j] = '\0';


			temp = grid[randX][randY];
			grid[randX][randY] = '\0';
			solution(grid, sol_grid, ans, ansCount, 0, 0);
			if (ansCount != 1) grid[randX][randY] = temp;
			else --count;
		}

		countSave = 0;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (see_grid[i][j]) ++countSave;

		if (countSave == 81) {
			count = 0;
			break;
		}
	}
}

//���������� �������, ���� ������, ���������� ������ � ����� ������� "level passed"
inline bool check_solution(unsigned char grid[9][9], unsigned char us_grid[9][9], unsigned char us_grid_note[9][9]) {
	unsigned char sol_grid[9][9] = { '\0' }, ans[9][9] = { '\0' };
	bool check[9][9];
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			check[i][j] = true;
	int ansCount = 0, rightCount = 0, cellCount = 0;
	solution(grid, sol_grid, ans, ansCount, 0, 0);
	//cellCount - ���������� ����� ��� ����������
	//rightCount - ���������� ����� ����������� �����

	//�������� ����������� �������
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			if (grid[i][j] == '\0' && ans[i][j] != us_grid[i][j] && us_grid[i][j] != '\0') check[i][j] = false;
			if (grid[i][j] == '\0') ++cellCount;
			if (us_grid[i][j] == ans[i][j] && grid[i][j] == '\0') ++rightCount;
		}

	system("cls");
	if (cellCount == rightCount) {
		return true;
	}
	//������� � ���������� ������
	else {
		sudoku();

		//����� �������
		for (int i = 0; i < 9; ++i) {
			if (i % 3 == 0) cout << setw(50) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";
			else {
				cout << setw(50) << setfill(' ') << ' ' << "#";
				cout << setw(24) << setfill('�') << "#";
				cout << setw(24) << setfill('�') << "#";
				cout << setw(24) << setfill('�') << "#";
			}
			cout << endl;

			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j) {
				if (j % 3 == 0) cout << "#";
				else cout << "|";
				if (grid[i][j] != 0) {
					SetColor(Blue, Black);
					cout << ' ' << setw(6) << setfill('*') << ' ';
					SetColor(White, Black);
				}
				else
					if (!check[i][j]) {
						SetColor(Red, Black);
						cout << ' ' << setw(5) << setfill('*') << '*';
						if (us_grid_note[i][j] != '\0') {
							SetColor(Magenta, Black);
							cout << us_grid_note[i][j];
						}
						else cout << ' ';
						SetColor(White, Black);
					}
					else
						if (us_grid_note[i][j] != '\0') {
							SetColor(Magenta, Black);
							cout << "      " << us_grid_note[i][j];
							SetColor(White, Black);
						}
						else cout << "       ";
			}
			cout << "#" << endl;

			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j) {
				if (j % 3 == 0) cout << "#";
				else cout << "|";
				if (grid[i][j] != '\0') {
					SetColor(Blue, Black);
					cout << " * ";
					SetColor(White, Black);
					cout << grid[i][j];
					SetColor(Blue, Black);
					cout << " * ";
					SetColor(White, Black);
				}
				else
					if (us_grid[i][j] != '\0') {
						if (!check[i][j]) {
							SetColor(Red, Black);
							cout << " * ";
							SetColor(White, Black);
							cout << us_grid[i][j];
							SetColor(Red, Black);
							cout << " * ";
							SetColor(White, Black);
						}
						else cout << "   " << us_grid[i][j] << "   ";
					}
					else cout << setw(8) << setfill(' ');
			}
			cout << "#" << endl;


			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j) {
				if (j % 3 == 0) cout << "#";
				else cout << "|";
				if (grid[i][j] != 0) {
					SetColor(Blue, Black);
					cout << ' ' << setw(6) << setfill('*') << ' ';
					SetColor(White, Black);
				}
				else
					if (!check[i][j]) {
						SetColor(Red, Black);
						cout << ' ' << setw(6) << setfill('*') << ' ';
						SetColor(White, Black);
					}
					else cout << "       ";
			}
			cout << "#" << endl;
		}
		cout << setw(50) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";

		cout << endl << setfill(' ') << setw(70) << "��������� ����" << setw(46) << "[���������]";
		Sleep(3000);
	}
	return false;
}

//���� � ��������������� ������
/*
1 - ����� ����
2 - ����������� ����������� ����
*/
void Game(unsigned char grid[9][9], const unsigned char& modification) {
	unsigned char  row = 4, col = 4, us_grid[9][9] = { '\0' }, us_grid_note[9][9] = { '\0' }, podType = 1;

	if (modification == 2) {
		FILE* file = fopen("SavedLvl", "rb");
		if (file != NULL)
		{
			fread(grid, 9, 9, file);
			fread(us_grid, 9, 9, file);
			fread(us_grid_note, 9, 9, file);
			fclose(file);
		}

	}

	do {
		sudoku();

		//����� �������
		for (int i = 0; i < 9; ++i) {
			if (i % 3 == 0) cout << setw(50) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";
			else {
				cout << setw(50) << setfill(' ') << ' ' << "#";
				cout << setw(24) << setfill('�') << "#";
				cout << setw(24) << setfill('�') << "#";
				cout << setw(24) << setfill('�') << "#";
			}
			cout << endl;

			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j) {
				if (j % 3 == 0) cout << "#";
				else cout << "|";
				if (grid[i][j] != 0) {
					SetColor(Blue, Black);
					cout << ' ' << setw(6) << setfill('*') << ' ';
					SetColor(White, Black);
				}
				else
					if (us_grid_note[i][j] != '\0') {
						SetColor(Magenta, Black);
						cout << "      " << us_grid_note[i][j];
						SetColor(White, Black);
					}
					else cout << "       ";
			}
			cout << "#" << endl;

			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j) {
				if (j % 3 == 0) cout << "#";
				else cout << "|";
				if (grid[i][j] != '\0')
					if (i == row && j == col) {
						SetColor(Blue, Black);
						cout << " *";
						SetColor(White, Black);
						cout << '[' << grid[i][j] << ']';
						SetColor(Blue, Black);
						cout << "* ";
						SetColor(White, Black);
					}
					else {
						SetColor(Blue, Black);
						cout << " * ";
						SetColor(White, Black);
						cout << grid[i][j];
						SetColor(Blue, Black);
						cout << " * ";
						SetColor(White, Black);
					}
				else
					if (us_grid[i][j] != '\0') {
						if (i == row && j == col) cout << " [ " << us_grid[i][j] << " ] ";
						else cout << "   " << us_grid[i][j] << "   ";
					}
					else
						if (i == row && j == col) cout << " [   ] ";
						else cout << setw(8) << setfill(' ');
			}
			cout << "#" << endl;


			cout << setw(50) << setfill(' ') << ' ';
			for (int j = 0; j < 9; ++j) {
				if (j % 3 == 0) cout << "#";
				else cout << "|";
				if (grid[i][j] != 0) {
					SetColor(Blue, Black);
					cout << ' ' << setw(6) << setfill('*') << ' ';
					SetColor(White, Black);
				}
				else cout << "       ";
			}
			cout << "#" << endl;
		}
		cout << setw(50) << setfill(' ') << ' ' << setw(73) << setfill('#') << "#";

		if (row == 9 && podType == 1) cout << endl << setfill(' ') << setw(71) << "[��������� ����]" << setw(44) << "���������";
		else
			if (row == 9 && podType == 2) cout << endl << setfill(' ') << setw(70) << "��������� ����" << setw(46) << "[���������]";
			else cout << endl << setfill(' ') << setw(70) << "��������� ����" << setw(45) << "���������";

		ch = _getch();

		//����������� �� ���� � �������� ����� � ���� � �������� �������
		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			case Up:
				if (row != 0) --row;
				else row = 9;
				break;
			case Down:
				if (row != 9) ++row;
				else row = 0;
				break;
			case Right:
				if (col != 8) ++col;
				else col = 0;
				if (row == 9) podType = 2;
				break;
			case Left:
				if (col != 0) --col;
				else col = 8;
				if (row == 9) podType = 1;
				break;
			case Delete:
				us_grid_note[row][col] = '\0';
				break;
			}
		}

		//�������� ����� �� ����
		if (ch >= '1' && ch <= '9' && grid[row][col] == '\0') us_grid[row][col] = ch;

		//�������� ����� �� ���� � �������� �������
		if (grid[row][col] == '\0')
			if (ch == '!') us_grid_note[row][col] = '1';
			else if (ch == '@' || ch == '"') us_grid_note[row][col] = '2';
			else if (ch == '#' || ch == 252) us_grid_note[row][col] = '3';
			else if (ch == '$' || ch == ';') us_grid_note[row][col] = '4';
			else if (ch == '%') us_grid_note[row][col] = '5';
			else if (ch == '^' || ch == ':') us_grid_note[row][col] = '6';
			else if (ch == '&' || ch == '?') us_grid_note[row][col] = '7';
			else if (ch == '*') us_grid_note[row][col] = '8';
			else if (ch == '(') us_grid_note[row][col] = '9';

		//�������� �������� � ����
		if (ch == Backspace && grid[row][col] == '\0') us_grid[row][col] = '\0';

		if (ch == Enter && row == 9) {
			//��������� ������ � ����
			if (podType == 1) {
				FILE* file = fopen("SavedLvl", "wb");
				fwrite(grid, 1, 81, file);
				fwrite(us_grid, 1, 81, file);
				fwrite(us_grid_note, 1, 81, file);
				fclose(file);
			}
			else
				//��������� ������
				if (podType == 2) {
					if (check_solution(grid, us_grid, us_grid_note)) {
						system("cls");
						levelPassed();
						break;
					}
					ch = 0;
				}
		}
		else
			if (ch == Enter) ch = 0;

		system("cls");
	} while (ch != Enter && ch != Esc);
}

//�������� ����
inline menu* initMenu() {
	menu* head = new menu();
	menu* temp1 = new menu();
	menu* temp2 = new menu();

	head->arr[0] = '�';
	head->arr[1] = '�';
	head->arr[2] = '�';
	head->arr[3] = '�';
	head->arr[4] = '�';
	head->arr[5] = ' ';
	head->arr[6] = '�';
	head->arr[7] = '�';
	head->arr[8] = '�';
	head->arr[9] = '�';
	head->next = temp1;
	head->prev = temp2;

	temp1->arr[0] = '�';
	temp1->arr[1] = '�';
	temp1->arr[2] = '�';
	temp1->arr[3] = '�';
	temp1->arr[4] = '�';
	temp1->arr[5] = '�';
	temp1->arr[6] = '�';
	temp1->arr[7] = '�';
	temp1->arr[8] = '�';
	temp1->arr[9] = '�';
	temp1->arr[10] = ' ';
	temp1->arr[11] = '�';
	temp1->arr[12] = '�';
	temp1->arr[13] = '�';
	temp1->arr[14] = '�';
	temp1->arr[15] = '�';
	temp1->arr[16] = '�';
	temp1->arr[17] = '�';
	temp1->arr[18] = '�';
	temp1->arr[19] = '�';
	temp1->arr[20] = '�';
	temp1->arr[21] = '�';
	temp1->arr[22] = ' ';
	temp1->arr[23] = '�';
	temp1->arr[24] = '�';
	temp1->arr[25] = '�';
	temp1->arr[26] = '�';
	temp1->next = temp2;
	temp1->prev = head;

	temp2->arr[0] = '�';
	temp2->arr[1] = '�';
	temp2->arr[2] = '�';
	temp2->arr[3] = '�';
	temp2->arr[4] = '�';
	temp2->arr[5] = '�';
	temp2->arr[6] = ' ';
	temp2->arr[7] = '�';
	temp2->arr[8] = '�';
	temp2->arr[9] = '�';
	temp2->arr[10] = '�';
	temp2->arr[11] = '�';
	temp2->arr[12] = '�';
	temp2->next = head;
	temp2->prev = temp1;

	return head;
}

//�������� ����
inline void delMenu(menu* head) {
	delete head->prev;
	delete head->next;
	delete head;
}

int main() {
	//���������� ������� �� ���� �����
	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
	
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	unsigned char grid[9][9] = { '\0' }, type = 1;
	unsigned char sol_grid[9][9] = { '\0' }, ans[9][9] = { '\0' }, podType = 1;
	char file_name[31] = { '\0' };//��� ����� ����������� ������ ���� char
	int ansCount = 0;
	bool f1 = true, f2 = true;

	menu* head = initMenu();
	do {
		//���������� �� ������������� ���������
		if (f1) {
			do {
				sudoku();
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
					<< setfill(' ') << setw(104) << "��� ������ ������ ���� ������� Enter" << endl
					<< setw(123) << "��� ����������� ����� �������� ���� �������������� ��������� ����� � ����" << endl
					<< setw(111) << "��� ����������� � ��������� ���� ������� Backspace" << endl
					<< setw(108) << "��� ���������� ������ ��������� ������� Esc" << endl
					<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
					<< setw(101) << "��� ����������� ������� Enter" << endl;
				ch = _getch();
				system("cls");
			} while (ch != Enter);
			f1 = false;
		}

		sudoku();
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
			<< setw(81) << (type == 1 ? '[' : ' ') << head->arr << (type == 1 ? ']' : ' ') << endl << endl
			<< setw(73) << (type == 2 ? '[' : ' ') << head->next->arr << (type == 2 ? ']' : ' ') << endl << endl
			<< setw(80) << (type == 3 ? '[' : ' ') << head->prev->arr << (type == 3 ? ']' : ' ') << endl;


		/*
		if (type == 1) cout << endl << setw(92) << "[����� ����]" << endl;
		else cout << endl << setw(91) << "����� ����" << endl;
		if (type == 2) cout << endl << setw(101) << "[���������� ����������� ����]" << endl;
		else cout << endl << setw(100) << "���������� ����������� ����" << endl;
		if (type == 3) cout << endl << setw(94) << "[������ ������]" << endl;
		else cout << endl << setw(93) << "������ ������" << endl;
		*/
		
		//����������� �� ����
		ch = _getch();
		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			case Up:
				if (type != 1) --type;
				else type = 3;
			break;
			case Down:
				if (type != 3) ++type;
				else type = 1;
			break;
			}
		}

		//��� ������ ������ ��������� ��������� ����
		if (ch == Enter) {
			switch (type) {
			//��������� ������ ������
			case 1:
				podType = 1;

				//�������
				do {
					system("cls");
					sudoku();
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					if (podType == 1) cout << setw(95) << "[������� �������]" << endl;
					else cout << setw(94) << "������� �������" << endl;
					if (podType == 2) cout << endl << setw(95) << "[������� �������]" << endl;
					else cout << endl << setw(94) << "������� �������" << endl;
					if (podType == 3) cout << endl << setw(95) << "[������� �������]" << endl;
					else cout << endl << setw(94) << "������� �������" << endl;
					if (podType == 4) cout << endl << setw(96) << "[���������� �������]" << endl;
					else cout << endl << setw(95) << "���������� �������" << endl;

					ch = _getch();

					//����������� �� ����
					if (ch == 224) {
						ch = _getch();
						switch (ch) {
						case Up:
							if (podType != 1) --podType;
							else podType = 4;
							break;
						case Down:
							if (podType != 4) ++podType;
							else podType = 1;
							break;
						}
					}

					if (ch == Enter) {
						//���������� �� ����
						if (f2) {
							do {
								system("cls");
								sudoku();
								cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
									<< setfill(' ') << setw(124) << "��� ����������� �� ���� �������������� ��������� �����, ����, ������ � �����" << endl
									<< setw(118) << "��� ���������� ����� �� ���� ������� �� ������� � ������ ������" << endl
									<< setw(112) << "��� �������� � ���� ����� ������� ������� Backspace" << endl
									<< setw(126) << "��� ���������� ����� � �������� ������� ������� Shift + ������� � ������ ������" << endl
									<< setw(107) << "��� �������� �����-������� ������� Delete" << endl
									<< setw(113) << "��� ������ ������ ������� �������� ��� � ������� Enter" << endl
									<< setw(115) << "��� ������ ������ ������� \"���������\" ���� ����� ���������" << endl
									<< setw(132) << "��� ������ ������ ������� \"��������\" �� 3 ������� ����� �������� ���� � ����������� ��������" << endl
									<< setw(115) << "��� ������ �� ���� � �������� � �������� ���� ������� Esc" << endl
									<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
									<< setw(101) << "��� ����������� ������� Enter" << endl;
								ch = _getch();
							} while (ch != Enter);
							f2 = false;
						}

						system("cls");
						Generation(grid, podType);
						Game(grid, 1);
						ch = Backspace;
					}
						
				} while (ch != Backspace && ch != Esc);
			break;
			//�������� ������ �� �����
			case 2:
			{
				system("cls");
				Game(grid, 2);
				if (ch == Esc) ch = 0;
			}
			break;
			//������� ������, ���������� �������
			case 3:
				system("cls");
				podType = 1;

				//�������
				do {
					sudoku();
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					if (podType == 1) cout << endl << setw(98) << "[������ ������ �������]" << endl;
					else cout << endl << setw(97) << "������ ������ �������" << endl;
					if (podType == 2) cout << endl << setw(99) << "[Co������� ������ � ����]" << endl;
					else cout << endl << setw(98) << "Co������� ������ � ����" << endl;
					if (podType == 3) cout << endl << setw(99) << "[������� ������ �� �����]" << endl;
					else cout << endl << setw(98) << "������� ������ �� �����" << endl;

					ch = _getch();
					//����������� �� ����
					if (ch == 224) {
						ch = _getch();
						switch (ch) {
						case Up:
							if (podType != 1) --podType;
							else podType = 3;
							break;
						case Down:
							if (podType != 3) ++podType;
							else podType = 1;
							break;
						}
					}

					if (ch == Enter)
						switch (podType) {
							//���� ������ � ������ � �� �������
						case 1: {
							system("cls");
							for (int i = 0; i < 9; ++i)
								for (int j = 0; j < 9; ++j)
									grid[i][j] = sol_grid[i][j] = ans[i][j] = '\0';
							ansCount = 0;
							bool f = true;

							read(grid);
							if (ch != Esc) {
								for (int i = 0; i < 9; ++i) {
									for (int j = 0; j < 9; ++j)
										if (grid[i][j] != '\0') {
											//�������� �� ���������� ������� �������� � ������
											for (int k = 0; k < 9; ++k)
												if (grid[i][j] == grid[i][k] && j != k) f = false;

											//�������� �� ���������� ������� �������� � �������
											for (int k = 0; k < 9; ++k)
												if (grid[i][j] == grid[k][j] && i != k) f = false;

											//�������� �� ���������� ������� �������� � ������
											int startX = i / 3 * 3;
											int startY = j / 3 * 3;
											for (int p = 0; p < 3; ++p)
												for (int q = 0; q < 3; ++q)
													if (grid[startX + p][startY + q] ==  grid[i][j] && (startX + p) != i && (startY + q) != j) f = false;
										}
										
									if (!f) break;
								}

								if (f) solution(grid, sol_grid, ans, ansCount, 0, 0);

								if (ansCount == 1) {
									print(grid, ans);
								}
								else
									if (!f) noAnswer();
									else manyDecisions();

								ch = _getch();
							}
							else ch = 0;
							break;
						}
							//���������� ��������� � ������ ������ � ����
						case 2:
							system("cls");
							for (int i = 0; i < 9; ++i)
								for (int j = 0; j < 9; ++j)
									grid[i][j] = '\0';
							for (int i = 0; i < 31; ++i) file_name[i] = '\0';

							read(grid);
							if (ch != Esc) {
								read(file_name);
								if (ch != Esc) {
									FILE* file = fopen(file_name, "wb");
									fwrite(grid, 1, 81, file);
									fclose(file);
								}
								else ch = 0;
							}
							else ch = 0;
							break;
							//�������� ������ �� ����� � �� �������
						case 3: {
							system("cls");
							for (int i = 0; i < 9; ++i)
								for (int j = 0; j < 9; ++j)
									grid[i][j] = sol_grid[i][j] = ans[i][j] = '\0';
							ansCount = 0;
							for (int i = 0; i < 31; ++i) file_name[i] = '\0';

							read(file_name);
							if (ch != Esc) {
								FILE* file = fopen(file_name, "rb");
								if (file == NULL) noFile();
								else {
									fread(grid, 9, 9, file);
									fclose(file);
								}
								system("cls");

								bool f = true;
								for (int i = 0; i < 9; ++i) {
									for (int j = 0; j < 9; ++j)
										if (grid[i][j] != '\0') {
											//�������� �� ���������� ������� �������� � ������
											for (int k = 0; k < 9; ++k)
												if (grid[i][j] == grid[i][k] && j != k) f = false;

											//�������� �� ���������� ������� �������� � �������
											for (int k = 0; k < 9; ++k)
												if (grid[i][j] == grid[k][j] && i != k) f = false;

											//�������� �� ���������� ������� �������� � ������
											int startX = i / 3 * 3;
											int startY = j / 3 * 3;
											for (int p = 0; p < 3; ++p)
												for (int q = 0; q < 3; ++q)
													if (grid[startX + p][startY + q] == grid[i][j] && (startX + p) != i && (startY + q) != j) f = false;
										}

									if (!f) break;
								}

								if (f)solution(grid, sol_grid, ans, ansCount, 0, 0);
								if (ansCount == 1) {
									print(grid, ans);
								}
								else
									if (!f) print_noAnswer(grid);
									else print_manyDecisions(grid);
								ch = _getch();
							}
							else ch = 0;
							break;
						}
						}
					system("cls");
				} while (ch != Backspace && ch != Esc);
				break;
			}
		}

		system("cls");
	} while (ch != Esc);
	delMenu(head);

	return 0;
}