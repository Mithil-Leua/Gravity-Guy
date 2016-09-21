#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		string l1,l2;
		cin >> l1 >> l2;
		char lane[2][l1.size()];
		int len = l1.size();
		for(int i=0;i<len;i++){
			lane[0][i] = l1[i]; 
		}
		for(int i=0;i<len;i++){
			lane[1][i] = l2[i];
		}

		int table[2][len];
		// 0 = blocked 
		// 1 = not blocked
		for(int j=0;j<len;j++){
			for(int i=0;i<2;i++){
				if(j == 0){
					if(lane[i][j] == '.')
						table[i][j] = 1;
					else
						table[i][j] = 0;
				}
				else{
					if(lane[i][j] == '#')
						table[i][j] = 0;
					else{
						//cout << i << j <<endl;
						if(i==0){
							if(table[i][j-1] || table[i+1][j-1])
								table[i][j] = 1;
							else
								table[i][j] = 0;
						}
						if(i==1){
							if(table[i][j-1] || table[i-1][j-1])
								table[i][j] = 1;
							else
								table[i][j] = 0;
						}
					}
				}
			}
		}
		int curr,flag = 0,jump=0;
		for(int j=len-1;j>=0;j--){
			//cout << curr << endl; 
			if(!(table[0][j]||table[1][j])){
				flag = 1;
				cout << "No" <<endl;
				break;
			}
			else{
				if(j == len-1){
					if(table[0][j]&&table[1][j])
						curr = 2;
					else if(table[0][j] && !table[1][j])
						curr = 0;
					else if(!table[0][j] && table[1][j])
						curr = 1;
				}
				else{
					if(curr == 0){
						if(table[0][j] && j!=0){
							curr = curr;
						}
						else if(table[1][j] && !table[0][j]){
							curr = 1;
							jump++;
						}
						else
							curr = curr;
					}
					else if(curr == 1){
						if(table[1][j] == 1 && !table[0][j]){
							curr = curr;
						}
						else if(table[0][j] && !table[1][j]){
							curr = 0;
							jump++;
						}
						else{
							curr = curr;	
						}
					}
					else{
						if(table[0][j] && table[1][j]){
							curr = curr;
						}
						else if(table[1][j] && !table[0][j]){
							curr = 1;
						}
						else if(table[0][j] && !table[1][j]){
							curr = 0;
						}
					}
				}
			}
		}
		if(flag == 0){
			cout << "Yes" << endl;
			cout << jump <<endl;
		}
	}
    return 0;
}
