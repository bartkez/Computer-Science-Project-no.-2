#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct image
{
	char standard[3];
	int width;
	int height;
	int maxGrey;
	int pixArray[7][17];
};

void loadImage(struct image *img);


int main()
{
	int i_choice;
	struct image image1;
	do
	{
		system("cls");
		printf("1. Open an image\n2. Exit\n");
		scanf("%d", &i_choice);
		switch (i_choice)
		{
		case 1:
		{
			loadImage(&image1);
		}
		default:
			break;
		}

	} while (i_choice != 2);
	system("pause");
	return 0;

}

void loadImage(struct image *img)
{
	system("cls");
	char flname[20];
	int line = 0,i,j,temp;
	printf("Insert a name of a desired file: ");
	scanf("%s", &flname);
	FILE *file;
	file = fopen(flname, "r");
	if (file == NULL)
	{
		printf("Cannot open desired file!\n");
		return EXIT_FAILURE;
	}
	while (!feof(file))
	{
		while (getc(file) == '#') 
		{
			while (getc(file) != '\n');
		}
		fseek(file, -1, SEEK_CUR);
		if (line==0)
		{
			fscanf(file, "%s", &img->standard);
			printf("%s\n", img->standard);
			line++;
		}
		else if (line == 1)
		{
			fscanf(file, "%d %d", &img->width,&img->height);
			printf("%d %d\n", img->width,img->height);
			line++;
		}
		else if (line == 2)
		{
			fscanf(file, "%d", &img->maxGrey);
			printf("%d\n", img->maxGrey);
			line++;
		}
		else
		{
			for (i = 0; i < 7; i++)
			{
				for (j = 0; j < 17; j++)
				{
					fscanf(file, "%d", &temp);
					(img)->pixArray[i][j] = temp;
					printf("%d ", img->pixArray[i][j]);
				}
				printf("\n");
			}
		}
	}
	printf("To continue press any key...");
	_getch();
	fclose(file);
}
