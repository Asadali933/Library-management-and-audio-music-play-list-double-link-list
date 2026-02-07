#include <iostream>
#include <string>
using namespace std;

struct Node{
    int songID;
    string title;
    string artist;
    int duration;
    Node *p, *n;
};

class Playlist{
private:
    Node *start, *tem, *curn;
    Node *current; 
public:
    int sN;
    int totalDuration;

    Playlist(){
        start = NULL;
        current = NULL;
        sN = 0;
        totalDuration = 0;
    }

    
    void insert(){
        sN++;
        tem = new Node;

        cout << "\nEnter Song Title: ";
        cin.ignore();
        getline(cin, tem->title);

        cout << "Enter Artist Name: ";
        getline(cin, tem->artist);

        cout << "Enter Duration (in seconds): ";
        cin >> tem->duration;

        tem->songID = sN;
        totalDuration += tem->duration;
        tem->p = NULL;
        tem->n = NULL;

        if(start == NULL){
            start = tem;
            current = start;
        } else {
            curn = start;
            while(curn->n != NULL)
                curn = curn->n;
            curn->n = tem;
            tem->p = curn;
        }
    }

   
    void display(){
        if(start == NULL){
            cout << "Playlist is empty\n";
            return;
        }

        cout << "\nPlaylist Songs:\n";
        cout << "ID   Title         Artist       Duration\n";
        cout << "------------------------------------------\n";

        curn = start;
        while(curn != NULL){
            cout << curn->songID << "    " << curn->title << "        "
                 << curn->artist << "       " << curn->duration << " sec\n";
            curn = curn->n;
        }
        cout << "\nTotal Songs: " << sN << ", Total Duration: " << totalDuration << " sec\n";
    }

   
    void selectSong(){
        int id;
        cout << "\nEnter Song ID to play: ";
        cin >> id;

        curn = start;
        while(curn != NULL){
            if(curn->songID == id){
                current = curn;
                cout << "Now Playing: " << current->title << " by " << current->artist << endl;
                return;
            }
            curn = curn->n;
        }
        cout << "Song not found\n";
    }

   
    void playNext(){
        if(current == NULL){
            cout << "No song selected\n";
            return;
        }
        if(current->n != NULL){
            current = current->n;
            cout << "Now Playing: " << current->title << " by " << current->artist << endl;
        } else {
             cout << "Now Playing: " << current->title << " by " << current->artist << endl;
            cout << "This is the last song\n";
        }
    }

   
    void playPrevious(){
        if(current == NULL){
            cout << "No song selected\n";
            return;
        }
        if(current->p != NULL){
            current = current->p;
            cout << "Now Playing: " << current->title << " by " << current->artist << endl;
        } else {
            cout << "Now Playing: " << current->title << " by " << current->artist << endl;
            cout << "This is the first song\n";
        }
    }
};

int main(){
    Playlist pl;
    int choice;

    do{
        cout << "\n1.Insert Song";
        cout << "\n2.Display Playlist";
        cout << "\n3.Select Song to Play";
        cout << "\n4.Play Next";
        cout << "\n5.Play Previous";
        cout << "\n6.End\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: pl.insert(); break;
            case 2: pl.display(); break;
            case 3: pl.selectSong(); break;
            case 4: pl.playNext(); break;
            case 5: pl.playPrevious(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n"; break;
        }
    } while(choice != 6);

    return 0;
}

