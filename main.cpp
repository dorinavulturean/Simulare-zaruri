#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

// Functie care simuleaza o aruncare de zar
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

	do
	{

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
		cout << "0. Iesire\n";
		
		int opt;
		cout << "Alegeti o optiune: ";
		cin >> opt;

		switch (opt)
		{
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

			cout << "\nFrecventa fiecarei fete:\n";
			for (auto p : frequency)
			{
				cout << "Fata " << p.first << " apare de " << p.second << "  ori\n";
			}
		}
		break;

		case 2:
		{
			int rolls;
			int targetSum;
			int success = 0;

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

		case 4:
		{
			// Joc: Craps (simplificat)
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

		case 5:
		{
			// Joc: Yahtzee Dice (simplificat)
			int dice[5];
			bool yahtzee = true;

			for (int i = 0; i < 5; i++)
			{
				dice[i] = rollDie(6);
				cout << dice[i] << " ";
			}

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
		case 6:
		{
			int faces, rolls;
			cout << "Introdu numarul de fete ale zarului: ";
			cin >> faces;
			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			vector<int> results;
			map<int, int> frequency;
			double sum = 0;

			for (int i = 0; i < rolls; i++)
			{
				int r = rollDie(faces);
				results.push_back(r);
				frequency[r]++;
				sum += r;
			}

			double mean = sum / rolls;

			sort(results.begin(), results.end());

			double median;
			if (rolls % 2 == 0)
				median = (results[rolls / 2 - 1] + results[rolls / 2]) / 2.0;
			else
				median = results[rolls / 2];

			double variance = 0;
			for (int r : results)
				variance += (r - mean) * (r - mean);
			variance /= rolls;

			double stddev = sqrt(variance);

			cout << "\nFrecvente:\n";
			for (auto p : frequency)
				cout << "Fata " << p.first << ": " << p.second << endl;

			cout << "\nMedia: " << mean << endl;
			cout << "Mediana: " << median << endl;
			cout << "Deviația standard: " << stddev << endl;

			break;
		}
		case 7:
		{
			int faces, rolls;
			cout << "Introdu numarul de fete ale zarului: ";
			cin >> faces;
			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			ofstream file("simulare_zaruri.log");

			if (!file)
			{
				cout << "Eroare la deschiderea fisierului!\n";
				break;
			}

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
		case 8:
		{
			int faces, rolls;
			cout << "Introdu numarul de fete ale zarului: ";
			cin >> faces;
			cout << "Introdu numarul de aruncari: ";
			cin >> rolls;

			map<int, int> frequency;

			for (int i = 0; i < rolls; i++)
			{
				int r = rollDie(faces);
				frequency[r]++;
			}

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
		case 9:
		{
			int targetSum, rolls, success = 0;

			cout << "Introdu suma cautata (2-12): ";
			cin >> targetSum;
			cout << "Introdu numarul de simulari: ";
			cin >> rolls;

			for (int i = 0; i < rolls; i++)
			{
				int d1 = rollDie(6);
				int d2 = rollDie(6);
				if (d1 + d2 == targetSum)
					success++;
			}

			double experimental = (double)success / rolls;

			int favorable;
			if (targetSum <= 7)
				favorable = targetSum - 1;
			else
				favorable = 13 - targetSum;

			double theoretical = (double)favorable / 36;

			cout << "\nProbabilitate teoretica: " << theoretical * 100 << "%\n";
			cout << "Probabilitate experimentala: " << experimental * 100 << "%\n";
			cout << "Diferenta: "
				<< abs(theoretical - experimental) * 100 << "%\n";

			break;
		}

		case 0:exit(0);

		default:
			break;
		}
	} while (true);
	return 0;
}