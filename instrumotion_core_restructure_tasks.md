Claude-Engineer, please perform the following tasks to rename and restructure our project from Sensorhub to Instrumotion Core:

1. Rename the project:
   - Update CMakeLists.txt, replacing all instances of "Sensorhub" with "Instrumotion Core"
   - Update all .cpp and .hpp files, replacing "Sensorhub" with "InstrumotionCore" in class names, namespaces, and comments
   - Update README.md and any other documentation files with the new project name

2. Restructure the directory:
   - Create new directories: src/sensor_hub, src/sam2, src/gesture_recognition, src/audio, src/ar
   - Move all existing sensor-related code into src/sensor_hub
   - Update CMakeLists.txt files to reflect the new directory structure
   - Update include paths in all .cpp and .hpp files to reflect the new structure

3. Create placeholder files:
   - In src/sam2, create SAM2Processor.cpp and SAM2Processor.hpp
   - In src/gesture_recognition, create GestureRecognizer.cpp and GestureRecognizer.hpp
   - In src/audio, create AudioProcessor.cpp and AudioProcessor.hpp
   - In src/ar, create ARIntegrator.cpp and ARIntegrator.hpp

4. Update the main API:
   - Rename SensorhubAPI.cpp and SensorhubAPI.hpp to InstrumotionCoreAPI.cpp and InstrumotionCoreAPI.hpp
   - Update the class name and methods in these files to reflect the expanded scope

5. Generate a report of all changes made, including:
   - List of renamed files
   - List of moved files
   - List of new directories and files created
   - Summary of major changes in CMakeLists.txt and main API files

After making these changes, please run the following tests:

1. Attempt to build the project using CMake and report any errors
2. Run any existing unit tests and report the results
3. Check that all #include statements in .cpp files correctly reference the new file locations
4. Verify that no old directory structures or file names remain

Please provide the report of changes and test results when finished.