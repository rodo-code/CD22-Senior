#include "supertrees.h"
#include <vector>
#include <cmath>

using namespace std;

int construct(vector<vector<int>> p) {
	int n = p.size();
	vector<vector<int>> answer;
	answer.assign(n,vector<int>(n));
	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++){
			if(abs(i-j)==1){
				answer[i][j]=1;
			}
			else{
				answer[i][j]=0;
			}
		}
	}
	build(answer);
	return 1;
}
// g++ -std=c++17 grader.cpp supertrees.cpp -o supertrees.exe