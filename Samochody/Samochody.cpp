#include <iostream>
#include <string>
#include <iterator>
using namespace std;
struct samochod {
	string marka;
	int pojemnosc;
	string rodzaj;
} s1, s2, s3, s4, s5;
int length = 4;
void Find(struct samochod* s, string marka)
{
	for (int i = 0; i < length; i++) {
		if (s[i].marka == marka) {
			cout << "\n" << i << "-te auto: " << s[i].marka << " pojemnosc: " << s[i].pojemnosc
				<< " rodzaj: " << s[i].rodzaj << endl;
		}
	}
}
void Dispaly(samochod* s)
{
	for (int i = 0; i < length; i++)
		cout << "\n" << i << "-te auto: " << s[i].marka << " pojemnosc: " << s[i].pojemnosc
			<< " rodzaj: " << s[i].rodzaj << endl;
	
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
samochod* Add(samochod* s, samochod a)
{
	samochod* r = new samochod[length++];
	for (int i = 0; i < length - 1; i++)
		r[i] = s[i];
	r[length] = a;
	return r;
}
int main(int argc, char** argv)
{
	s1.marka = "Fiat";
	s1.pojemnosc = 1300;
	s1.rodzaj = "sedan";

	s2.marka = "Seat";
	s2.pojemnosc = 1900;
	s2.rodzaj = "kombi";

	s3.marka = "Nissan";
	s3.pojemnosc = 2100;
	s3.rodzaj = "crossover";

	s4.marka = "Fiat";
	s4.pojemnosc = 1800;
	s4.rodzaj = "hatchback";

	//samochod samochody[] = { s1,s2,s3,s4 };
	samochod samochody[4] = { s1,s2,s3,s4 };
	Find(samochody, "Fiat");
	s5 = Get();
	samochod* s = Add(samochody, s4);

	Dispaly(s);

	return 0;
}