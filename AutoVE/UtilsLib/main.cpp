/**
 * @file main.cpp
 * @author srira
 */
#include <cstdlib> // For system()
#include <iostream>

int main() {
	// Construct the FFmpeg command
	const char* command = "ffmpeg -i C:/Users/srira/Videos/kalki.mp4 output.avi";

	// Execute the command
	int result = system(command);

	// Check the result
	if (result != 0) {
		// Handle the error
		std::cerr << "Error executing FFmpeg command" << std::endl;
	}

	return 0;
}
