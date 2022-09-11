
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

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
			printf("Sorry, but no. You can't delete your system. We're caring about your happiness when using that system, and didn't want to break it. We didn't can help you with removing system. You can't go into magic permissive mode and remove package system. This error is a part of compiled C code.\n");
		}
		else
		{
        	printf("next package(s) will be deleted: ");
        	printf(argv[2]);
	        printf("\n");
        	printf("do you really want to remove this package?(1/0) ");
			int a;
			scanf("%d", &a);
			if (a == 1)
        	{
            	if(remove(strcat("/usr/apps/",argv[2])) == 0)
            	{
			        remove(strcat("/usr/bin/",argv[2]));
            	    printf("Package successfully removed");
            	    return 0;
            	}
            	else
            	{
            	    printf("Error occured when removing package. Did you remove it with sudo?");
            	}
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
            printf("do you really want to install this package?(1/0) ");
            int b;
            scanf("%d", &b);
            if (b == 1)
            {
                printf("okay, starting libcurl...");
                CURL *curl;
                FILE *fp;
                CURLcode res;
                char *url = strcat("https://zover-os.github.io/zerp-packages/",argv[2]);
                char outfilename[FILENAME_MAX] = strcat("/var/cache",argv[2]);
                curl = curl_easy_init();
                if (curl)
                {
                    fp = fopen(outfilename,"wb");
                    curl_easy_setopt(curl, CURLOPT_URL, url);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
                    res = curl_easy_perform(curl);
                    /* always cleanup */
                    curl_easy_cleanup(curl);
                    fclose(fp);
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
