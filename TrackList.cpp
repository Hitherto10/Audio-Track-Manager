/*
    TrackList.cpp
    Author: M00804152
*/

// Include the header file for TrackList
#include "TrackList.h"

// Default constructor initializes an empty TrackList
TrackList::TrackList() : head(nullptr) {}

// Destructor deallocates memory by deleting all nodes in the TrackList
TrackList::~TrackList() {
    TrackNode *currentNode = head;

    // Iterate through the linked list deleting each node
    while (currentNode != nullptr) {
        TrackNode *next = currentNode->getNext();
        // Delete the current node
        delete currentNode;
        // Move to the next node in the list
        currentNode = next;
    }
}

// Append a track to the end of the TrackList
void TrackList::push_back(const Track &track) {
    // Create a new node with the track data
    TrackNode *newNode = new TrackNode(track);

    // If the list is empty, set the head to the new node
    if (head == nullptr) {
        head = newNode;
    } else {
        // Find the last node in the list
        TrackNode *currentNode = head;

        // While loop to traverse the TrackList until the last node is found.
        while (currentNode->getNext() != nullptr) {
            currentNode = currentNode->getNext();
        }
        // Set the last node's next pointer to the new node
        currentNode->setNext(newNode);
    }
}

// Check if the TrackList contains a specific track
bool TrackList::contains(const Track &searchTrack) const {
    TrackNode *currentNode = head;
    // Iterate through the list, checking each node for the search track
    while (currentNode != nullptr) {
        // If the track is found, return true
        if (currentNode->getTrack() == searchTrack) {
            return true;
        }

        // Move to the next node in the list
        currentNode = currentNode->getNext();
    }
    // If the track is not found, return false
    return false;
}

// Print the TrackList content to the console
void TrackList::print() const {
    TrackNode *currentNode = head;

    // Iterate through the list, printing each track's details
    while (currentNode != nullptr) {
        std::cout << "Track name: "
                  << currentNode->getTrack().gettitle()
                  << ", Artist: " << currentNode->getTrack().getArtist()
                  << ", Track number: " << currentNode->getTrack().getDurationInSeconds() << std::endl;

        // Move to the next node in the list
        currentNode = currentNode->getNext();
    }
}

// Get the head node of the TrackList
TrackNode* TrackList::getHead() const {
    return head;
}