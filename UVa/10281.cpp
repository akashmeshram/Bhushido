//UVa 10281 - Average Speed
#include<bits/stdc++.h>
using namespace std;

int main() {
	char stamp[20];
	double hh, mm, ss, speed = 0;
	double crrtime = 0, ptime = 0, dist = 0;
	while(gets(stamp)) {		
		sscanf(stamp, "%lf:%lf:%lf", &hh, &mm, &ss);
		crrtime = hh + mm/60.0 + ss/3600.0 ;
		dist += (crrtime - ptime)*speed;
		if(stamp[8] == '\0') {
			sscanf(stamp, "%lf:%lf:%lf", &hh, &mm, &ss);
			printf("%s %.2lf km \n", stamp, dist);
		} else {
			sscanf(stamp + 8, "%lf", &speed);
		}
		ptime = crrtime;
	}
	return 0;
}
