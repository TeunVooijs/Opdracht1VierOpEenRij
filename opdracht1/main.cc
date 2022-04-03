// Hoofdprogramma voor oplossing voor eerste programmeeropdracht Algoritmiek,
// voorjaar 2022: Vier op een Rij
//
// Biedt de gebruiker een menustructuur om
// * het spel te spelen
//   - vanaf een nieuw, leeg bord
//   - vanaf een in te lezen, en mogelijk (deels) gevuld bord
//   waarbij de gebruiker steeds
//   - een zet kan uitvoeren (een schijf in een kolom laten vallen)
//   - de laatste zet ongedaan kan maken
//   - kan vragen om de score voor de speler die aan de beurt is, als beide
//     spelers vanaf dit moment optimaal verder spelen
//   - kan vragen om een `goede zet' voor de speler die aan de beurt is
//   - kan vragen om de eindscore voor de speler die aan de beurt is,
//     als hij vanaf nu een `goede zet' doet, terwijl de andere speler
//     steeds een beste zet doet
//   - kan vragen om de eindscore voor de speler die aan de beurt is,
//     als hij vanaf nu een random zet doet, terwijl de andere speler
//     steeds een `goede zet' doet
//
// * experiment 1 uit te voeren, waarbij een stand zo ver mogelijk vanaf
//   het einde wordt uitgespeeld met `goede zetten' tegen beste zetten
// * experiment 2 uit te voeren, waarbij voor een reeks maten van borden
//   het spel vanaf het begin tot het einde wordt uitgespeeld met random
//   zetten tegen `goede zetten' (waarbij ook het aantal simulaties wordt
//   gevarieerd dat wordt uitgevoerd bij het bepalen van een `goede zet')
//
// Namen + nummers studenten, datum

#include <iostream>
#include <ctime>  // voor clock() en clock_t
#include "vieropeenrij.h"
using namespace std;
const int MaxBestandsNaamLengte = 30; // maximale lengte van een bestandsnaam
const int nrSimulaties = 100;  // standaard aantal random simulaties per zet
                               // bij bepalen `goede zet'
const int nrTests = 100;  // aantal tests voor zelfde set parameters bij
                          // experimenten

//*************************************************************************

// Schrijf het menu op het scherm en vraag een keuze van de gebruiker.
// Retourneer: de keuze van de gebruiker
int keuzeUitMenu ()
{ int keuze;

  cout << endl;
  cout << "1. Een zet uitvoeren" << endl;
  cout << "2. Laatste zet ongedaan maken" << endl;
  cout << "3. Beste score (met beste zet) bepalen" << endl;
  cout << "4. Een goede zet bepalen" << endl;
  cout << "5. Bepaal score goed tegen best" << endl;
  cout << "6. Bepaal score random tegen goed" << endl;
  cout << "7. Stoppen met dit spel" << endl;
  cout << endl;
  cout << "Maak een keuze: ";
  cin >> keuze;

  return keuze;

}  // keuzeUitMenu

//*************************************************************************

// Roep vr1->besteScore aan, meet de benodigde tijd, en zet de relevante
// data op het scherm.
void roepBesteScoreAan (VierOpEenRij *vr1)
{ clock_t t1, t2;
  int kolom,
      score;
  long long aantalStanden;  // aantal bekeken standen bij aanroep besteScore

  t1 = clock ();
  score = vr1 -> besteScore (kolom, aantalStanden);
  t2 = clock ();
  cout << endl;
  cout << "Beste score is: " << score << endl;
  cout << "Een beste zet is: " << kolom << endl;
  cout << "We hebben hiervoor " << aantalStanden
       << " standen bekeken." << endl;
  cout << "Dit kostte " << (t2-t1) << " clock ticks, ofwel "
       << (((double)(t2-t1))/CLOCKS_PER_SEC) << " seconden." << endl;

}  // roepBesteScoreAan

//*************************************************************************

// Speel het spel op het bord van vr1.
// Hierbij krijgt de gebruiker herhaaldelijk de keuze om
// * een zet uit te voeren (een schijf in een kolom laten vallen)
// * te vragen om de score voor de speler die aan de beurt is, als beide
//   spelers vanaf dit moment optimaal verder spelen
// * te vragen om een `goede zet'
// * te vragen om de `goede score'
//
// Voor elke iteratie van het menu wordt de stand afgedrukt.
//
// Dit alles gaat door
// * totdat er een eindstand is bereikt (een van de spelers heeft vier op
//   een rij, of het bord is vol)
// * of totdat de gebruiker aangeeft dat hij wil stoppen met het spel
void doeSpel (VierOpEenRij *vr1)
{ int breedte,
      keuze,
      kolom,
      score;

  breedte = vr1->getBreedte();

  keuze = 0;
  while (keuze!=7 && !vr1->eindstand())
  {
    vr1 -> drukAf ();

    keuze = keuzeUitMenu ();

    switch (keuze)
    { case 1: cout << endl;
              cout << "Geef het nummer van de kolom (0.." << breedte-1 << "): ";
              cin >> kolom;
              vr1->doeZet (kolom);
              break;
      case 2: if (!(vr1->unDoeZet ()))
              { cout << endl;
                cout << "Er is geen zet ongedaan gemaakt." << endl;
              }
              break;
      case 3: roepBesteScoreAan (vr1);
              break;
      case 4: kolom = vr1 -> bepaalGoedeZet (nrSimulaties);
              cout << endl;
              cout << "Een goede zet is: " << kolom << endl;
              break;
      case 5: score = vr1 -> bepaalGoedeScore (nrSimulaties);
              cout << endl;
              cout << "Score goed tegen best is: " << score << endl;
              break;
      case 6: score = vr1 -> bepaalRandomScore (nrSimulaties);
              cout << endl;
              cout << "Score random tegen goed is: " << score << endl;
              break;
      case 7: break;
      default: cout << endl;
               cout << "Voer een goede keuze in!" << endl;
    }  // switch

  }  // while

  if (vr1->eindstand())
  { vr1 -> drukAf ();
    cout << endl;
    cout << "De huidige stand is een eindstand.\n";
  }

}  // doeSpel

//*************************************************************************

// Voert experiment 1 uit zoals beschreven in de opdracht.
void doeExperiment1 ()
{ int breedte, hoogte;
      
  cout << "Geef de breedte van het bord (1.." << MaxDimensie << "): ";
  cin >> breedte;
  cout << "Geef de hoogte van het bord (1.." << MaxDimensie << "): ";
  cin >> hoogte;

// TODO: implementeer deze functie verder, zodat het experiment met zo min
// mogelijk input van de gebruiker wordt uitgevoerd

}  // doeExperiment1

//*************************************************************************

// Voert experiment 2 uit zoals beschreven in de opdracht.
void doeExperiment2 ()
{

// TODO: implementeer deze functie, zodat het experiment met zo min
// mogelijk input van de gebruiker wordt uitgevoerd

}  // doeExperiment2

//*************************************************************************

void hoofdmenu ()
{ VierOpEenRij *vr1;  // pointer, om makkeijk nieuwe objecten te kunnen maken
                      // en weer weg te gooien
  int keuze,
      breedte, hoogte;
  char invoernaam[MaxBestandsNaamLengte+1];

  do
  {
    cout << endl;
    cout << "1. Een nieuw spel starten" << endl;
    cout << "2. Een spel inlezen" << endl;
    cout << "3. Experiment 1 uitvoeren" << endl;
    cout << "4. Experiment 2 uitvoeren" << endl;
    cout << "5. Stoppen" << endl;
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;
    switch (keuze)
    { case 1: cout << "Geef de breedte van het bord (1.." << MaxDimensie
                   << "): ";
              cin >> breedte;
              cout << "Geef de hoogte van het bord (1.." << MaxDimensie
                   << "): ";
              cin >> hoogte;
              vr1 = new VierOpEenRij (breedte, hoogte);
              doeSpel (vr1);
              delete vr1;  // netjes opruimen
              break;
      case 2: vr1 = new VierOpEenRij ();
              cout << "Geef de naam van het tekstbestand met het spel: ";
              cin >> invoernaam;
              if (vr1 -> leesIn (invoernaam))
                doeSpel (vr1);
              delete vr1;  // netjes opruimen
              break;
      case 3: doeExperiment1 ();
              break;
      case 4: doeExperiment2 ();
              break;
      case 5: break;
      default: cout << endl;
               cout << "Voer een goede keuze in!" << endl;
    }

  } while (keuze!=5);

}  // hoofdmenu

//*************************************************************************
  
int main ()
{
  hoofdmenu ();

  return 0;

}
