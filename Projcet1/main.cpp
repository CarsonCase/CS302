#include <iostream>
#include "linkedList.h"
#include "linkedList.cpp"
/*Linked List that just simply stores intergers.*/
int main() {
	linkedList<int> mainList;
	int userInput;
	do {
		std::cout << "Enter a number as a choice. And no there is no error handling so please be gentle ;)" << std::endl;
		std::cout << "1). Add to Stack\n2). Remove One Item From Stack\n3). Print Number Of Items\n4). Print List\n5). Quit" << std::endl;
		std::cin >> userInput;
		switch (userInput) {
		case 1:
			int toAdd;
			std::cout << "What number do you want to add?" << std::endl;
			std::cin >> toAdd;
			mainList.push(toAdd);
			break;
		case 2:
			try {
				mainList.pop();
				std::cout << "Item removed" << std::endl;
			}
			catch (std::string e) {
				std::cout << e << std::endl;
			}
			break;
		case 3:
			std::cout << "Number of Items in List: " << mainList.getSize() << std::endl;
			break;
		case 4:
			std::cout << "List: " << mainList << std::endl;
			break;
		}
		} while (userInput != 5);
	return 0;
}