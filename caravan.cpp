/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>


struct Node{
  PackAnimal animal;
  struct Node* next;
};

 struct CaravanImplementation{
	 struct Node* head;
	 int length;
   int load;
   int speed;
 };

Caravan new_caravan()
{
  struct CaravanImplementation* list;
  list = (struct CaravanImplementation*) malloc(sizeof(struct CaravanImplementation));
  list->length = 0;
  list->load = 0;
  list->speed = 0;
  list->head = 0;
//  list->head = (struct Node*) malloc(sizeof(struct Node));
  return list;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
    struct Node* current = caravan->head;

    while (current != 0) {
          struct Node* next_node = current;
          current = current->next;
          sfree(next_node);
    }
   sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal == 0 || get_caravan(animal) == caravan)
  {
    return;
  }
  else{
    struct Node* node_to_add = (struct Node*) malloc(sizeof(struct Node));
    node_to_add->animal = animal;
    node_to_add->next = 0;

    if (caravan->head == 0) {
      caravan->head = node_to_add;
      add_to_caravan(animal, caravan);
    }
    else{
      struct Node* current = caravan->head;

      while (current->next != NULL) {
        current = current->next;
      }
      current->next = node_to_add;
      add_to_caravan(animal, caravan);
    }
        caravan->length++;
        caravan->load += get_load(animal);
  }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal == 0 || caravan == 0) {
    return;
  }
  struct Node* current = caravan->head;


  if (current->animal == animal) {
    int load = get_load(current->animal);
    remove_from_caravan(current->animal, caravan);
    current = current->next;
    caravan->length--;
    caravan->load -= load;
    return;
  }
  while (current->next->next != NULL) {
    if (current->next->animal == animal) {

      int load= get_load(current->next->animal);
      remove_from_caravan(current->next->animal, caravan);
      delete_animal(current->next->animal);
      current->next = current->next->next;
      caravan->length--;
      caravan->load -= load;
      return;
    }
    current = current->next;
  }
}

int get_caravan_load(Caravan caravan)
{
  return caravan->load;
}

void unload(Caravan caravan)
{
  struct Node* current = caravan->head;
   while (current->next != NULL) {
    unload(current->animal);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  /*if (caravan->head != NULL) {
    PackAnimal slowest_animal = caravan->head->animal;
    struct Node* current = caravan->head;


  while (current->next != NULL) {
    if (current->animal->get_actual_speed(current->animal) >= current->next->animal->get_actual_speed(current->next->animal)) {
      slowest_animal = current->next->animal;
    }
    current = current->next;
  }
  return slowest_animal->get_actual_speed(slowest_animal);
}*/
  return 0;
}

void optimize_load(Caravan caravan)
{

}
