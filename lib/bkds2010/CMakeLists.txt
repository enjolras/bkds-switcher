SET (bkds2010_lib
	bkds_control.cpp
	command.cpp
	connectionHandler.cpp
	effectDispatcher.cpp
	wsDispatcher.cpp
	key.cpp
	ping.cpp
	select_xpt.cpp
	tbar.cpp
	auto_rate.cpp
	eventmem.cpp
	wipe.cpp
	trans.cpp
	dsk.cpp
	eff00_13.cpp
	eff01_a1.cpp
	eff01_9c.cpp
	eff01_8a.cpp
	effect_keyer.cpp
	effect_matte.cpp
	effect_chr.cpp
	eff25_82.cpp
	eff2e_86.cpp
	enable.cpp
	sysinfo.cpp
	setup_systm.cpp
	wipepos.cpp
	wipeparams.cpp
	mixparams.cpp
	matteparams.cpp
	gpiin.cpp
	util.cpp
	)

add_library(bkds2010 SHARE ${bkds2010_lib})

set_target_properties(
	bkds2010
	PROPERTIES
	SOVERSION ${BKDS_SWITCHER_VERSION_MAJOR}
	VERSION ${BKDS_SWITCHER_VERSION_MAJOR}.${BKDS_SWICTHER_VERSION_MINOR}.${BKDS_SWICTHER_VERSION_RELEASE}
)
