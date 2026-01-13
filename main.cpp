#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
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
		case 0:exit(0);

		default:
			break;
		}
	} while (true);
	return 0;
}