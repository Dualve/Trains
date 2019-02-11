#include <iostream>

using namespace std;

const int amount = 10;
bool flag = true;

int main()
{
	setlocale(LC_ALL, "Rus");

	struct Train
	{
		char name[80];
		char number[20];
		float time;
	};

	Train amountOftrain[amount];

	for (int i = 0; i < amount; i++)
	{
		cout << "Введите название пункта назначения: " << endl;
		cin >> amountOftrain[i].name;
		cout << "Введиет номер поезда: " << endl;
		cin >> amountOftrain[i].number;

		do
		{
			cout << "Введите время отправления(от 0.01 до 24.00): " << endl;
			cin >> amountOftrain[i].time;
			
			if ( amountOftrain[i].time > 24.00 || amountOftrain[i].time < 0.00)
			{
				cout << "Введено неправильное время!" << endl;
			}
		} while (24.00 < amountOftrain[i].time || amountOftrain[i].time < 0.00);

	}

	Train temp;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - i - 1; j++)
		{
			if (amountOftrain[j].time > amountOftrain[j + 1].time)
			{
				temp = amountOftrain[j];
				amountOftrain[j] = amountOftrain[j + 1];
				amountOftrain[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i < amount; i++)
	{
		cout << amountOftrain[i].number << " " << amountOftrain[i].name << " " << amountOftrain[i].time << endl;
	}


	cout << "Введите интересующий вас пункт направления: " << endl;
	cin >> temp.name;

	for(int i = 0; i<amount; i++)
	{
		if(!strcmp(temp.name, amountOftrain[i].name))
		{
			cout << amountOftrain[i].number << " " << amountOftrain[i].name << " " << amountOftrain[i].time << endl;
			flag = false;
		}
	}
	if (flag)
		{
		cout << "Поездов на данном направлении нет." << endl;
		}

	system("Pause");
	return 0;
}