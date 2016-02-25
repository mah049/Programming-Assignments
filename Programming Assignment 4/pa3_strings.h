/*
 * Filename: pa3_strings.h
 * Author: Mark Huang
 * Userid: cs30xcl
 * Description: Strings used in pa3
 */

#ifndef PA3_STRINGS_H
#define PA3_STRINGS_H

/*
 * buildAnagramDictionary constants
 */
#define FILE_OPEN_MODE "rb" /* file open mode for dictionary */

/*
 * Strings are used for user interaction
 */
#define STR_SEARCH "Enter a word to search for anagrams [^D to exit]: "
#define STR_NO_ANAGRAMS_FOUND "\nNo anagrams found.\n\n"
#define STR_ANAGRAMS_FOUND "\nAnagram(s) are:"
#define STR_ANAGRAM_WORD " %s"
#define STR_NEW_LINE "\n\n" /* use after displaying the last anagram word */

/*
 * makeAnagramTable error string
 */
#define STR_ERR_MAKE_ANAGRAM_TABLE "makeAnagramTable failed"

/*
 * The following strings will be used in your assembly modules and are
 * defined globally in global.c for access from your assembly routines.
 */
extern const char *STR_USAGE;

#endif /* PA3_STRINGS_H */

