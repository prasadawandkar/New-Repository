#include <iostream>
#include<vector>
using namespace std;

int main() 
{
    int N, flag ,nod, nodes;
    float M[100][4], min ;
    vector<float> B;         
	cout << "what are the total number of branches in the network ?";
    cin >> N;
    cout << endl << "no of nodes?";
    cin >> nodes;
    cout << "Give the input in the following format:" << endl;
    cout << "Srno O_n T_n resistance:" << endl;
    
    for(int i =0;i<N;i++){
    	for(int j=0; j<4 ; j++){
    		cin >> M[i][j];
		}
	}
	flag = 1;
	int count = 0;
	while(count < 2*N){
		min = 10;
		for(int j=0; j<N; j++){
//			cout << j << "  " << min << "  " << endl;
			if((M[j][1]<0) && (M[j][2] == flag)){
				M[j][2] = (-1)*M[j][2];
				count = count+1;
			}
			if((M[j][2]<0) && (M[j][1] == flag)){
				M[j][1] = (-1)*M[j][1];
				count = count+1;
			}
			
			if((M[j][1]==flag) && (M[j][2]>0)){
				M[j][1] = (-1)*M[j][1];
				count = count+1;
				if(M[j][3] < min){
					min = M[j][3];
					nod = M[j][2];
				}
			}
			
			else if((M[j][2]==flag) && (M[j][1]>0)){
				M[j][2] = (-1)*M[j][2];
				count = count+1;
				if(M[j][3] < min){
					min = M[j][3];
					nod = M[j][1];
				}
			}
			
			else if((M[j][1]<0) && (M[j][2]>0) && (M[j][2] != flag)){
				if(M[j][3] < min){
					min = M[j][3];
					nod = M[j][2];
				}
			}
			
			else if((M[j][1]>0) && (M[j][1] != flag) && (M[j][2]<0)){
				if(M[j][3] < min){
					min = M[j][3];
					nod = M[j][1];
				}
			}	
		}
		flag = nod;
		B.push_back(min);
	}	
//	resistance of branches of MST
	cout << "resistance corresponding to branches in Minimal spanning trees are:" << endl;
	for(int m = 0; m< B.size() - 1; m++){
		cout << B[m] << "  ";
	}	
	cout << endl;
	cout << "The branches corresponding to minimal spanning trees are:" << endl;
	cout << "O_n T_n Rest" << endl;
//  Printing Branches of MST:
	for(int i=0; i<N; i++){
		for(int m = 0; m< B.size() - 1; m++){
			if(M[i][3]==B[m]){
				cout << -1*M[i][1] << "   " << -1*M[i][2] << "   " << M[i][3] << endl;
			}
		}
	}
    return 0;
}	
	
	
	

	
	
   
