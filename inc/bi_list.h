/**
 * @file bi_list.h
 *
 * @date Feb 28, 2014
 * @author norethel
 *
 * @{
 */

#ifndef __BI_LIST_H__
#define __BI_LIST_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** forward declaration of TBiElement */
typedef struct SBiElement TBiElement;

/**
 * Bidirectional intrusive list structure
 */
struct SBiList
{
TBiElement* head; ///< head of the list
TBiElement* tail; ///< tail of the list
};

/** typedef for SBiList structure */
typedef struct SBiList TBiList;

/**
 * @brief constructs empty list
 * @pre 0 != _self
 * @post list is empty
 * @param _self pointer to list
 */
void bi_list_ctor(TBiList* const _self);

/**
 * @brief constructs list from another one
 * @b WARNING: it is in user responsibility to release @b _list
 * otherwise it is undefined behaviour when two lists are pointing
 * to the same sequence of the elements.
 * @pre 0 != _self
 * @pre 0 != _list
 * @post _self equals to list
 * @param _self pointer to list to be constructed
 * @param _list pointer to list from which @b _self needs to be constructed
 */
void bi_list_cctor(TBiList* const _self, TBiList* const _list);

/**
 * @brief destructs list
 * @pre 0 != _self
 * @pre list should be empty
 * @param _self pointer to list structure
 */
void bi_list_dtor(TBiList* const _self);

/**
 * @brief checks if list is empty
 * @pre 0 != _self
 * @param _self pointer to list to be checked
 * @return if list is empty the return value is greater than 0 (usually 1),
 * otherwise 0
 */
int bi_list_empty(TBiList* const _self);

/**
 * @brief inserts element at the end of the list
 * @pre 0 != _self
 * @pre 0 != _element
 * @pre element is not linked
 * @post element is linked
 * @post element is a new tail of the list
 * @post if element is a first element of the list, it is also its head
 * @param _self pointer to list
 * @param _element pointer to element to be added to list
 */
void bi_list_push_back(TBiList* const _self, TBiElement* const _element);

/**
 * @brief takes off the last element from the list
 * @pre 0 != _self
 * @post tail->prev is a new tail of the list
 * @param _self pointer to list
 * @return if list is not empty, a pointer to taken element is returned,
 * otherwise 0
 */
TBiElement* bi_list_pop_back(TBiList* const _self);

/**
 * @brief returns pointer to last element in the list
 * @pre 0 != _self
 * @param _self pointer to list
 * @return if list is not empty, a pointer to the last element in the list
 * is returned, otherwise 0
 */
TBiElement* bi_list_back(TBiList* const _self);

#ifdef __cplusplus
}
#endif

#endif
/** __BI_LIST_H__ @} */
