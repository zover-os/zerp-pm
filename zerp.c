#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc <=1)
	{
		printf("entered too few arguments. Try again.");
		printf("\n");
	}
	printf("\n");
	if (strcmp(argv[1], "-r") == 0)
	{
		if (strcmp(argv[2], "system") == 0)
		{
			printf("Sorry, but no. You can't delete your system. I don't care what you are and idiot. We didn't can help you with removing system. You can't go into magic permissive mode and remove package system. This error is a part of compiled C code.\n");
		}
		else
		{
        	printf("next packages will be deleted: ");
        	printf(argv[2]);
	        printf("\n");
        	printf("do you really want to remove this package? 0(no)/1(yes)\n");
			int a;
			scanf("%d", &a);
			if (a == 1)
        	{
            	char x[] = "rm -f /usr/bin/";
            	system(strcat(x, argv[2]));
			}
			if (a == 0)
			{
				printf("abort.");
				printf("\n");
			}
    		}
	}
        if (strcmp(argv[1], "-i") == 0)
        {
            printf("next package(s) will be installed: ");
            printf(argv[2]);
            printf("\n");
            printf("do you really want to install this package? 0(no)/1(yes)\n");
            int b;
            scanf("%d", &b);
            if (b == 1)
            {
                char x[] = "cd /usr/bin/ && tar -xvf ";
                system(strcat(x, argv[2]));
                char z[] = "rm -f /usr/bin/";
                system(strcat(z, argv[2]));
            }
            if (b == 0)
            {
                printf("abort.\n");
            }
        }
        if (strcmp(argv[1], "-h") == 0)
        {
            printf("Welcome to version of Zover OS Package Manager - zerp.");
            printf("\n");
            printf("install package - zerp -i _name_ \n");
            printf("remove packages - zerp -r _name_\n");
        }
}
