#include "ex17.h"
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
	if (argc < 3)
	{
		printf("ERROR\n");
		exit(1);
	}
		
	char action = argv[2][0];
	char *filename = argv[1];

	struct Connection *conn __attribute__((cleanup(cleanup_free)))
		= Database_open(filename, action);
	int id = 0;
	if (argc > 3) id = atoi(argv[3]);
	if (id < 0 || id >= MAX_ROWS)
	{
		printf("ERROR\n");
		exit(1);
	}

	switch (action)
	{
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;

		case 'g':
			if (argc != 4)
			{
				printf("ERROR\n");
				exit(1);
			}
			Database_get(conn, id);
			break;

		case 's':
			if (argc != 6)
			{
				printf("ERROR\n");
				exit(1);
			}
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if (argc != 4)
			{
				printf("ERROR\n");
				exit(1);
			}
			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;

		default:
			exit(1);

	}
return 0;
}
