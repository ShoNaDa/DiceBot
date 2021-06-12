#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

void function()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "-";
	}
	cout << endl;
}

string kub(string kub, int chislo)
{
	switch (chislo)
	{
	case 1:
		cout << "-----" << endl << "|   |" << endl << "| X |" << endl << "|   |" << endl << "-----" << endl;
		break;
	case 2:
		cout << "-----" << endl << "|   |" << endl << "|X X|" << endl << "|   |" << endl << "-----" << endl;
		break;
	case 3:
		cout << "-----" << endl << "| X |" << endl << "|   |" << endl << "|X X|" << endl << "-----" << endl;
		break;
	case 4:
		cout << "-----" << endl << "|X X|" << endl << "|   |" << endl << "|X X|" << endl << "-----" << endl;
		break;
	case 5:
		cout << "-----" << endl << "|X X|" << endl << "| X |" << endl << "|X X|" << endl << "-----" << endl;
		break;
	case 6:
		cout << "-----" << endl << "|XXX|" << endl << "|   |" << endl << "|XXX|" << endl << "-----" << endl;
		break;
	}
	return kub;
}

string vibor(int monetka, int vibor1, string igra)
{
	igra = "a";
	cout << "\nНажмите любую клавишу, чтобы подкинуть монетку\n";
	_getch();
	switch (vibor1)
	{
	case 1:
		if (vibor1 == monetka)
		{
			cout << "Выпала решка, вы ходите первый" << endl;
			igra = "Игрок";
			function();
		}
		else
		{
			cout << "Выпал орел, первый ходит бот" << endl;
			igra = "Бот";
			function();
		}
		break;
	case 2:
		if (vibor1 == monetka)
		{
			cout << "Выпал орел, вы ходите первый" << endl;
			igra = "Игрок";
			function();
		}
		else
		{
			cout << "Выпала решка, первый ходит бот" << endl;
			igra = "Бот";
			function();
		}
		break;
	default:
		cout << "Вы выбрали что-то другое" << endl;
		function();
	}
	return igra;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int z = 1;
	int monetka, vibor1;
	string igra = "a";
	int kubic, kubik;
	int sum_kubik = 0;
	string cub;
	int chislo;
	int kubic1, kubik1;
	int sum_kubik1 = 0;
	int sum = 0;
	int sum1 = 0;

	while (z <= 4)
	{
		srand(time(NULL));
		monetka = 1 + rand() % 2;
		Sleep(1000);
		igra = "a";
		cout << "Чтобы выбрать, кто первый бросит кубики, нужно подбросить монетку, \nнапишите 1, если ставите на решку и 2, если на орла" << endl;
		
		while (igra == "a")
		{
			cin >> vibor1;
			igra = vibor(monetka, vibor1, igra);
		}
		int t = 0;
		int p = 0, o = 0, l = 0;
		while (t < 2)
		{
			if ((igra == "Игрок" && p == 0) || (t != 0 && p == 0))
			{
				cout << "Нажмите любую кнопку, чтобы бросить кости (это может занять некоторое время)" << endl;
				_getch();
				p++;
			}

			if ((igra == "Игрок" && o == 0) || (t != 0 && o == 0))
			{
				srand(time(NULL));
				kubic = 1 + rand() % 6;
				Sleep(1500);
				srand(time(NULL));
				kubik = 1 + rand() % 6;
				Sleep(1000);
				cout << endl;
				sum_kubik = kubik + kubic;
				cout << "Игрок набрал " << sum_kubik << " очков" << endl;
				sum += sum_kubik;
				cout << "Общее количество очков - " << sum << endl;

				chislo = kubic;
				kub(cub, chislo);
				cout << endl;
				chislo = kubik;
				kub(cub, chislo);
				function();
				o++;
			}

			if ((igra == "Бот" && l == 0) || (t != 0 && l == 0))
			{
				srand(time(NULL));
				kubic1 = 1 + rand() % 6;
				Sleep(1500);
				srand(time(NULL));
				kubik1 = 1 + rand() % 6;
				Sleep(1000);

				if (igra == "Бот")
				{
					igra = "Игрок";
				}
				else
				{
					igra = "Бот";
				}
				cout << endl;

				sum_kubik1 = kubik1 + kubic1;
				cout << "Бот набрал " << sum_kubik1 << " очков" << endl;
				sum1 += sum_kubik1;
				cout << "Общее количество очков - " << sum1 << endl;
				chislo = kubic1;
				kub(cub, chislo);
				cout << endl;
				chislo = kubik1;
				kub(cub, chislo);
				function();
				l++;
			}
			t++;
		}
		z++;
	}

	if (sum == sum1)
	{
		cout << "Ничья" << endl;
	}
	else if (sum > sum1)
	{
		cout << "Вы победили" << endl;
	}
	else if (sum < sum1)
	{
		cout << "Вы проиграли" << endl;
	}
}