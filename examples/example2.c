//
// Created by 莫松松 on 2022/7/21.
//

#include "hashmap.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

typedef HASHMAP(void, void) Hashmap;

void test_add(Hashmap* map)
{
    char *key = "123";
    char *value = "abc";
    hashmap_put(map, key, value);
}

void test_read(Hashmap* map)
{
    char *value = hashmap_get(map,"123");
    printf("%s\n", value);
}

int main()
{
    HASHMAP(char, char) map;
    HASHMAP(char, char) map2;

    hashmap_init(&map, hashmap_hash_string, strcmp);
    hashmap_init(&map2, hashmap_hash_string, strcmp);

    test_add(&map);
    char* strmap = hashmap2str(&map);
    printf("%s\n", strmap);
    str2hashmap(strmap, &map2);
    test_read(&map2);

    return 0;
}

