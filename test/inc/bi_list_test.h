/**
 * @file bi_list_test.h
 *
 * @date Feb 28, 2014
 * @author norethel
 *
 * @{
 */

#ifndef __BI_LIST_TEST_H__
#define __BI_LIST_TEST_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <CUnit/CUnit.h>

int bi_list_test_suite_init(void);

int bi_list_test_suite_cleanup(void);

void bi_list_test_push_back_to_empty(void);

void bi_list_test_push_back_next(void);

void bi_list_test_pop_back_empty(void);

void bi_list_test_pop_back_last(void);

void bi_list_test_pop_back_tail(void);

void bi_list_test_back_empty(void);

void bi_list_test_back(void);

void bi_list_test_push_front_to_empty(void);

void bi_list_test_push_front_next(void);

void bi_list_test_pop_front_empty(void);

void bi_list_test_pop_front_last(void);

void bi_list_test_pop_front_head(void);

void bi_list_test_front_empty(void);

void bi_list_test_front(void);

void bi_list_test_size_empty(void);

void bi_list_test_size(void);

void bi_list_test_insert_tail(void);

void bi_list_test_insert(void);

void bi_list_test_remove_last(void);

void bi_list_test_remove_head(void);

void bi_list_test_remove_tail(void);

void bi_list_test_remove(void);

extern CU_TestInfo bi_list_tests[];

#ifdef __cplusplus
}
#endif

#endif
/** __BI_LIST_TEST_H__ @} */
