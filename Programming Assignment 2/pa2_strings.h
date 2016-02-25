/*
 * Filename: pa2_strings.h
 * Author: Mark Huang
 * Userid:cs30xcl 
 * Description: Strings used in PA2 output
 * Date: 2/9/2015
 * Sources of Help: Writeup and piazza
 */

#ifndef PA2_STRINGS_H
#define PA2_STRINGS_H

#define STR_USAGE "\nUsage: %s [#_of_ticks [starting_time]] | [--help]\n"\
  "    (optional #_of_ticks = [%d-%d])\n"\
  "    (optional starting_time = HH:MM:SS)\n"\
  "    (HH = [%d-%d]; MM = [%d-%d]; SS = [%d-%d])\n\n"

#define STR_HELP "--help" /* Used to check if the user entered --help */

/*
 * Time output strings
 */
#define STR_DEF_TIME "%s\n" /* use this string to display time when
                             * argc != MAX_ARGS */

#define STR_BCD_TIME "%02x " /* use this string to display the time
                              * after each tick */

/*
 * Error strings
 */
#define STR_ERR_TICK_RANGE "\n\t# of clock ticks must be in the range"\
  " [%d-%d]\n\n"

#define STR_ERR_TICK_VALUE "\n\tError parsing clock ticks\n\n"

#define STR_ERR_HR_RANGE "\n\tHours value must be in the range"\
  " [%d-%d]\n\n"

#define STR_ERR_HR_VALUE "\n\tError parsing hours\n\n"

#define STR_ERR_MIN_RANGE "\n\tMinutes value must be in the range"\
  " [%d-%d]\n\n"

#define STR_ERR_MIN_VALUE "\n\tError parsing minutes\n\n"

#define STR_ERR_SEC_RANGE "\n\tSeconds value must be in the range"\
  " [%d-%d]\n\n"

#define STR_ERR_SEC_VALUE "\n\tError parsing seconds\n\n"

#define STR_ERR_SEC_RANGE "\n\tSeconds value must be in the range"\
  " [%d-%d]\n\n"

#define STR_ERR_TIME_FORMAT "\n\tStarting time format incorrect\n\n"


#endif /* PA2_STRINGS_H */

