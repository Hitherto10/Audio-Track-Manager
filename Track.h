/*
    Track.h
    Author: M00804152
 */

#ifndef COURSEWORK2_TRACK_H
#define COURSEWORK2_TRACK_H

#include <string>

// Class representing a music track with title, artist, and duration information.
class Track {
private:
    std::string title;
    std::string artist;
    int durationInSeconds;

public:
    /*
        Constructs a Track object with the given title, artist, and duration.
        @param title - The title of the track, @param artist - The artist of the track
        @param durationInSeconds - The duration of the track in seconds
    */
    Track(const std::string& title, const std::string& artist, int durationInSeconds);

    /*
        Returns the title of the track.
        @return - The track's title
    */
    std::string gettitle() const;

    /*
        Returns the artist of the track.
        @return - The track's artist
    */
    std::string getArtist() const;

    /*
        Returns the duration of the track in seconds.
        @return - The track's duration in seconds
    */
    int getDurationInSeconds() const;

    /*
        Compares two Track objects for equality based on title and artist
        in order to prevent duplicate tracks in the library.
        @param trackToCompare - The other Track object to compare with
        @return - true if the two Track objects have the same title and artist, return false otherwise
    */
    bool operator==(const Track &trackToCompare) const;

    /*
        Compares two Track objects for ordering based on artist and title
        as a binarySearchTree is an ordered Data Structure.
        @param trackToCompare - The other Track object to compare with
        @return - true if this Track object is less than the other, return false otherwise
    */
    bool operator<(const Track &trackToCompare) const;

    /*
        Compares two Track objects for ordering based on artist and title
        as a binarySearchTree is an ordered Data Structure.
        @param trackToCompare - The other Track object to compare with
        @return - true if this Track object is greater than the other, return false otherwise
    */
    bool operator>(const Track &trackToCompare) const;
};

#endif //COURSEWORK2_TRACK_H
