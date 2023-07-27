video_file = /disk/videos/road.mov

build/main -v $video_file


g++ asift.cpp -I/usr/include/opencv4/ -lopencv_videoio -lopencv_highgui -lopencv_imgproc -lopencv_core -lopencv_imgcodecs -lopencv_photo -lopencv_imgproc -lopencv_calib3d -lopencv_features2d
