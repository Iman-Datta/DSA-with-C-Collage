#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for sleep()

#define MAX_TITLE 100
#define MAX_ARTIST 100

// Define Song structure
typedef struct Song {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    struct Song* next;
} Song;
Song* head = NULL;

Song* createSong(char title[], char artist[]) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strncpy(newSong->title, title, MAX_TITLE);
    strncpy(newSong->artist, artist, MAX_ARTIST);
    newSong->next = NULL;
    return newSong;
}

// Function to add a song to the playlist (at the end)
void addSong(char title[], char artist[]) {
    Song* newSong = createSong(title, artist);
    if (head == NULL) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newSong;
    }
    printf("Song \"%s\" by \"%s\" added to the playlist.\n", title, artist);
}

// Function to delete a song by title
void deleteSong(char title[]) {
    Song* temp = head;
    Song* prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song \"%s\" not found in the playlist.\n", title);
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Song \"%s\" deleted from the playlist.\n", title);
}

// Function to display the playlist
void displayPlaylist() {
    if (head == NULL) {
        printf("The playlist is empty.\n");
        return;
    }

    Song* temp = head;
    int count = 1;
    printf("\n--- Playlist ---\n");
    while (temp != NULL) {
        printf("%d. \"%s\" by \"%s\"\n", count++, temp->title, temp->artist);
        temp = temp->next;
    }
    printf("----------------\n");
}

// Function to simulate playing the playlist
void playPlaylist() {
    if (head == NULL) {
        printf("The playlist is empty. Nothing to play.\n");
        return;
    }

    Song* temp = head;
    printf("\nPlaying Playlist:\n");
    while (temp != NULL) {
        printf("Now Playing: \"%s\" by \"%s\"\n", temp->title, temp->artist);
        sleep(1); // simulate delay
        temp = temp->next;
    }
}

// Function to search for a song by title
int searchSong(char title[]) {
    Song* temp = head;
    int index = 0;

    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0)
            return index;
        temp = temp->next;
        index++;
    }

    return -1; // Not found
}

// Function to clear the playlist (used before exiting)
void clearPlaylist() {
    Song* temp = head;
    while (temp != NULL) {
        Song* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    head = NULL;
}

// Menu-driven interface
void showMenu() {
    printf("\n==== Music Playlist Menu ====\n");
    printf("1. Add a song\n");
    printf("2. Delete a song\n");
    printf("3. Display playlist\n");
    printf("4. Play playlist\n");
    printf("5. Search for a song\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];

    do {
        showMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = '\0';

                printf("Enter artist name: ");
                fgets(artist, MAX_ARTIST, stdin);
                artist[strcspn(artist, "\n")] = '\0';

                addSong(title, artist);
                break;

            case 2:
                printf("Enter the title of the song to delete: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = '\0';
                deleteSong(title);
                break;

            case 3:
                displayPlaylist();
                break;

            case 4:
                playPlaylist();
                break;

            case 5:
                printf("Enter the title of the song to search: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = '\0';
                int pos;
                pos = searchSong(title);
                if (pos != -1)
                    printf("Song \"%s\" found at position %d.\n", title, pos + 1);
                else
                    printf("Song \"%s\" not found.\n", title);
                break;

            case 6:
                clearPlaylist();
                printf("Exiting playlist. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
