/*
    main.cpp
    Author: M00804152
*/

#include "TrackLibrary.h"
#include "Track.h"
#include "TrackList.h"
#include <iostream>
#include <limits>


// Reads and adds all tracks from a user specified file to the track library.
void addTracksFromFile(TrackLibrary& trackLibrary, std::string& filename) {
    std::cout << "Enter the input track file name: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    // Raise validation error in case of an invalid file name input
    if (!inputFile) {
        std::cerr << "Error: Unable to open the file \"" << filename << std::endl;
        return;
    }

    std::string line;
    int duplicateCount = 0, addedCount = 0;

    // Loop through each line of the input file
    while (std::getline(inputFile, line)) {
        std::stringstream stringStream(line);
        std::string title, artist;
        int durationInSeconds;

        // Extract track information from each line using tab '\t' as a delimiter for title and artist.
        std::getline(stringStream, title, '\t');
        std::getline(stringStream, artist, '\t');
        stringStream >> durationInSeconds;

        // Create a Track object using the extracted information
        Track trackToAdd(title, artist, durationInSeconds);


        // Check if track already exists in library.
        TrackList tracks = trackLibrary.searchByArtist(artist);
        if (!tracks.contains(trackToAdd)) {
            trackLibrary.loadFileTracksToLibrary(trackToAdd);
            addedCount++;
        } else {
            duplicateCount++;
        }
    }

    std::cout << "------------------------\n";
    std::cout << "   " << addedCount << " TRACKS ADDED.\n";
    std::cout << "------------------------\n";

    // If there were duplicates, print the number of duplicate tracks skipped
    if (duplicateCount > 0) {
        std::cout << "\n-----------------------------\n";
        std::cout <<  duplicateCount << " DUPLICATE TRACKS SKIPPED.\n";
        std::cout << "-----------------------------\n";
    }
}



// Saves Tracks in the TrackLibrary object into a user specified file
void saveTracksToFile(const TrackLibrary& trackLibrary) {
    std::string filename;
    std::cout << "Enter the output file name: ";
    std::cin >> filename;

    // Open output file.
    std::ofstream outputFile(filename);

    /*
        Loop through each track in the library using & to capture
        all variables used in the lambda function by reference.
    */
    trackLibrary.getLibrary().forEach([&](const Track& track) {
       //  Write the track details to the output file by calling the class getter functions.
       outputFile << track.gettitle() << '\t'
                  << track.getArtist() << '\t'
                  << track.getDurationInSeconds() << '\n';
   });

    std::cout << "\n\n-----------------------------\n";
    std::cout << "  LIBRARY SAVED TO " <<  filename << "\n";
    std::cout << "-----------------------------\n";

   outputFile.close();
}


// Function to search for tracks in the TrackLibrary by a given artist/band name
void searchByArtist(TrackLibrary& trackLibrary) {
   std::string artist;
   std::cout << "\nEnter the artist/band name: ";
   std::cin.ignore();
   std::getline(std::cin, artist);

   // Search the track library for all tracks by the given artist
   TrackList tracks = trackLibrary.searchByArtist(artist);

   /*
      call function that checks if the head pointer of the TrackList object (linked list)
      is empty, if the linked list is empty, the inputted artist does not exist in the library
   */
   if (tracks.getHead() == nullptr) {
       std::cout << "\n\n-------------------------------------\n";
       std::cout << "  NO TRACK FOUND FOR: '" << artist << "'\n";
       std::cout << "-------------------------------------\n\n";
   } else {
       // call print function to display all tracks found under inputted artist
       tracks.print();
   }
}


// Function to remove a specific track from the TrackLibrary
void removeTracks(TrackLibrary& trackLibrary) {
   std::string artist, title;

    // Prompt the user for the artist/band name and track name
   std::cout << "Enter the artist/band name: ";
   std::cin.ignore();
   std::getline(std::cin, artist);

   std::cout << "Enter the track name: ";
   std::getline(std::cin, title);

    // call remove function to delete the specified track from the library
   trackLibrary.removeTrack(artist, title);
}


int main() {

   // Initialize the TrackLibrary
   TrackLibrary trackLibrary;
   std::string filename;

   int choice;
   bool exitProgram = false;

   std::cout << "\n\n----------------------------------------\n";
   std::cout << "        AUDIO STREAMING SERVICE\n";
   std::cout << "----------------------------------------\n\n";

   // Main menu Loop
    while (!exitProgram) {
        // Display the menu options to the user
        std::cout << "\n1. Load tracks from file\n";
        std::cout << "2. Save tracks to file\n";
        std::cout << "3. Search by artist/band name\n";
        std::cout << "4. Remove specific track(s)\n";
        std::cout << "5. Press 5 to exit\n\n";
        std::cout << "Operation: ";

        // Error message for non-integer  and out of range input
        if (!(std::cin >> choice) || choice < 1 || choice > 5) {
            std::cout << "Invalid input. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // End program when user selects 5
        if (choice == 5) {
            std::cout << "Program Exited.\n";
            exitProgram = true;
        }

        // Check if the library is empty for operations other than Operation 1 (Load tracks from file)
        else if (choice != 1 && trackLibrary.getLibrary().empty()) {
            std::cout << "\n-----------------------------------------------------\n";
            std::cout << "  ERROR: LIBRARY IS EMPTY, LOAD TRACKS FROM A FILE (1).\n";
            std::cout << "-------------------------------------------------------\n\n";
            continue;
        }

        // Perform the chosen operation based on the user's input
        if (choice == 1) {
            addTracksFromFile(trackLibrary, filename);
        } else if (choice == 2) {
            saveTracksToFile(trackLibrary);
        } else if (choice == 3) {
            searchByArtist(trackLibrary);
        } else if (choice == 4) {
            removeTracks(trackLibrary);
        }
    }


    return 0;
}
