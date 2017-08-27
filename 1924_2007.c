#include <stdio.h>

int main(){
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char day[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

	int x, y;
	int select_day = 1;
	scanf("%d %d", &x, &y);

	if( !(1 <= x && x <= 12) || !(1 <= y && y <=31))
		return 0;

	// finding a day of first date on the next month
	for(int i = 1; i < x; i++){
		int tmp = month[i - 1] % 7;
		select_day  = (select_day + tmp) % 7; // next month day of the week
	}

	// finding the day in x month
	int tmp  = (y % 7);
	select_day = (select_day + tmp - 1) % 7;

	if(select_day == -1)
		select_day = 6;
	printf("%s\n", day[select_day]);

	return 0;
}

