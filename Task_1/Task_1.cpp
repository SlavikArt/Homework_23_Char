#include <iostream>
using namespace std;

bool isVowel(char l);

int main()
{
	int letters = 0;
	int signs = 0;
	int symbols = 0;
	int vowels = 0;
	int consonants = 0;
	int digits = 0;
	int others = 0;
	int words = 0;

	int cnt = 0;
	int size = 0;
	char txt[200] = {};
	cin.getline(txt, 200);

	do
	{
		size++;
	} while (txt[size] != '\0');

	for (int i = 0; i < size; i++)
	{
		if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?' || txt[i] == ';' || txt[i] == ':')
		{
			signs++;
			txt[i] = ' ';
		}
	}

	if (txt[0] == ' ')
	{
		cnt = 1;
		while (txt[cnt] == ' ')
		{
			cnt++;
		}
	}

	for (int k = cnt; k < size; k++)
	{
		if (txt[k] != ' ')
		{
			if ((txt[k] >= 'a' && txt[k] <= 'z') || (txt[k] >= 'A' && txt[k] <= 'Z'))
			{
				if (isVowel(txt[k]))
				{
					vowels++;
				}
				else
				{
					consonants++;
				}
				letters++;
			}
			else if (isdigit(txt[k]))
			{
				digits++;
			}
			else
			{
				others++;
			}
		}
		else if (txt[k] == ' ')
		{
			int tmp = k + 1;
			while (txt[tmp] == ' ' && tmp < size - 1)
			{
				tmp++;
			}
			words++;
		}
	}
	symbols = vowels + consonants + digits + others + signs;

	cout << "Symbols: " << symbols << "\n";
	cout << "-Letters: " << letters << "\n";
	cout << "--Vowels: " << vowels << "\n";
	cout << "--Consonants: " << consonants << "\n";
	cout << "-Words: " << words << "\n";
	cout << "-Digits: " << digits << "\n";
	cout << "-Signs: " << signs << "\n";
	cout << "-Others: " << others << "\n";
}

bool isVowel(char l)
{
	char vowel[] = { 'a', 'e', 'i', 'o', 'u', 'y',
					'A', 'E', 'I', 'O', 'U', 'Y' };
	for (int i = 0; i < 12; i++)
	{
		if (l == vowel[i])
		{
			return true;
		}
	}
	return false;
}