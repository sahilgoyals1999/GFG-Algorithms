// https://www.geeksforgeeks.org/measure-1-litre-from-two-vessels-infinite-water-supply/
//

#include <iostream>
using namespace std;

// A utility function to get GCD of two numbers
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

class Vessel {
	// A vessel has capacity, and current amount of water in it
	int capacity, current;
public:
	// Constructor: initializes capacity as given, and current as 0
	Vessel(int capacity) {
		this->capacity = capacity;
		current = 0;
	}
	// The main function to fill one litre in this vessel. Capacity of V2
	// must be greater than this vessel and two capacities must be co-prime
	void makeOneLitre(Vessel &V2);
	// Fills vessel with given amount and returns the amount of water transferred to it.
	// If the vessel becomes full, then the vessel is made empty.
	int transfer(int amount);
};

void Vessel:: makeOneLitre(Vessel &V2) {
	// solution exists iff a and b are co-prime
	if (gcd(capacity, V2.capacity) != 1) return;

	while (current != 1) {
		// fill A (smaller vessel)
		if (current == 0) current = capacity;
		cout << "Vessel 1: " << current << "   Vessel 2: " << V2.current << "\n";
		// Transfer water from V1 to V2 and reduce current of V1 by the amount equal to transferred water
		current = current - V2.transfer(current);
	}
	// Finally, there will be 1 litre in vessel 1
	cout << "Vessel 1: " << current << "   Vessel 2: " << V2.current << "\n";
}

int Vessel::transfer(int amount) {
	// If the vessel can accommodate the given amount
	if (current + amount < capacity) {
		current += amount;
		return amount;
	}
	// If the vessel cannot accommodate the given amount, then store the amount of water transferred
	int transferred = capacity - current;
	// Since the vessel becomes full, make the vessel empty so that it can be filled again
	current = 0;
	return transferred;
}

int main() {
	int a = 3, b = 7;  // a must be smaller than b
	// Create two vessels of capacities a and b
	Vessel V1(a), V2(b);
	// Get 1 litre in first vessel
	V1.makeOneLitre(V2);
	return 0;
}