//
// Created by 莫松松 on 2022/7/26.
//

#ifndef HASHMAP_UTIL_H
#define HASHMAP_UTIL_H

#include "hashmap.h"

typedef HASHMAP(void, void) Hashmap2;

char** strsplit( const char* s, const char* delim );
char** strsplit_count( const char* s, const char* delim, size_t* nb );

char* hashmap2str(Hashmap2* hashmap);
void str2hashmap(char* strmap, Hashmap2* hashmap);

#endif //HASHMAP_UTIL_H
