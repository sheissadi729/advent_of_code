#include "main.h"
/**
 * main - 
 */
int main(void)
{
	FILE *file;
	int len, i;
	ssize_t r;
	char buffer[300];
	int first_digit, last_digit, sum = 0;

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
			if ((buffer[i] >= 48) && (buffer[i] <= 57))
			{
				first_digit = buffer[i] - '0';
				break;
			}
		}
		for (i = len -1; i >= 0; i--)
		{
			if ((buffer[i] >= 48) && (buffer[i] <= 57))
			{
				last_digit = buffer[i] - '0';
				break;
			}
		}
		sum += (first_digit * 10) + last_digit;
	}
	printf("sum is: %d\n", sum);
	fclose(file);
	return (0);
}
