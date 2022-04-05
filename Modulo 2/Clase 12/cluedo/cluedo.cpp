#include "grader.h"
#include "cluedo.h"

void Solve(){
   int murder=1,location=1,weapon=1;
   int res;
   while(true){
      res = Theory(murder,location,weapon);
      if(res==0) break;
      if(res==1) murder++;
      if(res==2) location++;
      if(res==3) weapon++;
   }
}
