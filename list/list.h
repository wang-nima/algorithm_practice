#include "types.h"

#pragma once

#define offsetof(type, member) \
        ((uint32_t)((char*)&((type *)(0))->member - (char*)0))


typedef struct list {
        struct list *l_next;
        struct list *l_prev;
} list_t, list_link_t;

#define list_link_init(link)                                            \
        do {                                                            \
                (link)->l_next = (link)->l_prev = NULL;                 \
        } while (0);

#define list_link_is_linked(link)                                       \
        (((link)->l_next != NULL) && ((link)->l_prev != NULL))

#define list_init(list)                                                 \
        do {                                                            \
                (list)->l_next = (list)->l_prev = (list);               \
        } while (0);

#define list_empty(list)                                                \
        ((list)->l_next == (list))

#define list_insert_before(old, new)                                    \
        do {                                                            \
                list_link_t *prev = (new);                              \
                list_link_t *next = (old);                              \
                prev->l_next = next;                                    \
                prev->l_prev = next->l_prev;                            \
                next->l_prev->l_next = prev;                            \
                next->l_prev = prev;                                    \
        } while(0)

#define list_insert_head(list, link)                                    \
        list_insert_before((list)->l_next, link)

#define list_insert_tail(list, link)                                    \
        list_insert_before(list, link)

#define list_remove(link)                                               \
        do {                                                            \
                list_link_t *ll = (link);                               \
                list_link_t *prev = ll->l_prev;                         \
                list_link_t *next = ll->l_next;                         \
                prev->l_next = next;                                    \
                next->l_prev = prev;                                    \
                ll->l_next = ll->l_prev = NULL;                         \
        } while(0)

#define list_remove_head(list)                                          \
        list_remove((list)->l_next)

#define list_remove_tail(list)                                          \
        list_remove((list)->l_prev)

#define list_item(link, type, member)                                   \
        (type*)((char*)(link) - offsetof(type, member))

#define list_head(list, type, member)                                   \
        list_item((list)->l_next, type, member)

#define list_tail(list, type, member)                                   \
        list_item((list)->l_prev, type, member)

#define list_iterate_begin(list, var, type, member)                     \
        do {                                                            \
                list_link_t *__link;                                    \
                list_link_t *__next;                                    \
                for (__link = (list)->l_next;                           \
                     __link != (list);                                  \
                     __link = __next) {                                 \
                        var = list_item(__link, type, member);          \
                        __next = __link->l_next;                        \
                        do

#define list_iterate_reverse(list, var, type, member)                   \
        do {                                                            \
                list_link_t *__link;                                    \
                list_link_t *__prev;                                    \
                for (__link = (list)->l_prev;                           \
                     __link != (list);                                  \
                     __link = __prev) {                                 \
                        var = list_item(__link, type, member);          \
                        __prev = __link->l_prev;                        \
                        do

#define list_iterate_end()                                              \
                        while(0);                                       \
                }                                                       \
        } while(0)
