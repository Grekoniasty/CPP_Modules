# ex01 - Fixed-Point Constructors & Conversions

## Goal

Extend the `Fixed` class from ex00 with:
- A constructor from `int` (integer to fixed-point)
- A constructor from `float` (float to fixed-point)
- Conversion back via `toInt()` and `toFloat()`
- `operator<<` so you can print a `Fixed` directly

## Fixed-Point Arithmetic Recap

With 8 fractional bits (`_fract = 8`), the raw integer stores the real value * 2^8 = 256.

```
real value = raw / 256
raw value  = real * 256
```

## What to implement

### `Fixed(const int n)`
```cpp
_integer = n << _fract;   // same as n * 256
```

### `Fixed(const float f)`
```cpp
_integer = roundf(f * (1 << _fract));   // requires <cmath>
```

### `float toFloat(void) const`
```cpp
return (float)_integer / (1 << _fract);
```

### `int toInt(void) const`
```cpp
return _integer >> _fract;   // truncates toward negative infinity
```

### `operator<<`
```cpp
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
```

---

## Edge Cases (evaluators WILL test these)

### 1. Self-assignment
```cpp
Fixed a(42);
a = a;   // must not corrupt _integer
```
The `if (this != &other)` guard in `operator=` handles this. **Do not remove it.**

### 2. Negative integers
```cpp
Fixed a(-5);   // _integer = -5 << 8 = -1280  (correct in two's complement)
std::cout << a.toInt();   // must print -5
```
Left-shifting a negative signed integer is **undefined behavior in C++98**, but
the subject and most evaluators accept it since the expected output matches.
If you want to be safe: `_integer = (int)((unsigned int)n << _fract);`

### 3. Negative floats
```cpp
Fixed c(-42.42f);
std::cout << c;           // prints -42.4219 (float precision)
std::cout << c.toInt();   // prints -42  (truncates toward -inf, NOT toward 0)
```
`toInt()` uses `>>` which is arithmetic right-shift — it truncates toward negative
infinity. `-42.42` becomes raw `-10859`, and `-10859 >> 8` = `-43`, NOT `-42`.
This is consistent with how the subject defines it, but be aware evaluators may
ask: **"what does toInt() do with negatives?"**

### 4. Zero
```cpp
Fixed z(0);
Fixed zf(0.0f);
std::cout << z;    // 0
std::cout << zf;   // 0
```

### 5. Chain of copies
```cpp
Fixed a(10);
Fixed b(a);    // copy constructor
Fixed c;
c = b;         // copy assignment
// a, b, c must all hold the same value
```

### 6. `operator<<` must NOT print int — it prints float
```cpp
Fixed b(10);
std::cout << b;   // must print "10"   (toFloat returns 10.0f -> prints as "10")
Fixed c(42.42f);
std::cout << c;   // must print "42.4219"  NOT "42"
```
If you accidentally do `out << fixed.toInt()` you fail this case.

### 7. Constructor log messages order
The exact order of constructor/destructor messages matters for the subject test.
Trace through the main manually before submitting.

---

## Expected output

```
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
```

## Build

```bash
make
./Fixed
```
