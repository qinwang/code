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
 *  103004 AC   Creation           
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
/* Generated */ int Core::CDL3BLACKCROWS_Lookback( void )
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_CDL3BLACKCROWS_Lookback( void )
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
    return TA_CANDLEAVGPERIOD(TA_ShadowVeryShort) + 3;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CDL3BLACKCROWS - Three Black Crows
 * 
 * Input  = Open, High, Low, Close
 * Output = int
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::CDL3BLACKCROWS( int    startIdx,
/* Generated */                                             int    endIdx,
/* Generated */                                             double       inOpen __gc [],
/* Generated */                                             double       inHigh __gc [],
/* Generated */                                             double       inLow __gc [],
/* Generated */                                             double       inClose __gc [],
/* Generated */                                             [OutAttribute]Int32 *outBegIdx,
/* Generated */                                             [OutAttribute]Int32 *outNbElement,
/* Generated */                                             int           outInteger __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_CDL3BLACKCROWS( int    startIdx,
/* Generated */                               int    endIdx,
/* Generated */                               const double inOpen[],
/* Generated */                               const double inHigh[],
/* Generated */                               const double inLow[],
/* Generated */                               const double inClose[],
/* Generated */                               int          *outBegIdx,
/* Generated */                               int          *outNbElement,
/* Generated */                               int           outInteger[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
    double ShadowVeryShortPeriodTotal[3];
    int i, outIdx, totIdx, ShadowVeryShortTrailingIdx, lookbackTotal;

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

   lookbackTotal = TA_CDL3BLACKCROWS_Lookback();

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
   ShadowVeryShortPeriodTotal[2] = 0;
   ShadowVeryShortPeriodTotal[1] = 0;
   ShadowVeryShortPeriodTotal[0] = 0;
   ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_ShadowVeryShort);
   
   i = ShadowVeryShortTrailingIdx;
   while( i < startIdx ) {
        ShadowVeryShortPeriodTotal[2] += TA_CANDLERANGE( TA_ShadowVeryShort, i-2 );
        ShadowVeryShortPeriodTotal[1] += TA_CANDLERANGE( TA_ShadowVeryShort, i-1 );
        ShadowVeryShortPeriodTotal[0] += TA_CANDLERANGE( TA_ShadowVeryShort, i );
        i++;
   }
   i = startIdx;

   /* Proceed with the calculation for the requested range.
    * Must have:
    * - three consecutive and declining black candlesticks
    * - each candle must have no or very short lower shadow
    * - each candle after the first must open within the prior candle's real body
    * - the first candle's close should be under the prior white candle's high
    * The meaning of "very short" is specified with TA_SetCandleSettings
    * outInteger is negative (-1 to -100): three black crows is always bearish; 
    * the user should consider that 3 black crows is significant when it appears after a mature advance or at high levels, 
    * while this function does not consider it
    */
   outIdx = 0;
   do
   {
        if( TA_CANDLECOLOR(i-3) == 1 &&                                         // white
            TA_CANDLECOLOR(i-2) == -1 &&                                        // 1st black
            TA_LOWERSHADOW(i-2) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[2], i-2 ) &&     
                                                                                // very short lower shadow
            TA_CANDLECOLOR(i-1) == -1 &&                                        // 2nd black
            TA_LOWERSHADOW(i-1) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&     
                                                                                // very short lower shadow
            TA_CANDLECOLOR(i) == -1 &&                                          // 3rd black
            TA_LOWERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&         
                                                                                // very short lower shadow
            inOpen[i-1] < inOpen[i-2] && inOpen[i-1] > inClose[i-2] &&          // 2nd black opens within 1st black's rb
            inOpen[i] < inOpen[i-1] && inOpen[i] > inClose[i-1] &&              // 3rd black opens within 2nd black's rb
            inHigh[i-3] > inClose[i-2] &&                                       // 1st black closes under prior candle's high
            inClose[i-2] > inClose[i-1] &&                                      // three declining
            inClose[i-1] > inClose[i]                                           // three declining
          )
            outInteger[outIdx++] = -100;
        else
            outInteger[outIdx++] = 0;
        /* add the current range and subtract the first range: this is done after the pattern recognition 
         * when avgPeriod is not 0, that means "compare with the previous candles" (it excludes the current candle)
         */
        for (totIdx = 2; totIdx >= 0; --totIdx)
            ShadowVeryShortPeriodTotal[totIdx] += TA_CANDLERANGE( TA_ShadowVeryShort, i-totIdx ) 
                                                - TA_CANDLERANGE( TA_ShadowVeryShort, ShadowVeryShortTrailingIdx-totIdx );
        i++; 
        ShadowVeryShortTrailingIdx++;
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
/* Generated */ enum Core::TA_RetCode Core::CDL3BLACKCROWS( int    startIdx,
/* Generated */                                             int    endIdx,
/* Generated */                                             float        inOpen __gc [],
/* Generated */                                             float        inHigh __gc [],
/* Generated */                                             float        inLow __gc [],
/* Generated */                                             float        inClose __gc [],
/* Generated */                                             [OutAttribute]Int32 *outBegIdx,
/* Generated */                                             [OutAttribute]Int32 *outNbElement,
/* Generated */                                             int           outInteger __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CDL3BLACKCROWS( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                 const float  inOpen[],
/* Generated */                                 const float  inHigh[],
/* Generated */                                 const float  inLow[],
/* Generated */                                 const float  inClose[],
/* Generated */                                 int          *outBegIdx,
/* Generated */                                 int          *outNbElement,
/* Generated */                                 int           outInteger[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     double ShadowVeryShortPeriodTotal[3];
/* Generated */     int i, outIdx, totIdx, ShadowVeryShortTrailingIdx, lookbackTotal;
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
/* Generated */    lookbackTotal = TA_CDL3BLACKCROWS_Lookback();
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }
/* Generated */    ShadowVeryShortPeriodTotal[2] = 0;
/* Generated */    ShadowVeryShortPeriodTotal[1] = 0;
/* Generated */    ShadowVeryShortPeriodTotal[0] = 0;
/* Generated */    ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_ShadowVeryShort);
/* Generated */    i = ShadowVeryShortTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         ShadowVeryShortPeriodTotal[2] += TA_CANDLERANGE( TA_ShadowVeryShort, i-2 );
/* Generated */         ShadowVeryShortPeriodTotal[1] += TA_CANDLERANGE( TA_ShadowVeryShort, i-1 );
/* Generated */         ShadowVeryShortPeriodTotal[0] += TA_CANDLERANGE( TA_ShadowVeryShort, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = startIdx;
/* Generated */    outIdx = 0;
/* Generated */    do
/* Generated */    {
/* Generated */         if( TA_CANDLECOLOR(i-3) == 1 &&                                         // white
/* Generated */             TA_CANDLECOLOR(i-2) == -1 &&                                        // 1st black
/* Generated */             TA_LOWERSHADOW(i-2) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[2], i-2 ) &&     
/* Generated */                                                                                 // very short lower shadow
/* Generated */             TA_CANDLECOLOR(i-1) == -1 &&                                        // 2nd black
/* Generated */             TA_LOWERSHADOW(i-1) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&     
/* Generated */                                                                                 // very short lower shadow
/* Generated */             TA_CANDLECOLOR(i) == -1 &&                                          // 3rd black
/* Generated */             TA_LOWERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&         
/* Generated */                                                                                 // very short lower shadow
/* Generated */             inOpen[i-1] < inOpen[i-2] && inOpen[i-1] > inClose[i-2] &&          // 2nd black opens within 1st black's rb
/* Generated */             inOpen[i] < inOpen[i-1] && inOpen[i] > inClose[i-1] &&              // 3rd black opens within 2nd black's rb
/* Generated */             inHigh[i-3] > inClose[i-2] &&                                       // 1st black closes under prior candle's high
/* Generated */             inClose[i-2] > inClose[i-1] &&                                      // three declining
/* Generated */             inClose[i-1] > inClose[i]                                           // three declining
/* Generated */           )
/* Generated */             outInteger[outIdx++] = -100;
/* Generated */         else
/* Generated */             outInteger[outIdx++] = 0;
/* Generated */         for (totIdx = 2; totIdx >= 0; --totIdx)
/* Generated */             ShadowVeryShortPeriodTotal[totIdx] += TA_CANDLERANGE( TA_ShadowVeryShort, i-totIdx ) 
/* Generated */                                                 - TA_CANDLERANGE( TA_ShadowVeryShort, ShadowVeryShortTrailingIdx-totIdx );
/* Generated */         i++; 
/* Generated */         ShadowVeryShortTrailingIdx++;
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

