#
#
#

#	When all source files in a folder are under tests, it is prefered to add the folder instead of adding individual source files.
SRC_DIRS = \
	$(PRODUCTION_SOURCES)/llist\
	$(PRODUCTION_SOURCES)/normalize_string\
#	<Add here the folders that contain code under test>

SRC_FILES = \
#	$(PRODUCTION_SOURCES)/source_file.cpp
#	<Add here the source file that is being tested>

INCLUDE_DIRS +=\
	$(PRODUCTION_SOURCES)/\
	$(PRODUCTION_SOURCES)/normalize_string\
#	<Add here the folder that contains the headers. Note that the order is important!>