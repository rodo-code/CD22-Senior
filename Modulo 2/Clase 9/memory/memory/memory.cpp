#include "grader.h"
#include "memory.h"
#include <vector>
#include <cstdio>

using namespace std;

void play_50puntos() {
   char a, b;
   for (int carta=1; carta<=50; carta++) {
      for(int j=carta+1;j<=50;j++){
         a = faceup(carta);
         b = faceup(j);
         if(a==b) break;
      }
   }
}

void play(){
   vector< vector<int> >memoria;
   memoria.assign(25,vector<int>());
   char a, b;
   for(int i=1;i<=50;i++){
      a = faceup(i);
      int ascii = a - 'A';
      memoria[ascii].push_back(i);
   }
   for(int i=0;i<25;i++){
      a = faceup(memoria[i][0]);
      b = faceup(memoria[i][1]);
   }
}
