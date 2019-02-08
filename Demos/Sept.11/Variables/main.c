/* Variables demo to assist in learning the variable types in C Programming. The standard C integer variables are not
 * used so students understand programming Arduinos.
 * Created by: Andrew Parisee
 * Date: September 1, 2018
 * Time: 1:34PM*/
#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <float.h>

int main() {

    printf("Variables:\n");
    // integers

    // 8-bit

    /*signed*/
    char c8 = INT8_MAX;
    signed char sc8 = INT8_MIN;
    int8_t i8 = INT8_MAX;
    bool b8 = true;
    _Bool _b8 = false;

    /*unsigned*/
    unsigned char uc8 = UINT8_MAX;
    uint8_t ui8 = UINT8_MAX;

    printf("8-bit: c8=%hhi, sc8=%hhi, uc8=%hhu, _b8=%i, b8 =%i, i8=%"PRIi8
           ", ui8=%"PRIu8"\n", c8, sc8, uc8, _b8, b8, i8, ui8);

    // 16-bit
    // (signed) short, (signed) short (int), unsigned short, unsigned short (int) \Words in brackets are not needed
    int16_t i16min = INT16_MIN;
    int16_t i16max = INT16_MAX;
    uint16_t ui16 = UINT16_MAX;

    printf("16-bit: %i, %i, %i\n", i16min, i16max, ui16);

    //32-bit
    //int, signed, unsigned, (signed) long (int), unsigned long (int) \Words in brackets are not needed

    int32_t i32tmin = INT32_MIN;
    int32_t i32tmax = INT32_MAX;
    uint32_t ui32t = UINT32_MAX;

    printf("32-bit: %i, %i, %u\n", i32tmin, i32tmax, ui32t);

    //64-bit
    //(signed) long long, unsigned long long \Words in brackets are not needed

    int64_t i64tmin = INT64_MIN;
    int64_t i64tmax = INT64_MAX;
    uint64_t ui64t = UINT64_MAX;

    printf("64-bit: %lli, %lli, %llu\n", i64tmin, i64tmax, ui64t);

    // floating point

    // 32-bit (1-sign, 8-exponents, 23-mantissa)
    float f32 = 32.0f;  // If the f is not there it converts from a float into a double
    float fmax = FLT_MAX;

    // 64-bit (1-sign, 11-exponent, 52-mantissa)
    double d64 = 64.0;
    double dmax = DBL_MAX;

    // 80-bit (1-sign, 15-exponents, 64-mantissa)
    long double ld80 = 80.0;
    long double ldmax = LDBL_MAX;
    // __float80 f80 = 80.0;

    //128-bit (1-sign, 15-exponents, 112-mantissa)
    // __float128 f128 = 128q;


    printf("Float: f32=%f, d64=%lf, ld80=%Lf\n", f32, d64, ld80)   ;

    // Characters and Strings

    char ch = 'a';
    char str[32] = "Hello!";

    printf("ch=%c, str=%s\n", ch, str);

    return 0;
}