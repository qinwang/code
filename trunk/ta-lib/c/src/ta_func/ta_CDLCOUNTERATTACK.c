/* TA-LIB Copyright (c) 1999-2004, Mario Fortier
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
 *  AC       Angelo Ciceri
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  010605 AC   Creation           
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #using <mscorlib.dll>
/* Generated */    #include "Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */    #include "ta_trace.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::CDLCOUNTERATTACK_Lookback( void )
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_CDLCOUNTERATTACK_Lookback( void )
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
    return max( TA_CANDLEAVGPERIOD(TA_Equal), TA_CANDLEAVGPERIOD(TA_BodyLong)
            ) + 1;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CDLCOUNTERATTACK - Counterattack
 * 
 * Input  = Open, High, Low, Close
 * Output = int
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ __value enum Core::TA_RetCode Core::CDLCOUNTERATTACK( int    startIdx,
/* Generated */                                                       int    endIdx,
/* Generated */                                                       double       inOpen __gc [],
/* Generated */                                                       double       inHigh __gc [],
/* Generated */                                                       double       inLow __gc [],
/* Generated */                                                       double       inClose __gc [],
/* Generated */                                                       [OutAttribute]Int32 *outBegIdx,
/* Generated */                                                       [OutAttribute]Int32 *outNbElement,
/* Generated */                                                       int           outInteger __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_CDLCOUNTERATTACK( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                 const double inOpen[],
/* Generated */                                 const double inHigh[],
/* Generated */                                 const double inLow[],
/* Generated */                                 const double inClose[],
/* Generated */                                 int          *outBegIdx,
/* Generated */                                 int          *outNbElement,
/* Generated */                                 int           outInteger[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
    double EqualPeriodTotal, BodyLongPeriodTotal[2];
    int i, outIdx, totIdx, EqualTrailingIdx, BodyLongTrailingIdx, lookbackTotal;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    /* Verify required price component. */
/* Generated */    if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outInteger == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */

   lookbackTotal = TA_CDLCOUNTERATTACK_Lookback();

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   /* Do the calculation using tight loops. */
   /* Add-up the initial period, except for the last value. */
   EqualPeriodTotal = 0;
   EqualTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_Equal);
   BodyLongPeriodTotal[1] = 0;
   BodyLongPeriodTotal[0] = 0;
   BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyLong);

   i = EqualTrailingIdx;
   while( i < startIdx ) {
        EqualPeriodTotal += TA_CANDLERANGE( TA_Equal, i-1 );
        i++;
   }
   i = BodyLongTrailingIdx;
   while( i < startIdx ) {
        BodyLongPeriodTotal[1] += TA_CANDLERANGE( TA_BodyLong, i-1 );
        BodyLongPeriodTotal[0] += TA_CANDLERANGE( TA_BodyLong, i );
        i++;
   }
   i = startIdx;

   /* Proceed with the calculation for the requested range.
    * Must have:
    * - first candle: long black (white)
    * - second candle: long white (black) with close equal to the prior close
    * The meaning of "equal" and "long" is specified with TA_SetCandleSettings
    * outInteger is positive (1 to 100) when bullish or negative (-1 to -100) when bearish;
    * the user should consider that counterattack is significant in a trend, while this function does not consider it
    */
   outIdx = 0;
   do
   {
        if( TA_CANDLECOLOR(i-1) == -TA_CANDLECOLOR(i) &&                                        // opposite candles
            TA_REALBODY(i-1) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[1], i-1 ) &&     // 1st long
            TA_REALBODY(i) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[0], i ) &&         // 2nd long
            inClose[i] <= inClose[i-1] + TA_CANDLEAVERAGE( TA_Equal, EqualPeriodTotal, i-1 ) && // equal closes
            inClose[i] >= inClose[i-1] - TA_CANDLEAVERAGE( TA_Equal, EqualPeriodTotal, i-1 )
          )
            outInteger[outIdx++] = TA_CANDLECOLOR(i) * 100;
        else
            outInteger[outIdx++] = 0;
        /* add the current range and subtract the first range: this is done after the pattern recognition 
         * when avgPeriod is not 0, that means "compare with the previous candles" (it excludes the current candle)
         */
        EqualPeriodTotal += TA_CANDLERANGE( TA_Equal, i-1 ) - TA_CANDLERANGE( TA_Equal, EqualTrailingIdx-1 );
        for (totIdx = 1; totIdx >= 0; --totIdx)
            BodyLongPeriodTotal[totIdx] += TA_CANDLERANGE( TA_BodyLong, i-totIdx ) 
                                         - TA_CANDLERANGE( TA_BodyLong, BodyLongTrailingIdx-totIdx );
        i++;
        EqualTrailingIdx++;
        BodyLongTrailingIdx++;
   } while( i <= endIdx );

   /* All done. Indicate the output limits and return. */
   *outNbElement = outIdx;
   *outBegIdx    = startIdx;

   return TA_SUCCESS;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ __value enum Core::TA_RetCode Core::CDLCOUNTERATTACK( int    startIdx,
/* Generated */                                                       int    endIdx,
/* Generated */                                                       float        inOpen __gc [],
/* Generated */                                                       float        inHigh __gc [],
/* Generated */                                                       float        inLow __gc [],
/* Generated */                                                       float        inClose __gc [],
/* Generated */                                                       [OutAttribute]Int32 *outBegIdx,
/* Generated */                                                       [OutAttribute]Int32 *outNbElement,
/* Generated */                                                       int           outInteger __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CDLCOUNTERATTACK( int    startIdx,
/* Generated */                                   int    endIdx,
/* Generated */                                   const float  inOpen[],
/* Generated */                                   const float  inHigh[],
/* Generated */                                   const float  inLow[],
/* Generated */                                   const float  inClose[],
/* Generated */                                   int          *outBegIdx,
/* Generated */                                   int          *outNbElement,
/* Generated */                                   int           outInteger[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     double EqualPeriodTotal, BodyLongPeriodTotal[2];
/* Generated */     int i, outIdx, totIdx, EqualTrailingIdx, BodyLongTrailingIdx, lookbackTotal;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outInteger == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    lookbackTotal = TA_CDLCOUNTERATTACK_Lookback();
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }
/* Generated */    EqualPeriodTotal = 0;
/* Generated */    EqualTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_Equal);
/* Generated */    BodyLongPeriodTotal[1] = 0;
/* Generated */    BodyLongPeriodTotal[0] = 0;
/* Generated */    BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyLong);
/* Generated */    i = EqualTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         EqualPeriodTotal += TA_CANDLERANGE( TA_Equal, i-1 );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = BodyLongTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         BodyLongPeriodTotal[1] += TA_CANDLERANGE( TA_BodyLong, i-1 );
/* Generated */         BodyLongPeriodTotal[0] += TA_CANDLERANGE( TA_BodyLong, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = startIdx;
/* Generated */    outIdx = 0;
/* Generated */    do
/* Generated */    {
/* Generated */         if( TA_CANDLECOLOR(i-1) == -TA_CANDLECOLOR(i) &&                                        // opposite candles
/* Generated */             TA_REALBODY(i-1) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[1], i-1 ) &&     // 1st long
/* Generated */             TA_REALBODY(i) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[0], i ) &&         // 2nd long
/* Generated */             inClose[i] <= inClose[i-1] + TA_CANDLEAVERAGE( TA_Equal, EqualPeriodTotal, i-1 ) && // equal closes
/* Generated */             inClose[i] >= inClose[i-1] - TA_CANDLEAVERAGE( TA_Equal, EqualPeriodTotal, i-1 )
/* Generated */           )
/* Generated */             outInteger[outIdx++] = TA_CANDLECOLOR(i) * 100;
/* Generated */         else
/* Generated */             outInteger[outIdx++] = 0;
/* Generated */         EqualPeriodTotal += TA_CANDLERANGE( TA_Equal, i-1 ) - TA_CANDLERANGE( TA_Equal, EqualTrailingIdx-1 );
/* Generated */         for (totIdx = 1; totIdx >= 0; --totIdx)
/* Generated */             BodyLongPeriodTotal[totIdx] += TA_CANDLERANGE( TA_BodyLong, i-totIdx ) 
/* Generated */                                          - TA_CANDLERANGE( TA_BodyLong, BodyLongTrailingIdx-totIdx );
/* Generated */         i++;
/* Generated */         EqualTrailingIdx++;
/* Generated */         BodyLongTrailingIdx++;
/* Generated */    } while( i <= endIdx );
/* Generated */    *outNbElement = outIdx;
/* Generated */    *outBegIdx    = startIdx;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

