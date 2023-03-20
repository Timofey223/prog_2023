#include <stddef.h>

struct IntVector
{
	int *data;
	size_t size;
	size_t capacity;
};

struct IntVector *int_vector_new(size_t initial_capacity);

struct IntVector *int_vector_copy(struct IntVector *str);

void int_vector_free(struct IntVector *str);

int int_vector_get_item(const struct IntVector *str, size_t index);

void int_vector_set_item(struct IntVector *str, size_t index, int item);

size_t int_vector_get_size(const struct IntVector *str);

size_t int_vector_get_capacity(const struct IntVector *str);

int int_vector_push_back(struct IntVector *str, int item);

void int_vector_pop_back(struct IntVector *str);

int int_vector_shrink_to_fit(struct IntVector *str);

int int_vector_resize(struct IntVector *str, size_t new_size);

int int_vector_reserve(struct IntVector *str, size_t new_capacity);

void print_struct(struct IntVector *str);
