#include <iostream>
#include <string>
#include <iterator>
using namespace std;
struct samochod {
	string marka;
	int pojemnosc;
	string rodzaj;
} s1, s2, s3, s4, s5;
samochod samochody[100];
int length = 0;
void Find(string marka)
{
	for (int i = 0; i < length; i++) {
		if (samochody[i].marka == marka) {
			cout << i << "-te auto: " << samochody[i].marka << " pojemnosc: " << samochody[i].pojemnosc
				<< " rodzaj: " << samochody[i].rodzaj << endl;
		}
	}
}
void Dispaly()
{
	for (int i = 0; i < length; i++)
		cout << i << "-te auto: " << samochody[i].marka << " pojemnosc: " << samochody[i].pojemnosc
		<< " rodzaj: " << samochody[i].rodzaj << endl;
}
samochod Get()
{
	struct samochod result;
	cout << "Podaj marke: ";
	cin >> result.marka;
	cout << "Podaj pojemnosc: ";
	cin >> result.pojemnosc;
	cout << "Podaj rodzaj: ";
	cin >> result.rodzaj;
	return result;
}
void Add(samochod a)
{
	samochody[length++] = a;
}
void Remove(int index)
{
	index--;
	for (int i = 0; i < length; i++)
	{
		if (i > index) samochody[i] = samochody[i + 1];
	}
	length--;
}
int menu()
{
	cout << "1.Wyswietl" << endl;
	cout << "2.Dodaj" << endl;
	cout << "3.Usun" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Koniec" << endl;
	int a;
	cin >> a;
	return a;
}
int main(int argc, char** argv)
{
	s1.marka = "Fiat";
	s1.pojemnosc = 1300;
	s1.rodzaj = "sedan";
	Add(s1);
	s2.marka = "Seat";
	s2.pojemnosc = 1900;
	s2.rodzaj = "kombi";
	Add(s2);
	s3.marka = "Nissan";
	s3.pojemnosc = 2100;
	s3.rodzaj = "crossover";
	Add(s3);
	s4.marka = "Fiat";
	s4.pojemnosc = 1800;
	s4.rodzaj = "hatchback";
	Add(s4);
	bool end = true;
	string s;
	while (end)
	{
		switch (menu())
		{
		case 1:
			Dispaly();
			break;
		case 2:
			Add(Get());
			break;
		case 3:
			int index;
			cout << "podaj index: ";
			cin >> index;
			Remove(index);
			break;
		case 4:
			cin >> s;
			cout << "podaj markę: ";
			Find(s);
			break;
		case 5:
			end = false;
			cout << "koniec";
			break;
		default:
			cout << "niepoprawny numer";
			break;
		}
	}
	return 0;
}
