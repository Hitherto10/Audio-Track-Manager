/*
    Track.cpp
    Author: M00804152
*/

#include "Track.h"


// call constructor for the Track class to initialize title, artist, and durationInSeconds
Track::Track(const std::string& title, const std::string& artist, int durationInSeconds)
        : title(title), artist(artist), durationInSeconds(durationInSeconds) {}

// Getter function for the track's title
std::string Track::gettitle() const {
    return title;
}

// Getter function for the track's artist
std::string Track::getArtist() const {
    return artist;
}

// Getter function for the track's duration in seconds
int Track::getDurationInSeconds() const {
    return durationInSeconds;
}

// Equal comparison operator to compare two Track objects
// based on title, artist, and durationInSeconds to avoid duplicate tracks
bool Track::operator==(const Track &trackToCompare) const {

    // Returns true if all three attributes are equal, otherwise returns false
    return title == trackToCompare.title
    && artist == trackToCompare.artist
    && durationInSeconds == trackToCompare.durationInSeconds;
}

// Less than operator to compare two Track objects
// based on artist and durationInSeconds to arrange tracks in library
bool Track::operator<(const Track &trackToCompare) const {

    /*
        If the artist is the same for both tracks, compare by durationInSeconds
        Return true if the first track is considered "less" than the second, otherwise returns false
     */
    if (artist == trackToCompare.artist) {
        return durationInSeconds < trackToCompare.durationInSeconds;
    } else {
        return artist < trackToCompare.artist;
    }
}


// call to the greater than operator to compare two Track objects based on artist and durationInSeconds
bool Track::operator>(const Track &trackToCompare) const {

    /*
        If the artist is the same for both tracks, compare by durationInSeconds
        Return true if the first track is considered "greater" than the second, otherwise returns false
    */
    if (artist == trackToCompare.artist) {
        return durationInSeconds > trackToCompare.durationInSeconds;
    } else {
        return artist > trackToCompare.artist;
    }
}