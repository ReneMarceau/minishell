/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:32:34 by aperez-b          #+#    #+#             */
/*   Updated: 2023/11/29 23:10:07 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

/* ************* *************           ************* ************* */
/*                             STRUCTURES                            */
/* ************* *************           ************* ************* */

/**
 * @brief Structure representing a singly-linked list node.
 * 
 * The 't_list' structure represents a node in a singly-linked list.
 * It contains a pointer
 * to arbitrary content and a pointer to the next node in the list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Structure representing a 2D vector.
 *
 * The 't_vector' structure
 * represents a 2D vector with 'x' and 'y' components.
 */
typedef struct s_vector
{
	int				x;
	int				y;
}					t_vector;

/* ************* *************           ************* ************* */
/*                    STRING MANIPULATION FUNCTIONS                  */
/* ************* *************           ************* ************* */

/**
 * @brief Calculate the length of a null-terminated string.
 *
 * @param s The input string.
 * 
 * @return The length of the string.
 */
size_t				ft_strlen(const char *s);

/**
 * @brief Concatenate two strings, ensuring null-termination.
 * 
 * This function appends the content of the 'src' string to the 'dst' string
 * while ensuring that the resulting string is null-terminated.
 * The 'size' parameter
 * specifies the size of the 'dst' buffer to prevent buffer overflows.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * 
 * @return The total length of the concatenated string.
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copy 'size - 1' bytes from 'src' to 'dst'.
 *
 * This function copies up to 'size
 * - 1' bytes from 'src' to 'dst' and ensures that
 * the resulting 'dst' string is null-terminated.
 * It prevents buffer overflows by limiting the copy size to 'size'.
 *
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * 
 * @return The total length of the copied string.
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Compare two strings.
 * 
 * This function compares the strings 's1' and 's2'.
 * It returns true or false, depending on whether 's1' is the exact same as 's2'.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * 
 * @return True if 's1' is the same as 's2', false otherwise.
 */
bool    			ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Compare two strings up to the first 'n' characters.
 * 
 * This function compares the first 'n' characters of 's1' and 's2'.
 * It returns an integer less than, equal to,
 * or greater than zero, depending on whether 's1' is
 * less than, equal to, or greater than 's2', respectively.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The number of characters to compare.
 * 
 * @return An integer less than, equal to, or greater than zero.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Convert a string to an integer.
 * 
 * This function parses the string 'nptr'
 * and returns the equivalent integer value.
 * 
 * @param nptr The input string to convert.
 * 
 * @return The converted integer value.
 */
int					ft_atoi(const char *nptr);

/**
 * @brief A more restrictive version of ft_atoi that also 
 * returns the parsed number.
 * 
 * This function parses the string 'nptr'
 * and returns the equivalent integer value.
 * Additionally, it stores the parsed integer in 'nbr' if 'nbr' is not NULL.
 *
 * @param nptr The input string to convert.
 * @param nbr A pointer to store the parsed integer (if not NULL).
 * 
 * @return The converted integer value.
 */
int					ft_atoi2(const char *nptr, long *nbr);

/**
 * @brief Convert an integer to a string.
 * 
 * This function converts an integer 'n' to its string representation.
 * 
 * @param n The integer to convert.
 * 
 * @return The string representation of the integer.
 */
char				*ft_itoa(int n);

/**
 * @brief Convert an unsigned integer to a string.
 * 
 * This function converts an unsigned integer 'n' to its string representation.
 * 
 * @param n The unsigned integer to convert.
 * 
 * @return The string representation of the unsigned integer.
 */
char				*ft_uitoa(unsigned int n);

/**
 * @brief Print a character to the given file descriptor.
 * 
 * This function writes a single character 'c'
 * to the specified file descriptor 'fd'.
 * 
 * @param c The character to print.
 * @param fd The file descriptor to write to.
 * 
 * @return The number of characters written or -1 on error.
 */
int					ft_putchar_fd(char c, int fd);

/**
 * @brief Write 'n' characters to the given file descriptor.
 * 
 * This function writes 'n' copies of the character 'c'
 * to the specified file descriptor 'fd'.
 * 
 * @param c The character to print.
 * @param fd The file descriptor to write to.
 * @param n The number of characters to write.
 *
 * @return The number of characters written or -1 on error.
 */
int					ft_putnchar_fd(char c, int fd, int n);

/**
 * @brief Print a string followed by a newline character '\\n' 
 * to a given file descriptor.
 * 
 * This function writes the string 's'
 * to the specified file descriptor 'fd' followed
 * by a newline character '\\n'.
 *
 * @param s The string to print.
 * @param fd The file descriptor to write to.
 *
 * @return The number of characters written or -1 on error.
 */
int					ft_putendl_fd(char *s, int fd);

/**
 * @brief Print an integer to the given file descriptor.
 * 
 * This function writes the integer 'n' to the specified file descriptor 'fd'.
 *
 * @param n The integer to print.
 * @param fd The file descriptor to write to.
 *
 * @return The number of characters written or -1 on error.
 */
int					ft_putnbr_fd(int n, int fd);

/**
 * @brief Print a number in a given base to the given file descriptor.
 * 
 * This function writes the number 'n' in the specified base
 * to the file descriptor 'fd'.
 *
 * @param n The number to print.
 * @param base The base for representation (e.g., "0123456789ABCDEF").
 * @param fd The file descriptor to write to.
 *
 * @return The number of characters written or -1 on error.
 */
int					ft_putnbr_base_fd(long n, char *base, int fd);

/**
 * @brief Print a string to the given file descriptor.
 * 
 * This function writes the string 's' to the specified file descriptor 'fd'.
 *
 * @param s The string to print.
 * @param fd The file descriptor to write to.
 * 
 * @return The number of characters written or -1 on error.
 */
int					ft_putstr_fd(char *s, int fd);

/**
 * @brief Write 'n' bytes from a string to the given file descriptor.
 * 
 * This function writes 'n' bytes from the string 's'
 * to the specified file descriptor 'fd'.
 *
 * @param s The source string.
 * @param fd The file descriptor to write to.
 * @param n The number of bytes to write.
 * 
 * @return The number of characters written or -1 on error.
 */
int					ft_putstrn_fd(char *s, int fd, int n);

/**
 * @brief Split a string into an array of strings using a delimiter character.
 * 
 * This function splits the string 's' into an array of strings
 * using the delimiter 'c'.
 * The result is an array of strings terminated by a NULL pointer.
 *
 * @param s The input string to split.
 * @param c The delimiter character.
 * 
 * @return An array of strings or NULL on failure.
 */
char				**ft_split(char const *s, char c);

/**
 * @brief Concatenate two strings, allocating enough space.
 *
 * This function concatenates the strings 
 * 's1' and 's2' into a new string, dynamically 
 * allocating memory for the result. 
 * The caller is responsible for freeing the returned
 * string when no longer needed.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * 
 * @return A new concatenated string or NULL on memory allocation failure.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Apply a function to every character in a string.
 *
 * This function applies the function 'f' to every character in the string 's'.
 * It returns a new string with the modified characters.
 *
 * @param s The input string.
 * @param f The function to apply to each character.

 * @return A new string with modified characters or 
 * NULL on memory allocation failure.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Remove occurrences of characters in 'set' 
 * from the start and end of 's1'.
 * 
 * This function trims characters from the start and end of 's1' 
 * that are present in the 'set' string. 
 * The result is a new dynamically allocated string.
 *
 * @param s1 The input string to trim.
 * @param set The set of characters to remove.
 * 
 * @return A new trimmed string or NULL on memory allocation failure.
 */
char				*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Copy a substring from a string, 
 * starting at 'start' with a length of 'len'.
 * 
 * This function copies a substring from the string 's', 
 * starting at index 'start', and with a length of 'len'. 
 * The result is a new dynamically allocated string.
 *
 * @param s The source string.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * 
 * @return A new substring or NULL on memory allocation failure.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/* ************* *************           ************* ************* */
/*                          MEMORY FUNCTIONS                         */
/* ************* *************           ************* ************* */

/**
 * @brief Set 'n' bytes of memory pointed to by 's' to zero.
 * 
 * This function sets the first 'n' bytes of the memory 
 * pointed to by 's' to zero.
 *
 * @param s Pointer to the memory to be set to zero.
 * @param n Number of bytes to set to zero.
 */
void				ft_bzero(void *s, size_t n);

/**
 * @brief Allocate memory for an array of elements.
 *
 * This function allocates memory for an array of 'nmemb' elements, 
 * each 'size' bytes long.
 * The allocated memory is initialized to zero. 
 * The caller is responsible for freeing the
 * allocated memory when it is no longer needed.
 *
 * @param nmemb Number of elements in the array.
 * @param size Size of each element in bytes.
 * 
 * @return A pointer to the allocated memory, or NULL on failure.
 */
void				*ft_calloc(size_t nmemb, size_t size);

/* ************* *************           ************* ************* */
/*                        CHARACTER FUNCTIONS                        */
/* ************* *************           ************* ************* */

/**
 * @brief Check if a character is alphanumeric.
 * 
 * This function checks whether the character 'c' is alphanumeric 
 * (a letter or a digit).
 *
 * @param c The character to check.
 * 
 * @return 1 if 'c' is alphanumeric, 0 otherwise.
 */
int					ft_isalnum(int c);

/**
 * @brief Check if a character is alphabetic.
 *
 * This function checks whether the character 'c' is an alphabetic character.
 *
 * @param c The character to check.
 * 
 * @return 1 if 'c' is alphabetic, 0 otherwise.
 */
int					ft_isalpha(int c);

/**
 * @brief Check if a character is a valid ASCII character.
 *
 * This function checks whether the character 'c' is a valid ASCII character.
 *
 * @param c The character to check.
 * 
 * @return 1 if 'c' is a valid ASCII character, 0 otherwise.
 */
int					ft_isascii(int c);

/**
 * @brief Check if a character is a digit (0-9).
 *
 * This function checks whether the character 'c' is a digit (0-9).
 *
 * @param c The character to check.
 * 
 * @return 1 if 'c' is a digit, 0 otherwise.
 */
int					ft_isdigit(int c);

/**
 * @brief Check if a character is a printable character.
 *
 * This function checks whether the character 'c' is a printable character.
 *
 * @param c The character to check.
 * 
 * @return 1 if 'c' is a printable character, 0 otherwise.
 */
int					ft_isprint(int c);

/**
 * @brief Convert an uppercase character to lowercase.
 *
 * This function converts an uppercase character 'c' 
 * to its corresponding lowercase character.
 *
 * @param c The uppercase character to convert.
 * 
 * @return The lowercase equivalent of 'c', 
 * or 'c' if it is not an uppercase character.
 */
int					ft_tolower(int c);

/**
 * @brief Convert a lowercase character to uppercase.
 * 
 * This function converts a lowercase character 'c' 
 * to its corresponding uppercase character.
 *
 * @param c The lowercase character to convert.
 * 
 * @return The uppercase equivalent of 'c',
	or 'c' if it is not a lowercase character.
 */
int					ft_toupper(int c);

/* ************* *************           ************* ************* */
/*                   MEMORY MANIPULATION FUNCTIONS                   */
/* ************* *************           ************* ************* */

/**
 * @brief Copy memory from 'src' to 'dest',
	stopping if 'c' is encountered or after 'n' bytes.
    
 * This function copies up to 'n' bytes from memory area 'src' to 'dest'.
 * If the character 'c' is encountered during copying, the copying stops, 
 * and a pointer to the character after 'c' in 'dest' is returned. 
 * If 'c' is not found in the first 'n' bytes
 * of 'src', 'n' bytes are copied, and NULL is returned.
 *
 * @param dest Pointer to the destination memory.
 * @param src Pointer to the source memory.
 * @param c The stopping character.
 * @param n Maximum number of bytes to copy.
 * 
 * @return A pointer to the character after 'c' in 'dest' if 'c' is found,
	or NULL otherwise.
 */
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

/**
 * @brief Search for the first occurrence of 'c' in the first 'n' bytes of 's'.
 * 
 * This function searches the first 'n' bytes of memory pointed to by 's' 
 * for the character 'c'. If 'c' is found, a pointer to the first occurrence
 * of 'c' is returned. If 'c' is not found
 * in the first 'n' bytes, NULL is returned.
 *
 * @param s Pointer to the memory to be searched.
 * @param c The character to search for.
 * @param n Number of bytes to search.
 * 
 * @return A pointer to the first occurrence of 'c' in 's' if found,
	or NULL otherwise.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compare 'n' bytes of memory between 's1' and 's2'.
 * 
 * This function compares the first 'n' bytes of 
 * memory pointed to by 's1' and 's2'.
 * It returns an integer less than, equal to, 
 * or greater than zero if 's1' is found to be
 * less than, equal to, or greater than 's2', respectively.
 *
 * @param s1 Pointer to the first memory block.
 * @param s2 Pointer to the second memory block.
 * @param n Number of bytes to compare.
 * 
 * @return An integer less than, equal to,
	or greater than zero based on the comparison.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copy 'n' bytes from 'src' to 'dest'.
 *
 * This function copies 'n' bytes from memory area 'src' to memory area 'dest'.
 *
 * @param dest Pointer to the destination memory.
 * @param src Pointer to the source memory.
 * @param n Number of bytes to copy.
 * 
 * @return A pointer to the destination memory 'dest'.
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copy 'n' bytes from 'src' to 'dest', even if they overlap.
 *
 * This function copies 'n' bytes from memory area 'src' to memory area 'dest',
 * even if the memory areas overlap. 
 * It ensures the correct behavior when copying between 
 * overlapping memory regions.
 *
 * @param dest Pointer to the destination memory.
 * @param src Pointer to the source memory.
 * @param n Number of bytes to copy.
 * 
 * @return A pointer to the destination memory 'dest'.
 */
void				*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Set 'n' bytes of memory 's' to the value 'c'.
 * 
 * This function sets the first 'n' bytes of the memory area pointed to by 's' 
 * to the specified value 'c'.
 *
 * @param s Pointer to the memory to be set.
 * @param c The value to set (as an unsigned char).
 * @param n Number of bytes to set.
 * 
 * @return A pointer to the memory 's' after setting.
 */
void				*ft_memset(void *s, int c, size_t n);

/* ************* *************           ************* ************* */
/*                       STRING SEARCH FUNCTIONS                     */
/* ************* *************           ************* ************* */

/**
 * @brief Find the first occurrence of 'c' in the string 's'.
 * 
 * This function searches the string 's' for the first occurrence of 
 * the character 'c'.
 * If 'c' is found, a pointer to the location of 'c' in 's' is returned. 
 * If 'c' is not found, NULL is returned.
 *
 * @param s Pointer to the null-terminated string to be searched.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of 'c' in 's' if found,
	or NULL otherwise.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Find the index of the first occurrence of 'c' in the string 's'.
 *
 * This function searches the string 's' for the first occurrence 
 * of the character 'c'. If 'c' is found, the index (position) of 'c' in 's' 
 * is returned. If 'c' is not found, -1 is returned.
 *
 * @param s Pointer to the null-terminated string to be searched.
 * @param c The character to search for.
 * 
 * @return The index of the first occurrence of 'c' in 's' if found, or
	-1 otherwise.
 */
int					ft_strchr_i(const char *s, int c);

/**
 * @brief Find the index of the first character in 's' 
 * that belongs to the character set 'set'.
 *
 * This function searches the string 's' for the first character 
 * that belongs to the character set 'set'. 
 * If such a character is found, its index (position) in 's' is returned. 
 * If no character in 's' belongs to 'set', -1 is returned.
 *
 * @param s Pointer to the null-terminated string to be searched.
 * @param set A null-terminated string representing a character set.
 * @return The index of the first character in 's' that belongs to 'set', or
	-1 if none are found.
 */
int					ft_strchars_i(const char *s, char *set);

/**
 * @brief Find the last occurrence of 'c' in the string 's'.
 *
 * This function searches the string 's' for 
 * the last occurrence of the character 'c'.
 * If 'c' is found, a pointer to the location of the last 'c' in 's' 
 * is returned. 
 * If 'c' is not found, NULL is returned.
 *
 * @param s Pointer to the null-terminated string to be searched.
 * @param c The character to search for.
 * 
 * @return A pointer to the last occurrence of 'c' in 's' if found,
	or NULL otherwise.
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Duplicate a null-terminated string.
 *
 * This function duplicates the null-terminated string 's' and 
 * returns a pointer to the newly allocated string. 
 * The caller is responsible for freeing the allocated memory when it is
 * no longer needed.
 *
 * @param s Pointer to the null-terminated string to be duplicated.
 * 
 * @return A pointer to the duplicated string, or NULL on failure.
 */
char				*ft_strdup(const char *s);

/**
 * @brief Find the first occurrence of 'little' in 'big', 
 * up to 'len' characters.
 * 
 * This function searches the string 'big' for the first occurrence of 
 * the string 'little' within the first 'len' characters of 'big'. 
 * If 'little' is found, a pointer to the location of 'little' in 'big' 
 * is returned. 
 * If 'little' is not found within the first 'len' characters, NULL is returned.
 *
 * @param big Pointer to the null-terminated string to be searched.
 * @param little Pointer to the null-terminated string to search for.
 * @param len Maximum number of characters to search within 'big'.
 * 
 * @return A pointer to the first occurrence of 'little' in 'big' if found,
	or NULL otherwise.
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/* ************* *************           ************* ************* */
/*                        NUMERIC FUNCTIONS                          */
/* ************* *************           ************* ************* */

/**
 * @brief Calculate the length of a number 'n' in a given base.
 *
 * This function calculates the number of digits in an integer 'n' 
 * when represented in the specified numeric 'base'.
 *
 * @param n The integer number to calculate the length of.
 * @param base The numeric base for representation (e.g., 10 for decimal,
	16 for hexadecimal).
 *
 * @return The number of digits in 'n' when represented in the given base.
 */
int					ft_nbrlen(long n, int base);

/**
 * @brief Calculate the square root of 'nb' as the closest rounded integer.
 *
 * This function calculates the square root of a non-negative integer 'nb'
 * and returns the closest rounded integer value.
 *
 * @param nb The non-negative integer to calculate the square root of.
 * 
 * @return The square root of 'nb' as the closest rounded integer.
 */
int					ft_sqrt(int nb);

/**
 * @brief Calculate 'nb' raised to the power of 'power' using recursion.
 *
 * This function calculates 'nb' raised to the power of 'power' using recursion.
 *
 * @param nb The base value.
 * @param power The exponent value.
 * 
 * @return The result of 'nb' raised to the power of 'power'.
 */
int					ft_recursive_power(int nb, int power);

/**
 * @brief Calculate the Euclidean distance between two points.
 *
 * This function calculates the Euclidean distance between two points represented
 * by the 'src' and 'dest' vectors.
 *
 * @param src The source vector.
 * @param dest The destination vector.
 * 
 * @return The Euclidean distance between 'src' and 'dest'.
 */
int					ft_euclideandistance(t_vector src, t_vector dest);

/* ************* *************           ************* ************* */
/*                 CHARACTER AND STRING OPERATIONS                   */
/* ************* *************           ************* ************* */

/**
 * @brief Count the number of occurrences of character 'c' in the string 's'.
 *
 * This function counts and returns the number of occurrences of the character 
 * 'c' in the null-terminated string 's'.
 *
 * @param s Pointer to the null-terminated string to search within.
 * @param c The character to count.
 * 
 * @return The number of occurrences of 'c' in 's'.
 */
int					ft_countchar(char *s, char c);

/**
 * @brief Check if 'c' is a form of whitespace (space, tab, etc.).
 *
 * This function checks if the character 'c' represents a form of whitespace, 
 * including space (' '), tab ('\\t'), newline ('\\n'), carriage return ('\\r'),
 * vertical tab ('\\v'), and form feed ('\\f').
 *
 * @param c The character to check.
 * 
 * @return 1 if 'c' is a form of whitespace, 0 otherwise.
 */
int					ft_isspace(char c);

/**
 * @brief Convert a character 'c' to a string.
 *
 * This function converts the character 'c' to a dynamically allocated string 
 * containing only that character and a null-terminator. 
 * The caller is responsible for freeing the allocated memory 
 * when it is no longer needed.
 *
 * @param c The character to convert to a string.
 * 
 * @return A pointer to the dynamically allocated string containing 'c'.
 */
char				*ft_chartostr(char c);

/**
 * @brief Concatenate two strings, handling NULL inputs gracefully.
 *
 * This function concatenates two strings, 's1' and 's2'. 
 * If either 's1' or 's2' is NULL, it returns a copy of the non-NULL string,
 * or an empty string if both are NULL.
 *
 * @param s1 The first string to concatenate (can be NULL).
 * @param s2 The second string to concatenate (can be NULL).

 * @return A new string that is the concatenation of 's1' and 's2' 
 * (or a copy of the non-NULL string).
 */
char				*ft_strenlarge(char *s1, char *s2);

/**
 * @brief Compare the last 'n' characters of two strings.
 *
 * This function compares the last 'n' characters of 
 * two null-terminated strings 's1' and 's2'.
 *
 * @param s1 Pointer to the first null-terminated string.
 * @param s2 Pointer to the second null-terminated string.
 * @param n Number of characters to compare from the end of the strings.
 * 
 * @return An integer less than, equal to,
	or greater than zero if 's1' is found to be less than,
 * equal to, or greater than 's2', respectively.
 */
int					ft_strrncmp(const char *s1, const char *s2, size_t n);

/* ************* *************           ************* ************* */
/*                            LINKED LIST FUNCTIONS                          */
/* ************* *************           ************* ************* */

/**
 * @brief Add a new node to the end of a linked list.
 *
 * This function adds a new node with the specified 'newnode' 
 * to the end of the linked list 'lst'.
 *
 * @param lst A pointer to a pointer to the first node of the linked list.
 * @param newnode The node to be added to the end of the linked list.
 */
void				ft_lstadd_back(t_list **lst, t_list *newnode);

/**
 * @brief Add a new node to the beginning of a linked list.
 *
 * This function adds a new node with the specified 'newnode' 
 * to the beginning of the linked list 'lst'.
 *
 * @param lst A pointer to a pointer to the first node of the linked list.
 * @param newnode The node to be added to the beginning of the linked list.
 */
void				ft_lstadd_front(t_list **lst, t_list *newnode);

/**
 * @brief Delete all elements of a linked list, applying 'del' to each content.
 *
 * This function deletes all elements of the linked list 'lst' 
 * by applying the 'del' function to each content of the nodes 
 * and freeing the memory associated with the nodes.
 *
 * @param lst A pointer to a pointer to the first node of the linked list. 
 * After calling this function, the pointer is set to NULL.
 * @param del The function to apply to each content in the linked list 
 * for deletion (can be NULL).
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Delete a node, free its memory, and apply 'del' to its content.
 *
 * This function deletes the specified node 'lst' by applying the 'del' 
 * function to its content and freeing the memory associated with the node.
 *
 * @param lst The node to be deleted and freed.
 * @param del The function to apply to the content of the node for deletion 
 * (can be NULL).
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Apply a function 'f' to the content of each node in the linked list.
 * This function applies the specified function 'f' to the content of each node 
 * in the linked list 'lst'.
 *
 * @param lst A pointer to the first node of the linked list.
 * @param f The function to apply to the content of each node.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Return a pointer to the last node in the linked list.
 *
 * This function returns a pointer to the last node in the linked list 'lst'.
 *
 * @param lst A pointer to the first node of the linked list.
 * 
 * @return A pointer to the last node in the linked list 
 * or NULL if the list is empty.
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * @brief Apply 'f' to each node of the linked list 
 * and return a new linked list.
 *
 * This function applies the specified function 'f' 
 * to the content of each node in the linked
 * list 'lst' and creates a new linked list containing the results.
 *
 * @param lst A pointer to the first node of the linked list.
 * @param f The function to apply to the content of each node.
 * @param del The function to apply to the content of nodes for deletion 
 * (can be NULL).
 * 
 * @return A pointer to the new linked list containing the results 
 * of applying 'f'.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/**
 * @brief Create a new node with 'content'.
 *
 * This function creates a new node with the specified 'content' 
 * and returns a pointer to the new node.
 *
 * @param content The content to be stored in the new node.
 * 
 * @return A pointer to the newly created node.
 */
t_list				*ft_lstnew(void *content);

/**
 * @brief Return the number of elements in a linked list.
 *
 * This function returns the number of elements in the linked list 'lst'.
 *
 * @param lst A pointer to the first node of the linked list.
 * 
 * @return The number of elements in the linked list.
 */
int					ft_lstsize(t_list *lst);

/**
 * @brief Return the node at the given index or NULL
 * if the index is out of range.
 *
 * This function returns a pointer to the node at the specified index 'i' 
 * in the linked list 'lst'.
 * If the index is out of range, it returns NULL.
 *
 * @param lst A pointer to the first node of the linked list.
 * @param i The index of the node to retrieve (0-based).

 * @return A pointer to the node at the specified index
 * or NULL if the index is out of range.
 */
t_list				*ft_lstget_at(t_list *lst, int i);

/* ************* *************           ************* ************* */
/*                         MATRIX FUNCTIONS                          */
/* ************* *************           ************* ************* */

/**
 * @brief Frees memory allocated for a matrix (array of arrays).
 *
 * This function frees the memory allocated for a matrix 'm,' 
 * which is represented as an array of strings.
 *
 * @param m A pointer to the matrix (array of arrays) to be freed.
 */
void				ft_free_matrix(char ***m);

/**
 * @brief Duplicates a matrix (array of arrays).
 *
 * This function creates a deep copy of a matrix 'm,' 
 * which is represented as an array of strings,
 * and returns a pointer to the duplicated matrix.
 *
 * @param m The matrix (array of arrays) to be duplicated.
 * 
 * @return A pointer to the duplicated matrix.
 */
char				**ft_dup_matrix(char **m);

/**
 * @brief Prints a matrix (array of strings) to a file descriptor.
 *
 * This function prints each row of the matrix 'm,' 
 * which is represented as an array of strings, to the
 * specified file descriptor 'fd.' If 'nl' is non-zero, 
 * a newline character is added after each row.
 *
 * @param m The matrix (array of strings) to be printed.
 * @param nl Flag indicating whether to add newline characters 
 * between rows (non-zero for yes).
 * @param fd The file descriptor to which the matrix is printed.
 * 
 * @return The number of characters printed, or -1 on error.
 */
int					ft_putmatrix_fd(char **m, int nl, int fd);

/**
 * @brief Returns the number of rows in a matrix (array of strings).
 *
 * This function returns the number of rows in the matrix 'm,' 
 * which is represented as an array of strings.
 *
 * @param m The matrix (array of strings) for which to count the rows.
 * 
 * @return The number of rows in the matrix.
 */
int					ft_matrixlen(char **m);

/**
 * @brief Checks if any character in 'set' is surrounded
 * by two other characters in 's'.
 *
 * This function checks if any character in the 'set' string is surrounded 
 * by two other characters in the input string 's.' 
 * It returns 1 if such a character is found; otherwise, it returns 0.
 *
 * @param s The input string to search within.
 * @param set The set of characters to check for.
 * @param char1 The first surrounding character.
 * @param char2 The second surrounding character.
 * 
 * @return (1 if a matching character is found); otherwise, 0.
 */
int					ft_between_chars(char *s, char *set, char char1,
						char char2);

/**
 * @brief Splits a string into a matrix (array of arrays)
 * using 'set' as delimiters.
 *
 * This function splits the input string 's' into a matrix (array of arrays) 
 * using the characters in the 'set' string as delimiters. 
 * It returns a dynamically allocated matrix.
 *
 * @param s The input string to split.
 * @param set The set of delimiter characters.
 * @return A dynamically allocated matrix (array of arrays) 
 * containing the split substrings.
 */
char				**ft_subsplit(char const *s, char *set);

/**
 * @brief Appends a new row to a matrix (array of arrays).
 *
 * This function appends a new row, represented as a string 'newstr,' 
 * to the matrix 'in' (array of arrays).
 * It returns a dynamically allocated matrix with the additional row.
 *
 * @param in The matrix (array of arrays) to which the new row is appended.
 * @param newstr The string representing the new row.
 * 
 * @return A dynamically allocated matrix with the appended row.
 */
char				**ft_extend_matrix(char **in, char *newstr);

/**
 * @brief Converts a matrix (array of arrays) to a linked list,
	with each element as content.
 *
 * This function converts a matrix 'matrix' (array of arrays) 
 * into a linked list, with each element
 * from the matrix represented as the content of a node in the linked list.
 *
 * @param matrix The matrix (array of arrays) to be converted.
 * 
 * @return A pointer to the head of the resulting linked list.
 */
t_list				*ft_matrixtolst(char **matrix);

/**
 * @brief Converts a linked list to a matrix (array of arrays), 
 * using each element's content.
 *
 * This function converts a linked list 'lst' into a matrix (array of arrays), 
 * using the content of each node as an element in the matrix.
 *
 * @param lst A pointer to the head of the linked list to be converted.

 * @return A dynamically allocated matrix (array of arrays) 
 * containing the content of the linked list.
 */
char				**ft_lsttomatrix(t_list *lst);

/**
 * @brief Replaces the 'n'-th row of a matrix with another matrix.
 *
 * This function replaces the 'n'-th row of the matrix 'big' (array of arrays) 
 * with the contents of the matrix 'small' (array of arrays).
 *
 * @param big A pointer to the matrix (array of arrays) in which 
 * the replacement occurs.
 * @param small The matrix (array of arrays) used for replacement.
 * @param n The index of the row to be replaced in 'big.'
 * 
 * @return The modified 'big' matrix.
 */
char				**ft_matrix_replace_in(char ***big, char **small, int n);

#endif
