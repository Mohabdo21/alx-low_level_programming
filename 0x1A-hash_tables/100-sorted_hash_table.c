#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;
	unsigned long int i;

	new_table = malloc(sizeof(shash_table_t));
	if (new_table == NULL)
		return (NULL);

	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	new_table->shead = NULL;
	new_table->stail = NULL;

	return (new_table);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Check if key already exists in the hash table */
	current_node = ht->array[key_index((const unsigned char *)key, ht->size)];
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			/* If key exists, update its value */
			free(current_node->value);
			current_node->value = strdup(value);
			return (1);
		}
		current_node = current_node->next;
	}

	/* If key does not exist, create a new node */
	new_node = create_new_node(key, value);
	if (new_node == NULL)
		return (0);

	/* Insert the new_node into the hash table and the sorted linked list */
	insert_node(ht, new_node);

	return (1);
}

/**
 * create_new_node - creates a new node with given key and value
 * @key: the key
 * @value: the value
 *
 * Return: pointer to the new node
 */
shash_node_t *create_new_node(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	return (new_node);
}

/**
 * insert_node - inserts a new node into the hash table
 * and the sorted linked list
 * @ht: the hash table
 * @new_node: the new node
 */
void insert_node(shash_table_t *ht, shash_node_t *new_node)
{
	unsigned long int index;
	shash_node_t *sorted_node;

	index = key_index((const unsigned char *)new_node->key, ht->size);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		sorted_node = ht->shead;
		while (sorted_node != NULL && strcmp(new_node->key, sorted_node->key) > 0)
			sorted_node = sorted_node->snext;

		insert_node_sorted_list(ht, new_node, sorted_node);
	}
}

/**
 * insert_node_sorted_list - inserts a new node into the sorted linked list
 * @ht: the hash table
 * @new_node: the new node
 * @sorted_node: the node in the sorted linked list after which the
 * new node should be inserted
 */
void insert_node_sorted_list(shash_table_t *ht, shash_node_t *new_node,
		shash_node_t *sorted_node)
{
	if (sorted_node == NULL)
	{
		new_node->sprev = ht->stail;
		new_node->snext = NULL;
		ht->stail->snext = new_node;
		ht->stail = new_node;
	}
	else if (sorted_node->sprev == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = sorted_node;
		sorted_node->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		new_node->sprev = sorted_node->sprev;
		new_node->snext = sorted_node;
		sorted_node->sprev->snext = new_node;
		sorted_node->sprev = new_node;
	}
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table
 * @key: the key
 *
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *sep = "";

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		printf("%s'%s': '%s'", sep, node->key, node->value);
		sep = ", ";
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *separator = "";

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		printf("%s'%s': '%s'", separator, node->key, node->value);
		separator = ", ";
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *temp_node;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp_node = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp_node;
		}
	}
	free(ht->array);
	free(ht);
}
