// Fresh Random Civ Picker
// (C) Hjoerleif 2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

bool parse_int(char *string, int *integer);

char *civ_name(int index);
int result(int);
void resetter(int *);

int main()
{
	printf("Welcome to the Fresh Random Civ Picker for AoE2DE!\nThis free program was made by Hjoerleif. Donate: https://ko-fi.com/hjoerleif\n\n");

	int input = 0;
	int available[45];
	int given_index;
	bool parsed_correct = true;
	
	
	resetter(&available);
	
	int iterator = 0;
	int remaining = 45;
	do
	{

		do
		{
			printf("\nEnter 1 to receive a fresh random civ, 0 to reset, or -1 to quit: ");
			char buffer[BUFFER_SIZE];
			fgets(buffer, BUFFER_SIZE, stdin);
			parsed_correct = parse_int(buffer, &input);
			if (!parsed_correct || input != -1 && input != 0 && input != 1) printf("\nInvalid input. Please try again.\n");
		} while (!parsed_correct || input != -1 && input != 0 && input != 1);

		if (input == -1) return 0;
		given_index = result(remaining);
		int j = 0;
		int i = 0;
		while (i < 45) {
			while (available[j] != 1) j++;
			if (i == given_index) {
					given_index = j;
					break;
			}
			j++;
			i++;

		}
		if (input == 1)
		{
			printf("\n%s (current set: %d/%d)\n", civ_name(given_index), iterator + 1, 45);
			available[given_index] = 0;
			iterator++;
			remaining--;
		}
		if (iterator == 45 || input == 0)
		{
			printf("\nProgram has been reset.\n");
			iterator = 0;
			resetter(&available);
			remaining = 45;
		}
	} while (input != -1);
	return 0;
}

bool parse_int(char *string, int *integer)
{
	int i = 0;
	while (isspace(string[i])) i++;
	int length = strlen(string);
	if (length == i) return false;
	char integer_buffer[BUFFER_SIZE];
	int integer_chars = 0;
	if (string[i] == '-')
	{
		integer_buffer[integer_chars] = '-';
		integer_chars++;
		i++;
		if (!isdigit(string[i])) return false;
	}

	while (i < length && !isspace(string[i]))
	{
		if (!isdigit(string[i])) return false;
		integer_buffer[integer_chars] = string[i];
		integer_chars++;
		i++;
	}
	integer_buffer[integer_chars] = '\0';
	while (isspace(string[i])) i++;
	if (string[i] != '\0') return false;
	*integer = atoi(integer_buffer);
	return true;
}

int result(int max)
{
	int result = -1;
	srand(time(NULL));
	result = rand() % max;
	return result;
}

char *civ_name(int index)
{
	switch (index)
	{
	case 0:
		return "Armenians";
		break;
	case 1:
		return "Aztecs";
		break;
	case 2:
		return "Bengalis";
		break;
	case 3:
		return "Berbers";
		break;
	case 4:
		return "Bohemians";
		break;
	case 5:
		return "Britons";
		break;
	case 6:
		return "Bulgarians";
		break;
	case 7:
		return "Burgundians";
		break;
	case 8:
		return "Burmese";
		break;
	case 9:
		return "Byzantines";
		break;
	case 10:
		return "Celts";
		break;
	case 11:
		return "Chinese";
		break;
	case 12:
		return "Cumans";
		break;
	case 13:
		return "Dravidians";
		break;
	case 14:
		return "Ethiopians";
		break;
	case 15:
		return "Franks";
		break;
	case 16:
		return "Georgians";
		break;
	case 17:
		return "Goths";
		break;
	case 18:
		return "Gurjaras";
		break;
	case 19:
		return "Hindustanis";
		break;
	case 20:
		return "Huns";
		break;
	case 21:
		return "Incas";
		break;
	case 22:
		return "Italians";
		break;
	case 23:
		return "Japanese";
		break;
	case 24:
		return "Khmer";
		break;
	case 25:
		return "Koreans";
		break;
	case 26:
		return "Lithuanians";
		break;
	case 27:
		return "Magyars";
		break;
	case 28:
		return "Malay";
		break;
	case 29:
		return "Malians";
		break;
	case 30:
		return "Mayans";
		break;
	case 31:
		return "Mongols";
		break;
	case 32:
		return "Persians";
		break;
	case 33:
		return "Poles";
		break;
	case 34:
		return "Portuguese";
		break;
	case 35:
		return "Romans";
		break;
	case 36:
		return "Saracens";
		break;
	case 37:
		return "Sicilians";
		break;
	case 38:
		return "Slavs";
		break;
	case 39:
		return "Spanish";
		break;
	case 40:
		return "Tatars";
		break;
	case 41:
		return "Teutons";
		break;
	case 42:
		return "Turks";
		break;
	case 43:
		return "Vietnamese";
		break;
	case 44:
		return "Vikings";
		break;
	default:
		return "(no civ chosen)";
	}
}

void resetter(int *ptr)
{
	for (int i = 0; i < 45; i++)
	{
		ptr[i] = 1;
	}
}