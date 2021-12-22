#include<ctime>
#include <stdlib.h>
#include "random.h"


crandoms::crandoms() {
	for (int i = 0; i < 10; i++) {
		ord0[i] = 0;
		ord1[i] = 100;
		ord2[i] = 100;
	}
}

void crandoms::randomize() {
	
	int k;
	for (int i = 0; i < 10; i++) {
		int flag = 0;
		while (flag != 1) {
			k = (time(0) + rand()) % 10;
			if (ord0[k] != 100) {
				ord1[k] = i;
				ord0[k] = 100;
				flag = 1;
			}
		}
	}
	for (int j = 0; j < 10; j++) {
		ord0[j] = 0;
		ord2[j] = 100;
	}
	for (int i = 0; i < 10; i++) {
		int flag = 0;
		while (flag != 1) {
			k = (time(0) + rand()) % 10;
			if (ord0[k] != 100) {
				ord2[k] = i;
				ord0[k] = 100;
				flag = 1;
			}
		}
	}
}
int crandoms::get1(int i) {
	return ord1[i];
}
int crandoms::get2(int i) {
	return ord2[i];
}