#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
  char* data;
};

struct sentence {
  struct word* data;
  int word_count;  // denotes number of words in a sentence
};

struct paragraph {
  struct sentence* data;
  int sentence_count;  // denotes number of sentences in a paragraph
};

struct document {
  struct paragraph* data;
  int paragraph_count;  // denotes number of paragraphs in a document
};
typedef struct document document;
typedef struct paragraph paragraph;
typedef struct sentence sentence;
typedef struct word word;

struct document get_document(char* text) {
  document dstruct;
  dstruct.data = (paragraph*)malloc(MAX_PARAGRAPHS * sizeof(paragraph));
  dstruct.paragraph_count = 0;

  int pcount = 0;
  char* p = NULL;
  char* prest = text;

  while (p = strtok_r(prest, "\n", &prest)) {
    paragraph pstruct;
    pstruct.data = (sentence*)malloc(MAX_CHARACTERS * sizeof(sentence));
    pstruct.sentence_count = 0;

    int scount = 0;
    char* s = NULL;
    char* srest = p;

    while (s = strtok_r(srest, ".", &srest)) {
      sentence sstruct;
      sstruct.data = (word*)malloc(256 * sizeof(word));
      sstruct.word_count = 0;

      char* wrest = s;
      char* w = NULL;
      int wcount = 0;

      while (w = strtok_r(wrest, " ", &wrest)) {
        word wstruct;
        wstruct.data = (char*)malloc(strlen(w) * sizeof(char));
        wstruct.data = w;
        sstruct.data[wcount++] = wstruct;
        sstruct.word_count = wcount;
      }

      sstruct.data =
          (word*)realloc(sstruct.data, sstruct.word_count * sizeof(word));
      pstruct.data[scount++] = sstruct;
      pstruct.sentence_count = scount;
    }

    pstruct.data = (sentence*)realloc(
        pstruct.data, pstruct.sentence_count * sizeof(sentence));
    dstruct.data[pcount++] = pstruct;
    dstruct.paragraph_count = pcount;
  }

  dstruct.data = (paragraph*)realloc(
      dstruct.data, dstruct.paragraph_count * sizeof(paragraph));

  return dstruct;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc,
                                                      int k, int m, int n) {
  return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k,
                                              int m) {
  return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
  return Doc.data[k - 1];
}
void print_word(struct word w) { printf("%s", w.data); }

void print_sentence(struct sentence sen) {
  for (int i = 0; i < sen.word_count; i++) {
    print_word(sen.data[i]);
    if (i != sen.word_count - 1) {
      printf(" ");
    }
  }
}

void print_paragraph(struct paragraph para) {
  for (int i = 0; i < para.sentence_count; i++) {
    print_sentence(para.data[i]);
    printf(".");
  }
}

void print_document(struct document doc) {
  for (int i = 0; i < doc.paragraph_count; i++) {
    print_paragraph(doc.data[i]);
    if (i != doc.paragraph_count - 1) printf("\n");
  }
}

char* get_input_text() {
  int paragraph_count;
  scanf("%d", &paragraph_count);

  char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
  memset(doc, 0, sizeof(doc));
  getchar();
  for (int i = 0; i < paragraph_count; i++) {
    scanf("%[^\n]%*c", p[i]);
    strcat(doc, p[i]);
    if (i != paragraph_count - 1) strcat(doc, "\n");
  }

  char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
  strcpy(returnDoc, doc);
  return returnDoc;
}

int main() {
  char* text = get_input_text();
  struct document Doc = get_document(text);

  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 3) {
      int k, m, n;
      scanf("%d %d %d", &k, &m, &n);
      struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
      print_word(w);
    }

    else if (type == 2) {
      int k, m;
      scanf("%d %d", &k, &m);
      struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
      print_sentence(sen);
    }

    else {
      int k;
      scanf("%d", &k);
      struct paragraph para = kth_paragraph(Doc, k);
      print_paragraph(para);
    }
    printf("\n");
  }
}