#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Trie
{
int isWord;//0/1
struct Trie* next[26];
};

void insert(struct Trie **ppTrie, char *word)
{
    int k = 0;
    int length = strlen(word);
        // Down to the end, insert the word.
    // See if the next place to go exists, if not, create it.
    for (int k = 0; k < length; k++)
    {
        if (k == strlen(word)-1)
        {
          (*ppTrie)->isWord = 1;
            return;
        }
        int nextIndex = word[k] - 'a';
        if ((*ppTrie)->next[nextIndex] == NULL)
        {
            struct Trie *temp = malloc(sizeof(struct Trie));
            for (int i = 0; i < 26; i++)
            {
                temp->next[i] = NULL;
            }
          (*ppTrie)->next[nextIndex] = temp;
        (*ppTrie)=(*ppTrie)->next[nextIndex];
        }

    }
}
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    int k = 0;
    int length = strlen(word);
    for (int k = 0; k < length; k++)
    {
        if (k == length-1)
        {
            return (pTrie->isWord);
        }
        int nextIndex = word[k] - 'a';
        if(pTrie->next[nextIndex] != NULL)
        {
          pTrie = pTrie->next[nextIndex];
        }

    }
}
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    int i;
    for (i=0; i<26; i++)
        if (pTrie->next[i] != NULL)
            deallocateTrie(pTrie->next[i]);

    free(pTrie);
    return NULL;
}

int main(void)
{
      struct Trie *temp = malloc(sizeof(struct Trie));
                  for (int i = 0; i < 26; i++)
            {
                temp->next[i] = NULL;
            }
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
            for (int i=0;i<5;i++)
      {
          insert(&temp, pWords[i]);
     }
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(temp, pWords[i]));
     }
    temp = deallocateTrie(temp);
    if (temp != NULL)
       printf("There is an error in this program\n");
    return 0;
}
