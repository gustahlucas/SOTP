#ifndef PRIMOS_HPP 
#define PRIMOS_HPP
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std; 
using namespace std::chrono;

bool calcular_primos_intervalo(int inf, int sup, int &result)
{
	int quant_primos = 0;
	for(int i = inf ; i <= sup ; i++)
	{
		int primo = 0;
		int raiz = sqrt(i);
		for(int j = 1 ; j <= raiz ; j++)
		{
			if(i%j == 0)
				primo++;
		}

		//se for primo, imprime na tela
		if(primo == 1)
		{	
			quant_primos++;
		}
		//pulando linha para organizar melhor a impressao
		if(i%10 == 0);
	}
	result = quant_primos; 

		// cout << " Chamou a calcular_primos_intervalo" << endl; 
	return true; 
}
#endif
