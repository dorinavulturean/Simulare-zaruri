#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;

int rollDie(int faces)
{
	return (rand() % faces) + 1;
}

int main()
{
	cout << "Simulator de zaruri\n";
	cout << "Student Vulturean Dorina\n"; 

	int faces;
	int rolls;

	// Citirea numarului de fete si a numarului de aruncari
	cout << "Introdu numarul de fete ale zarului (6, 8, 10, 12, 20): ";
	cin >> faces;

	cout << "Introdu numarul de aruncari: ";
	cin >> rolls;

	//Initializarea generatorului de numere aleatoare
	srand(time(NULL));

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

	return 0;
}