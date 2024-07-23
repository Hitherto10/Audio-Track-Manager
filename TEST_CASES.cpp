#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Track.h"
#include "BinarySearchTree.h"
#include "TrackNode.h"
#include "TrackList.h"

// Test cases for the Track class
TEST_CASE("Track class tests") {
    // Call Track class constructor for testing
    Track track1("House Of Lost Minds", "Archillrecords", 217);
    Track track2("House Of Lost Minds", "Archillrecords", 217);
    Track track3("The Interest Get Out", "Aronas Jackson", 120);

    // Test creating a track with all fields and accessing its title, artist, and duration
    SECTION("Create a track with all fields") {

        REQUIRE(track1.gettitle() == "House Of Lost Minds");
        REQUIRE(track1.getArtist() == "Archillrecords");
        REQUIRE(track1.getDurationInSeconds() == 217);
    }

    // Test comparing two identical tracks for equality
    SECTION("Compare equal tracks") {
        REQUIRE(track1 == track2);
    }

    // Test comparing two different tracks for inequality
    SECTION("Compare unequal tracks") {
        REQUIRE_FALSE(track1 == track3);
    }

    // Test comparing two tracks with the same artist and different durations using operator<
    SECTION("Compare two tracks with same artist and different durations") {
        Track trackA("An Easy Solution", "Assimil", 193);
        Track trackB("Difficult customers", "Assimil", 199);
        REQUIRE(trackA < trackB);
        REQUIRE_FALSE(trackB < trackA);
    }

    // Test comparing two tracks with the same artist and different durations using operator>
    SECTION("Compare two tracks with same artist and different durations using operator>") {
        Track trackA("An Easy Solution", "Assimil", 193);
        Track trackB("Difficult customers", "Assimil", 199);
        REQUIRE_FALSE(trackA > trackB);
        REQUIRE(trackB > trackA);
    }
}

// Test cases for the BinarySearchTree class
TEST_CASE("BinarySearchTree - Basic operations", "[insert][remove][search][empty]") {
    // Test inserting a single track into the tree
    SECTION("Insert single track") {
        BinarySearchTree bst;
        Track track("Social Unrest", "Aggravator", 179);
        // Test inserting a single track into the tree
        bst.insert(track);

        // Check that the tree is not empty
        REQUIRE(!bst.empty());
    }

    // Test inserting multiple tracks into the tree
    SECTION("Insert multiple tracks") {
        BinarySearchTree bst;
        Track track1("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
        Track track2("So Necessary", "5ive Mics", 177);
        Track track3("Position Of Power", "50 Cent", 192);

        bst.insert(track1);
        bst.insert(track2);
        bst.insert(track3);

        // Require that no track os empty or a null pointer
        REQUIRE(!bst.empty());
        REQUIRE(bst.search(track1) != nullptr);
        REQUIRE(bst.search(track2) != nullptr);
        REQUIRE(bst.search(track3) != nullptr);
    }

    // Test removing a track from the tree
    SECTION("Remove track from tree") {
        BinarySearchTree bst;
        Track track1("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
        Track track2("So Necessary", "5ive Mics", 177);
        Track track3("Position Of Power", "50 Cent", 192);
        bst.insert(track1);
        bst.insert(track2);
        bst.insert(track3);

        bst.remove(track2);

        // Require that track removed is now a null pointer
        REQUIRE(bst.search(track1) != nullptr);
        REQUIRE(bst.search(track2) == nullptr);
        REQUIRE(bst.search(track3) != nullptr);
    }

    // Test removing a non-existent track from the tree
    SECTION("Remove non-existent track") {
        BinarySearchTree bst;
        Track track1("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
        Track track2("So Necessary", "5ive Mics", 177);

        bst.insert(track1);

        bst.remove(track2);

        // Require gives true if track 2 is a null pointer after bring removed
        REQUIRE(bst.search(track1) != nullptr);
        REQUIRE(bst.search(track2) == nullptr);
    }

    // Test searching for an existing track in the tree
    SECTION("Search for existing track") {
        BinarySearchTree bst;
        Track track1("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
        Track track2("So Necessary", "5ive Mics", 177);

        bst.insert(track1);
        bst.insert(track2);

        Track *foundTrack = bst.search(track1);
        REQUIRE(foundTrack != nullptr);
        REQUIRE(*foundTrack == track1);
    }

    // Test searching for a non-existent track in the tree
    SECTION("Search for non-existent track") {
        BinarySearchTree bst;
        Track track1("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
        Track track2("So Necessary", "5ive Mics", 177);

        bst.insert(track1);

        Track *foundTrack = bst.search(track2);
        REQUIRE(foundTrack == nullptr);
    }

    // Test checking if the tree is empty
    SECTION("Check empty tree") {
        BinarySearchTree bst;
        REQUIRE(bst.empty());
    }

    // Test checking if the tree is non-empty
    SECTION("Check non-empty tree") {
        BinarySearchTree bst;
        Track track("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
        bst.insert(track);

        REQUIRE(!bst.empty());
    }
}

// Test cases for the TrackList class
TEST_CASE("TrackList tests") {
    TrackList trackList;
    Track track1("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
    Track track3("Position Of Power", "50 Cent", 192);
    Track track2("So Necessary", "5ive Mics", 177);

    // Test appending a single track to the list and checking if it is in the list
    SECTION("Append a single track to the list") {
        trackList.push_back(track1);
        REQUIRE(trackList.contains(track1) == true);
    }

    // Test appending multiple tracks to the list and checking if they are in the list
    SECTION("Append multiple tracks to the list") {
        trackList.push_back(track1);
        trackList.push_back(track2);
        trackList.push_back(track3);
        REQUIRE(trackList.contains(track1) == true);
        REQUIRE(trackList.contains(track2) == true);
        REQUIRE(trackList.contains(track3) == true);
    }

    // Test finding an existing track in the list
    SECTION("Find existing track in the list") {
        trackList.push_back(track1);
        REQUIRE(trackList.contains(track1) == true);
    }

    // Test finding a non-existent track in the list
    SECTION("Find non-existent track in the list") {
        REQUIRE(trackList.contains(track1) == false);
    }

    // Test getting the head of the list when there is only one track in the list
    SECTION("Get the head of the list with a single track") {
        trackList.push_back(track1);
        TrackNode* head = trackList.getHead();
        REQUIRE(head != nullptr);
        REQUIRE(head->getTrack() == track1);
    }

    // Test getting the head of the list when there are multiple tracks in the list
    SECTION("Get the head of the list with multiple tracks") {
        trackList.push_back(track1);
        trackList.push_back(track2);
        trackList.push_back(track3);
        TrackNode* head = trackList.getHead();
        REQUIRE(head != nullptr);
        REQUIRE(head->getTrack() == track1);
    }

    // Test getting the head of an empty list
    SECTION("Get the head of an empty list") {
        TrackNode* head = trackList.getHead();
        REQUIRE(head == nullptr);
    }
}

// Test cases for the TrackNode class
TEST_CASE("TrackNode tests") {
    Track track1("Ghosts of Syllables", "ADMIRAL RADLEY", 120);
    Track track2("So Necessary", "5ive Mics", 177);
    Track track3("Position Of Power", "50 Cent", 192);

    // Test constructing a TrackNode with a track and getting its track
    SECTION("Construct TrackNode with a track") {
        TrackNode node(track1);
        REQUIRE(node.getTrack() == track1);
    }


    SECTION("Get the track in a TrackNode") {
        TrackNode node(track1);
        Track retrievedTrack = node.getTrack();
        REQUIRE(retrievedTrack == track1);
    }

    // Test getting the next node of a TrackNode when it is initially nullptr
    SECTION("Get the next node (initially nullptr)") {
        TrackNode node(track1);
        TrackNode* nextNode = node.getNext();
        REQUIRE(nextNode == nullptr);
    }

    // Test setting the next node of a TrackNode and getting the next node
    SECTION("Set the next node") {
        TrackNode node1(track1);
        TrackNode node2(track2);
        node1.setNext(&node2);
        TrackNode* nextNode = node1.getNext();
        REQUIRE(nextNode == &node2);
    }
}