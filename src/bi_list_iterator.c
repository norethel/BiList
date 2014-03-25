#include "bi_list_iterator.h"
#include "bi_assert.h"
#include "bi_list.h"
#include "bi_element.h"
#include <string.h>

void bi_list_iterator_ctor(TBiListIterator* const _self, TBiList* const _list)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _list);

	_self->list = _list;
	_self->current = _list->head;
}

void bi_list_iterator_cctor(TBiListIterator* const _self,
        TBiListIterator* const _iter)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _iter);

	memcpy(_self, _iter, sizeof(TBiListIterator));

	ENSURE(0 == memcmp(_self, _iter, sizeof(TBiListIterator)));
}

void bi_list_iterator_dtor(TBiListIterator* const _self)
{
	REQUIRE(0 != _self);

	memset(_self, 0, sizeof(TBiListIterator));
}

void bi_list_iterator_inc(TBiListIterator* const _self)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _self->list);

	if (0 != _self->current && _self->current != _self->list->tail)
	{
		_self->current = _self->current->next;
	}
	else if (0 != _self->current)
	{
		_self->current = 0;
	}
}

void bi_list_iterator_dec(TBiListIterator* const _self)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _self->list);

	if (0 != _self->current && _self->current != _self->list->head)
	{
		_self->current = _self->current->prev;
	}
	else if (0 != _self->current)
	{
		_self->current = 0;
	}
}

void bi_list_iterator_rewind(TBiListIterator* const _self)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _self->list);

	_self->current = _self->list->head;
}

void bi_list_iterator_rrewind(TBiListIterator* const _self)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _self->list);

	_self->current = _self->list->tail;
}

TBiElement* bi_list_iterator_deref(TBiListIterator* const _self)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _self->list);

	return _self->current;
}
