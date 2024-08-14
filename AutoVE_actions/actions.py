import subprocess
import os

def convert_video_format(source_path, target_path):
    """
    Convert the video format from one to another.

    Args:
    source_path : The path to the source video file.
    target_path : The path to save the converted video file.
    """
    print(f"Converting video format from {source_path} to {target_path}")
    subprocess.run(["ffmpeg", "-i", source_path, "-acodec", "copy", "-vcodec", "copy", target_path], check=True)

def extract_audio_from_video(source_path, target_path):
    """
    Extract the audio from a video file.

    Args:
    source_path : The path to the source video file.
    target_path : The path to save the extracted audio file.
    """
    print("Extracting audio from video")
    subprocess.run(["ffmpeg", "-i", source_path, "-q:a", "0", "-map", "a", target_path], check=True)

def resize_video(source_path, width, height, target_path):
    """
    Resize the video to the specified dimensions.

    Args:
    source_path : The path to the source video file.
    width : The width of the resized video.
    height : The height of the resized video.
    target_path : The path to save the resized video file.
    """
    scale = f"scale={width}:{height}"
    print(f"Resizing video to {width}x{height}")
    subprocess.run(["ffmpeg", "-i", source_path, "-vf", scale, target_path], check=True)

def trim_video(source_path, start_time, end_time, target_path):
    """
    Trim the video to the specified start and end times.

    Args:
    source_path : The path to the source video file.
    start_time : The start time of the trimmed video.
    end_time : The end time of the trimmed video.
    target_path : The path to save the trimmed video file.
    """
    print(f"Trimming video from {start_time} to {end_time}")
    subprocess.run(["ffmpeg", "-i", source_path, "-ss", start_time, "-to", end_time, "-c", "copy", target_path], check=True)


def open_video(video_path):
    try:
        # Normalize the path to ensure it's in the correct format for the OS
        normalized_path = os.path.normpath(video_path)
        
        # Ensure the path is correctly quoted to handle spaces and special characters
        command = ['ffplay', '-autoexit', f'"{normalized_path}"']
        
        # Use shell=True on Windows to handle path correctly
        subprocess.run(' '.join(command), check=True, shell=True)
    except subprocess.CalledProcessError:
        print("Failed to open video.")

