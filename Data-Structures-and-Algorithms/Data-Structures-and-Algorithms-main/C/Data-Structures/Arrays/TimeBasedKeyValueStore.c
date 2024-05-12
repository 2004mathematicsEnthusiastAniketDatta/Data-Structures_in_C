#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size for the key and value strings
#define MAX_SIZE 100

// Define a struct to represent a single key-value-time entry
typedef struct {
    char key[MAX_SIZE];
    char value[MAX_SIZE];
    int timestamp;
} Entry;

// Define a struct to represent the TimeMap
typedef struct {
    Entry* entries;
    int size;
    int capacity;
} TimeMap;

// Function to create a new TimeMap
TimeMap* createTimeMap(int capacity) {
    TimeMap* timeMap = (TimeMap*)malloc(sizeof(TimeMap));
    timeMap->entries = (Entry*)malloc(capacity * sizeof(Entry));
    timeMap->size = 0;
    timeMap->capacity = capacity;
    return timeMap;
}

// Function to set a key-value-time entry in the TimeMap
void set(TimeMap* timeMap, char* key, char* value, int timestamp) {
    // Check if the TimeMap is full and needs to be resized
    if (timeMap->size == timeMap->capacity) {
        timeMap->capacity *= 2;
        timeMap->entries = (Entry*)realloc(timeMap->entries, timeMap->capacity * sizeof(Entry));
    }

    // Add the new entry to the TimeMap
    strcpy(timeMap->entries[timeMap->size].key, key);
    strcpy(timeMap->entries[timeMap->size].value, value);
    timeMap->entries[timeMap->size].timestamp = timestamp;
    timeMap->size++;
}

// Function to get a value from the TimeMap
char* get(TimeMap* timeMap, char* key, int timestamp) {
    int i; 
    // Search for the key-value-time entry with the largest timestamp that is less than or equal to the given timestamp
    for (i = timeMap->size - 1; i >= 0; i--) {
        if (strcmp(timeMap->entries[i].key, key) == 0 && timeMap->entries[i].timestamp <= timestamp) {
            return timeMap->entries[i].value;
        }
    }

    // If no such entry is found, return an empty string
    return "";
}

// Driver code
int main() {
    // Create a new TimeMap
    TimeMap* timeMap = createTimeMap(10);

    // Add some entries to the TimeMap
    set(timeMap, "foo", "bar", 1);
    set(timeMap, "foo", "bar2", 4);

    // Get some values from the TimeMap
    printf("%s\n", get(timeMap, "foo", 1));  // Outputs: bar
    printf("%s\n", get(timeMap, "foo", 4));  // Outputs: bar2

    // Free the memory allocated for the TimeMap
    free(timeMap->entries);
    free(timeMap);

    return 0;
}

