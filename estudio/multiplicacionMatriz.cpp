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
			matrix[i][j] = -100 + (rand() % 100);
		}
	}
}

void fillMatrixZero(int matrix[SIZEM][SIZEM], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			matrix[i][j] = 0;
		}
	}
}

void  multiply( int A[SIZEM][SIZEM],int B[SIZEM][SIZEM], int n) {
	
	int C[SIZEM][SIZEM];
	fillMatrixZero(C, n);
		
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
						
			for (int k = 0; k < n; k++){
				C[i][j] += A[i][k] * B[k][j]; 
			}
		
		}
	}
	showMatrix(C, n);
    
}


int main(int argc, char** argv) {
	
	clock_t tStart = clock();
    
	int n;
	
	int I[SIZEM][SIZEM] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	int A[SIZEM][SIZEM];
	int B[SIZEM][SIZEM];
	
	cout << "\n Enter the size of the matrix:";
	cin >> n;
	cout << "\n Enter the elements of the matrix:\n" << endl;
	
	cout<<"\n The entered matrix is: \n"<<endl;
	
	fillMatrix( A, n );
	fillMatrix( B, n);
	
	showMatrix( A, n);
	cout << endl;
	
	showMatrix( I, n);
	cout << endl;
	
	multiply( A, I, n);
	cout << endl;
	
	  
	printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  
   return 0;
}
