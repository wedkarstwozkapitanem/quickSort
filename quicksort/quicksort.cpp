#include<iostream>
#include<math.h>


template<typename T>
void quickSort(T* tab, const int lewy, const int prawy);


template<typename T>
void wypisz(const T* tab, const int rozmiar) {
	for (int i{}; i < rozmiar; i++) std::cout << tab[i] << " ";
}


int main() {

	int liczby[] = {6,4,7,8,3,24};
	quickSort(liczby,0,sizeof(liczby)/sizeof(liczby[0]) - 1);

	for (auto& i : liczby) std::cout << i << " ";
	return EXIT_SUCCESS;
}


template<typename T>
void quickSort(T* tab,const int lewy,const int prawy) {
	if (prawy <= lewy) return;
	int i = lewy-1,j = prawy+1, pivot =std::min(std::max(tab[(lewy + prawy)/2],tab[0]),std::max(tab[(lewy + prawy) / 2], tab[prawy]));
	std::cout << "Pivot: " << pivot << ": ";

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