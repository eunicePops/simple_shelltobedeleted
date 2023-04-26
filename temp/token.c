#include "shell.h"

/**
 * my_strtoks - this helps split a string into words. delimiters that are 
 * 		repeated are ignored
 * @str: is the input string
 * @delem: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
  
 char* my_strtok(char *str,char *delem) 
 {   char *result=(char *)malloc(sizeof(char)*100);  
         static int position=0; 
         if(!str  !delem  str[position]=='\0')  
         {return NULL;} 
  
  
         //i for indexing the string , j for indexing the delem , k for indexing the result 
         int i=position,j=0,k=0; 
                  
         while(str[i]!='\0') 
         { 
                 j=0; 
                 while(delem[j]!='\0') 
                 { 
                         if(str[i]!=delem[j]) 
                         { 
                                 result[k]=str[i]; 
                         } 
                         else goto ELSE; 
                         j++; 
                 } 
  
         i++; 
         k++; 
         } 
 ELSE: 
                 result[i]='\0'; 
                 position=i+1; 
                 return result;          
  
  
 }
