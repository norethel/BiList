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
 * @brief
 * @param _self
 */
void bi_list_ctor(TBiList* const _self);

#ifdef __cplusplus
}
#endif

#endif
/** __BI_LIST_H__ @} */
