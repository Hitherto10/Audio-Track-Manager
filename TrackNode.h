/*
    TrackNode.h
    Author: M00804152
*/

#ifndef TRACKNODE_H
#define TRACKNODE_H

#include "Track.h"

// TrackNode class to store a Track object and a pointer to the next TrackNode
class TrackNode {
public:
    /*
        Constructor to initialize a TrackNode with a given Track object
        @param track - A reference to the Track object to be stored
    */
    TrackNode(const Track& track);

    /*
        Getter function to obtain the Track object stored in the TrackNode
        @return - A copy of the stored Track object
    */
    Track getTrack() const;

    /*
        Getter function to obtain a pointer to the next TrackNode in the list
        @return - A pointer to the next TrackNode
    */
    TrackNode *getNext() const;

    /*
        Setter function to update the pointer to the next TrackNode in the list
        @param newNext - A pointer to the new next TrackNode
    */
    void setNext(TrackNode *newNext);

private:
    // The Track object stored in the TrackNode
    Track track;
    // Pointer to the next TrackNode in the list
    TrackNode* next;
};

#endif // TRACKNODE_H
