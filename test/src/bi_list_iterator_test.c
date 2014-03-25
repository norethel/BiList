#include "bi_list_iterator_test.h"
#include "bi_list_iterator.h"
#include "bi_list.h"
#include "bi_element.h"
#include "test_macros.h"

CU_TestInfo bi_list_iterator_tests[] = {
TEST_ENTRY(bi_list_iterator_test_inc_empty),
TEST_ENTRY(bi_list_iterator_test_inc_tail),
TEST_ENTRY(bi_list_iterator_test_inc),
TEST_ENTRY(bi_list_iterator_test_dec_empty),
TEST_ENTRY(bi_list_iterator_test_dec_head),
TEST_ENTRY(bi_list_iterator_test_dec),
TEST_ENTRY(bi_list_iterator_test_rewind_empty),
TEST_ENTRY(bi_list_iterator_test_rewind_head),
TEST_ENTRY(bi_list_iterator_test_rewind),
TEST_ENTRY(bi_list_iterator_test_rrewind_empty),
TEST_ENTRY(bi_list_iterator_test_rrewind_tail),
TEST_ENTRY(bi_list_iterator_test_rrewind),
TEST_ENTRY(bi_list_iterator_test_end),
CU_TEST_INFO_NULL };

int bi_list_iterator_test_suite_init(void)
{
	return CUE_SUCCESS;
}

int bi_list_iterator_test_suite_cleanup(void)
{
	return CUE_SUCCESS;
}

void bi_list_iterator_test_inc_empty(void)
{
	TBiList list;
	TBiListIterator iter;

	bi_list_ctor(&list);

	bi_list_iterator_ctor(&iter, &list);

	bi_list_iterator_inc(&iter);

	/* check if current is still 0 */
	CU_ASSERT_PTR_EQUAL(0, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_inc_tail(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement tail;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &tail);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	bi_list_iterator_inc(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&tail, old_current);
	/* check if iterators current is 0 (iterator has reached end) */
	CU_ASSERT_PTR_EQUAL(0, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_inc(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement head;
	TBiElement tail;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	bi_list_iterator_inc(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&head, old_current);
	/* check if iterators current is next element in the list */
	CU_ASSERT_PTR_EQUAL(&tail, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_dec_empty(void)
{
	TBiList list;
	TBiListIterator iter;

	bi_list_ctor(&list);

	bi_list_iterator_ctor(&iter, &list);

	bi_list_iterator_dec(&iter);

	/* check if current is still 0 */
	CU_ASSERT_PTR_EQUAL(0, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_dec_head(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement head;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&head);

	bi_list_push_back(&list, &head);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	bi_list_iterator_dec(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&head, old_current);
	/* check if iterators current is 0 (iterator has reached end) */
	CU_ASSERT_PTR_EQUAL(0, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_dec(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement head;
	TBiElement tail;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	/* a little bit hacking here to move iter to the last element of the list
	 * without using rrewind */
	iter.current = list.tail;

	bi_list_iterator_dec(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&head, old_current);
	/* check if iterators current is previous element in the list */
	CU_ASSERT_PTR_EQUAL(&head, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_rewind_empty(void)
{
	TBiList list;
	TBiListIterator iter;

	bi_list_ctor(&list);

	bi_list_iterator_ctor(&iter, &list);

	bi_list_iterator_rewind(&iter);

	/* check if current is still 0 */
	CU_ASSERT_PTR_EQUAL(0, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_rewind_head(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement head;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&head);

	bi_list_push_back(&list, &head);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	bi_list_iterator_rewind(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&head, old_current);
	/* check if iterators current is head of the list */
	CU_ASSERT_PTR_EQUAL(&head, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_rewind(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement head;
	TBiElement tail;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	/* a little bit hacking here to move iter to the last element of the list
	 * without using rrewind */
	iter.current = list.tail;

	bi_list_iterator_rewind(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&head, old_current);
	/* check if iterators current points to head of the list */
	CU_ASSERT_PTR_EQUAL(&head, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_rrewind_empty(void)
{
	TBiList list;
	TBiListIterator iter;

	bi_list_ctor(&list);

	bi_list_iterator_ctor(&iter, &list);

	bi_list_iterator_rrewind(&iter);

	/* check if current is still 0 */
	CU_ASSERT_PTR_EQUAL(0, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_rrewind_tail(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement tail;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &tail);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	bi_list_iterator_rrewind(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&tail, old_current);
	/* check if iterators current is tail of the list */
	CU_ASSERT_PTR_EQUAL(&tail, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_rrewind(void)
{
	TBiList list;
	TBiListIterator iter;
	TBiElement head;
	TBiElement tail;
	TBiElement* old_current = 0;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	bi_list_iterator_ctor(&iter, &list);

	old_current = bi_list_iterator_deref(&iter);

	bi_list_iterator_rrewind(&iter);

	/* check if constructed iterator points to begin of the list */
	CU_ASSERT_PTR_EQUAL(&head, old_current);
	/* check if iterators current points to tail of the list */
	CU_ASSERT_PTR_EQUAL(&tail, bi_list_iterator_deref(&iter));
}

void bi_list_iterator_test_end(void)
{
	TBiList list;
	TBiElement element;
	TBiListIterator iter;

	bi_list_ctor(&list);
	bi_element_ctor(&element);
	bi_list_push_back(&list, &element);
	bi_list_iterator_ctor(&iter, &list);

	/* check if iterator is not pointing to the end of the iteration */
	CU_ASSERT_EQUAL(0, bi_list_iterator_end(&iter));

	bi_list_iterator_inc(&iter);

	/* check if iterator is pointing to end of the iteration */
	CU_ASSERT_NOT_EQUAL(0, bi_list_iterator_end(&iter));
}
