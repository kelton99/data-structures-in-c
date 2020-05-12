#include <stdlib.h>
#include <stdio.h>
#include "dlinked_list.h"

// Terrible way to clean the console window, using only for the sake of simplicity
#ifdef _WIN32
	void clear_console() { system("cls"); }
#else
	void clear_console() { system("clear"); }
#endif

enum options {OPT_EXIT, OPT_PUSH_BACK, OPT_INSERT, OPT_REMOVE, OPT_REMOVE_POS, OPT_SEARCH};

int get_int_input(int *value);
int get_menu_input(void);
void print_list(DLinked_List *list);
void push_back(DLinked_List *list);
void insert(DLinked_List *list);
void remove_element(DLinked_List *list);
void remove_from(DLinked_List *list);
void search(DLinked_List *list);
void load_dataset(DLinked_List *list);

int main(void)
{
	DLinked_List *list = create_list();
	load_dataset(list);
	while(1) {
		clear_console();
            printf("Current List: ");
    		list_print(list);

    		int option = get_menu_input();

    		switch (option) {
    			case OPT_EXIT:
    				exit(0);
    			case OPT_PUSH_BACK:
    				push_back(list);
    				break;
    			case OPT_INSERT:
    				insert(list);
    				break;
			case OPT_REMOVE:
    				remove_element(list);
    				break;
			case OPT_REMOVE_POS:
    				remove_from(list);
    				break;
			case OPT_SEARCH:
    				search(list);
    				break;
			default:
				puts("Option not avaliable!");
				break;
    		}

    		puts("Press any key to continue to menu...");
		getchar();

	}
}

int get_int_input(int *value)
{
	char line[256];

	if (fgets(line, sizeof(line), stdin)){
			fflush(stdin);
			return sscanf(line, "%d", value);
	}
	
	return 0;
}

int get_menu_input(void)
{
	puts("Options Menu:\n[0] exit\n[1] push back\n[2] insert\n[3] remove\n[4] remove from position");
	puts("[5] search");
	puts("Insert an option:");
	
	int option;
	if (get_int_input(&option)){

		return option;
	}
	
	return 0;
}

void push_back(DLinked_List *list) 
{
	int value;
	puts("Insert a value to push back:\n");
	if (get_int_input(&value)) 
		list_push_back(list, value);
	else
		puts("Not able to push back, invalid input.");
}

void insert(DLinked_List *list) 
{
	int value;
    int index;
	puts("Insert a value and index to insert:\n");
	if (get_int_input(&value) && get_int_input(&index))
		list_insert(list, value, index);
	else
		puts("Not able to insert, invalid input.");
}

void remove_element(DLinked_List *list)
{
    if (is_empty(list)){
		puts("Can't remove an element of an empty list");
		return;
	}

	int element;
	puts("Insert a value to remove: ");
	if(!get_int_input(&element)) return;

	list_remove(list, element);
	
}

void remove_from(DLinked_List *list)
{
    if (is_empty(list)){
		puts("Can't remove an element of an empty list");
		return;
	}

	int index;
	puts("Insert a index to remove: ");
	if(!get_int_input(&index)) return;

	list_remove_from(list, index);
}

void search(DLinked_List *list)
{
	if (is_empty(list)){
		puts("Can't search an element of an empty list");
		return;
	}

	int element;
	puts("Insert a element to search: ");
	if(!get_int_input(&element)) return;

	int index = list_search(list, element);
	if (index == -1) return;
	printf("Element found at: %d\n", index);
}

void load_dataset(DLinked_List *list)
{
	for(int i = 0; i < 15; i++) list_push_back(list, i);
}