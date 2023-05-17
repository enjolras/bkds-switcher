SET (bkdsobs_lib
	bkdsobs.cpp
	obsConn.cpp
	wsDispatcher.cpp
	)

FIND_PACKAGE (Boost COMPONENTS system REQUIRED)
FIND_PACKAGE (websocketpp REQUIRED)

add_library(bkdsobs SHARED ${bkdsobs_lib})

TARGET_LINK_LIBRARIES (bkdsobs
${Boost_LIBRARIES}
jsoncpp
)

set_target_properties(
	bkdsobs
	PROPERTIES
	SOVERSION ${BKDS_SWITCHER_VERSION_MAJOR}
	VERSION ${BKDS_SWITCHER_VERSION_MAJOR}.${BKDS_SWICTHER_VERSION_MINOR}.${BKDS_SWICTHER_VERSION_RELEASE}
)
