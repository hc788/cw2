#include <iostream>
// this line is work
// #include "includes/TrackLibrary.cpp" 
// this line is work
#include "includes/TrackLibrary.h" 


/*
 code.cpp
 Author: M00847153
 Created: 20/04/2023
 */




int main() {
    TrackLibrary library;
    std::cout << "Enter a name of the input file:-> "; 
    // to store the file name entered by the user
    std::string fileName;
    std::cin >> fileName;

    // Load tracks from a file
    library.loadFromFile(fileName);

    // Add a new track
    library.addTrack("The Beatles", "Let It Be", 243);
    library.addTrack("tile track random", "artist 8", 190);

    // Search for tracks by artist
    std::vector<Track> results = library.searchByArtist("Joy Division");
    for (const auto& track : results) {
        std::cout << "Artist/Band: " << track.artist << ", Title - " << track.title << ", Duration (" << track.length_seconds << " seconds)" << std::endl;
    }

    // Remove a track
    library.removeTrack("Al Green", "Let's Stay Together");

    // Save tracks to a file
    library.saveToFile("tracks_updated.txt");

    return 0;
}