#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct wordStat
{
	char name[40];
	int count;
};

/* Function pointer type */
typedef void (*AnalysisFunction)(struct wordStat *, int);

void count_words(struct wordStat *words, int word_count)
{
	int total = 0;

	for (int i = 0; i < word_count; i++)
		total += words[i].count;

	 printf("Total words: %d\n", total);
}

void longest_word(struct wordStat *words, int word_count)
{
	int max = 0;
	char longest[40] = "";

	for (int i = 0; i < word_count; i++) 
	{
		if ((int)strlen(words[i].name) > max)
		{
			max = strlen(words[i].name);
			strcpy(longest, words[i].name);
		}
	}

	printf("Longest word: %s (%d letters)\n", longest, max);
}

void most_frequent(struct wordStat *words, int word_count)
{
	int max = 0;
	char frequent[40] = "";

	for (int i = 0; i < word_count; i++) 
	{
		if (words[i].count > max) {
			max = words[i].count;
			strcpy(frequent, words[i].name);
		}
	}

	printf("Most frequent word: %s (%d times)\n", frequent, max);
}

void avg_word_len(struct wordStat *words, int word_count)
{
	int totalLetters = 0;
	int totalWords = 0;

	for (int i = 0; i < word_count; i++) 
	{
		totalLetters += strlen(words[i].name) * words[i].count;
		totalWords += words[i].count;
	}

	double average = (double)totalLetters / totalWords;

	printf("Average word length: %.2f characters\n", average);
}

int main()
{
	char buffer[5000];
	char *paragraph = NULL;
	char *ptr;

	int len;
	int word_count = 0;

	printf("Enter the paragraph to analyse: \n");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0'; /* replace consumed '\n' with '\0' */

	len = strlen(buffer);
	paragraph = malloc((len + 1) * sizeof(char));

	if (paragraph == NULL) 
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	strcpy(paragraph, buffer);

	struct wordStat *words = malloc(sizeof(struct wordStat) * len);

	if (words == NULL) 
	{
		printf("Memory allocation failed.\n");
		free(paragraph);
		return 1;
	}

	ptr = paragraph;

	while (*ptr != '\0')
	{
		while (*ptr != '\0' && !isalnum(*ptr))
			ptr++;

		if (*ptr == '\0')
			break;

		char temp[40]; /* store current word */
		int index = 0;

		 /* Read one word */
		while (*ptr != '\0' && isalnum(*ptr))
		{
			temp[index++] = tolower(*ptr);
			ptr++;
		}

		temp[index] = '\0';

		int found = 0; /* check if word existed */

		 /* Search for existing word */
		for (int i = 0; i < word_count; i++)
		{
			if (strcmp(words[i].name, temp) == 0)
			{
				words[i].count++;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			strcpy(words[word_count].name, temp);
			words[word_count].count = 1;
			word_count++;
		}
	}

	// Memory addresses
	printf("\nMemory Addresses:\n");
	printf("Word array stored at: %p\n", paragraph);
	printf("Word statistics array stored at: %p\n", words);

	// Function pointers
	AnalysisFunction analyses[] = {count_words, longest_word, most_frequent, avg_word_len};


	printf("\nAnalysis Results\n");
	for (int i = 0; i < 4; i++)
	 {
		 analyses[i](words, word_count);
	 }

	 free(paragraph);
	 free(words);

	 return(0);
}
