# CMake generated Testfile for 
# Source directory: /home/slee198/RRT/rrt.git/trunk/cmake-3.5.2/Utilities/cmcurl
# Build directory: /home/slee198/RRT/rrt.git/trunk/cmake-3.5.2/Utilities/cmcurl
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(curl "LIBCURL" "http://open.cdash.org/user.php")
subdirs(lib)
