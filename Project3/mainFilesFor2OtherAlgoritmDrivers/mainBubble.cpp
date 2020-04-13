#include <iostream>
#include <fstream>
#include "sorter.h"
#include "sorter.cpp"
#include <string>
#include <vector>
#include <ctime>
using namespace std;

//function to read in data from file
void readArray(string fileName, vector<int> &v) {
	ifstream fp;
	fp.open(fileName);
	if (fp.is_open()) {
		cout << "file open" << endl;
		int x;
		while (fp>>x) {
			v.push_back(x);
		}
	}
	else {
		cout << "File Open Error" << endl;
	}
	fp.close();
}

//writes a sorter object to a file

void writeArray(string fileName, sorter<int> s){
	ofstream fp;
	fp.open(fileName);
	for (int i = 0; i < s.getSize(); i++) {
		fp << (s.getArray()[i]) << " ";
	}
	fp.close();
}
int main() {
	//vectors to store the count information
	vector<double> times;
	vector<size_t> swaps;		//60 of each sort type
	vector<size_t> comparisons;
	//Read into sorter objects
	vector<int> thousand, ten_thousand, hundred_thousand, thousandS, ten_thousandS, hundred_thousandS;
	//read unsorted arrays
	readArray("data0.txt", thousand);
	readArray("data1.txt", ten_thousand);
	readArray("data2.txt", hundred_thousand);

	//read sorted arrays
	readArray("sortedData0.txt", thousandS);
	readArray("sortedData1.txt", ten_thousandS);
	readArray("sortedData2.txt", hundred_thousandS);

	//create list obj for each
	sorter<int> t(thousand), tt(ten_thousand), ht(hundred_thousand), tS(thousandS), ttS(ten_thousandS), htS(hundred_thousandS);


	ofstream fp;
	fp.open("bubbleSort.csv");
	//BUBBLE SORT
	fp << "bubbleSort\n";
	fp << "RunTime\n";
	fp << "i,1k(unsorted),10k(unsorted),100k(unsorted),1k(sorted),10k(sorted),100k(sorted)\n";
	//Gather data for each 10 times
	for (int i = 0; i < 10; i++) {
		cout << "SORT ROUND: " << i << endl;
		clock_t start;
		//1k
		cout << "1k file sorting" << endl;
		start = clock();
		t.bubbleSort();
		times.push_back ((clock()-start) / (double)CLOCKS_PER_SEC);
		swaps.push_back(t.getSwapCount());
		comparisons.push_back(t.getCompCount());

		//10k
		cout << "10k file sorting..." << endl;
		start = clock();
		tt.bubbleSort();
		times.push_back((clock() - start) / (double)CLOCKS_PER_SEC);
		swaps.push_back(tt.getSwapCount());
		comparisons.push_back(tt.getCompCount());
		//100k
		cout << "100k file sorting..." << endl;
		start = clock();
		ht.bubbleSort();
		times.push_back((clock() - start) / (double)CLOCKS_PER_SEC);
		swaps.push_back(ht.getSwapCount());
		comparisons.push_back(ht.getCompCount());
		//Sorted already
		cout << "presorted sorting..." << endl;
		//1k
		start = clock();
		tS.bubbleSort();
		times.push_back((clock() - start) / (double)CLOCKS_PER_SEC);
		swaps.push_back(tS.getSwapCount());
		comparisons.push_back(tS.getCompCount());
		//10k
		start = clock();
		ttS.bubbleSort();
		times.push_back((clock() - start) / (double)CLOCKS_PER_SEC);
		swaps.push_back(ttS.getSwapCount());
		comparisons.push_back(ttS.getCompCount());
		//100k
		start = clock();
		htS.bubbleSort();
		times.push_back((clock() - start) / (double)CLOCKS_PER_SEC);
		swaps.push_back(htS.getSwapCount());
		comparisons.push_back(htS.getCompCount());
		//NEWLINE for next loop
		
	}
	cout << "Sorting complete. Printing to file";
	//print times
	for (int i = 0; i < 10; i++) {
		fp << i << ",";
		for (int j = i*6; j < i*6 + 6; j++) {
			fp << times[j] << ",";
		}
		fp << "\n";
	}
	//print swaps 
	fp<<"\n"<< "Swaps\n";
	fp << "i,1k(unsorted),10k(unsorted),100k(unsorted),1k(sorted),10k(sorted),100k(sorted)\n";
	for (int i = 0; i < 10; i++) {
		fp << i << ",";
		for (int j = i * 6; j < i * 6 + 6; j++) {
			fp << swaps[j] << ",";
		}
		fp << "\n";
	}

	//print comparisons 
	fp << "\n" << "Comparisons\n";
	fp << "i,1k(unsorted),10k(unsorted),100k(unsorted),1k(sorted),10k(sorted),100k(sorted)\n";
	for (int i = 0; i < 10; i++) {
		fp << i << ",";
		for (int j = i * 6; j < i * 6 + 6; j++) {
			fp << comparisons[j] << ",";
		}
		fp << "\n";
	}


	
	fp.close();
	
	return 0;
}