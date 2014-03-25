/**
 * @file bi_list_iterator.h
 *
 * @date Mar 6, 2014
 * @author norethel
 *
 * @{
 */

#ifndef __BI_LIST_ITERATOR_H__
#define __BI_LIST_ITERATOR_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** forward declaration of TBiList */
typedef struct SBiList TBiList;

/** forward declaration of TBiElement */
typedef struct SBiElement TBiElement;

/**
 * Iterator structure of bidirectional intrusive list
 */
struct SBiListIterator
{
TBiList* list; ///< list pointer over which iterator is iterating
TBiElement* current; ///< pointer to currently pointed element in the list
};

/** typedef for SBiListIterator structure */
typedef struct SBiListIterator TBiListIterator;

/**
 * @brief constructs iterator from specified list
 * note: iterator is set to head of the list by default
 * if list is empty, the current element is 0
 * @pre 0 != _self
 * @pre 0 != _list
 * @post list->head == current
 * @param _self pointer to iterator
 * @param _list pointer to list to be iterated
 */
void bi_list_iterator_ctor(TBiListIterator* const _self, TBiList* const _list);

/**
 * @brief constructs iterator from another one
 * @pre 0 != _self
 * @pre 0 != _iter
 * @post _self equals to _iter
 * @param _self pointer to iterator to be constructed
 * @param _iter pointer to iterator from which _self will be constructed
 */
void bi_list_iterator_cctor(TBiListIterator* const _self,
        TBiListIterator* const _iter);

/**
 * @brief destructs iterator
 * @pre 0 != _self
 * @param _self pointer to iterator
 */
void bi_list_iterator_dtor(TBiListIterator* const _self);

/**
 * @brief moves its pointer forward to next list element
 * note: after last element of the list reached, the next incrementation
 * will set its pointer to 0 (iterator dereferenced)
 * and further incrementation will take no effect;
 * after this point, iterator needs to be rewind or reversely rewind.
 * @pre 0 != _self
 * @pre iterator is initialized with a valid list pointer
 * @param _self pointer to iterator
 */
void bi_list_iterator_inc(TBiListIterator* const _self);

/**
 * @brief moves its pointer backward to previous list element
 * note: after first element of the list reached,
 * the next decrementation will set its pointer to 0
 * (iterator dereferenced) and further decrementation
 * will take no effect; after this point,
 * iterator needs to be reversely rewind or rewind.
 * @pre 0 != _self
 * @pre iterator is initialized with a valid list pointer
 * @param _self pointer to iterator
 */
void bi_list_iterator_dec(TBiListIterator* const _self);

/**
 * @brief sets its pointer to the first element of the list
 * @pre 0 != _self
 * @pre iterator is initialized with a valid list pointer
 * @param _self pointer to iterator
 */
void bi_list_iterator_rewind(TBiListIterator* const _self);

/**
 * @brief sets its pointer to the last element of the list
 * @pre 0 != _self
 * @pre iterator is initialized with a valid list pointer
 * @param _self pointer to iterator
 */
void bi_list_iterator_rrewind(TBiListIterator* const _self);

/**
 * @brief dereferences iterator by returning element at which
 * it currently points
 * @param _self pointer to iterator
 * @pre iterator is initialized with a valid list pointer
 * @return element or 0 if list is empty or iterator reached the iteration end
 */
TBiElement* bi_list_iterator_deref(TBiListIterator* const _self);

/**
 * @brief checks if iterator has reached the end of the list
 * @pre 0 != _self
 * @param _self pointer to iterator
 * @return returns value different from 0 (usually 1)
 * if iterator reached the end of the list, otherwise returns 0
 */
int bi_list_iterator_end(TBiListIterator* const _self);

#ifdef __cplusplus
}
#endif

#endif
/** __BI_LIST_ITERATOR_H__ @} */
