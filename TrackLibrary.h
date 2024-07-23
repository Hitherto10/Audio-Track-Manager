/*
    TrackLibrary.h
    Author: M00804152
*/

#ifndef COURSEWORK2_TRACKLIBRARY_H
#define COURSEWORK2_TRACKLIBRARY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Track.h"
#include "BinarySearchTree.h"
#include "TrackList.h"

// A library of tracks using a binary search tree data structure.
class TrackLibrary {
private:
    BinarySearchTree library;

    /*
        Find and return a track in the library with a given artist and title
        to be used for track deletion.
        @param artist - The artist of the track to be found
        @param title - The title of the track to be found
    */
    Track findTrack(const std::string &artist, const std::string &title);

public:

    /*
        Load(add) all tracks from a file into the library
        @param track - The track(s) to be added to the library
    */
    void loadFileTracksToLibrary(const Track &track);

    /*
        Remove a track from the library with a given artist and title
        @param artist - The artist of the track to be removed
        @param title - The title of the track to be removed
    */
    void removeTrack(const std::string &artist, const std::string &title);

    /*
        Search and return a list of tracks by a given artist
        @param artist - The artist of the tracks to be found
    */
    TrackList searchByArtist(const std::string &artist);


    //  Get a const reference to the BinarySearchTree containing the library of tracks
    const BinarySearchTree &getLibrary() const;


};

#endif //COURSEWORK2_TRACKLIBRARY_H
