#include "bi_element_test.h"
#include "bi_element.h"
#include "test_macros.h"

CU_TestInfo bi_element_tests[] = {
TEST_ENTRY(bi_element_test_linkage_self),
TEST_ENTRY(bi_element_test_linkage_head),
TEST_ENTRY(bi_element_test_linkage_tail),
TEST_ENTRY(bi_element_test_linkage_inside),
TEST_ENTRY(bi_element_test_unlink_self_linked),
TEST_ENTRY(bi_element_test_unlink_head),
TEST_ENTRY(bi_element_test_unlink_tail),
TEST_ENTRY(bi_element_test_unlink_inside),
CU_TEST_INFO_NULL };

int bi_element_test_suite_init(void)
{
	return CUE_SUCCESS;
}

int bi_element_test_suite_cleanup(void)
{
	return CUE_SUCCESS;
}

void bi_element_test_linkage_self(void)
{
	TBiElement self;

	bi_element_ctor(&self);
	bi_element_link_self(&self);

	/* ensure the self is linked */
	CU_ASSERT_NOT_EQUAL(0, bi_element_linked(&self));
	/* check if self is a successor of self */
	CU_ASSERT_PTR_EQUAL(self.next, &self);
	/* check if self is a predecessor of self */
	CU_ASSERT_PTR_EQUAL(self.prev, &self);
}

void bi_element_test_linkage_head(void)
{
	TBiElement head;
	TBiElement element1;

	bi_element_ctor(&head);
	bi_element_ctor(&element1);

	bi_element_link_self(&head);
	bi_element_link_self(&element1);

	/* link element1 before head; element1 will be new head */
	bi_element_link(&head, &element1);

	/* check if element1 is predecessor of head */
	CU_ASSERT_PTR_EQUAL(head.prev, &element1);
	/* check if head is successor of element1 */
	CU_ASSERT_PTR_EQUAL(element1.next, &head);
	/* check if element1 is a new head */
	CU_ASSERT_PTR_EQUAL(element1.prev, &element1);
	/* check if head is now new tail */
	CU_ASSERT_PTR_EQUAL(head.next, &head);
}

void bi_element_test_linkage_tail(void)
{
	TBiElement element1;
	TBiElement element2;

	bi_element_ctor(&element1);
	bi_element_ctor(&element2);

	bi_element_link_self(&element2);

	bi_element_link(&element1, &element2);

	/* check if element1 is successor of element2 */
	CU_ASSERT_PTR_EQUAL(element2.next, &element1);
	/* check if element2 is predecessor of element1 */
	CU_ASSERT_PTR_EQUAL(element1.prev, &element2);
	/* check if element2 is still the head */
	CU_ASSERT_PTR_EQUAL(element2.prev, &element2);
	/* check if element1 is now new tail */
	CU_ASSERT_PTR_EQUAL(element1.next, &element1);
}

void bi_element_test_linkage_inside(void)
{
	TBiElement element1;
	TBiElement element2;
	TBiElement element3;

	bi_element_ctor(&element1);
	bi_element_ctor(&element2);
	bi_element_ctor(&element3);

	/* prepare head */
	element1.prev = element1.next = &element1;

	/* prepare tail */
	bi_element_link(&element3, &element1);

	/* put element2 between element1 and element3 */
	bi_element_link(&element2, &element1);

	/* check if element1 is still a head */
	CU_ASSERT_PTR_EQUAL(element1.prev, &element1);
	/* check if element3 is still a tail */
	CU_ASSERT_PTR_EQUAL(element3.next, &element3);
	/* check if element2 is successor of element1 */
	CU_ASSERT_PTR_EQUAL(element1.next, &element2);
	/* check if element2 is predecessor of element3 */
	CU_ASSERT_PTR_EQUAL(element3.prev, &element2);
}

void bi_element_test_unlink_self_linked(void)
{
	TBiElement head;

	bi_element_ctor(&head);

	bi_element_link_self(&head);

	bi_element_unlink(&head);

	CU_ASSERT_EQUAL(0, bi_element_linked(&head));
}

void bi_element_test_unlink_head(void)
{
	TBiElement head;
	TBiElement tail;

	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_element_link_self(&head);
	bi_element_link(&tail, &head);

	bi_element_unlink(&head);

	/* ensure the head is unlinked */
	CU_ASSERT_EQUAL(0, bi_element_linked(&head));
	/* ensure the tail is still linked */
	CU_ASSERT_NOT_EQUAL(0, bi_element_linked(&tail));
	/* check if the tail is a new head */
	CU_ASSERT_PTR_EQUAL(tail.prev, &tail);
	/* check if the tail is still a tail */
	CU_ASSERT_PTR_EQUAL(tail.next, &tail);
}

void bi_element_test_unlink_tail(void)
{
	TBiElement head;
	TBiElement tail;

	bi_element_ctor(&head);
	bi_element_ctor(&tail);

	bi_element_link_self(&head);
	bi_element_link(&tail, &head);

	bi_element_unlink(&tail);

	/* ensure the tail is unlinked */
	CU_ASSERT_EQUAL(0, bi_element_linked(&tail));
	/* ensure the head is still linked */
	CU_ASSERT_NOT_EQUAL(0, bi_element_linked(&head));
	/* ensure the head is still a head */
	CU_ASSERT_PTR_EQUAL(head.prev, &head);
	/* ensure the head is a new tail */
	CU_ASSERT_PTR_EQUAL(head.next, &head);
}

void bi_element_test_unlink_inside(void)
{
	TBiElement head;
	TBiElement element;
	TBiElement tail;

	bi_element_ctor(&head);
	bi_element_ctor(&element);
	bi_element_ctor(&tail);

	bi_element_link_self(&head);
	bi_element_link(&element, &head);
	bi_element_link(&tail, &element);

	bi_element_unlink(&element);

	/* ensure the element is unlinked */
	CU_ASSERT_EQUAL(0, bi_element_linked(&element));
	/* check if tail is a new successor of head */
	CU_ASSERT_PTR_EQUAL(head.next, &tail);
	/* check if head is a new predecessor of tail */
	CU_ASSERT_PTR_EQUAL(tail.prev, &head);
	/* ensure the head is still a head */
	CU_ASSERT_PTR_EQUAL(head.prev, &head);
	/* ensure the tail is still a tail */
	CU_ASSERT_PTR_EQUAL(tail.next, &tail);
}
