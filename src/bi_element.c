#include <bi_element.h>
#include <bi_assert.h>
#include <string.h>

void bi_element_ctor(TBiElement* const _self)
{
	REQUIRE(0 != _self);

	memset(_self, 0, sizeof(TBiElement));
}

void bi_element_cctor(TBiElement* const _self, TBiElement* const _element)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _element);

	memcpy(_self, _element, sizeof(TBiElement));

	ENSURE(0 == memcmp(_self, _element, sizeof(TBiElement)));
}

void bi_element_dtor(TBiElement* const _self)
{
	REQUIRE(0 != _self);

	memset(_self, 0, sizeof(TBiElement));
}

int bi_element_linked(TBiElement* const _self)
{
	REQUIRE(0 != _self);

	return ((0 != _self->prev) && (0 != _self->next));
}

void bi_element_link(TBiElement* const _self, TBiElement* const _element)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != _element);
	REQUIRE(0 != bi_element_linked(_element));

	/* if _element is a tail */
	if (_element == _element->next)
	{
		_element->next = _self;
		_self->next = _self;
		_self->prev = _element;
	}
	else /* _element is somewhere inside the list */
	{
		_element->next->prev = _self;
		_self->next = _element->next;
		_element->next = _self;
		_self->prev = _element;
	}

	ENSURE(0 != bi_element_linked(_element));
	ENSURE(0 != bi_element_linked(_self));
}

void bi_element_link_self(TBiElement* const _self)
{
	REQUIRE(0 != _self);

	_self->prev = _self->next = _self;

	ENSURE(0 != bi_element_linked(_self));
}

void bi_element_unlink(TBiElement* const _self)
{
	REQUIRE(0 != _self);
	REQUIRE(0 != bi_element_linked(_self));

	/* _self is inside a list */
	if (_self != _self->prev && _self != _self->next)
	{
		_self->prev->next = _self->next;
		_self->next->prev = _self->prev;
	}
	/* _self is a tail */
	else if (_self != _self->prev)
	{
		_self->prev->next = _self->prev;
	}
	else /* _self is a head */
	{
		_self->next->prev = _self->next;
	}

	memset(_self, 0, sizeof(TBiElement));

	ENSURE(0 == bi_element_linked(_self));
}
