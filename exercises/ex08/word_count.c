#include <stdlib.h>
#include <stdio.h>
#include <glib.h>

typedef struct {
    gint * count;
    gchar * word;
} word_count;

FILE * fp;
GHashTable* hash;
GSList * list;

gint compare (gconstpointer a, gconstpointer b){
    word_count * wc_a = (word_count *) a;
    word_count * wc_b = (word_count *) b;
    return *(wc_a->count) - *(wc_b->count);
}

void add_to_list(gpointer key, gpointer value, gpointer user_data) {
    word_count * wc = (word_count*)malloc(sizeof(word_count));
    wc->count = (gint*)value;
    wc->word = (gchar*)key;
    list = g_slist_insert_sorted(list, wc, compare);
}

void iterator(gpointer value, gpointer user_data) {
    word_count * wc = (word_count *) value;
    printf(user_data, wc->word, *(wc->count));
}

int main(int argc, char** argv) {
    if(argc > 1) {
	fp = fopen(argv[1],"r");
    }
    hash = g_hash_table_new(g_str_hash, g_str_equal);
    list = NULL;
    gchar * read = malloc(sizeof(char)*10);
    gchar * valid_chars = "abcdefghijklmnopqrstuvwxyz'-";
    while(fscanf(fp,"%s",read) >0) {
	gchar * word;
	word = g_ascii_strdown(read, -1);
	word = g_strcanon(word, valid_chars, ' ');
	word = g_strstrip(word);
	if(!g_hash_table_contains(hash, word)) {
	    gint * count = g_new(gint, 1);
	    *count = 0;
	    g_hash_table_insert(hash, word, count);
	}
	gint * count = g_hash_table_lookup(hash, word);
	(*count)++;
    }
    g_hash_table_foreach(hash, (GHFunc)add_to_list, list);
    g_slist_foreach(list, (GFunc)iterator, "%s:%d\n");
    g_hash_table_destroy(hash);
    return 0;
}
