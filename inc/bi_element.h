/**
 * @file bi_element.h
 *
 * @date Feb 20, 2014
 * @author norethel
 *
 * @{
 */

#ifndef __BI_ELEMENT_H__
#define __BI_ELEMENT_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** typedef for SBiElement structure */
typedef struct SBiElement TBiElement;

/** Single list element structure */
struct SBiElement
{
TBiElement* prev; ///< previous list element
TBiElement* next; ///< next list element
};

/**
 * @brief constructs list element
 * @pre 0 != _self
 * @param _self pointer to list element to be constructed
 */
void bi_element_ctor(TBiElement* const _self);

/**
 * @brief constructs list element from another one
 * @pre 0 != _self
 * @pre 0 != _element
 * @param _self pointer to list element to be constructed
 * @param _element pointer to list element from which @b _self will be constructed
 */
void bi_element_cctor(TBiElement* const _self, TBiElement* const _element);

/**
 * @brief destructs list element
 * @pre 0 != _self
 * @param _self pointer to list element to be destructed
 */
void bi_element_dtor(TBiElement* const _self);

/**
 * @brief checks if list element is linked
 * @pre 0 != _self
 * @param _self pointer to list element needed to be checked for linkage
 * @return value != 0 if list element is linked (usually 1), otherwise 0
 */
int bi_element_linked(TBiElement* const _self);

/**
 * @brief links @b _self with @b _element with @b _element as preceding one
 * @pre 0 != _self
 * @pre 0 != _element
 * @pre @b _element need to be linked
 * @post _self is linked
 * @post _element is linked
 * @param _self pointer to list element to be linked
 * @param _element pointer to list element with which @b _element will be linked
 */
void bi_element_link(TBiElement* const _self, TBiElement* const _element);

/**
 * @brief links @b _self with @b _self
 * @pre 0 != _self
 * @post _self is linked
 * @param _self pointer to list element to be linked
 */
void bi_element_link_self(TBiElement* const _self);

/**
 * @brief unlinks list element
 * @pre 0 != _self
 * @pre @b _self need to be linked
 * @param _self pointer to list element to be unlinked
 */
void bi_element_unlink(TBiElement* const _self);

#ifdef __cplusplus
}
#endif

#endif
/** __BI_ELEMENT_H__ @} */
