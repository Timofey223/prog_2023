#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
struct IntVector{
	int* data;
	size_t size;
	size_t capacity;
};
struct IntVector *int_vector_new(size_t initial_capacity){
	if(initial_capacity == 0){
		return 0;
	}
	struct IntVector *str = malloc(sizeof(struct IntVector));
	if(!str){
		free(str);
		return NULL;
	}
	str->size = 0;
	str->capacity = initial_capacity;
	if(!(str->data = malloc(sizeof(int)*initial_capacity))){
		free(str);
		return NULL;
	}
	else{
		return str;
	}
}

struct IntVector *int_vector_copy(const struct IntVector *str){
	struct IntVector *str_copy = malloc(sizeof(*str));
	if((!str_copy) || (str->capacity == 0)){
		free(str_copy);
		return NULL;
	}
	str_copy->size = str->size;
	str_copy->capacity = str->capacity;
	if(!(str_copy->data = malloc(sizeof(int)*str_copy->capacity))){
		free(str_copy);
		return NULL;
	}
	else{
		for(int i = 0; i < str->capacity;i++){
			str_copy->data[i] = str->data[i];
		}
		return str_copy;
	}
}

void int_vector_free(struct IntVector *str){
	if(str!=NULL){
		free(str->data);
		free(str);
	}
}

int int_vector_get_item(const struct IntVector *str, size_t index){
	if(str->size == 0){
		printf("Error: There's nothing\n");
		return -1;
	}
	if(str->size <= index){
		printf("Error: List index out of range\n");
		return -1;
	}
	return str->data[index];
}

void int_vector_set_item(struct IntVector *str, size_t index, int item){
	if(str->size>index){
		str->data[index] = item;
	}
	else{ 
		str->data[index] = item;
		str->size = index + 1;
	}
}

size_t int_vector_get_size(const struct IntVector *str){
	return str->size;
}

size_t int_vector_get_capacity(const struct IntVector *str){
	return str->capacity;
}

int int_vector_push_back(struct IntVector *str, int item){
	if(str->capacity<=str->size){
		str->data = realloc(str->data,(str->capacity)*2*(sizeof(int)));
		str->capacity *= 2;
		if(!str->data){
			return -1;
		}
	}
	if(str->capacity>str->size){
		str->data[str->size] = item;
		str->size++;
		return 0;
	}
	return -1;
}

void int_vector_pop_back(struct IntVector *str){
	if((str->size)>0){
		str->data[(str->size)-1] = 0;
		str->size --;
	}
}

int int_vector_shrink_to_fit(struct IntVector *str){
	if(str->size!=str->capacity){
		str->data = realloc(str->data,(str->size)*(sizeof(int)));
		str->capacity = str->size;
		if(!str->data){
			return -1;
		}
	}
	return 0;
}

int int_vector_resize(struct IntVector *str, size_t new_size){
	if(new_size>str->size){
		if(str->capacity < new_size){
			str->capacity = new_size;
			str->data = realloc(str->data,(str->capacity)*(sizeof(int)));
			if(!str->data){
				return -1;
			}
		}
		for(int i = str->size; i<new_size;i++){
			str->data[i] = 0;
		}
		str->size = new_size;
		return 0;
	}
	else if(new_size == str->size){
		return 0;
	}
	else{
		return -1;
	}
}

int int_vector_reserve(struct IntVector *str, size_t new_capacity){
	if(new_capacity>str->capacity){
		str->data = realloc(str->data,new_capacity*sizeof(int));
		str->capacity = new_capacity;
		if(!str->data){
			return -1;
		}
	}
	if(errno){
		return -1;
	}
	return 0;
}

void print_struct(const struct IntVector *str){
        printf("struct IntVector\n\tData:");
        for(int i = 0; i < str->capacity;i++){
                printf("%d ",str->data[i]);
        }
        printf("\n\tSize %ld\n\tCapacity %ld\n",str->size,str->capacity);
}
