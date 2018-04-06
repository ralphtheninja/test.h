#ifndef __test_h__
#define __test_h__

#include <stdio.h>

#define BEGIN_TEST()                      \
  int _failed_count = 0;                  \
  int _success_count = 0;

#define TEST(fn)                               \
  printf("\n# Testing " #fn "\n");             \
  test_##fn();

#define ASSERT(A)                                         \
  if (!(A)) {                                             \
    printf(" [FAIL] " #A " (at line %d)\n", __LINE__);    \
    ++_failed_count;                                      \
  } else {                                                \
    printf(" [OK] " #A "\n");                             \
    ++_success_count;                                     \
  }

#define ABORT(A)                                          \
  if (!(A)) {                                             \
    printf(" [ABORT] " #A " (at line %d)\n", __LINE__);   \
    exit(1);                                              \
  }

#define TEST_REPORT()                                                   \
  printf("\n# Result\n");                                               \
  printf(" [OK] %4d\n", _success_count);                                \
  printf(" [FAIL] %2d\n", _failed_count);                               \

#define TEST_RESULT() _failed_count == 0 ? 0 : 1

#endif // __test_h__
