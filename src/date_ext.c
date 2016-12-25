/*  =========================================================================
    date_ext - implementation

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#include "classes.h"


time_t date_to_time (int year, int mon, int day, int hour, int min, int sec) {
    struct tm t = {0};
    t.tm_sec  = sec;
    t.tm_min  = min;
    t.tm_hour = hour;
    t.tm_mday = day;
    t.tm_mon  = mon - 1;
    t.tm_year = year - 1900;
    return mktime(&t);
}


bool date_is_expired (time_t expire_time) {
    return (time(NULL) > expire_time);
}


bool date_is_expired_by_date (int expire_year, int expire_month, int expire_day) {
    return date_is_expired (
            date_to_time (expire_year, expire_month, expire_day, 0, 0, 0));
}
