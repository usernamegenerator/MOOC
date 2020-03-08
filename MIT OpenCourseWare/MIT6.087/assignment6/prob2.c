/*
 * prob2.c
 *
 *  Created on:
 *      Author:
 */

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* the trie node data structure */
struct s_trie_node
{
	char * translation; /* NULL if node not a word */

	/* pointer array to child nodes */
	struct s_trie_node * children[UCHAR_MAX+1];
};

/* pointer to the root node of the trie structure */
static struct s_trie_node * proot = NULL;

/* helper functions for trie structure */

/* allocate new node on the heap
   output: pointer to new node (must be freed) */
struct s_trie_node * new_node(void);

/* delete node and all its children
   input: pointer to node to delete
   postcondition: node and children are freed */
void delete_node(struct s_trie_node * pnode);

/* add word to trie, with translation
   input: word and translation
   output: non-zero if new node added, zero otherwise
   postcondition: word exists in trie */
int add_word(const char * word, char * translation);

/* read dictionary file into trie structure */
unsigned int load_dictionary(const char * filename);

/* search trie structure for word and return translations
   input: word to search
   output: translation, or NULL if not found */
char * lookup_word(const char * word);

/* maximum number of characters for word to search */
#define WORD_MAX 256

/* maximum number of characters in line */
#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

/* main function */
int main(int argc, char * argv[]) {
	char word[WORD_MAX], * translation;
	int len;

	if (argc <= 1)
		return 0; /* no dictionary specified */

	/* load dictionary */
	proot = new_node();
	load_dictionary(argv[1]);

	do {
		printf("Enter word to translate: ");
		fflush(stdout);
		if (!fgets(word, WORD_MAX, stdin))
			abort();

		/* strip trailing newline */
		len = strlen(word);
		if (len > 0 && word[len-1] == '\n') {
			word[len-1] = '\0';
			--len;
		}

		/* exit on empty string */
		if (len == 0)
			break;

		/* lookup word */
		translation = lookup_word(word);

		if (translation)
			printf("%s -> %s\n", word, translation);
		else
			printf("\"%s\" not found\n", word);
	} while (1);

	/* clean up trie structure */
	delete_node(proot);

	return 0;
}

/* allocate new node on the heap
   output: pointer to new node (must be freed) */
struct s_trie_node * new_node(void) {
	/* TODO: allocate a new node on the heap, and
	   initialize all fields to default values */
	   struct s_trie_node * newNode = (struct s_trie_node *)malloc(sizeof(struct s_trie_node));
	   //printf("sizeof(struct s_trie_node) %lu\n",sizeof(struct s_trie_node));
	   int i;
	   newNode->translation = NULL;
	   for(i=0;i<UCHAR_MAX;i++)
            newNode->children[i] = NULL;
}

/* delete node and all its children
   input: pointer to node to delete
   postcondition: node and children are freed */
void delete_node(struct s_trie_node * pnode) {
	/* TODO: delete node and all its children
	   Be sure to free non-null translations!
	   Hint: use recursion
	 */
	 int i;
	 if(pnode->translation!=NULL)
                free(pnode->translation);

	 for(i=0;i<UCHAR_MAX;i++)
     {
        if(pnode->children[i]!=NULL)
        {
            delete_node(pnode->children[i]);
        }
     }
     free(pnode);
}


/* add word to trie, with translation
   input: word and translation
   output: non-zero if new node added, zero otherwise
   postcondition: word exists in trie */
int add_word(const char * word, char * translation) {
	/* TODO: add word to trie structure
	   If word exists, append translation to existing
	   string
	   Be sure to store a copy of translation, since
	   the string is reused by load_dictionary()
	 */

     int len_word = strlen(word);
     int len_translation = strlen(translation);
     int i;
     struct s_trie_node * temp_root = proot;
     //use letter's ascii number as the index of the children
     for(i=0;i<len_word;i++)
     {
         int index = (int)word[i];
         //printf("%c\n",word[i]);
         if(temp_root->children[index] == NULL)
         {
            temp_root->children[index] = new_node();
         }
         temp_root = temp_root->children[index];

         if(i==len_word-1)
         {
            temp_root->translation = (char*)malloc(sizeof(char)*len_translation);
            memcpy(temp_root->translation,translation,sizeof(char)*len_translation);
         }

         if(temp_root->translation == NULL)
         {
            //printf("<add_word> NULL TRANSLATION\n");
         }
         else
         {
             //printf("<add_word> TRANSLATE TO %s\n",temp_root->translation);
         }

     }

}

/* delimiter for dictionary */
#define DELIMS "\t"

/* read dictionary file into trie structure */
unsigned int load_dictionary(const char * filename) {
	FILE * pfile;
	char line[LINE_MAX], * word, * translation;
	unsigned int icount = 0;

	/* ensure file can be opened */
	if ( !(pfile = fopen(filename,"r")) )
		return icount;

	/* read lines */
	while ( (fgets(line, LINE_MAX, pfile)) ) {
		/* strip trailing newline */
		int len = strlen(line);
		if (len > 0 && line[len-1] == '\n') {
			line[len-1] = '\0';
			--len;
		}

		if (len == 0 || line[0] == '#')
			continue; /* ignore comment/empty lines */

		/* separate word and translation */
		word = line + strspn(line, DELIMS);
		if ( !word[0] )
			continue; /* no word in line */
		translation = word + strcspn(word, DELIMS);
		*translation++ = '\0';
		translation += strspn(translation, DELIMS);

		/* add word to trie */
		//printf("<load_dictionary> word = %s, translation = %s\n",word,translation);
		if (add_word(word, translation))
			icount++;
	}

	/* finish */
	fclose(pfile);
	return icount;
}

/* search trie structure for word and return translations
   input: word to search
   output: translation, or NULL if not found */
char * lookup_word(const char * word) {
	/* TODO: search trie structure for word
	   return NULL if word is not found */

       int len_word = strlen(word);
       char * translation = NULL;
       int i;
       struct s_trie_node * temp_root = proot;

       for(i=0;i<len_word;i++)
       {
           int index = (int)word[i];
           if(temp_root->children[index] == NULL)
           {
               //printf("<lookup_word> Null children at %c\n",word[i]);
               return NULL;

           }
           temp_root = temp_root->children[index];
           if(i==len_word-1)
           {
               //printf("%s\n",temp_root->translation);
               return temp_root->translation;
           }
       }
}

