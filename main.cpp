#include <iostream> // pentru cout, cin
#include <cstdlib> // pentru rand(), srand()
#include <ctime> // pentru time()
#include <map> // pentru map (frecvente)
#include <vector> // pentru vector (statistici)
#include <algorithm> // pentru sort()
#include <cmath> // pentru sqrt(), abs()
#include <fstream> // pentru fisiere

using namespace std;

// Functie care simuleaza o aruncare de zar
// Returneaza un numar intre 1 si numarul de fete
int rollDie(int faces)
{
	return (rand() % faces) + 1;
}

int main()
{
	cout << "Simulator de zaruri\n";
	cout << "Student Vulturean Dorina\n"; 

	//Initializarea generatorului de numere aleatoare
	srand(time(NULL));

	// Meniul ruleaza in bucla pana cand utilizatorul alege iesire
	do
	{
		// Afisarea meniului
		cout << "Meniu:\n";
		cout << "1. Simulare aruncari de zaruri cu numar configurabil de fete (6, 8, 10, 12, 20)\n";
		cout << "2. Calcularea probabilitatilor pentru sume specifice\n";
		cout << "3. Joc simplu: suma aruncarilor\n";
		cout << "4. Joc: Craps (versiune simplificata)\n";
		cout << "5. Joc: Yahtzee Dice (simplificat)\n";
		cout << "6. Statistici detaliate (frecventa, medie, mediana, deviatie standard)\n";
		cout << "7. Salvare log-uri simulare in fisier\n";
		cout << "8. Histograma ASCII pentru distributia aruncarilor\n";
		cout << "9. Comparatie intre probabilitati teoretice si experimentale\n";
		cout << "10. Setare seed pentru reproducerea rezultatelor\n";
		cout << "0. Iesire\n";
		
		int opt;
		cout << "Alegeti o optiune: ";
		cin >> opt;

		switch (opt)
		{
			// 1. SIMULARE ARUNCARI
		case 1:
		{

			int faces;
			int rolls;

			// Citirea numarului de fete si a numarului de aruncari
			cout << "Introdu numarul de fete ale zarului (6, 8, 10, 12, 20): ";
			cin >> faces;

			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			// Map pentru a tine evidenta frecventei fiecarui rezultat

			map<int, int> frequency;

			cout << "\nRezultatele aruncarilor:\n";

			// Simularea aruncarilor

			for (int i = 0; i < rolls; i++)
			{
				int result = rollDie(faces);
				cout << result << " ";
				frequency[result]++;
			}

			// Afisarea frecventelor
			cout << "\nFrecventa fiecarei fete:\n";
			for (auto p : frequency)
			{
				cout << "Fata " << p.first << " apare de " << p.second << "  ori\n";
			}
		}
		break;

		// 2. PROBABILITATE SUMA (EXPERIMENTAL)
		case 2:
		{
			int rolls;
			int targetSum;
			int success = 0;

			// Citirea sumei cautate si a numarului de simulari
			cout << "Introdu suma cautata: ";
			cin >> targetSum;

			cout << "Introdu numarul de simulari: ";
			cin >> rolls;

			// Simularea aruncarilor a doua zaruri
			for (int i = 0; i < rolls; i++)
			{
				int die1 = rollDie(6);
				int die2 = rollDie(6);

				int sum = die1 + die2;

				// Verificarea daca suma este cea cautata
				if(sum== targetSum)
				{
					success++;
				}
			}

			//Calcularea probabilitatii experimentale
			double probability = (double)success / rolls;

			//Afisarea rezultatului
			cout << "Probabilitatea experimentala pentru suma " << targetSum << " este: " << probability * 100<< "%\n";
		}
		break;

		// 3. JOC: SUMA ARUNCARILOR
		case 3:
		{
			// Joc: suma aruncarilor
			int d1 = rollDie(6);
			int d2 = rollDie(6);

			cout << "Zar 1: " << d1 << endl;
			cout << "Zar 2: " << d2 << endl;
			cout << "Suma: " << d1 + d2 << endl;
			break;
		}

		// 4. JOC: CRAPS (SIMPLIFICAT)
		case 4:
		{
			// Reguli simplificate:
			// 7 sau 11 -> castig
			// 2, 3, 12 -> pierdere
			// altfel -> mai incearca
			int d1 = rollDie(6);
			int d2 = rollDie(6);
			int sum = d1 + d2;

			cout << "Suma obtinuta: " << sum << endl;

			if (sum == 7 || sum == 11)
				cout << "Castig!\n";
			else if (sum == 2 || sum == 3 || sum == 12)
				cout << "Pierdere!\n";
			else
				cout << "Mai incearca!\n";

			break;
		}

		// 5. JOC: YAHTZEE (SIMPLIFICAT)
		case 5:
		{
			// Joc: Yahtzee Dice (simplificat)
			// Se arunca 5 zaruri, daca toate sunt egale -> YAHTZEE
			int dice[5];
			bool yahtzee = true;

			// Aruncarea celor 5 zaruri
			for (int i = 0; i < 5; i++)
			{
				dice[i] = rollDie(6);
				cout << dice[i] << " ";
			}

			// Verificare daca toate valorile sunt egale
			for (int i = 1; i < 5; i++)
			{
				if (dice[i] != dice[0])
				{
					yahtzee = false;
					break;
				}
			}

			if (yahtzee)
				cout << "\nYAHTZEE!\n";
			else
				cout << "\nNu este Yahtzee.\n";

		break;
		}

		// 6. STATISTICI: FRECVENTA, MEDIE, MEDIANA, STDDEV
		case 6:
		{
			int faces, rolls;
			cout << "Introdu numarul de fete ale zarului: ";
			cin >> faces;
			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			vector<int> results; // pastram toate rezultatele pentru mediana
			map<int, int> frequency; // frecvente
			double sum = 0;  // suma pentru medie

			// Colectarea rezultatelor
			for (int i = 0; i < rolls; i++)
			{
				int r = rollDie(faces);
				results.push_back(r);
				frequency[r]++;
				sum += r;
			}

			// Media
			double mean = sum / rolls;

			// Mediana (sortam rezultatele)
			sort(results.begin(), results.end());

			double median;
			if (rolls % 2 == 0)
				median = (results[rolls / 2 - 1] + results[rolls / 2]) / 2.0;
			else
				median = results[rolls / 2];

			// Deviatia standard: sqrt(varianta)
			double variance = 0;
			for (int r : results)
				variance += (r - mean) * (r - mean);
			variance /= rolls;

			double stddev = sqrt(variance);

			// Afisarea frecventelor
			cout << "\nFrecvente:\n";
			for (auto p : frequency)
				cout << "Fata " << p.first << ": " << p.second << endl;

			// Afisarea statisticilor
			cout << "\nMedia: " << mean << endl;
			cout << "Mediana: " << median << endl;
			cout << "Deviația standard: " << stddev << endl;

			break;
		}

		// 7. SALVARE LOG IN FISIER
		case 7:
		{
			int faces, rolls;
			cout << "Introdu numarul de fete ale zarului: ";
			cin >> faces;
			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			// Deschidem fisierul de log (suprascrie continutul la fiecare rulare)
			ofstream file("simulare_zaruri.log");

			// Verificare daca s-a deschis corect
			if (!file)
			{
				cout << "Eroare la deschiderea fisierului!\n";
				break;
			}

			// Scriem informatii in fisier
			file << "Simulare zaruri\n";
			file << "Numar fete: " << faces << endl;
			file << "Numar aruncari: " << rolls << endl;
			file << "Rezultate:\n";

			for (int i = 0; i < rolls; i++)
			{
				int r = rollDie(faces);
				file << r << " ";
			}

			file << endl;
			file.close();

			cout << "Simularea a fost salvata in fisierul simulare_zaruri.log\n";

			break;
		}

		// 8. HISTOGRAMA ASCII 
		case 8:
		{
			int faces, rolls;
			cout << "Introdu numarul de fete ale zarului: ";
			cin >> faces;
			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			map<int, int> frequency;

			// Colectam frecventele
			for (int i = 0; i < rolls; i++)
			{
				int r = rollDie(faces);
				frequency[r]++;
			}

			// Afisam histograma
			cout << "\nHistograma ASCII:\n";

			for (auto p : frequency)
			{
				cout << p.first << " | ";
				for (int i = 0; i < p.second; i++)
					cout << "*";
				cout << " (" << p.second << ")\n";
			}

			break;
		}

		// 9. COMPARATIE PROBABILITATI (TEORETIC vs EXPERIMENTAL)
		case 9:
		{
			int targetSum, rolls, success = 0;

			cout << "Introdu suma cautata (2-12): ";
			cin >> targetSum;
			cout << "Introdu numarul de simulari: ";
			cin >> rolls;

			// Probabilitate experimentala (simulam)
			for (int i = 0; i < rolls; i++)
			{
				int d1 = rollDie(6);
				int d2 = rollDie(6);
				if (d1 + d2 == targetSum)
					success++;
			}

			double experimental = (double)success / rolls;

			// Probabilitate teoretica:
		   // numar cazuri favorabile / 36
			int favorable;
			if (targetSum <= 7)
				favorable = targetSum - 1;
			else
				favorable = 13 - targetSum;

			double theoretical = (double)favorable / 36;

			// Afisare rezultate
			cout << "\nProbabilitate teoretica: " << theoretical * 100 << "%\n";
			cout << "Probabilitate experimentala: " << experimental * 100 << "%\n";
			cout << "Diferenta: "
				<< abs(theoretical - experimental) * 100 << "%\n";

			break;
		}

		// 10. SETARE SEED PENTRU REPRODUCERE
		case 10:
		{
			unsigned int seed;
			int faces, rolls;

			// Citim seed-ul si il setam pentru rand()
			cout << "Introdu seed-ul (numar intreg): ";
			cin >> seed;

			srand(seed);

			// Apoi simulam o serie de aruncari (repetabile cu acelasi seed)
			cout << "Introdu numarul de fete ale zarului: ";
			cin >> faces;
			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			cout << "Rezultate:\n";
			for (int i = 0; i < rolls; i++)
				cout << rollDie(faces) << " ";

			cout << endl;
			break;
		}

		// IESIRE
		case 0:
			cout << "La revedere!\n";
			exit(0);

			// OPTIUNE INVALIDA
		default:
			cout << "Optiune invalida!\n";
			break;
		}
	} while (true);
	return 0;
}