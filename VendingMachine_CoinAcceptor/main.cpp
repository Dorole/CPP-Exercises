#include <iostream>

using namespace std;

struct KolicineKovanica
{
	unsigned kolicina_2e;
	unsigned kolicina_1e;
	unsigned kolicina_50c;
	unsigned kolicina_20c;
	unsigned kolicina_10c;
};

KolicineKovanica pretvoriIznosUKolicine(float iznos)
{
	KolicineKovanica kolicineZaPovrat {};

	int iznosUCentima = iznos * 100;

	const int centi_2e = 200, centi_1e = 100, centi_50c = 50, centi_20c = 20, centi_10c = 10;

	int kolicina_2e = iznosUCentima / centi_2e;
	iznosUCentima %= centi_2e;

	int kolicina_1e = iznosUCentima / centi_1e;
	iznosUCentima %= centi_1e;

	int kolicina_50c = iznosUCentima / centi_50c;
	iznosUCentima %= centi_50c;

	int kolicina_20c = iznosUCentima / centi_20c;
	iznosUCentima %= centi_20c;

	int kolicina_10c = iznosUCentima/ centi_10c;
	iznosUCentima %= centi_10c;

	cout << "2 EUR: " << kolicina_2e << endl;
	cout << "1 EUR: " << kolicina_1e << endl;
	cout << "0.50 EUR: " << kolicina_50c << endl;
	cout << "0.20 EUR: " << kolicina_20c << endl;
	cout << "0.10 EUR: " << kolicina_10c << endl;

	return kolicineZaPovrat;
}

KolicineKovanica izracunajKolicineZaPovrat(float primljeniIznos, float cijena)
{
	KolicineKovanica kolicineZaPovrat{};
	float iznosZaPovrat{};

	if (cijena > primljeniIznos)
	{
		cout << "\nNedovoljno novca! Vracam primljeni iznos." << endl;

		iznosZaPovrat = primljeniIznos;
	}
	else
		iznosZaPovrat = primljeniIznos - cijena;
	
	cout << "\n********** Povrat: **********" << endl;

	return pretvoriIznosUKolicine(iznosZaPovrat);
}

void testirajKolicineZaPovrat()
{
	float primljeniIznos{};
	float cijena{};

	cout << "Kontrole radi, upisi dva cijela ili decimalna broja veca od 0." << endl;
	cout << "Cijena: ";
	cin >> cijena;

	while (cijena <= 0)
	{
		cout << "Cijena treba biti veca od 0. Upisi novu cijenu: ";
		cin >> cijena;
	}

	cout << "Primljeni iznos: ";
	cin >> primljeniIznos;

	while (primljeniIznos <= 0)
	{
		cout << "Primljeni iznos treba biti veci od 0. Upisi novi iznos: ";
		cin >> primljeniIznos;
	}

	cout << "Cijena proizvoda je EUR " << cijena << ". Vi ste dali EUR " << primljeniIznos << "." << endl;
	cout << "Za povrat: EUR " << (primljeniIznos - cijena) << endl;

	izracunajKolicineZaPovrat(primljeniIznos, cijena);

}

int main()
{
	testirajKolicineZaPovrat();
}