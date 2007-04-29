/* TA-LIB Copyright (c) 1999-2007, Mario Fortier
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
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (RetCode::InternalError)
/* Generated */    namespace TicTacTec { namespace TA { namespace Library {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #include "ta_java_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (RetCode.InternalError)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
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
/* Generated */ int Core::MacdFixLookback( int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int macdFixLookback( int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_MACDFIX_Lookback( int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */    /* min/max are checked for optInSignalPeriod. */
/* Generated */    if( (int)optInSignalPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSignalPeriod = 9;
/* Generated */    else if( ((int)optInSignalPeriod < 1) || ((int)optInSignalPeriod > 100000) )
/* Generated */       return -1;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */

   /* The lookback is driven by the signal line output.
    *
    * (must also account for the initial data consume 
    *  by the fix 26 period EMA).
    */
   return   LOOKBACK_CALL(EMA)( 26 )
          + LOOKBACK_CALL(EMA)( optInSignalPeriod );
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_MACDFIX - Moving Average Convergence/Divergence Fix 12/26
 * 
 * Input  = double
 * Output = double, double, double
 * 
 * Optional Parameters
 * -------------------
 * optInSignalPeriod:(From 1 to 100000)
 *    Smoothing for the signal line (nb of period)
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::MacdFix( int    startIdx,
/* Generated */                                         int    endIdx,
/* Generated */                                         cli::array<double>^ inReal,
/* Generated */                                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                                         [Out]int%    outBegIdx,
/* Generated */                                         [Out]int%    outNBElement,
/* Generated */                                         cli::array<double>^  outMACD,
/* Generated */                                         cli::array<double>^  outMACDSignal,
/* Generated */                                         cli::array<double>^  outMACDHist )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode macdFix( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         double       inReal[],
/* Generated */                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                         MInteger     outBegIdx,
/* Generated */                         MInteger     outNBElement,
/* Generated */                         double        outMACD[],
/* Generated */                         double        outMACDSignal[],
/* Generated */                         double        outMACDHist[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_MACDFIX( int    startIdx,
/* Generated */                        int    endIdx,
/* Generated */                        const double inReal[],
/* Generated */                        int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                        int          *outBegIdx,
/* Generated */                        int          *outNBElement,
/* Generated */                        double        outMACD[],
/* Generated */                        double        outMACDSignal[],
/* Generated */                        double        outMACDHist[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_START_INDEX,OutOfRangeStartIndex);
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_END_INDEX,OutOfRangeEndIndex);
/* Generated */ 
/* Generated */    #if !defined(_JAVA)
/* Generated */    if( !inReal ) return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */    #endif /* !defined(_JAVA)*/
/* Generated */    /* min/max are checked for optInSignalPeriod. */
/* Generated */    if( (int)optInSignalPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSignalPeriod = 9;
/* Generated */    else if( ((int)optInSignalPeriod < 1) || ((int)optInSignalPeriod > 100000) )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #if !defined(_JAVA)
/* Generated */    if( !outMACD )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    if( !outMACDSignal )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    if( !outMACDHist )
/* Generated */       return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */ 
/* Generated */    #endif /* !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   return FUNCTION_CALL(INT_MACD)( startIdx, endIdx, inReal,
                                   0, /* 0 indicate fix 12 == 0.15  for optInFastPeriod */
                                   0, /* 0 indicate fix 26 == 0.075 for optInSlowPeriod */
                                   optInSignalPeriod,
                                   outBegIdx,
                                   outNBElement,
                                   outMACD,
                                   outMACDSignal,
                                   outMACDHist );
}

/**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::RetCode Core::MacdFix( int    startIdx,
/* Generated */                                         int    endIdx,
/* Generated */                                         cli::array<float>^ inReal,
/* Generated */                                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                                         [Out]int%    outBegIdx,
/* Generated */                                         [Out]int%    outNBElement,
/* Generated */                                         cli::array<double>^  outMACD,
/* Generated */                                         cli::array<double>^  outMACDSignal,
/* Generated */                                         cli::array<double>^  outMACDHist )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public RetCode macdFix( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         float        inReal[],
/* Generated */                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                         MInteger     outBegIdx,
/* Generated */                         MInteger     outNBElement,
/* Generated */                         double        outMACD[],
/* Generated */                         double        outMACDSignal[],
/* Generated */                         double        outMACDHist[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_MACDFIX( int    startIdx,
/* Generated */                          int    endIdx,
/* Generated */                          const float  inReal[],
/* Generated */                          int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                          int          *outBegIdx,
/* Generated */                          int          *outNBElement,
/* Generated */                          double        outMACD[],
/* Generated */                          double        outMACDSignal[],
/* Generated */                          double        outMACDHist[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_START_INDEX,OutOfRangeStartIndex);
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return ENUM_VALUE(RetCode,TA_OUT_OF_RANGE_END_INDEX,OutOfRangeEndIndex);
/* Generated */     #if !defined(_JAVA)
/* Generated */     if( !inReal ) return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */     if( (int)optInSignalPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSignalPeriod = 9;
/* Generated */     else if( ((int)optInSignalPeriod < 1) || ((int)optInSignalPeriod > 100000) )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #if !defined(_JAVA)
/* Generated */     if( !outMACD )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     if( !outMACDSignal )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     if( !outMACDHist )
/* Generated */        return ENUM_VALUE(RetCode,TA_BAD_PARAM,BadParam);
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    return FUNCTION_CALL(INT_MACD)( startIdx, endIdx, inReal,
/* Generated */                                    0, 
/* Generated */                                    0, 
/* Generated */                                    optInSignalPeriod,
/* Generated */                                    outBegIdx,
/* Generated */                                    outNBElement,
/* Generated */                                    outMACD,
/* Generated */                                    outMACDSignal,
/* Generated */                                    outMACDHist );
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }}} // Close namespace TicTacTec.TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

