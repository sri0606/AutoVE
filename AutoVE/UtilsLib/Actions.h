/**
 * @file Actions.h
 * @author srira
 *
 *
 */

#ifndef AUTOVE_UTILSLIB_ACTIONS_H
#define AUTOVE_UTILSLIB_ACTIONS_H

#include <string>

void convert_video_format(const std::string& source_path, const std::string& target_path);
void extract_audio_from_video(const std::string& source_path, const std::string& target_path);
void resize_video(const std::string& source_path, int width, int height, const std::string& target_path);
void trim_video(const std::string& source_path, const std::string& start_time, const std::string& end_time, const std::string& target_path);

#endif //AUTOVE_UTILSLIB_ACTIONS_H
