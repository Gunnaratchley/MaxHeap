#include <iostream>
#include <string>
#include <vector>

#include "max_heap.h"

int main()
{
	nwacc::heap<int> heap;

	
	// For loop populated randomly and somehow messed up the indicies
	//for (auto index = 1; index < 25; index++) {
	//int r = (rand() % 100) + 1;
	//heap.insert(r);
	//std::cout << r << ", ";
	//}
	
	/* while (!heap.is_empty()) {
	auto max = 0;
	heap.delete_max(max);
	std::cout << max << std::endl;
	}*/

	//When entered manually everything works perfectly
	//My best guess is that to utilize a for loop porperly we must set 
	//up an iterator to work throught the heap.
	heap.insert(22);
	heap.insert(81);
	heap.insert(4);
	heap.insert(117);
	heap.insert(777);
	heap.insert(125);
	heap.insert(420);
	heap.insert(30);
	heap.insert(327);
	heap.insert(49);
	heap.insert(18);
	heap.insert(624);
	heap.insert(3);
	heap.insert(32);
	heap.insert(41);
	heap.insert(879);
	heap.insert(1);
	heap.insert(92);
	heap.insert(79);
	heap.insert(65);
	heap.insert(51);
	heap.insert(99);
	heap.insert(02);
	heap.insert(58);
	heap.insert(23);

	std::cout << heap.find_max() << std::endl;
	std::cout << std::endl;

	while (!heap.is_empty()) {
		auto max = 0;
		heap.delete_max(max);
		std::cout << max << std::endl;
	}


	return 0;
}