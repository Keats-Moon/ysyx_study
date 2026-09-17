#include <string.h>
#include <stdlib.h>
#include "ex17.h"

void Address_print (struct Address *print)
{
	printf("ID: %d\nName: %s\nEmail: %s\n",
			print->id, print->name, print->email);

}

void Database_load (struct Connection *conn)
{
	fread (conn->db, sizeof(struct Database), 1, conn->file);
}

struct Connection *Database_open (const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	  //struct Connection *conn __attribute__((cleanup(cleanup_free)));这里不能写__attribute__((cleanup(func)))
                                                                  //因为cleanup会在离开作用域时释放，这样的话return的值就悬空了！！！

	conn->db = malloc(sizeof(struct Database));

	if (mode == 'c')
  {
      conn->file = fopen(filename,"w"); 
			if (conn->file == NULL)
      {
         printf("ERROR: Cannot open file.\n");
         exit(1);
      }
	}
  else 
	{
    conn->file = fopen(filename, "r+");

		if (conn->file == NULL)
    {
        printf("ERROR: Cannot open file.\n");
        exit(1);
    }
    Database_load(conn);
  } 
  return conn;
 }

void Database_write (struct Connection *conn)
{
	rewind(conn->file);
	fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	fflush(conn->file);
}

void Database_create (struct Connection *conn)
{
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++)
	{
		struct Address addr = {.id = i, .set = 0};
		conn->db->rows[i] = addr;
	}
}

void Database_set (struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	addr->set = 1;

	strncpy(addr->name, name, MAX_DATA);
	strncpy(addr->email, email, MAX_DATA);
}

void Database_get (struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set)
	{
		Address_print(addr);
	}
}

void Database_delete (struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list (struct Connection *conn)
{
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++)
	{
		struct Address *cur = &conn->db->rows[i];
		if (cur->set)
		{
			Address_print(cur);
		}
	}
}

void cleanup_free (void *p)
{
	struct Connection **cleanup = p;
	fclose((*cleanup)->file);
	free((*cleanup)->db);
	free(*cleanup);
}
