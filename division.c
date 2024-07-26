#include "monty.h"
/**
 * f_div - this will divides the top two elements of the stack.
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *d;
	int ln = 0, ax;

	d = *head;
	while (d)
	{
		d = d->next;
		ln++;
	}
	if (ln < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	d = *head;
	if (d->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ax = d->next->n / d->n;
	d->next->n = ax;
	*head = d->next;
	free(d);
}
