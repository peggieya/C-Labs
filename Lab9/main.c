#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// A node in the linked list
// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.

#define MAX_LENGTH  1024

typedef struct song
{
    char songName[MAX_LENGTH];
    char artist[MAX_LENGTH];
} Song;

void getStringFromUserInput(char s[], int arraySize);
void songNameDuplicate(char songName[]);
void songNameFound(char songName[]);
void songNameNotFound(char songName[]);
void songNameDeleted(char songName[]);
void artistFound(char artist[]);
void artistNotFound(char artist[]);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);

Song* search(Song lib[], int count, char songName[]);

void cocktailSort(Song library[], int size);

int main(void)
{
    // Declare the head of the linked list.
    
    //   ADD YOUR STATEMENT(S) HERE
    const int MAX_LIBRARY_SIZE = 100;
    Song Library[MAX_LIBRARY_SIZE];
    int count = 0;
    
    // Announce the start of the program
    printf("%s", "Personal Music Library.\n\n");
    printf("%s", "Commands are I (insert), S (sort by artist),\n"
           "P (print), Q (quit).\n");
    
    char response;
    char input[MAX_LENGTH + 1];
    do
    {
        printf("\nCommand?: ");
        getStringFromUserInput(input, MAX_LENGTH);
        
        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);
        
        if (response == 'I')
        {
            // Insert a song into the linked list.
            // Maintain the list in alphabetical order by song name.
            //   ADD STATEMENT(S) HERE
            Song song;
            printf("Song name: ");
            getStringFromUserInput(song.songName, MAX_LENGTH - 1);
            printf("Artist: ");
            
            getStringFromUserInput(song.artist, MAX_LENGTH - 1);
            
            if (search(Library, count, song.songName))
            {
                songNameDuplicate(song.songName);
            } else
            {
                Library[count] = song;
                count++;
            }
            
        } else if (response == 'S')
        {
            //   ADD STATEMENT(S) HERE
            cocktailSort(Library, count);
            if (count == 0)
            {
                printMusicLibraryEmpty();
                continue;
            }
            printf("\nMy Personal Music Library:\n");
            
            int i;
            for (i = 0; i < count; i++)
            {
                printf("\n%s\n%s\n", Library[i].songName, Library[i].artist);
            }
            
        } else if (response == 'P')
        {
            // Print the music library.
            if (count == 0)
            {
                printMusicLibraryEmpty();
                continue;
            }
            printf("\nMy Personal Music Library:\n");
            
            int i;
            for (i = 0; i < count; i++)
            {
                printf("\n%s\n%s\n", Library[i].songName, Library[i].artist);
            }
            
        } else if (response == 'Q')
        {
            ; // do nothing, we'll catch this below
        } else
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n");
        }
    } while (response != 'Q');
    
    return 0;
}

// Prompt the user for a string safely, without buffer overflow
void getStringFromUserInput(char s[], int maxStrLength)
{
    int i = 0;
    char c;
    
    while (i < maxStrLength && (c = getchar()) != '\n')
        s[i++] = c;
    
    s[i] = '\0';
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate(char songName[])
{
    printf("\nA song with the name '%s' is already in the music library.\n"
           "No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char songName[])
{
    printf("\nThe song name '%s' was found in the music library.\n", songName);
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound(char songName[])
{
    printf("\nThe song name '%s' was not found in the music library.\n",
           songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char songName[])
{
    printf("\nDeleting a song with name '%s' from the music library.\n",
           songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void)
{
    printf("\nThe music library is empty.\n");
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void)
{
    printf("\nMy Personal Music Library: \n");
}

// Add your functions below this line.

//   ADD STATEMENT(S) HERE
Song* search(Song lib[], int count, char songName[])
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (strcmp(lib[i].songName, songName) == 0)
        {
            return &lib[i];
        }
    }
    return NULL;
}

void cocktailSort(Song library[], int size)
{
    int swapped = 1;
    while (swapped != 0)
    {
        swapped = 0;
        int i;
        for (i = 0; i < size - 1; i = i + 1)
        {
            if (strcmp(library[i].artist, library[i + 1].artist) > 0)
            {
                Song song = library[i];
                library[i] = library[i + 1];
                library[i + 1] = song;
                swapped = 1;
            } else if (strcmp(library[i].artist, library[i + 1].artist) == 0)
            {
                if (strcmp(library[i].songName, library[i + 1].songName) > 0)
                {
                    Song song = library[i];
                    library[i] = library[i + 1];
                    library[i + 1] = song;
                    swapped = 1;
                }
            }
        }
        for (i = size - 1; i > 0; i = i - 1)
        {
            if (strcmp(library[i].artist, library[i - 1].artist) < 0)
            {
                Song song = library[i];
                library[i] = library[i - 1];
                library[i - 1] = song;
                swapped = 1;
            } else if (strcmp(library[i].artist, library[i - 1].artist) == 0)
            {
                if (strcmp(library[i].songName, library[i - 1].songName) < 0)
                {
                    Song song = library[i];
                    library[i] = library[i - 1];
                    library[i - 1] = song;
                    swapped = 1;
                }
            }
        }
    }
}
