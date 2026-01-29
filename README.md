Simulator de Zaruri in C++

Aplicatie de tip consola care simuleaza aruncari de zaruri cu un numar variabil de fete. Programul include jocuri clasice cu zaruri, calcule de probabilitati si statistici matematice pentru analiza rezultatelor.



Autor

Nume: Vulturean Dorina
Grupa: 3.2
Email: dorina.vulturean@student.upt.ro
An academic: 2025-2026



Descriere

Simulatorul de zaruri permite utilizatorului sa ruleze diferite simulari ale aruncarilor de zaruri si sa analizeze rezultatele obtinute. Aplicatia este utila pentru intelegerea notiunilor de probabilitate, distributii statistice si pentru simularea unor jocuri populare precum Craps sau Yahtzee. Programul ofera si posibilitatea salvarii rezultatelor in fisier si compararea probabilitatilor teoretice cu cele experimentale.



Tehnologii folosite

Limbaj: C++
Biblioteci standard:

  <iostream> – input/output
  <cstdlib>, <ctime> – generare numere aleatoare
  <map>, <vector> – structuri de date
  <algorithm> – sortare
  <cmath> – calcule matematice
  <fstream> – lucrul cu fisiere
Tools: Visual Studio



Cerinte sistem

Compilator: Microsoft Visual C++ (MSVC)
Sistem de operare: Windows
Dependente externe: Nu exista (doar biblioteci standard C++)



Instalare

1. Deschide proiectul in Visual Studio
2. Asigura-te ca fisierul `main.cpp` este inclus in proiect
3. Selecteaza configuratia Debug sau Release
4. Compileaza si ruleaza aplicatia folosind `Ctrl + F5`

Rulare cu Docker

bash
docker run ghcr.io/dorinavulturean/simulare-zaruri:latest

Rulare

Programul ruleaza in consola si afiseaza un meniu interactiv:

  text
1. Simulare aruncari de zaruri
2. Calcularea probabilitatilor
3. Joc simplu
4. Joc: Craps
5. Joc: Yahtzee
6. Statistici detaliate
7. Salvare log-uri
8. Histograma ASCII
9. Comparatie probabilitati
10. Setare seed
0. Iesire



Exemple de utilizare

Exemplul 1: Simulare zar cu 6 fete

Input:


Optiune: 1
Fete: 6
Aruncari: 10


Output asteptat:

Rezultatele aruncarilor:
2 5 1 6 3 4 2 6 1 5



Exemplul 2: Probabilitate pentru suma cautata

Input:


Optiune: 2
Suma cautata: 7
Simulari: 10000


Output asteptat:


Probabilitatea experimentala pentru suma 7 este: 16.6%



Exemplul 3: Joc Craps

Input:


Optiune: 4


Output posibil:


Suma obtinuta: 11
Castig!



Exemplul 4: Statistici

Input:


Optiune: 6
Fete: 6
Aruncari: 1000


Output asteptat:


Media: 3.5
Mediana: 4
Deviatia standard: 1.7



Exemplul 5: Salvare in fisier

Input:


Optiune: 7
Fete: 6
Aruncari: 20


Output asteptat:


Simularea a fost salvata in fisierul simulare_zaruri.log



Functionalitati implementate

1. Simulare zaruri cu fete configurabile
2. Calcul probabilitati experimentale
3. Jocuri cu zaruri (Craps, Yahtzee)
4. Statistici: frecventa, medie, mediana, deviatie standard
5. Histograma ASCII
6. Salvare rezultate in fisier


Structura proiectului


project/
 └── main.cpp   - implementarea completa a aplicatiei



Decizii de design

* Am utilizat `map<int,int>` pentru frecvente deoarece ofera acces rapid si ordonat.
* Vectorii au fost folositi pentru calculul medianei si deviatiei standard.
* Meniul interactiv permite extinderea usoara a aplicatiei cu noi functionalitati.



Probleme intalnite si solutii

Problema: rezultate diferite la fiecare rulare
Solutie: adaugarea optiunii de setare a seed-ului pentru reproductibilitate

Problema: calculul medianei
Solutie: sortarea vectorului de rezultate inainte de calcul


Testare

Testarea s-a realizat manual, prin rularea fiecarei optiuni din meniu cu valori diferite pentru zaruri si numarul de aruncari, verificand corectitudinea rezultatelor afisate.



Resurse folosite

Documentatia C++: https://www.cplusplus.com/, https://www.youtube.com/@PortfolioCourses
Materiale de curs de la materia Probabilitati si Statistici



Contact

Pentru intrebari: dorina.vulturean@student.upt.ro
