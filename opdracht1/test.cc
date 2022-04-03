#include <iostream>
#include <vector>
using namespace std;


int main(){
  vector<vector<int>> weird = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};

  for (int i = 0; i < int(weird.size()); i++) {
    for (
      auto it = weird[i].begin();
      it != weird[i].end(); it++)
      cout << *it << " ";
    cout << endl;
  }


  return 0;
}