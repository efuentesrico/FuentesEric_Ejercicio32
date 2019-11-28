#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;



int main()
{
	
    ofstream outfile;
	
	//Espaciado deltaX
	
	static float fX=1.0;
	static int num_x=101;
	float dX=fX/(num_x-1);
	
	//Tensión y densidad
	
	static float rho=1e-2;
	static float ten=40.0;
	
	//Velocidad de propagación
	
	static float c=sqrt(ten/rho);
	
    //Espaciado deltaT
	
    static float fTim=0.1;
	static int num_tim=120;
	float dTim=fTim/num_tim;
	
	int nX=1;
	int nTim=15;
    
    float c1=dX/dTim;
	float radio=c*c/(c1*c1);
    
    
    //Condiciones iniciales de la onda
    
	
    double wave[3][nX*num_x];
	
    for(int i=0;i<nX*num_x;i++)
	{
         wave[0][i]=sin(i*2*M_PI/(fX));
    }
	
	//Los extremos de la cuerda son nodos fijos...
	
     wave[1][0]=0;
     wave[1][-1]=0;
	
	//Mueve la onda según lo indicado en el libro
	

    for(int i=1;i<nX*(num_x-1);i++)
	{
         wave[1][i]= wave[0][i]+radio/2*( wave[0][i+1]+ wave[0][i-1]-2* wave[0][i]);
    }
	

    /*
    solucion
    */
	
   outfile.open("wave.dat");
	
	
	
    for (int j=0;j<nTim*20;j++)
	{
		
        for(int i=1;i<nX*(num_x-1);i++)
		{
             wave[2][i]=2* wave[1][i]- wave[0][i]+radio*( wave[1][i+1]+ wave[1][i-1]-2* wave[1][i]);
        }

        //Imprime
		
        for(int i=0;i<nX*num_x;i++)
		{
        outfile <<  wave[0][i] << " ";
        }
		
        outfile << "\n";

        for(int i=1;i<nX*(num_x-1);i++)
		{
             wave[0][i]= wave[1][i];
             wave[1][i]= wave[2][i];
        }
        
    }

    return 0;
}