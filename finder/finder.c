#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int il, int ic)
{
	int gameOn=1, guessCount=0;
	struct element
	{int line, column;};

	srand(time(NULL));

	struct element game;
	struct element chosen;
	struct element guess;
	struct element dir;
	char direction[10];
	char ek[2];


	system("cls");	
	printf("FINDER GAME!\n\n\nPlease enter the amount of line and column as 'LinexColumn' format (3-10): ");
	scanf("%dx%d", &game.line, &game.column);
	while(game.line>10 || game.line<3 || game.column>10 || game.column<3)
	{
		system("cls");
		printf("FINDER GAME!\n\n\nThat's not a valid input, try again between 3-10: ");
		scanf("%dx%d", &game.line, &game.column);
	}

	int grid[game.line][game.column];
	char gridShown[game.line][game.column];


	for (il=0 ; il<=game.line-1 ; il++)
	{
		for (ic=0 ; ic<=game.column-1 ; ic++)
		{
			grid[il][ic]=0; //sets all the variables in grid to 0
			gridShown[il][ic]='-'; //sets the shown grid with all -
		}
	}

	//picks a coordinate
	chosen.line = rand() % game.line;
	chosen.column = rand() % game.column;

	grid[chosen.line][chosen.column]=1;

	while(gameOn==1 || gameOn==2)
	{
		system("cls");
		//printf("%d %d\n", chosen.line+1, chosen.column+1); //hint
		printf("FINDER GAME\n\n");

		//prints the game grid with @'s
		for (il=0 ; il<=game.line-1 ; il++)
		{
			for (ic=0 ; ic<=game.column-1 ; ic++)
			{
				printf("  %c ", gridShown[il][ic]);
			}
			printf("\n\n");

		}

		
		if(gameOn==2)
		{
			printf("Your guess was wrong. It's at%sof your guess.\n(You have %d right(s) to guess left.)\n", direction, 5-guessCount);
		}

		//scanning for the guess line and column
		printf("\nEnter your guess as 'LinexColumn' format (ex: 4x5): ");
		scanf("%dx%d", &guess.line, &guess.column);
		while(guess.line>game.line || guess.line<1 || guess.column>game.column || guess.column<1 || gridShown[guess.line-1][guess.column-1]=='X')
		{
			if(gridShown[guess.line-1][guess.column-1]='X')
			{
				printf("\nYou've already typed that coordination. ");
			}

			else
			{
				printf("\nThat's not a valid guess. ");
			}
			 
			printf("Make your guess again between 1-%d and 1-%d: ", game.line, game.column);
			scanf("%d %d", &guess.line, &guess.column);
		}

		guessCount++;

		switch(guessCount)
		{
			case 1:
				strcpy(ek, "st");
				break;
			case 2:
				strcpy(ek, "nd");
				break;
			case 3:
				strcpy(ek, "rd");
				break;
			case 4:
				strcpy(ek, "th");
				break;
			case 5:
				strcpy(ek, "th");
				break;
		}

		if(guess.line==chosen.line+1 && guess.column==chosen.column+1)
		{
			system("cls");
			printf("CONGRATULATIONS!\nYou've finded the circle at %d%s try.\n\n\n", guessCount, ek);
			
			gridShown[chosen.line][chosen.column]='O';
			for (il=0 ; il<=game.line-1 ; il++)
			{
				for (ic=0 ; ic<=game.column-1 ; ic++)
				{
					printf("  %c ", gridShown[il][ic]);
				}
				printf("\n\n");
			}
			gameOn=0;
		}

		else
		{
			if(guess.line>chosen.line+1){dir.line=1;}
			if(guess.line==chosen.line+1){dir.line=2;}
			if(guess.line<chosen.line+1){dir.line=3;}

			if(guess.column>chosen.column+1){dir.column=1;}
			if(guess.column==chosen.column+1){dir.column=2;}
			if(guess.column<chosen.column+1){dir.column=3;}

			switch(dir.line)
			{
				case 1:
					strcpy(direction, " top ");
					break;

				case 2:
					strcpy(direction, " ");
					break;

				case 3:
					strcpy(direction, " bottom ");
					break;
			}

			switch(dir.column)
			{
				case 1:
					strcat(direction, "left ");
					break;

				case 2:
					strcat(direction, " ");
					break;

				case 3:
					strcat(direction, "right ");
					break;
			}

			
			gridShown[guess.line-1][guess.column-1]='X';
			gameOn=2;
		}

		if(guessCount==5)
		{
			gameOn=3;
		}

	}

	if (gameOn==3)
	{
		system("cls");
		printf("You couldn't find the X but thank you for playing!\n");
	}

	
	system("pause");
	
	return 0;
}