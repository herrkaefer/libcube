/*  =========================================================================
    date_ext - extension of date & time types

    Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
    =========================================================================
*/

#ifndef __DATE_EXT_H_INCLUDED__
#define __DATE_EXT_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#define TIME_NONE (time_t)(0)

// Check whether current date expires
bool date_is_expired (time_t expire_time);

// Check whether current date expires
bool date_is_expired_by_date (int expire_year, int expire_month, int expire_day);

// Convert date to time_t
time_t date_to_time (int year, int mon, int day, int hour, int min, int sec);

#ifdef __cplusplus
}
#endif

#endif
