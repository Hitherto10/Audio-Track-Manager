/*
    main.h
    Author: M00804152
*/

#ifndef COURSEWORK2_MAIN_H
#define COURSEWORK2_MAIN_H


#include "TrackLibrary.h"


/*
    Reads tracks from a file and adds them to the track library
    @param - trackLibrary: reference to the TrackLibrary object to add the tracks to
    @param - filename: this represents the name of the input file to extract tracks from
*/
void addTracksFromFile(TrackLibrary& trackLibrary, std::string& filename);


/*
    Saves tracks from the track library to a user specified file
    @param - trackLibrary: reference to the TrackLibrary object to extract tracks from
*/
void saveTracksToFile(const TrackLibrary& trackLibrary);


/*
    Searches for tracks by artist/band name in the track library and displays for the User
    @param - trackLibrary: the library to search for tracks in
*/
void searchByArtist(TrackLibrary& trackLibrary);


/*
    Removes a track with the given artist/band name and track name from the track library
    @param - trackLibrary: the library to remove tracks from
*/
void removeTracks(TrackLibrary& trackLibrary);


#endif //COURSEWORK2_MAIN_H
