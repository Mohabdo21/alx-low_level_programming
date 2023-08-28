#include "main.h"
/**
 * set_string - Sets the value of a pointer to a char.
 * @s: A pointer to a pointer that needs to be updated.
 * @to: The new value that @s should point to.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
