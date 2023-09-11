#ifndef DOG_H
#define DOG_H
/**
 * struct dog - Contains a Dog data
 * @name: The dog name
 * @age: The dog age
 * @owner: The name of dog owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

typedef struct dog dog_t;

#endif /* DOG_H */
