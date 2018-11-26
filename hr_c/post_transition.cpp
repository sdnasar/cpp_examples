#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package {
  char* id;
  int weight;
};

typedef struct package package;

struct post_office {
  int min_weight;
  int max_weight;
  package* packages;
  int packages_count;
};

typedef struct post_office post_office;

struct town {
  char* name;
  post_office* offices;
  int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
  printf("%s:\n", t.name);
  for (int i = 0; i < t.offices_count; i++) {
    printf("\t%d:\n", i);
    for (int j = 0; j < t.offices[i].packages_count; j++) {
      printf("\t\t%s\n", t.offices[i].packages[j].id);
    }
  }
}

void send_all_acceptable_packages(town* source, int source_office_index,
                                  town* target, int target_office_index) {
  int target_min_weight = (*target).offices[target_office_index].min_weight;
  int target_max_weight = (*target).offices[target_office_index].max_weight;
  int target_packages_count =
      (*target).offices[target_office_index].packages_count;
  int source_packages_count =
      (*source).offices[source_office_index].packages_count;
  package* target_packages =
      (package*)malloc(sizeof(package) * source_packages_count);
  package* source_packages_to_keep =
      (package*)malloc(sizeof(package) * source_packages_count);
  int packages_moved = 0;
  int packages_to_keep = 0;

  post_office* source_office = &source->offices[source_office_index];
  post_office* target_office = &target->offices[target_office_index];
  for (int i = 0; i < source_office->packages_count; i++) {
    package p = source_office->packages[i];
    if (p.weight >= target_min_weight && p.weight <= target_max_weight) {
      target_packages[packages_moved++] = p;
    } else {
      source_packages_to_keep[packages_to_keep++] = p;
    }
  }
  if (packages_moved > 0) {
    target_office->packages = (package*)realloc(
        target_office->packages,
        (target_packages_count + packages_moved) * sizeof(package));
    int j = 0;
    for (int i = target_packages_count;
         i < (target_packages_count + packages_moved); i++) {
      target_office->packages[i] = target_packages[j++];
    }
    target_office->packages_count = target_packages_count + packages_moved;
  }
  if (packages_to_keep == source_packages_count) return;
  source_office->packages = (package*)realloc(
      source_packages_to_keep, packages_to_keep * sizeof(package));
  source_office->packages_count = packages_to_keep;
}

town town_with_most_packages(town* towns, int towns_count) {
  int* total_packages = (int*)malloc(towns_count * sizeof(int));
  // memset(total_packages, 0, sizeof(total_packages) / sizeof(int));
  int most_packages_index = 0;
  for (int i = 0; i < towns_count; i++) {
    total_packages[i] = 0;
  }
  for (int i = 0; i < towns_count; i++) {
    for (int j = 0; j < towns[i].offices_count; j++) {
      total_packages[i] += towns[i].offices[j].packages_count;
      if (total_packages[most_packages_index] < total_packages[i]) {
        most_packages_index = i;
      }
    }
  }
  return towns[most_packages_index];
}

town* find_town(town* towns, int towns_count, char* name) {
  town* t;
  for (int i = 0; i < towns_count; i++) {
    if (strcmp(towns[i].name, name) == 0) {
      t = &towns[i];
      break;
    }
  }
  return t;
}

int main() {
  int towns_count;
  scanf("%d", &towns_count);
  town* towns = (town*)malloc(sizeof(town) * towns_count);
  for (int i = 0; i < towns_count; i++) {
    towns[i].name = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
    scanf("%s", towns[i].name);
    scanf("%d", &towns[i].offices_count);
    towns[i].offices =
        (post_office*)malloc(sizeof(post_office) * towns[i].offices_count);
    for (int j = 0; j < towns[i].offices_count; j++) {
      scanf("%d%d%d", &towns[i].offices[j].packages_count,
            &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
      towns[i].offices[j].packages = (package*)malloc(
          sizeof(package) * towns[i].offices[j].packages_count);
      for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
        towns[i].offices[j].packages[k].id =
            (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].offices[j].packages[k].id);
        scanf("%d", &towns[i].offices[j].packages[k].weight);
      }
    }
  }
  int queries;
  scanf("%d", &queries);
  char town_name[MAX_STRING_LENGTH];
  while (queries--) {
    int type;
    scanf("%d", &type);
    switch (type) {
      case 1: {
        scanf("%s", town_name);
        town* t = find_town(towns, towns_count, town_name);
        print_all_packages(*t);
      } break;
      case 2: {
        scanf("%s", town_name);
        town* source = find_town(towns, towns_count, town_name);
        int source_index;
        scanf("%d", &source_index);
        scanf("%s", town_name);
        town* target = find_town(towns, towns_count, town_name);
        int target_index;
        scanf("%d", &target_index);
        send_all_acceptable_packages(source, source_index, target,
                                     target_index);
      } break;
      case 3:
        printf("Town with the most number of packages is %s\n",
               town_with_most_packages(towns, towns_count).name);
        break;
    }
  }
  return 0;
}