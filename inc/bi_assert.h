/**
 * @file bi_assert.h
 *
 * @date Feb 21, 2014
 * @author norethel
 *
 * @{
 */

#ifndef __BI_ASSERT_H__
#define __BI_ASSERT_H__

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define REQUIRE(expr) \
	if (0 == (expr)) \
	{ \
		printf("%s:%d : REQUIRE: assertion failed: %s", __FILE__, __LINE__, #expr); \
		exit(-1); \
	}

#define CHECK(expr) \
	if (0 == (expr)) \
	{ \
		printf("%s:%d : CHECK: assertion failed: %s", __FILE__, __LINE__, #expr); \
		exit(-1); \
	}

#define ENSURE(expr) \
	if (0 == (expr)) \
	{ \
		printf("%s:%d : ENSURE: assertion failed: %s", __FILE__, __LINE__, #expr); \
		exit(-1); \
	}

#ifdef __cplusplus
}
#endif

#endif
/** __BI_ASSERT_H__ @} */
