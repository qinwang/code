/* TA-LIB Copyright (c) 1999-2002, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  MF       Mario Fortier
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *
 */
#include <string.h>
#include "ta_memory.h"


/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */

#ifndef TA_FUNC_H
   #include "ta_func.h"
#endif

#ifndef TA_UTILITY_H
   #include "ta_utility.h"
#endif

int TA_MACD_Lookback( TA_Integer    optInFastPeriod_0, /* From 1 to TA_INTEGER_MAX */
                      TA_Integer    optInSlowPeriod_1, /* From 1 to TA_INTEGER_MAX */
                      TA_Integer    optInSignalPeriod_2 )  /* From 1 to TA_INTEGER_MAX */

/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* The lookback is driven by the signal line output.
    *
    * (must also account for the initial data consume 
    *  by the slow period).
    */
   TA_Integer tempInteger;

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod_1 < optInFastPeriod_0 )
   {
       /* swap */
       tempInteger       = optInSlowPeriod_1;
       optInSlowPeriod_1 = optInFastPeriod_0;
       optInFastPeriod_0 = tempInteger;
   }

   return   TA_EMA_Lookback( optInSlowPeriod_1   )
          + TA_EMA_Lookback( optInSignalPeriod_2 );
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_MACD - Moving Average Convergence/Divergence
 * 
 * Input  = TA_Real
 * Output = TA_Real, TA_Real, TA_Real
 * 
 * Optional Parameters
 * -------------------
 * optInFastPeriod_0:(From 1 to TA_INTEGER_MAX)
 *    Number of period for the fast MA
 * 
 * optInSlowPeriod_1:(From 1 to TA_INTEGER_MAX)
 *    Number of period for the slow MA
 * 
 * optInSignalPeriod_2:(From 1 to TA_INTEGER_MAX)
 *    Smoothing for the signal line (nb of period)
 * 
 * 
 */

TA_RetCode TA_MACD( TA_Integer    startIdx,
                    TA_Integer    endIdx,
                    const TA_Real inReal_0[],
                    TA_Integer    optInFastPeriod_0, /* From 1 to TA_INTEGER_MAX */
                    TA_Integer    optInSlowPeriod_1, /* From 1 to TA_INTEGER_MAX */
                    TA_Integer    optInSignalPeriod_2, /* From 1 to TA_INTEGER_MAX */
                    TA_Integer   *outBegIdx,
                    TA_Integer   *outNbElement,
                    TA_Real       outRealMACD_0[],
                    TA_Real       outRealMACDSignal_1[],
                    TA_Real       outRealMACDHist_2[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   if( !inReal_0 ) return TA_BAD_PARAM;
   /* min/max are checked for optInFastPeriod_0. */
   if( optInFastPeriod_0 == TA_INTEGER_DEFAULT )
      optInFastPeriod_0 = 12;
   else if( (optInFastPeriod_0 < 1) || (optInFastPeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   /* min/max are checked for optInSlowPeriod_1. */
   if( optInSlowPeriod_1 == TA_INTEGER_DEFAULT )
      optInSlowPeriod_1 = 26;
   else if( (optInSlowPeriod_1 < 1) || (optInSlowPeriod_1 > 2147483647) )
      return TA_BAD_PARAM;

   /* min/max are checked for optInSignalPeriod_2. */
   if( optInSignalPeriod_2 == TA_INTEGER_DEFAULT )
      optInSignalPeriod_2 = 9;
   else if( (optInSignalPeriod_2 < 1) || (optInSignalPeriod_2 > 2147483647) )
      return TA_BAD_PARAM;

   if( outRealMACD_0 == NULL )
      return TA_BAD_PARAM;

   if( outRealMACDSignal_1 == NULL )
      return TA_BAD_PARAM;

   if( outRealMACDHist_2 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */  

   return TA_INT_MACD( startIdx, endIdx,                       
                       inReal_0,
                       optInFastPeriod_0,
                       optInSlowPeriod_1,
                       optInSignalPeriod_2,
                       outBegIdx,
                       outNbElement,
                       outRealMACD_0,
                       outRealMACDSignal_1,
                       outRealMACDHist_2 );
}

TA_RetCode TA_INT_MACD( TA_Integer    startIdx,
                        TA_Integer    endIdx,
                        const TA_Real inReal_0[],
                        TA_Integer    optInFastPeriod_0, /* From 1 to 200, 0 is fix 12 */
                        TA_Integer    optInSlowPeriod_1, /* From 1 to 200, 0 is fix 26 */
                        TA_Integer    optInSignalPeriod_2, /* From 1 to 200 */
                        TA_Integer   *outBegIdx,
                        TA_Integer   *outNbElement,
                        TA_Real       outRealMACD_0[],
                        TA_Real       outRealMACDSignal_1[],
                        TA_Real       outRealMACDHist_2[] )
{
   TA_Real *slowEMABuffer, *fastEMABuffer;
   TA_Real k1, k2;
   TA_RetCode retCode;
   TA_Integer tempInteger, outBegIdx1, outNbElement1;
   TA_Integer outBegIdx2, outNbElement2;
   TA_Integer lookbackTotal, lookbackSignal;
   int i;

   /* !!! A lot of speed optimization could be done
    * !!! with this function. 
    * !!!
    * !!! A better approach would be to use TA_INT_EMA
    * !!! just to get the seeding values for the
    * !!! fast and slow EMA. Then process the difference
    * !!! in an allocated buffer until enough data is
    * !!! available for the first signal value.
    * !!! From that point all the processing can
    * !!! be done in a tight loop.
    * !!!
    * !!! That approach will have the following
    * !!! advantage:
    * !!!   1) One mem allocation needed instead of two.
    * !!!   2) The mem allocation size will be only the
    * !!!      signal lookback period instead of the 
    * !!!      whole range of data.
    * !!!   3) Processing will be done in a tight loop.
    * !!!      allowing to avoid a lot of memory store-load
    * !!!      operation.
    * !!!   4) The memcpy at the end will be eliminated!
    * !!!
    * !!! If only I had time....
    */

   /* Catch special case for fix 26/12 MACD. */
   if( optInSlowPeriod_1 != 0 )
      k1 = PER_TO_K(optInSlowPeriod_1);
   else
   {
      optInSlowPeriod_1 = 26;
      k1 = (TA_Real)0.075; /* Fix 26 */
   }

   if( optInFastPeriod_0 != 0 )
      k2 = PER_TO_K(optInFastPeriod_0);
   else
   {
      optInFastPeriod_0 = 12;
      k2 = (TA_Real)0.15; /* Fix 12 */
   }

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod_1 < optInFastPeriod_0 )
   {
       /* swap */
       tempInteger       = optInSlowPeriod_1;
       optInSlowPeriod_1 = optInFastPeriod_0;
       optInFastPeriod_0 = tempInteger;
   }

   lookbackSignal = TA_EMA_Lookback( optInSignalPeriod_2 ); 

   /* Move up the start index if there is not
    * enough initial data.
    */
   lookbackTotal =  lookbackSignal;
   lookbackTotal += TA_EMA_Lookback( optInSlowPeriod_1 );

   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   /* Allocate intermediate buffer for fast/slow EMA. */
   tempInteger = (endIdx-startIdx)+1+lookbackSignal;
   fastEMABuffer = TA_Malloc( tempInteger * sizeof( TA_Real ) );
   if( !fastEMABuffer )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_ALLOC_ERR;
   }

   slowEMABuffer = TA_Malloc( tempInteger * sizeof( TA_Real ) );
   if( !slowEMABuffer )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      TA_Free(  fastEMABuffer );
      return TA_ALLOC_ERR;
   }

   /* Calculate the slow EMA. 
    *
    * Move back the startIdx to get enough data
    * for the signal period. That way, once the
    * signal calculation is done, all the output
    * will start at the requested 'startIdx'.
    */
   tempInteger = startIdx-lookbackSignal;
   retCode = TA_INT_EMA( tempInteger, endIdx,
                         inReal_0, optInSlowPeriod_1, k1,
                         &outBegIdx1, &outNbElement1, slowEMABuffer );

   if( retCode != TA_SUCCESS )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      TA_Free(  fastEMABuffer );
      TA_Free(  slowEMABuffer );
      return retCode;
   }

   /* Calculate the fast EMA. */
   retCode = TA_INT_EMA( tempInteger, endIdx,
                         inReal_0, optInFastPeriod_0, k2,
                         &outBegIdx2, &outNbElement2, fastEMABuffer );

   if( retCode != TA_SUCCESS )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      TA_Free(  fastEMABuffer );
      TA_Free(  slowEMABuffer );
      return retCode;
   }

   /* Parano tests. Will be removed eventually. */
   if( (outBegIdx1 != tempInteger) || 
       (outBegIdx2 != tempInteger) || 
       (outNbElement1 != outNbElement2) ||
       (outNbElement1 != (endIdx-startIdx)+1+lookbackSignal) )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      TA_Free(  fastEMABuffer );
      TA_Free(  slowEMABuffer );
      return TA_INTERNAL_ERROR(119);
   }

   /* Calculate (fast EMA) - (slow EMA). */
   for( i=0; i < outNbElement1; i++ )
      fastEMABuffer[i] = fastEMABuffer[i] - slowEMABuffer[i];


   /* Copy the result into the output for the caller. */
   memcpy( outRealMACD_0, &fastEMABuffer[lookbackSignal], ((endIdx-startIdx)+1)*sizeof(TA_Real) );

   /* Calculate the signal/trigger line. */
   retCode = TA_INT_EMA( 0, outNbElement1-1,
                         fastEMABuffer, optInSignalPeriod_2, PER_TO_K(optInSignalPeriod_2), 
                         &outBegIdx2, &outNbElement2, outRealMACDSignal_1 );


   TA_Free( fastEMABuffer );
   TA_Free( slowEMABuffer );

   if( retCode != TA_SUCCESS )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return retCode;
   }

   /* Calculate the histogram. */
   for( i=0; i < outNbElement2; i++ )
      outRealMACDHist_2[i] = outRealMACD_0[i]-outRealMACDSignal_1[i];

   /* !!! To be done.
    * !!! Should adjust the histogram for being scale adjusted
    * !!! to the MACD line.
    */

   /* All done! Indicate the output limits and return success. */
   *outBegIdx     = startIdx;
   *outNbElement  = outNbElement2;

   return TA_SUCCESS;
}

