#include "include/lexer.h"
#include <string.h>
#include <stdlib.h>


lexer_T* init_lexer(char* src)
{
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->i = 0;
    lexer->c = src[lexer->i];
    return lexer;
}

 void lexer_advance(lexer_T* lexer)
 {
     if(lexer->i < lexer->src_size && lexer->c != '\0')
     {
         lexer->i += 1;
         lexer->c = lexer->src[lexer->i]; 
     }
 }

 void lexer_skip_whitespace(lexer_T* lexer)
 {
     while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
     lexer_advance(lexer);
 }

 token_T* lexer_parse_id(lexer_T* lexer)
 {
     char* value = calloc(1, sizeof(char));
     while (isalnum(lexer->c))
     {
          value = realloc(value, (strlen(value) + 2) * sizeof(char));
          strcat(value, (char[]){c, 0});

     }
 }

 token_T* lexer_next_token(lexer_T* lexer)
 {
     while (lexer->c != '\0') 
     {
         if(isalnum(lexer->c))
            return lexer_advance_with(lexer_parse_id(lexer));
     }
 }