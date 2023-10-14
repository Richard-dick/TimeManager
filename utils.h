#ifndef UTILS_H
#define UTILS_H

// Time to String
#define T2S_default(time) time.toString("yyyy-MM-dd hh:mm:ss")
#define T2S(time, format) time.toString(format)

// Integer to String
#define I2S_default(num) QString::number(num)
// #define I2S(number, format) time.toString(format)


#endif