#include "bi_list_test.h"
#include "bi_list.h"
#include "bi_element.h"
#include "test_macros.h"

CU_TestInfo bi_list_tests[] = {
TEST_ENTRY(bi_list_test_push_back_to_empty),
TEST_ENTRY(bi_list_test_push_back_next),
TEST_ENTRY(bi_list_test_pop_back_empty),
TEST_ENTRY(bi_list_test_pop_back_last),
TEST_ENTRY(bi_list_test_pop_back_tail),
TEST_ENTRY(bi_list_test_back_empty),
TEST_ENTRY(bi_list_test_back),
TEST_ENTRY(bi_list_test_push_front_to_empty),
TEST_ENTRY(bi_list_test_push_front_next),
TEST_ENTRY(bi_list_test_pop_front_empty),
TEST_ENTRY(bi_list_test_pop_front_last),
TEST_ENTRY(bi_list_test_pop_front_head),
TEST_ENTRY(bi_list_test_front_empty),
TEST_ENTRY(bi_list_test_front),
TEST_ENTRY(bi_list_test_size_empty),
TEST_ENTRY(bi_list_test_size),
TEST_ENTRY(bi_list_test_insert_tail),
TEST_ENTRY(bi_list_test_insert),
TEST_ENTRY(bi_list_test_remove_last),
TEST_ENTRY(bi_list_test_remove_head),
TEST_ENTRY(bi_list_test_remove_tail),
TEST_ENTRY(bi_list_test_remove),
CU_TEST_INFO_NULL };

int bi_list_test_suite_init(void)
{
	return CUE_SUCCESS;
}

int bi_list_test_suite_cleanup(void)
{
	return CUE_SUCCESS;
}

void bi_list_test_push_back_to_empty(void)
{
	TBiList list;
	TBiElement element;

	bi_list_ctor(&list);
	bi_element_ctor(&element);

	bi_list_push_back(&list, &element);

	/* check if list is not empty */
	CU_ASSERT_EQUAL(0, bi_list_empty(&list));
	/* check if element is linked */
	CU_ASSERT_NOT_EQUAL(0, bi_element_linked(&element));
	/* check if element is a new tail of the list */
	CU_ASSERT_PTR_EQUAL(list.tail, &element);
	/* check if on the list is only one element */
	CU_ASSERT_PTR_EQUAL(list.head, list.tail);
}

void bi_list_test_push_back_next(void)
{
	TBiList list;
	TBiElement head;
	TBiElement next;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&next);

	bi_list_push_back(&list, &head);

	TBiElement* oldTail = list.tail;

	bi_list_push_back(&list, &next);

	/* check if list is not empty */
	CU_ASSERT_EQUAL(0, bi_list_empty(&list));
	/* check if next is a new tail of the list */
	CU_ASSERT_PTR_EQUAL(&next, list.tail);
	/* check if on the list are more than one element */
	CU_ASSERT_PTR_NOT_EQUAL(list.head, list.tail);
	/* check if oldTail is the predecessor of next */
	CU_ASSERT_PTR_EQUAL(oldTail, next.prev);
	/* check if next is a successor of the oldTail */
	CU_ASSERT_PTR_EQUAL(&next, oldTail->next);
}

void bi_list_test_pop_back_empty(void)
{
	TBiList list;
	TBiElement* back;

	bi_list_ctor(&list);

	back = bi_list_pop_back(&list);

	CU_ASSERT_PTR_EQUAL(0, back);
}

void bi_list_test_pop_back_last(void)
{
	TBiList list;
	TBiElement head;

	bi_list_ctor(&list);
	bi_element_ctor(&head);

	bi_list_push_back(&list, &head);

	TBiElement* back = bi_list_pop_back(&list);

	/* check if back is not 0 */
	CU_ASSERT_PTR_NOT_EQUAL(0, back);
	/* check if list is empty */
	CU_ASSERT_NOT_EQUAL(0, bi_list_empty(&list));
	/* check if back points to head */
	CU_ASSERT_PTR_EQUAL(back, &head);
}

void bi_list_test_pop_back_tail(void)
{
	TBiList list;
	TBiElement head;
	TBiElement tail;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	TBiElement* old_tail = list.tail;
	TBiElement* old_tail_prev = old_tail->prev;

	TBiElement* back = bi_list_pop_back(&list);

	/* check if back is not 0 */
	CU_ASSERT_PTR_NOT_EQUAL(0, back);
	/* check if back is the old_tail */
	CU_ASSERT_PTR_EQUAL(back, old_tail);
	/* check if new tail is the predecessor of the old_tail */
	CU_ASSERT_PTR_EQUAL(old_tail_prev, list.tail);
}

void bi_list_test_back_empty(void)
{
	TBiList list;

	bi_list_ctor(&list);

	TBiElement* back = bi_list_back(&list);

	/* check if back is 0 */
	CU_ASSERT_PTR_EQUAL(0, back);
	/* check if list is empty */
	CU_ASSERT_NOT_EQUAL(0, bi_list_empty(&list));
}

void bi_list_test_back(void)
{
	TBiList list;
	TBiElement head;

	bi_list_ctor(&list);
	bi_element_ctor(&head);

	bi_list_push_back(&list, &head);

	TBiElement* back = bi_list_back(&list);

	/* check if list is not empty */
	CU_ASSERT_EQUAL(0, bi_list_empty(&list));
	/* check if back points to list tail */
	CU_ASSERT_PTR_EQUAL(back, list.tail);
}

void bi_list_test_push_front_to_empty(void)
{
	TBiList list;
	TBiElement element;

	bi_list_ctor(&list);
	bi_element_ctor(&element);

	bi_list_push_front(&list, &element);

	/* check if list is not empty */
	CU_ASSERT_EQUAL(0, bi_list_empty(&list));
	/* check if element is linked */
	CU_ASSERT_NOT_EQUAL(0, bi_element_linked(&element));
	/* check if element is a new head of the list */
	CU_ASSERT_PTR_EQUAL(list.head, &element);
	/* check if on the list is only one element */
	CU_ASSERT_PTR_EQUAL(list.head, list.tail);
}

void bi_list_test_push_front_next(void)
{
	TBiList list;
	TBiElement head;
	TBiElement next;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&next);

	bi_list_push_front(&list, &head);

	TBiElement* old_head = list.head;

	bi_list_push_front(&list, &next);

	/* check if list is not empty */
	CU_ASSERT_EQUAL(0, bi_list_empty(&list));
	/* check if next is a new head of the list */
	CU_ASSERT_PTR_EQUAL(&next, list.head);
	/* check if on the list are more than one element */
	CU_ASSERT_PTR_NOT_EQUAL(list.head, list.tail);
	/* check if old_head is the successor of next */
	CU_ASSERT_PTR_EQUAL(old_head, next.next);
	/* check if next is a predecessor of the old_head */
	CU_ASSERT_PTR_EQUAL(&next, old_head->prev);
}

void bi_list_test_pop_front_empty(void)
{
	TBiList list;
	TBiElement* front;

	bi_list_ctor(&list);

	front = bi_list_pop_front(&list);

	CU_ASSERT_PTR_EQUAL(0, front);
}

void bi_list_test_pop_front_last(void)
{
	TBiList list;
	TBiElement head;

	bi_list_ctor(&list);
	bi_element_ctor(&head);

	bi_list_push_front(&list, &head);

	TBiElement* front = bi_list_pop_front(&list);

	/* check if front is not 0 */
	CU_ASSERT_PTR_NOT_EQUAL(0, front);
	/* check if list is empty */
	CU_ASSERT_NOT_EQUAL(0, bi_list_empty(&list));
	/* check if front points to head */
	CU_ASSERT_PTR_EQUAL(front, &head);
}

void bi_list_test_pop_front_head(void)
{
	TBiList list;
	TBiElement head;
	TBiElement tail;

	bi_list_ctor(&list);
	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_front(&list, &head);
	bi_list_push_front(&list, &tail);

	TBiElement* old_head = list.head;
	TBiElement* old_head_next = old_head->next;

	TBiElement* front = bi_list_pop_front(&list);

	/* check if front is not 0 */
	CU_ASSERT_PTR_NOT_EQUAL(0, front);
	/* check if front is the old_head */
	CU_ASSERT_PTR_EQUAL(front, old_head);
	/* check if new head is the successor of the old_head */
	CU_ASSERT_PTR_EQUAL(old_head_next, list.head);
}

void bi_list_test_front_empty(void)
{
	TBiList list;

	bi_list_ctor(&list);

	TBiElement* front = bi_list_front(&list);

	/* check if front is 0 */
	CU_ASSERT_PTR_EQUAL(0, front);
	/* check if list is empty */
	CU_ASSERT_NOT_EQUAL(0, bi_list_empty(&list));
}

void bi_list_test_front(void)
{
	TBiList list;
	TBiElement head;

	bi_list_ctor(&list);
	bi_element_ctor(&head);

	bi_list_push_front(&list, &head);

	TBiElement* front = bi_list_front(&list);

	/* check if list is not empty */
	CU_ASSERT_EQUAL(0, bi_list_empty(&list));
	/* check if front points to list head */
	CU_ASSERT_PTR_EQUAL(front, list.head);
}

void bi_list_test_size_empty(void)
{
	TBiList list;

	bi_list_ctor(&list);

	size_t size = bi_list_size(&list);

	/* check if size is 0 for empty list */
	CU_ASSERT_EQUAL(0, size);
}

void bi_list_test_size(void)
{
	const size_t NUM_OF_ELEMENTS = 3;

	TBiList list;
	TBiElement elements[NUM_OF_ELEMENTS];

	bi_list_ctor(&list);

	size_t i = 0;

	while (i < NUM_OF_ELEMENTS)
	{
		bi_element_ctor(&elements[i]);
		bi_list_push_back(&list, &elements[i]);

		++i;
	}

	size_t size = bi_list_size(&list);

	/* check if size is equal to number of list elements */
	CU_ASSERT_EQUAL(NUM_OF_ELEMENTS, size);
}

void bi_list_test_insert_tail(void)
{
	TBiList list;
	TBiElement head;
	TBiElement element;

	bi_list_ctor(&list);

	bi_element_ctor(&head);
	bi_element_ctor(&element);
	bi_list_push_back(&list, &head);

	bi_list_insert(&list, &head, &element);

	/* check if element is a new tail of the list */
	CU_ASSERT_PTR_EQUAL(list.tail, &element);
	/* check if element is successor of the head */
	CU_ASSERT_PTR_EQUAL(head.next, &element);
	/* check if head is predecessor of the element */
	CU_ASSERT_PTR_EQUAL(&head, element.prev);
}

void bi_list_test_insert(void)
{
	TBiList list;
	TBiElement head;
	TBiElement tail;
	TBiElement element;

	bi_list_ctor(&list);

	bi_element_ctor(&head);
	bi_element_ctor(&tail);
	bi_element_ctor(&element);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	bi_list_insert(&list, &head, &element);

	/* check if element is successor of head */
	CU_ASSERT_PTR_EQUAL(head.next, &element);
	/* check if head is predecessor of element */
	CU_ASSERT_PTR_EQUAL(&head, element.prev);
	/* check if element is predecessor of tail */
	CU_ASSERT_PTR_EQUAL(tail.prev, &element);
	/* check if tail is successor of element */
	CU_ASSERT_PTR_EQUAL(&tail, element.next);
}

void bi_list_test_remove_last(void)
{
	TBiList list;
	TBiElement head;

	bi_list_ctor(&list);
	bi_element_ctor(&head);

	bi_list_push_back(&list, &head);

	bi_list_remove(&list, &head);

	/* check if list is empty after last element removal */
	CU_ASSERT_NOT_EQUAL(0, bi_list_empty(&list));
}

void bi_list_test_remove_head(void)
{
	TBiList list;
	TBiElement head;
	TBiElement tail;

	bi_list_ctor(&list);

	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	bi_list_remove(&list, &head);

	/* check if head equals to tail */
	CU_ASSERT_PTR_EQUAL(list.head, list.tail);
	/* check if tail is self linked */
	CU_ASSERT_PTR_EQUAL(tail.prev, &tail);
	CU_ASSERT_PTR_EQUAL(tail.next, &tail);
}

void bi_list_test_remove_tail(void)
{
	TBiList list;
	TBiElement head;
	TBiElement tail;

	bi_list_ctor(&list);

	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &tail);

	bi_list_remove(&list, &tail);

	/* check if head equals to tail */
	CU_ASSERT_PTR_EQUAL(list.head, list.tail);
	/* check if head is a new tail */
	CU_ASSERT_PTR_EQUAL(&head, list.tail);
	/* check if list tail is self linked */
	CU_ASSERT_PTR_EQUAL(list.tail->prev, list.tail);
	CU_ASSERT_PTR_EQUAL(list.tail->next, list.tail);
}

void bi_list_test_remove(void)
{
	TBiList list;

	TBiElement head;
	TBiElement element;
	TBiElement tail;

	bi_list_ctor(&list);

	bi_element_ctor(&head);
	bi_element_ctor(&element);
	bi_element_ctor(&tail);

	bi_list_push_back(&list, &head);
	bi_list_push_back(&list, &element);
	bi_list_push_back(&list, &tail);

	bi_list_remove(&list, &element);

	/* check if head is predecessor of tail */
	CU_ASSERT_PTR_EQUAL(&head, tail.prev);
	/* check if tail is successor of head */
	CU_ASSERT_PTR_EQUAL(&tail, head.next);
}
