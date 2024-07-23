/*
    TrackLibrary.cpp
    Author: M00804152
*/

#include "TrackLibrary.h"


// Uses the BST insert function to add tracks to the library
void TrackLibrary::loadFileTracksToLibrary(const Track &track) {
    library.insert(track);
}


// Removes a track from the library based on the provided artist and title
void TrackLibrary::removeTrack(const std::string &artist, const std::string &title) {
    Track trackToRemove = findTrack(artist, title);

    // If the track is not found (getArtist.empty returns null) in the library,
    // display an error message and return
    if (trackToRemove.getArtist().empty()) {
        std::cout << "\n\n----------------------------------\n";
        std::cout << "  TRACK NOT FOUND IN THE LIBRARY.\n";
        std::cout << "----------------------------------\n\n";
        return;
    }

    // Remove the track from the library and display a success message
    library.remove(trackToRemove);
    std::cout << "\n\n-----------------------------\n";
    std::cout << "  TRACK SUCCESSFULLY REMOVED.\n";
    std::cout << "-----------------------------\n\n";
}


// Searches for a track in the library based on the user inputted artist and title
// in order to be removed
Track TrackLibrary::findTrack(const std::string &artist, const std::string &title) {

    // Initializes a Track object with empty strings for title and artist,
    // and -1 for durationInSeconds to represent a "not found" track
    Track foundTrack("", "", -1);

    bool trackFound = false;

    /*
        Loop through each track in the library using [&] capturing
        all variables referenced in the function by reference
        to find the provided track
    */
    library.forEach([&](const Track &track) {
        if (track.getArtist() == artist && track.gettitle() == title && !trackFound) {
            trackFound = true;
            foundTrack = track;
        }
    });
    return foundTrack;
}


// Searches for tracks by the provided artist and returns a list of found tracks
TrackList TrackLibrary::searchByArtist(const std::string &artist) {

    // Create an empty TrackList to store tracks with the specified artist
    TrackList tracks;

    // Iterate through the tracks in the library using forEach
    library.forEach([&](const Track &track) {
        // Check if the current track's artist matches the specified artist
        if (track.getArtist() == artist) {

            // Search for the track in the library (this step is actually unnecessary since we're iterating through the library)
            Track *foundTrack = library.search(track);

            // If the track is found, add it to the TrackList (it should always be found in this case)
            if (foundTrack != nullptr) {
                tracks.push_back(*foundTrack);
            }
        }
    });

    return tracks;
}

// Returns a constant reference to the contents of the library
const BinarySearchTree &TrackLibrary::getLibrary() const {
    return library;
}
