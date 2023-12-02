#include "main.h"
/**
 * main - gets the first and last digit of a line and combine them
 * Return: 0(success)
 */
int main(void)
{
	FILE *file;
	int len, i, j = 0, k, x, l, y;
	ssize_t r;
	char buffer[300];
	int first_digit = 0, last_digit = 0, sum = 0;
	digits my_digits[] = {
		{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
		{6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, NULL}
	};

	file = fopen("calib_doc", "r");
	if (file == NULL)
	{
		perror("fopen");
		exit(1);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		len = strlen(buffer);
		if ((len > 0) && (buffer[len - 1] == '\n'))
			buffer[len - 1] = '\0';
		for (i = 0; buffer[i] != '\0'; i++)
		{
			j = 0;
			while (my_digits[j].spelled != NULL)
			{
				y = i;
				l = strlen(my_digits[j].spelled);
				for (k = 0; k < l; k++)
				{
					if (buffer[y] != my_digits[j].spelled[k])
						break;
					y++;
				}
				if (k == l)
				{
					if (first_digit == 0)
						first_digit = my_digits[j].num;
					break;
				}
				j++;
			}
			if ((buffer[i] >= 48) && (buffer[i] <= 57))
			{
				if (first_digit == 0)
					first_digit = buffer[i] - '0';
				break;
			}
		}
		for (i = len - 1; i >= 0; i--)
		{
			j = 0;
			while (my_digits[j].spelled != NULL)
			{
				l = strlen(my_digits[j].spelled);
				x = i - l + 1;
				for (k = 0; k < l; k++)
				{
					if (buffer[x] != my_digits[j].spelled[k])
						break;
					x++;
				}
				if (k == l)
				{
					if (last_digit == 0)
						last_digit = my_digits[j].num;
					break;
				}
				j++;
			}
			if ((buffer[i] >= 48) && (buffer[i] <= 57))
			{
				if (last_digit == 0)
					last_digit = buffer[i] - '0';
				break;
			}
		}
		printf("first digit: %d\n last digit: %d\n", first_digit, last_digit);
		printf("cal value: %d\n", ((first_digit * 10) + last_digit));
		sum += (first_digit * 10) + last_digit;
		first_digit = 0;
		last_digit = 0;
	}
	printf("sum is: %d\n", sum);
	fclose(file);
	return (0);
}
