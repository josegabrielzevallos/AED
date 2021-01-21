#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>
#include <math.h>

using namespace std;


double DistaciaEuclidiana(vector<int> &dato1, vector<int> &dato2) {
	double distancia = 0.0;
	for (int i = 0; i < int(dato1.size()); i++) {
		distancia += pow(dato1[i] - dato2[i],2);
	}
	return sqrt(distancia);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double Tiempo(vector<vector<int>> &dato) {
	
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	
	
	for (auto &dato_ : dato) {
		for (auto &dato_o : dato) {
			DistaciaEuclidiana(dato_, dato_o);
			
		}
	}
	end = std::chrono::high_resolution_clock::now();
	int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	
	return duration;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void obtenerdatorandon(vector<vector<int>> &dato, int N, int dimensiones) {
	dato.resize(N);
	for (auto &dato_ : dato) {
		for (int i = 0; i < dimensiones; i++) {
			dato_.push_back(rand() % 1000 + 500);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[]) {
	
	vector<vector<vector<int>>> V;
	int tamano[3] = { 10000,20000,25000 };
	int dimensiones[4] = { 5,10,15,20 };
	
	
	for (int tam = 0; tam < 3; tam++) {
		for (int dim = 0; dim < 4; dim++) {
			vector<vector<int>> D;
			obtenerdatorandon(D, tamano[tam], dimensiones[dim]);
			V.push_back(D);
		}
	}
	
	for (auto &V_ : V) {
		cout << "Tiempo-->" << int(V_.size()) << "," << int(V_[0].size()) << " = " << Tiempo(V_) << endl;
	}
	system("pause");
	return 0;
	
}
