# compiler flags
CC=g++
INC_DIRS= -I../ -I/usr/local/include/eigen3 -I/usr/local/include/ -I/usr/local/opencv3/release/include -I/usr/local/include/boost
#INC_DIRS= -I../ -I/usr/local/include/eigen3 -I/usr/local/include/
#INC_DIRS= -I../ -I/usr/local/include/ -I/usr/local/include/eigen3 -Iboost_dir
#INC_DIRS= -I../ -I/usr/local/include/ -Ieigen_dir -Iboost_dir
#INCS=$(foreach d, $INC_DIR, -I$d)
CFLAGS = -c -std=c++11 $(INC_DIRS) -Wfatal-errors #-Wall
#RELEASE: LDFLAGS= -L/usr/local/lib/boost/ -L/usr/local/lib/ -L/usr/local/eigen3 -L/usr/local/opencv3/release/lib/
LDFLAGS= -L/usr/local/lib/boost/ -L/usr/local/lib/ -L/usr/local/eigen3 -L/usr/local/opencv3/debug/lib/
#LDFLAGS= -L/usr/local/lib/boost/ -L/usr/local/lib/ -L/usr/local/eigen3
#LDFLAGS= -Lboost_dir/stage/lib -L/usr/local/lib/ -L/usr/local/eigen3
#LDFLAGS= -Lboost_dir/stage/lib -L/usr/local/lib/
SOURCES= Camera.cpp FrameRateLimiter.cpp \
VideoIOHandler.cpp Cornea_computer.cpp \
PerformanceTimer.cpp VideoWriterNoThread.cpp \
EyeTracker.cpp \
PupilEstimator.cpp FrameBinocular.cpp \
Settings.cpp FrameProcessor.cpp GlintFinder.cpp Ooga.cpp \
computePupilCenter3d.cpp getPupilCenter.cpp getPupilEllipsePoints.cpp kalmanFilterGazePoint.cpp \
../utils/OOGUI.cpp \
ResultHandler.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ooga

#LIBRARIES
LIBS_opencv = -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_calib3d
LIBS_boost = -lboost_thread -lboost_filesystem -lboost_program_options -lboost_system
LIBS_pthread = -lpthread
LIBS_GL = -lGL -lGLEW

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(INC_DIRS) $(LIBS_opencv) $(LIBS_boost) $(LIBS_pthread) $(LIBS_GL) $(OBJECTS) -o $@

pkgconf: $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ `pkg-config gsl glfw3 --cflags --libs`  $(LIBS_pthread) $(LIBS_opencv) $(LIBS_boost) $(LIBS_GL) 
#-O3 -DNDEBUG
#	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ `pkg-config opencv gsl glfw3 eigen3 --cflags --libs`  $(LIBS_pthread) $(LIBS_boost) $(LIBS_GL)

.cpp.o:
	$(CC) $(CFLAGS) $(INC_DIRS) $< -o $@ 
#-O3 -DNDEBUG

clean:
	rm -f $(OBJECTS) $(TARGET) $(EXECUTABLE)
