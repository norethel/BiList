#ifndef __BI_ELEMENT_TEST_H__
#define __BI_ELEMENT_TEST_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <CUnit/CUnit.h>

int bi_element_test_suite_init(void);

int bi_element_test_suite_cleanup(void);

void bi_element_test_linkage_self(void);

void bi_element_test_linkage_head(void);

void bi_element_test_linkage_tail(void);

void bi_element_test_linkage_inside(void);

void bi_element_test_unlink_self_linked(void);

void bi_element_test_unlink_head(void);

void bi_element_test_unlink_tail(void);

void bi_element_test_unlink_inside(void);

extern CU_TestInfo bi_element_tests[];

#ifdef __cplusplus
}
#endif

#endif
