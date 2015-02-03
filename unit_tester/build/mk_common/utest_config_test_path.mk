#
#
#

INCLUDE_DIRS =\
	.\
	$(TEST_ROOT)/helpers/include\
  	$(TEST_ROOT)/mocks/include\
  	/usr/include\
	$(CPPUTEST_HOME)/include\
	
TEST_SRC_DIRS = \
	$(TEST_ROOT)/helpers/src\
	$(TEST_ROOT)/tests\
	$(TEST_ROOT)/tests/llist_test\
	$(TEST_ROOT)/tests/queue\
#	<Add here the folder that contains the tester source>	

MOCKS_SRC_DIRS =\
	$(TEST_ROOT)/mocks/src\