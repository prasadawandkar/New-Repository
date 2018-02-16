#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int N, nodes, e1,A,k;
	float M[100][5],O[100][4], max,e,g;
	vector<float> E,G;      
	cout << "No of total branches in network?" << endl ;
	cin >> N;
	cout << "No of nodes ?" << endl;
	cin >> nodes;
	cout << "Input Format:" << endl;
	cout << "Srn O_n T_n Quantity Resistance " << endl;

//	give the input in format Srn   O_n   T_n   Quantity   Resistance   0 //
	for(int i =0; i<N ;i++){
    	for(int j=0; j<5 ; j++){
    		cin >> M[i][j];
		}
	}

//  Forward pass Solution:
	E.push_back(0); 
	for(int i=1; i<nodes; i++){
		max = 0;
		for(int j =0; j<N; j++){
			if(M[j][2] == i+1){
				k = M[j][1];
				e = E[k-1] + (M[j][4])*(M[j][3])*(M[j][3]) ;
				if(e > max){
					max = e;
				}
			}
			
		}
		E.push_back(max);
	}

//  Backward Pass Solution:
//	G[nodes-1] = E[nodes-1] ;
//	G.push_back(E[E.size()-1]); 
//	for(int i=nodes-2; i>=0; i--){
//		int min = 10000;
//		for(int j=0; j<N; j++){
//			if(M[j][1] == i+1){
//				k = M[j][1];
//				g = G[nodes-1-k] - (M[j][4])*(M[j][3])*(M[j][3]);
//				if(g < min){
//					min = g;
//				}
//			}
//		}
//		G.push_back(min);
//	}
//	for(int i=0; i<G.size() ; i++){
//		cout << G[i] << "  ";
//	}
//	cout << endl;
//	for(int i=0; i< N ; i++){
//		cout << (M[i][4])*(M[i][3])*(M[i][3]) << "  ";
//	}

//  Output MAtrix:
	for(int i=0; i<N; i++){
		for(int j=0; j<=2; j++){
			O[i][j] = M[i][j];
		}
		O[i][3] = E[M[i][2]-1] - E[M[i][1]-1] - (M[i][4])*(M[i][3])*(M[i][3]) ;
//		O[i][4] = G[nodes-M[i][2]] - G[nodes-M[i][1]] - (M[i][4])*(M[i][3])*(M[i][3]) ;
	}


	cout << endl << endl;
		
//	output 
	cout << "Srno O_n T_n Reg(Fp)" << endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<=3; j++){
			cout << O[i][j] << "    " ;
		}
		cout << endl;
	}

	return 0;
}



