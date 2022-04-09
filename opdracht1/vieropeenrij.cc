// Implementatie van klasse VierOpEenRij

#include "vieropeenrij.h"
#include "standaard.h"
#include <fstream>   // voor inlezen van bord
#include <iostream>

//*************************************************************************

VierOpEenRij::VierOpEenRij ()
{
  eindbereikt = false;
  aantal_op_rij=0;
  aanBeurt = 1;
  zet = 0;
  for (int i = 0; i < MaxDimensie; i++)
  {
    for (int j = 0; j < MaxDimensie; j++)
    {
      bord[i][j]=0;
    }
  }
// TODO: implementeer zo nodig deze constructor

}  // default constructor

//*************************************************************************

// Constructor met parameters.
VierOpEenRij::VierOpEenRij (int nwBreedte, int nwHoogte)
{
  eindbereikt = false;
  aantal_op_rij = 0;
  aanBeurt = 2;
  zet = -1;
  hoogte = nwHoogte;
  breedte = nwBreedte;
  cout << breedte << " " << hoogte << endl;
  for (int i = 0; i < nwHoogte; i++)
  {
    for (int j = 0; j < nwBreedte; j++)
    {
      bord[i][j]=0;
      bord2[i][j]=0;
    }
    
  }
}  // constructor met parameters

  

//*************************************************************************

bool VierOpEenRij::leesIn (const char* invoernaam){
// TODO: implementeer deze memberfunctie
  ifstream fin (invoernaam, ios::binary);
  
  int getal;
  int count = 0;
  
  int posx = 0, posy = 0;
  fin >> breedte;
  fin >> hoogte;

  while (! fin.eof()){
    fin >> getal ;

    if(getal < 3 ){
      posx = count % breedte;
      posy = count / breedte;
      bord[posy][posx] = getal;
      count+=1;
    }

  }

  fin.close();
  return true;

}  // leesIn

//*************************************************************************

bool VierOpEenRij::eindstand (){
  int count = 0;
  int rij = 0 ,kolom;

  if(!zetten.empty()){
    kolom = zetten.back();
    while (true){
      if (bord[rij][kolom] == 0){
        rij += 1;
        if (rij == hoogte){
          break;
        }
      } else if(bord[rij][kolom] != 0){
        for (int k = -1; k < 2 ; k++){
          for (int l = -1; l < 2 ; l++){
            if (bord[rij+k][kolom+l] == bord[rij][kolom] && (l != 0 || k != 0 )){
              count = telSchijvenInRichting(aanBeurt,kolom,rij,l,k);
              cout << aanBeurt << " :aanbeurt" << endl;
              if (count == 4){
                return true;
              } else
                count = 0;
            } 
          }
        }      
        break;
      }
    }
  }
  for (int j = 0; j < breedte; j++){
    if ( bord[0][j] == 0){
      return false;
    }
  }
  eindbereikt = true;
  return true;
} // eindstand

//*************************************************************************

int VierOpEenRij::winnaar(){






}

//*************************************************************************

void VierOpEenRij::drukAf ()
{
  for (int  i = 0; i < breedte; i++)
  {
    cout << i << " ";
  }
  cout << endl;
  // cout << breedte << " " << hoogte << endl << endl << endl << endl;
  for (int i = 0; i < hoogte ; i++)
  {

    for (int j = 0; j < breedte; j++){
      cout << bord[i][j] << " ";
    }
    cout << i << endl;
  }

}  // drukAf

//*************************************************************************

bool VierOpEenRij::doeZet (int kolom)
{
  
// TODO: implementeer deze memberfunctie
  if (aanBeurt == 1){
    aanBeurt = 2;
  } else {
    aanBeurt = 1;
  }
  int rownum=0;
  if(kolom >= breedte){return false;}
  if (bord[0][kolom] != 0){
    return false;
  } else {
    while (true){
      if (bord[rownum][kolom] != 0 || rownum == hoogte){
        bord[rownum-1][kolom] = aanBeurt;
        rownum = 0;
        // eindstand();
        
        break;
      } else {
        rownum += 1;
      }
    }
  }
  zet+=1;
  zetten.push_back(kolom);
  return true;
}  // doeZet

//*************************************************************************

bool VierOpEenRij::unDoeZet ()
{

// TODO: implementeer deze memberfunctie
  
  if (zetten.size()==0){
    return false;
  }
  

  int kolom = zetten.back();
  zetten.pop_back();
  int rownum = 0;


  while (true){
    if (bord[rownum][kolom] != 0){
        bord[rownum][kolom] = 0;
        rownum = 0;
        if (aanBeurt == 1){
          aanBeurt = 2;
        } else {
          aanBeurt = 1;
        }
        break;
      } else {
        rownum += 1;
      }
  }
  return true;

}  // unDoeZet

//*************************************************************************

int VierOpEenRij::besteScore (int &besteKolom, long long &aantalStanden)
{

// TODO: implementeer deze memberfunctie
  // if (eindstand()) else
  // { for alle mogelijke zetten k do
  // { doeZet (k);
  // score = - besteScore ();
  // unDoeZet (k);
  //   onthoud beste score en bijbehorende zet
  // }
  // }
  // return 0;

}  // besteScore

//*************************************************************************

int VierOpEenRij::bepaalGoedeZet (int nrSimulaties)
{

// TODO: implementeer deze memberfunctie
  for (int i = 0; i < breedte; i++){
    if (bord[0][i] != 0){
      break;
    }
    for (int j = 0; j < nrSimulaties; j++){
        
        





    }
  }
  





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
int deltakolom, int deltarij){ 
  int count=1;
  // Als een bepaalde richting op werkt roep weer op met zelfde richting
  // return count + telschijveninrichting(waardes met zelfde riching)
  // als waarde niet geld stopt het

  if (bord[rij0+deltarij][kolom0+deltakolom] == bord[rij0][kolom0] && (deltakolom != 0 || deltarij != 0 )){
    // cout << count << endl;
    return count += telSchijvenInRichting(kleur,kolom0+deltakolom,rij0+deltarij,deltakolom,deltarij);
  } 
  
// TODO: implementeer en gebruik deze private memberfunctie

  return count;

}  // telSchijvenInRichting

void VierOpEenRij::kopie(){
  for (int i = 0; i < hoogte; i++)
  {
    for (int j = 0; j < breedte; j++)
    {
      bord2[i][j] = bord[i][j];
    }
    
  }
}


void VierOpEenRij::reset(){
  for (int i = 0; i < hoogte; i++)
  {
    for (int j = 0; j < breedte; j++)
    {
      bord[i][j] = bord2[i][j];
    }
    
  }
}
