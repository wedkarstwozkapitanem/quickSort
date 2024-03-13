#include<iostream>
#include<math.h>
#include <time.h>

template<typename T>
void quickSort(T* tab, const int lewy, const int prawy);


template<typename T>
void wypisz(const T* tab, const int rozmiar) {
	for (int i{}; i < rozmiar; i++) std::cout << tab[i] << " ";
}


int main() {
	srand(time(NULL));

	std::cout << "Ile ma byc liczb?: ";
	int ileLiczb{}; std::cin >> ileLiczb;
	
	std::cout << "Jakiej wielkosci?: ";
	int przedzial{}; std::cin >> przedzial;

	double* liczby = new double[ileLiczb];
	for (int i{ }; i < ileLiczb; i++) {
		liczby[i] = rand() % przedzial + 1;
	}

	quickSort(liczby,0,ileLiczb - 1);

	for (int i{ }; i < ileLiczb;i++) std::cout << liczby[i] << " ";
	return EXIT_SUCCESS;
}


template<typename T>
void quickSort(T* tab,const int lewy,const int prawy) {
	if (prawy <= lewy) return;
	int i = lewy-1,j = prawy+1, pivot =std::min(std::max(tab[(lewy + prawy)/2],tab[0]),std::max(tab[(lewy + prawy) / 2], tab[prawy]));

	while (true) {
		while (tab[++i] < pivot);
		while (tab[--j] > pivot);
		if (i <= j) std::swap(tab[i],tab[j]);
		else break;
	}
	if (j > lewy) {
		quickSort(tab, lewy, j);
	}
	if(i<prawy) {
		quickSort(tab, i, prawy);
	}
	
}