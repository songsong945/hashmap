//
// Created by 莫松松 on 2022/7/26.
//

#include "util.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

static char**
_strsplit( const char* s, const char* delim, size_t* nb )
{
    void* data;
    char* _s = ( char* )s;
    const char** ptrs;
    size_t
            ptrsSize,
            nbWords = 1,
            sLen = strlen( s ),
            delimLen = strlen( delim );

    while ( ( _s = strstr( _s, delim ) ) ) {
        _s += delimLen;
        ++nbWords;
    }
    ptrsSize = ( nbWords + 1 ) * sizeof( char* );
    ptrs =
    data = malloc( ptrsSize + sLen + 1 );
    if ( data ) {
        *ptrs =
        _s = strcpy( ( ( char* )data ) + ptrsSize, s );
        if ( nbWords > 1 ) {
            while ( ( _s = strstr( _s, delim ) ) ) {
                *_s = '\0';
                _s += delimLen;
                *++ptrs = _s;
            }
        }
        *++ptrs = NULL;
    }
    if ( nb ) {
        *nb = data ? nbWords : 0;
    }
    return data;
}

char**
strsplit( const char* s, const char* delim )
{
    return _strsplit( s, delim, NULL );
}

char**
strsplit_count( const char* s, const char* delim, size_t* nb )
{
    return _strsplit( s, delim, nb );
}


char*
hashmap2str(Hashmap2* hashmap)
{
    char* key;
    char* val;
    char* tag = ":";

    int len = 0;
    int pos = 0;

    hashmap_foreach(key, val, hashmap) {
        len = len + strlen(key) + strlen(val) + 2;
    }

    char* result = (char*) malloc(sizeof(char)*len);

    hashmap_foreach(key, val, hashmap) {
        if(pos == 0){
            strcat(result, key);
            strcat(result, tag);
            strcat(result, val);
            pos = 1;
        } else{
            strcat(result, tag);
            strcat(result, key);
            strcat(result, tag);
            strcat(result, val);
        }

    }
    return result;
}

void
str2hashmap(char* strmap, Hashmap2* hashmap)
{
    int nb = 0;
    char** map = strsplit_count(strmap, ":", &nb);

    for(int i=0; i < nb/2; i++)
    {
        hashmap_put(hashmap, map[2*i], map[2*i+1]);
    }
}