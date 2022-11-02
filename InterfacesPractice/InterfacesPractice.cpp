#include <fstream>
#include <iostream>
#include <conio.h>
void Update();
void Encryption(std::string name, int k);
void Decryption(std::string name, int k);
char ChangeEnc(char ch, int k);
char ChangeDec(char ch, int k);


int main()
{

	setlocale(LC_ALL, "rus");

	Update();

    
}


void Update()
{
	std::string nameOfFile;
	int k;
	while (true)
	{
		std::cout << "1.Зашифровать" << std::endl;
		std::cout << "2.Расшифровать" << std::endl;
		std::cout << "3.Выйти" << std::endl;
		int ch = _getch();
		switch (ch)
		{
		case('1'):

			std::cout << "Введите имя файла: \n";
			std::cin >> nameOfFile;
			std::cout << "Введите сдвиг: \n";
			std::cin >> k;
			Encryption(nameOfFile, k);

			break;
		case('2'):

			std::cout << "Введите имя файла: \n";
			std::cin >> nameOfFile;
			std::cout << "Введите сдвиг: \n";
			std::cin >> k;
			Decryption(nameOfFile, k);
			break;

		case('3'):
			exit(0);
			break;

		default:
			break;
		}
	}
}

void Encryption(std::string name, int k)
{
	char ch;
	std::ofstream output("Enc_result.txt");
	std::ifstream input(name);
	if (input.is_open())
	{
		for (; input;)
		{
			ch = input.get();
			if (input.eof()) break;
			output << ChangeEnc(ch, k);
		}
	}
}

void Decryption(std::string name, int k)
{
	char ch;
	std::ofstream output("Dec_result.txt");
	std::ifstream input(name);
	if (input.is_open())
	{
		for (; input;)
		{
			ch = input.get();
			if (input.eof()) break;
			output << ChangeDec(ch, k);
		}
	}
}


char ChangeEnc(char ch, int k)
{
	if (isupper(ch))
	{
		ch = tolower(ch);
	}
	char ABC[] = { 'a','b','c','d','e','f','g','h','i',
				'j','k','l','m','n','o','p','q','r',
				's','t','u','v','w','x','y','z',
				'_','.',',','0','\'',
				'1','2','3','4','5','6','7','8','9' };
	if (ch == ' ')  return ch;
	char result = ' ';
	for (int i = 0; i < 40; i++)
	{
		if (ch == ABC[i])
		{
			if (i > 34) result = ABC[39 - i + k];
			else result = ABC[i + k];
			if (i > 40) break;
		}
	}

	return result;
}





	char ChangeDec(char ch, int k)
	{
		std::cout << "before changing " << ch << " ";
		if (isupper(ch))
		{
			ch = tolower(ch);
			
		}
		char ABC[] = { 'a','b','c','d','e','f','g','h','i',
					'j','k','l','m','n','o','p','q','r',
					's','t','u','v','w','x','y','z',
					'_','.',',','0','\'',
					'1','2','3','4','5','6','7','8','9' };
		if (ch == ' ')  return ch;
		char result = ' ';
		for (int i = 0; i < 40; i++)
		{
			if (ch == ABC[i])
			{
				if (i < 5) result = ABC[39 + i - k];
				else result = ABC[i - k];
				if (i > 40) break;
			}
		}
		std::cout << "after changing " << result << std::endl;
		return result;
	}
