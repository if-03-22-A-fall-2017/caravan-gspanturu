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
 };

Caravan new_caravan()
{
  struct CaravanImplementation* list;
  list = (struct CaravanImplementation*) malloc(sizeof(struct CaravanImplementation));
  list->length = 0;
  list->head = (struct Node*) malloc(sizeof(struct Node));
  return list;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  //alle nodes freen weil sich in c nichts selba löscht!!
 sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (caravan->head->animal == NULL) { // wenn liste leer

    if (animal != 0) {

      if (get_caravan(animal) != NULL) { //wenns in ana anderen karavane drinnen is
        remove_from_caravan(animal, get_caravan(animal));
      }

      add_to_caravan(animal, caravan); //in da jetzigen karavane eini
      caravan->head->animal = animal;
      caravan->head->next = NULL;
      caravan->length++; //1 tier mehr drinnen
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

          if (get_caravan(animal) != NULL) { //wenns in ana anderen karavane drinnen is
            remove_from_caravan(animal, get_caravan(animal));
          }

          add_to_caravan(animal,caravan);
          current->next = node_to_add;
          caravan->length++;
        }
      }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
}

int get_caravan_load(Caravan caravan)
{
  return 0;
}

void unload(Caravan caravan)
{
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
