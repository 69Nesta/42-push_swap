# 📌 Libft

**Libft** is a custom C library that reimplements essential functions from the standard C library, along with additional string utilities, memory handling helpers, and a full linked-list API.

This document includes **function descriptions, arguments, and return values** for all parts of the project.

---

# 📦 Installation

```sh
make            # build libft.a
make clean      # remove object files
make fclean     # remove object files + libft.a
make re         # rebuild everything
```

Include the header:

```c
#include "libft.h"
```

Compile your program with the library:

```sh
cc main.c -L. -lft
```

# 1️⃣ Part 1 — Libc Functions

### 🔠 Character checks

#### `int ft_isalpha(int c)`

* **Arg:** `c` → character to test
* **Return:** non-zero if alphabetic, 0 otherwise

#### `int ft_isdigit(int c)`

* Tests if `c` is a digit (`0–9`)

#### `int ft_isalnum(int c)`

* Tests if `c` is alphanumeric

#### `int ft_isascii(int c)`

* Tests if `c` is a valid ASCII value (0–127)

#### `int ft_isprint(int c)`

* Tests if printable (32–126)

---

### 🔁 Character conversion

#### `int ft_toupper(int c)`

* Converts lowercase → uppercase
* **Return:** converted char or original if no change

#### `int ft_tolower(int c)`

* Converts uppercase → lowercase

---

### 🧵 String functions

#### `size_t ft_strlen(const char *str)`

* **Arg:** string pointer
* **Return:** length of string (no `\0`)

#### `size_t ft_strlcpy(char *dst, const char *src, size_t size)`

* Copies up to `size - 1` bytes
* **Return:** length of `src`

#### `size_t ft_strlcat(char *dst, const char *src, size_t size)`

* Appends `src` to `dst`
* **Return:** total length of string it tried to create

#### `char *ft_strchr(const char *s, int c)`

* Finds first `c`
* **Return:** pointer to char or `NULL`

#### `char *ft_strrchr(const char *s, int c)`

* Finds last `c`

#### `int ft_strncmp(const char *s1, const char *s2, size_t n)`

* Compares `s1` and `s2` up to `n` chars
* **Return:** negative, zero, or positive

#### `char *ft_strnstr(const char *hay, const char *needle, size_t len)`

* Searches for substring inside a limited range
* **Return:** pointer to start of match or `NULL`

#### `char *ft_strdup(const char *s)`

* Allocates and returns a copy of `s`

---

### 💾 Memory functions

#### `void *ft_memset(void *ptr, int value, size_t n)`

* Fills memory with `value`
* **Return:** `ptr`

#### `void ft_bzero(void *s, size_t n)`

* Sets `n` bytes to zero

#### `void *ft_memcpy(void *dst, const void *src, size_t n)`

* Copies memory (no overlap protection)
* **Return:** `dst`

#### `void *ft_memmove(void *dst, const void *src, size_t n)`

* Safe memory copy (handles overlap)

#### `void *ft_memchr(const void *s, int c, size_t n)`

* Finds byte in memory block
* **Return:** pointer or `NULL`

#### `int ft_memcmp(const void *s1, const void *s2, size_t n)`

* Compares memory blocks
* **Return:** <0, 0, >0

#### `void *ft_calloc(size_t count, size_t size)`

* Allocates zero-filled memory
* **Return:** allocated block or `NULL`

---

### 🔢 Conversions

#### `int ft_atoi(const char *nptr)`

* Converts string → integer
* Handles whitespace, +/−

---

# 2️⃣ Part 2 — Additional Functions

### ✂️ Substrings & joining

#### `char *ft_substr(char const *s, unsigned int start, size_t len)`

* Extracts substring starting at `start` for `len` chars

#### `char *ft_strjoin(char const *s1, char const *s2)`

* Returns a new string: `s1 + s2`

#### `char *ft_strtrim(char const *s1, char const *set)`

* Removes characters from both ends

---

### 🔡 Splitting & mapping

#### `char **ft_split(char const *s, char c)`

* Splits `s` into an array of strings
* **Return:** `NULL`-terminated array

#### `char *ft_itoa(int n)`

* Converts integer → newly allocated string

#### `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`

* Applies `f(index, char)` to each character
* **Return:** new string

#### `void ft_striteri(char *s, void (*f)(unsigned int, char*))`

* Same as `strmapi` but modifies `s` directly

---

### 🖨 File descriptor output

#### `void ft_putchar_fd(char c, int fd)`

* Writes one character

#### `void ft_putstr_fd(char *s, int fd)`

* Writes string

#### `void ft_putendl_fd(char *s, int fd)`

* Writes string + newline

#### `void ft_putnbr_fd(int n, int fd)`

* Writes integer as text

---

# 3️⃣ Bonus — Linked List Functions

All list functions use:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

---

### ➕ Creation & insertion

#### `t_list *ft_lstnew(void *content)`

* Creates a new node

#### `void ft_lstadd_front(t_list **lst, t_list *new)`

* Adds node at beginning

#### `void ft_lstadd_back(t_list **lst, t_list *new)`

* Adds node at end

---

### 📏 Size & navigation

#### `int ft_lstsize(t_list *lst)`

* Counts nodes

#### `t_list *ft_lstlast(t_list *lst)`

* Returns last node

---

### 🗑 Deletion

#### `void ft_lstdelone(t_list *lst, void (*del)(void *))`

* Deletes one node using `del`

#### `void ft_lstclear(t_list **lst, void (*del)(void *))`

* Deletes all nodes

---

### 🔄 Iteration & mapping

#### `void ft_lstiter(t_list *lst, void (*f)(void *))`

* Applies function to each node

#### `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`

* Creates new list from applying `f`
* Uses `del` to free in case of failure

---

# ✔️ Usage Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s = ft_strjoin("Hello, ", "World!");
    printf("%s\n", s);
    free(s);
    return 0;
}
```

Compile:

```sh
cc main.c -L. -lft
```

## ✍️ Author

- [@69Nesta](https://github.com/69Nesta)
