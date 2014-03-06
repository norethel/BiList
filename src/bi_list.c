#include "bi_list.h"
#include "bi_assert.h"
#include "bi_element.h"
#include <string.h>

void bi_list_ctor(TBiList* const _self)
{
	REQUIRE(0 != _self);

	memset(_self, 0, sizeof(TBiList));

	ENSURE(0 != bi_list_empty(_self));
}

void bi_list_cctor(TBiList* const _self, TBiList* const _list)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _list);

	memcpy(_self, _list, sizeof(TBiList));

	ENSURE(0 == memcmp(_self, _list, sizeof(TBiList)));
}

void bi_list_dtor(TBiList* const _self)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != bi_list_empty(_self));
}

int bi_list_empty(TBiList* const _self)
{
	REQUIRE(0 != _self);

	ENSURE((0 == _self->head) ? (0 == _self->tail) : 1);
	ENSURE((0 != _self->head) ? (0 != _self->tail) : 1);

	return ((0 == _self->head) && (0 == _self->tail));
}

void bi_list_push_back(TBiList* const _self, TBiElement* const _element)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _element);
	REQUIRE(0 == bi_element_linked(_element));

	/* if list is empty */
	if (0 != bi_list_empty(_self))
	{
		/* make element a first element of the list: */
		bi_element_link_self(_element);
		_self->head = _element;
	}
	else /* list already has some elements, so put element as a new tail */
	{
		bi_element_link(_element, _self->tail);
	}

	_self->tail = _element;

	ENSURE(0 != bi_element_linked(_element));
}

TBiElement* bi_list_pop_back(TBiList* const _self)
{
	REQUIRE(0 != _self);

	TBiElement* element = 0;

	/* if list is not empty */
	if (0 == bi_list_empty(_self))
	{
		element = _self->tail;

		/* if it is not the last element in the list */
		if (_self->head != _self->tail)
		{
			_self->tail = element->prev;
		}
		else /* in the list is only one element */
		{
			memset(_self, 0, sizeof(TBiList));

			CHECK(0 != bi_list_empty(_self));
		}

		CHECK(0 != element);

		bi_element_unlink(element);
	}

	ENSURE((0 != element) ? (0 == bi_element_linked(element)) : 1);

	return element;
}

TBiElement* bi_list_back(TBiList* const _self)
{
	REQUIRE(0 != _self);

	return _self->tail;
}

void bi_list_push_front(TBiList* const _self, TBiElement* const _element)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _element);
	REQUIRE(0 == bi_element_linked(_element));

	/* if list is empty */
	if (0 != bi_list_empty(_self))
	{
		/* make element a last element of the list: */
		bi_element_link_self(_element);
		_self->tail = _element;
	}
	else /* list already has some elements, so put element as a new head */
	{
		/* hacking needed here, since element
		 * does not provide linking of linked element */
		_element->prev = _element;
		_element->next = _self->head;
		_self->head->prev = _element;
	}

	_self->head = _element;

	ENSURE(0 != bi_element_linked(_element));
}

TBiElement* bi_list_pop_front(TBiList* const _self)
{
	REQUIRE(0 != _self);

	TBiElement* element = 0;

	/* if list is not empty */
	if (0 == bi_list_empty(_self))
	{
		element = _self->head;

		/* if it is not the last element in the list */
		if (_self->head != _self->tail)
		{
			_self->head = element->next;
		}
		else /* in the list is only one element */
		{
			memset(_self, 0, sizeof(TBiList));

			CHECK(0 != bi_list_empty(_self));
		}

		CHECK(0 != element);

		bi_element_unlink(element);
	}

	ENSURE((0 != element) ? (0 == bi_element_linked(element)) : 1);

	return element;
}

TBiElement* bi_list_front(TBiList* const _self)
{
	REQUIRE(0 != _self);

	return _self->head;
}

size_t bi_list_size(TBiList* const _self)
{
	REQUIRE(0 != _self);

	size_t size = 0;
	TBiElement* cur = 0;

	/* if list is not empty */
	if (0 == bi_list_empty(_self))
	{
		size += 1;

		for (cur = _self->head; cur != cur->next; cur = cur->next)
		{
			size += 1;
		}
	}

	return size;
}

void bi_list_clear(TBiList* const _self)
{
	REQUIRE(0 != _self);

	while (0 != bi_list_pop_back(_self))
		;

	REQUIRE(0 != bi_list_empty(_self));
}

void bi_list_insert(TBiList* const _self, TBiElement* const _pos,
        TBiElement* const _element)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _pos);
	REQUIRE(0 != _element);
	REQUIRE(0 == bi_list_empty(_self));
	REQUIRE(0 != bi_element_linked(_pos));
	REQUIRE(0 == bi_element_linked(_element));

	TBiElement* cur;
	TBiElement* found = 0;

	for (cur = _self->head; cur != cur->next; cur = cur->next)
	{
		if (_pos == cur)
		{
			found = cur;
			break;
		}
	}

	/* check also tail */
	if (0 == found && _pos == _self->tail)
	{
		found = _self->tail;
		_self->tail = _element;
	}

	REQUIRE(0 != found);

	bi_element_link(_element, _pos);

	ENSURE(0 != bi_element_linked(_element));
}

void bi_list_remove(TBiList* const _self, TBiElement* const _pos)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _pos);
	REQUIRE(0 == bi_list_empty(_self));
	REQUIRE(0 != bi_element_linked(_pos));

	TBiElement* cur;
	TBiElement* found = 0;

	for (cur = _self->head; cur != cur->next; cur = cur->next)
	{
		if (_pos == cur)
		{
			found = cur;
			break;
		}
	}

	/* check also tail */
	if (0 == found && _pos == _self->tail)
	{
		found = _self->tail;
	}

	REQUIRE(0 != found);

	if (_self->head == _self->tail)
	{
		_self->head = _self->tail = 0;
	}
	else if (found == _self->head)
	{
		_self->head = _self->head->next;
	}
	else
	{
		_self->tail = _self->tail->prev;
	}

	bi_element_unlink(_pos);

	ENSURE(0 == bi_element_linked(_pos));
}
