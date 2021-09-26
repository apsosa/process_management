#include <unistd.h>
#include <stdio.h>

int main()
{
	int ret;
	printf("I am in the main function:\n");
	ret = execv("./hello",NULL);

	printf("Ending the Main function\n");
	return 0;
}
