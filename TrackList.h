/*
    TrackList.h
    Author: M00804152
*/

#ifndef COURSEWORK2_TRACKLIST_H
#define COURSEWORK2_TRACKLIST_H


#include <iostream>
#include "TrackNode.h"

//Class to store Track objects in a singly-linked list structure
class TrackList {
private:
    // Pointer to the head (first element) of the TrackList
    TrackNode *head;

public:

    // Constructor to initialize an empty TrackList
    TrackList();

    // Destructor to delete up the memory allocated by the TrackList
    ~TrackList();

    /*
        Adds a new Track object to the end of the TrackList
        @param track - A reference to the Track object to be added
    */
    void push_back(const Track &track);

    /*
        Checks if the TrackList contains a specific Track object
        @param searchTrack - A reference to the Track object to search for
        @return - true if the Track object is found in the list, false otherwise
    */
    bool contains(const Track &searchTrack) const;

    //  Print the contents of the TrackList
    void print() const;

    /*
        Getter function to obtain a pointer to the head of the TrackList
        @return - A pointer to the head of the TrackList
    */
    TrackNode* getHead() const;

};


#endif //COURSEWORK2_TRACKLIST_H
