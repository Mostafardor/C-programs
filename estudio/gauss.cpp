/*
 * determinanteMatriz.cpp
 * 
 * Copyright 2022 W10 <W10@DESKTOP-T3EABRP>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
#include <math.h>
#include <time.h>

const int SIZEM = 15;

using namespace std;


void showMatrix(int matrix[SIZEM][SIZEM],int n){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cout << " [" <<matrix[i][j] <<"] ";
		}
		cout<<endl;
	}	
} 


void fillMatrix(int matrix[SIZEM][SIZEM], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			matrix[i][j] = -10 + (rand() % 10);
		}
	}
}

void elmiminationGauss(int matrix[SIZEM][SIZEM], int n){

}

int main(int argc, char** argv) {
	
	clock_t tStart = clock();
    
	int n;
   
	int matrix[SIZEM][SIZEM];
	
	cout << "Enter the size of the matrix:";
	cin >> n;
	cout << "Enter the elements of the matrix:" << endl;
	
	cout<<"The entered matrix is:"<<endl;
	
	fillMatrix( matrix, n );

	showMatrix(matrix, n);
	
	
	
	
	int piva = matrix[0][0];
	int pivb = matrix[1][0];
	for (int i = 0; i < n; i++){
		matrix[1][i] = pivb * matrix[0][i] - piva * matrix[1][i];
	}
		
	
	pivb = matrix[2][0];
		for (int i = 0; i < n; i++){
		matrix[2][i] = pivb * matrix[0][i] - piva * matrix[2][i];
	}	
	
	
	pivb = matrix[3][0];
	for (int i = 0; i < n; i++){
		matrix[3][i] = pivb * matrix[0][i] - piva * matrix[3][i];
	}

	
	piva = matrix[1][1];
	pivb = matrix[2][1];
		for (int i = 0; i < n; i++){
		matrix[2][i] = pivb * matrix[1][i] - piva * matrix[2][i];
	}
	
	pivb = matrix[3][1];
	for (int i = 0; i < n; i++){
		matrix[3][i] = pivb * matrix[1][i] - piva * matrix[3][i];
	}
	
	
	piva = matrix[2][2];
	pivb = matrix[3][2];
	
	cout << "\n piva = " << piva << endl;
	cout << " pivb = " << pivb << endl;
		
	if( piva > 0 && pivb > 0){
		piva = -piva;
	}	
	for (int i = 0; i < n; i++){
		matrix[3][i] = pivb * matrix[2][i] - piva * matrix[3][i];
	}
	showMatrix( matrix, n );
	
	

		
		
		
		
		
	//fact = n - 1
	//for (i = 0; i < fact; i++, --fact){
		//piva = matrix[i][i];
		//for ( j = 0; i < ; i++){
			//pivb = matrix[][0];
			
			//cout << "\n piva = " << piva << endl;
			//cout << " pivb = " << pivb << endl;
				
			//if( piva > 0 && pivb > 0){
				//piva = -piva;
			//}	
			//for (k = 0; k < n; i++){
				//matrix[2][k] = pivb * matrix[0][k] - piva * matrix[2][k];
			//}
		//}
	//}
	//showMatrix( matrix, n );	
		
		
		
		
		
		
		
		
	
	
	
	cout << endl;
	
  
	printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  
   return 0;
}
