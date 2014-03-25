#ifndef __TEST_MACROS_H__
#define __TEST_MACROS_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
	ETestSuite_bi_element, ETestSuite_End
} ETestSuite;

#define TEST_ENTRY(test) { #test, test}

#define SUITE_ENTRY(suite, tests) \
		{ #suite, (CU_InitializeFunc)suite##_init, (CU_CleanupFunc)suite##_cleanup, tests}

#ifdef __cplusplus
}
#endif

#endif
