/**
 * Time.h -- A simple ctime wrapper class.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-06 [Tuesday, 218]
 */

#ifndef _HEADER_TIME_H_
#define _HEADER_TIME_H_

#include <ctime>
#include <cstring>

class Time {
    std::time_t t;
    std::tm local;
    char asciiRep[26];
    unsigned char lflag, aflag;

    void updateLocal() {
        if(!lflag) {
            local = *std::localtime(&t);
            lflag++;
        }
    }

    void updateAscii() {
        if(!aflag) {
            updateLocal();
            std::strcpy(asciiRep, std::asctime(&local));
            aflag++;
        }
    }

    public:
        Time() {
            mark();
        }

        void mark() {
            lflag = aflag = 0;
            std::time(&t); // get current time, the same as: t = time(NULL)
        }

        const char* ascii() {
            updateAscii();
            return asciiRep;
        }

        // Difference in seconds:
        int delta(Time* dt) const {
            return int(std::difftime(t, dt->t));
        }

        // Difference in milli-seconds:
        double deltaMilli(Time* dt) const {
            return 1000 * std::difftime(t, dt->t);
        }

        int daylightSavings() {
            updateLocal();
            return local.tm_isdst;
        }

        int dayOfYear() {
            // Since January 1
            updateLocal();
            return local.tm_yday;
        }

        int dayOfWeek() {
            // Since Sunday
            updateLocal();
            return local.tm_wday;
        }

        int since1900() {
            // Years since 1900
            updateLocal();
            return local.tm_year;
        }

        int month() {
            // Since January
            updateLocal();
            return local.tm_mon;
        }

        int dayOfMonth() {
            updateLocal();
            return local.tm_mday;
        }

        int hour() {
            // Since midnight, 24-hour clock
            updateLocal();
            return local.tm_hour;
        }

        int minute() {
            updateLocal();
            return local.tm_min;
        }

        int second() {
            updateLocal();
            return local.tm_sec;
        }
};

#endif /* ~_HEADER_TIME_H_ */
