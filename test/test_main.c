#include <CUnit/Basic.h>
#include "bi_element_test.h"
#include "bi_list_test.h"
#include "test_macros.h"

CU_SuiteInfo suites[] = {
SUITE_ENTRY(bi_element_test_suite, bi_element_tests),
SUITE_ENTRY(bi_list_test_suite, bi_list_tests),
CU_SUITE_INFO_NULL };

int main(void)
{
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	if (CUE_SUCCESS != CU_register_suites(suites))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);

	CU_basic_run_tests();

	CU_cleanup_registry();

	return CU_get_error();
}
