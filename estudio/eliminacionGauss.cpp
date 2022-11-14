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

int determinant( int matrix[SIZEM][SIZEM], int n) {
   //int iterations = 0;
   int det = 0;
   int submatrix[SIZEM][SIZEM];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         if( matrix[0][x] != 0){ 
         //iterations++;
         //cout << "\n iteration = " << iterations ;
         //cout << "\n k = " << x ;
         //cout << "\n D = " << det;
         //cout << "\n [0][0] = " << matrix[0][x] << endl;
         //showMatrix(submatrix, n - 1);
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
		 //cout << "\n D = " << det;
		} else {
			
      }
	}
   return det;
	}
}


void showMatrix(int matrix[SIZEM][SIZEM],int n){
	for (int i = 0; i < n; i++) {
		cout<<endl;
		for (int j = 0; j < n+1; j++){
			cout << " [" <<matrix[i][j] <<"] ";
		}
	}	
} 


void fillMatrix(int matrix[SIZEM][SIZEM], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			matrix[i][j] = -20 + (rand() % 10);
		}
	}
}

void elmiminationGauss(int matrix[SIZEM][SIZEM], int n){

}

int main(int argc, char** argv) {
	
	clock_t tStart = clock();
    
	int n, i, j, k;
   
	//int matrix[SIZEM][SIZEM];
	
	int matriz[SIZEM][SIZEM] = {{-2,3,-1,2},{3,-1,3,-1},{-1,2,5,-2},{6,-3,1,1}};

	
	cout << "Enter the size of the matrix:";
	cin >> n;
	cout << "Enter the elements of the matrix:" << endl;
	
	cout<<"The entered matrix is:"<<endl;
	
	//fillMatrix( matrix, n );

	showMatrix(matriz, n);
		
	//int deter = determinant( matrix, n);
	
	int piva;
	int pivb;
		
	
	for (i = 0; i < n; i++){
		piva = matriz[i][i];
		cout << "\n piva = " << piva << endl;
		
		for ( j = i+1; j < n; j++){
			pivb = matriz[j][i];
			cout << " pivb = " << pivb << endl;
				
			//pivb = ( (piva < 0 && pivb > 0))? -pivb : pivb ;
				
			for (k = 0; k < n; k++){
				matriz[j][k] = pivb * matriz[i][k] - piva * matriz[j][k];
				//showMatrix( matrix, n );
				cout << endl;
			}
		}
	}
	
	//int det = 1;
	
	//for ( i = 0; i < n; i++){
		//det *= matrix[i][i];
	//}
	
	//cout << "\n determinant(A) = " << deter << endl;
	//cout << " det(A) = " << det << endl;
	//cout << "\n determinant(A) = " << determinant(matrix,n) << endl;
	
	//showMatrix( matrix, n );	
		
	
	//cout << endl;
	
	showMatrix( matriz, n );
	
  
	printf("Time taken: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  
   return 0;
}
