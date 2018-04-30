/*
	Solu��o do problema das n-rainhas (N-Queens Problem)
	Autor:R�mulo Henrique
*/

#include <iostream>
#include <vector>

using namespace std;

// conta a quantidade de solu��es
int sol = 0;

// fun��o para mostrar o tabuleiro
void mostrarTabuleiro(vector<vector<int> > & tab, int N)
{
	for(int i2 = 0; i2 < N; i2++)
	{
		for(int j = 0; j < N; j++)
		{
			if(tab[i2][j] == 1)
				cout << "R\t";
			else
				cout << "-\t";
		}
		cout << "\n\n";
	}
	cout << "\n";
}

// verifica se � seguro colocar a rainha numa determinada coluna
// isso poderia ser feito com menos c�digo, mas assim ficou mais did�tico
bool seguro(vector<vector<int> > & tab, int N, int lin, int col)
{
	int i2, j;

	// verifica se ocorre ataque na linha
	for(i2 = 0; i2 < N; i2++)
	{
		if(tab[lin][i2] == 1)
			return false;
	}

	//verifica se ocorre ataque na coluna
	for(i2 = 0; i2 < N; i2++)
	{
		if(tab[i2][col] == 1)
			return false;
	}

	// verifica se ocorre ataque na diagonal principal
	// acima e abaixo
	for(i2 = lin, j = col; i2 >= 0 && j >= 0; i2--, j--)
	{
		if(tab[i2][j] == 1)
			return false;
	}
	for(i2 = lin, j = col; i2 < N && j < N; i2++, j++)
	{
		if(tab[i2][j] == 1)
			return false;
	}

	// verifica se ocorre ataque na diagonal secund�ria
	// acima e abaixo
	for(i2 = lin, j = col; i2 >= 0 && j < N; i2--, j++)
	{
		if(tab[i2][j] == 1)
			return false;
	}
	for(i2 = lin, j = col; i2 < N && j >= 0; i2++, j--)
	{
		if(tab[i2][j] == 1)
			return false;
	}

	// se chegou aqui, ent�o est� seguro (retorna true)
	return true;
}

/*
	fun��o que resolve o problema
	retorna true se conseguiu resolver e false caso contr�rio
*/
void executar(vector<vector<int> > & tab, int N, int col)
{
	if(col == N)
	{
		cout << "Solucao " << sol + 1 << ":\n\n";
		mostrarTabuleiro(tab, N);
		sol++;
		return;
	}

	for(int i2 = 0; i2 < N; i2++) 
	{
		// verifica se � seguro colocar a rainha naquela coluna
		if(seguro(tab, N, i2, col))
		{
			// insere a rainha (marca com 1)
			tab[i2][col] = 1;

			// chamada recursiva
			executar(tab, N, col + 1);

			// remove a rainha (backtracking)
			tab[i2][col] = 0;
		}
	}
}

int main(int argc, char *argv[])
{
	// n�mero de rainhas
	int N ;
	cout<<"\nSo e possivel uma rainha por cada tabela,\n\nportanto a quantidade de rainhas � igual ao numero de linhas por coluna";
	cout<<"\n\n\nInsira o padrao do tabuleiro:\n";
	cin	>> N;
	
	// tabuleiro (matriz)
	vector<vector<int> > tab;

	// inserindo todas as linhas
	for(int i2 = 0; i2 < N; i2++)
	{
		vector<int> linha(N);
		tab.push_back(linha);
	}
	
	// imprime todas as solu��es


	// imprime a quantidade de solu��es
	cout << "\nEncontradas " << sol << " solucoes!\n";

	return 0;
}
