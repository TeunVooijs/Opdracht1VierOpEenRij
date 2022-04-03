// Implementatie van klasse VierOpEenRij

#include "vieropeenrij.h"
#include "standaard.h"
#include <fstream>   // voor inlezen van bord
#include <iostream>

//*************************************************************************

VierOpEenRij::VierOpEenRij ()
{
   
// TODO: implementeer zo nodig deze constructor

}  // default constructor

//*************************************************************************

// Constructor met parameters.
VierOpEenRij::VierOpEenRij (int nwBreedte, int nwHoogte)
{
  hoogte = nwHoogte;
  breedte = nwBreedte;
  for (int i = 0; i < nwHoogte; i++)
  {
    for (int j = 0; j < nwBreedte; j++)
    {
      bord[i][j]=0;
    }
    
  }

}  // constructor met parameters



//*************************************************************************

bool VierOpEenRij::leesIn (const char* invoernaam)
{

// TODO: implementeer deze memberfunctie

  return true;

}  // leesIn

//*************************************************************************

bool VierOpEenRij::eindstand ()
{

// TODO: implementeer deze memberfunctie

  return false;

} // eindstand

//*************************************************************************

void VierOpEenRij::drukAf ()
{
  
  cout << breedte << " " << hoogte << endl << endl << endl << endl;
  for (int i = 0; i < hoogte ; i++)
  {
    for (int j = 0; j < breedte; j++)
    {
      cout << bord[i][j] << " ";
    }
    cout << endl;
  }

}  // drukAf

//*************************************************************************

bool VierOpEenRij::doeZet (int kolom)
{

// TODO: implementeer deze memberfunctie
  if(kolom >= breedte){return false;}
  if (bord[kolom][hoogte] != 0){
    return false;
  } else{
  
    for (int i = 0; i < hoogte-1; i++)
    {
      if
    }
  }

  return true;

}  // doeZet

//*************************************************************************

bool VierOpEenRij::unDoeZet ()
{

// TODO: implementeer deze memberfunctie

  return true;

}  // unDoeZet

//*************************************************************************

int VierOpEenRij::besteScore (int &besteKolom, long long &aantalStanden)
{

// TODO: implementeer deze memberfunctie

  return 0;

}  // besteScore

//*************************************************************************

int VierOpEenRij::bepaalGoedeZet (int nrSimulaties)
{

// TODO: implementeer deze memberfunctie

  return 0;

}  // bepaalGoedeZet

//*************************************************************************

int VierOpEenRij::bepaalGoedeScore (int nrSimulaties)
{

// TODO: implementeer deze memberfunctie

  return 0;

}  // bepaalGoedeScore

//*************************************************************************

int VierOpEenRij::bepaalRandomScore (int nrSimulaties)
{

// TODO: implementeer deze memberfunctie

  return 0;

}  // bepaalRandomScore

//*************************************************************************

int VierOpEenRij::telSchijvenInRichting (int kleur, int kolom0, int rij0,
          int deltakolom, int deltarij)
{

// TODO: implementeer en gebruik deze private memberfunctie

  return 0;

}  // telSchijvenInRichting

