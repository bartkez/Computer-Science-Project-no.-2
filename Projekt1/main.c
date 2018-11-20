#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


struct image
{
	char ca_standard[3];
	int i_width;
	int i_height;
	int i_maxGrey;
	int ia_pixArray[7][17];
};

void loadImage(struct image *img);


int main()
{
	int i_choice;
	struct image st_image1;
	do
	{
		system("cls");
		printf("1. Open an image\n2. Exit\n");
		scanf("%d", &i_choice);
		switch (i_choice)
		{
		case 1:
		{
			loadImage(&st_image1);
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
	char ca_flname[20];
	int i_line = 0,i,j,temp;
	printf("Insert a name of a desired file: ");
	scanf("%s", &ca_flname);
	FILE *file;
	file = fopen(ca_flname, "r");
	if (file == NULL)
	{
		printf("Cannot open desired file!\n");
		return;
	}
	while (!feof(file))
	{
		while (getc(file) == '#') 
		{
			while (getc(file) != '\n');
		}
		fseek(file, -1, SEEK_CUR);
		if (i_line==0)
		{
			fscanf(file, "%s", &img->ca_standard);
			printf("%s\n", img->ca_standard);
			i_line++;
		}
		else if (i_line == 1)
		{
			fscanf(file, "%d %d", &img->i_width,&img->i_height);
			printf("%d %d\n", img->i_width,img->i_height);
			i_line++;
		}
		else if (i_line == 2)
		{
			fscanf(file, "%d", &img->i_maxGrey);
			printf("%d\n", img->i_maxGrey);
			i_line++;
		}
		else
		{
			for (i = 0; i < 7; i++)
			{
				for (j = 0; j < 17; j++)
				{
					fscanf(file, "%d", &temp);
					(img)->ia_pixArray[i][j] = temp;
					printf("%d ", img->ia_pixArray[i][j]);
				}
				printf("\n");
			}
		}
	}
	printf("To continue press any key...");
	_getch();
	fclose(file);
}
