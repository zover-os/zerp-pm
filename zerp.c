#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <curl/easy.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

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
            	remove(strcat("/usr/bin/",argv[2]));
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
                char z[80];
                sprintf(z, "%s %s", "/usr/apps", argv[2]);
                printf("okay, starting libcurl...");
                CURL *curl;
                FILE *fp;
                CURLcode res;
                char y[120];
                sprintf(y, "%s %s", "https://zover-os.github.io/zerp-packages/", argv[2]);
                char *url = y;
                char outfilename[FILENAME_MAX] = "/var/cache/cached_package.tar.xz";
                curl = curl_easy_init();
                if (curl)
                {
                    fp = fopen(outfilename,"wb");
                    curl_easy_setopt(curl, CURLOPT_URL, url);
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
                    res = curl_easy_perform(curl);
                    curl_easy_cleanup(curl);
                    fclose(fp);
                    printf("\nPackage succesfull download!(or not :) )\n starting packer...");
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
}
