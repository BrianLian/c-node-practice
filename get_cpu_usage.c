#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	long double a[4], b[4], loadavg;
    FILE *fp;
    char dump[50];

    for( ; ; )
    {
        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
        fclose(fp);
        sleep(1);

        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
        fclose(fp);

        loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
        printf("The current CPU utilization is : %Lf\n",loadavg * 100);
		break;
    }
	return 0;
}


