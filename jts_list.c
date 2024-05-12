#include "jts_list.h"

static node* node_create(const size_t size, const void *restrict data)
{
	node* n	= malloc(sizeof(*n));

	if (n == NULL) {
		goto err;
	}

	n->d = malloc(size);

	if (n->d == NULL) {
		goto err;
	}

	memcpy(n->d, data, size);

	err:

	return n;
}

static void node_destroy(node *restrict deletion)
{

	free(deletion->d);
	deletion->d = NULL;

	free(deletion);
	deletion = NULL;
}

list* new_list(void)
{

	list* l = calloc(1, sizeof(*l));

	return l;
}

void free_list(list* l)
{
	if (l) {
		node* tmp;

		while (l->head) {

			tmp = l->head;

			l->head = l->head->next;

			free(tmp->d);

			tmp->d = NULL;

			free(tmp);

			tmp = NULL;

			l->total--;
		}

		l->tail = NULL;

		free(l);

		l = NULL;
	}

	return;
}

void push(list* l, const size_t size, const void *restrict data)
{
	node* n = node_create(size, data);

	if (n) {

		n->next = NULL;

		if(l->tail == NULL) l->tail = n;

		n->next = l->head;

		l->head = n;

		l->total++;
	}

	return;
}

void* pop(list* l)
{
	void *r = NULL;

	if (l && l->head && l->tail && l->total > 0) {

		r = l->head->d;

		node* tmp;

		tmp = l->head->next;

//		if you do this, then the returned pointer would point to an already freed piece of data
//		free(l->head->d);

		free(l->head);

		l->head = NULL;

		l->head = tmp;

		tmp = NULL;

		l->total--;

	} else {

		r = NULL; //fprintf(stderr, "%s", "Cannot pop! List head, list tail, or list itself is NULL. Or list total is zero.");
	}

	return r;
}

void enqueue(list* l, const size_t size, void* data)
{
	node* n = node_create(size, data);

	if (l == NULL || n == NULL) {

		goto err;

	}

	if (n) {

		n->next = NULL;

		if (l->head == NULL) {

			l->head = n;
		}

		if (l->tail == NULL) {

			l->tail = n;

		}

		if (l->tail != n) {

			l->tail->next = n;

			l->tail = n;
		}

		l->total++;

	} else {

		n = NULL; //fprintf(stderr, "%s", "Cannot malloc() new node.");
	}

	err:

	return;
}

list* argvtol(const int argc, char **argv)
{
	list *l = new_list();

	char space = ' ';

	for (int i = 0; i < argc; i++) {

		for (uintmax_t j = 0; j < strlen(argv[i]); j++) {

			enqueue(l, 1, &argv[i][j]);
		}

		enqueue(l, 1, &space);
	}

	return l;
}

list* map_inplace(list *l, void (*fp)(void *))
{
	node *tmp = l->head;

	for (uintmax_t i = 0; i < l->total; i++) {

		(*fp)(tmp->d);

		if (tmp->next == NULL) {

			break;

		} else {

			tmp = tmp->next;
		}
	}

	return l;
}

list* filter_inplace(list *l, int (*is_true)(void *))
{
	node *prev = NULL;
	node *current = l->head;

	while (current != NULL) {

		if ((*is_true)(current->d)) {
			if (prev == NULL) {
				l->head = current->next;
				node_destroy(current);
				l->total--;
				current = l->head;
			} else {
				prev->next = current->next;
				node_destroy(current);
				l->total--;
				current = prev->next;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
	return l;
}

list* map(list *l, int (*compar)(const void *, const void *))
{

	return NULL;

}

list* filter(list *l, int (*compar)(const void *, const void *))
{

	return NULL;
}
