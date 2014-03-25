#ifndef __BI_LIST_ITERATOR_TEST_H__
#define __BI_LIST_ITERATOR_TEST_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <CUnit/CUnit.h>

int bi_list_iterator_test_suite_init(void);

int bi_list_iterator_test_suite_cleanup(void);

void bi_list_iterator_test_inc_empty(void);

void bi_list_iterator_test_inc_tail(void);

void bi_list_iterator_test_inc(void);

void bi_list_iterator_test_dec_empty(void);

void bi_list_iterator_test_dec_head(void);

void bi_list_iterator_test_dec(void);

void bi_list_iterator_test_rewind_empty(void);

void bi_list_iterator_test_rewind_head(void);

void bi_list_iterator_test_rewind(void);

void bi_list_iterator_test_rrewind_empty(void);

void bi_list_iterator_test_rrewind_tail(void);

void bi_list_iterator_test_rrewind(void);

void bi_list_iterator_test_end(void);

extern CU_TestInfo bi_list_iterator_tests[];

#ifdef __cplusplus
}
#endif

#endif
