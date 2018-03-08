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
  list->head = (struct Node*) malloc(sizeof(struct Node));
  return list;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
/*  if(caravan->length == 0)
  {
    sfree(caravan);
  }
  else{
    struct Node* current = caravan->head;
    struct Node* next_node;

    while (current != NULL) {
          next_node = current->next;
          sfree(current);
          current = next_node;
    }
  }*/
   sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (caravan->head->animal == NULL) {

    if (animal != 0) {

      if (get_caravan(animal) != NULL) {
        remove_from_caravan(animal, get_caravan(animal));
      }

      add_to_caravan(animal, caravan);
      caravan->head->animal = animal;
      caravan->head->next = (struct Node*) malloc(sizeof(struct Node));
      caravan->length++;
      caravan->load += get_load(animal);
    }
  }
    else{
      struct Node* node_to_add = (struct Node*) malloc(sizeof(struct Node));
      node_to_add->animal = animal;
      node_to_add->next = NULL;

      struct Node* current = caravan->head;

        while (current->next != NULL ) {
          current = current->next;
        }

        if (current != NULL) {

          if (get_caravan(animal) != NULL) {
            remove_from_caravan(animal, get_caravan(animal));
          }

          add_to_caravan(animal,caravan);
          current->next = (struct Node*) malloc(sizeof(struct Node));
          current->next = node_to_add;
          caravan->load += get_load(animal);
          caravan->length++;
        }
      }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  struct Node* current = caravan->head;

  while (current->next->next != NULL) {
    if (current->next->animal == animal) {
      delete_animal(current->next->animal);
      current->next = current->next->next;
      caravan->length--;
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
