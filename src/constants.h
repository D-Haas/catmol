#pragma once

#include <stdint.h>

#define TRUE 1
#define FALSE 0

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

#define restrain(v, a, b) (v<a ? a : (v>b ? b : v))

extern f64 atomic_masses[119];
extern f64 atomic_radi[119];
extern i16 atomic_colors_term[110];

u8 atomic_symbol_to_number(char symbol[2]);
