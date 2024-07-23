/*
    TrackNode.cpp
    Author: M00804152
*/

#include "TrackNode.h"


// Constructor to initialize a TrackNode with a given Track object and a nullptr for the next pointer
TrackNode::TrackNode(const Track& track) : track(track), next(nullptr) {}

// Getter function to obtain the Track object stored in the TrackNode
Track TrackNode::getTrack() const {
    return track;
}

// Getter function to obtain a pointer to the next TrackNode in the list
TrackNode* TrackNode::getNext() const {
    return next;
}

// Setter function to update the pointer to the next TrackNode in the list
void TrackNode::setNext(TrackNode *newNext) {
    next = newNext;
}


