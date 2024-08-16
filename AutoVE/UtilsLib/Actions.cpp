/**
 * @file Actions.cpp
 * @author srira
 */

#include "Actions.h"
#include <iostream>


void convert_video_format(const std::string& source_path, const std::string& target_path) {
	std::string command = "ffmpeg -i " + source_path + " -acodec copy -vcodec copy " + target_path;
	std::cout << "Converting video format from " << source_path << " to " << target_path << std::endl;
	int result = std::system(command.c_str());
	if (result != 0) {
		std::cerr << "Error: ffmpeg command failed with exit code " << result << std::endl;
	}
}

void extract_audio_from_video(const std::string& source_path, const std::string& target_path) {
	std::string command = "ffmpeg -i " + source_path + " -q:a 0 -map a " + target_path;
	std::cout << "Extracting audio from video" << std::endl;
	int result = std::system(command.c_str());
	if (result != 0) {
		std::cerr << "Error: ffmpeg command failed with exit code " << result << std::endl;
	}
}

void resize_video(const std::string& source_path, int width, int height, const std::string& target_path) {
	std::string scale = "scale=" + std::to_string(width) + ":" + std::to_string(height);
	std::string command = "ffmpeg -i " + source_path + " -vf " + scale + " " + target_path;
	std::cout << "Resizing video to " << width << "x" << height << std::endl;
	int result = std::system(command.c_str());
	if (result != 0) {
		std::cerr << "Error: ffmpeg command failed with exit code " << result << std::endl;
	}
}

void trim_video(const std::string& source_path, const std::string& start_time, const std::string& end_time, const std::string& target_path) {
	std::string command = "ffmpeg -i " + source_path + " -ss " + start_time + " -to " + end_time + " -c copy " + target_path;
	std::cout << "Trimming video from " << start_time << " to " << end_time << std::endl;
	int result = std::system(command.c_str());
	if (result != 0) {
		std::cerr << "Error: ffmpeg command failed with exit code " << result << std::endl;
	}
}

//int main() {
//	std::string source_path = "input.mp4";
//	std::string target_path_video = "output.mp4";
//	std::string target_path_audio = "output.mp3";
//	std::string target_path_resized = "resized.mp4";
//	std::string target_path_trimmed = "trimmed.mp4";
//
//	convert_video_format(source_path, target_path_video);
//	extract_audio_from_video(source_path, target_path_audio);
//	resize_video(source_path, 1280, 720, target_path_resized);
//	trim_video(source_path, "00:00:10", "00:00:20", target_path_trimmed);
//
//	return 0;
//}