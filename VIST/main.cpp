#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, N;
	double p;
	

	cout << "Unesite n: "; cin >> n;
	cout << "Unesite p: "; cin >> p;
	cout << "Unesite N: "; cin >> N;
	int* vektor = new int[n];
	if (n < 0 || N < 0 || p < 0 || p>1) return 0;
	for (int i = 0; i < n + 1; i++) vektor[i] = 0;

	for (int i = 0; i < N; i++) {
		int br = 0;
		for (int j = 0; j < n + 1; j++) {
			double b = (double)rand() / RAND_MAX;
			if (b < p) br++;
		}
		vektor[br]++;
	}

	cout << "Relativna frekvencija" << endl;
	for (int i = 0; i < n + 1; i++) {
		cout << "Vektor[" << i << "] = " << (double)vektor[i] / N << endl;
	}
	cout << endl;

	// Histogram
	int sirina_grafika = 6;

	for (int i = 0; i < n + 1; i++) vektor[i] = round(100 * ((double)vektor[i] / N));
	int max = vektor[0];
	for (int i = 0; i < n + 1; i++) if (vektor[i] > max) max = vektor[i];
	for (max; max > 0; max--) {
		cout <<"0," << std::setfill('0') << std::setw(2) << max << "|";
		for (int i = 0; i < n + 1; i++) {
			if (vektor[i] == max) {
				vektor[i]--; cout << std::setfill(' ') << std::setw(sirina_grafika)<< "||";
			}
			else cout << std::setfill(' ') << std::setw(sirina_grafika) << " ";
		}
		cout << endl;
	}
	cout <<"0,00|";
	for (int i = 0; i < n + 1; i++)cout << std::setfill('-') << std::setw(sirina_grafika) << "-";
	cout << endl;
	cout << std::setfill(' ') << std::setw(sirina_grafika) << " ";
	for (int i = 0; i < n + 1; i++) cout << std::setfill(' ') << std::setw(sirina_grafika-1)<< i << " ";
}