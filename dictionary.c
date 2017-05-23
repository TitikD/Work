/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define INDEX(c) ((int)c - (int)'a')
#define ALPHABET 27
#include "dictionary.h"


struct node
{
    bool end;
    struct node* next[ALPHABET];

};
struct node* root;

int convert(char a)
{
    if(islower(a))
    {
        return ((int)a - 97);  
    }else 
    if(isupper(a))
    {
        return (((int) a + 32)-97);
    }else
    {
        return 26;
    }
}

int sizeDict = 0;
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    root = calloc(1,sizeof(struct node));
    struct node* curRoot = root;
    const char* open = NULL;
    if(dictionary == NULL)
    {
        open = "/home/cs50/pset5/dictionaries/large";
    }else
    {
        open = dictionary;
    }
    char maxW[LENGTH];
    
    char* minW = NULL;
    FILE* fo = fopen(open, "r");
    if(!fo)
    {
        return false;
    }
    while(fscanf(fo, "%s", maxW) > 0)
    {
        minW = maxW;
        for(int i = 0, n = strlen(minW); n > i;i++)
        {
            int indx = INDEX(minW[i]);
            if(indx < 0)
                indx = 26;
            if(!curRoot->next[indx])
            {
                curRoot->next[indx] = calloc(1,sizeof(struct node));;
            }
            curRoot = curRoot->next[indx]; 
        }
        curRoot->end = true;
        sizeDict++;
        curRoot = root;
    }
    fclose(fo);
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    struct node* curRoot = root;
    int n = strlen(word);
    for(int i = 0; n > i; i++)
    {
        int index = convert(word[i]);
        if(curRoot->next[index])
        {
            curRoot = curRoot->next[index];
        }else
        {
            return false;
        }
    }
    if(curRoot->end == true)
    {
        return true;
    }else
    {
        return false;
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return sizeDict;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
void unloadNode(struct node* curRoot)
{
    for(int i = 0; ALPHABET > i;i++)
    {
        if(curRoot->next[i])
        {
            unloadNode(curRoot->next[i]);
        }
        
    }
    free(curRoot);
}
bool unload(void)
{
    unloadNode(root);
    return true;
}


