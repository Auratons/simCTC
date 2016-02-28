ACLOCAL_AMFLAGS = -I build-aux/m4
AUTOMAKE_OPTIONS = foreign


bin_PROGRAMS = src/sim

src_sim_SOURCES = \
	src/logger.cc \
	src/app.cc \
	src/gui/window.cc \
	src/main.cc

src_sim_CPPFLAGS = --pedantic -Wall -std=c++11 \
	$(BOOST_CPPFLAGS) \
	-DBOOST_ALL_DYN_LINK

src_sim_LDADD = $(BOOST_LDFLAGS) \
	$(BOOST_DATE_TIME_LIB) \
	$(BOOST_SYSTEM_LIB) \
	$(BOOST_LOG_SETUP_LIB) \
	$(BOOST_LOG_LIB) \
	$(BOOST_THREAD_LIB) \
	-lpthread