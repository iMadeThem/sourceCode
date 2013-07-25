/**
 * ClockAngle.c -- Calculate the angle between hour hand and minute hand at given time.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-25 [Thursday, 206]
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) \
    ({ \
         __typeof__ (a)_a = (a); \
         __typeof__ (b)_b = (b); \
         _a > _b ? _a : _b; \
     })

#define min(a, b) \
    ({ \
         __typeof__ (a)_a = (a); \
         __typeof__ (b)_b = (b); \
         _a < _b ? _a : _b; \
     })

/**
 * hour:   0~23
 * minute: 0~59
 * return: -1.0 on error or else the angle between hour and minute hand
 */
double ClockAngle(int hour, int minute)
{
    if(hour > 23 || hour < 0 || minute > 59 || minute < 0)
        return -1.0;
    int _hour = hour > 12 ? (hour - 12) : hour;

    double hAngle = 0.5 * (_hour * 60 + minute);
    double mAngle = 6 * minute;
    double angle = fabs(hAngle - mAngle);
    angle = min(angle, 360 - angle);
    return angle;
}

int main(int argc, char* argv[])
{
    char q;
    int h, m;

    while(1) {
        printf("  Hour(0~23): ");
        scanf("%d", &h);
        printf("Minute(0~59): ");
        scanf("%d", &m);
        double result = ClockAngle(h, m);
        if(result > -1.0) {
            printf("ClockAngle for %02d:%02d is: %f\n", h, m, result);
        } else {
            printf("Input a corret time and try again.\n");
        }

        printf("Press \"Q\" or \"q\" to quit.\n");
        scanf("%c", &q);

        if(q == 'q' || q == 'Q')
            break;
    }

    return 0;
}
