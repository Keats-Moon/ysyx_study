#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct Person 
{
	char *name;
	int age;
	int height;
	int weight;
};

void cleanup_free (void *p)
{
	struct Person **person = p;
	free ((*person)->name);
	free (*person);
	*person = NULL;
}


struct Person *Person_create (char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert (who != NULL);
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}


void Person_print (struct Person *who)
{
	printf ("Name: %s\n", who->name);
	printf ("Age: %d\n", who->age);
	printf ("Height: %d\n", who->height);
	printf ("Weight: %d\n", who->weight);
}

int main ()
{
	struct Person *ShiWenxuan __attribute__((cleanup(cleanup_free)))
		= Person_create("Shi Wenxuan", 18, 185, 65);
	struct Person *SunBinhe __attribute__((cleanup(cleanup_free)))
		= Person_create("Sun Binhe", 18, 170, 55);
	Person_print (ShiWenxuan);
	Person_print (SunBinhe);

	return 0;
}



