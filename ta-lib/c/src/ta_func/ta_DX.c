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
 *  010802 MF   Template creation.
 *
 */

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

int TA_DX_Lookback( TA_Integer    optInTimePeriod_0, /* From 1 to TA_INTEGER_MAX */
                    TA_Integer    optInCompatibility_1 ) 
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   return 0;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_DX - Directional Movement Index
 * 
 * Input  = High, Low, Close
 * Output = TA_Real
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod_0:(From 1 to TA_INTEGER_MAX)
 *    Number of period
 * 
 * optInCompatibility_1:
 *    Make function compatible to some software
 * 
 * 
 */

TA_RetCode TA_DX( TA_Libc      *libHandle,
                  TA_Integer    startIdx,
                  TA_Integer    endIdx,
                  const TA_Real inHigh_0[],
                  const TA_Real inLow_0[],
                  const TA_Real inClose_0[],
                  TA_Integer    optInTimePeriod_0, /* From 1 to TA_INTEGER_MAX */
                  TA_Integer    optInCompatibility_1,
                  TA_Integer   *outBegIdx,
                  TA_Integer   *outNbElement,
                  TA_Real       outReal_0[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   (void)libHandle; /* Get ride of warning if unused. */

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   /* Verify required price component. */
   if(!inHigh_0||!inLow_0||!inClose_0)
      return TA_BAD_PARAM;

   /* min/max are checked for optInTimePeriod_0. */
   if( optInTimePeriod_0 == TA_INTEGER_DEFAULT )
      optInTimePeriod_0 = 14;
   else if( (optInTimePeriod_0 < 1) || (optInTimePeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   if( optInCompatibility_1 == TA_INTEGER_DEFAULT )
      optInCompatibility_1 = 0;
   else if( (optInCompatibility_1 < 0) || (optInCompatibility_1 > 1) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   return TA_SUCCESS;
}

