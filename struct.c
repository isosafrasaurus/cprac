/*
 * struct.c
 */

#include "information.h"

struct CharCharInt{
	char c1;
	char c2;
	int i;
};

typedef long long ll;
// Could alternatively do #define long long ll
typedef struct ADate {
	int month;
	int day;
	int year;
} Date;

void create_date2(Date*d, int month, int day, int year){
	d -> month = month;
	d -> day = day;
	d -> year = year;
}

#if 0
int main() {
	struct CharCharInt x;
	x.c1 = 'a'; x.c2 = 'b'; x.i = 0xDEADBEEF;
	show_bytes((byte_pointer) &x, 8);
	// Output:  61 62 c0 7c ef be ad de
	// Here, c0 7c are padding.

	ll i = 100000000001;
	Date d = {2, 4, 2021};
	// Sanity check that i works
	printf("%lld\n", i);

	Date today;
	create_date2(&today, 2, 1, 2024);
	printf("%d %d %d", today.day, today.month, today.year); // different format

	// Enumerated types
	enum Color { RED, WHITE, BLACK, YELLOW };
	enum Color my_color = RED;
}
#endif
