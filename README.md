# test.h

> A minimalistic test harness for c code.

[![npm](https://img.shields.io/npm/v/test.h.svg)](https://www.npmjs.com/package/test.h)
[![Build Status](https://travis-ci.org/ralphtheninja/test.h.svg?branch=master)](https://travis-ci.org/ralphtheninja/test.h)

## Usage

```c
#include "test.h"

BEGIN_TEST();

#define true 1
#define false 0

void test_bools()
{
  ASSERT(1 == true);
  ASSERT(0 == false);
}

void test_ints()
{
  ASSERT(1 == 1);
  ASSERT(0 == 1);
}

int main(void)
{
  TEST(bools);
  TEST(ints);
  TEST_REPORT();
  return TEST_RESULT();
}
```

Output:

```
# Testing bools
[OK] 1 == true
[OK] 0 == false

# Testing ints
[OK] 1 == 1
[FAIL] 0 == 1 (at line 17)

# Result
[OK]    3
[FAIL]  1
```

## Api

Exposes the following set of macros:

### `BEGIN_TEST();`

Call this macro at file scope. This sets up test counters.

### `TEST(function);`

Print out a text and call function `test_function()`.

### `ASSERT(expr);`

Evaluate an expression. Does the following:

* Evaluate `expr`
* If `expr` is `true` print out message and increment counter for successful tests
* If `expr` is `false` print out message (using `__LINE__`) and increment counter for failed tests

### `ABORT(expr);`

Like `ASSERT(expr)` but exits process directly. Useful if you don't want to continue testing for some reason to not end up in infinite loops etc.

### `TEST_REPORT();`

Print out test report.

### `TEST_RESULT();`

Return this in your `main` (or use with `exit()`) for proper exit code.

## License

MIT
