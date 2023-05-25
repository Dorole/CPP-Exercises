#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct KolicineKovanica
{
	unsigned kolicina_2e;
	unsigned kolicina_1e;
	unsigned kolicina_50c;
	unsigned kolicina_20c;
	unsigned kolicina_10c;
};

KolicineKovanica inicijalizirajKolicineKovanica(int kolicina)
{
	KolicineKovanica inicKolicine;
	inicKolicine.kolicina_2e = inicKolicine.kolicina_1e = inicKolicine.kolicina_50c = inicKolicine.kolicina_20c = inicKolicine.kolicina_10c = kolicina;

	return inicKolicine;
}

KolicineKovanica pretvoriIznosUKolicine(float iznos)
{
	KolicineKovanica kolicineZaPovrat{};

	int iznosUCentima = iznos * 100;

	const int centi_2e = 200, centi_1e = 100, centi_50c = 50, centi_20c = 20, centi_10c = 10;

	while (iznosUCentima > 0)
	{
		if (iznosUCentima >= 200)
		{
			kolicineZaPovrat.kolicina_2e = iznosUCentima / centi_2e;
			iznosUCentima %= centi_2e;
		}

		if (iznosUCentima >= 100)
		{
			kolicineZaPovrat.kolicina_1e = iznosUCentima / centi_1e;
			iznosUCentima %= centi_1e;
		}

		if (iznosUCentima >= 50)
		{
			kolicineZaPovrat.kolicina_50c = iznosUCentima / centi_50c;
			iznosUCentima %= centi_50c;
		}

		if (iznosUCentima >= 20)
		{
			kolicineZaPovrat.kolicina_20c = iznosUCentima / centi_20c;
			iznosUCentima %= centi_20c;
		}

		if (iznosUCentima >= 10)
		{
			kolicineZaPovrat.kolicina_10c = iznosUCentima / centi_10c;
			iznosUCentima %= centi_10c;
		}
	}

	return kolicineZaPovrat;
}

KolicineKovanica obracunajPovrat(float primljeniIznos, float cijena, float stanjeAparata)
{
	KolicineKovanica kolicineZaPovrat{};
	float iznosZaPovrat{};

	if (stanjeAparata < (primljeniIznos - cijena))
	{
		cout << "\nNedovoljno novca za povrat! Vracam primljeni iznos." << endl;
		iznosZaPovrat = primljeniIznos;
	}
	else
		iznosZaPovrat = primljeniIznos - cijena;

	//cout << "\n********** Povrat: **********" << endl;
	cout << "Za povrat: EUR " << iznosZaPovrat << endl;

	return pretvoriIznosUKolicine(iznosZaPovrat);
}

void ispisiKolicineKovanica(KolicineKovanica kovanice)
{
	if (kovanice.kolicina_2e)
		cout << "2 EUR: " << kovanice.kolicina_2e << endl;
	if (kovanice.kolicina_1e)
		cout << "1 EUR: " << kovanice.kolicina_1e << endl;
	if (kovanice.kolicina_50c)
		cout << "0.50 EUR: " << kovanice.kolicina_50c << endl;
	if (kovanice.kolicina_20c)
		cout << "0.20 EUR: " << kovanice.kolicina_20c << endl;
	if(kovanice.kolicina_10c)
		cout << "0.10 EUR: " << kovanice.kolicina_10c << endl;
}

KolicineKovanica azurirajKolicineKovanica(KolicineKovanica& trenutneKolicine, KolicineKovanica& pomakKolicina, int predznak)
{
	//predznak: 1 ili -1 ovisno o tome treba li kolicine dodati ili oduzeti

	trenutneKolicine.kolicina_2e += pomakKolicina.kolicina_2e * predznak;
	trenutneKolicine.kolicina_1e += pomakKolicina.kolicina_1e * predznak;
	trenutneKolicine.kolicina_50c += pomakKolicina.kolicina_50c * predznak;
	trenutneKolicine.kolicina_20c += pomakKolicina.kolicina_20c * predznak;
	trenutneKolicine.kolicina_10c += pomakKolicina.kolicina_10c * predznak;

	return trenutneKolicine;
	
}


int generirajRandomInt(int min, int max)
{
	random_device randDev;
	mt19937 generator(randDev());

	uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}


enum Proizvod
{
	CIPS, COKOLADA, BOMBONI, SOK, VODA
};

string pretvoriEnumUString(Proizvod proizvod)
{
	switch (proizvod)
	{
		case CIPS:
			return "CIPS";
			break;
		case COKOLADA:
			return "COKOLADA";
			break;
		case BOMBONI:
			return "BOMBONI";
			break;
		case SOK:
			return "SOK";
			break;
		case VODA:
			return "VODA";
			break;
		default:
			return "GRESKA";
			break;
	}
}

struct RedProizvoda
{
	Proizvod tipProizvoda;
	string imeProizvoda;
	float cijena{};
	int kolicinaProizvoda{};
	int pristupniBroj{};
};

RedProizvoda generirajProizvod()
{
	RedProizvoda redProizvoda;

	redProizvoda.tipProizvoda = static_cast<Proizvod>(generirajRandomInt(0, 4));
	redProizvoda.imeProizvoda = pretvoriEnumUString(redProizvoda.tipProizvoda);

	int generiranaCijena{};
	do
	{
		generiranaCijena = generirajRandomInt(1, 500);

	} while (generiranaCijena % 10 != 0);

	redProizvoda.cijena = generiranaCijena / static_cast<float>(100);
	redProizvoda.kolicinaProizvoda = generirajRandomInt(1, 10);
	//u vektoru pristupni broj treba biti kombinacija reda i stupca

	return redProizvoda;
}

struct Aparat
{
	KolicineKovanica kolicineKovanica{};
	RedProizvoda katalog[7];
	int duljinaKataloga = sizeof(katalog) / sizeof(RedProizvoda);

	void punjenjeAparata()
	{
		kolicineKovanica = inicijalizirajKolicineKovanica(50);

		for (int i = 0; i < duljinaKataloga; i++)
		{
			katalog[i] = generirajProizvod();
			katalog[i].pristupniBroj = i;
		}
	}

	void ispisiStanjeProizvoda()
	{
		for (int i = 0; i < duljinaKataloga; i++)
		{
			RedProizvoda red = katalog[i];

			cout
				<< red.pristupniBroj << ": "
				<< red.imeProizvoda << " -- "
				<< "Cijena: EUR " << red.cijena << " -- "
				<< "Preostalo proizvoda: " << red.kolicinaProizvoda << endl;
		}
	}

	void ispisiStanjeKovanica()
	{
		cout << "\nTrenutno stanje aparata (kovanice):" << endl;
		ispisiKolicineKovanica(kolicineKovanica);
	}

	float iznosNovcaUAparatu()
	{
		const float vrijednost_2e = 2.0;
		const float vrijednost_50c = 0.5;
		const float vrijednost_20c = 0.2;
		const float vrijednost_10c = 0.1;

		float zbroj_2e = kolicineKovanica.kolicina_2e * vrijednost_2e;
		float zbroj_1e = kolicineKovanica.kolicina_1e;
		float zbroj_50c = kolicineKovanica.kolicina_50c * vrijednost_50c;
		float zbroj_20c = kolicineKovanica.kolicina_20c * vrijednost_20c;
		float zbroj_10c = kolicineKovanica.kolicina_10c * vrijednost_10c;

		float ukupanZbroj = zbroj_2e + zbroj_1e + zbroj_50c + zbroj_20c + zbroj_10c;
		return ukupanZbroj;
	}

	void azurirajKolicinuProizvoda(int index)
	{
		katalog[index].kolicinaProizvoda--;
	}

	void azurirajAparat(int index, KolicineKovanica odlazneKovanice)
	{
		azurirajKolicinuProizvoda(index);
		kolicineKovanica = azurirajKolicineKovanica(kolicineKovanica, odlazneKovanice, -1);

		ispisiStanjeProizvoda();
		ispisiStanjeKovanica();

		cout << "\nTrenutno stanje aparata (iznos): EUR " << iznosNovcaUAparatu() << endl;;
	}
};

int odaberiProizvod(Aparat aparat)
{
	int odabir{};
	cout << "\nOdaberi proizvod upisom broja reda: ";

	RedProizvoda trenutniOdabir;

	do
	{
		cin >> odabir;
		trenutniOdabir = aparat.katalog[odabir];

		if (trenutniOdabir.kolicinaProizvoda == 0)
			cout << "Odabrani proizvod nije dostupan. Odaberi novi: ";

	} while (trenutniOdabir.kolicinaProizvoda == 0);

	return odabir;
}

float izvrsiPlacanje(RedProizvoda trenutniOdabir)
{
	float trenutnaUplata{};
	float uplata{};

	cout << "\nUplati: EUR ";

	do
	{
		cin >> trenutnaUplata;
		uplata += trenutnaUplata;

		if (trenutniOdabir.cijena > uplata)
			cout << "Uplata je manja od cijene. Uplati jos: EUR ";

	} while (trenutniOdabir.cijena > uplata);

	return uplata;
}


int main()
{
	Aparat aparat;
	
	// *************** INICIJALIZACIJA APARATA ***************
	aparat.punjenjeAparata();
	aparat.ispisiStanjeProizvoda();

	while (true)
	{
		// *************** ODABIR PROIZVODA ***************
		cout << "\n********************" << endl;

		int odabir = odaberiProizvod(aparat);
		RedProizvoda trenutniOdabir = aparat.katalog[odabir];


		// *************** PLACANJE ***************
		float uplata = izvrsiPlacanje(trenutniOdabir);


		// *************** OBRACUNI ***************
		cout << "\n********************" << endl;

		KolicineKovanica primljeneKovanice = pretvoriIznosUKolicine(uplata);
		aparat.kolicineKovanica = azurirajKolicineKovanica(aparat.kolicineKovanica, primljeneKovanice, 1);

		KolicineKovanica vraceneKovanice = obracunajPovrat(uplata, trenutniOdabir.cijena, aparat.iznosNovcaUAparatu());
		ispisiKolicineKovanica(vraceneKovanice);


		// *************** AZURIRANJE STANJA APARATA ***************
		cout << "\n****************************************" << endl
			<< endl;

		aparat.azurirajAparat(odabir, vraceneKovanice);
	}

}

