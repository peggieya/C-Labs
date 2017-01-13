\//
// APS105-F15 Lab 8 Lab8.c
//
// This is a program written to maintain a personal music library,
// using a linked list to hold the songs in the library.
//
// Author: <Yalan Zhang>
// Student Number: <1002220857>
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.

typedef struct node
{
    char *songName;
    char *artist;
    char *genre;
    struct node *link;
} Node;

Node *pHead;
int iCount = 0;

// Declarations of linked list functions
//
// Declare your own linked list functions here.
//
// ADD YOUR STATEMENT(S) HERE

// Declarations of support functions
// See below the main function for descriptions of what these functions do

void getStringFromUserInput(char s[], int arraySize);
void songNameDuplicate(char songName[]);
void songNameFound(char songName[]);
void songNameNotFound(char songName[]);
void songNameDeleted(char songName[]);
void artistFound(char artist[]);
void artistNotFound(char artist[]);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);
Node *Delete(Node *pHead, char* songEnter);
Node *addSong(Node *pHead);
void searchForSong(Node *pHead, char* songEnter);
void printLib(Node *pHead);
void deletAllNode(Node *pHead);

const int MAX_LENGTH = 1024;

int main(void)
{
    // Declare the head of the linked list.
    // ADD YOUR STATEMENT(S) HERE
    // Announce the start of the program
    printf("%s", "Personal Music Library.\n\n");
    printf("%s",
           "Commands are I (insert), D (delete), S (search by song name),\n"
           "P (print), Q (quit).\n");
    
    char response;
    char songEnter[MAX_LENGTH + 1];
    char input[MAX_LENGTH + 1];
    
    do
    {
        printf("\nCommand?: ");
        getStringFromUserInput(input, MAX_LENGTH);
        response = toupper(input[0]);
        
        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        
        if (response == 'I')
        {
            // Insert a song into the linked list.
            // Maintain the list in alphabetical order by song name.
            //   ADD STATEMENT(S) HERE
            
            pHead = addSong(pHead);
            
        } else if (response == 'D')
        {
            // Delete a song from the list.
            
            printf("\nEnter the name of the song to be deleted: ");
            getStringFromUserInput(songEnter, MAX_LENGTH);
            pHead = Delete(pHead, songEnter);
            
            //   ADD STATEMENT(S) HERE
            
        } else if (response == 'S')
        {
            // Search for a song by its name.
            
            printf("\nEnter the name of the song to search for: ");
            getStringFromUserInput(songEnter, MAX_LENGTH);
            searchForSong(pHead, songEnter);
            //   ADD STATEMENT(S) HERE
            
        } else if (response == 'P')
        {
            // Print the music library.
            if (iCount == 0)
            {
                printMusicLibraryEmpty();
            } else
            {
                printLib(pHead);
            }
            
            //   ADD STATEMENT(S) HERE
            
        } else if (response == 'Q')
        {
            ; // do nothing, we'll catch this below
        } else
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n");
        }
    } while (response != 'Q');
    
    // Delete the entire linked list.
    //   ADD STATEMENT(S) HERE
    deletAllNode(pHead);
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
    
    return 0;
}

// Support Function Definitions

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

//When user enter Q
//Free all memory
void deletAllNode(Node *pHead)
{
    int n = iCount;
    while (n != 0)
    {
        Node *node = pHead;
        pHead = pHead->link;
        songNameDeleted(node->songName);
        free(node->songName);
        free(node->artist);
        free(node->genre);
        free(node);
        n--;
    }
    
    printf("\nThe music library is empty.\n");
    
}

//This function free a certain node
Node *Delete(Node *pHead, char* songEnter)
{
    if (pHead == NULL)
        return NULL;
    
    // If the first node is to be deleted
    if (strcmp(pHead->songName, songEnter) == 0)
    {
        Node *secondNode = pHead->link;
        songNameDeleted(secondNode->songName);
        free(pHead->songName);
        free(pHead->artist);
        free(pHead->genre);
        free(pHead);
        iCount--;
        return secondNode;
    }
    
    //Not find the song to be deleted
    int found = 0;
    Node *current = pHead;
    
    while (!found && current->link != NULL)
    {
        if (strcmp(current->link->songName, songEnter) == 0)
            found = 1;
        else
            current = current->link;
    }
    
    // if there exists a node to be deleted
    if (current->link != NULL)
    {
        Node *nodeToRemove = current->link;
        current->link = current->link->link;
        songNameDeleted(nodeToRemove->songName);
        free(nodeToRemove->songName);
        free(nodeToRemove->artist);
        free(nodeToRemove->genre);
        free(nodeToRemove);
        iCount--;
    }
    
    return pHead;
}

//This function match the song enter with the list
void searchForSong(Node *pHead, char* songEnter)
{
    
    int n = iCount;
    while (n != 0)
    {
        if (strcmp(pHead->songName, songEnter) == 0)
        {
            songNameFound(songEnter);
            printf("\n%s", pHead->songName);
            printf("\n%s", pHead->artist);
            printf("\n%s\n", pHead->genre);
            
            return;
        } else
        {
            pHead = pHead->link;
            n--;
        }
    }
    
    if (n == 0)
    {
        songNameNotFound(songEnter);
        
        return;
    }
}

//This function print the list
void printLib(Node *pHead)
{
    
    Node *curr = pHead;
    
    printMusicLibraryTitle();
    
    while (curr!=NULL)
    {
        printf("\n%s", curr->songName);
        printf("\n%s", curr->artist);
        printf("\n%s\n", curr->genre);
        curr = curr->link;
    }
}

//This function add a new node to the list
Node *addSong(Node *pHead)
{
    char* songName = malloc(MAX_LENGTH + 1);
    char* artist = malloc(MAX_LENGTH + 1);
    char* genre = malloc(MAX_LENGTH + 1);
    
    printf("Song name: ");
    getStringFromUserInput(songName, MAX_LENGTH);
    
    printf("Artist: ");
    getStringFromUserInput(artist, MAX_LENGTH);
    
    printf("Genre: ");
    getStringFromUserInput(genre, MAX_LENGTH);
    
    int n = iCount;
    Node* node = pHead;
    
    //If the song entered already in list
    while (n != 0)
    {
        if (strcmp(node->songName, songName) == 0)
        {
            songNameDuplicate(songName);
            free(songName);
            free(artist);
            free(genre);
            return pHead;
        } else
        {
            node = node->link;
            n--;
        }
    }
    
    if (pHead == NULL || strcmp(songName, pHead->songName) < 0)
    {
        Node *node = (Node *) malloc(sizeof(Node));
        
        node->songName = songName;
        node->artist = artist;
        node->genre = genre;
        node->link = pHead;
        iCount++;
        return node;
    }
    
    Node *current = pHead;
    
    while (current->link != NULL
           && strcmp(songName, current->link->songName) > 0)
        current = current->link;
    
    node = (Node *) malloc(sizeof(Node));
    
    node->songName = songName;
    node->artist = artist;
    node->genre = genre;
    node->link = current->link;
    current->link = node;
    iCount++;
    return pHead;
}
