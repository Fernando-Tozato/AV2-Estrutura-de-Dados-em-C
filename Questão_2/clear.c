#include <stdio.h>
#include <stdlib.h>
#include "clear.h"

// fun��o para limpar o console
void clear () {
	#ifdef __linux__
		system("clear");
	#elif _WIN32
		system("cls");
	#else
	#endif
	printf("\n\n\n");
}
