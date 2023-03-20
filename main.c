#include <stdio.h>
#include "Intvector.h"
int main(){
	struct IntVector *Array_1;
	struct IntVector *Array_2;

	Array_1 = int_vector_new(8);

	printf("Array_1:\n");
	printf("Adress - %p\n", Array_1);
	print_struct(Array_1);

	Array_2 = int_vector_copy(Array_1);

	printf("\nArray 2(copy Array_1):\n");
	printf("Adress - %p\n", Array_2);
	print_struct(Array_2);
	printf("Freeing memory..(Array_1)\n");
	int_vector_free(Array_1);
	
	printf("Push_back:\n");
	for(int i = 0; i < 10; i++){
		int_vector_push_back(Array_2, i);
	}
	print_struct(Array_2);

	printf("\n\nPop_Back\n");
	int_vector_pop_back(Array_2);
	print_struct(Array_2);

	print_struct(Array_2);
	printf("\nGet_item(data[10]):");
	printf("%d\n",int_vector_get_item(Array_2, 10));
	printf("Get Size ---> %ld\n",int_vector_get_size(Array_2));
        printf("Get Capacity ---> %ld\n\n", int_vector_get_capacity(Array_2));

	printf("\n\nSet_item 38 -> data[2]:\n");
	int_vector_set_item(Array_2, 2, 38);
	print_struct(Array_2);

	printf("\n\nFunc int_vector_shrink_to_fit:\n");
	int_vector_shrink_to_fit(Array_2);
	print_struct(Array_2);

	printf("\n\nResize to 13:\n");
	int_vector_resize(Array_2, 13);
	print_struct(Array_2);

	printf("\n\nIncrease capacity to 15\n");
	int_vector_reserve(Array_2, 15);
	print_struct(Array_2);

	printf("Freeing memory..\n");

	int_vector_free(Array_2);
}



