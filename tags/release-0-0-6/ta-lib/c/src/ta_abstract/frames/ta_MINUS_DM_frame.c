/* DO NOT MODIFY this file.
 * This file is automatically generated by gen_Code.
 *
 * The function define in this file allows to have a consistent
 * framework for calling all the TA function through
 * the TA_CallFunc mechanism.
 *
 * See "ta_abstract.h"
 */

#include "ta_func.h"
#include "ta_frame_priv.h"
#include "ta_frame.h"

/* NEVER CALL directly this function! Use TA_CallFunc. */
 
TA_RetCode TA_MINUS_DM_FramePP( TA_Libc            *libHandle,
                          TA_Integer          startIdx,
                          TA_Integer          endIdx,
                          TA_Integer         *outBegIdx,
                          TA_Integer         *outNbElement,
                          TA_ParamHolderPriv  in[],
                          TA_ParamHolderPriv  optIn[],
                          TA_ParamHolderPriv  out[] )
{
   return TA_MINUS_DM( libHandle,
                 startIdx,
                 endIdx,
                 in[0].p.in.data.inPrice.high, /* inHigh_0 */
                 in[0].p.in.data.inPrice.low, /* inLow_0 */
                 optIn[0].p.optIn.data.optInInteger, /* optInTimePeriod_0 */
                 outBegIdx, 
                 outNbElement, 
                 out[0].p.out.data.outReal /*  outReal_0 */ );
}

/***************
 * End of File *
 ***************/
