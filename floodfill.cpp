#include<iostream> 
using namespace std; 

#define M 6
#define N 6
  

void floodFill(int myScreen[][N], int a, int b, int currColor, int newColor) 
{ 
    if (a < 0 || a >= M || b < 0 || b >= N) 
        return; 
    if (myScreen[a][b] != currColor) 
        return; 
    if (myScreen[a][b] == newColor) 
        return; 
  
    myScreen[a][b] = newColor; 
  
    floodFill(myScreen, a+1, b, currColor, newColor); 
    floodFill(myScreen, a-1, b, currColor, newColor); 
    floodFill(myScreen, a, b+1, currColor, newColor); 
    floodFill(myScreen, a, b-1, currColor, newColor); 
} 
  
void findColor(int myScreen[][N], int a, int b, int newColor) 
{ 
    int currColor = myScreen[a][b]; 
    floodFill(myScreen, a, b, currColor, newColor); 
} 
  
int main() 
{ 
    int myScreen[M][N] = 
                    { 
                      {1, 1, 1, 1, 1,1}, 
                      {1, 1, 2, 1, 2,2},
                      {0, 2, 1, 1, 1,1}, 
                      {1, 2, 2, 2, 3,0}, 
                      {1, 0, 1, 2, 1,1}, 
                      {1, 1, 1, 0, 2,2},
                     }; 
    int a = 3, b = 3, newColor = 4; 
    findColor(myScreen, a, b, newColor); 
  
    cout << "Updated screen after call to floodFill: \n"; 
    
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << myScreen[i][j] << " "; 
        cout << endl; 
    } 
    return 0;
} 