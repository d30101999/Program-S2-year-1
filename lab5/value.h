#pragma once
template < typename T, size_t Power >
T ownPower(T element) {
	T multiplier = element;
	if (Power == 0) {
		element = 1;
	}
	else if (Power > 0) {
		for (int i = 0; i < Power - 1; i++) {
			element *= multiplier;
		}
	}
	else {
		for (int i = 0; i < Power - 1; i++) {
			element *= multiplier;
		}
		return 1.0 / element;
	}
	return element;
}
