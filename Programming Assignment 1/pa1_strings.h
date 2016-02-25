/*
 *Filename: pa1_strings.h
 *author:mark ahung
 *userid: cs30xcl
 *Date:1/27/2015
 *Descritipno: contains the strings name
 */

#ifndef STRINGS_H
#define STRINGS_H

/*
 * Usage instructions
 */
#define USAGE_STR "\
Usage: %s size plus_char fill_char border_char\n\
    size        (must be within the range of [%d-%d])\n\
                (must be odd)\n\
    plus_char   (must be an ASCII value within the range of [%d-%d])\n\
                (must be different than fill_char and border_char)\n\
    fill_char   (must be an ASCII value within the range of [%d-%d])\n\
                (must be different than plus_char and border_char)\n\
    border_char (must be an ASCII value within the range of [%d-%d])\n\
                (must be different than plus_char and fill_char)\n"

/*
 * Display plus format string
 */
#define PRINT_CHAR_FMT_STR "%c"

/*
 * Error messages
 */
#define SIZE_RANGE_ERR_STR "\
size (%ld) must be within the range [%d-%d]\n\n"

#define SIZE_ODD_INTEGER_ERR_STR "\
size (%ld) must be odd\n\n"

#define PLUS_CHAR_RANGE_ERR_STR "\
plus_char (%ld) must be within the range [%d-%d]\n\n"

#define FILL_CHAR_RANGE_ERR_STR "\
fill_char (%ld) must be within the range [%d-%d]\n\n"

#define BORDER_CHAR_RANGE_ERR_STR "\
border_char (%ld) must be within the range [%d-%d]\n\n"

#define PLUS_CHAR_FILL_CHAR_ERR_STR "\
plus_char (%ld) and fill_char (%ld) must be different\n\n"

#define PLUS_CHAR_BORDER_CHAR_ERR_STR "\
plus_char (%ld) and border_char (%ld) must be different\n\n"

#define FILL_CHAR_BORDER_CHAR_ERR_STR "\
fill_char (%ld) and border_char (%ld) must be different\n\n"

#define INTEGER_ERR_STR "\
\"%s\" is not an integer\n\n"

#endif /* STRINGS_H */
